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

  mlir::LogicalResult matchAndRewrite(mlir::pcc::AwaitOp op,
                                      PatternRewriter &rewriter) const final {
    // Look at the state of the parent op
    mlir::pcc::FunctionOp f = dyn_cast<mlir::pcc::FunctionOp>(op.getParentOp());
    std::string f_cur_state =
        f.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
    std::string f_action =
        f.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string f_machine =
        f.getAttr("machine").cast<mlir::StringAttr>().getValue().str();

    
    mlir::ModuleOp module = dyn_cast<mlir::ModuleOp>(f.getParentOp());

    mlir::Attribute endStateAttr;

    op.walk([&](mlir::pcc::WhenOp whenOp) {
      std::string msgId =
          whenOp.getAttr("msgId").cast<mlir::StringAttr>().getValue().str();
      mlir::pcc::FunctionOp funOp = rewriter.create<mlir::pcc::FunctionOp>(
          rewriter.getUnknownLoc(), rewriter.getStringAttr(f_machine),
          rewriter.getStringAttr(f_cur_state + "_" + f_action), rewriter.getStringAttr(msgId),
          endStateAttr);


      mlir::Block *entryBlock = new mlir::Block();
      funOp.region().push_back(entryBlock);

      rewriter.setInsertionPointToStart(entryBlock);

      funOp.region().walk([&](mlir::Operation *op) { rewriter.insert(op); });

    });

    rewriter.eraseOp(op);
    return success();
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

  mlir::ConversionTarget target(getContext());

  // We cant to convert PCC to Murphi
  target.addLegalDialect<murphi::MurphiDialect>();
  // target.addIllegalDialect<pcc::PCCDialect>();
  // target.addIllegalOp<pcc::ConstantOp>();

  OwningRewritePatternList patterns;

  patterns.insert<ConstantOpLowering>(&getContext());
  patterns.insert<AwaitOpLowering>(&getContext());

  if (failed(applyPartialConversion(getOperation(), target,
                                    std::move(patterns)))) {
    signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createLowerToMurphiPass() {
  return std::make_unique<MyPass>();
}