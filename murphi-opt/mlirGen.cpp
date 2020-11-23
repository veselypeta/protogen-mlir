#include "ProtoCCVisitor.h"
#include "antlr4-runtime.h"
#include <iostream>
#include <utility>

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "mlir/InitAllDialects.h"

#include "PCC/Dialect.h"
#include "PCC/Ops.h"

#include "ProtoCCLexer.h"
#include "mlirGen.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/ScopedHashTable.h"
#include "llvm/Support/raw_ostream.h"
#include <numeric>

namespace {
class MLIRGenImpl {

public:
  MLIRGenImpl(mlir::MLIRContext &context) : builder(&context) {}

  mlir::ModuleOp mlirGen(ProtoCCParser::DocumentContext *ctx) {
    // Create an empty module to which operations are added
    theModule = mlir::ModuleOp::create(builder.getUnknownLoc());

    for (auto declCtx : ctx->const_decl()) {
      mlirGen(declCtx);
    }

    for (auto initHWCtx : ctx->init_hw()) {
      mlirGen(initHWCtx);
    }

    for (auto archBlockCtx : ctx->arch_block()) {
      mlirGen(archBlockCtx);
    }

    // theModule.dump();

    if (mlir::failed(mlir::verify(theModule))) {
      theModule.emitError("Module Verification Error");
      return nullptr;
    }

    return theModule;
  }

private:
  mlir::ModuleOp theModule;

  mlir::OpBuilder builder;

  mlir::LogicalResult mlirGen(ProtoCCParser::Const_declContext *ctx) {
    std::string id = ctx->ID()->getText();
    int value = std::atoi((ctx->INT())->toString().c_str());
    theModule.push_back(makeConstantOp(id.c_str(), value));
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Init_hwContext *ctx) {
    if (ctx->network_block()) {
      return mlirGen(ctx->network_block());
    }
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Network_blockContext *ctx) {
    for (auto netwElem : ctx->network_element()) {
      mlirGen(netwElem);
    }
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Network_elementContext *ctx) {
    std::string networkId = ctx->ID()->toString();
    std::string networkOrdering = ctx->getStart()->getText();
    antlr4::Token *netToken = ctx->getStop(); // TODO - get the correct token
    mlir::pcc::NetworkDeclOp netOp = makeNetworkDeclOp(
        networkId.c_str(), networkOrdering.c_str(), *netToken);
    theModule.push_back(netOp);
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Arch_blockContext *ctx) {
    // get the id of the architecture
    std::string id = ctx->ID()->getText();

    auto funcType = builder.getFunctionType(
        llvm::None,
        llvm::None); // TODO - set the type of the function correctly
    mlir::FuncOp function =
        mlir::FuncOp::create(builder.getUnknownLoc(), id, funcType);

    auto entryBlock = function.addEntryBlock();
    builder.setInsertionPointToStart(entryBlock);

    mlirGen(ctx->arch_body());

    builder.setInsertionPointToEnd(entryBlock);
    builder.create<mlir::ReturnOp>(builder.getUnknownLoc());
    theModule.push_back(function);
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Arch_bodyContext *ctx) {
    for (auto processCtx : ctx->process_block()) {
      if (mlir::failed(mlirGen(processCtx))) {
        return mlir::failure();
      }
    }
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Process_blockContext *ctx) {
    ProtoCCParser::Arch_blockContext *parentArchCtx =
        dynamic_cast<ProtoCCParser::Arch_blockContext *>(ctx->parent->parent);
    if (parentArchCtx == nullptr) {
      return mlir::failure();
    }
    std::string functionName =
        parentArchCtx->ID()->getText() + "_" +
        ctx->process_trans()->ID()->getText() + "_" +
        ctx->process_trans()->process_events()->getText();
    auto func_type = builder.getFunctionType(llvm::None, llvm::None);
    auto function = builder.create<mlir::FuncOp>(builder.getUnknownLoc(),
                                                 functionName, func_type);
    auto entryBlock = function.addEntryBlock();

    builder.setInsertionPointToStart(entryBlock);

    for (auto processBodyCtx : ctx->process_expr()) {
      if (mlir::failed(mlirGen(processBodyCtx))) {
        return mlir::failure();
      }
    }

    builder.create<mlir::ReturnOp>(builder.getUnknownLoc());

    // Restore the insertion point
    builder.setInsertionPointAfter(function);
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Process_exprContext *ctx) {
    if (ctx->expressions() != nullptr) {
      return mlirGen(ctx->expressions());
    }
    if (ctx->network_send() != nullptr) {
      return mlirGen(ctx->network_send());
    }
      return mlir::success();
  }

  // Generate correct MLIR for an expression
  mlir::LogicalResult mlirGen(ProtoCCParser::ExpressionsContext *ctx) {
    if (ctx->assignment() != nullptr) {
      return mlirGen(ctx->assignment());
    }
    if (ctx->conditional() != nullptr) {
      // TODO - conditional
    }
    if (ctx->object_block() != nullptr) {
      // TODO - object instantiation
    }
    if (ctx->set_block() != nullptr) {
      // TODO - set block
    }
    if (ctx->internal_event_block() != nullptr) {
      // TODO - internal event block b
    }
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::AssignmentContext *ctx) {
    auto finalStateId = ctx->process_finalident()->getText();
    return mlir::success();
  }

  // Generate MLIR for Network Send
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_sendContext *ctx){
    auto ids = ctx->ID();
    std::string netId = ids[0]->getText();
    std::string msgId = ids[1]->getText();

    // TODO - build a SendOp from network_decl and msg type
    // mlir::Value netInput = builder.getI64IntegerAttr(22);
    // mlir::Value msgInput = builder.getStringAttr(msgId);
    // builder.create<mlir::pcc::SendOp>(builder.getUnknownLoc(), llvm::None, llvm::None);
    return mlir::success();
  }

  mlir::pcc::ConstantOp makeConstantOp(const char *id, const int value) {
    mlir::Type intType = builder.getI64Type();
    mlir::IntegerAttr valueAttribute = mlir::IntegerAttr::get(intType, value);
    mlir::StringAttr idAttribute = builder.getStringAttr(id);

    return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                 idAttribute, valueAttribute);
  }

  mlir::pcc::NetworkDeclOp
  makeNetworkDeclOp(const char *id, const char *ordering, antlr4::Token &tok) {
    mlir::pcc::NetworkType netType =
        mlir::pcc::NetworkType::get(builder.getContext());
    mlir::StringAttr idAttribute = builder.getStringAttr(id);
    mlir::StringAttr orderingAttribute = builder.getStringAttr(ordering);
    return builder.create<mlir::pcc::NetworkDeclOp>(
        getLoc(tok), netType, idAttribute, orderingAttribute);
  }

  std::vector<std::string>
  getStableStates(ProtoCCParser::Stable_defContext *ctx) {
    std::vector<std::string> stable_states;
    for (auto state : ctx->ID()) {
      stable_states.push_back(state->getText());
    }
    return stable_states;
  }

  mlir::Location getLoc(antlr4::Token &tok) {
    antlr4::TokenSource *source = tok.getTokenSource();
    auto line = source->getLine();
    auto col = source->getCharPositionInLine();
    auto file = source->getSourceName();
    return builder.getFileLineColLoc(builder.getIdentifier(file), line, col);
  }
};

} // namespace

namespace pcc {
mlir::OwningModuleRef mlirGen(mlir::MLIRContext &mlirCtx,
                              ProtoCCParser::DocumentContext *docCtx) {
  return MLIRGenImpl(mlirCtx).mlirGen(docCtx);
}
} // namespace pcc