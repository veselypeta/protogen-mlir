
// Generated from /Users/petrvesely/dev/mlir/mlir-standalone-template/ProtoCC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  ProtoCCLexer : public antlr4::Lexer {
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

  ProtoCCLexer(antlr4::CharStream *input);
  ~ProtoCCLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

