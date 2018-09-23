
// Generated from usbm.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  usbmParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, TITLE = 2, TOOLKIT = 3, SYNTAX = 4, LOCATION = 5, DESCRIPTION = 6, 
    KW = 7, KEYWORD = 8, KW_SEP = 9, XREF = 10, EXAMPLE = 11, NOTE = 12, 
    NOTES = 13, CODE = 14, OPEN_1 = 15, CLOSE_1 = 16, OPEN_3 = 17, CLOSE_3 = 18, 
    OPEN_4 = 19, CLOSE_4 = 20, TEXT = 21, OPEN_2 = 22, CLOSE_2 = 23, LISTING = 24, 
    DQ_STRING = 25, SQ_STRING = 26, COMMENT_SL = 27, COMMENT_ML = 28, TITLE_ID = 29, 
    NUMBER = 30, WS = 31
  };

  enum {
    RuleFile = 0, RuleToolkit = 1, RuleLocation = 2, RuleKeyword = 3, RuleTitle = 4, 
    RuleTitle_id = 5, RuleSyntax = 6, RuleDescription = 7, RuleExample = 8, 
    RuleKw_notes = 9, RuleNote = 10, RuleNotes = 11, RuleNoteheader = 12, 
    RuleNotelist = 13, RuleListing = 14, RuleXref = 15, RuleString = 16, 
    RuleText = 17
  };

  usbmParser(antlr4::TokenStream *input);
  ~usbmParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class ToolkitContext;
  class LocationContext;
  class KeywordContext;
  class TitleContext;
  class Title_idContext;
  class SyntaxContext;
  class DescriptionContext;
  class ExampleContext;
  class Kw_notesContext;
  class NoteContext;
  class NotesContext;
  class NoteheaderContext;
  class NotelistContext;
  class ListingContext;
  class XrefContext;
  class StringContext;
  class TextContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ToolkitContext *toolkit();
    LocationContext *location();
    std::vector<KeywordContext *> keyword();
    KeywordContext* keyword(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  ToolkitContext : public antlr4::ParserRuleContext {
  public:
    ToolkitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOOLKIT();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ToolkitContext* toolkit();

  class  LocationContext : public antlr4::ParserRuleContext {
  public:
    LocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCATION();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LocationContext* location();

  class  KeywordContext : public antlr4::ParserRuleContext {
  public:
    KeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TitleContext *title();
    DescriptionContext *description();
    std::vector<SyntaxContext *> syntax();
    SyntaxContext* syntax(size_t i);
    std::vector<ExampleContext *> example();
    ExampleContext* example(size_t i);
    std::vector<Kw_notesContext *> kw_notes();
    Kw_notesContext* kw_notes(size_t i);
    std::vector<XrefContext *> xref();
    XrefContext* xref(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  KeywordContext* keyword();

  class  TitleContext : public antlr4::ParserRuleContext {
  public:
    TitleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Title_idContext *title_id();
    antlr4::tree::TerminalNode *KW();
    antlr4::tree::TerminalNode *KEYWORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TitleContext* title();

  class  Title_idContext : public antlr4::ParserRuleContext {
  public:
    Title_idContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TITLE_ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Title_idContext* title_id();

  class  SyntaxContext : public antlr4::ParserRuleContext {
  public:
    SyntaxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SYNTAX();
    StringContext *string();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SyntaxContext* syntax();

  class  DescriptionContext : public antlr4::ParserRuleContext {
  public:
    DescriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DESCRIPTION();
    std::vector<TextContext *> text();
    TextContext* text(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescriptionContext* description();

  class  ExampleContext : public antlr4::ParserRuleContext {
  public:
    ExampleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXAMPLE();
    std::vector<TextContext *> text();
    TextContext* text(size_t i);
    std::vector<ListingContext *> listing();
    ListingContext* listing(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExampleContext* example();

  class  Kw_notesContext : public antlr4::ParserRuleContext {
  public:
    Kw_notesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NoteContext *note();
    NotesContext *notes();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Kw_notesContext* kw_notes();

  class  NoteContext : public antlr4::ParserRuleContext {
  public:
    NoteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTE();
    std::vector<NotelistContext *> notelist();
    NotelistContext* notelist(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoteContext* note();

  class  NotesContext : public antlr4::ParserRuleContext {
  public:
    NotesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTES();
    std::vector<NoteheaderContext *> noteheader();
    NoteheaderContext* noteheader(size_t i);
    std::vector<NotelistContext *> notelist();
    NotelistContext* notelist(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NotesContext* notes();

  class  NoteheaderContext : public antlr4::ParserRuleContext {
  public:
    NoteheaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoteheaderContext* noteheader();

  class  NotelistContext : public antlr4::ParserRuleContext {
  public:
    NotelistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TextContext *text();
    ListingContext *listing();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NotelistContext* notelist();

  class  ListingContext : public antlr4::ParserRuleContext {
  public:
    ListingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CODE();
    antlr4::tree::TerminalNode *LISTING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ListingContext* listing();

  class  XrefContext : public antlr4::ParserRuleContext {
  public:
    XrefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *XREF();
    std::vector<Title_idContext *> title_id();
    Title_idContext* title_id(size_t i);
    std::vector<antlr4::tree::TerminalNode *> KW_SEP();
    antlr4::tree::TerminalNode* KW_SEP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  XrefContext* xref();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SQ_STRING();
    antlr4::tree::TerminalNode *DQ_STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringContext* string();

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TextContext* text();


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

