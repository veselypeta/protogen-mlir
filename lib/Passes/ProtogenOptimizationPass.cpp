#include "Murphi/Dialect.h"
#include "Murphi/Ops.h"
#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

#include "utils/stateUtils.h"

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

#include <algorithm>
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
            if (fAction == msg && fCur_state == logicalState &&
                fAction != action) {
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

              // create the handling of the racing transaction: cache_M_evict,
              // Fwd_GetM, cache_I_evict
              mlir::pcc::FunctionOp fConc =
                  rewriter.create<mlir::pcc::FunctionOp>(
                      rewriter.getUnknownLoc(), machine, cur_state, msg,
                      nTransientState);
              mlir::pcc::FunctionOp fTrans =
                  rewriter.create<mlir::pcc::FunctionOp>(
                      rewriter.getUnknownLoc(), machine, nTransientState,
                      action, fEnd_State);

              // race handler clone
              mlir::pcc::FunctionOp inClone = funcOp.clone();
              mlir::pcc::FunctionOp fClone = f.clone();

              // inline fClone into fConc
              rewriter.inlineRegionBefore(fClone.getRegion(), fConc.getRegion(),
                                          fConc.getRegion().end());
              // incline inClone into fTrans
              rewriter.inlineRegionBefore(inClone.getRegion(),
                                          fTrans.getRegion(),
                                          fTrans.getRegion().end());

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
    // std::cout << "attempting to find hander for state : " << state << " msgId
    // : " << msgId << std::endl;
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

class OptimizeRacingTransactions
    : public mlir::OpRewritePattern<mlir::pcc::FunctionOp> {
public:
  OptimizeRacingTransactions(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::FunctionOp>(context, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::FunctionOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::FunctionOp funcOp,
                                      PatternRewriter &rewriter) const final {

    // Get the module
    mlir::ModuleOp mod = funcOp.getParentOfType<mlir::ModuleOp>();

    // Read the attributes of the function
    std::string action =
        funcOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string machine =
        funcOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string cur_state =
        funcOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();

    if (machine != "cache") {
      return mlir::failure();
    }

    if (!utils::isTransientState(cur_state)) {
      return mlir::failure();
    }

    // Find the Logical Start State
    // i.e. ["cache", "I", "load"] -> "cache_I"
    std::string logicalStartState = utils::getLogicalStartState(cur_state);
    std::vector<std::string> stateTokens =
        utils::parseStateIntoTokens(cur_state);

    // find all the messages that could arrive for the logical start state
    std::vector<mlir::pcc::FunctionOp> handlerFuns =
        getAllLogicalStartStateHandlerFunctions(logicalStartState, mod);
    for (mlir::pcc::FunctionOp hfunc : handlerFuns) {
      // Does the handler exist
      std::string hfuncAction =
          hfunc.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      // if no handler then we must create one
      if (!utils::doesHandlerExist(cur_state, hfuncAction, mod)) {
        // TODO - handle case when there is no end-state
        std::string newLogicalStartState = hfunc.getAttr("end_state")
                                               .cast<mlir::StringAttr>()
                                               .getValue()
                                               .str();

        std::string transitionToState = newLogicalStartState;
        // copy rest of tokens
        for (size_t i = 2; i < stateTokens.size(); i++) {
          transitionToState += ("_" + stateTokens[i]);
        }

        // std::cout << "TRANSITION TO STATE : " << transitionToState << std::endl;

        // if the transtional state does not exists we must create it
        if (!utils::doesStateExist(transitionToState, mod)) {
          // std::cout << transitionToState << " : Does not exists yet"
          //           << std::endl;
          // How does this transient state deal with transactions
          std::string directoryStartState =
              "directory_" + utils::parseStateIntoTokens(logicalStartState)[1];
          // Msg Sent -- TODO - deduce this
          std::string msgSent = "PutM";

          // Find the directory handler (directoryStartState, msgSent)
          // discover what message it reponds to
          std::string directoryEndState;

          // Walk over all directory handlers
          mod.walk([&](mlir::pcc::FunctionOp f) {
            std::string fMac =
                f.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
            if (fMac == "directory") {

              // Get the directory start state
              std::string fStartState = f.getAttr("cur_state")
                                            .cast<mlir::StringAttr>()
                                            .getValue()
                                            .str();
              // if the directory start state matches expected start state
              if (fStartState == directoryStartState) {
                // walk through all the msg constructors - get the message sent
                f.walk([&](mlir::pcc::MsgConstrOp msgContrOp) {
                  std::string msgSent = msgContrOp.getAttr("params")
                                            .cast<mlir::ArrayAttr>()[0]
                                            .cast<mlir::StringAttr>()
                                            .getValue()
                                            .str();

                  // if the sent message matches the handler function action
                  if (msgSent == hfuncAction) {
                    // get the directory end state
                    if (f.getAttr("end_state") == nullptr) {
                      directoryEndState = fStartState;

                    } else {
                      directoryEndState = f.getAttr("end_state")
                                              .cast<mlir::StringAttr>()
                                              .getValue()
                                              .str();
                    }
                  }
                });
              }
            }
          });

          std::string msgSentByDirectoryWhenMessageEventuallyArrives;
          mod.walk([&](mlir::pcc::FunctionOp dirHandler) {
            std::string dMac = dirHandler.getAttr("machine")
                                   .cast<mlir::StringAttr>()
                                   .getValue()
                                   .str();
            if (dMac == "directory") {
              std::string dCurState = dirHandler.getAttr("cur_state")
                                          .cast<mlir::StringAttr>()
                                          .getValue()
                                          .str();
              std::string dAction = dirHandler.getAttr("action")
                                        .cast<mlir::StringAttr>()
                                        .getValue()
                                        .str();
              if (dCurState == directoryEndState && dAction == msgSent) {
                dirHandler.walk([&](mlir::pcc::MsgConstrOp mconstructor) {
                  msgSentByDirectoryWhenMessageEventuallyArrives =
                      mconstructor.getAttr("params")
                          .cast<mlir::ArrayAttr>()[0]
                          .cast<mlir::StringAttr>()
                          .getValue()
                          .str();
                });
              }
            }
          });

          // std::cout << "Expected Response from directory : "
          //           << msgSentByDirectoryWhenMessageEventuallyArrives
          //           << std::endl;

          // Now find the cache handler for msgSentByDirectoryWhenMessage
          // Eventually Arrives
          mod.walk([&](mlir::pcc::FunctionOp pccFunc) {
            std::string pccFuncAction = pccFunc.getAttr("action")
                                            .cast<mlir::StringAttr>()
                                            .getValue()
                                            .str();
            if (pccFuncAction ==
                msgSentByDirectoryWhenMessageEventuallyArrives) {

              mlir::pcc::FunctionOp newTransientStateHandler = rewriter.create<
                  mlir::pcc::FunctionOp>(
                  rewriter.getUnknownLoc(),
                  /* machine */ machine,
                  /* start state */ transitionToState,
                  /* action */ msgSentByDirectoryWhenMessageEventuallyArrives);
              rewriter.inlineRegionBefore(
                  pccFunc.clone().getRegion(),
                  newTransientStateHandler.getRegion(),
                  newTransientStateHandler.getRegion().end());
            }
          });
        }

        // Create the handler function
        mlir::pcc::FunctionOp racingTransactionHandler =
            rewriter.create<mlir::pcc::FunctionOp>(
                rewriter.getUnknownLoc(), machine, cur_state, hfuncAction,
                transitionToState);
        mlir::pcc::FunctionOp fClone = hfunc.clone();
        rewriter.inlineRegionBefore(fClone.getRegion(),
                                    racingTransactionHandler.getRegion(),
                                    racingTransactionHandler.getRegion().end());
        return mlir::success();
      }
    }
    return mlir::failure();
  }

  std::vector<mlir::pcc::FunctionOp>
  getAllLogicalStartStateHandlerFunctions(std::string logicalStartState,
                                          mlir::ModuleOp mod) const {
    std::vector<mlir::pcc::FunctionOp> funs;
    std::vector<std::string> allMsgTypes = utils::getAllMsgTypes(mod);

    // for every pcc function
    for (mlir::Operation &operation :
         mod.getRegion().getBlocks().front().getOperations()) {
      if (mlir::dyn_cast<mlir::pcc::FunctionOp>(operation) != nullptr) {
        mlir::pcc::FunctionOp funOp =
            mlir::dyn_cast<mlir::pcc::FunctionOp>(operation);
        // check the attributes
        std::string cur_stateFunc = funOp.getAttr("cur_state")
                                        .cast<mlir::StringAttr>()
                                        .getValue()
                                        .str();
        std::string actionFunc =
            funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
        // if cur_state is the logical start state AND allMsgs contains the
        // actionFunc
        if (logicalStartState == cur_stateFunc &&
            (std::find(allMsgTypes.begin(), allMsgTypes.end(), actionFunc) !=
             allMsgTypes.end())) {
          // This is a function that can execute
          funs.push_back(funOp);
        }
      }
    }
    return funs;
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

  // patterns.insert<GenerateTransientStates>(&getContext());
  patterns.insert<OptimizeRacingTransactions>(&getContext());

  if (mlir::failed(mlir::applyPatternsAndFoldGreedily(getOperation(),
                                                      std::move(patterns)))) {
    return signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createProtogenOptimizationPass() {
  return std::make_unique<ProtogenPass>();
}