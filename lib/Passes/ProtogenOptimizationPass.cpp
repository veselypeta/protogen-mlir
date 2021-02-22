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
using namespace mlir;

class GenerateTransientStates
    : public mlir::OpRewritePattern<mlir::pcc::FunctionOp> {
  GenerateTransientStates(mlir::MLIRContext *context)
      : OpRewritePattern<mlir::pcc::FunctionOp>(context, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::FunctionOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::FunctionOp funcOp,
                                      PatternRewriter &rewriter) const final {

    mlir::ModuleOp mod = funcOp.getParentOfType<mlir::ModuleOp>();

    
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

  if (mlir::failed(mlir::applyPatternsAndFoldGreedily(getOperation(),
                                                      std::move(patterns)))) {
    return signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createProtogenOptimizationPass() {
  return std::make_unique<ProtogenPass>();
}