
// Generated from usbm.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  usbmLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, TITLE = 2, TOOLKIT = 3, SYNTAX = 4, LOCATION = 5, DESCRIPTION = 6, 
    KW = 7, KEYWORD = 8, KW_SEP = 9, XREF = 10, EXAMPLE = 11, NOTE = 12, 
    NOTES = 13, CODE = 14, OPEN_1 = 15, CLOSE_1 = 16, OPEN_3 = 17, CLOSE_3 = 18, 
    OPEN_4 = 19, CLOSE_4 = 20, TEXT = 21, OPEN_2 = 22, CLOSE_2 = 23, LISTING = 24, 
    DQ_STRING = 25, SQ_STRING = 26, COMMENT_SL = 27, COMMENT_ML = 28, TITLE_ID = 29, 
    NUMBER = 30, WS = 31
  };

  usbmLexer(antlr4::CharStream *input);
  ~usbmLexer();

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

