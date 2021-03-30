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

struct SetOpConversion : public OpRewritePattern<mlir::pcc::SetOp> {
  SetOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetOp pccSetOP,
                                      PatternRewriter &rewriter) const final {
    mlir::Attribute setId = pccSetOP.getAttr("id");
    mlir::Attribute setValue = pccSetOP.getAttr("value");

    rewriter.replaceOpWithNewOp<mlir::murphi::SetOp>(pccSetOP, setId, setValue);

    return mlir::success();
  }
};

struct MsgConstrConversion : public OpRewritePattern<mlir::pcc::MsgConstrOp> {
  MsgConstrConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::MsgConstrOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::MsgConstrOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::MsgConstrOp pccMsgConstrOp,
                                      PatternRewriter &rewriter) const final {
    mlir::ArrayAttr params =
        pccMsgConstrOp.getAttr("params").cast<mlir::ArrayAttr>();
    mlir::Attribute msgType = pccMsgConstrOp.getAttr("msgType");
    rewriter.replaceOpWithNewOp<mlir::murphi::MsgConstrOp>(
        pccMsgConstrOp, pccMsgConstrOp.getType(), params, msgType);

    return mlir::success();
  }
};

struct SendOpConversion : public OpRewritePattern<mlir::pcc::SendOp> {
  SendOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SendOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SendOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SendOp pccSendOp,
                                      PatternRewriter &rewriter) const final {

    mlir::Value msgConstrResult = pccSendOp.msg();
    mlir::Value sendNetId = pccSendOp.netId();
    rewriter.replaceOpWithNewOp<mlir::murphi::SendOp>(
        pccSendOp, msgConstrResult, sendNetId);
    return mlir::success();
  }
};

struct MathOpConversion : public OpRewritePattern<mlir::pcc::MathOp> {
  MathOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::MathOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::MathOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::MathOp pccMathOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::MathOp>(
        pccMathOp, pccMathOp.getResult().getType(), pccMathOp.lhs(),
        pccMathOp.rhs(), pccMathOp.opAttr(), pccMathOp.idAttr());
  }
};

struct ReturnOpConversion : public OpRewritePattern<mlir::pcc::ReturnOp> {
  ReturnOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::ReturnOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::ReturnOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::ReturnOp pccRetOp,
                                      PatternRewriter &rewriter) const final {

    mlir::Value v;
    rewriter.replaceOpWithNewOp<mlir::murphi::ReturnOp>(pccRetOp, v);
    return mlir::success();
  }
};

struct IfOpConversion : public OpRewritePattern<mlir::pcc::IfOp> {
  IfOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::IfOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::IfOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::IfOp pccIfOp,
                                      PatternRewriter &rewriter) const final {

    rewriter.setInsertionPointAfter(pccIfOp);

    mlir::murphi::IfOp murIfOp = rewriter.create<mlir::murphi::IfOp>(
        rewriter.getUnknownLoc(), pccIfOp.getAttr("lhs"),
        pccIfOp.getAttr("comparison"), pccIfOp.getAttr("rhs"));

    rewriter.createBlock(&murIfOp.getRegion());

    for (mlir::Operation &op :
         pccIfOp.getRegion().getBlocks().front().getOperations()) {

      mlir::Operation *clone = op.clone();
      rewriter.insert(clone);
    }
    rewriter.eraseOp(pccIfOp);

    return mlir::success();
  }
};

struct ExIfOpConversion : public OpRewritePattern<mlir::pcc::ExIfOp> {
  ExIfOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::ExIfOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::ExIfOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::ExIfOp pccExIfOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.setInsertionPointAfter(pccExIfOp);

    mlir::pcc::ExIfOp ifOpClone = pccExIfOp.clone();

    // create the new murphi op
    mlir::murphi::ExIfOp murphiExIfOp = rewriter.create<mlir::murphi::ExIfOp>(
        rewriter.getUnknownLoc(), pccExIfOp.getOperand());

    // inline the regions
    rewriter.inlineRegionBefore(ifOpClone.getThenRegion(),
                                murphiExIfOp.getThenRegion(),
                                murphiExIfOp.getThenRegion().end());

    rewriter.inlineRegionBefore(ifOpClone.getElseRegion(),
                                murphiExIfOp.getElseRegion(),
                                murphiExIfOp.getElseRegion().end());

    rewriter.eraseOp(pccExIfOp);

    return mlir::success();
  }
};

struct NetworkDeclOpConversion
    : public OpRewritePattern<mlir::pcc::NetworkDeclOp> {
  NetworkDeclOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::NetworkDeclOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::NetworkDeclOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::NetworkDeclOp pccNetDeclOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::NetworkDeclOp>(
        pccNetDeclOp, pccNetDeclOp.getResult().getType(),
        pccNetDeclOp.getAttr("id"), pccNetDeclOp.getAttr("ordering"));
    return mlir::success();
  }
};

