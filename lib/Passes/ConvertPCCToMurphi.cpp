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

struct AwaitOpLowering : public OpRewritePattern<mlir::pcc::AwaitOp> {
  AwaitOpLowering(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::AwaitOp>(context, /*benefit*/ 1) {}

  using OpRewritePattern<mlir::pcc::AwaitOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::AwaitOp awaitOp,
                                      PatternRewriter &rewriter) const final {

    // Get the entry block of the opeartion
    mlir::Block &awaitEntryBlock = awaitOp.getRegion().front();
    for(mlir::Operation &op : awaitEntryBlock.getOperations()){
      // If anything except a await retrun op is found then it cannot be removed
      if(dyn_cast<mlir::pcc::AwaitReturnOp>(op) == nullptr){
        return mlir::failure();
      }
    }

    rewriter.eraseOp(awaitOp);
    return mlir::success();    
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

    // If the parent->parent of the when op is 'When' then this is a nested when
    // and we skip
    if (dyn_cast<mlir::pcc::WhenOp>(whenOp.getParentOp()->getParentOp()) !=
        nullptr) {
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

    // Set the insertion point to module
    rewriter.setInsertionPointToStart(
        &moduleOp.getBodyRegion().getBlocks().front());

    // Generate a new function with these new attributes
    mlir::pcc::FunctionOp newFunc = rewriter.create<mlir::pcc::FunctionOp>(
        rewriter.getUnknownLoc(), machineAttr, newCurStateId, msgId);
    mlir::Block *entryBlock = new mlir::Block();
    newFunc.region().push_back(entryBlock);

    // Set the insertion point to the start of the entry block
    rewriter.setInsertionPointToStart(entryBlock);

    // Iterate through the Nested Operations in the When Op Region and copy them
    // to the new function
    mlir::Region &srcEntryBlock = whenOp.getOperation()->getRegion(0);
    mlir::Block &block = srcEntryBlock.front();
    for (mlir::Operation &b : block.getOperations()) {
      mlir::Operation *clone = b.clone();
      // Skip the Break Operation
      if (dyn_cast<mlir::pcc::BreakOp>(clone) != nullptr) {
        continue;
      }
      // Copy the operation to the insertion point
      rewriter.insert(clone);
    }

    // Add a return Op to the Function
    mlir::Value v;
    rewriter.create<mlir::pcc::ReturnOp>(rewriter.getUnknownLoc(), v);

    // Erase the when Op
    rewriter.eraseOp(whenOp);

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

  patterns.insert<WhenOpLowering>(&getContext());
  patterns.insert<AwaitOpLowering>(&getContext());

  if (mlir::failed(mlir::applyPatternsAndFoldGreedily(getOperation(),
                                                      std::move(patterns)))) {
    return signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createLowerToMurphiPass() {
  return std::make_unique<MyPass>();
}