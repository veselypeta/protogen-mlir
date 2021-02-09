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

namespace {
struct ConvertPCCPass : public ConvertPCCToMurphiBase<ConvertPCCPass> {
  void getDependentDialects(mlir::DialectRegistry &registry) const override {
    registry.insert<mlir::murphi::MurphiDialect>();
    registry.insert<mlir::pcc::PCCDialect>();
  }
  void runOnOperation() override;
};
} // namespace

void ConvertPCCPass::runOnOperation() {
  mlir::MLIRContext &ctx = getContext();
  mlir::ConversionTarget target(ctx);

  target.addLegalDialect<mlir::murphi::MurphiDialect>();

  target.addIllegalDialect<mlir::pcc::PCCDialect>();

  // create the patterns
  mlir::OwningRewritePatternList patterns;

  // insert patterns

  // apply the conversion
  auto module = getOperation();
  if (mlir::failed(mlir::applyFullConversion(module, target, std::move(patterns)))) {
    mlir::Pass::signalPassFailure();
  }
} 


// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createPCCToMurphiPass() {
  return std::make_unique<ConvertPCCPass>();
}