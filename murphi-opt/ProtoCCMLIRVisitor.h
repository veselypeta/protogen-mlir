#pragma once

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

#include "PCC/Dialect.h"
#include "PCC/Ops.h"

#include "ProtoCCLexer.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/ScopedHashTable.h"
#include "llvm/Support/raw_ostream.h"
#include <numeric>

/**
 * This class provides an empty implementation of ProtoCCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the
 * available methods.
 */
class ProtoCCMLIRVisitor : public ProtoCCVisitor {
public:
  ProtoCCMLIRVisitor(mlir::MLIRContext &context) : builder(&context) {}

  mlir::ModuleOp mlirGen(ProtoCCParser::DocumentContext *ctx) {
    // Create an empty module to which operations are added
    theModule = mlir::ModuleOp::create(builder.getUnknownLoc());
    // Visit the start of the tree
    visitDocument(ctx);
    return theModule;
  }

  virtual antlrcpp::Any
  visitSend_function(ProtoCCParser::Send_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMcast_function(ProtoCCParser::Mcast_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitBcast_function(ProtoCCParser::Bcast_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInternal_event_function(
      ProtoCCParser::Internal_event_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet_function_types(
      ProtoCCParser::Set_function_typesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational_operator(
      ProtoCCParser::Relational_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCombinatorial_operator(
      ProtoCCParser::Combinatorial_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitDocument(ProtoCCParser::DocumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitDeclarations(ProtoCCParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitConst_decl(ProtoCCParser::Const_declContext *ctx) override {

    int declVal = std::atoi((ctx->INT())->toString().c_str());

    mlir::Type intType = builder.getI64Type();
    mlir::IntegerAttr valueAttribute = mlir::IntegerAttr::get(intType, declVal);
    mlir::StringAttr idAttribute =
        builder.getStringAttr((ctx->ID())->toString());

    mlir::pcc::ConstantOp constant = builder.create<mlir::pcc::ConstantOp>(
        builder.getUnknownLoc(), idAttribute, valueAttribute);

    theModule.push_back(constant);

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitInt_decl(ProtoCCParser::Int_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitBool_decl(ProtoCCParser::Bool_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitState_decl(ProtoCCParser::State_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitData_decl(ProtoCCParser::Data_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitId_decl(ProtoCCParser::Id_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitSet_decl(ProtoCCParser::Set_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(ProtoCCParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitVal_range(ProtoCCParser::Val_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitArray_decl(ProtoCCParser::Array_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitFifo_decl(ProtoCCParser::Fifo_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitInit_hw(ProtoCCParser::Init_hwContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObject_block(ProtoCCParser::Object_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObject_expr(ProtoCCParser::Object_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObject_id(ProtoCCParser::Object_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObject_func(ProtoCCParser::Object_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObject_idres(ProtoCCParser::Object_idresContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMachines(ProtoCCParser::MachinesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCache_block(ProtoCCParser::Cache_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitDir_block(ProtoCCParser::Dir_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMem_block(ProtoCCParser::Mem_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitObjset_decl(ProtoCCParser::Objset_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNetwork_block(ProtoCCParser::Network_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitElement_type(ProtoCCParser::Element_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNetwork_element(ProtoCCParser::Network_elementContext *ctx) override {
    std::string networkId = ctx->ID()->toString();
    std::string networkOrdering = ctx->getStart()->getText();

    mlir::StringAttr orderingAttribute = builder.getStringAttr(networkOrdering);
    mlir::StringAttr idAttribute = builder.getStringAttr(networkId);

    mlir::pcc::NetworkType netType =
        mlir::pcc::NetworkType::get(builder.getContext());

    mlir::pcc::NetworkDeclOp networkOp =
        builder.create<mlir::pcc::NetworkDeclOp>(
            builder.getUnknownLoc(), netType, idAttribute, orderingAttribute);

    theModule.push_back(networkOp);

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNetwork_send(ProtoCCParser::Network_sendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNetwork_bcast(ProtoCCParser::Network_bcastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNetwork_mcast(ProtoCCParser::Network_mcastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMessage_block(ProtoCCParser::Message_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMessage_constr(ProtoCCParser::Message_constrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMessage_expr(ProtoCCParser::Message_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitSet_block(ProtoCCParser::Set_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitSet_func(ProtoCCParser::Set_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitSet_nest(ProtoCCParser::Set_nestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInternal_event_block(
      ProtoCCParser::Internal_event_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInternal_event_func(
      ProtoCCParser::Internal_event_funcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitArch_block(ProtoCCParser::Arch_blockContext *ctx) override {

    // get the id of the architecture
    std::string id = ctx->ID()->getText();

    auto funcType = builder.getFunctionType(llvm::None, llvm::None); // TODO - set the type of the function correctly
    mlir::FuncOp function =
        mlir::FuncOp::create(builder.getUnknownLoc(), id, funcType);

    // Generate Blocks for operations
    mlirGen(ctx->arch_body(), function);

    theModule.push_back(function);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitArch_body(ProtoCCParser::Arch_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  // Generate MLIR Blocks for Switch Statement Style in cache
  void mlirGen(ProtoCCParser::Arch_bodyContext *ctx,
                        mlir::FuncOp archFunction) {

    llvm::StringMap<mlir::Block *> blockMap;

    std::vector<std::string> stableStates =
        visitStable_def_mlir(ctx->stable_def());

    std::vector<mlir::Block *> switch_blocks;
    std::vector<mlir::Block *> state_blocks;



    // Push the switch Blocks
    for (std::string stableState : stableStates) {
      auto switch_block = new mlir::Block;
      archFunction.push_back(switch_block);

      // save to vector
      switch_blocks.push_back(switch_block);

      // push to string map
      blockMap.insert({"switch_" + stableState, switch_block});
    }

    // Push the state blocks
    for (std::string stableState : stableStates) {
      auto state_block = new mlir::Block;
      archFunction.push_back(state_block);

      // save to vector
      state_blocks.push_back(state_block);

      // push to string map
      blockMap.insert({"state_" + stableState, state_block});
    }

    // push the exit block
    mlir::Block *exit_block = new mlir::Block;
    mlir::ReturnOp returnOp =
        builder.create<mlir::ReturnOp>(builder.getUnknownLoc());
    exit_block->push_back(returnOp);
    archFunction.push_back(exit_block);

      // push to string map
      blockMap.insert({"exit", exit_block});

    // Push Branch statements to switch blocks
    for (int i = 0; i < (int)switch_blocks.size(); i++) {
      mlir::Block *switch_block = switch_blocks.at(i);
      mlir::Block *true_block = state_blocks.at(i);
      mlir::Block *false_block;
      // False Block is either exit block or next switch block
      if (i == (int)switch_blocks.size() - 1) {
        false_block = exit_block;
      } else {
        false_block = switch_blocks.at(i + 1);
      }

      // create the operation
      mlir::pcc::ConstantOp valOp =
          makeConstantOp("EqualsState", 1); // TODO - this will compare to the state
      switch_block->push_back(valOp);
      mlir::Value v = valOp.getResult();

      mlir::CondBranchOp condBrOp = builder.create<mlir::CondBranchOp>(
          builder.getUnknownLoc(), v, true_block, false_block);
      switch_block->push_back(condBrOp);
    }

    // generate MLIR for each process block
    for (ProtoCCParser::Process_blockContext *processBlock: ctx->process_block()){
      mlirGen(processBlock, blockMap);
    }
  };

  // Generate MLIR for each Process Block in the giver architecture
  void mlirGen(ProtoCCParser::Process_blockContext *ctx, llvm::StringMap<mlir::Block *> blockMap){
    
    // find the start state block to which this process is expressing
    std::string startState = ctx->process_trans()->ID()->getText();
    mlir::Block *stateBlock = blockMap.lookup("state_" + startState);

    std::string event = ctx->process_trans()->process_events()->getText();

    // Set the Builder Insertion Point
    // builder.setInsertionPointToStart(stateBlock);
    // builder.getInsertionPoint();


    auto attr = builder.getBoolAttr(true);
    mlir::ConstantOp flag = builder.create<mlir::ConstantOp>(builder.getUnknownLoc(), attr);

    mlir::scf::IfOp ifOp = builder.create<mlir::scf::IfOp>(builder.getUnknownLoc(), flag.getResult(), false);


    // TODO - push operations to correct block
    for(ProtoCCParser::Process_exprContext *proc_expr: ctx->process_expr()){
      // TODO - MLIRGen for every process expression
      // mlirGen(proc_expr, ifOp.getBody());
    }

    // push the yield
    mlir::scf::YieldOp yield = builder.create<mlir::scf::YieldOp>(builder.getUnknownLoc());
    ifOp.getBody()->push_back(yield);
  }

  void mlirGen(ProtoCCParser::Process_exprContext *ctx, mlir::Block *block){
    mlir::pcc::NetworkDeclOp n = makeNetworkDeclOp("Test Network", "Ordered");
    block->push_back(n);
  }

  virtual antlrcpp::Any
  visitStable_def(ProtoCCParser::Stable_defContext *ctx) override {
    return visitChildren(ctx);
  }

  std::vector<std::string>
  visitStable_def_mlir(ProtoCCParser::Stable_defContext *ctx) {

    std::vector<std::string> states;

    for (auto state : ctx->ID()) {
      states.push_back(state->getText());
    }

    return states;
  }

  virtual antlrcpp::Any
  visitProcess_block(ProtoCCParser::Process_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitProcess_trans(ProtoCCParser::Process_transContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_finalstate(
      ProtoCCParser::Process_finalstateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcess_finalident(
      ProtoCCParser::Process_finalidentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitProcess_events(ProtoCCParser::Process_eventsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitProcess_expr(ProtoCCParser::Process_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitTransaction(ProtoCCParser::TransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrans(ProtoCCParser::TransContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitTrans_body(ProtoCCParser::Trans_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNext_trans(ProtoCCParser::Next_transContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitNext_break(ProtoCCParser::Next_breakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitExpressions(ProtoCCParser::ExpressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitAssignment(ProtoCCParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitAssign_types(ProtoCCParser::Assign_typesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitMath_op(ProtoCCParser::Math_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitConditional(ProtoCCParser::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitIf_stmt(ProtoCCParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitIfnot_stmt(ProtoCCParser::Ifnot_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitIf_expression(ProtoCCParser::If_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitElse_expression(ProtoCCParser::Else_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitExprwbreak(ProtoCCParser::ExprwbreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCond_comb(ProtoCCParser::Cond_combContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCond_rel(ProtoCCParser::Cond_relContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCond_sel(ProtoCCParser::Cond_selContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCond_type_expr(ProtoCCParser::Cond_type_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any
  visitCond_types(ProtoCCParser::Cond_typesContext *ctx) override {
    return visitChildren(ctx);
  }

private:
  mlir::ModuleOp theModule;
  mlir::OpBuilder builder;

  mlir::pcc::ConstantOp makeConstantOp(const char *id, const int value) {
    mlir::Type intType = builder.getI64Type();
    mlir::IntegerAttr valueAttribute = mlir::IntegerAttr::get(intType, value);
    mlir::StringAttr idAttribute = builder.getStringAttr(id);

    return builder.create<mlir::pcc::ConstantOp>(builder.getUnknownLoc(),
                                                 idAttribute, valueAttribute);
  }

  mlir::pcc::NetworkDeclOp makeNetworkDeclOp(const char *id, const char *ordering) {
    mlir::pcc::NetworkType netType =
        mlir::pcc::NetworkType::get(builder.getContext());
    mlir::StringAttr idAttribute = builder.getStringAttr(id);
    mlir::StringAttr orderingAttribute = builder.getStringAttr(ordering);
    return builder.create<mlir::pcc::NetworkDeclOp>(builder.getUnknownLoc(), netType, idAttribute, orderingAttribute);
  }
};