struct ObjRefOpConvervsion : public OpRewritePattern<mlir::pcc::ObjRefOp> {
  ObjRefOpConvervsion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::ObjRefOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::ObjRefOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::ObjRefOp pccObjRef,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::ObjRefOp>(
        pccObjRef, pccObjRef.getResult().getType(),
        pccObjRef.getAttr("objId").cast<mlir::StringAttr>(),
        pccObjRef.getAttr("ident").cast<mlir::StringAttr>(),
        pccObjRef.getAttr("id").cast<mlir::StringAttr>());
    return mlir::success();
  }
};

struct CompareOpConvervsion : public OpRewritePattern<mlir::pcc::CompareOp> {
  CompareOpConvervsion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::CompareOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::CompareOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::CompareOp pccCompOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::CompareOp>(
        pccCompOp, pccCompOp.getResult().getType(), pccCompOp.getOperand(0),
        pccCompOp.getOperand(1),
        pccCompOp.getAttr("oper").cast<mlir::StringAttr>(),
        pccCompOp.getAttr("id").cast<mlir::StringAttr>());
    return mlir::success();
  }
};

struct ConstantOpConvervsion : public OpRewritePattern<mlir::pcc::ConstantOp> {
  ConstantOpConvervsion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::ConstantOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::ConstantOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::ConstantOp pccConstOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::ConstantOp>(
        pccConstOp, pccConstOp.getResult().getType(), pccConstOp.getAttr("id"),
        pccConstOp.getAttr("value"));
    return mlir::success();
  }
};

struct EndIfOpConversion : public OpRewritePattern<mlir::pcc::EnfIfOp> {
  EndIfOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::EnfIfOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::EnfIfOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::EnfIfOp pccEndIfOp,
                                      PatternRewriter &rewriter) const final {

    rewriter.replaceOpWithNewOp<mlir::murphi::EnfIfOp>(pccEndIfOp);
    return mlir::success();
  }
};

struct BreakOpConversion : public OpRewritePattern<mlir::pcc::BreakOp> {
  BreakOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::BreakOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::BreakOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::BreakOp pccBreakOp,
                                      PatternRewriter &rewriter) const final {
    if (pccBreakOp.getParentOfType<mlir::pcc::FunctionOp>() == nullptr ||
        pccBreakOp.getParentOfType<mlir::murphi::FunctionOp>() == nullptr) {
      mlir::Value v;
      rewriter.replaceOpWithNewOp<mlir::murphi::ReturnOp>(pccBreakOp, v);
    } else {
      rewriter.eraseOp(pccBreakOp);
    }
    return mlir::success();
  }
};

struct SetAddOpConversion : public OpRewritePattern<mlir::pcc::SetAddOp> {
  SetAddOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetAddOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetAddOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetAddOp pccSetAddOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::SetAddOp>(
        pccSetAddOp, pccSetAddOp.getOperand(0), pccSetAddOp.getOperand(1));
    return mlir::success();
  }
};

struct SetContainsOpConversion
    : public OpRewritePattern<mlir::pcc::SetContainsOp> {
  SetContainsOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetContainsOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetContainsOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetContainsOp pccSetContainsOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::SetContainsOp>(
        pccSetContainsOp, pccSetContainsOp.getResult().getType(),
        pccSetContainsOp.getOperand(0), pccSetContainsOp.getOperand(1),
        pccSetContainsOp.id());
    return mlir::success();
  }
};

struct SetDelOpConversion : public OpRewritePattern<mlir::pcc::SetDelOp> {
  SetDelOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetDelOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetDelOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetDelOp pccSetDelOp,
                                      PatternRewriter &rewriter) const final {
    assert(pccSetDelOp.getOperand(0) != nullptr &&
           "SetDelOp operand is nullptr");
    assert(pccSetDelOp.getOperand(1) != nullptr &&
           "SetDelOp operand is nullptr");
    rewriter.replaceOpWithNewOp<mlir::murphi::SetDelOp>(
        pccSetDelOp, pccSetDelOp.getOperand(0), pccSetDelOp.getOperand(1));
    return mlir::success();
  }
};

struct SetCountOpConversion : public OpRewritePattern<mlir::pcc::SetCountOp> {
  SetCountOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetCountOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetCountOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetCountOp pccSetCountOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::SetCountOp>(
        pccSetCountOp, pccSetCountOp.getResult().getType(),
        pccSetCountOp.getOperand(), pccSetCountOp.id());
    return mlir::success();
  }
};

struct SetClearOpConversion : public OpRewritePattern<mlir::pcc::SetClearOp> {
  SetClearOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::SetClearOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::SetClearOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::SetClearOp pccSetClearOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::SetClearOp>(
        pccSetClearOp, pccSetClearOp.getOperand());
    return mlir::success();
  }
};

