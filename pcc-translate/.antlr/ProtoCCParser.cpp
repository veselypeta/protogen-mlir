
// Generated from /Users/petrvesely/dev/mlir/mlir-standalone-template/pcc-translate/ProtoCC.g4 by ANTLR 4.8



#include "ProtoCCParser.h"


using namespace antlrcpp;
using namespace antlr4;

ProtoCCParser::ProtoCCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ProtoCCParser::~ProtoCCParser() {
  delete _interpreter;
}

std::string ProtoCCParser::getGrammarFileName() const {
  return "ProtoCC.g4";
}

const std::vector<std::string>& ProtoCCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ProtoCCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Send_functionContext ------------------------------------------------------------------

ProtoCCParser::Send_functionContext::Send_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Send_functionContext::getRuleIndex() const {
  return ProtoCCParser::RuleSend_function;
}


ProtoCCParser::Send_functionContext* ProtoCCParser::send_function() {
  Send_functionContext *_localctx = _tracker.createInstance<Send_functionContext>(_ctx, getState());
  enterRule(_localctx, 0, ProtoCCParser::RuleSend_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::T__0

    || _la == ProtoCCParser::T__1)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mcast_functionContext ------------------------------------------------------------------

ProtoCCParser::Mcast_functionContext::Mcast_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Mcast_functionContext::getRuleIndex() const {
  return ProtoCCParser::RuleMcast_function;
}


ProtoCCParser::Mcast_functionContext* ProtoCCParser::mcast_function() {
  Mcast_functionContext *_localctx = _tracker.createInstance<Mcast_functionContext>(_ctx, getState());
  enterRule(_localctx, 2, ProtoCCParser::RuleMcast_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::T__2

    || _la == ProtoCCParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bcast_functionContext ------------------------------------------------------------------

ProtoCCParser::Bcast_functionContext::Bcast_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Bcast_functionContext::getRuleIndex() const {
  return ProtoCCParser::RuleBcast_function;
}


ProtoCCParser::Bcast_functionContext* ProtoCCParser::bcast_function() {
  Bcast_functionContext *_localctx = _tracker.createInstance<Bcast_functionContext>(_ctx, getState());
  enterRule(_localctx, 4, ProtoCCParser::RuleBcast_function);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::T__4

    || _la == ProtoCCParser::T__5)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Internal_event_functionContext ------------------------------------------------------------------

ProtoCCParser::Internal_event_functionContext::Internal_event_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Internal_event_functionContext::getRuleIndex() const {
  return ProtoCCParser::RuleInternal_event_function;
}


ProtoCCParser::Internal_event_functionContext* ProtoCCParser::internal_event_function() {
  Internal_event_functionContext *_localctx = _tracker.createInstance<Internal_event_functionContext>(_ctx, getState());
  enterRule(_localctx, 6, ProtoCCParser::RuleInternal_event_function);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(ProtoCCParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_function_typesContext ------------------------------------------------------------------

ProtoCCParser::Set_function_typesContext::Set_function_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Set_function_typesContext::getRuleIndex() const {
  return ProtoCCParser::RuleSet_function_types;
}


ProtoCCParser::Set_function_typesContext* ProtoCCParser::set_function_types() {
  Set_function_typesContext *_localctx = _tracker.createInstance<Set_function_typesContext>(_ctx, getState());
  enterRule(_localctx, 8, ProtoCCParser::RuleSet_function_types);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::T__7)
      | (1ULL << ProtoCCParser::T__8)
      | (1ULL << ProtoCCParser::T__9)
      | (1ULL << ProtoCCParser::T__10)
      | (1ULL << ProtoCCParser::T__11))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational_operatorContext ------------------------------------------------------------------

ProtoCCParser::Relational_operatorContext::Relational_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Relational_operatorContext::getRuleIndex() const {
  return ProtoCCParser::RuleRelational_operator;
}


ProtoCCParser::Relational_operatorContext* ProtoCCParser::relational_operator() {
  Relational_operatorContext *_localctx = _tracker.createInstance<Relational_operatorContext>(_ctx, getState());
  enterRule(_localctx, 10, ProtoCCParser::RuleRelational_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::T__12)
      | (1ULL << ProtoCCParser::T__13)
      | (1ULL << ProtoCCParser::T__14)
      | (1ULL << ProtoCCParser::T__15)
      | (1ULL << ProtoCCParser::T__16)
      | (1ULL << ProtoCCParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Combinatorial_operatorContext ------------------------------------------------------------------

ProtoCCParser::Combinatorial_operatorContext::Combinatorial_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Combinatorial_operatorContext::getRuleIndex() const {
  return ProtoCCParser::RuleCombinatorial_operator;
}


ProtoCCParser::Combinatorial_operatorContext* ProtoCCParser::combinatorial_operator() {
  Combinatorial_operatorContext *_localctx = _tracker.createInstance<Combinatorial_operatorContext>(_ctx, getState());
  enterRule(_localctx, 12, ProtoCCParser::RuleCombinatorial_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::T__18

    || _la == ProtoCCParser::T__19)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DocumentContext ------------------------------------------------------------------

ProtoCCParser::DocumentContext::DocumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::Const_declContext *> ProtoCCParser::DocumentContext::const_decl() {
  return getRuleContexts<ProtoCCParser::Const_declContext>();
}

ProtoCCParser::Const_declContext* ProtoCCParser::DocumentContext::const_decl(size_t i) {
  return getRuleContext<ProtoCCParser::Const_declContext>(i);
}

std::vector<ProtoCCParser::Init_hwContext *> ProtoCCParser::DocumentContext::init_hw() {
  return getRuleContexts<ProtoCCParser::Init_hwContext>();
}

ProtoCCParser::Init_hwContext* ProtoCCParser::DocumentContext::init_hw(size_t i) {
  return getRuleContext<ProtoCCParser::Init_hwContext>(i);
}

std::vector<ProtoCCParser::Arch_blockContext *> ProtoCCParser::DocumentContext::arch_block() {
  return getRuleContexts<ProtoCCParser::Arch_blockContext>();
}

ProtoCCParser::Arch_blockContext* ProtoCCParser::DocumentContext::arch_block(size_t i) {
  return getRuleContext<ProtoCCParser::Arch_blockContext>(i);
}

std::vector<ProtoCCParser::ExpressionsContext *> ProtoCCParser::DocumentContext::expressions() {
  return getRuleContexts<ProtoCCParser::ExpressionsContext>();
}

ProtoCCParser::ExpressionsContext* ProtoCCParser::DocumentContext::expressions(size_t i) {
  return getRuleContext<ProtoCCParser::ExpressionsContext>(i);
}


size_t ProtoCCParser::DocumentContext::getRuleIndex() const {
  return ProtoCCParser::RuleDocument;
}


ProtoCCParser::DocumentContext* ProtoCCParser::document() {
  DocumentContext *_localctx = _tracker.createInstance<DocumentContext>(_ctx, getState());
  enterRule(_localctx, 14, ProtoCCParser::RuleDocument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & ((1ULL << (ProtoCCParser::T__6 - 7))
      | (1ULL << (ProtoCCParser::NETWORK - 7))
      | (1ULL << (ProtoCCParser::CACHE - 7))
      | (1ULL << (ProtoCCParser::DIR - 7))
      | (1ULL << (ProtoCCParser::MEM - 7))
      | (1ULL << (ProtoCCParser::MSG - 7))
      | (1ULL << (ProtoCCParser::STATE - 7))
      | (1ULL << (ProtoCCParser::ARCH - 7))
      | (1ULL << (ProtoCCParser::CONSTANT - 7))
      | (1ULL << (ProtoCCParser::IF - 7))
      | (1ULL << (ProtoCCParser::ID - 7)))) != 0)) {
      setState(168);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ProtoCCParser::CONSTANT: {
          setState(164);
          const_decl();
          break;
        }

        case ProtoCCParser::NETWORK:
        case ProtoCCParser::CACHE:
        case ProtoCCParser::DIR:
        case ProtoCCParser::MEM:
        case ProtoCCParser::MSG: {
          setState(165);
          init_hw();
          break;
        }

        case ProtoCCParser::ARCH: {
          setState(166);
          arch_block();
          break;
        }

        case ProtoCCParser::T__6:
        case ProtoCCParser::STATE:
        case ProtoCCParser::IF:
        case ProtoCCParser::ID: {
          setState(167);
          expressions();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

ProtoCCParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Int_declContext* ProtoCCParser::DeclarationsContext::int_decl() {
  return getRuleContext<ProtoCCParser::Int_declContext>(0);
}

ProtoCCParser::Bool_declContext* ProtoCCParser::DeclarationsContext::bool_decl() {
  return getRuleContext<ProtoCCParser::Bool_declContext>(0);
}

ProtoCCParser::State_declContext* ProtoCCParser::DeclarationsContext::state_decl() {
  return getRuleContext<ProtoCCParser::State_declContext>(0);
}

ProtoCCParser::Data_declContext* ProtoCCParser::DeclarationsContext::data_decl() {
  return getRuleContext<ProtoCCParser::Data_declContext>(0);
}

ProtoCCParser::Id_declContext* ProtoCCParser::DeclarationsContext::id_decl() {
  return getRuleContext<ProtoCCParser::Id_declContext>(0);
}


size_t ProtoCCParser::DeclarationsContext::getRuleIndex() const {
  return ProtoCCParser::RuleDeclarations;
}


ProtoCCParser::DeclarationsContext* ProtoCCParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 16, ProtoCCParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(178);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProtoCCParser::INTID: {
        enterOuterAlt(_localctx, 1);
        setState(173);
        int_decl();
        break;
      }

      case ProtoCCParser::BOOLID: {
        enterOuterAlt(_localctx, 2);
        setState(174);
        bool_decl();
        break;
      }

      case ProtoCCParser::STATE: {
        enterOuterAlt(_localctx, 3);
        setState(175);
        state_decl();
        break;
      }

      case ProtoCCParser::DATA: {
        enterOuterAlt(_localctx, 4);
        setState(176);
        data_decl();
        break;
      }

      case ProtoCCParser::NID:
      case ProtoCCParser::SET: {
        enterOuterAlt(_localctx, 5);
        setState(177);
        id_decl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_declContext ------------------------------------------------------------------

ProtoCCParser::Const_declContext::Const_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Const_declContext::CONSTANT() {
  return getToken(ProtoCCParser::CONSTANT, 0);
}

tree::TerminalNode* ProtoCCParser::Const_declContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Const_declContext::INT() {
  return getToken(ProtoCCParser::INT, 0);
}


size_t ProtoCCParser::Const_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleConst_decl;
}


ProtoCCParser::Const_declContext* ProtoCCParser::const_decl() {
  Const_declContext *_localctx = _tracker.createInstance<Const_declContext>(_ctx, getState());
  enterRule(_localctx, 18, ProtoCCParser::RuleConst_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(ProtoCCParser::CONSTANT);
    setState(181);
    match(ProtoCCParser::ID);
    setState(182);
    match(ProtoCCParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Int_declContext ------------------------------------------------------------------

ProtoCCParser::Int_declContext::Int_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Int_declContext::INTID() {
  return getToken(ProtoCCParser::INTID, 0);
}

ProtoCCParser::RangeContext* ProtoCCParser::Int_declContext::range() {
  return getRuleContext<ProtoCCParser::RangeContext>(0);
}

tree::TerminalNode* ProtoCCParser::Int_declContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Int_declContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Int_declContext::EQUALSIGN() {
  return getTokens(ProtoCCParser::EQUALSIGN);
}

tree::TerminalNode* ProtoCCParser::Int_declContext::EQUALSIGN(size_t i) {
  return getToken(ProtoCCParser::EQUALSIGN, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Int_declContext::INT() {
  return getTokens(ProtoCCParser::INT);
}

tree::TerminalNode* ProtoCCParser::Int_declContext::INT(size_t i) {
  return getToken(ProtoCCParser::INT, i);
}


size_t ProtoCCParser::Int_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleInt_decl;
}


ProtoCCParser::Int_declContext* ProtoCCParser::int_decl() {
  Int_declContext *_localctx = _tracker.createInstance<Int_declContext>(_ctx, getState());
  enterRule(_localctx, 20, ProtoCCParser::RuleInt_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(ProtoCCParser::INTID);
    setState(185);
    range();
    setState(186);
    match(ProtoCCParser::ID);
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::EQUALSIGN) {
      setState(187);
      match(ProtoCCParser::EQUALSIGN);
      setState(188);
      match(ProtoCCParser::INT);
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(194);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_declContext ------------------------------------------------------------------

ProtoCCParser::Bool_declContext::Bool_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Bool_declContext::BOOLID() {
  return getToken(ProtoCCParser::BOOLID, 0);
}

tree::TerminalNode* ProtoCCParser::Bool_declContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Bool_declContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Bool_declContext::EQUALSIGN() {
  return getTokens(ProtoCCParser::EQUALSIGN);
}

tree::TerminalNode* ProtoCCParser::Bool_declContext::EQUALSIGN(size_t i) {
  return getToken(ProtoCCParser::EQUALSIGN, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Bool_declContext::BOOL() {
  return getTokens(ProtoCCParser::BOOL);
}

tree::TerminalNode* ProtoCCParser::Bool_declContext::BOOL(size_t i) {
  return getToken(ProtoCCParser::BOOL, i);
}


size_t ProtoCCParser::Bool_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleBool_decl;
}


ProtoCCParser::Bool_declContext* ProtoCCParser::bool_decl() {
  Bool_declContext *_localctx = _tracker.createInstance<Bool_declContext>(_ctx, getState());
  enterRule(_localctx, 22, ProtoCCParser::RuleBool_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(ProtoCCParser::BOOLID);
    setState(197);
    match(ProtoCCParser::ID);
    setState(202);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::EQUALSIGN) {
      setState(198);
      match(ProtoCCParser::EQUALSIGN);
      setState(199);
      match(ProtoCCParser::BOOL);
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(205);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- State_declContext ------------------------------------------------------------------

ProtoCCParser::State_declContext::State_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::State_declContext::STATE() {
  return getToken(ProtoCCParser::STATE, 0);
}

tree::TerminalNode* ProtoCCParser::State_declContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::State_declContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::State_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleState_decl;
}


ProtoCCParser::State_declContext* ProtoCCParser::state_decl() {
  State_declContext *_localctx = _tracker.createInstance<State_declContext>(_ctx, getState());
  enterRule(_localctx, 24, ProtoCCParser::RuleState_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(ProtoCCParser::STATE);
    setState(208);
    match(ProtoCCParser::ID);
    setState(209);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Data_declContext ------------------------------------------------------------------

ProtoCCParser::Data_declContext::Data_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Data_declContext::DATA() {
  return getToken(ProtoCCParser::DATA, 0);
}

tree::TerminalNode* ProtoCCParser::Data_declContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Data_declContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Data_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleData_decl;
}


ProtoCCParser::Data_declContext* ProtoCCParser::data_decl() {
  Data_declContext *_localctx = _tracker.createInstance<Data_declContext>(_ctx, getState());
  enterRule(_localctx, 26, ProtoCCParser::RuleData_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(ProtoCCParser::DATA);
    setState(212);
    match(ProtoCCParser::ID);
    setState(213);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_declContext ------------------------------------------------------------------

ProtoCCParser::Id_declContext::Id_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Id_declContext::NID() {
  return getToken(ProtoCCParser::NID, 0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Id_declContext::ID() {
  return getTokens(ProtoCCParser::ID);
}

tree::TerminalNode* ProtoCCParser::Id_declContext::ID(size_t i) {
  return getToken(ProtoCCParser::ID, i);
}

tree::TerminalNode* ProtoCCParser::Id_declContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::Set_declContext *> ProtoCCParser::Id_declContext::set_decl() {
  return getRuleContexts<ProtoCCParser::Set_declContext>();
}

ProtoCCParser::Set_declContext* ProtoCCParser::Id_declContext::set_decl(size_t i) {
  return getRuleContext<ProtoCCParser::Set_declContext>(i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Id_declContext::EQUALSIGN() {
  return getTokens(ProtoCCParser::EQUALSIGN);
}

tree::TerminalNode* ProtoCCParser::Id_declContext::EQUALSIGN(size_t i) {
  return getToken(ProtoCCParser::EQUALSIGN, i);
}


size_t ProtoCCParser::Id_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleId_decl;
}


ProtoCCParser::Id_declContext* ProtoCCParser::id_decl() {
  Id_declContext *_localctx = _tracker.createInstance<Id_declContext>(_ctx, getState());
  enterRule(_localctx, 28, ProtoCCParser::RuleId_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::SET) {
      setState(215);
      set_decl();
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(221);
    match(ProtoCCParser::NID);
    setState(222);
    match(ProtoCCParser::ID);
    setState(233);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::EQUALSIGN) {
      setState(223);
      match(ProtoCCParser::EQUALSIGN);
      setState(227);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ProtoCCParser::SET) {
        setState(224);
        set_decl();
        setState(229);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(230);
      match(ProtoCCParser::ID);
      setState(235);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(236);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_declContext ------------------------------------------------------------------

ProtoCCParser::Set_declContext::Set_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Set_declContext::SET() {
  return getToken(ProtoCCParser::SET, 0);
}

tree::TerminalNode* ProtoCCParser::Set_declContext::OEBRACE() {
  return getToken(ProtoCCParser::OEBRACE, 0);
}

ProtoCCParser::Val_rangeContext* ProtoCCParser::Set_declContext::val_range() {
  return getRuleContext<ProtoCCParser::Val_rangeContext>(0);
}

tree::TerminalNode* ProtoCCParser::Set_declContext::CEBRACE() {
  return getToken(ProtoCCParser::CEBRACE, 0);
}


size_t ProtoCCParser::Set_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleSet_decl;
}


ProtoCCParser::Set_declContext* ProtoCCParser::set_decl() {
  Set_declContext *_localctx = _tracker.createInstance<Set_declContext>(_ctx, getState());
  enterRule(_localctx, 30, ProtoCCParser::RuleSet_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(ProtoCCParser::SET);
    setState(239);
    match(ProtoCCParser::OEBRACE);
    setState(240);
    val_range();
    setState(241);
    match(ProtoCCParser::CEBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

ProtoCCParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::RangeContext::OEBRACE() {
  return getToken(ProtoCCParser::OEBRACE, 0);
}

std::vector<ProtoCCParser::Val_rangeContext *> ProtoCCParser::RangeContext::val_range() {
  return getRuleContexts<ProtoCCParser::Val_rangeContext>();
}

ProtoCCParser::Val_rangeContext* ProtoCCParser::RangeContext::val_range(size_t i) {
  return getRuleContext<ProtoCCParser::Val_rangeContext>(i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::RangeContext::DOT() {
  return getTokens(ProtoCCParser::DOT);
}

tree::TerminalNode* ProtoCCParser::RangeContext::DOT(size_t i) {
  return getToken(ProtoCCParser::DOT, i);
}

tree::TerminalNode* ProtoCCParser::RangeContext::CEBRACE() {
  return getToken(ProtoCCParser::CEBRACE, 0);
}


size_t ProtoCCParser::RangeContext::getRuleIndex() const {
  return ProtoCCParser::RuleRange;
}


ProtoCCParser::RangeContext* ProtoCCParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 32, ProtoCCParser::RuleRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(ProtoCCParser::OEBRACE);
    setState(244);
    val_range();
    setState(245);
    match(ProtoCCParser::DOT);
    setState(246);
    match(ProtoCCParser::DOT);
    setState(247);
    val_range();
    setState(248);
    match(ProtoCCParser::CEBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Val_rangeContext ------------------------------------------------------------------

ProtoCCParser::Val_rangeContext::Val_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Val_rangeContext::INT() {
  return getToken(ProtoCCParser::INT, 0);
}

tree::TerminalNode* ProtoCCParser::Val_rangeContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}


size_t ProtoCCParser::Val_rangeContext::getRuleIndex() const {
  return ProtoCCParser::RuleVal_range;
}


ProtoCCParser::Val_rangeContext* ProtoCCParser::val_range() {
  Val_rangeContext *_localctx = _tracker.createInstance<Val_rangeContext>(_ctx, getState());
  enterRule(_localctx, 34, ProtoCCParser::RuleVal_range);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::INT

    || _la == ProtoCCParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_declContext ------------------------------------------------------------------

ProtoCCParser::Array_declContext::Array_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Array_declContext::ARRAY() {
  return getToken(ProtoCCParser::ARRAY, 0);
}

ProtoCCParser::RangeContext* ProtoCCParser::Array_declContext::range() {
  return getRuleContext<ProtoCCParser::RangeContext>(0);
}


size_t ProtoCCParser::Array_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleArray_decl;
}


ProtoCCParser::Array_declContext* ProtoCCParser::array_decl() {
  Array_declContext *_localctx = _tracker.createInstance<Array_declContext>(_ctx, getState());
  enterRule(_localctx, 36, ProtoCCParser::RuleArray_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(ProtoCCParser::ARRAY);
    setState(253);
    range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fifo_declContext ------------------------------------------------------------------

ProtoCCParser::Fifo_declContext::Fifo_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Fifo_declContext::FIFO() {
  return getToken(ProtoCCParser::FIFO, 0);
}

ProtoCCParser::RangeContext* ProtoCCParser::Fifo_declContext::range() {
  return getRuleContext<ProtoCCParser::RangeContext>(0);
}


size_t ProtoCCParser::Fifo_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleFifo_decl;
}


ProtoCCParser::Fifo_declContext* ProtoCCParser::fifo_decl() {
  Fifo_declContext *_localctx = _tracker.createInstance<Fifo_declContext>(_ctx, getState());
  enterRule(_localctx, 38, ProtoCCParser::RuleFifo_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(ProtoCCParser::FIFO);
    setState(256);
    range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Init_hwContext ------------------------------------------------------------------

ProtoCCParser::Init_hwContext::Init_hwContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Network_blockContext* ProtoCCParser::Init_hwContext::network_block() {
  return getRuleContext<ProtoCCParser::Network_blockContext>(0);
}

ProtoCCParser::MachinesContext* ProtoCCParser::Init_hwContext::machines() {
  return getRuleContext<ProtoCCParser::MachinesContext>(0);
}

ProtoCCParser::Message_blockContext* ProtoCCParser::Init_hwContext::message_block() {
  return getRuleContext<ProtoCCParser::Message_blockContext>(0);
}


size_t ProtoCCParser::Init_hwContext::getRuleIndex() const {
  return ProtoCCParser::RuleInit_hw;
}


ProtoCCParser::Init_hwContext* ProtoCCParser::init_hw() {
  Init_hwContext *_localctx = _tracker.createInstance<Init_hwContext>(_ctx, getState());
  enterRule(_localctx, 40, ProtoCCParser::RuleInit_hw);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProtoCCParser::NETWORK: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        network_block();
        break;
      }

      case ProtoCCParser::CACHE:
      case ProtoCCParser::DIR:
      case ProtoCCParser::MEM: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        machines();
        break;
      }

      case ProtoCCParser::MSG: {
        enterOuterAlt(_localctx, 3);
        setState(260);
        message_block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_blockContext ------------------------------------------------------------------

ProtoCCParser::Object_blockContext::Object_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Object_blockContext::object_expr() {
  return getRuleContext<ProtoCCParser::Object_exprContext>(0);
}

tree::TerminalNode* ProtoCCParser::Object_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Object_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleObject_block;
}


ProtoCCParser::Object_blockContext* ProtoCCParser::object_block() {
  Object_blockContext *_localctx = _tracker.createInstance<Object_blockContext>(_ctx, getState());
  enterRule(_localctx, 42, ProtoCCParser::RuleObject_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    object_expr();
    setState(264);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_exprContext ------------------------------------------------------------------

ProtoCCParser::Object_exprContext::Object_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Object_idContext* ProtoCCParser::Object_exprContext::object_id() {
  return getRuleContext<ProtoCCParser::Object_idContext>(0);
}

ProtoCCParser::Object_funcContext* ProtoCCParser::Object_exprContext::object_func() {
  return getRuleContext<ProtoCCParser::Object_funcContext>(0);
}


size_t ProtoCCParser::Object_exprContext::getRuleIndex() const {
  return ProtoCCParser::RuleObject_expr;
}


ProtoCCParser::Object_exprContext* ProtoCCParser::object_expr() {
  Object_exprContext *_localctx = _tracker.createInstance<Object_exprContext>(_ctx, getState());
  enterRule(_localctx, 44, ProtoCCParser::RuleObject_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(266);
      object_id();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      object_func();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_idContext ------------------------------------------------------------------

ProtoCCParser::Object_idContext::Object_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Object_idContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}


size_t ProtoCCParser::Object_idContext::getRuleIndex() const {
  return ProtoCCParser::RuleObject_id;
}


ProtoCCParser::Object_idContext* ProtoCCParser::object_id() {
  Object_idContext *_localctx = _tracker.createInstance<Object_idContext>(_ctx, getState());
  enterRule(_localctx, 46, ProtoCCParser::RuleObject_id);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(ProtoCCParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_funcContext ------------------------------------------------------------------

ProtoCCParser::Object_funcContext::Object_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Object_funcContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Object_funcContext::DOT() {
  return getToken(ProtoCCParser::DOT, 0);
}

ProtoCCParser::Object_idresContext* ProtoCCParser::Object_funcContext::object_idres() {
  return getRuleContext<ProtoCCParser::Object_idresContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Object_funcContext::OBRACE() {
  return getTokens(ProtoCCParser::OBRACE);
}

tree::TerminalNode* ProtoCCParser::Object_funcContext::OBRACE(size_t i) {
  return getToken(ProtoCCParser::OBRACE, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Object_funcContext::CBRACE() {
  return getTokens(ProtoCCParser::CBRACE);
}

tree::TerminalNode* ProtoCCParser::Object_funcContext::CBRACE(size_t i) {
  return getToken(ProtoCCParser::CBRACE, i);
}

std::vector<ProtoCCParser::Object_exprContext *> ProtoCCParser::Object_funcContext::object_expr() {
  return getRuleContexts<ProtoCCParser::Object_exprContext>();
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Object_funcContext::object_expr(size_t i) {
  return getRuleContext<ProtoCCParser::Object_exprContext>(i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Object_funcContext::COMMA() {
  return getTokens(ProtoCCParser::COMMA);
}

tree::TerminalNode* ProtoCCParser::Object_funcContext::COMMA(size_t i) {
  return getToken(ProtoCCParser::COMMA, i);
}


size_t ProtoCCParser::Object_funcContext::getRuleIndex() const {
  return ProtoCCParser::RuleObject_func;
}


ProtoCCParser::Object_funcContext* ProtoCCParser::object_func() {
  Object_funcContext *_localctx = _tracker.createInstance<Object_funcContext>(_ctx, getState());
  enterRule(_localctx, 48, ProtoCCParser::RuleObject_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(ProtoCCParser::ID);
    setState(273);
    match(ProtoCCParser::DOT);
    setState(274);
    object_idres();
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::OBRACE) {
      setState(275);
      match(ProtoCCParser::OBRACE);
      setState(279);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ProtoCCParser::ID) {
        setState(276);
        object_expr();
        setState(281);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ProtoCCParser::COMMA) {
        setState(282);
        match(ProtoCCParser::COMMA);
        setState(283);
        object_expr();
        setState(288);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(289);
      match(ProtoCCParser::CBRACE);
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Object_idresContext ------------------------------------------------------------------

ProtoCCParser::Object_idresContext::Object_idresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Object_idresContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Object_idresContext::NID() {
  return getToken(ProtoCCParser::NID, 0);
}


size_t ProtoCCParser::Object_idresContext::getRuleIndex() const {
  return ProtoCCParser::RuleObject_idres;
}


ProtoCCParser::Object_idresContext* ProtoCCParser::object_idres() {
  Object_idresContext *_localctx = _tracker.createInstance<Object_idresContext>(_ctx, getState());
  enterRule(_localctx, 50, ProtoCCParser::RuleObject_idres);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::NID

    || _la == ProtoCCParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MachinesContext ------------------------------------------------------------------

ProtoCCParser::MachinesContext::MachinesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Cache_blockContext* ProtoCCParser::MachinesContext::cache_block() {
  return getRuleContext<ProtoCCParser::Cache_blockContext>(0);
}

ProtoCCParser::Dir_blockContext* ProtoCCParser::MachinesContext::dir_block() {
  return getRuleContext<ProtoCCParser::Dir_blockContext>(0);
}

ProtoCCParser::Mem_blockContext* ProtoCCParser::MachinesContext::mem_block() {
  return getRuleContext<ProtoCCParser::Mem_blockContext>(0);
}


size_t ProtoCCParser::MachinesContext::getRuleIndex() const {
  return ProtoCCParser::RuleMachines;
}


ProtoCCParser::MachinesContext* ProtoCCParser::machines() {
  MachinesContext *_localctx = _tracker.createInstance<MachinesContext>(_ctx, getState());
  enterRule(_localctx, 52, ProtoCCParser::RuleMachines);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ProtoCCParser::CACHE: {
        enterOuterAlt(_localctx, 1);
        setState(297);
        cache_block();
        break;
      }

      case ProtoCCParser::DIR: {
        enterOuterAlt(_localctx, 2);
        setState(298);
        dir_block();
        break;
      }

      case ProtoCCParser::MEM: {
        enterOuterAlt(_localctx, 3);
        setState(299);
        mem_block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cache_blockContext ------------------------------------------------------------------

ProtoCCParser::Cache_blockContext::Cache_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Cache_blockContext::CACHE() {
  return getToken(ProtoCCParser::CACHE, 0);
}

tree::TerminalNode* ProtoCCParser::Cache_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Cache_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Cache_blockContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Cache_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::DeclarationsContext *> ProtoCCParser::Cache_blockContext::declarations() {
  return getRuleContexts<ProtoCCParser::DeclarationsContext>();
}

ProtoCCParser::DeclarationsContext* ProtoCCParser::Cache_blockContext::declarations(size_t i) {
  return getRuleContext<ProtoCCParser::DeclarationsContext>(i);
}

std::vector<ProtoCCParser::Objset_declContext *> ProtoCCParser::Cache_blockContext::objset_decl() {
  return getRuleContexts<ProtoCCParser::Objset_declContext>();
}

ProtoCCParser::Objset_declContext* ProtoCCParser::Cache_blockContext::objset_decl(size_t i) {
  return getRuleContext<ProtoCCParser::Objset_declContext>(i);
}


size_t ProtoCCParser::Cache_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleCache_block;
}


ProtoCCParser::Cache_blockContext* ProtoCCParser::cache_block() {
  Cache_blockContext *_localctx = _tracker.createInstance<Cache_blockContext>(_ctx, getState());
  enterRule(_localctx, 54, ProtoCCParser::RuleCache_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(ProtoCCParser::CACHE);
    setState(303);
    match(ProtoCCParser::OCBRACE);
    setState(307);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::STATE)
      | (1ULL << ProtoCCParser::DATA)
      | (1ULL << ProtoCCParser::NID)
      | (1ULL << ProtoCCParser::BOOLID)
      | (1ULL << ProtoCCParser::INTID)
      | (1ULL << ProtoCCParser::SET))) != 0)) {
      setState(304);
      declarations();
      setState(309);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(310);
    match(ProtoCCParser::CCBRACE);
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::SET) {
      setState(311);
      objset_decl();
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(317);
    match(ProtoCCParser::ID);
    setState(318);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dir_blockContext ------------------------------------------------------------------

ProtoCCParser::Dir_blockContext::Dir_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Dir_blockContext::DIR() {
  return getToken(ProtoCCParser::DIR, 0);
}

tree::TerminalNode* ProtoCCParser::Dir_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Dir_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Dir_blockContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Dir_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::DeclarationsContext *> ProtoCCParser::Dir_blockContext::declarations() {
  return getRuleContexts<ProtoCCParser::DeclarationsContext>();
}

ProtoCCParser::DeclarationsContext* ProtoCCParser::Dir_blockContext::declarations(size_t i) {
  return getRuleContext<ProtoCCParser::DeclarationsContext>(i);
}

std::vector<ProtoCCParser::Objset_declContext *> ProtoCCParser::Dir_blockContext::objset_decl() {
  return getRuleContexts<ProtoCCParser::Objset_declContext>();
}

ProtoCCParser::Objset_declContext* ProtoCCParser::Dir_blockContext::objset_decl(size_t i) {
  return getRuleContext<ProtoCCParser::Objset_declContext>(i);
}


size_t ProtoCCParser::Dir_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleDir_block;
}


ProtoCCParser::Dir_blockContext* ProtoCCParser::dir_block() {
  Dir_blockContext *_localctx = _tracker.createInstance<Dir_blockContext>(_ctx, getState());
  enterRule(_localctx, 56, ProtoCCParser::RuleDir_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    match(ProtoCCParser::DIR);
    setState(321);
    match(ProtoCCParser::OCBRACE);
    setState(325);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::STATE)
      | (1ULL << ProtoCCParser::DATA)
      | (1ULL << ProtoCCParser::NID)
      | (1ULL << ProtoCCParser::BOOLID)
      | (1ULL << ProtoCCParser::INTID)
      | (1ULL << ProtoCCParser::SET))) != 0)) {
      setState(322);
      declarations();
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(328);
    match(ProtoCCParser::CCBRACE);
    setState(332);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::SET) {
      setState(329);
      objset_decl();
      setState(334);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(335);
    match(ProtoCCParser::ID);
    setState(336);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_blockContext ------------------------------------------------------------------

ProtoCCParser::Mem_blockContext::Mem_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Mem_blockContext::MEM() {
  return getToken(ProtoCCParser::MEM, 0);
}

tree::TerminalNode* ProtoCCParser::Mem_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Mem_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Mem_blockContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Mem_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::DeclarationsContext *> ProtoCCParser::Mem_blockContext::declarations() {
  return getRuleContexts<ProtoCCParser::DeclarationsContext>();
}

ProtoCCParser::DeclarationsContext* ProtoCCParser::Mem_blockContext::declarations(size_t i) {
  return getRuleContext<ProtoCCParser::DeclarationsContext>(i);
}

std::vector<ProtoCCParser::Objset_declContext *> ProtoCCParser::Mem_blockContext::objset_decl() {
  return getRuleContexts<ProtoCCParser::Objset_declContext>();
}

ProtoCCParser::Objset_declContext* ProtoCCParser::Mem_blockContext::objset_decl(size_t i) {
  return getRuleContext<ProtoCCParser::Objset_declContext>(i);
}


size_t ProtoCCParser::Mem_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleMem_block;
}


ProtoCCParser::Mem_blockContext* ProtoCCParser::mem_block() {
  Mem_blockContext *_localctx = _tracker.createInstance<Mem_blockContext>(_ctx, getState());
  enterRule(_localctx, 58, ProtoCCParser::RuleMem_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(ProtoCCParser::MEM);
    setState(339);
    match(ProtoCCParser::OCBRACE);
    setState(343);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::STATE)
      | (1ULL << ProtoCCParser::DATA)
      | (1ULL << ProtoCCParser::NID)
      | (1ULL << ProtoCCParser::BOOLID)
      | (1ULL << ProtoCCParser::INTID)
      | (1ULL << ProtoCCParser::SET))) != 0)) {
      setState(340);
      declarations();
      setState(345);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(346);
    match(ProtoCCParser::CCBRACE);
    setState(350);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::SET) {
      setState(347);
      objset_decl();
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(353);
    match(ProtoCCParser::ID);
    setState(354);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Objset_declContext ------------------------------------------------------------------

ProtoCCParser::Objset_declContext::Objset_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Objset_declContext::SET() {
  return getToken(ProtoCCParser::SET, 0);
}

tree::TerminalNode* ProtoCCParser::Objset_declContext::OEBRACE() {
  return getToken(ProtoCCParser::OEBRACE, 0);
}

ProtoCCParser::Val_rangeContext* ProtoCCParser::Objset_declContext::val_range() {
  return getRuleContext<ProtoCCParser::Val_rangeContext>(0);
}

tree::TerminalNode* ProtoCCParser::Objset_declContext::CEBRACE() {
  return getToken(ProtoCCParser::CEBRACE, 0);
}


size_t ProtoCCParser::Objset_declContext::getRuleIndex() const {
  return ProtoCCParser::RuleObjset_decl;
}


ProtoCCParser::Objset_declContext* ProtoCCParser::objset_decl() {
  Objset_declContext *_localctx = _tracker.createInstance<Objset_declContext>(_ctx, getState());
  enterRule(_localctx, 60, ProtoCCParser::RuleObjset_decl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(ProtoCCParser::SET);
    setState(357);
    match(ProtoCCParser::OEBRACE);
    setState(358);
    val_range();
    setState(359);
    match(ProtoCCParser::CEBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_blockContext ------------------------------------------------------------------

ProtoCCParser::Network_blockContext::Network_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Network_blockContext::NETWORK() {
  return getToken(ProtoCCParser::NETWORK, 0);
}

tree::TerminalNode* ProtoCCParser::Network_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::Network_elementContext *> ProtoCCParser::Network_blockContext::network_element() {
  return getRuleContexts<ProtoCCParser::Network_elementContext>();
}

ProtoCCParser::Network_elementContext* ProtoCCParser::Network_blockContext::network_element(size_t i) {
  return getRuleContext<ProtoCCParser::Network_elementContext>(i);
}


size_t ProtoCCParser::Network_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleNetwork_block;
}


ProtoCCParser::Network_blockContext* ProtoCCParser::network_block() {
  Network_blockContext *_localctx = _tracker.createInstance<Network_blockContext>(_ctx, getState());
  enterRule(_localctx, 62, ProtoCCParser::RuleNetwork_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(ProtoCCParser::NETWORK);
    setState(362);
    match(ProtoCCParser::OCBRACE);
    setState(366);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::T__20

    || _la == ProtoCCParser::T__21) {
      setState(363);
      network_element();
      setState(368);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(369);
    match(ProtoCCParser::CCBRACE);
    setState(370);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Element_typeContext ------------------------------------------------------------------

ProtoCCParser::Element_typeContext::Element_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ProtoCCParser::Element_typeContext::getRuleIndex() const {
  return ProtoCCParser::RuleElement_type;
}


ProtoCCParser::Element_typeContext* ProtoCCParser::element_type() {
  Element_typeContext *_localctx = _tracker.createInstance<Element_typeContext>(_ctx, getState());
  enterRule(_localctx, 64, ProtoCCParser::RuleElement_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::T__20

    || _la == ProtoCCParser::T__21)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_elementContext ------------------------------------------------------------------

ProtoCCParser::Network_elementContext::Network_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Element_typeContext* ProtoCCParser::Network_elementContext::element_type() {
  return getRuleContext<ProtoCCParser::Element_typeContext>(0);
}

tree::TerminalNode* ProtoCCParser::Network_elementContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Network_elementContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Network_elementContext::getRuleIndex() const {
  return ProtoCCParser::RuleNetwork_element;
}


ProtoCCParser::Network_elementContext* ProtoCCParser::network_element() {
  Network_elementContext *_localctx = _tracker.createInstance<Network_elementContext>(_ctx, getState());
  enterRule(_localctx, 66, ProtoCCParser::RuleNetwork_element);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    element_type();
    setState(375);
    match(ProtoCCParser::ID);
    setState(376);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_sendContext ------------------------------------------------------------------

ProtoCCParser::Network_sendContext::Network_sendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProtoCCParser::Network_sendContext::ID() {
  return getTokens(ProtoCCParser::ID);
}

tree::TerminalNode* ProtoCCParser::Network_sendContext::ID(size_t i) {
  return getToken(ProtoCCParser::ID, i);
}

tree::TerminalNode* ProtoCCParser::Network_sendContext::DOT() {
  return getToken(ProtoCCParser::DOT, 0);
}

ProtoCCParser::Send_functionContext* ProtoCCParser::Network_sendContext::send_function() {
  return getRuleContext<ProtoCCParser::Send_functionContext>(0);
}

tree::TerminalNode* ProtoCCParser::Network_sendContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_sendContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_sendContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Network_sendContext::getRuleIndex() const {
  return ProtoCCParser::RuleNetwork_send;
}


ProtoCCParser::Network_sendContext* ProtoCCParser::network_send() {
  Network_sendContext *_localctx = _tracker.createInstance<Network_sendContext>(_ctx, getState());
  enterRule(_localctx, 68, ProtoCCParser::RuleNetwork_send);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    match(ProtoCCParser::ID);
    setState(379);
    match(ProtoCCParser::DOT);
    setState(380);
    send_function();
    setState(381);
    match(ProtoCCParser::OBRACE);
    setState(382);
    match(ProtoCCParser::ID);
    setState(383);
    match(ProtoCCParser::CBRACE);
    setState(384);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_bcastContext ------------------------------------------------------------------

ProtoCCParser::Network_bcastContext::Network_bcastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProtoCCParser::Network_bcastContext::ID() {
  return getTokens(ProtoCCParser::ID);
}

tree::TerminalNode* ProtoCCParser::Network_bcastContext::ID(size_t i) {
  return getToken(ProtoCCParser::ID, i);
}

tree::TerminalNode* ProtoCCParser::Network_bcastContext::DOT() {
  return getToken(ProtoCCParser::DOT, 0);
}

ProtoCCParser::Bcast_functionContext* ProtoCCParser::Network_bcastContext::bcast_function() {
  return getRuleContext<ProtoCCParser::Bcast_functionContext>(0);
}

tree::TerminalNode* ProtoCCParser::Network_bcastContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_bcastContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_bcastContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Network_bcastContext::getRuleIndex() const {
  return ProtoCCParser::RuleNetwork_bcast;
}


ProtoCCParser::Network_bcastContext* ProtoCCParser::network_bcast() {
  Network_bcastContext *_localctx = _tracker.createInstance<Network_bcastContext>(_ctx, getState());
  enterRule(_localctx, 70, ProtoCCParser::RuleNetwork_bcast);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(ProtoCCParser::ID);
    setState(387);
    match(ProtoCCParser::DOT);
    setState(388);
    bcast_function();
    setState(389);
    match(ProtoCCParser::OBRACE);
    setState(390);
    match(ProtoCCParser::ID);
    setState(391);
    match(ProtoCCParser::CBRACE);
    setState(392);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Network_mcastContext ------------------------------------------------------------------

ProtoCCParser::Network_mcastContext::Network_mcastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ProtoCCParser::Network_mcastContext::ID() {
  return getTokens(ProtoCCParser::ID);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::ID(size_t i) {
  return getToken(ProtoCCParser::ID, i);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::DOT() {
  return getToken(ProtoCCParser::DOT, 0);
}

ProtoCCParser::Mcast_functionContext* ProtoCCParser::Network_mcastContext::mcast_function() {
  return getRuleContext<ProtoCCParser::Mcast_functionContext>(0);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::COMMA() {
  return getToken(ProtoCCParser::COMMA, 0);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Network_mcastContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Network_mcastContext::getRuleIndex() const {
  return ProtoCCParser::RuleNetwork_mcast;
}


ProtoCCParser::Network_mcastContext* ProtoCCParser::network_mcast() {
  Network_mcastContext *_localctx = _tracker.createInstance<Network_mcastContext>(_ctx, getState());
  enterRule(_localctx, 72, ProtoCCParser::RuleNetwork_mcast);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    match(ProtoCCParser::ID);
    setState(395);
    match(ProtoCCParser::DOT);
    setState(396);
    mcast_function();
    setState(397);
    match(ProtoCCParser::OBRACE);
    setState(398);
    match(ProtoCCParser::ID);
    setState(399);
    match(ProtoCCParser::COMMA);
    setState(400);
    match(ProtoCCParser::ID);
    setState(401);
    match(ProtoCCParser::CBRACE);
    setState(402);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Message_blockContext ------------------------------------------------------------------

ProtoCCParser::Message_blockContext::Message_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Message_blockContext::MSG() {
  return getToken(ProtoCCParser::MSG, 0);
}

tree::TerminalNode* ProtoCCParser::Message_blockContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Message_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Message_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Message_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}

std::vector<ProtoCCParser::DeclarationsContext *> ProtoCCParser::Message_blockContext::declarations() {
  return getRuleContexts<ProtoCCParser::DeclarationsContext>();
}

ProtoCCParser::DeclarationsContext* ProtoCCParser::Message_blockContext::declarations(size_t i) {
  return getRuleContext<ProtoCCParser::DeclarationsContext>(i);
}


size_t ProtoCCParser::Message_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleMessage_block;
}


ProtoCCParser::Message_blockContext* ProtoCCParser::message_block() {
  Message_blockContext *_localctx = _tracker.createInstance<Message_blockContext>(_ctx, getState());
  enterRule(_localctx, 74, ProtoCCParser::RuleMessage_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(ProtoCCParser::MSG);
    setState(405);
    match(ProtoCCParser::ID);
    setState(406);
    match(ProtoCCParser::OCBRACE);
    setState(410);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::STATE)
      | (1ULL << ProtoCCParser::DATA)
      | (1ULL << ProtoCCParser::NID)
      | (1ULL << ProtoCCParser::BOOLID)
      | (1ULL << ProtoCCParser::INTID)
      | (1ULL << ProtoCCParser::SET))) != 0)) {
      setState(407);
      declarations();
      setState(412);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(413);
    match(ProtoCCParser::CCBRACE);
    setState(414);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Message_constrContext ------------------------------------------------------------------

ProtoCCParser::Message_constrContext::Message_constrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Message_constrContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Message_constrContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Message_constrContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

std::vector<ProtoCCParser::Message_exprContext *> ProtoCCParser::Message_constrContext::message_expr() {
  return getRuleContexts<ProtoCCParser::Message_exprContext>();
}

ProtoCCParser::Message_exprContext* ProtoCCParser::Message_constrContext::message_expr(size_t i) {
  return getRuleContext<ProtoCCParser::Message_exprContext>(i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Message_constrContext::COMMA() {
  return getTokens(ProtoCCParser::COMMA);
}

tree::TerminalNode* ProtoCCParser::Message_constrContext::COMMA(size_t i) {
  return getToken(ProtoCCParser::COMMA, i);
}


size_t ProtoCCParser::Message_constrContext::getRuleIndex() const {
  return ProtoCCParser::RuleMessage_constr;
}


ProtoCCParser::Message_constrContext* ProtoCCParser::message_constr() {
  Message_constrContext *_localctx = _tracker.createInstance<Message_constrContext>(_ctx, getState());
  enterRule(_localctx, 76, ProtoCCParser::RuleMessage_constr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(ProtoCCParser::ID);
    setState(417);
    match(ProtoCCParser::OBRACE);
    setState(421);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 30) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 30)) & ((1ULL << (ProtoCCParser::NID - 30))
      | (1ULL << (ProtoCCParser::BOOL - 30))
      | (1ULL << (ProtoCCParser::INT - 30))
      | (1ULL << (ProtoCCParser::ID - 30)))) != 0)) {
      setState(418);
      message_expr();
      setState(423);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(428);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::COMMA) {
      setState(424);
      match(ProtoCCParser::COMMA);
      setState(425);
      message_expr();
      setState(430);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(431);
    match(ProtoCCParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Message_exprContext ------------------------------------------------------------------

ProtoCCParser::Message_exprContext::Message_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Message_exprContext::object_expr() {
  return getRuleContext<ProtoCCParser::Object_exprContext>(0);
}

ProtoCCParser::Set_funcContext* ProtoCCParser::Message_exprContext::set_func() {
  return getRuleContext<ProtoCCParser::Set_funcContext>(0);
}

tree::TerminalNode* ProtoCCParser::Message_exprContext::INT() {
  return getToken(ProtoCCParser::INT, 0);
}

tree::TerminalNode* ProtoCCParser::Message_exprContext::BOOL() {
  return getToken(ProtoCCParser::BOOL, 0);
}

tree::TerminalNode* ProtoCCParser::Message_exprContext::NID() {
  return getToken(ProtoCCParser::NID, 0);
}


size_t ProtoCCParser::Message_exprContext::getRuleIndex() const {
  return ProtoCCParser::RuleMessage_expr;
}


ProtoCCParser::Message_exprContext* ProtoCCParser::message_expr() {
  Message_exprContext *_localctx = _tracker.createInstance<Message_exprContext>(_ctx, getState());
  enterRule(_localctx, 78, ProtoCCParser::RuleMessage_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(438);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(433);
      object_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(434);
      set_func();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(435);
      match(ProtoCCParser::INT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(436);
      match(ProtoCCParser::BOOL);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(437);
      match(ProtoCCParser::NID);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_blockContext ------------------------------------------------------------------

ProtoCCParser::Set_blockContext::Set_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Set_funcContext* ProtoCCParser::Set_blockContext::set_func() {
  return getRuleContext<ProtoCCParser::Set_funcContext>(0);
}

tree::TerminalNode* ProtoCCParser::Set_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Set_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleSet_block;
}


ProtoCCParser::Set_blockContext* ProtoCCParser::set_block() {
  Set_blockContext *_localctx = _tracker.createInstance<Set_blockContext>(_ctx, getState());
  enterRule(_localctx, 80, ProtoCCParser::RuleSet_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    set_func();
    setState(441);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_funcContext ------------------------------------------------------------------

ProtoCCParser::Set_funcContext::Set_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Set_funcContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Set_funcContext::DOT() {
  return getToken(ProtoCCParser::DOT, 0);
}

ProtoCCParser::Set_function_typesContext* ProtoCCParser::Set_funcContext::set_function_types() {
  return getRuleContext<ProtoCCParser::Set_function_typesContext>(0);
}

tree::TerminalNode* ProtoCCParser::Set_funcContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Set_funcContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

std::vector<ProtoCCParser::Set_nestContext *> ProtoCCParser::Set_funcContext::set_nest() {
  return getRuleContexts<ProtoCCParser::Set_nestContext>();
}

ProtoCCParser::Set_nestContext* ProtoCCParser::Set_funcContext::set_nest(size_t i) {
  return getRuleContext<ProtoCCParser::Set_nestContext>(i);
}


size_t ProtoCCParser::Set_funcContext::getRuleIndex() const {
  return ProtoCCParser::RuleSet_func;
}


ProtoCCParser::Set_funcContext* ProtoCCParser::set_func() {
  Set_funcContext *_localctx = _tracker.createInstance<Set_funcContext>(_ctx, getState());
  enterRule(_localctx, 82, ProtoCCParser::RuleSet_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(ProtoCCParser::ID);
    setState(444);
    match(ProtoCCParser::DOT);
    setState(445);
    set_function_types();
    setState(446);
    match(ProtoCCParser::OBRACE);
    setState(450);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::ID) {
      setState(447);
      set_nest();
      setState(452);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(453);
    match(ProtoCCParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_nestContext ------------------------------------------------------------------

ProtoCCParser::Set_nestContext::Set_nestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Set_funcContext* ProtoCCParser::Set_nestContext::set_func() {
  return getRuleContext<ProtoCCParser::Set_funcContext>(0);
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Set_nestContext::object_expr() {
  return getRuleContext<ProtoCCParser::Object_exprContext>(0);
}


size_t ProtoCCParser::Set_nestContext::getRuleIndex() const {
  return ProtoCCParser::RuleSet_nest;
}


ProtoCCParser::Set_nestContext* ProtoCCParser::set_nest() {
  Set_nestContext *_localctx = _tracker.createInstance<Set_nestContext>(_ctx, getState());
  enterRule(_localctx, 84, ProtoCCParser::RuleSet_nest);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(457);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(455);
      set_func();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(456);
      object_expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Internal_event_blockContext ------------------------------------------------------------------

ProtoCCParser::Internal_event_blockContext::Internal_event_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Internal_event_funcContext* ProtoCCParser::Internal_event_blockContext::internal_event_func() {
  return getRuleContext<ProtoCCParser::Internal_event_funcContext>(0);
}

tree::TerminalNode* ProtoCCParser::Internal_event_blockContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Internal_event_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleInternal_event_block;
}


ProtoCCParser::Internal_event_blockContext* ProtoCCParser::internal_event_block() {
  Internal_event_blockContext *_localctx = _tracker.createInstance<Internal_event_blockContext>(_ctx, getState());
  enterRule(_localctx, 86, ProtoCCParser::RuleInternal_event_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(459);
    internal_event_func();
    setState(460);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Internal_event_funcContext ------------------------------------------------------------------

ProtoCCParser::Internal_event_funcContext::Internal_event_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Internal_event_functionContext* ProtoCCParser::Internal_event_funcContext::internal_event_function() {
  return getRuleContext<ProtoCCParser::Internal_event_functionContext>(0);
}

tree::TerminalNode* ProtoCCParser::Internal_event_funcContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Internal_event_funcContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Internal_event_funcContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}


size_t ProtoCCParser::Internal_event_funcContext::getRuleIndex() const {
  return ProtoCCParser::RuleInternal_event_func;
}


ProtoCCParser::Internal_event_funcContext* ProtoCCParser::internal_event_func() {
  Internal_event_funcContext *_localctx = _tracker.createInstance<Internal_event_funcContext>(_ctx, getState());
  enterRule(_localctx, 88, ProtoCCParser::RuleInternal_event_func);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    internal_event_function();
    setState(463);
    match(ProtoCCParser::OBRACE);
    setState(464);
    match(ProtoCCParser::ID);
    setState(465);
    match(ProtoCCParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arch_blockContext ------------------------------------------------------------------

ProtoCCParser::Arch_blockContext::Arch_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Arch_blockContext::ARCH() {
  return getToken(ProtoCCParser::ARCH, 0);
}

tree::TerminalNode* ProtoCCParser::Arch_blockContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Arch_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

ProtoCCParser::Arch_bodyContext* ProtoCCParser::Arch_blockContext::arch_body() {
  return getRuleContext<ProtoCCParser::Arch_bodyContext>(0);
}

tree::TerminalNode* ProtoCCParser::Arch_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}


size_t ProtoCCParser::Arch_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleArch_block;
}


ProtoCCParser::Arch_blockContext* ProtoCCParser::arch_block() {
  Arch_blockContext *_localctx = _tracker.createInstance<Arch_blockContext>(_ctx, getState());
  enterRule(_localctx, 90, ProtoCCParser::RuleArch_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(467);
    match(ProtoCCParser::ARCH);
    setState(468);
    match(ProtoCCParser::ID);
    setState(469);
    match(ProtoCCParser::OCBRACE);
    setState(470);
    arch_body();
    setState(471);
    match(ProtoCCParser::CCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arch_bodyContext ------------------------------------------------------------------

ProtoCCParser::Arch_bodyContext::Arch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Stable_defContext* ProtoCCParser::Arch_bodyContext::stable_def() {
  return getRuleContext<ProtoCCParser::Stable_defContext>(0);
}

std::vector<ProtoCCParser::Process_blockContext *> ProtoCCParser::Arch_bodyContext::process_block() {
  return getRuleContexts<ProtoCCParser::Process_blockContext>();
}

ProtoCCParser::Process_blockContext* ProtoCCParser::Arch_bodyContext::process_block(size_t i) {
  return getRuleContext<ProtoCCParser::Process_blockContext>(i);
}


size_t ProtoCCParser::Arch_bodyContext::getRuleIndex() const {
  return ProtoCCParser::RuleArch_body;
}


ProtoCCParser::Arch_bodyContext* ProtoCCParser::arch_body() {
  Arch_bodyContext *_localctx = _tracker.createInstance<Arch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 92, ProtoCCParser::RuleArch_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    stable_def();
    setState(477);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::PROC) {
      setState(474);
      process_block();
      setState(479);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stable_defContext ------------------------------------------------------------------

ProtoCCParser::Stable_defContext::Stable_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Stable_defContext::STABLE() {
  return getToken(ProtoCCParser::STABLE, 0);
}

tree::TerminalNode* ProtoCCParser::Stable_defContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Stable_defContext::ID() {
  return getTokens(ProtoCCParser::ID);
}

tree::TerminalNode* ProtoCCParser::Stable_defContext::ID(size_t i) {
  return getToken(ProtoCCParser::ID, i);
}

tree::TerminalNode* ProtoCCParser::Stable_defContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Stable_defContext::COMMA() {
  return getTokens(ProtoCCParser::COMMA);
}

tree::TerminalNode* ProtoCCParser::Stable_defContext::COMMA(size_t i) {
  return getToken(ProtoCCParser::COMMA, i);
}


size_t ProtoCCParser::Stable_defContext::getRuleIndex() const {
  return ProtoCCParser::RuleStable_def;
}


ProtoCCParser::Stable_defContext* ProtoCCParser::stable_def() {
  Stable_defContext *_localctx = _tracker.createInstance<Stable_defContext>(_ctx, getState());
  enterRule(_localctx, 94, ProtoCCParser::RuleStable_def);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    match(ProtoCCParser::STABLE);
    setState(481);
    match(ProtoCCParser::OCBRACE);
    setState(482);
    match(ProtoCCParser::ID);
    setState(487);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::COMMA) {
      setState(483);
      match(ProtoCCParser::COMMA);
      setState(484);
      match(ProtoCCParser::ID);
      setState(489);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(490);
    match(ProtoCCParser::CCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_blockContext ------------------------------------------------------------------

ProtoCCParser::Process_blockContext::Process_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Process_blockContext::PROC() {
  return getToken(ProtoCCParser::PROC, 0);
}

ProtoCCParser::Process_transContext* ProtoCCParser::Process_blockContext::process_trans() {
  return getRuleContext<ProtoCCParser::Process_transContext>(0);
}

tree::TerminalNode* ProtoCCParser::Process_blockContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Process_blockContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

std::vector<ProtoCCParser::Process_exprContext *> ProtoCCParser::Process_blockContext::process_expr() {
  return getRuleContexts<ProtoCCParser::Process_exprContext>();
}

ProtoCCParser::Process_exprContext* ProtoCCParser::Process_blockContext::process_expr(size_t i) {
  return getRuleContext<ProtoCCParser::Process_exprContext>(i);
}


size_t ProtoCCParser::Process_blockContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_block;
}


ProtoCCParser::Process_blockContext* ProtoCCParser::process_block() {
  Process_blockContext *_localctx = _tracker.createInstance<Process_blockContext>(_ctx, getState());
  enterRule(_localctx, 96, ProtoCCParser::RuleProcess_block);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    match(ProtoCCParser::PROC);
    setState(493);
    process_trans();
    setState(494);
    match(ProtoCCParser::OCBRACE);
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & ((1ULL << (ProtoCCParser::T__6 - 7))
      | (1ULL << (ProtoCCParser::STATE - 7))
      | (1ULL << (ProtoCCParser::AWAIT - 7))
      | (1ULL << (ProtoCCParser::IF - 7))
      | (1ULL << (ProtoCCParser::ID - 7)))) != 0)) {
      setState(495);
      process_expr();
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(501);
    match(ProtoCCParser::CCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_transContext ------------------------------------------------------------------

ProtoCCParser::Process_transContext::Process_transContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Process_transContext::OBRACE() {
  return getToken(ProtoCCParser::OBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Process_transContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Process_transContext::COMMA() {
  return getToken(ProtoCCParser::COMMA, 0);
}

ProtoCCParser::Process_eventsContext* ProtoCCParser::Process_transContext::process_events() {
  return getRuleContext<ProtoCCParser::Process_eventsContext>(0);
}

tree::TerminalNode* ProtoCCParser::Process_transContext::CBRACE() {
  return getToken(ProtoCCParser::CBRACE, 0);
}

ProtoCCParser::Process_finalstateContext* ProtoCCParser::Process_transContext::process_finalstate() {
  return getRuleContext<ProtoCCParser::Process_finalstateContext>(0);
}


size_t ProtoCCParser::Process_transContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_trans;
}


ProtoCCParser::Process_transContext* ProtoCCParser::process_trans() {
  Process_transContext *_localctx = _tracker.createInstance<Process_transContext>(_ctx, getState());
  enterRule(_localctx, 98, ProtoCCParser::RuleProcess_trans);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    match(ProtoCCParser::OBRACE);
    setState(504);
    match(ProtoCCParser::ID);
    setState(505);
    match(ProtoCCParser::COMMA);
    setState(506);
    process_events();
    setState(508);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ProtoCCParser::COMMA) {
      setState(507);
      process_finalstate();
    }
    setState(510);
    match(ProtoCCParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_finalstateContext ------------------------------------------------------------------

ProtoCCParser::Process_finalstateContext::Process_finalstateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Process_finalstateContext::COMMA() {
  return getToken(ProtoCCParser::COMMA, 0);
}

ProtoCCParser::Process_finalidentContext* ProtoCCParser::Process_finalstateContext::process_finalident() {
  return getRuleContext<ProtoCCParser::Process_finalidentContext>(0);
}


size_t ProtoCCParser::Process_finalstateContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_finalstate;
}


ProtoCCParser::Process_finalstateContext* ProtoCCParser::process_finalstate() {
  Process_finalstateContext *_localctx = _tracker.createInstance<Process_finalstateContext>(_ctx, getState());
  enterRule(_localctx, 100, ProtoCCParser::RuleProcess_finalstate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    match(ProtoCCParser::COMMA);
    setState(513);
    process_finalident();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_finalidentContext ------------------------------------------------------------------

ProtoCCParser::Process_finalidentContext::Process_finalidentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Process_finalidentContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::Process_finalidentContext::STATE() {
  return getToken(ProtoCCParser::STATE, 0);
}


size_t ProtoCCParser::Process_finalidentContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_finalident;
}


ProtoCCParser::Process_finalidentContext* ProtoCCParser::process_finalident() {
  Process_finalidentContext *_localctx = _tracker.createInstance<Process_finalidentContext>(_ctx, getState());
  enterRule(_localctx, 102, ProtoCCParser::RuleProcess_finalident);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::STATE

    || _la == ProtoCCParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_eventsContext ------------------------------------------------------------------

ProtoCCParser::Process_eventsContext::Process_eventsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Process_eventsContext::ACCESS() {
  return getToken(ProtoCCParser::ACCESS, 0);
}

tree::TerminalNode* ProtoCCParser::Process_eventsContext::EVICT() {
  return getToken(ProtoCCParser::EVICT, 0);
}

tree::TerminalNode* ProtoCCParser::Process_eventsContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}


size_t ProtoCCParser::Process_eventsContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_events;
}


ProtoCCParser::Process_eventsContext* ProtoCCParser::process_events() {
  Process_eventsContext *_localctx = _tracker.createInstance<Process_eventsContext>(_ctx, getState());
  enterRule(_localctx, 104, ProtoCCParser::RuleProcess_events);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (ProtoCCParser::ACCESS - 67))
      | (1ULL << (ProtoCCParser::EVICT - 67))
      | (1ULL << (ProtoCCParser::ID - 67)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Process_exprContext ------------------------------------------------------------------

ProtoCCParser::Process_exprContext::Process_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::ExpressionsContext* ProtoCCParser::Process_exprContext::expressions() {
  return getRuleContext<ProtoCCParser::ExpressionsContext>(0);
}

ProtoCCParser::Network_sendContext* ProtoCCParser::Process_exprContext::network_send() {
  return getRuleContext<ProtoCCParser::Network_sendContext>(0);
}

ProtoCCParser::Network_mcastContext* ProtoCCParser::Process_exprContext::network_mcast() {
  return getRuleContext<ProtoCCParser::Network_mcastContext>(0);
}

ProtoCCParser::Network_bcastContext* ProtoCCParser::Process_exprContext::network_bcast() {
  return getRuleContext<ProtoCCParser::Network_bcastContext>(0);
}

ProtoCCParser::TransactionContext* ProtoCCParser::Process_exprContext::transaction() {
  return getRuleContext<ProtoCCParser::TransactionContext>(0);
}


size_t ProtoCCParser::Process_exprContext::getRuleIndex() const {
  return ProtoCCParser::RuleProcess_expr;
}


ProtoCCParser::Process_exprContext* ProtoCCParser::process_expr() {
  Process_exprContext *_localctx = _tracker.createInstance<Process_exprContext>(_ctx, getState());
  enterRule(_localctx, 106, ProtoCCParser::RuleProcess_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(524);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(519);
      expressions();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(520);
      network_send();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(521);
      network_mcast();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(522);
      network_bcast();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(523);
      transaction();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransactionContext ------------------------------------------------------------------

ProtoCCParser::TransactionContext::TransactionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::TransactionContext::AWAIT() {
  return getToken(ProtoCCParser::AWAIT, 0);
}

tree::TerminalNode* ProtoCCParser::TransactionContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::TransactionContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

std::vector<ProtoCCParser::TransContext *> ProtoCCParser::TransactionContext::trans() {
  return getRuleContexts<ProtoCCParser::TransContext>();
}

ProtoCCParser::TransContext* ProtoCCParser::TransactionContext::trans(size_t i) {
  return getRuleContext<ProtoCCParser::TransContext>(i);
}


size_t ProtoCCParser::TransactionContext::getRuleIndex() const {
  return ProtoCCParser::RuleTransaction;
}


ProtoCCParser::TransactionContext* ProtoCCParser::transaction() {
  TransactionContext *_localctx = _tracker.createInstance<TransactionContext>(_ctx, getState());
  enterRule(_localctx, 108, ProtoCCParser::RuleTransaction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    match(ProtoCCParser::AWAIT);
    setState(527);
    match(ProtoCCParser::OCBRACE);
    setState(531);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::WHEN) {
      setState(528);
      trans();
      setState(533);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(534);
    match(ProtoCCParser::CCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransContext ------------------------------------------------------------------

ProtoCCParser::TransContext::TransContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::TransContext::WHEN() {
  return getToken(ProtoCCParser::WHEN, 0);
}

tree::TerminalNode* ProtoCCParser::TransContext::ID() {
  return getToken(ProtoCCParser::ID, 0);
}

tree::TerminalNode* ProtoCCParser::TransContext::DDOT() {
  return getToken(ProtoCCParser::DDOT, 0);
}

std::vector<ProtoCCParser::Trans_bodyContext *> ProtoCCParser::TransContext::trans_body() {
  return getRuleContexts<ProtoCCParser::Trans_bodyContext>();
}

ProtoCCParser::Trans_bodyContext* ProtoCCParser::TransContext::trans_body(size_t i) {
  return getRuleContext<ProtoCCParser::Trans_bodyContext>(i);
}


size_t ProtoCCParser::TransContext::getRuleIndex() const {
  return ProtoCCParser::RuleTrans;
}


ProtoCCParser::TransContext* ProtoCCParser::trans() {
  TransContext *_localctx = _tracker.createInstance<TransContext>(_ctx, getState());
  enterRule(_localctx, 110, ProtoCCParser::RuleTrans);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(536);
    match(ProtoCCParser::WHEN);
    setState(537);
    match(ProtoCCParser::ID);
    setState(538);
    match(ProtoCCParser::DDOT);
    setState(542);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & ((1ULL << (ProtoCCParser::T__6 - 7))
      | (1ULL << (ProtoCCParser::STATE - 7))
      | (1ULL << (ProtoCCParser::AWAIT - 7))
      | (1ULL << (ProtoCCParser::NEXT - 7))
      | (1ULL << (ProtoCCParser::BREAK - 7))
      | (1ULL << (ProtoCCParser::IF - 7))
      | (1ULL << (ProtoCCParser::ID - 7)))) != 0)) {
      setState(539);
      trans_body();
      setState(544);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trans_bodyContext ------------------------------------------------------------------

ProtoCCParser::Trans_bodyContext::Trans_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::ExpressionsContext* ProtoCCParser::Trans_bodyContext::expressions() {
  return getRuleContext<ProtoCCParser::ExpressionsContext>(0);
}

ProtoCCParser::Next_transContext* ProtoCCParser::Trans_bodyContext::next_trans() {
  return getRuleContext<ProtoCCParser::Next_transContext>(0);
}

ProtoCCParser::Next_breakContext* ProtoCCParser::Trans_bodyContext::next_break() {
  return getRuleContext<ProtoCCParser::Next_breakContext>(0);
}

ProtoCCParser::TransactionContext* ProtoCCParser::Trans_bodyContext::transaction() {
  return getRuleContext<ProtoCCParser::TransactionContext>(0);
}

ProtoCCParser::Network_sendContext* ProtoCCParser::Trans_bodyContext::network_send() {
  return getRuleContext<ProtoCCParser::Network_sendContext>(0);
}

ProtoCCParser::Network_mcastContext* ProtoCCParser::Trans_bodyContext::network_mcast() {
  return getRuleContext<ProtoCCParser::Network_mcastContext>(0);
}

ProtoCCParser::Network_bcastContext* ProtoCCParser::Trans_bodyContext::network_bcast() {
  return getRuleContext<ProtoCCParser::Network_bcastContext>(0);
}


size_t ProtoCCParser::Trans_bodyContext::getRuleIndex() const {
  return ProtoCCParser::RuleTrans_body;
}


ProtoCCParser::Trans_bodyContext* ProtoCCParser::trans_body() {
  Trans_bodyContext *_localctx = _tracker.createInstance<Trans_bodyContext>(_ctx, getState());
  enterRule(_localctx, 112, ProtoCCParser::RuleTrans_body);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(552);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(545);
      expressions();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(546);
      next_trans();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(547);
      next_break();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(548);
      transaction();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(549);
      network_send();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(550);
      network_mcast();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(551);
      network_bcast();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Next_transContext ------------------------------------------------------------------

ProtoCCParser::Next_transContext::Next_transContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Next_transContext::NEXT() {
  return getToken(ProtoCCParser::NEXT, 0);
}

tree::TerminalNode* ProtoCCParser::Next_transContext::OCBRACE() {
  return getToken(ProtoCCParser::OCBRACE, 0);
}

tree::TerminalNode* ProtoCCParser::Next_transContext::CCBRACE() {
  return getToken(ProtoCCParser::CCBRACE, 0);
}

std::vector<ProtoCCParser::TransContext *> ProtoCCParser::Next_transContext::trans() {
  return getRuleContexts<ProtoCCParser::TransContext>();
}

ProtoCCParser::TransContext* ProtoCCParser::Next_transContext::trans(size_t i) {
  return getRuleContext<ProtoCCParser::TransContext>(i);
}


size_t ProtoCCParser::Next_transContext::getRuleIndex() const {
  return ProtoCCParser::RuleNext_trans;
}


ProtoCCParser::Next_transContext* ProtoCCParser::next_trans() {
  Next_transContext *_localctx = _tracker.createInstance<Next_transContext>(_ctx, getState());
  enterRule(_localctx, 114, ProtoCCParser::RuleNext_trans);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(ProtoCCParser::NEXT);
    setState(555);
    match(ProtoCCParser::OCBRACE);
    setState(559);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::WHEN) {
      setState(556);
      trans();
      setState(561);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(562);
    match(ProtoCCParser::CCBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Next_breakContext ------------------------------------------------------------------

ProtoCCParser::Next_breakContext::Next_breakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Next_breakContext::BREAK() {
  return getToken(ProtoCCParser::BREAK, 0);
}

tree::TerminalNode* ProtoCCParser::Next_breakContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::Next_breakContext::getRuleIndex() const {
  return ProtoCCParser::RuleNext_break;
}


ProtoCCParser::Next_breakContext* ProtoCCParser::next_break() {
  Next_breakContext *_localctx = _tracker.createInstance<Next_breakContext>(_ctx, getState());
  enterRule(_localctx, 116, ProtoCCParser::RuleNext_break);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    match(ProtoCCParser::BREAK);
    setState(565);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionsContext ------------------------------------------------------------------

ProtoCCParser::ExpressionsContext::ExpressionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::AssignmentContext* ProtoCCParser::ExpressionsContext::assignment() {
  return getRuleContext<ProtoCCParser::AssignmentContext>(0);
}

ProtoCCParser::ConditionalContext* ProtoCCParser::ExpressionsContext::conditional() {
  return getRuleContext<ProtoCCParser::ConditionalContext>(0);
}

ProtoCCParser::Object_blockContext* ProtoCCParser::ExpressionsContext::object_block() {
  return getRuleContext<ProtoCCParser::Object_blockContext>(0);
}

ProtoCCParser::Set_blockContext* ProtoCCParser::ExpressionsContext::set_block() {
  return getRuleContext<ProtoCCParser::Set_blockContext>(0);
}

ProtoCCParser::Internal_event_blockContext* ProtoCCParser::ExpressionsContext::internal_event_block() {
  return getRuleContext<ProtoCCParser::Internal_event_blockContext>(0);
}


size_t ProtoCCParser::ExpressionsContext::getRuleIndex() const {
  return ProtoCCParser::RuleExpressions;
}


ProtoCCParser::ExpressionsContext* ProtoCCParser::expressions() {
  ExpressionsContext *_localctx = _tracker.createInstance<ExpressionsContext>(_ctx, getState());
  enterRule(_localctx, 118, ProtoCCParser::RuleExpressions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(572);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(567);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(568);
      conditional();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(569);
      object_block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(570);
      set_block();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(571);
      internal_event_block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ProtoCCParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Process_finalidentContext* ProtoCCParser::AssignmentContext::process_finalident() {
  return getRuleContext<ProtoCCParser::Process_finalidentContext>(0);
}

tree::TerminalNode* ProtoCCParser::AssignmentContext::EQUALSIGN() {
  return getToken(ProtoCCParser::EQUALSIGN, 0);
}

ProtoCCParser::Assign_typesContext* ProtoCCParser::AssignmentContext::assign_types() {
  return getRuleContext<ProtoCCParser::Assign_typesContext>(0);
}

tree::TerminalNode* ProtoCCParser::AssignmentContext::SEMICOLON() {
  return getToken(ProtoCCParser::SEMICOLON, 0);
}


size_t ProtoCCParser::AssignmentContext::getRuleIndex() const {
  return ProtoCCParser::RuleAssignment;
}


ProtoCCParser::AssignmentContext* ProtoCCParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 120, ProtoCCParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(574);
    process_finalident();
    setState(575);
    match(ProtoCCParser::EQUALSIGN);
    setState(576);
    assign_types();
    setState(577);
    match(ProtoCCParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_typesContext ------------------------------------------------------------------

ProtoCCParser::Assign_typesContext::Assign_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Assign_typesContext::object_expr() {
  return getRuleContext<ProtoCCParser::Object_exprContext>(0);
}

ProtoCCParser::Message_constrContext* ProtoCCParser::Assign_typesContext::message_constr() {
  return getRuleContext<ProtoCCParser::Message_constrContext>(0);
}

ProtoCCParser::Math_opContext* ProtoCCParser::Assign_typesContext::math_op() {
  return getRuleContext<ProtoCCParser::Math_opContext>(0);
}

ProtoCCParser::Set_funcContext* ProtoCCParser::Assign_typesContext::set_func() {
  return getRuleContext<ProtoCCParser::Set_funcContext>(0);
}

tree::TerminalNode* ProtoCCParser::Assign_typesContext::INT() {
  return getToken(ProtoCCParser::INT, 0);
}

tree::TerminalNode* ProtoCCParser::Assign_typesContext::BOOL() {
  return getToken(ProtoCCParser::BOOL, 0);
}


size_t ProtoCCParser::Assign_typesContext::getRuleIndex() const {
  return ProtoCCParser::RuleAssign_types;
}


ProtoCCParser::Assign_typesContext* ProtoCCParser::assign_types() {
  Assign_typesContext *_localctx = _tracker.createInstance<Assign_typesContext>(_ctx, getState());
  enterRule(_localctx, 122, ProtoCCParser::RuleAssign_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(585);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(579);
      object_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(580);
      message_constr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(581);
      math_op();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(582);
      set_func();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(583);
      match(ProtoCCParser::INT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(584);
      match(ProtoCCParser::BOOL);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Math_opContext ------------------------------------------------------------------

ProtoCCParser::Math_opContext::Math_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::Val_rangeContext *> ProtoCCParser::Math_opContext::val_range() {
  return getRuleContexts<ProtoCCParser::Val_rangeContext>();
}

ProtoCCParser::Val_rangeContext* ProtoCCParser::Math_opContext::val_range(size_t i) {
  return getRuleContext<ProtoCCParser::Val_rangeContext>(i);
}

tree::TerminalNode* ProtoCCParser::Math_opContext::PLUS() {
  return getToken(ProtoCCParser::PLUS, 0);
}

tree::TerminalNode* ProtoCCParser::Math_opContext::MINUS() {
  return getToken(ProtoCCParser::MINUS, 0);
}


size_t ProtoCCParser::Math_opContext::getRuleIndex() const {
  return ProtoCCParser::RuleMath_op;
}


ProtoCCParser::Math_opContext* ProtoCCParser::math_op() {
  Math_opContext *_localctx = _tracker.createInstance<Math_opContext>(_ctx, getState());
  enterRule(_localctx, 124, ProtoCCParser::RuleMath_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(587);
    val_range();
    setState(588);
    _la = _input->LA(1);
    if (!(_la == ProtoCCParser::PLUS

    || _la == ProtoCCParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(589);
    val_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalContext ------------------------------------------------------------------

ProtoCCParser::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::If_stmtContext* ProtoCCParser::ConditionalContext::if_stmt() {
  return getRuleContext<ProtoCCParser::If_stmtContext>(0);
}

ProtoCCParser::Ifnot_stmtContext* ProtoCCParser::ConditionalContext::ifnot_stmt() {
  return getRuleContext<ProtoCCParser::Ifnot_stmtContext>(0);
}


size_t ProtoCCParser::ConditionalContext::getRuleIndex() const {
  return ProtoCCParser::RuleConditional;
}


ProtoCCParser::ConditionalContext* ProtoCCParser::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 126, ProtoCCParser::RuleConditional);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(593);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(591);
      if_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(592);
      ifnot_stmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_stmtContext ------------------------------------------------------------------

ProtoCCParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::If_stmtContext::IF() {
  return getToken(ProtoCCParser::IF, 0);
}

ProtoCCParser::Cond_combContext* ProtoCCParser::If_stmtContext::cond_comb() {
  return getRuleContext<ProtoCCParser::Cond_combContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::If_stmtContext::OCBRACE() {
  return getTokens(ProtoCCParser::OCBRACE);
}

tree::TerminalNode* ProtoCCParser::If_stmtContext::OCBRACE(size_t i) {
  return getToken(ProtoCCParser::OCBRACE, i);
}

ProtoCCParser::If_expressionContext* ProtoCCParser::If_stmtContext::if_expression() {
  return getRuleContext<ProtoCCParser::If_expressionContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::If_stmtContext::CCBRACE() {
  return getTokens(ProtoCCParser::CCBRACE);
}

tree::TerminalNode* ProtoCCParser::If_stmtContext::CCBRACE(size_t i) {
  return getToken(ProtoCCParser::CCBRACE, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::If_stmtContext::ELSE() {
  return getTokens(ProtoCCParser::ELSE);
}

tree::TerminalNode* ProtoCCParser::If_stmtContext::ELSE(size_t i) {
  return getToken(ProtoCCParser::ELSE, i);
}

std::vector<ProtoCCParser::Else_expressionContext *> ProtoCCParser::If_stmtContext::else_expression() {
  return getRuleContexts<ProtoCCParser::Else_expressionContext>();
}

ProtoCCParser::Else_expressionContext* ProtoCCParser::If_stmtContext::else_expression(size_t i) {
  return getRuleContext<ProtoCCParser::Else_expressionContext>(i);
}


size_t ProtoCCParser::If_stmtContext::getRuleIndex() const {
  return ProtoCCParser::RuleIf_stmt;
}


ProtoCCParser::If_stmtContext* ProtoCCParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 128, ProtoCCParser::RuleIf_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(595);
    match(ProtoCCParser::IF);
    setState(596);
    cond_comb();
    setState(597);
    match(ProtoCCParser::OCBRACE);
    setState(598);
    if_expression();
    setState(599);
    match(ProtoCCParser::CCBRACE);
    setState(607);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::ELSE) {
      setState(600);
      match(ProtoCCParser::ELSE);
      setState(601);
      match(ProtoCCParser::OCBRACE);
      setState(602);
      else_expression();
      setState(603);
      match(ProtoCCParser::CCBRACE);
      setState(609);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ifnot_stmtContext ------------------------------------------------------------------

ProtoCCParser::Ifnot_stmtContext::Ifnot_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Ifnot_stmtContext::IF() {
  return getToken(ProtoCCParser::IF, 0);
}

tree::TerminalNode* ProtoCCParser::Ifnot_stmtContext::NEG() {
  return getToken(ProtoCCParser::NEG, 0);
}

ProtoCCParser::Cond_combContext* ProtoCCParser::Ifnot_stmtContext::cond_comb() {
  return getRuleContext<ProtoCCParser::Cond_combContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Ifnot_stmtContext::OCBRACE() {
  return getTokens(ProtoCCParser::OCBRACE);
}

tree::TerminalNode* ProtoCCParser::Ifnot_stmtContext::OCBRACE(size_t i) {
  return getToken(ProtoCCParser::OCBRACE, i);
}

ProtoCCParser::If_expressionContext* ProtoCCParser::Ifnot_stmtContext::if_expression() {
  return getRuleContext<ProtoCCParser::If_expressionContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Ifnot_stmtContext::CCBRACE() {
  return getTokens(ProtoCCParser::CCBRACE);
}

tree::TerminalNode* ProtoCCParser::Ifnot_stmtContext::CCBRACE(size_t i) {
  return getToken(ProtoCCParser::CCBRACE, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Ifnot_stmtContext::ELSE() {
  return getTokens(ProtoCCParser::ELSE);
}

tree::TerminalNode* ProtoCCParser::Ifnot_stmtContext::ELSE(size_t i) {
  return getToken(ProtoCCParser::ELSE, i);
}

std::vector<ProtoCCParser::Else_expressionContext *> ProtoCCParser::Ifnot_stmtContext::else_expression() {
  return getRuleContexts<ProtoCCParser::Else_expressionContext>();
}

ProtoCCParser::Else_expressionContext* ProtoCCParser::Ifnot_stmtContext::else_expression(size_t i) {
  return getRuleContext<ProtoCCParser::Else_expressionContext>(i);
}


size_t ProtoCCParser::Ifnot_stmtContext::getRuleIndex() const {
  return ProtoCCParser::RuleIfnot_stmt;
}


ProtoCCParser::Ifnot_stmtContext* ProtoCCParser::ifnot_stmt() {
  Ifnot_stmtContext *_localctx = _tracker.createInstance<Ifnot_stmtContext>(_ctx, getState());
  enterRule(_localctx, 130, ProtoCCParser::RuleIfnot_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(610);
    match(ProtoCCParser::IF);
    setState(611);
    match(ProtoCCParser::NEG);
    setState(612);
    cond_comb();
    setState(613);
    match(ProtoCCParser::OCBRACE);
    setState(614);
    if_expression();
    setState(615);
    match(ProtoCCParser::CCBRACE);
    setState(623);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::ELSE) {
      setState(616);
      match(ProtoCCParser::ELSE);
      setState(617);
      match(ProtoCCParser::OCBRACE);
      setState(618);
      else_expression();
      setState(619);
      match(ProtoCCParser::CCBRACE);
      setState(625);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_expressionContext ------------------------------------------------------------------

ProtoCCParser::If_expressionContext::If_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::ExprwbreakContext *> ProtoCCParser::If_expressionContext::exprwbreak() {
  return getRuleContexts<ProtoCCParser::ExprwbreakContext>();
}

ProtoCCParser::ExprwbreakContext* ProtoCCParser::If_expressionContext::exprwbreak(size_t i) {
  return getRuleContext<ProtoCCParser::ExprwbreakContext>(i);
}


size_t ProtoCCParser::If_expressionContext::getRuleIndex() const {
  return ProtoCCParser::RuleIf_expression;
}


ProtoCCParser::If_expressionContext* ProtoCCParser::if_expression() {
  If_expressionContext *_localctx = _tracker.createInstance<If_expressionContext>(_ctx, getState());
  enterRule(_localctx, 132, ProtoCCParser::RuleIf_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(629);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & ((1ULL << (ProtoCCParser::T__6 - 7))
      | (1ULL << (ProtoCCParser::STATE - 7))
      | (1ULL << (ProtoCCParser::AWAIT - 7))
      | (1ULL << (ProtoCCParser::BREAK - 7))
      | (1ULL << (ProtoCCParser::IF - 7))
      | (1ULL << (ProtoCCParser::ID - 7)))) != 0)) {
      setState(626);
      exprwbreak();
      setState(631);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_expressionContext ------------------------------------------------------------------

ProtoCCParser::Else_expressionContext::Else_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::ExprwbreakContext *> ProtoCCParser::Else_expressionContext::exprwbreak() {
  return getRuleContexts<ProtoCCParser::ExprwbreakContext>();
}

ProtoCCParser::ExprwbreakContext* ProtoCCParser::Else_expressionContext::exprwbreak(size_t i) {
  return getRuleContext<ProtoCCParser::ExprwbreakContext>(i);
}


size_t ProtoCCParser::Else_expressionContext::getRuleIndex() const {
  return ProtoCCParser::RuleElse_expression;
}


ProtoCCParser::Else_expressionContext* ProtoCCParser::else_expression() {
  Else_expressionContext *_localctx = _tracker.createInstance<Else_expressionContext>(_ctx, getState());
  enterRule(_localctx, 134, ProtoCCParser::RuleElse_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(635);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 7) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 7)) & ((1ULL << (ProtoCCParser::T__6 - 7))
      | (1ULL << (ProtoCCParser::STATE - 7))
      | (1ULL << (ProtoCCParser::AWAIT - 7))
      | (1ULL << (ProtoCCParser::BREAK - 7))
      | (1ULL << (ProtoCCParser::IF - 7))
      | (1ULL << (ProtoCCParser::ID - 7)))) != 0)) {
      setState(632);
      exprwbreak();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprwbreakContext ------------------------------------------------------------------

ProtoCCParser::ExprwbreakContext::ExprwbreakContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::ExpressionsContext* ProtoCCParser::ExprwbreakContext::expressions() {
  return getRuleContext<ProtoCCParser::ExpressionsContext>(0);
}

ProtoCCParser::Network_sendContext* ProtoCCParser::ExprwbreakContext::network_send() {
  return getRuleContext<ProtoCCParser::Network_sendContext>(0);
}

ProtoCCParser::Network_mcastContext* ProtoCCParser::ExprwbreakContext::network_mcast() {
  return getRuleContext<ProtoCCParser::Network_mcastContext>(0);
}

ProtoCCParser::Network_bcastContext* ProtoCCParser::ExprwbreakContext::network_bcast() {
  return getRuleContext<ProtoCCParser::Network_bcastContext>(0);
}

ProtoCCParser::TransactionContext* ProtoCCParser::ExprwbreakContext::transaction() {
  return getRuleContext<ProtoCCParser::TransactionContext>(0);
}

ProtoCCParser::Next_breakContext* ProtoCCParser::ExprwbreakContext::next_break() {
  return getRuleContext<ProtoCCParser::Next_breakContext>(0);
}


size_t ProtoCCParser::ExprwbreakContext::getRuleIndex() const {
  return ProtoCCParser::RuleExprwbreak;
}


ProtoCCParser::ExprwbreakContext* ProtoCCParser::exprwbreak() {
  ExprwbreakContext *_localctx = _tracker.createInstance<ExprwbreakContext>(_ctx, getState());
  enterRule(_localctx, 136, ProtoCCParser::RuleExprwbreak);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(644);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(638);
      expressions();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(639);
      network_send();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(640);
      network_mcast();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(641);
      network_bcast();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(642);
      transaction();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(643);
      next_break();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_combContext ------------------------------------------------------------------

ProtoCCParser::Cond_combContext::Cond_combContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::Cond_relContext *> ProtoCCParser::Cond_combContext::cond_rel() {
  return getRuleContexts<ProtoCCParser::Cond_relContext>();
}

ProtoCCParser::Cond_relContext* ProtoCCParser::Cond_combContext::cond_rel(size_t i) {
  return getRuleContext<ProtoCCParser::Cond_relContext>(i);
}

std::vector<ProtoCCParser::Combinatorial_operatorContext *> ProtoCCParser::Cond_combContext::combinatorial_operator() {
  return getRuleContexts<ProtoCCParser::Combinatorial_operatorContext>();
}

ProtoCCParser::Combinatorial_operatorContext* ProtoCCParser::Cond_combContext::combinatorial_operator(size_t i) {
  return getRuleContext<ProtoCCParser::Combinatorial_operatorContext>(i);
}


size_t ProtoCCParser::Cond_combContext::getRuleIndex() const {
  return ProtoCCParser::RuleCond_comb;
}


ProtoCCParser::Cond_combContext* ProtoCCParser::cond_comb() {
  Cond_combContext *_localctx = _tracker.createInstance<Cond_combContext>(_ctx, getState());
  enterRule(_localctx, 138, ProtoCCParser::RuleCond_comb);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(646);
    cond_rel();
    setState(652);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::T__18

    || _la == ProtoCCParser::T__19) {
      setState(647);
      combinatorial_operator();
      setState(648);
      cond_rel();
      setState(654);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_relContext ------------------------------------------------------------------

ProtoCCParser::Cond_relContext::Cond_relContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Cond_selContext* ProtoCCParser::Cond_relContext::cond_sel() {
  return getRuleContext<ProtoCCParser::Cond_selContext>(0);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Cond_relContext::OBRACE() {
  return getTokens(ProtoCCParser::OBRACE);
}

tree::TerminalNode* ProtoCCParser::Cond_relContext::OBRACE(size_t i) {
  return getToken(ProtoCCParser::OBRACE, i);
}

std::vector<tree::TerminalNode *> ProtoCCParser::Cond_relContext::CBRACE() {
  return getTokens(ProtoCCParser::CBRACE);
}

tree::TerminalNode* ProtoCCParser::Cond_relContext::CBRACE(size_t i) {
  return getToken(ProtoCCParser::CBRACE, i);
}


size_t ProtoCCParser::Cond_relContext::getRuleIndex() const {
  return ProtoCCParser::RuleCond_rel;
}


ProtoCCParser::Cond_relContext* ProtoCCParser::cond_rel() {
  Cond_relContext *_localctx = _tracker.createInstance<Cond_relContext>(_ctx, getState());
  enterRule(_localctx, 140, ProtoCCParser::RuleCond_rel);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(658);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::OBRACE) {
      setState(655);
      match(ProtoCCParser::OBRACE);
      setState(660);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(661);
    cond_sel();
    setState(665);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ProtoCCParser::CBRACE) {
      setState(662);
      match(ProtoCCParser::CBRACE);
      setState(667);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_selContext ------------------------------------------------------------------

ProtoCCParser::Cond_selContext::Cond_selContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::Cond_type_exprContext *> ProtoCCParser::Cond_selContext::cond_type_expr() {
  return getRuleContexts<ProtoCCParser::Cond_type_exprContext>();
}

ProtoCCParser::Cond_type_exprContext* ProtoCCParser::Cond_selContext::cond_type_expr(size_t i) {
  return getRuleContext<ProtoCCParser::Cond_type_exprContext>(i);
}

std::vector<ProtoCCParser::Relational_operatorContext *> ProtoCCParser::Cond_selContext::relational_operator() {
  return getRuleContexts<ProtoCCParser::Relational_operatorContext>();
}

ProtoCCParser::Relational_operatorContext* ProtoCCParser::Cond_selContext::relational_operator(size_t i) {
  return getRuleContext<ProtoCCParser::Relational_operatorContext>(i);
}


size_t ProtoCCParser::Cond_selContext::getRuleIndex() const {
  return ProtoCCParser::RuleCond_sel;
}


ProtoCCParser::Cond_selContext* ProtoCCParser::cond_sel() {
  Cond_selContext *_localctx = _tracker.createInstance<Cond_selContext>(_ctx, getState());
  enterRule(_localctx, 142, ProtoCCParser::RuleCond_sel);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    cond_type_expr();
    setState(674);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::T__12)
      | (1ULL << ProtoCCParser::T__13)
      | (1ULL << ProtoCCParser::T__14)
      | (1ULL << ProtoCCParser::T__15)
      | (1ULL << ProtoCCParser::T__16)
      | (1ULL << ProtoCCParser::T__17))) != 0)) {
      setState(669);
      relational_operator();
      setState(670);
      cond_type_expr();
      setState(676);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_type_exprContext ------------------------------------------------------------------

ProtoCCParser::Cond_type_exprContext::Cond_type_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ProtoCCParser::Cond_typesContext *> ProtoCCParser::Cond_type_exprContext::cond_types() {
  return getRuleContexts<ProtoCCParser::Cond_typesContext>();
}

ProtoCCParser::Cond_typesContext* ProtoCCParser::Cond_type_exprContext::cond_types(size_t i) {
  return getRuleContext<ProtoCCParser::Cond_typesContext>(i);
}

std::vector<ProtoCCParser::Indv_math_opContext *> ProtoCCParser::Cond_type_exprContext::indv_math_op() {
  return getRuleContexts<ProtoCCParser::Indv_math_opContext>();
}

ProtoCCParser::Indv_math_opContext* ProtoCCParser::Cond_type_exprContext::indv_math_op(size_t i) {
  return getRuleContext<ProtoCCParser::Indv_math_opContext>(i);
}


size_t ProtoCCParser::Cond_type_exprContext::getRuleIndex() const {
  return ProtoCCParser::RuleCond_type_expr;
}


ProtoCCParser::Cond_type_exprContext* ProtoCCParser::cond_type_expr() {
  Cond_type_exprContext *_localctx = _tracker.createInstance<Cond_type_exprContext>(_ctx, getState());
  enterRule(_localctx, 144, ProtoCCParser::RuleCond_type_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(677);
    cond_types();
    setState(683);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::PLUS)
      | (1ULL << ProtoCCParser::MINUS)
      | (1ULL << ProtoCCParser::MULT))) != 0)) {
      setState(678);
      indv_math_op();
      setState(679);
      cond_types();
      setState(685);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indv_math_opContext ------------------------------------------------------------------

ProtoCCParser::Indv_math_opContext::Indv_math_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ProtoCCParser::Indv_math_opContext::PLUS() {
  return getToken(ProtoCCParser::PLUS, 0);
}

tree::TerminalNode* ProtoCCParser::Indv_math_opContext::MINUS() {
  return getToken(ProtoCCParser::MINUS, 0);
}

tree::TerminalNode* ProtoCCParser::Indv_math_opContext::MULT() {
  return getToken(ProtoCCParser::MULT, 0);
}


size_t ProtoCCParser::Indv_math_opContext::getRuleIndex() const {
  return ProtoCCParser::RuleIndv_math_op;
}


ProtoCCParser::Indv_math_opContext* ProtoCCParser::indv_math_op() {
  Indv_math_opContext *_localctx = _tracker.createInstance<Indv_math_opContext>(_ctx, getState());
  enterRule(_localctx, 146, ProtoCCParser::RuleIndv_math_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(686);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ProtoCCParser::PLUS)
      | (1ULL << ProtoCCParser::MINUS)
      | (1ULL << ProtoCCParser::MULT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_typesContext ------------------------------------------------------------------

ProtoCCParser::Cond_typesContext::Cond_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ProtoCCParser::Object_exprContext* ProtoCCParser::Cond_typesContext::object_expr() {
  return getRuleContext<ProtoCCParser::Object_exprContext>(0);
}

ProtoCCParser::Set_funcContext* ProtoCCParser::Cond_typesContext::set_func() {
  return getRuleContext<ProtoCCParser::Set_funcContext>(0);
}

tree::TerminalNode* ProtoCCParser::Cond_typesContext::INT() {
  return getToken(ProtoCCParser::INT, 0);
}

tree::TerminalNode* ProtoCCParser::Cond_typesContext::BOOL() {
  return getToken(ProtoCCParser::BOOL, 0);
}

tree::TerminalNode* ProtoCCParser::Cond_typesContext::NID() {
  return getToken(ProtoCCParser::NID, 0);
}


size_t ProtoCCParser::Cond_typesContext::getRuleIndex() const {
  return ProtoCCParser::RuleCond_types;
}


ProtoCCParser::Cond_typesContext* ProtoCCParser::cond_types() {
  Cond_typesContext *_localctx = _tracker.createInstance<Cond_typesContext>(_ctx, getState());
  enterRule(_localctx, 148, ProtoCCParser::RuleCond_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(693);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(688);
      object_expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(689);
      set_func();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(690);
      match(ProtoCCParser::INT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(691);
      match(ProtoCCParser::BOOL);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(692);
      match(ProtoCCParser::NID);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ProtoCCParser::_decisionToDFA;
atn::PredictionContextCache ProtoCCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ProtoCCParser::_atn;
std::vector<uint16_t> ProtoCCParser::_serializedATN;

std::vector<std::string> ProtoCCParser::_ruleNames = {
  "send_function", "mcast_function", "bcast_function", "internal_event_function", 
  "set_function_types", "relational_operator", "combinatorial_operator", 
  "document", "declarations", "const_decl", "int_decl", "bool_decl", "state_decl", 
  "data_decl", "id_decl", "set_decl", "range", "val_range", "array_decl", 
  "fifo_decl", "init_hw", "object_block", "object_expr", "object_id", "object_func", 
  "object_idres", "machines", "cache_block", "dir_block", "mem_block", "objset_decl", 
  "network_block", "element_type", "network_element", "network_send", "network_bcast", 
  "network_mcast", "message_block", "message_constr", "message_expr", "set_block", 
  "set_func", "set_nest", "internal_event_block", "internal_event_func", 
  "arch_block", "arch_body", "stable_def", "process_block", "process_trans", 
  "process_finalstate", "process_finalident", "process_events", "process_expr", 
  "transaction", "trans", "trans_body", "next_trans", "next_break", "expressions", 
  "assignment", "assign_types", "math_op", "conditional", "if_stmt", "ifnot_stmt", 
  "if_expression", "else_expression", "exprwbreak", "cond_comb", "cond_rel", 
  "cond_sel", "cond_type_expr", "indv_math_op", "cond_types"
};

std::vector<std::string> ProtoCCParser::_literalNames = {
  "", "'send'", "'Send'", "'mcast'", "'Mcast'", "'bcast'", "'Bcast'", "'Event'", 
  "'add'", "'count'", "'contains'", "'del'", "'clear'", "'=='", "'!='", 
  "'<='", "'>='", "'<'", "'>'", "'&'", "'|'", "'Ordered'", "'Unordered'", 
  "'Network'", "'Cache'", "'Directory'", "'Memory'", "'Message'", "'State'", 
  "'Data'", "'ID'", "'FIFO'", "'Architecture'", "'Process'", "'Stable'", 
  "'.'", "','", "':'", "';'", "'='", "'+'", "'-'", "'*'", "'#'", "'bool'", 
  "'int'", "'array'", "'set'", "'await'", "'next'", "'when'", "'break'", 
  "'if'", "'else'", "'{'", "'}'", "'['", "']'", "'('", "')'", "'!'", "", 
  "", "", "", "", "", "", "'evict'"
};

std::vector<std::string> ProtoCCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "NETWORK", "CACHE", "DIR", "MEM", "MSG", "STATE", 
  "DATA", "NID", "FIFO", "ARCH", "PROC", "STABLE", "DOT", "COMMA", "DDOT", 
  "SEMICOLON", "EQUALSIGN", "PLUS", "MINUS", "MULT", "CONSTANT", "BOOLID", 
  "INTID", "ARRAY", "SET", "AWAIT", "NEXT", "WHEN", "BREAK", "IF", "ELSE", 
  "OCBRACE", "CCBRACE", "OEBRACE", "CEBRACE", "OBRACE", "CBRACE", "NEG", 
  "WS", "COMMENT", "LineComment", "NEWLINE", "BOOL", "INT", "ACCESS", "EVICT", 
  "ID"
};

dfa::Vocabulary ProtoCCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ProtoCCParser::_tokenNames;

ProtoCCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x47, 0x2ba, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xab, 0xa, 0x9, 
    0xc, 0x9, 0xe, 0x9, 0xae, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xb5, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0xc0, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc3, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xcb, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0xce, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x7, 0x10, 0xdb, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xde, 0xb, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe4, 0xa, 0x10, 0xc, 
    0x10, 0xe, 0x10, 0xe7, 0xb, 0x10, 0x3, 0x10, 0x7, 0x10, 0xea, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xed, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x108, 0xa, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x10f, 0xa, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x7, 0x1a, 0x118, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x11b, 0xb, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x11f, 0xa, 0x1a, 0xc, 0x1a, 
    0xe, 0x1a, 0x122, 0xb, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x125, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x128, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x12f, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x7, 0x1d, 0x134, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x137, 
    0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x13b, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x13e, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x146, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
    0x149, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x14d, 0xa, 0x1e, 
    0xc, 0x1e, 0xe, 0x1e, 0x150, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x158, 0xa, 0x1f, 0xc, 0x1f, 
    0xe, 0x1f, 0x15b, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x15f, 
    0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x162, 0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x16f, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x172, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x19b, 0xa, 0x27, 0xc, 0x27, 
    0xe, 0x27, 0x19e, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x1a6, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 
    0x1a9, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x1ad, 0xa, 0x28, 
    0xc, 0x28, 0xe, 0x28, 0x1b0, 0xb, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x1b9, 0xa, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x1c3, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x1c6, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 
    0x1cc, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x1de, 
    0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x1e1, 0xb, 0x30, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x1e8, 0xa, 0x31, 0xc, 0x31, 
    0xe, 0x31, 0x1eb, 0xb, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x1f3, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 
    0x1f6, 0xb, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x1ff, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 
    0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 
    0x20f, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x214, 
    0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x217, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x21f, 0xa, 0x39, 
    0xc, 0x39, 0xe, 0x39, 0x222, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x22b, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x230, 0xa, 0x3b, 0xc, 0x3b, 
    0xe, 0x3b, 0x233, 0xb, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 
    0x3d, 0x23f, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 
    0x3f, 0x5, 0x3f, 0x24c, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x254, 0xa, 0x41, 0x3, 0x42, 
    0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
    0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x260, 0xa, 0x42, 0xc, 0x42, 
    0xe, 0x42, 0x263, 0xb, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 
    0x43, 0x7, 0x43, 0x270, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x273, 0xb, 
    0x43, 0x3, 0x44, 0x7, 0x44, 0x276, 0xa, 0x44, 0xc, 0x44, 0xe, 0x44, 
    0x279, 0xb, 0x44, 0x3, 0x45, 0x7, 0x45, 0x27c, 0xa, 0x45, 0xc, 0x45, 
    0xe, 0x45, 0x27f, 0xb, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
    0x3, 0x46, 0x3, 0x46, 0x5, 0x46, 0x287, 0xa, 0x46, 0x3, 0x47, 0x3, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x28d, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 
    0x290, 0xb, 0x47, 0x3, 0x48, 0x7, 0x48, 0x293, 0xa, 0x48, 0xc, 0x48, 
    0xe, 0x48, 0x296, 0xb, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x29a, 
    0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x29d, 0xb, 0x48, 0x3, 0x49, 0x3, 0x49, 
    0x3, 0x49, 0x3, 0x49, 0x7, 0x49, 0x2a3, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 
    0x2a6, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 
    0x2ac, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x2af, 0xb, 0x4a, 0x3, 0x4b, 
    0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x5, 
    0x4c, 0x2b8, 0xa, 0x4c, 0x3, 0x4c, 0x2, 0x2, 0x4d, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 
    0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x2, 
    0xf, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 0x7, 0x8, 0x3, 
    0x2, 0xa, 0xe, 0x3, 0x2, 0xf, 0x14, 0x3, 0x2, 0x15, 0x16, 0x4, 0x2, 
    0x44, 0x44, 0x47, 0x47, 0x4, 0x2, 0x20, 0x20, 0x47, 0x47, 0x3, 0x2, 
    0x17, 0x18, 0x4, 0x2, 0x1e, 0x1e, 0x47, 0x47, 0x3, 0x2, 0x45, 0x47, 
    0x3, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2a, 0x2c, 0x2, 0x2c0, 0x2, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x10, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xba, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x24, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0x28, 0x101, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x110, 0x3, 0x2, 0x2, 0x2, 0x32, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x129, 0x3, 0x2, 0x2, 0x2, 0x36, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x130, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x154, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x166, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x42, 0x176, 0x3, 0x2, 0x2, 0x2, 0x44, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x48, 0x184, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x1d0, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1ee, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x66, 0x202, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x205, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x207, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x210, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x72, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x22c, 0x3, 0x2, 0x2, 0x2, 0x76, 0x236, 0x3, 0x2, 0x2, 0x2, 0x78, 0x23e, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x240, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x24b, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x253, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x255, 0x3, 0x2, 0x2, 0x2, 0x84, 0x264, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x277, 0x3, 0x2, 0x2, 0x2, 0x88, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x286, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x288, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x294, 0x3, 0x2, 0x2, 0x2, 0x90, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x92, 0x2a7, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x96, 0x2b7, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x99, 0x9, 0x2, 0x2, 0x2, 0x99, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x9b, 0x9, 0x3, 0x2, 0x2, 0x9b, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9d, 0x9, 0x4, 0x2, 0x2, 0x9d, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9f, 0x7, 0x9, 0x2, 0x2, 0x9f, 0x9, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa1, 0x9, 0x5, 0x2, 0x2, 0xa1, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 
    0x9, 0x6, 0x2, 0x2, 0xa3, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x9, 
    0x7, 0x2, 0x2, 0xa5, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xab, 0x5, 0x14, 
    0xb, 0x2, 0xa7, 0xab, 0x5, 0x2a, 0x16, 0x2, 0xa8, 0xab, 0x5, 0x5c, 0x2f, 
    0x2, 0xa9, 0xab, 0x5, 0x78, 0x3d, 0x2, 0xaa, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb5, 0x5, 0x16, 
    0xc, 0x2, 0xb0, 0xb5, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xb5, 0x5, 0x1a, 0xe, 
    0x2, 0xb2, 0xb5, 0x5, 0x1c, 0xf, 0x2, 0xb3, 0xb5, 0x5, 0x1e, 0x10, 0x2, 
    0xb4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb3, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 
    0x2d, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x47, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x44, 
    0x2, 0x2, 0xb9, 0x15, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x2f, 0x2, 
    0x2, 0xbb, 0xbc, 0x5, 0x22, 0x12, 0x2, 0xbc, 0xc1, 0x7, 0x47, 0x2, 0x2, 
    0xbd, 0xbe, 0x7, 0x29, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0x44, 0x2, 0x2, 0xbf, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x28, 
    0x2, 0x2, 0xc5, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x2e, 0x2, 
    0x2, 0xc7, 0xcc, 0x7, 0x47, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x29, 0x2, 0x2, 
    0xc9, 0xcb, 0x7, 0x43, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x28, 0x2, 0x2, 0xd0, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xd2, 0x7, 0x1e, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x47, 0x2, 
    0x2, 0xd3, 0xd4, 0x7, 0x28, 0x2, 0x2, 0xd4, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xd6, 0x7, 0x1f, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x47, 0x2, 0x2, 0xd7, 
    0xd8, 0x7, 0x28, 0x2, 0x2, 0xd8, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdb, 
    0x5, 0x20, 0x11, 0x2, 0xda, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x7, 0x20, 0x2, 0x2, 0xe0, 0xeb, 0x7, 0x47, 0x2, 0x2, 
    0xe1, 0xe5, 0x7, 0x29, 0x2, 0x2, 0xe2, 0xe4, 0x5, 0x20, 0x11, 0x2, 0xe3, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 0x7, 0x47, 
    0x2, 0x2, 0xe9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 
    0xef, 0x7, 0x28, 0x2, 0x2, 0xef, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 
    0x7, 0x31, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x3a, 0x2, 0x2, 0xf2, 0xf3, 0x5, 
    0x24, 0x13, 0x2, 0xf3, 0xf4, 0x7, 0x3b, 0x2, 0x2, 0xf4, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf6, 0x7, 0x3a, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x24, 0x13, 
    0x2, 0xf7, 0xf8, 0x7, 0x25, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x25, 0x2, 0x2, 
    0xf9, 0xfa, 0x5, 0x24, 0x13, 0x2, 0xfa, 0xfb, 0x7, 0x3b, 0x2, 0x2, 0xfb, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x9, 0x8, 0x2, 0x2, 0xfd, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x30, 0x2, 0x2, 0xff, 0x100, 0x5, 
    0x22, 0x12, 0x2, 0x100, 0x27, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 
    0x21, 0x2, 0x2, 0x102, 0x103, 0x5, 0x22, 0x12, 0x2, 0x103, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x108, 0x5, 0x40, 0x21, 0x2, 0x105, 0x108, 0x5, 
    0x36, 0x1c, 0x2, 0x106, 0x108, 0x5, 0x4c, 0x27, 0x2, 0x107, 0x104, 0x3, 
    0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x108, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x2e, 
    0x18, 0x2, 0x10a, 0x10b, 0x7, 0x28, 0x2, 0x2, 0x10b, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x10c, 0x10f, 0x5, 0x30, 0x19, 0x2, 0x10d, 0x10f, 0x5, 0x32, 
    0x1a, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0x47, 
    0x2, 0x2, 0x111, 0x31, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x47, 
    0x2, 0x2, 0x113, 0x114, 0x7, 0x25, 0x2, 0x2, 0x114, 0x126, 0x5, 0x34, 
    0x1b, 0x2, 0x115, 0x119, 0x7, 0x3c, 0x2, 0x2, 0x116, 0x118, 0x5, 0x2e, 
    0x18, 0x2, 0x117, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x11a, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0x7, 0x26, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x2e, 
    0x18, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x125, 0x7, 0x3d, 0x2, 0x2, 0x124, 0x115, 0x3, 0x2, 
    0x2, 0x2, 0x125, 0x128, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x9, 0x9, 0x2, 
    0x2, 0x12a, 0x35, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12f, 0x5, 0x38, 0x1d, 
    0x2, 0x12c, 0x12f, 0x5, 0x3a, 0x1e, 0x2, 0x12d, 0x12f, 0x5, 0x3c, 0x1f, 
    0x2, 0x12e, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x130, 0x131, 0x7, 0x1a, 0x2, 0x2, 0x131, 0x135, 0x7, 0x38, 0x2, 0x2, 
    0x132, 0x134, 0x5, 0x12, 0xa, 0x2, 0x133, 0x132, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x3, 0x2, 0x2, 0x2, 
    0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13c, 0x7, 0x39, 0x2, 0x2, 
    0x139, 0x13b, 0x5, 0x3e, 0x20, 0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x13b, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x47, 0x2, 0x2, 
    0x140, 0x141, 0x7, 0x28, 0x2, 0x2, 0x141, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x143, 0x7, 0x1b, 0x2, 0x2, 0x143, 0x147, 0x7, 0x38, 0x2, 0x2, 
    0x144, 0x146, 0x5, 0x12, 0xa, 0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 
    0x146, 0x149, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14e, 0x7, 0x39, 0x2, 0x2, 
    0x14b, 0x14d, 0x5, 0x3e, 0x20, 0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x47, 0x2, 0x2, 
    0x152, 0x153, 0x7, 0x28, 0x2, 0x2, 0x153, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x154, 0x155, 0x7, 0x1c, 0x2, 0x2, 0x155, 0x159, 0x7, 0x38, 0x2, 0x2, 
    0x156, 0x158, 0x5, 0x12, 0xa, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 0x2, 
    0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 
    0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x160, 0x7, 0x39, 0x2, 0x2, 
    0x15d, 0x15f, 0x5, 0x3e, 0x20, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x47, 0x2, 0x2, 
    0x164, 0x165, 0x7, 0x28, 0x2, 0x2, 0x165, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x166, 0x167, 0x7, 0x31, 0x2, 0x2, 0x167, 0x168, 0x7, 0x3a, 0x2, 0x2, 
    0x168, 0x169, 0x5, 0x24, 0x13, 0x2, 0x169, 0x16a, 0x7, 0x3b, 0x2, 0x2, 
    0x16a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x19, 0x2, 0x2, 
    0x16c, 0x170, 0x7, 0x38, 0x2, 0x2, 0x16d, 0x16f, 0x5, 0x44, 0x23, 0x2, 
    0x16e, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x173, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 0x2, 
    0x173, 0x174, 0x7, 0x39, 0x2, 0x2, 0x174, 0x175, 0x7, 0x28, 0x2, 0x2, 
    0x175, 0x41, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x9, 0xa, 0x2, 0x2, 0x177, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x5, 0x42, 0x22, 0x2, 0x179, 
    0x17a, 0x7, 0x47, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x28, 0x2, 0x2, 0x17b, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x47, 0x2, 0x2, 0x17d, 
    0x17e, 0x7, 0x25, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0x2, 0x2, 0x2, 0x17f, 
    0x180, 0x7, 0x3c, 0x2, 0x2, 0x180, 0x181, 0x7, 0x47, 0x2, 0x2, 0x181, 
    0x182, 0x7, 0x3d, 0x2, 0x2, 0x182, 0x183, 0x7, 0x28, 0x2, 0x2, 0x183, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x7, 0x47, 0x2, 0x2, 0x185, 
    0x186, 0x7, 0x25, 0x2, 0x2, 0x186, 0x187, 0x5, 0x6, 0x4, 0x2, 0x187, 
    0x188, 0x7, 0x3c, 0x2, 0x2, 0x188, 0x189, 0x7, 0x47, 0x2, 0x2, 0x189, 
    0x18a, 0x7, 0x3d, 0x2, 0x2, 0x18a, 0x18b, 0x7, 0x28, 0x2, 0x2, 0x18b, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x47, 0x2, 0x2, 0x18d, 
    0x18e, 0x7, 0x25, 0x2, 0x2, 0x18e, 0x18f, 0x5, 0x4, 0x3, 0x2, 0x18f, 
    0x190, 0x7, 0x3c, 0x2, 0x2, 0x190, 0x191, 0x7, 0x47, 0x2, 0x2, 0x191, 
    0x192, 0x7, 0x26, 0x2, 0x2, 0x192, 0x193, 0x7, 0x47, 0x2, 0x2, 0x193, 
    0x194, 0x7, 0x3d, 0x2, 0x2, 0x194, 0x195, 0x7, 0x28, 0x2, 0x2, 0x195, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x7, 0x1d, 0x2, 0x2, 0x197, 
    0x198, 0x7, 0x47, 0x2, 0x2, 0x198, 0x19c, 0x7, 0x38, 0x2, 0x2, 0x199, 
    0x19b, 0x5, 0x12, 0xa, 0x2, 0x19a, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 
    0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 
    0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19e, 
    0x19c, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x39, 0x2, 0x2, 0x1a0, 
    0x1a1, 0x7, 0x28, 0x2, 0x2, 0x1a1, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
    0x1a3, 0x7, 0x47, 0x2, 0x2, 0x1a3, 0x1a7, 0x7, 0x3c, 0x2, 0x2, 0x1a4, 
    0x1a6, 0x5, 0x50, 0x29, 0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
    0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
    0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
    0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x26, 0x2, 0x2, 0x1ab, 
    0x1ad, 0x5, 0x50, 0x29, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
    0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 
    0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x3d, 0x2, 0x2, 0x1b2, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b9, 0x5, 0x2e, 0x18, 0x2, 0x1b4, 
    0x1b9, 0x5, 0x54, 0x2b, 0x2, 0x1b5, 0x1b9, 0x7, 0x44, 0x2, 0x2, 0x1b6, 
    0x1b9, 0x7, 0x43, 0x2, 0x2, 0x1b7, 0x1b9, 0x7, 0x20, 0x2, 0x2, 0x1b8, 
    0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
    0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 
    0x5, 0x54, 0x2b, 0x2, 0x1bb, 0x1bc, 0x7, 0x28, 0x2, 0x2, 0x1bc, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x47, 0x2, 0x2, 0x1be, 0x1bf, 
    0x7, 0x25, 0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0xa, 0x6, 0x2, 0x1c0, 0x1c4, 
    0x7, 0x3c, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x56, 0x2c, 0x2, 0x1c2, 0x1c1, 
    0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 
    0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c7, 
    0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 
    0x7, 0x3d, 0x2, 0x2, 0x1c8, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1cc, 
    0x5, 0x54, 0x2b, 0x2, 0x1ca, 0x1cc, 0x5, 0x2e, 0x18, 0x2, 0x1cb, 0x1c9, 
    0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x5, 0x5a, 0x2e, 0x2, 0x1ce, 0x1cf, 0x7, 
    0x28, 0x2, 0x2, 0x1cf, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x5, 
    0x8, 0x5, 0x2, 0x1d1, 0x1d2, 0x7, 0x3c, 0x2, 0x2, 0x1d2, 0x1d3, 0x7, 
    0x47, 0x2, 0x2, 0x1d3, 0x1d4, 0x7, 0x3d, 0x2, 0x2, 0x1d4, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x22, 0x2, 0x2, 0x1d6, 0x1d7, 0x7, 
    0x47, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x38, 0x2, 0x2, 0x1d8, 0x1d9, 0x5, 
    0x5e, 0x30, 0x2, 0x1d9, 0x1da, 0x7, 0x39, 0x2, 0x2, 0x1da, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x1db, 0x1df, 0x5, 0x60, 0x31, 0x2, 0x1dc, 0x1de, 0x5, 
    0x62, 0x32, 0x2, 0x1dd, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 
    0x2, 0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 
    0x2, 0x2, 0x2, 0x1e0, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 
    0x2, 0x2, 0x1e2, 0x1e3, 0x7, 0x24, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x38, 
    0x2, 0x2, 0x1e4, 0x1e9, 0x7, 0x47, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0x26, 
    0x2, 0x2, 0x1e6, 0x1e8, 0x7, 0x47, 0x2, 0x2, 0x1e7, 0x1e5, 0x3, 0x2, 
    0x2, 0x2, 0x1e8, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1e7, 0x3, 0x2, 
    0x2, 0x2, 0x1e9, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ec, 0x3, 0x2, 
    0x2, 0x2, 0x1eb, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 0x7, 0x39, 
    0x2, 0x2, 0x1ed, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x7, 0x23, 
    0x2, 0x2, 0x1ef, 0x1f0, 0x5, 0x64, 0x33, 0x2, 0x1f0, 0x1f4, 0x7, 0x38, 
    0x2, 0x2, 0x1f1, 0x1f3, 0x5, 0x6c, 0x37, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 
    0x2, 0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 
    0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x39, 
    0x2, 0x2, 0x1f8, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x7, 0x3c, 
    0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x47, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x26, 
    0x2, 0x2, 0x1fc, 0x1fe, 0x5, 0x6a, 0x36, 0x2, 0x1fd, 0x1ff, 0x5, 0x66, 
    0x34, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 
    0x2, 0x2, 0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x7, 0x3d, 
    0x2, 0x2, 0x201, 0x65, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 0x7, 0x26, 
    0x2, 0x2, 0x203, 0x204, 0x5, 0x68, 0x35, 0x2, 0x204, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x205, 0x206, 0x9, 0xb, 0x2, 0x2, 0x206, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x207, 0x208, 0x9, 0xc, 0x2, 0x2, 0x208, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x209, 0x20f, 0x5, 0x78, 0x3d, 0x2, 0x20a, 0x20f, 0x5, 0x46, 0x24, 0x2, 
    0x20b, 0x20f, 0x5, 0x4a, 0x26, 0x2, 0x20c, 0x20f, 0x5, 0x48, 0x25, 0x2, 
    0x20d, 0x20f, 0x5, 0x6e, 0x38, 0x2, 0x20e, 0x209, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20d, 0x3, 0x2, 0x2, 0x2, 
    0x20f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x7, 0x32, 0x2, 0x2, 
    0x211, 0x215, 0x7, 0x38, 0x2, 0x2, 0x212, 0x214, 0x5, 0x70, 0x39, 0x2, 
    0x213, 0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x217, 0x3, 0x2, 0x2, 0x2, 
    0x215, 0x213, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x3, 0x2, 0x2, 0x2, 
    0x216, 0x218, 0x3, 0x2, 0x2, 0x2, 0x217, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x218, 0x219, 0x7, 0x39, 0x2, 0x2, 0x219, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x7, 0x34, 0x2, 0x2, 0x21b, 0x21c, 0x7, 0x47, 0x2, 0x2, 
    0x21c, 0x220, 0x7, 0x27, 0x2, 0x2, 0x21d, 0x21f, 0x5, 0x72, 0x3a, 0x2, 
    0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x71, 0x3, 0x2, 0x2, 0x2, 0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 0x223, 
    0x22b, 0x5, 0x78, 0x3d, 0x2, 0x224, 0x22b, 0x5, 0x74, 0x3b, 0x2, 0x225, 
    0x22b, 0x5, 0x76, 0x3c, 0x2, 0x226, 0x22b, 0x5, 0x6e, 0x38, 0x2, 0x227, 
    0x22b, 0x5, 0x46, 0x24, 0x2, 0x228, 0x22b, 0x5, 0x4a, 0x26, 0x2, 0x229, 
    0x22b, 0x5, 0x48, 0x25, 0x2, 0x22a, 0x223, 0x3, 0x2, 0x2, 0x2, 0x22a, 
    0x224, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x225, 0x3, 0x2, 0x2, 0x2, 0x22a, 
    0x226, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x227, 0x3, 0x2, 0x2, 0x2, 0x22a, 
    0x228, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x7, 0x33, 0x2, 0x2, 0x22d, 
    0x231, 0x7, 0x38, 0x2, 0x2, 0x22e, 0x230, 0x5, 0x70, 0x39, 0x2, 0x22f, 
    0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x233, 0x3, 0x2, 0x2, 0x2, 0x231, 
    0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x3, 0x2, 0x2, 0x2, 0x232, 
    0x234, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x234, 
    0x235, 0x7, 0x39, 0x2, 0x2, 0x235, 0x75, 0x3, 0x2, 0x2, 0x2, 0x236, 
    0x237, 0x7, 0x35, 0x2, 0x2, 0x237, 0x238, 0x7, 0x28, 0x2, 0x2, 0x238, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23f, 0x5, 0x7a, 0x3e, 0x2, 0x23a, 
    0x23f, 0x5, 0x80, 0x41, 0x2, 0x23b, 0x23f, 0x5, 0x2c, 0x17, 0x2, 0x23c, 
    0x23f, 0x5, 0x52, 0x2a, 0x2, 0x23d, 0x23f, 0x5, 0x58, 0x2d, 0x2, 0x23e, 
    0x239, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23e, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23c, 0x3, 0x2, 0x2, 0x2, 0x23e, 
    0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 
    0x5, 0x68, 0x35, 0x2, 0x241, 0x242, 0x7, 0x29, 0x2, 0x2, 0x242, 0x243, 
    0x5, 0x7c, 0x3f, 0x2, 0x243, 0x244, 0x7, 0x28, 0x2, 0x2, 0x244, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x245, 0x24c, 0x5, 0x2e, 0x18, 0x2, 0x246, 0x24c, 
    0x5, 0x4e, 0x28, 0x2, 0x247, 0x24c, 0x5, 0x7e, 0x40, 0x2, 0x248, 0x24c, 
    0x5, 0x54, 0x2b, 0x2, 0x249, 0x24c, 0x7, 0x44, 0x2, 0x2, 0x24a, 0x24c, 
    0x7, 0x43, 0x2, 0x2, 0x24b, 0x245, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x246, 
    0x3, 0x2, 0x2, 0x2, 0x24b, 0x247, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x248, 
    0x3, 0x2, 0x2, 0x2, 0x24b, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24a, 
    0x3, 0x2, 0x2, 0x2, 0x24c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 0x5, 
    0x24, 0x13, 0x2, 0x24e, 0x24f, 0x9, 0xd, 0x2, 0x2, 0x24f, 0x250, 0x5, 
    0x24, 0x13, 0x2, 0x250, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x251, 0x254, 0x5, 
    0x82, 0x42, 0x2, 0x252, 0x254, 0x5, 0x84, 0x43, 0x2, 0x253, 0x251, 0x3, 
    0x2, 0x2, 0x2, 0x253, 0x252, 0x3, 0x2, 0x2, 0x2, 0x254, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x255, 0x256, 0x7, 0x36, 0x2, 0x2, 0x256, 0x257, 0x5, 0x8c, 
    0x47, 0x2, 0x257, 0x258, 0x7, 0x38, 0x2, 0x2, 0x258, 0x259, 0x5, 0x86, 
    0x44, 0x2, 0x259, 0x261, 0x7, 0x39, 0x2, 0x2, 0x25a, 0x25b, 0x7, 0x37, 
    0x2, 0x2, 0x25b, 0x25c, 0x7, 0x38, 0x2, 0x2, 0x25c, 0x25d, 0x5, 0x88, 
    0x45, 0x2, 0x25d, 0x25e, 0x7, 0x39, 0x2, 0x2, 0x25e, 0x260, 0x3, 0x2, 
    0x2, 0x2, 0x25f, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x260, 0x263, 0x3, 0x2, 
    0x2, 0x2, 0x261, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 
    0x2, 0x2, 0x262, 0x83, 0x3, 0x2, 0x2, 0x2, 0x263, 0x261, 0x3, 0x2, 0x2, 
    0x2, 0x264, 0x265, 0x7, 0x36, 0x2, 0x2, 0x265, 0x266, 0x7, 0x3e, 0x2, 
    0x2, 0x266, 0x267, 0x5, 0x8c, 0x47, 0x2, 0x267, 0x268, 0x7, 0x38, 0x2, 
    0x2, 0x268, 0x269, 0x5, 0x86, 0x44, 0x2, 0x269, 0x271, 0x7, 0x39, 0x2, 
    0x2, 0x26a, 0x26b, 0x7, 0x37, 0x2, 0x2, 0x26b, 0x26c, 0x7, 0x38, 0x2, 
    0x2, 0x26c, 0x26d, 0x5, 0x88, 0x45, 0x2, 0x26d, 0x26e, 0x7, 0x39, 0x2, 
    0x2, 0x26e, 0x270, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26a, 0x3, 0x2, 0x2, 
    0x2, 0x270, 0x273, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26f, 0x3, 0x2, 0x2, 
    0x2, 0x271, 0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x271, 0x3, 0x2, 0x2, 0x2, 0x274, 0x276, 0x5, 0x8a, 0x46, 0x2, 
    0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x279, 0x3, 0x2, 0x2, 0x2, 
    0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x87, 0x3, 0x2, 0x2, 0x2, 0x279, 0x277, 0x3, 0x2, 0x2, 0x2, 0x27a, 
    0x27c, 0x5, 0x8a, 0x46, 0x2, 0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 
    0x27f, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27d, 
    0x27e, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 
    0x3, 0x2, 0x2, 0x2, 0x280, 0x287, 0x5, 0x78, 0x3d, 0x2, 0x281, 0x287, 
    0x5, 0x46, 0x24, 0x2, 0x282, 0x287, 0x5, 0x4a, 0x26, 0x2, 0x283, 0x287, 
    0x5, 0x48, 0x25, 0x2, 0x284, 0x287, 0x5, 0x6e, 0x38, 0x2, 0x285, 0x287, 
    0x5, 0x76, 0x3c, 0x2, 0x286, 0x280, 0x3, 0x2, 0x2, 0x2, 0x286, 0x281, 
    0x3, 0x2, 0x2, 0x2, 0x286, 0x282, 0x3, 0x2, 0x2, 0x2, 0x286, 0x283, 
    0x3, 0x2, 0x2, 0x2, 0x286, 0x284, 0x3, 0x2, 0x2, 0x2, 0x286, 0x285, 
    0x3, 0x2, 0x2, 0x2, 0x287, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28e, 0x5, 
    0x8e, 0x48, 0x2, 0x289, 0x28a, 0x5, 0xe, 0x8, 0x2, 0x28a, 0x28b, 0x5, 
    0x8e, 0x48, 0x2, 0x28b, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x289, 0x3, 
    0x2, 0x2, 0x2, 0x28d, 0x290, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28c, 0x3, 
    0x2, 0x2, 0x2, 0x28e, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x291, 0x293, 0x7, 0x3c, 
    0x2, 0x2, 0x292, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 0x296, 0x3, 0x2, 
    0x2, 0x2, 0x294, 0x292, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 
    0x2, 0x2, 0x295, 0x297, 0x3, 0x2, 0x2, 0x2, 0x296, 0x294, 0x3, 0x2, 
    0x2, 0x2, 0x297, 0x29b, 0x5, 0x90, 0x49, 0x2, 0x298, 0x29a, 0x7, 0x3d, 
    0x2, 0x2, 0x299, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29d, 0x3, 0x2, 
    0x2, 0x2, 0x29b, 0x299, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 0x3, 0x2, 
    0x2, 0x2, 0x29c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29b, 0x3, 0x2, 0x2, 
    0x2, 0x29e, 0x2a4, 0x5, 0x92, 0x4a, 0x2, 0x29f, 0x2a0, 0x5, 0xc, 0x7, 
    0x2, 0x2a0, 0x2a1, 0x5, 0x92, 0x4a, 0x2, 0x2a1, 0x2a3, 0x3, 0x2, 0x2, 
    0x2, 0x2a2, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a6, 0x3, 0x2, 0x2, 
    0x2, 0x2a4, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 
    0x2, 0x2a5, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a4, 0x3, 0x2, 0x2, 0x2, 
    0x2a7, 0x2ad, 0x5, 0x96, 0x4c, 0x2, 0x2a8, 0x2a9, 0x5, 0x94, 0x4b, 0x2, 
    0x2a9, 0x2aa, 0x5, 0x96, 0x4c, 0x2, 0x2aa, 0x2ac, 0x3, 0x2, 0x2, 0x2, 
    0x2ab, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2af, 0x3, 0x2, 0x2, 0x2, 
    0x2ad, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 
    0x2ae, 0x93, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
    0x2b1, 0x9, 0xe, 0x2, 0x2, 0x2b1, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b8, 
    0x5, 0x2e, 0x18, 0x2, 0x2b3, 0x2b8, 0x5, 0x54, 0x2b, 0x2, 0x2b4, 0x2b8, 
    0x7, 0x44, 0x2, 0x2, 0x2b5, 0x2b8, 0x7, 0x43, 0x2, 0x2, 0x2b6, 0x2b8, 
    0x7, 0x20, 0x2, 0x2, 0x2b7, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b3, 
    0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 
    0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0xaa, 0xac, 0xb4, 0xc1, 0xcc, 0xdc, 0xe5, 0xeb, 
    0x107, 0x10e, 0x119, 0x120, 0x126, 0x12e, 0x135, 0x13c, 0x147, 0x14e, 
    0x159, 0x160, 0x170, 0x19c, 0x1a7, 0x1ae, 0x1b8, 0x1c4, 0x1cb, 0x1df, 
    0x1e9, 0x1f4, 0x1fe, 0x20e, 0x215, 0x220, 0x22a, 0x231, 0x23e, 0x24b, 
    0x253, 0x261, 0x271, 0x277, 0x27d, 0x286, 0x28e, 0x294, 0x29b, 0x2a4, 
    0x2ad, 0x2b7, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ProtoCCParser::Initializer ProtoCCParser::_init;
