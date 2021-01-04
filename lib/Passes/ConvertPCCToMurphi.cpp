#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "Murphi/MurphiDialect.h"
#include "Murphi/MurphiOps.h"

#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"
#include "llvm/ADT/Sequence.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

#include <memory>


using namespace mlir;



// A set of rewrite patterns are added to a pass --- This rewrites a a pcc::ConstantOp as muprhi::ConstantOp
struct ConstantOpLowering: public OpRewritePattern<mlir::pcc::ConstantOp> {

    ConstantOpLowering(mlir::MLIRContext *context) : OpRewritePattern<mlir::pcc::ConstantOp>(context, /*benefit*/ 1){}

    using OpRewritePattern<mlir::pcc::ConstantOp>::OpRewritePattern;

    mlir::LogicalResult  matchAndRewrite(mlir::pcc::ConstantOp op, PatternRewriter &rewriter) const final {

        rewriter.replaceOpWithNewOp<mlir::murphi::ConstantOp>(op, op.getAttr("id"), op.getAttr("value"));
        return success();
    }
};


namespace {
    struct MyPass: public PCCToMurphiPassBase<MyPass>{
        void getDependentDialects(DialectRegistry &registry) const override {
            registry.insert<murphi::MurphiDialect>();
            registry.insert<pcc::PCCDialect>();
        }
        void runOnOperation() override;
    };   
}

// override the runOnFunction()
void MyPass::runOnOperation() {

    mlir::ConversionTarget target(getContext());

    // We cant to convert PCC to Murphi
    // target.addLegalDialect<murphi::MurphiDialect>();
    // target.addIllegalDialect<pcc::PCCDialect>();
    target.addIllegalOp<pcc::ConstantOp>();

    OwningRewritePatternList patterns;

    patterns.insert<ConstantOpLowering>(&getContext());

    if (failed(applyPartialConversion(getOperation(), target, std::move(patterns)))){
        signalPassFailure();
    }
}


// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createLowerToMurphiPass() {
    return std::make_unique<MyPass>();
}