
// Generated from /Users/petrvesely/dev/mlir/mlir-standalone-template/murphi-opt/ProtoCC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  ProtoCCParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, NETWORK = 23, CACHE = 24, DIR = 25, MEM = 26, 
    MSG = 27, STATE = 28, DATA = 29, NID = 30, FIFO = 31, ARCH = 32, PROC = 33, 
    STABLE = 34, DOT = 35, COMMA = 36, DDOT = 37, SEMICOLON = 38, EQUALSIGN = 39, 
    PLUS = 40, MINUS = 41, MULT = 42, CONSTANT = 43, BOOLID = 44, INTID = 45, 
    ARRAY = 46, SET = 47, AWAIT = 48, NEXT = 49, WHEN = 50, BREAK = 51, 
    IF = 52, ELSE = 53, OCBRACE = 54, CCBRACE = 55, OEBRACE = 56, CEBRACE = 57, 
    OBRACE = 58, CBRACE = 59, NEG = 60, WS = 61, COMMENT = 62, LineComment = 63, 
    NEWLINE = 64, BOOL = 65, INT = 66, ACCESS = 67, EVICT = 68, ID = 69
  };

  enum {
    RuleSend_function = 0, RuleMcast_function = 1, RuleBcast_function = 2, 
    RuleInternal_event_function = 3, RuleSet_function_types = 4, RuleRelational_operator = 5, 
    RuleCombinatorial_operator = 6, RuleDocument = 7, RuleDeclarations = 8, 
    RuleConst_decl = 9, RuleInt_decl = 10, RuleBool_decl = 11, RuleState_decl = 12, 
    RuleData_decl = 13, RuleId_decl = 14, RuleSet_decl = 15, RuleRange = 16, 
    RuleVal_range = 17, RuleArray_decl = 18, RuleFifo_decl = 19, RuleInit_hw = 20, 
    RuleObject_block = 21, RuleObject_expr = 22, RuleObject_id = 23, RuleObject_func = 24, 
    RuleObject_idres = 25, RuleMachines = 26, RuleCache_block = 27, RuleDir_block = 28, 
    RuleMem_block = 29, RuleObjset_decl = 30, RuleNetwork_block = 31, RuleElement_type = 32, 
    RuleNetwork_element = 33, RuleNetwork_send = 34, RuleNetwork_bcast = 35, 
    RuleNetwork_mcast = 36, RuleMessage_block = 37, RuleMessage_constr = 38, 
    RuleMessage_expr = 39, RuleSet_block = 40, RuleSet_func = 41, RuleSet_nest = 42, 
    RuleInternal_event_block = 43, RuleInternal_event_func = 44, RuleArch_block = 45, 
    RuleArch_body = 46, RuleStable_def = 47, RuleProcess_block = 48, RuleProcess_trans = 49, 
    RuleProcess_finalstate = 50, RuleProcess_finalident = 51, RuleProcess_events = 52, 
    RuleProcess_expr = 53, RuleTransaction = 54, RuleTrans = 55, RuleTrans_body = 56, 
    RuleNext_trans = 57, RuleNext_break = 58, RuleExpressions = 59, RuleAssignment = 60, 
    RuleAssign_types = 61, RuleMath_op = 62, RuleConditional = 63, RuleIf_stmt = 64, 
    RuleIfnot_stmt = 65, RuleIf_expression = 66, RuleElse_expression = 67, 
    RuleExprwbreak = 68, RuleCond_comb = 69, RuleCond_rel = 70, RuleCond_sel = 71, 
    RuleCond_type_expr = 72, RuleCond_types = 73
  };

  ProtoCCParser(antlr4::TokenStream *input);
  ~ProtoCCParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Send_functionContext;
  class Mcast_functionContext;
  class Bcast_functionContext;
  class Internal_event_functionContext;
  class Set_function_typesContext;
  class Relational_operatorContext;
  class Combinatorial_operatorContext;
  class DocumentContext;
  class DeclarationsContext;
  class Const_declContext;
  class Int_declContext;
  class Bool_declContext;
  class State_declContext;
  class Data_declContext;
  class Id_declContext;
  class Set_declContext;
  class RangeContext;
  class Val_rangeContext;
  class Array_declContext;
  class Fifo_declContext;
  class Init_hwContext;
  class Object_blockContext;
  class Object_exprContext;
  class Object_idContext;
  class Object_funcContext;
  class Object_idresContext;
  class MachinesContext;
  class Cache_blockContext;
  class Dir_blockContext;
  class Mem_blockContext;
  class Objset_declContext;
  class Network_blockContext;
  class Element_typeContext;
  class Network_elementContext;
  class Network_sendContext;
  class Network_bcastContext;
  class Network_mcastContext;
  class Message_blockContext;
  class Message_constrContext;
  class Message_exprContext;
  class Set_blockContext;
  class Set_funcContext;
  class Set_nestContext;
  class Internal_event_blockContext;
  class Internal_event_funcContext;
  class Arch_blockContext;
  class Arch_bodyContext;
  class Stable_defContext;
  class Process_blockContext;
  class Process_transContext;
  class Process_finalstateContext;
  class Process_finalidentContext;
  class Process_eventsContext;
  class Process_exprContext;
  class TransactionContext;
  class TransContext;
  class Trans_bodyContext;
  class Next_transContext;
  class Next_breakContext;
  class ExpressionsContext;
  class AssignmentContext;
  class Assign_typesContext;
  class Math_opContext;
  class ConditionalContext;
  class If_stmtContext;
  class Ifnot_stmtContext;
  class If_expressionContext;
  class Else_expressionContext;
  class ExprwbreakContext;
  class Cond_combContext;
  class Cond_relContext;
  class Cond_selContext;
  class Cond_type_exprContext;
  class Cond_typesContext; 

  class  Send_functionContext : public antlr4::ParserRuleContext {
  public:
    Send_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Send_functionContext* send_function();

  class  Mcast_functionContext : public antlr4::ParserRuleContext {
  public:
    Mcast_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Mcast_functionContext* mcast_function();

  class  Bcast_functionContext : public antlr4::ParserRuleContext {
  public:
    Bcast_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Bcast_functionContext* bcast_function();

  class  Internal_event_functionContext : public antlr4::ParserRuleContext {
  public:
    Internal_event_functionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Internal_event_functionContext* internal_event_function();

  class  Set_function_typesContext : public antlr4::ParserRuleContext {
  public:
    Set_function_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Set_function_typesContext* set_function_types();

  class  Relational_operatorContext : public antlr4::ParserRuleContext {
  public:
    Relational_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Relational_operatorContext* relational_operator();

  class  Combinatorial_operatorContext : public antlr4::ParserRuleContext {
  public:
    Combinatorial_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Combinatorial_operatorContext* combinatorial_operator();

  class  DocumentContext : public antlr4::ParserRuleContext {
  public:
    DocumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Const_declContext *> const_decl();
    Const_declContext* const_decl(size_t i);
    std::vector<Init_hwContext *> init_hw();
    Init_hwContext* init_hw(size_t i);
    std::vector<Arch_blockContext *> arch_block();
    Arch_blockContext* arch_block(size_t i);
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);

   
  };

  DocumentContext* document();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Int_declContext *int_decl();
    Bool_declContext *bool_decl();
    State_declContext *state_decl();
    Data_declContext *data_decl();
    Id_declContext *id_decl();

   
  };

  DeclarationsContext* declarations();

  class  Const_declContext : public antlr4::ParserRuleContext {
  public:
    Const_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *INT();

   
  };

  Const_declContext* const_decl();

  class  Int_declContext : public antlr4::ParserRuleContext {
  public:
    Int_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTID();
    RangeContext *range();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> EQUALSIGN();
    antlr4::tree::TerminalNode* EQUALSIGN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INT();
    antlr4::tree::TerminalNode* INT(size_t i);

   
  };

  Int_declContext* int_decl();

  class  Bool_declContext : public antlr4::ParserRuleContext {
  public:
    Bool_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLID();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> EQUALSIGN();
    antlr4::tree::TerminalNode* EQUALSIGN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BOOL();
    antlr4::tree::TerminalNode* BOOL(size_t i);

   
  };

  Bool_declContext* bool_decl();

  class  State_declContext : public antlr4::ParserRuleContext {
  public:
    State_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STATE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  State_declContext* state_decl();

  class  Data_declContext : public antlr4::ParserRuleContext {
  public:
    Data_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATA();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Data_declContext* data_decl();

  class  Id_declContext : public antlr4::ParserRuleContext {
  public:
    Id_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NID();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<Set_declContext *> set_decl();
    Set_declContext* set_decl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALSIGN();
    antlr4::tree::TerminalNode* EQUALSIGN(size_t i);

   
  };

  Id_declContext* id_decl();

  class  Set_declContext : public antlr4::ParserRuleContext {
  public:
    Set_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *OEBRACE();
    Val_rangeContext *val_range();
    antlr4::tree::TerminalNode *CEBRACE();

   
  };

  Set_declContext* set_decl();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OEBRACE();
    std::vector<Val_rangeContext *> val_range();
    Val_rangeContext* val_range(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *CEBRACE();

   
  };

  RangeContext* range();

  class  Val_rangeContext : public antlr4::ParserRuleContext {
  public:
    Val_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *ID();

   
  };

  Val_rangeContext* val_range();

  class  Array_declContext : public antlr4::ParserRuleContext {
  public:
    Array_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    RangeContext *range();

   
  };

  Array_declContext* array_decl();

  class  Fifo_declContext : public antlr4::ParserRuleContext {
  public:
    Fifo_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FIFO();
    RangeContext *range();

   
  };

  Fifo_declContext* fifo_decl();

  class  Init_hwContext : public antlr4::ParserRuleContext {
  public:
    Init_hwContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Network_blockContext *network_block();
    MachinesContext *machines();
    Message_blockContext *message_block();

   
  };

  Init_hwContext* init_hw();

  class  Object_blockContext : public antlr4::ParserRuleContext {
  public:
    Object_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_exprContext *object_expr();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Object_blockContext* object_block();

  class  Object_exprContext : public antlr4::ParserRuleContext {
  public:
    Object_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_idContext *object_id();
    Object_funcContext *object_func();

   
  };

  Object_exprContext* object_expr();

  class  Object_idContext : public antlr4::ParserRuleContext {
  public:
    Object_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

   
  };

  Object_idContext* object_id();

  class  Object_funcContext : public antlr4::ParserRuleContext {
  public:
    Object_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *DOT();
    Object_idresContext *object_idres();
    std::vector<antlr4::tree::TerminalNode *> OBRACE();
    antlr4::tree::TerminalNode* OBRACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CBRACE();
    antlr4::tree::TerminalNode* CBRACE(size_t i);
    std::vector<Object_exprContext *> object_expr();
    Object_exprContext* object_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Object_funcContext* object_func();

  class  Object_idresContext : public antlr4::ParserRuleContext {
  public:
    Object_idresContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *NID();

   
  };

  Object_idresContext* object_idres();

  class  MachinesContext : public antlr4::ParserRuleContext {
  public:
    MachinesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cache_blockContext *cache_block();
    Dir_blockContext *dir_block();
    Mem_blockContext *mem_block();

   
  };

  MachinesContext* machines();

  class  Cache_blockContext : public antlr4::ParserRuleContext {
  public:
    Cache_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CACHE();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<DeclarationsContext *> declarations();
    DeclarationsContext* declarations(size_t i);
    std::vector<Objset_declContext *> objset_decl();
    Objset_declContext* objset_decl(size_t i);

   
  };

  Cache_blockContext* cache_block();

  class  Dir_blockContext : public antlr4::ParserRuleContext {
  public:
    Dir_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIR();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<DeclarationsContext *> declarations();
    DeclarationsContext* declarations(size_t i);
    std::vector<Objset_declContext *> objset_decl();
    Objset_declContext* objset_decl(size_t i);

   
  };

  Dir_blockContext* dir_block();

  class  Mem_blockContext : public antlr4::ParserRuleContext {
  public:
    Mem_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEM();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<DeclarationsContext *> declarations();
    DeclarationsContext* declarations(size_t i);
    std::vector<Objset_declContext *> objset_decl();
    Objset_declContext* objset_decl(size_t i);

   
  };

  Mem_blockContext* mem_block();

  class  Objset_declContext : public antlr4::ParserRuleContext {
  public:
    Objset_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *OEBRACE();
    Val_rangeContext *val_range();
    antlr4::tree::TerminalNode *CEBRACE();

   
  };

  Objset_declContext* objset_decl();

  class  Network_blockContext : public antlr4::ParserRuleContext {
  public:
    Network_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NETWORK();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<Network_elementContext *> network_element();
    Network_elementContext* network_element(size_t i);

   
  };

  Network_blockContext* network_block();

  class  Element_typeContext : public antlr4::ParserRuleContext {
  public:
    Element_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  Element_typeContext* element_type();

  class  Network_elementContext : public antlr4::ParserRuleContext {
  public:
    Network_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Element_typeContext *element_type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Network_elementContext* network_element();

  class  Network_sendContext : public antlr4::ParserRuleContext {
  public:
    Network_sendContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *DOT();
    Send_functionContext *send_function();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Network_sendContext* network_send();

  class  Network_bcastContext : public antlr4::ParserRuleContext {
  public:
    Network_bcastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *DOT();
    Bcast_functionContext *bcast_function();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Network_bcastContext* network_bcast();

  class  Network_mcastContext : public antlr4::ParserRuleContext {
  public:
    Network_mcastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *DOT();
    Mcast_functionContext *mcast_function();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Network_mcastContext* network_mcast();

  class  Message_blockContext : public antlr4::ParserRuleContext {
  public:
    Message_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MSG();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<DeclarationsContext *> declarations();
    DeclarationsContext* declarations(size_t i);

   
  };

  Message_blockContext* message_block();

  class  Message_constrContext : public antlr4::ParserRuleContext {
  public:
    Message_constrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<Message_exprContext *> message_expr();
    Message_exprContext* message_expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Message_constrContext* message_constr();

  class  Message_exprContext : public antlr4::ParserRuleContext {
  public:
    Message_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_exprContext *object_expr();
    Set_funcContext *set_func();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *NID();

   
  };

  Message_exprContext* message_expr();

  class  Set_blockContext : public antlr4::ParserRuleContext {
  public:
    Set_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Set_funcContext *set_func();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Set_blockContext* set_block();

  class  Set_funcContext : public antlr4::ParserRuleContext {
  public:
    Set_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *DOT();
    Set_function_typesContext *set_function_types();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *CBRACE();
    std::vector<Set_nestContext *> set_nest();
    Set_nestContext* set_nest(size_t i);

   
  };

  Set_funcContext* set_func();

  class  Set_nestContext : public antlr4::ParserRuleContext {
  public:
    Set_nestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Set_funcContext *set_func();
    Object_exprContext *object_expr();

   
  };

  Set_nestContext* set_nest();

  class  Internal_event_blockContext : public antlr4::ParserRuleContext {
  public:
    Internal_event_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Internal_event_funcContext *internal_event_func();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Internal_event_blockContext* internal_event_block();

  class  Internal_event_funcContext : public antlr4::ParserRuleContext {
  public:
    Internal_event_funcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Internal_event_functionContext *internal_event_function();
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *CBRACE();

   
  };

  Internal_event_funcContext* internal_event_func();

  class  Arch_blockContext : public antlr4::ParserRuleContext {
  public:
    Arch_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARCH();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *OCBRACE();
    Arch_bodyContext *arch_body();
    antlr4::tree::TerminalNode *CCBRACE();

   
  };

  Arch_blockContext* arch_block();

  class  Arch_bodyContext : public antlr4::ParserRuleContext {
  public:
    Arch_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stable_defContext *stable_def();
    std::vector<Process_blockContext *> process_block();
    Process_blockContext* process_block(size_t i);

   
  };

  Arch_bodyContext* arch_body();

  class  Stable_defContext : public antlr4::ParserRuleContext {
  public:
    Stable_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STABLE();
    antlr4::tree::TerminalNode *OCBRACE();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *CCBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  Stable_defContext* stable_def();

  class  Process_blockContext : public antlr4::ParserRuleContext {
  public:
    Process_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROC();
    Process_transContext *process_trans();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    std::vector<Process_exprContext *> process_expr();
    Process_exprContext* process_expr(size_t i);

   
  };

  Process_blockContext* process_block();

  class  Process_transContext : public antlr4::ParserRuleContext {
  public:
    Process_transContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBRACE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COMMA();
    Process_eventsContext *process_events();
    antlr4::tree::TerminalNode *CBRACE();
    Process_finalstateContext *process_finalstate();

   
  };

  Process_transContext* process_trans();

  class  Process_finalstateContext : public antlr4::ParserRuleContext {
  public:
    Process_finalstateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMA();
    Process_finalidentContext *process_finalident();

   
  };

  Process_finalstateContext* process_finalstate();

  class  Process_finalidentContext : public antlr4::ParserRuleContext {
  public:
    Process_finalidentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *STATE();

   
  };

  Process_finalidentContext* process_finalident();

  class  Process_eventsContext : public antlr4::ParserRuleContext {
  public:
    Process_eventsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESS();
    antlr4::tree::TerminalNode *EVICT();
    antlr4::tree::TerminalNode *ID();

   
  };

  Process_eventsContext* process_events();

  class  Process_exprContext : public antlr4::ParserRuleContext {
  public:
    Process_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionsContext *expressions();
    Network_sendContext *network_send();
    Network_mcastContext *network_mcast();
    Network_bcastContext *network_bcast();
    TransactionContext *transaction();

   
  };

  Process_exprContext* process_expr();

  class  TransactionContext : public antlr4::ParserRuleContext {
  public:
    TransactionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AWAIT();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    std::vector<TransContext *> trans();
    TransContext* trans(size_t i);

   
  };

  TransactionContext* transaction();

  class  TransContext : public antlr4::ParserRuleContext {
  public:
    TransContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *DDOT();
    std::vector<Trans_bodyContext *> trans_body();
    Trans_bodyContext* trans_body(size_t i);

   
  };

  TransContext* trans();

  class  Trans_bodyContext : public antlr4::ParserRuleContext {
  public:
    Trans_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionsContext *expressions();
    Next_transContext *next_trans();
    Next_breakContext *next_break();
    TransactionContext *transaction();
    Network_sendContext *network_send();
    Network_mcastContext *network_mcast();
    Network_bcastContext *network_bcast();

   
  };

  Trans_bodyContext* trans_body();

  class  Next_transContext : public antlr4::ParserRuleContext {
  public:
    Next_transContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEXT();
    antlr4::tree::TerminalNode *OCBRACE();
    antlr4::tree::TerminalNode *CCBRACE();
    std::vector<TransContext *> trans();
    TransContext* trans(size_t i);

   
  };

  Next_transContext* next_trans();

  class  Next_breakContext : public antlr4::ParserRuleContext {
  public:
    Next_breakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  Next_breakContext* next_break();

  class  ExpressionsContext : public antlr4::ParserRuleContext {
  public:
    ExpressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();
    ConditionalContext *conditional();
    Object_blockContext *object_block();
    Set_blockContext *set_block();
    Internal_event_blockContext *internal_event_block();

   
  };

  ExpressionsContext* expressions();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Process_finalidentContext *process_finalident();
    antlr4::tree::TerminalNode *EQUALSIGN();
    Assign_typesContext *assign_types();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  AssignmentContext* assignment();

  class  Assign_typesContext : public antlr4::ParserRuleContext {
  public:
    Assign_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_exprContext *object_expr();
    Message_constrContext *message_constr();
    Math_opContext *math_op();
    Set_funcContext *set_func();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *BOOL();

   
  };

  Assign_typesContext* assign_types();

  class  Math_opContext : public antlr4::ParserRuleContext {
  public:
    Math_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Val_rangeContext *> val_range();
    Val_rangeContext* val_range(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  Math_opContext* math_op();

  class  ConditionalContext : public antlr4::ParserRuleContext {
  public:
    ConditionalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_stmtContext *if_stmt();
    Ifnot_stmtContext *ifnot_stmt();

   
  };

  ConditionalContext* conditional();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    Cond_combContext *cond_comb();
    std::vector<antlr4::tree::TerminalNode *> OCBRACE();
    antlr4::tree::TerminalNode* OCBRACE(size_t i);
    If_expressionContext *if_expression();
    std::vector<antlr4::tree::TerminalNode *> CCBRACE();
    antlr4::tree::TerminalNode* CCBRACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSE();
    antlr4::tree::TerminalNode* ELSE(size_t i);
    std::vector<Else_expressionContext *> else_expression();
    Else_expressionContext* else_expression(size_t i);

   
  };

  If_stmtContext* if_stmt();

  class  Ifnot_stmtContext : public antlr4::ParserRuleContext {
  public:
    Ifnot_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NEG();
    Cond_combContext *cond_comb();
    std::vector<antlr4::tree::TerminalNode *> OCBRACE();
    antlr4::tree::TerminalNode* OCBRACE(size_t i);
    If_expressionContext *if_expression();
    std::vector<antlr4::tree::TerminalNode *> CCBRACE();
    antlr4::tree::TerminalNode* CCBRACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSE();
    antlr4::tree::TerminalNode* ELSE(size_t i);
    std::vector<Else_expressionContext *> else_expression();
    Else_expressionContext* else_expression(size_t i);

   
  };

  Ifnot_stmtContext* ifnot_stmt();

  class  If_expressionContext : public antlr4::ParserRuleContext {
  public:
    If_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprwbreakContext *> exprwbreak();
    ExprwbreakContext* exprwbreak(size_t i);

   
  };

  If_expressionContext* if_expression();

  class  Else_expressionContext : public antlr4::ParserRuleContext {
  public:
    Else_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprwbreakContext *> exprwbreak();
    ExprwbreakContext* exprwbreak(size_t i);

   
  };

  Else_expressionContext* else_expression();

  class  ExprwbreakContext : public antlr4::ParserRuleContext {
  public:
    ExprwbreakContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionsContext *expressions();
    Network_sendContext *network_send();
    Network_mcastContext *network_mcast();
    Network_bcastContext *network_bcast();
    TransactionContext *transaction();
    Next_breakContext *next_break();

   
  };

  ExprwbreakContext* exprwbreak();

  class  Cond_combContext : public antlr4::ParserRuleContext {
  public:
    Cond_combContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cond_relContext *> cond_rel();
    Cond_relContext* cond_rel(size_t i);
    std::vector<Combinatorial_operatorContext *> combinatorial_operator();
    Combinatorial_operatorContext* combinatorial_operator(size_t i);

   
  };

  Cond_combContext* cond_comb();

  class  Cond_relContext : public antlr4::ParserRuleContext {
  public:
    Cond_relContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cond_selContext *cond_sel();
    std::vector<antlr4::tree::TerminalNode *> OBRACE();
    antlr4::tree::TerminalNode* OBRACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CBRACE();
    antlr4::tree::TerminalNode* CBRACE(size_t i);

   
  };

  Cond_relContext* cond_rel();

  class  Cond_selContext : public antlr4::ParserRuleContext {
  public:
    Cond_selContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cond_type_exprContext *> cond_type_expr();
    Cond_type_exprContext* cond_type_expr(size_t i);
    std::vector<Relational_operatorContext *> relational_operator();
    Relational_operatorContext* relational_operator(size_t i);

   
  };

  Cond_selContext* cond_sel();

  class  Cond_type_exprContext : public antlr4::ParserRuleContext {
  public:
    Cond_type_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cond_typesContext *> cond_types();
    Cond_typesContext* cond_types(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULT();
    antlr4::tree::TerminalNode* MULT(size_t i);

   
  };

  Cond_type_exprContext* cond_type_expr();

  class  Cond_typesContext : public antlr4::ParserRuleContext {
  public:
    Cond_typesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_exprContext *object_expr();
    Set_funcContext *set_func();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *NID();

   
  };

  Cond_typesContext* cond_types();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