struct MCastOpConversion : public OpRewritePattern<mlir::pcc::MCastOp> {
  MCastOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::MCastOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::MCastOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::MCastOp pccMCastOp,
                                      PatternRewriter &rewriter) const final {
    rewriter.replaceOpWithNewOp<mlir::murphi::MCastOp>(
        pccMCastOp, pccMCastOp.getOperand(0), pccMCastOp.getOperand(1),
        pccMCastOp.getOperand(2));
    return mlir::success();
  }
};

struct FunctionOpConversion : public OpRewritePattern<mlir::pcc::FunctionOp> {
  FunctionOpConversion(mlir::MLIRContext *ctx)
      : OpRewritePattern<mlir::pcc::FunctionOp>(ctx, /*benefit*/ 1){};
  using OpRewritePattern<mlir::pcc::FunctionOp>::OpRewritePattern;

  mlir::LogicalResult matchAndRewrite(mlir::pcc::FunctionOp pccFunctionOp,
                                      PatternRewriter &rewriter) const final {

    // Save the insertsion point
    auto savedIp = rewriter.saveInsertionPoint();

    // -- Check if PCC Function Op has an end-state attr
    // If so we need to insert a set - state operation at the end of the block
    mlir::Attribute end_state_attr = pccFunctionOp.getAttr("end_state");
    if (end_state_attr != nullptr) {
      std::string end_state =
          end_state_attr.cast<mlir::StringAttr>().getValue().str();

      mlir::Operation *r;
      for (auto &op :
           pccFunctionOp.getRegion().getBlocks().front().getOperations()) {
        auto rt = mlir::dyn_cast<mlir::pcc::ReturnOp>(op);
        auto mr = mlir::dyn_cast<mlir::murphi::ReleaseMutexOp>(op);
        if (rt != nullptr) {
          r = &op;
        }
        if (mr != nullptr) {
          r = &op;
          break;
        }
      }
      rewriter.setInsertionPoint(r);
      rewriter.create<mlir::murphi::SetOp>(rewriter.getUnknownLoc(), "State",
                                           end_state);
    }

    // set insertion point to end of current function
    rewriter.setInsertionPointAfter(pccFunctionOp);

    // create the new function to which we will copy the operations
    mlir::murphi::FunctionOp murFunOp =
        rewriter.create<mlir::murphi::FunctionOp>(
            rewriter.getUnknownLoc(), pccFunctionOp.getAttr("machine"),
            pccFunctionOp.getAttr("cur_state"),
            pccFunctionOp.getAttr("action"));

    rewriter.inlineRegionBefore(pccFunctionOp.getRegion(), murFunOp.getRegion(),
                                murFunOp.getRegion().end());

    // remove the old op
    rewriter.eraseOp(pccFunctionOp);

    // restore the insertion point
    rewriter.restoreInsertionPoint(savedIp);
    return mlir::success();
  }
};

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

  // murphi is the only legal dialect
  target.addLegalDialect<mlir::murphi::MurphiDialect>();

  // pcc is an illegal dialect
  target.addIllegalDialect<mlir::pcc::PCCDialect>();

  // module op is a legal op
  target.addLegalOp<mlir::ModuleOp>();
  target.addLegalOp<mlir::ModuleTerminatorOp>();

  // create the patterns
  mlir::OwningRewritePatternList patterns;

  // insert patterns
  patterns.insert<SetOpConversion>(&ctx);
  patterns.insert<MsgConstrConversion>(&ctx);
  patterns.insert<SendOpConversion>(&ctx);
  patterns.insert<MathOpConversion>(&ctx);
  patterns.insert<ReturnOpConversion>(&ctx);
  patterns.insert<EndIfOpConversion>(&ctx);
  patterns.insert<IfOpConversion>(&ctx);
  patterns.insert<ExIfOpConversion>(&ctx);
  patterns.insert<NetworkDeclOpConversion>(&ctx);
  patterns.insert<ObjRefOpConvervsion>(&ctx);
  patterns.insert<CompareOpConvervsion>(&ctx);
  patterns.insert<ConstantOpConvervsion>(&ctx);
  patterns.insert<BreakOpConversion>(&ctx);
  patterns.insert<SetAddOpConversion>(&ctx);
  patterns.insert<SetContainsOpConversion>(&ctx);
  patterns.insert<SetCountOpConversion>(&ctx);
  patterns.insert<SetClearOpConversion>(&ctx);
  // patterns.insert<SetDelOpConversion>(&ctx);
  patterns.insert<MCastOpConversion>(&ctx);
  patterns.insert<FunctionOpConversion>(&ctx);

  // apply the conversion
  auto theModule = getOperation();
  if (mlir::failed(
          mlir::applyFullConversion(theModule, target, std::move(patterns)))) {
    mlir::Pass::signalPassFailure();
  }
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createPCCToMurphiPass() {
  return std::make_unique<ConvertPCCPass>();
}