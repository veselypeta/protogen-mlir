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
#include <memory>
#include <vector>

using namespace mlir;

std::vector<std::string> split(const std::string &str,
                               const std::string &delim) {
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos)
      pos = str.length();
    std::string token = str.substr(prev, pos - prev);
    if (!token.empty())
      tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

// A set of rewrite patterns are added to a pass --- This rewrites a a
// pcc::ConstantOp as muprhi::ConstantOp
struct ConstantOpLowering : public OpRewritePattern<mlir::pcc::ConstantOp> {

  ConstantOpLowering(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::ConstantOp>(context, /*benefit*/ 1) {}

  using OpRewritePattern<mlir::pcc::ConstantOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::ConstantOp op,
                                      PatternRewriter &rewriter) const final {
    // TODO -- Try and find a "murphi::ConstantDecl Operation -- insert the new
    // operation in the attacked region"
    rewriter.replaceOpWithNewOp<mlir::murphi::ConstantOp>(op, op.getAttr("id"),
                                                          op.getAttr("value"));
    return success();
  }
};

struct AwaitOpLowering : public OpRewritePattern<mlir::pcc::AwaitOp> {
  AwaitOpLowering(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::AwaitOp>(context, /*benefit*/ 1) {}

  using OpRewritePattern<mlir::pcc::AwaitOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::AwaitOp awaitOp,
                                      PatternRewriter &rewriter) const final {

    mlir::pcc::FunctionOp parentFunc =
        awaitOp.getParentOfType<mlir::pcc::FunctionOp>();

    mlir::ModuleOp moduleOp = awaitOp.getParentOfType<mlir::ModuleOp>();

    // Get the Attributes from the parent op;
    std::string machineAttr =
        parentFunc.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string actionAttr =
        parentFunc.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string cur_stateAttr = parentFunc.getAttr("cur_state")
                                    .cast<mlir::StringAttr>()
                                    .getValue()
                                    .str();

    // Walk any When Operations -- at the first level of nesting
    awaitOp.walk([&](mlir::Operation *op) {
      // skip over any operations that arent WhenOp
      if (dyn_cast<mlir::pcc::WhenOp>(op) == nullptr) {
        return mlir::WalkResult::advance();
      }

      // Cast To a WhenOp
      mlir::pcc::WhenOp whenOp = dyn_cast<mlir::pcc::WhenOp>(op);

      // if the whenOp has parent AwaitOp -- which then has parent WhenOp
      // The we skip this one
      if (dyn_cast<mlir::pcc::WhenOp>(whenOp.getParentOp()->getParentOp()) !=
          nullptr) {
        return mlir::WalkResult::advance();
      }

      std::string msgId =
          whenOp.getAttr("msgId").cast<mlir::StringAttr>().getValue().str();

      std::string newState = cur_stateAttr + "_" + actionAttr;

      // Set insertion Point to Module
      rewriter.setInsertionPointToStart(
          &moduleOp.getBodyRegion().getBlocks().front());

      // Create the new function
      mlir::pcc::FunctionOp newFunc = rewriter.create<mlir::pcc::FunctionOp>(
          rewriter.getUnknownLoc(), machineAttr, newState, msgId);

      // Create the entry block for the function -- and add to function
      mlir::Block *entryBlock = new mlir::Block();
      newFunc.region().push_back(entryBlock);

      // Set insertion point to inside of the function
      rewriter.setInsertionPointToStart(entryBlock);

      // TODO -- Copy nested operations here; -- Don't know how to do this!!
      mlir::pcc::WhenOp whenClone = whenOp.clone();

      rewriter.insert(whenClone);

      // Add the return Op at the end;
      mlir::Value v;
      rewriter.create<mlir::pcc::ReturnOp>(rewriter.getUnknownLoc(), v);
    });

    // Erase The Await Op
    rewriter.eraseOp(awaitOp);
    return success();
    // rewriter.notifyOperationInserted(clonedfn);
  }
};

struct WhenOpLowering : public OpRewritePattern<mlir::pcc::WhenOp> {
  WhenOpLowering(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::WhenOp>(context, /*benefit*/ 1) {}

  using OpRewritePattern<mlir::pcc::WhenOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::WhenOp whenOp,
                                      PatternRewriter &rewriter) const final {

    mlir::pcc::FunctionOp parentFunc =
        whenOp.getParentOfType<mlir::pcc::FunctionOp>();

    mlir::ModuleOp moduleOp = whenOp.getParentOfType<mlir::ModuleOp>();
    // rewriter.setInsertionPointToStart(
    //     &moduleOp.getBodyRegion().getBlocks().front());

    // If the parent->parent of the when op is 'When' then this is a nested when and we skip
    if(dyn_cast<mlir::pcc::WhenOp>(whenOp.getParentOp()->getParentOp()) != nullptr){
      return mlir::failure();
    }

    // Parent Function Attributes
    std::string machineAttr =
        parentFunc.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string actionAttr =
        parentFunc.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string curStateAttr = parentFunc.getAttr("cur_state")
                                   .cast<mlir::StringAttr>()
                                   .getValue()
                                   .str();

    // When Op MsgId
    std::string msgId =
        whenOp.getAttr("msgId").cast<mlir::StringAttr>().getValue().str();

    // Calculate new Transient State
    std::string newCurStateId = curStateAttr + "_" + actionAttr;

    // Generate a new function with these new attributes
    // mlir::pcc::FunctionOp newFunc = rewriter.create<mlir::pcc::FunctionOp>(
    //     rewriter.getUnknownLoc(), machineAttr, newCurStateId, msgId);
    // mlir::Block *block = new mlir::Block();
    // newFunc.region().push_back(block);

    // rewriter.setInsertionPointToStart(block);

    // TODO -- Copy operations inside of when op to new function;
    // ---- HELP !!! ---

    // mlir::Value v;
    // rewriter.create<mlir::pcc::ReturnOp>(rewriter.getUnknownLoc(), v);

    // Erase the when Op
    rewriter.eraseOp(whenOp);

    return mlir::success();
  }
};

struct FunctionOpLowering : public OpRewritePattern<mlir::pcc::FunctionOp> {
  FunctionOpLowering(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::FunctionOp>(context, /*benefit*/ 1) {}

  using OpRewritePattern<mlir::pcc::FunctionOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::FunctionOp funOp,
                                      PatternRewriter &rewriter) const final {

    return mlir::success();
  }
};

namespace {
struct MyPass : public PCCToMurphiPassBase<MyPass> {
  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<murphi::MurphiDialect>();
    registry.insert<pcc::PCCDialect>();
  }
  void runOnOperation() override;
};
} // namespace

void MyPass::runOnOperation() {
  OwningRewritePatternList patterns;

  // patterns.insert<ConstantOpLowering>(&getContext());
  // Potentially unnecessary since covered by Await Op Lowering
  patterns.insert<WhenOpLowering>(&getContext());
  // patterns.insert<AwaitOpLowering>(&getContext());
  // patterns.insert<FunctionOpLowering>(&getContext());

  if (mlir::failed(mlir::applyPatternsAndFoldGreedily(getOperation(),
                                                      std::move(patterns)))) {
    return signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createLowerToMurphiPass() {
  return std::make_unique<MyPass>();
}