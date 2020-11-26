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
    // SymbolTableScopeT var_scope(symbolTable);

    for (auto declCtx : ctx->const_decl()) {
      mlirGen(declCtx);
    }

    for (auto initHWCtx : ctx->init_hw()) {
      mlirGen(initHWCtx);
    }

    for (auto archBlockCtx : ctx->arch_block()) {
      mlirGen(archBlockCtx);
    }

    if (mlir::failed(mlir::verify(theModule))) {
      theModule.emitError("Module Verification Error");
      return nullptr;
    }

    return theModule;
  }

private:
  mlir::ModuleOp theModule;

  mlir::OpBuilder builder;

  llvm::StringMap<std::pair<mlir::Type, ProtoCCParser::Message_blockContext *>>
      messageTypeMap;

  llvm::StringMap<mlir::Value> globals;

  llvm::ScopedHashTable<
      llvm::StringRef,
      std::pair<mlir::Value, ProtoCCParser::AssignmentContext *>>
      symbolTable;
  using SymbolTableScopeT = llvm::ScopedHashTableScope<
      llvm::StringRef,
      std::pair<mlir::Value, ProtoCCParser::AssignmentContext *>>;

  // Helper function to declare a variable in the current scope - fails if
  // variable with same name was already declared
  mlir::LogicalResult declare(mlir::Value value,
                              ProtoCCParser::AssignmentContext *ctx) {

    std::string key = ctx->process_finalident()->getText();

    /// --- WARNING --- THIS IS A MEMORY LEAK!!! --- This buffer needs to
    /// persist
    char *idBuffer = (char *)malloc(sizeof(char) * key.length());
    strcpy(idBuffer, key.c_str());
    if (symbolTable.count(key)) {
      return mlir::failure();
    }
    symbolTable.insert(idBuffer, {value, ctx});
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Const_declContext *ctx) {
    std::string id = ctx->ID()->getText();
    int value = std::atoi((ctx->INT())->toString().c_str());
    theModule.push_back(makeConstantOp(id.c_str(), value));
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Init_hwContext *ctx) {
    if (ctx->network_block() != nullptr) {
      return mlirGen(ctx->network_block());
    }
    if (ctx->message_block() != nullptr) {
      std::string messageTypeId = ctx->message_block()->ID()->getText();
      std::vector<mlir::Type> elementTypes;
      if (messageTypeMap.count(messageTypeId)) {
        // TODO - return mlir::emitError();
        return mlir::failure();
      }

      // push back default message constructor values
      mlir::Type messageId = builder.getI64Type();
      mlir::Type sourceId = builder.getI64Type();
      mlir::Type destId = builder.getI64Type();
      elementTypes.push_back(messageId);
      elementTypes.push_back(sourceId);
      elementTypes.push_back(destId);

      for (auto decl : ctx->message_block()->declarations()) {
        mlir::Type declType = getType(decl);
        elementTypes.push_back(declType);
      }
      messageTypeMap.try_emplace(messageTypeId,
                                 mlir::pcc::MsgType::get(elementTypes),
                                 ctx->message_block());
      return mlir::success();
    }
    return mlir::success();
  }

  mlir::Type getType(ProtoCCParser::DeclarationsContext *ctx) {
    if (ctx->bool_decl() != nullptr) {
      return builder.getI1Type();
    }
    if (ctx->int_decl() != nullptr) {
      return builder.getI64Type();
    }
    if (ctx->data_decl() != nullptr) {
      return mlir::pcc::DataType::get(builder.getContext());
    }
    return nullptr;
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Network_blockContext *ctx) {
    for (auto netwElem : ctx->network_element()) {
      if (mlir::failed(mlirGen(netwElem))) {
        return mlir::failure();
      }
    }
    return mlir::success();
  }

  mlir::LogicalResult mlirGen(ProtoCCParser::Network_elementContext *ctx) {
    std::string networkId = ctx->ID()->toString();
    std::string networkOrdering = ctx->getStart()->getText();
    antlr4::Token *netToken = ctx->getStop(); // TODO - get the correct token
    mlir::pcc::NetworkDeclOp netOp = makeNetworkDeclOp(
        networkId.c_str(), networkOrdering.c_str(), *netToken);
    globals.insert({networkId, netOp});
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
    // Create a scope in the symbol table to hold variable declarations.
    SymbolTableScopeT var_scope(symbolTable);

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
      mlirGen(ctx->assignment());
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

  mlir::Value mlirGen(ProtoCCParser::AssignmentContext *ctx) {
    std::string assignmentId = ctx->process_finalident()->getText();
    if (ctx->assign_types()->message_constr() != nullptr) {
      mlir::Value result = mlirGen(ctx->assign_types()->message_constr());
      if (!mlir::succeeded(declare(result, ctx))) {
        return nullptr;
      }
      return result;
    }
    if (ctx->assign_types()->INT() != nullptr) {
      int intValue = std::atoi(ctx->assign_types()->INT()->getText().c_str());
      mlir::IntegerAttr intAttr = builder.getI64IntegerAttr(intValue);
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      mlir::Value result = builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), idAttr, intAttr);
      if (!mlir::succeeded(declare(result, ctx))) {
        return nullptr;
      }
      return result;
    }
    if (ctx->assign_types()->BOOL() != nullptr) {
      bool value =
          ctx->assign_types()->BOOL()->getText() == "true" ? true : false;
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      mlir::BoolAttr boolAttr = builder.getBoolAttr(value);
      mlir::Value result = builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), idAttr, boolAttr);
      if (!mlir::succeeded(declare(result, ctx))) {
        return nullptr;
      }
      return result;
    }

    return nullptr;
  }

  mlir::Value mlirGen(ProtoCCParser::Message_constrContext *ctx) {
    std::string constrId = ctx->ID()->getText();
    // Lookup the type
    auto constrType = messageTypeMap.lookup(constrId);
    mlir::ArrayAttr dataAttr;
    mlir::Type dataType;
    std::tie(dataAttr, dataType) = getMessageAttr(ctx);

    return builder.create<mlir::pcc::MsgConstrOp>(builder.getUnknownLoc(),
                                                  dataType, dataAttr);
  }

  std::pair<mlir::ArrayAttr, mlir::Type>
  getMessageAttr(ProtoCCParser::Message_constrContext *ctx) {
    std::vector<mlir::Attribute> attrElements;
    std::vector<mlir::Type> typeElements;

    // Loop over the constructor and generate the elements

    attrElements.push_back(builder.getI64IntegerAttr(11));
    typeElements.push_back(builder.getI64Type());

    mlir::ArrayAttr dataAttr = builder.getArrayAttr(attrElements);
    mlir::Type dataType = mlir::pcc::MsgType::get(typeElements);

    return std::make_pair(dataAttr, dataType);
  }

  // Generate MLIR for Network Send
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_sendContext *ctx) {
    auto ids = ctx->ID();
    std::string netId = ids[0]->getText();
    std::string msgId = ids[1]->getText();

    auto msgConstructor = symbolTable.lookup(msgId);
    assert(msgConstructor.first != nullptr);
    std::cout << msgConstructor.second->getText() << std::endl;

    // TODO - build a SendOp from network_decl and msg type
    mlir::StringAttr strAttr = builder.getStringAttr(netId);
    mlir::pcc::NetType netType = mlir::pcc::NetType::get(builder.getContext());
    mlir::Value netInput = builder.create<mlir::pcc::GlobalNetworkOp>(builder.getUnknownLoc(), netType, strAttr);
    mlir::Value msgInput = msgConstructor.first;
    builder.create<mlir::pcc::SendOp>(builder.getUnknownLoc(), netInput,
                                      msgInput);
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
    mlir::pcc::NetType netType = mlir::pcc::NetType::get(builder.getContext());
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