#include "Murphi/Dialect.h"
#include "Murphi/Ops.h"
#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Transforms/InliningUtils.h"
#include "llvm/ADT/Sequence.h"

#include <iostream>
#include <set>
using namespace mlir;

class GenerateTransientStates
    : public mlir::OpRewritePattern<mlir::pcc::FunctionOp> {
public:
  GenerateTransientStates(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::FunctionOp>(context, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::FunctionOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::FunctionOp funcOp,
                                      PatternRewriter &rewriter) const final {

    // get the parent module and get all the unique msg types that are sent
    mlir::ModuleOp mod = funcOp.getParentOfType<mlir::ModuleOp>();

    std::string machine =
        funcOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string action =
        funcOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string cur_state =
        funcOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();

    std::vector<std::string> stateTokens = parseStateIntoTokens(cur_state);
    // consider only cache for now
    if (machine != "cache") {
      return mlir::failure();
    }
    // check if it is a transient state -- tokens length > 2
    if (stateTokens.size() <= 2) {
      return mlir::failure();
    }

    // i.e. cache_I_load has logical state "cache_I";
    std::string logicalState = stateTokens[0] + "_" + stateTokens[1];

    // for all msg types check if there exists a handler for that logical state
    std::vector<std::string> allMsgTypes = getAllMsgTypes(mod);
    for (auto msg : allMsgTypes) {
      // Does a handler exist for the message type in the logical state
      if (doesHandlerExist(logicalState, msg, mod)) {
        // find the handler
        for (auto &op : mod.getRegion().getBlocks().front().getOperations()) {
          if (mlir::dyn_cast<mlir::pcc::FunctionOp>(op) != nullptr) {
            mlir::pcc::FunctionOp f = mlir::dyn_cast<mlir::pcc::FunctionOp>(op);
            std::string fAction =
                f.getAttr("action").cast<mlir::StringAttr>().getValue().str();
            std::string fCur_state = f.getAttr("cur_state")
                                         .cast<mlir::StringAttr>()
                                         .getValue()
                                         .str();
            // Found the handler
            if (fAction == msg && fCur_state == logicalState && fAction != action) {
              // TODO -- fix ( not all have end state)

              std::string fEnd_State = f.getAttr("end_state")
                                           .cast<mlir::StringAttr>()
                                           .getValue()
                                           .str();

              // end state becomes the new logical state
              std::string nTransientState = fEnd_State + "_" + stateTokens[2];
              // stop if the hanlder exists
              if (doesHandlerExist(cur_state, msg, mod)) {
                return mlir::failure();
              }

              // create the handler for the transient state
              // set insetion point correctly
              rewriter.setInsertionPoint(f);

              // create the handling of the racing transaction: cache_M_evict, Fwd_GetM, cache_I_evict
              mlir::pcc::FunctionOp fConc =  rewriter.create<mlir::pcc::FunctionOp>(rewriter.getUnknownLoc(), machine, cur_state, msg, nTransientState);
              mlir::pcc::FunctionOp fTrans = rewriter.create<mlir::pcc::FunctionOp>(rewriter.getUnknownLoc(), machine, nTransientState, action, fEnd_State);

              // race handler clone
              mlir::pcc::FunctionOp inClone = funcOp.clone();
              mlir::pcc::FunctionOp fClone = f.clone();

              // inline fClone into fConc
              rewriter.inlineRegionBefore(fClone.getRegion(), fConc.getRegion(), fConc.getRegion().end());
              // incline inClone into fTrans
              rewriter.inlineRegionBefore(inClone.getRegion(), fTrans.getRegion(), fTrans.getRegion().end());

              // return success
              return mlir::success();
            }
          }
        }
      }
      // no handler exists -- we fail
      else {
        return mlir::failure();
      }
    }
    return mlir::failure();
  }
  bool doesHandlerExist(std::string state, std::string msgId,
                        mlir::ModuleOp &mod) const {
    // std::cout << "attempting to find hander for state : " << state << " msgId : " << msgId << std::endl;
    bool found = false;
    mod.walk([&](mlir::pcc::FunctionOp fun) {
      std::string action =
          fun.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      std::string cur_state =
          fun.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();

      if (cur_state == state && action == msgId) {
        found = true;
      }
    });
    // std::cout << "Found completed with result " << found << std::endl;
    return found;
  }

  std::vector<std::string> parseStateIntoTokens(std::string s) const {
    std::string delim = "_";
    std::vector<std::string> tokens;

    auto start = 0U;
    auto end = s.find(delim);

    while (end != std::string::npos) {
      std::string token = s.substr(start, end - start);
      tokens.push_back(token);
      start = end + delim.length();
      end = s.find(delim, start);
    }
    std::string token = s.substr(start, end);
    tokens.push_back(token);
    return tokens;
  }

  std::vector<std::string> getAllMsgTypes(mlir::ModuleOp mod) const {
    std::set<std::string> msgTypes;

    mod.walk([&](mlir::pcc::MsgConstrOp msgConstr) {
      mlir::ArrayAttr params =
          msgConstr.getAttr("params").cast<mlir::ArrayAttr>();
      std::string msgId = params[0].cast<mlir::StringAttr>().getValue().str();
      msgTypes.insert(msgId);
    });

    std::vector<std::string> v(msgTypes.begin(), msgTypes.end());
    return v;
  }
};

namespace {
struct ProtogenPass : public mlir::ProtogenOptimizationBase<ProtogenPass> {
  void getDependentDialects(mlir::DialectRegistry &registry) const override {
    registry.insert<mlir::murphi::MurphiDialect>();
    registry.insert<mlir::pcc::PCCDialect>();
  }
  void runOnOperation() override;
};
} // namespace

void ProtogenPass::runOnOperation() {
  mlir::OwningRewritePatternList patterns;

  patterns.insert<GenerateTransientStates>(&getContext());

  if (mlir::failed(mlir::applyPatternsAndFoldGreedily(getOperation(),
                                                      std::move(patterns)))) {
    return signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createProtogenOptimizationPass() {
  return std::make_unique<ProtogenPass>();
}