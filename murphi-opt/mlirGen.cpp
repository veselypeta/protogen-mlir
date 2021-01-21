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

#include "Murphi/Dialect.h"
#include "Murphi/Ops.h"
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

  // document : (const_decl | init_hw | arch_block | expressions) *;
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

    // for (auto archBlockCtx : ctx->arch_block()) {
    //   mlirGen(archBlockCtx);
    // }

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

  // const_decl : CONSTANT ID INT;
  mlir::LogicalResult mlirGen(ProtoCCParser::Const_declContext *ctx) {
    std::string id = ctx->ID()->getText();
    int value = std::atoi((ctx->INT())->toString().c_str());
    mlir::Attribute idAttr = builder.getStringAttr(id);
    mlir::Attribute valueAttr = builder.getI64IntegerAttr(value);
    mlir::murphi::ConstantOp constOp = builder.create<mlir::murphi::ConstantOp>(
        builder.getUnknownLoc(), idAttr, valueAttr);
    // mlir::pcc::ConstantOp constOp = builder.create<mlir::pcc::ConstantOp>(
    //     builder.getUnknownLoc(), idAttr, valueAttr);
    theModule.push_back(constOp);
    return mlir::success();
  }

  // init_hw : network_block | machines | message_block;
  mlir::LogicalResult mlirGen(ProtoCCParser::Init_hwContext *ctx) {
    if (ctx->network_block() != nullptr) {
      return mlirGen(ctx->network_block());
    }
    if (ctx->message_block() != nullptr) {
      return mlirGen(ctx->message_block());
    }
    if (ctx->machines() != nullptr) {
      return mlirGen(ctx->machines());
    }
    return mlir::success();
  }

  // message_block : MSG ID OCBRACE declarations* CCBRACE SEMICOLON ;
  // Returns (field, type)
  mlir::LogicalResult mlirGen(ProtoCCParser::Message_blockContext *ctx) {
    std::string messageTypeId = ctx->ID()->getText();
    std::vector<mlir::Attribute> fields;
    std::vector<mlir::Attribute> types;

    // declarations : int_decl | bool_decl | state_decl | data_decl | id_decl;
    for (auto decl : ctx->declarations()) {
      mlir::Attribute fieldAttr, typeAttr;
      std::tie(fieldAttr, typeAttr) = getDeclAttribute(decl);
      fields.push_back(fieldAttr);
      types.push_back(typeAttr);
    }

    mlir::murphi::MessageDefOp msgDefOp =
        builder.create<mlir::murphi::MessageDefOp>(
            builder.getUnknownLoc(), builder.getStringAttr(messageTypeId),
            builder.getArrayAttr(fields), builder.getArrayAttr(types));
    theModule.push_back(msgDefOp);
    // std::vector<mlir::Type> elementTypes;
    // if (messageTypeMap.count(messageTypeId)) {
    //   // TODO - return mlir::emitError();
    //   return mlir::failure();
    // }

    // push back default message constructor values
    // mlir::Type messageId = mlir::pcc::IDType::get(builder.getContext());
    // mlir::Type sourceId = mlir::pcc::IDType::get(builder.getContext());
    // mlir::Type destId = mlir::pcc::IDType::get(builder.getContext());
    // elementTypes.push_back(messageId);
    // elementTypes.push_back(sourceId);
    // elementTypes.push_back(destId);

    // for (auto decl : ctx->declarations()) {
    //   mlir::Type declType = getType(decl);
    //   elementTypes.push_back(declType);
    // }
    // messageTypeMap.try_emplace(messageTypeId,
    //                            mlir::pcc::MsgType::get(elementTypes), ctx);

    return mlir::success();
  }

  // declarations : int_decl | bool_decl | state_decl | data_decl | id_decl;
  std::pair<mlir::Attribute, mlir::Attribute>
  getDeclAttribute(ProtoCCParser::DeclarationsContext *ctx) {
    if (ctx->state_decl() != nullptr) {
      std::string stateId = ctx->state_decl()->ID()->getText();
      return std::make_pair(builder.getStringAttr("State"),
                            builder.getStringAttr(stateId));
    }
    if (ctx->data_decl() != nullptr) {
      std::string dataId = ctx->data_decl()->ID()->getText();
      return std::make_pair(builder.getStringAttr(dataId),
                            builder.getStringAttr("Data"));
    }
    if (ctx->id_decl() != nullptr) {
      // TODO -- id_decl is more complicated!!!
      std::string id = ctx->id_decl()->ID()[0]->getText();
      return std::make_pair(builder.getStringAttr(id),
                            builder.getStringAttr("ID"));
    }
    return std::make_pair(nullptr, nullptr);
  }

  // machines : cache_block | dir_block | mem_block;
  mlir::LogicalResult mlirGen(ProtoCCParser::MachinesContext *ctx) {
    if (ctx->cache_block() != nullptr) {
      return mlirGen(ctx->cache_block());
    }
    if (ctx->dir_block() != nullptr) {
      return mlirGen(ctx->dir_block());
    }
    if (ctx->mem_block() != nullptr) {
      // TODO - NOT USED IN MI PROTOCOL
    }
    return mlir::success();
  }

  // cache_block : CACHE OCBRACE declarations* CCBRACE objset_decl* ID
  // SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Cache_blockContext *ctx) {

    std::vector<mlir::Attribute> fields;
    std::vector<mlir::Attribute> types;

    for (auto decl : ctx->declarations()) {
      mlir::Attribute f;
      mlir::Attribute t;
      std::tie(f, t) = getDeclAttribute(decl);
      fields.push_back(f);
      types.push_back(t);
    }

    mlir::murphi::CacheDefOp cacheDef =
        builder.create<mlir::murphi::CacheDefOp>(builder.getUnknownLoc(),
                                                 builder.getArrayAttr(fields),
                                                 builder.getArrayAttr(types));
    theModule.push_back(cacheDef);

    return mlir::success();
  }

  // dir_block : DIR OCBRACE declarations* CCBRACE objset_decl* ID SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Dir_blockContext *ctx) {
    std::vector<mlir::Attribute> fields;
    std::vector<mlir::Attribute> types;

    for (auto decl : ctx->declarations()) {
      mlir::Attribute f, t;
      std::tie(f, t) = getDeclAttribute(decl);
      fields.push_back(f);
      types.push_back(t);
    }

    mlir::murphi::DirectoryDefOp dirDef =
        builder.create<mlir::murphi::DirectoryDefOp>(
            builder.getUnknownLoc(), builder.getArrayAttr(fields),
            builder.getArrayAttr(types));
    theModule.push_back(dirDef);
    return mlir::success();
  }

  // network_block : NETWORK OCBRACE network_element* CCBRACE SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_blockContext *ctx) {
    for (auto netwElem : ctx->network_element()) {
      if (mlir::failed(mlirGen(netwElem))) {
        return mlir::failure();
      }
    }
    return mlir::success();
  }

  // network_element : element_type ID SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_elementContext *ctx) {
    std::string networkId = ctx->ID()->toString();
    std::string networkOrdering = ctx->getStart()->getText();

    // mlir::pcc::NetworkDeclOp netOp =
    // builder.create<mlir::pcc::NetworkDeclOp>(
    //     builder.getUnknownLoc(), networkId, networkOrdering);

    mlir::murphi::NetworkDeclOp netOp =
        builder.create<mlir::murphi::NetworkDeclOp>(
            builder.getUnknownLoc(), builder.getStringAttr(networkId),
            builder.getStringAttr(networkOrdering));
    // TODO -- potentially redundant
    // globals.insert({networkId, netOp});
    theModule.push_back(netOp);
    return mlir::success();
  }

  // arch_block : ARCH ID OCBRACE arch_body CCBRACE;
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

  // arch_body: stable_def process_block*;
  mlir::LogicalResult mlirGen(ProtoCCParser::Arch_bodyContext *ctx) {
    for (auto processCtx : ctx->process_block()) {
      if (mlir::failed(mlirGen(processCtx))) {
        return mlir::failure();
      }
    }
    return mlir::success();
  }

  // process_block : PROC process_trans OCBRACE process_expr* CCBRACE;
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
    // Get the input arguments to the function;
    mlir::TypeRange functionInputType =
        getFunctionInputTypes(ctx->process_expr());
    auto func_type = builder.getFunctionType(functionInputType, llvm::None);
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

  mlir::TypeRange
  getFunctionInputTypes(std::vector<ProtoCCParser::Process_exprContext *> ctx) {
    mlir::TypeRange t;
    return t;
  }

  // process_expr: expressions | network_send | network_mcast | network_bcast
  // | transaction;
  mlir::LogicalResult mlirGen(ProtoCCParser::Process_exprContext *ctx) {

    if (ctx->expressions() != nullptr) {
      return mlirGen(ctx->expressions());
    }
    if (ctx->network_send() != nullptr) {
      return mlirGen(ctx->network_send());
    }
    if (ctx->transaction() != nullptr) {
      return mlirGen(ctx->transaction());
    }
    return mlir::success();
  }

  // expressions : assignment | conditional | object_block | set_block |
  // internal_event_block;
  mlir::LogicalResult mlirGen(ProtoCCParser::ExpressionsContext *ctx) {
    if (ctx->assignment() != nullptr) {
      mlir::Value assignmentValue = mlirGen(ctx->assignment());
      // DECLARE IS FLAWED
      return declare(assignmentValue, ctx->assignment());
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

  // assignment : process_finalident EQUALSIGN assign_types SEMICOLON;
  // assign_types : object_expr | message_constr | math_op | set_func | INT |
  // BOOL;
  // math_op : val_range (PLUS | MINUS) val_range;
  mlir::Value mlirGen(ProtoCCParser::AssignmentContext *ctx) {
    std::string assignmentId = ctx->process_finalident()->getText();

    // TODO Special cases {State, cl, owner ...} -- Hardcode for now!!
    if (assignmentId == "State") {
      // Get the rerpr. of the State i.e. M, I ...
      std::string stateId = ctx->assign_types()->getText();
      // Make the state Type
      mlir::pcc::StateType stateType =
          mlir::pcc::StateType::get(builder.getContext(), stateId);
      mlir::TypeAttr stateAttr = mlir::TypeAttr::get(stateType);
      mlir::StringAttr idAttribute = builder.getStringAttr(assignmentId);
      // Declare State as a Constant to get SSA value
      auto stateValue = builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), stateType, idAttribute, stateAttr);
      // Declare the Set State operation
      builder.create<mlir::pcc::SetOp>(builder.getUnknownLoc(), idAttribute,
                                       stateValue);
    }

    // message_constr
    if (ctx->assign_types()->message_constr() != nullptr) {
      return mlirGen(ctx->assign_types()->message_constr());
    }
    // INT
    if (ctx->assign_types()->INT() != nullptr) {
      int intValue = std::atoi(ctx->assign_types()->INT()->getText().c_str());
      mlir::IntegerAttr intAttr = builder.getI64IntegerAttr(intValue);
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                   idAttr, intAttr);
    }
    // BOOL
    if (ctx->assign_types()->BOOL() != nullptr) {
      bool value =
          ctx->assign_types()->BOOL()->getText() == "true" ? true : false;
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      mlir::BoolAttr boolAttr = builder.getBoolAttr(value);
      return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                   idAttr, boolAttr);
    }
    // object_expr
    if (ctx->assign_types()->object_expr() != nullptr) {
      return mlirGen(ctx->assign_types()->object_expr());
    }
    // math_op : val_range (PLUS | MINUS) val_range;
    if (ctx->assign_types()->math_op() != nullptr) {
      mlir::Value lhs = mlirGen(ctx->assign_types()->math_op()->val_range()[0]);
      mlir::Value rhs = mlirGen(ctx->assign_types()->math_op()->val_range()[1]);
      if (ctx->assign_types()->math_op()->PLUS() != nullptr) {
        return builder.create<mlir::AddIOp>(builder.getUnknownLoc(), lhs, rhs);
      } else {
        return builder.create<mlir::SubIOp>(builder.getUnknownLoc(), lhs, rhs);
      }
    }
    return nullptr;
  }

  // val_range : INT | ID;
  mlir::Value mlirGen(ProtoCCParser::Val_rangeContext *ctx) {
    if (ctx->INT() != nullptr) {
      int value = atoi(ctx->INT()->getText().c_str());
      mlir::IntegerAttr intAttr = builder.getI64IntegerAttr(value);
      return builder.create<mlir::ConstantOp>(builder.getUnknownLoc(), intAttr);
    } else {
      std::string valueId = ctx->ID()->getText();
      return symbolTable.lookup(valueId).first;
    }
  }

  // message_constr : ID OBRACE message_expr* (COMMA message_expr)* CBRACE ;
  mlir::Value mlirGen(ProtoCCParser::Message_constrContext *ctx) {
    std::string constrId = ctx->ID()->getText();
    // Lookup the type
    auto constrType = messageTypeMap.lookup(constrId);
    mlir::ArrayAttr dataAttr;
    mlir::Type dataType;
    std::tie(dataAttr, dataType) = getMessageAttr(ctx);

    mlir::ValueRange valRange;

    return builder.create<mlir::pcc::MsgConstrOp>(builder.getUnknownLoc(),
                                                  dataType, dataAttr);
    return nullptr;
  }

  // message_constr : ID OBRACE message_expr* (COMMA message_expr)* CBRACE ;
  std::pair<mlir::ArrayAttr, mlir::Type>
  getMessageAttr(ProtoCCParser::Message_constrContext *ctx) {
    std::vector<mlir::Attribute> attrElements;
    std::vector<mlir::Type> typeElements;

    std::vector<ProtoCCParser::Message_exprContext *> allMsgExpr =
        ctx->message_expr();
    // Default Object Paracters msg/src/dest
    // TODO -- String Attr Return None
    // Msg ID
    mlir::Attribute msgAttribute =
        builder.getStringAttr(allMsgExpr[0]->getText());
    attrElements.push_back(msgAttribute);
    typeElements.push_back(msgAttribute.getType());

    // Src - TODO -> How to implement???
    mlir::Attribute srcAttribute =
        builder.getStringAttr(allMsgExpr[1]->getText());
    attrElements.push_back(srcAttribute);
    typeElements.push_back(srcAttribute.getType());

    // Dest
    mlir::Attribute dstAttribute =
        builder.getStringAttr(allMsgExpr[2]->getText());
    attrElements.push_back(dstAttribute);
    typeElements.push_back(dstAttribute.getType());

    // Add Optional Parameter
    for (u_long i = 3; i < allMsgExpr.size(); i++) {
      auto res = mlirGen(allMsgExpr[i]);
      // attrElements.push_back(res.first);
      // typeElements.push_back(res.second);
    }

    // auto msgNameAttr = builder.getStringAttr();

    // Loop over the constructor and generate the elements

    // attrElements.push_back(builder.getI64IntegerAttr(11));
    // typeElements.push_back(builder.getI64Type());

    mlir::ArrayAttr dataAttr = builder.getArrayAttr(attrElements);
    mlir::Type dataType = mlir::pcc::MsgType::get(typeElements);

    return std::make_pair(dataAttr, dataType);
  }
  // message_expr : object_expr | set_func | INT | BOOL | NID;
  std::pair<mlir::Attribute, mlir::Type>
  mlirGen(ProtoCCParser::Message_exprContext *ctx) {
    if (ctx->object_expr() != nullptr) {
      // std::cout << ctx->object_expr()->getText() << std::endl;
    }
    // set_func : ID DOT set_function_types OBRACE set_nest* CBRACE;
    if (ctx->set_func() != nullptr) {
      // TODO -- NOT USED IN MI PROTOCOL
    }
    if (ctx->INT() != nullptr) {
      int value = atoi(ctx->INT()->getText().c_str());
      mlir::Attribute intAttr = builder.getI64IntegerAttr(value);
      mlir::Type intType = builder.getI64Type();
      return {intAttr, intType};
    }
    if (ctx->BOOL() != nullptr) {
      bool value = ctx->BOOL()->getText() == "true";
      mlir::Attribute boolAttr = builder.getBoolAttr(value);
      mlir::Type boolType = builder.getI1Type();
      return {boolAttr, boolType};
    }
    if (ctx->NID() != nullptr) {
      // Refereing to its own ID
    }
    return {nullptr, nullptr};
  }

  // object_expr : object_id | object_func;
  // object_id:  ID;
  // object_func : ID DOT object_idres (OBRACE object_expr* (COMMA object_expr)*
  // CBRACE)*;
  // object_idres: ID | NID;
  mlir::Value mlirGen(ProtoCCParser::Object_exprContext *ctx) {

    if (ctx->object_id() != nullptr) {
      // std::string objId = ctx->object_id()->ID()->getText();
      // TODO -- This is not used in the MI Protocol
    }

    if (ctx->object_func() != nullptr) {
      std::string objId = ctx->object_func()->ID()->getText();
      // TODO -- handle case when NID;
      assert(ctx->object_func()->object_idres()->ID() != nullptr);
      std::string objAddr = ctx->object_func()->object_idres()->ID()->getText();

      // Lookup the message type (Request, Ack, Resp, RespAck)
    }
    return nullptr;
  }

  // transaction : AWAIT OCBRACE trans* CCBRACE;
  mlir::LogicalResult mlirGen(ProtoCCParser::TransactionContext *ctx) {
    // Generate a Await Operation and move builder to inside attached
    // region
    auto awaitOp = builder.create<mlir::pcc::AwaitOp>(builder.getUnknownLoc());
    auto entryBlock = new mlir::Block;
    awaitOp.getRegion().push_back(entryBlock);
    builder.setInsertionPointToStart(entryBlock);

    for (auto transCtx : ctx->trans()) {
      if (mlir::failed(mlirGen(transCtx))) {
        return mlir::failure();
      }
    }
    // Add return Op to Region
    builder.create<mlir::pcc::AwaitReturnOp>(builder.getUnknownLoc());
    // Move Builder location back to next operation
    builder.setInsertionPointAfter(awaitOp);
    return mlir::success();
  }

  // trans : WHEN ID DDOT trans_body* ;
  mlir::LogicalResult mlirGen(ProtoCCParser::TransContext *ctx) {
    std::string msgId = ctx->ID()->getText();
    // Build the WhenOp
    mlir::pcc::WhenOp whenOp =
        builder.create<mlir::pcc::WhenOp>(builder.getUnknownLoc(), msgId);
    // Lookup the Message type and put it in as an argument to the block
    mlir::Block *entryBlock = new mlir::Block;
    mlir::Type msgType = messageTypeMap.lookup("Resp").first; // TODO - fix
    entryBlock->addArgument(msgType);
    whenOp.getRegion().push_back(entryBlock);
    builder.setInsertionPointToStart(entryBlock);

    for (auto tansBodyCtx : ctx->trans_body()) {
      if (mlir::failed(mlirGen(tansBodyCtx))) {
        return mlir::failure();
      }
    }

    // reset the insertion point
    builder.setInsertionPointAfter(whenOp);
    return mlir::success();
  }

  // trans_body : expressions | next_trans | next_break | transaction |
  // network_send | network_mcast | network_bcast;
  mlir::LogicalResult mlirGen(ProtoCCParser::Trans_bodyContext *ctx) {
    if (ctx->expressions() != nullptr) {
      return mlirGen(ctx->expressions());
    }
    if (ctx->next_trans() != nullptr) {
      // TODO - implement
    }
    if (ctx->next_break() != nullptr) {
      return mlirGen(ctx->next_break());
    }
    if (ctx->transaction()) {
      return mlirGen(ctx->transaction());
    }
    if (ctx->network_send() != nullptr) {
      return mlirGen(ctx->network_send());
    }
    if (ctx->network_mcast() != nullptr) {
      // TODO - implement
    }
    if (ctx->network_bcast() != nullptr) {
      // TODO - implement
    }
    return mlir::success();
  }

  // next_break : BREAK SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Next_breakContext *ctx) {
    // Create a Terminator Operator for the Transaction Region
    builder.create<mlir::pcc::BreakOp>(builder.getUnknownLoc());
    return mlir::success();
  }

  // Generate MLIR for Network Send
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_sendContext *ctx) {
    auto ids = ctx->ID();
    std::string netId = ids[0]->getText();
    std::string msgId = ids[1]->getText();

    auto msgConstructor = symbolTable.lookup(msgId);
    assert(msgConstructor.first != nullptr);

    mlir::Value netInput = builder.create<mlir::pcc::GlobalNetworkOp>(
        builder.getUnknownLoc(), netId);
    mlir::Value msgInput = msgConstructor.first;
    builder.create<mlir::pcc::SendOp>(builder.getUnknownLoc(), netInput,
                                      msgInput);
    return mlir::success();
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

  // Get Type from Declarations Context
  // declarations : int_decl | bool_decl | state_decl | data_decl | id_decl;
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
    if (ctx->id_decl() != nullptr) {
      return mlir::pcc::IDType::get(builder.getContext());
    }
    return nullptr;
  }
};

} // namespace

namespace pcc {
mlir::OwningModuleRef mlirGen(mlir::MLIRContext &mlirCtx,
                              ProtoCCParser::DocumentContext *docCtx) {
  return MLIRGenImpl(mlirCtx).mlirGen(docCtx);
}
} // namespace pcc