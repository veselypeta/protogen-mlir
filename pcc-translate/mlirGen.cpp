#include "ProtoCCVisitor.h"
#include "antlr4-runtime.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
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

#include "utils/stateUtils.h"

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
  llvm::StringMap<mlir::Value> globals;

  llvm::ScopedHashTable<
      llvm::StringRef,
      std::pair<mlir::Value, ProtoCCParser::AssignmentContext *>>
      symbolTable;
  using SymbolTableScopeT = llvm::ScopedHashTableScope<
      llvm::StringRef,
      std::pair<mlir::Value, ProtoCCParser::AssignmentContext *>>;

  std::string cur_mach;

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

  mlir::LogicalResult declareGlobal(mlir::Value value, std::string id) {
    char *idBuffer = (char *)malloc(sizeof(char) * id.length());
    strcpy(idBuffer, id.c_str());
    if (globals.try_emplace(idBuffer, value).second) {
      return mlir::failure();
    }
    return mlir::success();
  }

  mlir::Value lookup(mlir::StringRef value) {
    // Lookup in the local symbol table
    auto symLookup = symbolTable.lookup(value);
    if (symLookup.first != nullptr) {
      return symLookup.first;
    }
    auto globalLookup = globals.lookup(value);
    if (globalLookup != nullptr) {
      return globalLookup;
    }
    assert(false && "Value is not to be found");
  }

  // -------------------------------- //
  // ------ Init HW Preamble -------- //
  // -------------------------------- //

  // const_decl : CONSTANT ID INT;
  mlir::LogicalResult mlirGen(ProtoCCParser::Const_declContext *ctx) {
    std::string id = ctx->ID()->getText();
    int value = std::atoi((ctx->INT())->toString().c_str());
    mlir::Attribute idAttr = builder.getStringAttr(id);
    mlir::Attribute valueAttr = builder.getI64IntegerAttr(value);
    mlir::murphi::ConstantOp constOp = builder.create<mlir::murphi::ConstantOp>(
        builder.getUnknownLoc(), idAttr, valueAttr);
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
      // not a set decl ID
      if (ctx->id_decl()->set_decl().size() == 0) {
        return std::make_pair(builder.getStringAttr(id),
                              builder.getStringAttr("ID"));
      }
      std::string range = ctx->id_decl()->set_decl()[0]->getText() + " ID";
      return std::make_pair(builder.getStringAttr(id),
                            builder.getStringAttr(range));
    }
    if (ctx->int_decl() != nullptr) {
      std::string intRangeId = ctx->int_decl()->ID()->getText();
      auto rangeCtx = ctx->int_decl()->range();
      std::string range = rangeCtx->val_range()[0]->getText() + ".." +
                          rangeCtx->val_range()[1]->getText();
      // std::string valueStr;
      // for (auto v : ctx->int_decl()->INT()) {
      //   valueStr += v->getText();
      // }
      // int value = std::atoi(valueStr.c_str());
      return std::make_pair(builder.getStringAttr(intRangeId),
                            builder.getStringAttr(range));
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
    std::string cacheId = ctx->ID()->getText();

    for (auto decl : ctx->declarations()) {
      mlir::Attribute f;
      mlir::Attribute t;
      std::tie(f, t) = getDeclAttribute(decl);
      fields.push_back(f);
      types.push_back(t);
    }

    mlir::murphi::CacheDefOp cacheDef =
        builder.create<mlir::murphi::CacheDefOp>(
            builder.getUnknownLoc(), builder.getI64Type(),
            builder.getArrayAttr(fields), builder.getArrayAttr(types));
    theModule.push_back(cacheDef);

    declareGlobal(cacheDef, cacheId);

    return mlir::success();
  }

  // dir_block : DIR OCBRACE declarations* CCBRACE objset_decl* ID SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Dir_blockContext *ctx) {
    std::vector<mlir::Attribute> fields;
    std::vector<mlir::Attribute> types;
    std::string dirId = ctx->ID()->getText();

    for (auto decl : ctx->declarations()) {
      mlir::Attribute f, t;
      std::tie(f, t) = getDeclAttribute(decl);
      fields.push_back(f);
      types.push_back(t);
    }

    mlir::murphi::DirectoryDefOp dirDef =
        builder.create<mlir::murphi::DirectoryDefOp>(
            builder.getUnknownLoc(), builder.getI64Type(),
            builder.getArrayAttr(fields), builder.getArrayAttr(types));
    theModule.push_back(dirDef);
    declareGlobal(dirDef, dirId);
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

    mlir::pcc::NetworkDeclOp netOp = builder.create<mlir::pcc::NetworkDeclOp>(
        builder.getUnknownLoc(), builder.getI64Type(),
        builder.getStringAttr(networkId),
        builder.getStringAttr(networkOrdering));

    theModule.push_back(netOp);
    declareGlobal(netOp, networkId);
    return mlir::success();
  }

  // -------------------------------- //
  // ----------- Achitecutre -------- //
  // -------------------------------- //

  // arch_block : ARCH ID OCBRACE arch_body CCBRACE;
  mlir::LogicalResult mlirGen(ProtoCCParser::Arch_blockContext *ctx) {
    return mlirGen(ctx->arch_body());
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

    // Get the parent architecture type (cache or directory)
    ProtoCCParser::Arch_blockContext *parentArchCtx =
        dynamic_cast<ProtoCCParser::Arch_blockContext *>(ctx->parent->parent);
    if (parentArchCtx == nullptr) {
      return mlir::failure();
    }

    // Set a flag for the current machine we are working on
    std::string machine = parentArchCtx->ID()->getText();
    this->cur_mach = machine;

    // Get the current state and action from the Process() parameters
    std::string cur_state =
        machine + "_" + ctx->process_trans()->ID()->getText();
    std::string action = ctx->process_trans()->process_events()->getText();

    // Some will have an end-state -- TODO more research into how to set the
    // end-state for each state handler
    mlir::Attribute endStateAttr;
    if (ProtoCCParser::Process_finalstateContext *finalState =
            ctx->process_trans()->process_finalstate()) {
      if (auto finalIdent = finalState->process_finalident()->ID()) {
        endStateAttr =
            builder.getStringAttr(cur_mach + "_" + finalIdent->getText());
      }
    }

    builder.setInsertionPoint(theModule);

    // create the function op for the state and event
    mlir::pcc::FunctionOp funOp = builder.create<mlir::pcc::FunctionOp>(
        builder.getUnknownLoc(), builder.getStringAttr(machine),
        builder.getStringAttr(cur_state), builder.getStringAttr(action),
        endStateAttr);

    // add the entry block to the function
    mlir::Block *entryBlock = new mlir::Block();
    funOp.region().push_back(entryBlock);

    // set the insertion point inside this block
    builder.setInsertionPointToStart(entryBlock);

    // Loop and create Operations
    for (auto procExprCtx : ctx->process_expr()) {
      if (mlir::failed(mlirGen(procExprCtx))) {
        return mlir::failure();
      }
    }

    // Insert a return and reset the insertion point
    mlir::Value v;
    builder.create<mlir::pcc::ReturnOp>(builder.getUnknownLoc(), v);
    // builder.setInsertionPointAfter(funOp);

    // add the function to the module
    theModule.push_back(funOp);
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
    if (ctx->network_mcast() != nullptr) {
      return mlirGen(ctx->network_mcast());
    }
    // TODO -- add support for network_mcast & network_bcast
    return mlir::success();
  }

  // expressions : assignment | conditional | object_block | set_block |
  // internal_event_block;
  mlir::LogicalResult mlirGen(ProtoCCParser::ExpressionsContext *ctx) {
    if (ctx->assignment() != nullptr) {
      return mlirGen(ctx->assignment());
    }
    if (ctx->conditional() != nullptr) {
      return mlirGen(ctx->conditional());
    }
    if (ctx->object_block() != nullptr) {
      // TODO - object instantiation
      mlirGenV(ctx->object_block()->object_expr());
      return mlir::success();
    }
    if (ctx->set_block() != nullptr) {
      // TODO - set block
      mlirGen(ctx->set_block()->set_func());
      return mlir::success();
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
  mlir::LogicalResult mlirGen(ProtoCCParser::AssignmentContext *ctx) {
    std::string assignmentId = ctx->process_finalident()->getText();

    // Can be a MSG Constructor
    // Can be assigning to cache or directory state
    // or general assignment

    std::vector<std::string> fieldsvec;
    std::vector<std::string> typesvec;

    // Get the fields and types attributes of cache and directory aux-state
    if (cur_mach == "cache") {
      theModule.walk([&](mlir::murphi::CacheDefOp cacheOp) {
        auto fields = cacheOp.getAttr("fields").cast<mlir::ArrayAttr>();
        auto types = cacheOp.getAttr("types").cast<mlir::ArrayAttr>();
        for (int i = 0; i < (int)fields.size(); i++) {
          std::string f = fields[i].cast<mlir::StringAttr>().getValue().str();
          std::string t = types[i].cast<mlir::StringAttr>().getValue().str();
          fieldsvec.push_back(f);
          typesvec.push_back(t);
        }
      });
    } else {
      theModule.walk([&](mlir::murphi::DirectoryDefOp dirOp) {
        auto fields = dirOp.getAttr("fields").cast<mlir::ArrayAttr>();
        auto types = dirOp.getAttr("types").cast<mlir::ArrayAttr>();
        for (int i = 0; i < (int)fields.size(); i++) {
          std::string f = fields[i].cast<mlir::StringAttr>().getValue().str();
          std::string t = types[i].cast<mlir::StringAttr>().getValue().str();
          fieldsvec.push_back(f);
          typesvec.push_back(t);
        }
      });
    }

    // If assignment Id not in machine fields declaration
    if (std::find(fieldsvec.begin(), fieldsvec.end(), assignmentId) !=
        fieldsvec.end()) {
      // Here handle things like State = M; cl = msg.cl; etc...
      std::string rhs;
      // Special Case State
      if (assignmentId == "State") {
        rhs = cur_mach + "_" + ctx->assign_types()->getText();
      } else {
        rhs = ctx->assign_types()->getText();
      }
      builder.create<mlir::pcc::SetOp>(builder.getUnknownLoc(), assignmentId,
                                       rhs);
      return mlir::success();
    }

    // message_constr
    if (ctx->assign_types()->message_constr() != nullptr) {
      mlir::Value assignValue = mlirGen(ctx->assign_types()->message_constr());
      return declare(assignValue, ctx);
    }
    // INT
    if (ctx->assign_types()->INT() != nullptr) {
      int intValue = std::atoi(ctx->assign_types()->INT()->getText().c_str());
      mlir::IntegerAttr intAttr = builder.getI64IntegerAttr(intValue);
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      mlir::Value intVal = builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), idAttr, intAttr);
      return declare(intVal, ctx);
    }
    // BOOL
    if (ctx->assign_types()->BOOL() != nullptr) {
      bool value =
          ctx->assign_types()->BOOL()->getText() == "true" ? true : false;
      mlir::StringAttr idAttr = builder.getStringAttr(assignmentId);
      mlir::BoolAttr boolAttr = builder.getBoolAttr(value);
      mlir::Value boolVal = builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), idAttr, boolAttr);
      return declare(boolVal, ctx);
    }
    // object_expr
    if (ctx->assign_types()->object_expr() != nullptr) {
      mlir::Value v = mlirGenV(ctx->assign_types()->object_expr());
      return declare(v, ctx);
    }

    // set_func
    if (ctx->assign_types()->set_func() != nullptr) {
      mlir::Value v = mlirGen(ctx->assign_types()->set_func());
      return declare(v, ctx);
    }
    // math_op : val_range (PLUS | MINUS) val_range;
    if (ctx->assign_types()->math_op() != nullptr) {
      mlir::Value lhs = mlirGen(ctx->assign_types()->math_op()->val_range()[0]);
      mlir::Value rhs = mlirGen(ctx->assign_types()->math_op()->val_range()[1]);
      std::string uid = utils::getUniqueId();
      if (ctx->assign_types()->math_op()->PLUS() != nullptr) {
        mlir::Value v = builder.create<mlir::pcc::MathOp>(
            builder.getUnknownLoc(), lhs.getType(), lhs, rhs,
            builder.getStringAttr("+"), builder.getStringAttr(uid));
        return declare(v, ctx);
      } else {
        mlir::Value v =
            builder.create<mlir::SubIOp>(builder.getUnknownLoc(), lhs, rhs);
        return declare(v, ctx);
      }
    }
    return mlir::success();
  }

  // val_range : INT | ID;
  mlir::Value mlirGen(ProtoCCParser::Val_rangeContext *ctx) {
    if (ctx->INT() != nullptr) {
      int value = atoi(ctx->INT()->getText().c_str());
      mlir::IntegerAttr intAttr = builder.getI64IntegerAttr(value);
      std::string uid = utils::getUniqueId();
      return builder.create<mlir::pcc::ConstantOp>(
          builder.getUnknownLoc(), intAttr.getType(),
          builder.getStringAttr(uid), intAttr);
    } else {
      std::string valueId = ctx->ID()->getText();
      return symbolTable.lookup(valueId).first;
    }
  }

  // message_constr : ID OBRACE message_expr* (COMMA message_expr)* CBRACE ;
  mlir::Value mlirGen(ProtoCCParser::Message_constrContext *ctx) {
    std::string constrId = ctx->ID()->getText();

    std::vector<mlir::Attribute> params;
    for (auto paramCtx : ctx->message_expr()) {
      // TODO - Hardcoded string parameters
      params.push_back(builder.getStringAttr(paramCtx->getText()));
    }
    return builder.create<mlir::pcc::MsgConstrOp>(
        builder.getUnknownLoc(), builder.getI64Type(),
        builder.getArrayAttr(params), builder.getStringAttr(constrId));
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
    whenOp.getRegion().push_back(entryBlock);
    builder.setInsertionPointToStart(entryBlock);

    for (auto tansBodyCtx : ctx->trans_body()) {
      if (mlir::failed(mlirGen(tansBodyCtx))) {
        return mlir::failure();
      }
    }

    // TODO -- insert Break operation after the end of a when
    builder.create<mlir::pcc::BreakOp>(builder.getUnknownLoc());

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
      // TODO - implement -- probably quite importatnt
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
      return mlirGen(ctx->network_mcast());
    }
    if (ctx->network_bcast() != nullptr) {
      // TODO - implement
    }
    return mlir::success();
  }

  // next_break : BREAK SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Next_breakContext *ctx) {
    // Create a Terminator Operator for the Transaction Region
    if (cur_mach == "cache") {
      builder.create<mlir::murphi::ReleaseMutexOp>(builder.getUnknownLoc());
    }
    return mlir::success();
  }

  // Generate MLIR for Network Send
  // network_send : ID DOT send_function OBRACE ID CBRACE SEMICOLON
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_sendContext *ctx) {
    auto ids = ctx->ID();
    std::string netId = ids[0]->getText();
    std::string msgId = ids[1]->getText();

    // Check that the MsgId actually exists i.e. there is a corresponding
    // msgConstructor
    auto msgConstructor = symbolTable.lookup(msgId);
    assert(msgConstructor.first != nullptr);

    // TODO -- check that network exists
    mlir::Value networkRef = lookup(netId);

    mlir::Value msgInput = msgConstructor.first;
    builder.create<mlir::pcc::SendOp>(builder.getUnknownLoc(), msgInput,
                                      networkRef);
    return mlir::success();
  }

  // exprwbreak: expressions | network_send | network_mcast | network_bcast |
  // transaction | next_break;
  mlir::LogicalResult mlirGen(ProtoCCParser::ExprwbreakContext *ctx) {
    if (ctx->expressions() != nullptr) {
      return mlirGen(ctx->expressions());
    }
    if (ctx->network_send() != nullptr) {
      return mlirGen(ctx->network_send());
    }
    if (ctx->transaction() != nullptr) {
      // TODO -- Currently don't suuport transactions within if statement
      assert(false &&
             "Currently don't suuport transactions within if statement");
    }
    if (ctx->network_mcast() != nullptr) {
      return mlirGen(ctx->network_mcast());
    }
    // TODO - other paths are currently not supported
    return mlir::success();
  }
  // Create a conditional Op
  mlir::LogicalResult mlirGen(ProtoCCParser::ConditionalContext *ctx) {
    // If statement
    if (ctx->if_stmt() != nullptr) {

      // value of the if statement
      mlir::Value ifValue = mlirGen(ctx->if_stmt()->cond_comb());
      // mlir::Value ifValue =
      // builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(), "test",
      // false); theModule.dump(); create the if op
      mlir::pcc::ExIfOp exifop =
          builder.create<mlir::pcc::ExIfOp>(builder.getUnknownLoc(), ifValue);

      mlir::Block *thenEntryBlock = new mlir::Block();
      exifop.getThenRegion().push_back(thenEntryBlock);
      builder.setInsertionPointToStart(thenEntryBlock);

      // Add nested ops for then
      for (auto expr : ctx->if_stmt()->if_expression()->exprwbreak()) {
        if (mlir::failed(mlirGen(expr))) {
          return mlir::failure();
        }
      }

      builder.create<mlir::pcc::ReturnOp>(builder.getUnknownLoc());

      mlir::Block *elseEntryBlock = new mlir::Block();
      exifop.getElseRegion().push_back(elseEntryBlock);
      builder.setInsertionPointToStart(elseEntryBlock);

      // add Nested Ops for else
      // Currently supports only a single else expression
      if (ctx->if_stmt()->else_expression().size() == 1) {
        for (auto expr : ctx->if_stmt()->else_expression()[0]->exprwbreak()) {
          if (mlir::failed(mlirGen(expr))) {
            return mlir::failure();
          }
        }
      }

      builder.create<mlir::pcc::ReturnOp>(builder.getUnknownLoc());

      builder.setInsertionPointAfter(exifop);
    }
    return mlir::success();
  }

  mlir::Value mlirGen(ProtoCCParser::Cond_combContext *ctx) {
    std::vector<mlir::Value> values;
    for (auto rel : ctx->cond_rel()) {
      values.push_back(mlirGen(rel->cond_sel()));
    }

    for (auto combOp : ctx->combinatorial_operator()) {
      mlir::Value lhs = values[0];
      mlir::Value rhs = values[1];
      std::string oper = combOp->getText();
      mlir::Value v = builder.create<mlir::pcc::CompareOp>(
          builder.getUnknownLoc(), builder.getI1Type(), lhs, rhs,
          builder.getStringAttr(oper),
          builder.getStringAttr(utils::getUniqueId()));

      // pop of front twice
      values.erase(values.begin());
      values.erase(values.begin());

      // push front
      values.insert(values.begin(), v);
    }
    assert(values.size() > 0 && "Cond Comb Contain at least one value");
    return values[0];
  }

  // cond_sel : cond_type_expr (relational_operator cond_type_expr)*;
  mlir::Value mlirGen(ProtoCCParser::Cond_selContext *ctx) {
    std::vector<mlir::Value> values;

    for (auto condTexpr : ctx->cond_type_expr()) {
      values.push_back(mlirGen(condTexpr));
    }

    for (auto relOp : ctx->relational_operator()) {
      mlir::Value lhs = values[0];
      mlir::Value rhs = values[1];
      std::string oper = relOp->getText();
      mlir::Value v = builder.create<mlir::pcc::CompareOp>(
          builder.getUnknownLoc(), builder.getI1Type(), lhs, rhs,
          builder.getStringAttr(oper),
          builder.getStringAttr(utils::getUniqueId()));

      // pop of front twice
      values.erase(values.begin());
      values.erase(values.begin());

      // push front
      values.insert(values.begin(), v);
    }
    assert(values.size() > 0 && "Cond Select Contain at least one value");
    return values[0];
  }
  // cond_type_expr: cond_types (indv_math_op cond_types)*;
  mlir::Value mlirGen(ProtoCCParser::Cond_type_exprContext *ctx) {
    std::vector<mlir::Value> values;
    for (auto condType : ctx->cond_types()) {
      values.push_back(mlirGen(condType));
    }
    for (auto indvMath : ctx->indv_math_op()) {
      mlir::Value lhs = values[0];
      mlir::Value rhs = values[1];
      std::string oper = indvMath->getText();

      mlir::Value v = builder.create<mlir::pcc::MathOp>(
          builder.getUnknownLoc(), builder.getI64Type(), lhs, rhs,
          builder.getStringAttr(oper),
          builder.getStringAttr(utils::getUniqueId()));

      // pop of front twice
      values.erase(values.begin());
      values.erase(values.begin());

      // push front
      values.insert(values.begin(), v);
    }
    assert(values.size() > 0 && "Cond Type Contain at least one value");
    return values[0];
  }

  mlir::Value mlirGen(ProtoCCParser::Cond_typesContext *ctx) {
    if (ctx->INT() != nullptr) {
      int value = std::atoi(ctx->INT()->getText().c_str());
      return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                   utils::getUniqueId(), value);
    }
    if (ctx->BOOL() != nullptr) {
      bool value = ctx->BOOL()->getText() == "true" ? true : false;
      return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                   utils::getUniqueId(), value);
    }
    if (ctx->NID() != nullptr) {
      assert(false && "Should return here!");
      // TODO -- Not sure what to do here
    }
    if (ctx->object_expr() != nullptr) {
      return mlirGenV(ctx->object_expr());
    }
    if (ctx->set_func() != nullptr) {
      return mlirGen(ctx->set_func());
    }
    assert(false && "Cond Types Not Parsed Correctly!");
  }

  // object_expr : object_id | object_func;
  mlir::Value mlirGenV(ProtoCCParser::Object_exprContext *ctx) {
    if (ctx->object_id() != nullptr) {
      std::string idValue = ctx->object_id()->getText();
      if (isAuxStateRef(idValue)) {
        return builder.create<mlir::pcc::ObjRefOp>(
            builder.getUnknownLoc(), builder.getI64Type(),
            builder.getStringAttr(cur_mach), builder.getStringAttr(idValue),
            builder.getStringAttr(utils::getUniqueId()));
      }
      // check the aux state as well
      return lookup(idValue);
    }
    if (ctx->object_func() != nullptr) {
      return mlirGenV(ctx->object_func());
    }

    assert(false && "Must return before getting here!");
  }

  // object_func : ID DOT object_idres (OBRACE object_expr* (COMMA object_expr)*
  // CBRACE)*;
  mlir::Value mlirGenV(ProtoCCParser::Object_funcContext *ctx) {
    std::string id = ctx->ID()->getText();
    std::string objectAddress = ctx->object_idres()->getText();
    assert(ctx->object_expr().size() == 0 &&
           "NOT Considering Obj Expr with parameters");
    return builder.create<mlir::pcc::ObjRefOp>(
        builder.getUnknownLoc(), builder.getI64Type(),
        builder.getStringAttr(id), builder.getStringAttr(objectAddress),
        builder.getStringAttr(utils::getUniqueId()));
  }

  // set_func : ID DOT set_function_types OBRACE set_nest* CBRACE;
  mlir::Value mlirGen(ProtoCCParser::Set_funcContext *ctx) {
    std::string objId = ctx->ID()->getText();
    assert(isAuxStateRef(objId) && "Can only reference in aux state");
    mlir::Value objValue = builder.create<mlir::pcc::ObjRefOp>(
        builder.getUnknownLoc(), builder.getI64Type(),
        builder.getStringAttr("self"), builder.getStringAttr(objId),
        builder.getStringAttr(utils::getUniqueId()));
    std::string funcName = ctx->set_function_types()->getText();
    // TODO - implement all set_function_types
    if (funcName == "contains") {
      mlir::Value operand = mlirGen(ctx->set_nest()[0]);
      return builder.create<mlir::pcc::SetContainsOp>(
          builder.getUnknownLoc(), builder.getI1Type(), objValue, operand,
          builder.getStringAttr(utils::getUniqueId()));
    }
    if (funcName == "add") {
      mlir::Value operand = mlirGen(ctx->set_nest()[0]);
      builder.create<mlir::pcc::SetAddOp>(builder.getUnknownLoc(), objValue,
                                          operand);
      return nullptr;
    }
    if (funcName == "del") {
      mlir::Value operand = mlirGen(ctx->set_nest()[0]);
      builder.create<mlir::pcc::SetDelOp>(builder.getUnknownLoc(), objValue,
                                          operand);
      return nullptr;
    }

    if (funcName == "clear") {
      builder.create<mlir::pcc::SetClearOp>(builder.getUnknownLoc(), objValue);
      return nullptr;
    }

    if (funcName == "count") {
      return builder.create<mlir::pcc::SetCountOp>(
          builder.getUnknownLoc(), builder.getI64Type(), objValue,
          builder.getStringAttr(utils::getUniqueId()));
    }

    assert(false && "Operations not implemented");
  }

  // set_nest : set_func | object_expr;
  mlir::Value mlirGen(ProtoCCParser::Set_nestContext *ctx) {
    if (ctx->set_func() != nullptr) {
      return mlirGen(ctx->set_func());
    }
    if (ctx->object_expr() != nullptr) {
      return mlirGenV(ctx->object_expr());
    }
    assert(false && "Set Nest must return before getting here!");
  }

  // network_mcast: ID DOT mcast_function OBRACE ID COMMA ID CBRACE SEMICOLON;
  mlir::LogicalResult mlirGen(ProtoCCParser::Network_mcastContext *ctx) {
    std::string netId = ctx->ID()[0]->getText();
    std::string msgId = ctx->ID()[1]->getText();
    std::string setId = ctx->ID()[2]->getText();

    assert(isAuxStateRef(setId) && "Set has to reference in aux state");

    mlir::Value netRef = lookup(netId);
    mlir::Value msgRef = lookup(msgId);
    mlir::Value setRef = builder.create<mlir::pcc::ObjRefOp>(
        builder.getUnknownLoc(), builder.getI64Type(),
        builder.getStringAttr("self"), builder.getStringAttr(setId),
        builder.getStringAttr(utils::getUniqueId()));

    builder.create<mlir::pcc::MCastOp>(builder.getUnknownLoc(), netRef, msgRef,
                                       setRef);
    return mlir::success();
  }

  // is referencing the aux state
  bool isAuxStateRef(std::string ref) {
    // lookup the current machine
    mlir::Value v = lookup(cur_mach);
    mlir::Operation *op = v.getDefiningOp();

    if (mlir::dyn_cast<mlir::murphi::CacheDefOp>(op) != nullptr) {
      mlir::murphi::CacheDefOp cacheDef =
          mlir::dyn_cast<mlir::murphi::CacheDefOp>(op);
      mlir::ArrayAttr cacheFields =
          cacheDef.getAttr("fields").cast<mlir::ArrayAttr>();
      for (auto f : cacheFields) {
        std::string field = f.cast<mlir::StringAttr>().getValue().str();
        if (field == ref) {
          return true;
        }
      }
    } else {
      mlir::murphi::DirectoryDefOp dirDef =
          mlir::dyn_cast<mlir::murphi::DirectoryDefOp>(op);
      mlir::ArrayAttr directoryFields =
          dirDef.getAttr("fields").cast<mlir::ArrayAttr>();
      for (auto f : directoryFields) {
        std::string field = f.cast<mlir::StringAttr>().getValue().str();
        if (field == ref) {
          return true;
        }
      }
    }
    return false;
  }
};

} // namespace

namespace pcc {
mlir::ModuleOp mlirGen(mlir::MLIRContext &mlirCtx,
                       ProtoCCParser::DocumentContext *docCtx) {
  return MLIRGenImpl(mlirCtx).mlirGen(docCtx);
}
} // namespace pcc