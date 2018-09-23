
// Generated from usbm.g4 by ANTLR 4.7.1


#include "usbmListener.h"

#include "usbmParser.h"


using namespace antlrcpp;
using namespace antlr4;

usbmParser::usbmParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

usbmParser::~usbmParser() {
  delete _interpreter;
}

std::string usbmParser::getGrammarFileName() const {
  return "usbm.g4";
}

const std::vector<std::string>& usbmParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& usbmParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

usbmParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

usbmParser::ToolkitContext* usbmParser::FileContext::toolkit() {
  return getRuleContext<usbmParser::ToolkitContext>(0);
}

usbmParser::LocationContext* usbmParser::FileContext::location() {
  return getRuleContext<usbmParser::LocationContext>(0);
}

std::vector<usbmParser::KeywordContext *> usbmParser::FileContext::keyword() {
  return getRuleContexts<usbmParser::KeywordContext>();
}

usbmParser::KeywordContext* usbmParser::FileContext::keyword(size_t i) {
  return getRuleContext<usbmParser::KeywordContext>(i);
}


size_t usbmParser::FileContext::getRuleIndex() const {
  return usbmParser::RuleFile;
}

void usbmParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void usbmParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

usbmParser::FileContext* usbmParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, usbmParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    toolkit();
    setState(37);
    location();
    setState(39); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      keyword();
      setState(41); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::KW

    || _la == usbmParser::KEYWORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToolkitContext ------------------------------------------------------------------

usbmParser::ToolkitContext::ToolkitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::ToolkitContext::TOOLKIT() {
  return getToken(usbmParser::TOOLKIT, 0);
}

usbmParser::StringContext* usbmParser::ToolkitContext::string() {
  return getRuleContext<usbmParser::StringContext>(0);
}


size_t usbmParser::ToolkitContext::getRuleIndex() const {
  return usbmParser::RuleToolkit;
}

void usbmParser::ToolkitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToolkit(this);
}

void usbmParser::ToolkitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToolkit(this);
}

usbmParser::ToolkitContext* usbmParser::toolkit() {
  ToolkitContext *_localctx = _tracker.createInstance<ToolkitContext>(_ctx, getState());
  enterRule(_localctx, 2, usbmParser::RuleToolkit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(usbmParser::TOOLKIT);
    setState(44);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocationContext ------------------------------------------------------------------

usbmParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::LocationContext::LOCATION() {
  return getToken(usbmParser::LOCATION, 0);
}

usbmParser::StringContext* usbmParser::LocationContext::string() {
  return getRuleContext<usbmParser::StringContext>(0);
}


size_t usbmParser::LocationContext::getRuleIndex() const {
  return usbmParser::RuleLocation;
}

void usbmParser::LocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocation(this);
}

void usbmParser::LocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocation(this);
}

usbmParser::LocationContext* usbmParser::location() {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState());
  enterRule(_localctx, 4, usbmParser::RuleLocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(usbmParser::LOCATION);
    setState(47);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

usbmParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

usbmParser::TitleContext* usbmParser::KeywordContext::title() {
  return getRuleContext<usbmParser::TitleContext>(0);
}

usbmParser::DescriptionContext* usbmParser::KeywordContext::description() {
  return getRuleContext<usbmParser::DescriptionContext>(0);
}

std::vector<usbmParser::SyntaxContext *> usbmParser::KeywordContext::syntax() {
  return getRuleContexts<usbmParser::SyntaxContext>();
}

usbmParser::SyntaxContext* usbmParser::KeywordContext::syntax(size_t i) {
  return getRuleContext<usbmParser::SyntaxContext>(i);
}

std::vector<usbmParser::ExampleContext *> usbmParser::KeywordContext::example() {
  return getRuleContexts<usbmParser::ExampleContext>();
}

usbmParser::ExampleContext* usbmParser::KeywordContext::example(size_t i) {
  return getRuleContext<usbmParser::ExampleContext>(i);
}

std::vector<usbmParser::Kw_notesContext *> usbmParser::KeywordContext::kw_notes() {
  return getRuleContexts<usbmParser::Kw_notesContext>();
}

usbmParser::Kw_notesContext* usbmParser::KeywordContext::kw_notes(size_t i) {
  return getRuleContext<usbmParser::Kw_notesContext>(i);
}

std::vector<usbmParser::XrefContext *> usbmParser::KeywordContext::xref() {
  return getRuleContexts<usbmParser::XrefContext>();
}

usbmParser::XrefContext* usbmParser::KeywordContext::xref(size_t i) {
  return getRuleContext<usbmParser::XrefContext>(i);
}


size_t usbmParser::KeywordContext::getRuleIndex() const {
  return usbmParser::RuleKeyword;
}

void usbmParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void usbmParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}

usbmParser::KeywordContext* usbmParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 6, usbmParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    title();
    setState(51); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(50);
      syntax();
      setState(53); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::SYNTAX);
    setState(55);
    description();
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == usbmParser::EXAMPLE) {
      setState(56);
      example();
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == usbmParser::NOTE

    || _la == usbmParser::NOTES) {
      setState(62);
      kw_notes();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == usbmParser::XREF) {
      setState(68);
      xref();
      setState(73);
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

//----------------- TitleContext ------------------------------------------------------------------

usbmParser::TitleContext::TitleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

usbmParser::Title_idContext* usbmParser::TitleContext::title_id() {
  return getRuleContext<usbmParser::Title_idContext>(0);
}

tree::TerminalNode* usbmParser::TitleContext::KW() {
  return getToken(usbmParser::KW, 0);
}

tree::TerminalNode* usbmParser::TitleContext::KEYWORD() {
  return getToken(usbmParser::KEYWORD, 0);
}


size_t usbmParser::TitleContext::getRuleIndex() const {
  return usbmParser::RuleTitle;
}

void usbmParser::TitleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTitle(this);
}

void usbmParser::TitleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTitle(this);
}

usbmParser::TitleContext* usbmParser::title() {
  TitleContext *_localctx = _tracker.createInstance<TitleContext>(_ctx, getState());
  enterRule(_localctx, 8, usbmParser::RuleTitle);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    _la = _input->LA(1);
    if (!(_la == usbmParser::KW

    || _la == usbmParser::KEYWORD)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(75);
    title_id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Title_idContext ------------------------------------------------------------------

usbmParser::Title_idContext::Title_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::Title_idContext::TITLE_ID() {
  return getToken(usbmParser::TITLE_ID, 0);
}


size_t usbmParser::Title_idContext::getRuleIndex() const {
  return usbmParser::RuleTitle_id;
}

void usbmParser::Title_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTitle_id(this);
}

void usbmParser::Title_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTitle_id(this);
}

usbmParser::Title_idContext* usbmParser::title_id() {
  Title_idContext *_localctx = _tracker.createInstance<Title_idContext>(_ctx, getState());
  enterRule(_localctx, 10, usbmParser::RuleTitle_id);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(usbmParser::TITLE_ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SyntaxContext ------------------------------------------------------------------

usbmParser::SyntaxContext::SyntaxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::SyntaxContext::SYNTAX() {
  return getToken(usbmParser::SYNTAX, 0);
}

usbmParser::StringContext* usbmParser::SyntaxContext::string() {
  return getRuleContext<usbmParser::StringContext>(0);
}


size_t usbmParser::SyntaxContext::getRuleIndex() const {
  return usbmParser::RuleSyntax;
}

void usbmParser::SyntaxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSyntax(this);
}

void usbmParser::SyntaxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSyntax(this);
}

usbmParser::SyntaxContext* usbmParser::syntax() {
  SyntaxContext *_localctx = _tracker.createInstance<SyntaxContext>(_ctx, getState());
  enterRule(_localctx, 12, usbmParser::RuleSyntax);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(usbmParser::SYNTAX);
    setState(80);
    string();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescriptionContext ------------------------------------------------------------------

usbmParser::DescriptionContext::DescriptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::DescriptionContext::DESCRIPTION() {
  return getToken(usbmParser::DESCRIPTION, 0);
}

std::vector<usbmParser::TextContext *> usbmParser::DescriptionContext::text() {
  return getRuleContexts<usbmParser::TextContext>();
}

usbmParser::TextContext* usbmParser::DescriptionContext::text(size_t i) {
  return getRuleContext<usbmParser::TextContext>(i);
}


size_t usbmParser::DescriptionContext::getRuleIndex() const {
  return usbmParser::RuleDescription;
}

void usbmParser::DescriptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescription(this);
}

void usbmParser::DescriptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescription(this);
}

usbmParser::DescriptionContext* usbmParser::description() {
  DescriptionContext *_localctx = _tracker.createInstance<DescriptionContext>(_ctx, getState());
  enterRule(_localctx, 14, usbmParser::RuleDescription);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(usbmParser::DESCRIPTION);
    setState(84); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(83);
      text();
      setState(86); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExampleContext ------------------------------------------------------------------

usbmParser::ExampleContext::ExampleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::ExampleContext::EXAMPLE() {
  return getToken(usbmParser::EXAMPLE, 0);
}

std::vector<usbmParser::TextContext *> usbmParser::ExampleContext::text() {
  return getRuleContexts<usbmParser::TextContext>();
}

usbmParser::TextContext* usbmParser::ExampleContext::text(size_t i) {
  return getRuleContext<usbmParser::TextContext>(i);
}

std::vector<usbmParser::ListingContext *> usbmParser::ExampleContext::listing() {
  return getRuleContexts<usbmParser::ListingContext>();
}

usbmParser::ListingContext* usbmParser::ExampleContext::listing(size_t i) {
  return getRuleContext<usbmParser::ListingContext>(i);
}


size_t usbmParser::ExampleContext::getRuleIndex() const {
  return usbmParser::RuleExample;
}

void usbmParser::ExampleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExample(this);
}

void usbmParser::ExampleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExample(this);
}

usbmParser::ExampleContext* usbmParser::example() {
  ExampleContext *_localctx = _tracker.createInstance<ExampleContext>(_ctx, getState());
  enterRule(_localctx, 16, usbmParser::RuleExample);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(usbmParser::EXAMPLE);
    setState(91); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(91);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case usbmParser::TEXT: {
          setState(89);
          text();
          break;
        }

        case usbmParser::CODE: {
          setState(90);
          listing();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(93); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::CODE

    || _la == usbmParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Kw_notesContext ------------------------------------------------------------------

usbmParser::Kw_notesContext::Kw_notesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

usbmParser::NoteContext* usbmParser::Kw_notesContext::note() {
  return getRuleContext<usbmParser::NoteContext>(0);
}

usbmParser::NotesContext* usbmParser::Kw_notesContext::notes() {
  return getRuleContext<usbmParser::NotesContext>(0);
}


size_t usbmParser::Kw_notesContext::getRuleIndex() const {
  return usbmParser::RuleKw_notes;
}

void usbmParser::Kw_notesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKw_notes(this);
}

void usbmParser::Kw_notesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKw_notes(this);
}

usbmParser::Kw_notesContext* usbmParser::kw_notes() {
  Kw_notesContext *_localctx = _tracker.createInstance<Kw_notesContext>(_ctx, getState());
  enterRule(_localctx, 18, usbmParser::RuleKw_notes);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case usbmParser::NOTE: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        note();
        break;
      }

      case usbmParser::NOTES: {
        enterOuterAlt(_localctx, 2);
        setState(96);
        notes();
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

//----------------- NoteContext ------------------------------------------------------------------

usbmParser::NoteContext::NoteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::NoteContext::NOTE() {
  return getToken(usbmParser::NOTE, 0);
}

std::vector<usbmParser::NotelistContext *> usbmParser::NoteContext::notelist() {
  return getRuleContexts<usbmParser::NotelistContext>();
}

usbmParser::NotelistContext* usbmParser::NoteContext::notelist(size_t i) {
  return getRuleContext<usbmParser::NotelistContext>(i);
}


size_t usbmParser::NoteContext::getRuleIndex() const {
  return usbmParser::RuleNote;
}

void usbmParser::NoteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNote(this);
}

void usbmParser::NoteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNote(this);
}

usbmParser::NoteContext* usbmParser::note() {
  NoteContext *_localctx = _tracker.createInstance<NoteContext>(_ctx, getState());
  enterRule(_localctx, 20, usbmParser::RuleNote);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(usbmParser::NOTE);
    setState(101); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(100);
      notelist();
      setState(103); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::CODE

    || _la == usbmParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotesContext ------------------------------------------------------------------

usbmParser::NotesContext::NotesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::NotesContext::NOTES() {
  return getToken(usbmParser::NOTES, 0);
}

std::vector<usbmParser::NoteheaderContext *> usbmParser::NotesContext::noteheader() {
  return getRuleContexts<usbmParser::NoteheaderContext>();
}

usbmParser::NoteheaderContext* usbmParser::NotesContext::noteheader(size_t i) {
  return getRuleContext<usbmParser::NoteheaderContext>(i);
}

std::vector<usbmParser::NotelistContext *> usbmParser::NotesContext::notelist() {
  return getRuleContexts<usbmParser::NotelistContext>();
}

usbmParser::NotelistContext* usbmParser::NotesContext::notelist(size_t i) {
  return getRuleContext<usbmParser::NotelistContext>(i);
}


size_t usbmParser::NotesContext::getRuleIndex() const {
  return usbmParser::RuleNotes;
}

void usbmParser::NotesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotes(this);
}

void usbmParser::NotesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotes(this);
}

usbmParser::NotesContext* usbmParser::notes() {
  NotesContext *_localctx = _tracker.createInstance<NotesContext>(_ctx, getState());
  enterRule(_localctx, 22, usbmParser::RuleNotes);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(usbmParser::NOTES);
    setState(112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(106);
      noteheader();
      setState(108); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(107);
        notelist();
        setState(110); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == usbmParser::CODE

      || _la == usbmParser::TEXT);
      setState(114); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == usbmParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoteheaderContext ------------------------------------------------------------------

usbmParser::NoteheaderContext::NoteheaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::NoteheaderContext::NUMBER() {
  return getToken(usbmParser::NUMBER, 0);
}


size_t usbmParser::NoteheaderContext::getRuleIndex() const {
  return usbmParser::RuleNoteheader;
}

void usbmParser::NoteheaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoteheader(this);
}

void usbmParser::NoteheaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoteheader(this);
}

usbmParser::NoteheaderContext* usbmParser::noteheader() {
  NoteheaderContext *_localctx = _tracker.createInstance<NoteheaderContext>(_ctx, getState());
  enterRule(_localctx, 24, usbmParser::RuleNoteheader);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(usbmParser::NUMBER);
    setState(117);
    match(usbmParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotelistContext ------------------------------------------------------------------

usbmParser::NotelistContext::NotelistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

usbmParser::TextContext* usbmParser::NotelistContext::text() {
  return getRuleContext<usbmParser::TextContext>(0);
}

usbmParser::ListingContext* usbmParser::NotelistContext::listing() {
  return getRuleContext<usbmParser::ListingContext>(0);
}


size_t usbmParser::NotelistContext::getRuleIndex() const {
  return usbmParser::RuleNotelist;
}

void usbmParser::NotelistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotelist(this);
}

void usbmParser::NotelistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotelist(this);
}

usbmParser::NotelistContext* usbmParser::notelist() {
  NotelistContext *_localctx = _tracker.createInstance<NotelistContext>(_ctx, getState());
  enterRule(_localctx, 26, usbmParser::RuleNotelist);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case usbmParser::TEXT: {
        setState(119);
        text();
        break;
      }

      case usbmParser::CODE: {
        setState(120);
        listing();
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

//----------------- ListingContext ------------------------------------------------------------------

usbmParser::ListingContext::ListingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::ListingContext::CODE() {
  return getToken(usbmParser::CODE, 0);
}

tree::TerminalNode* usbmParser::ListingContext::LISTING() {
  return getToken(usbmParser::LISTING, 0);
}


size_t usbmParser::ListingContext::getRuleIndex() const {
  return usbmParser::RuleListing;
}

void usbmParser::ListingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListing(this);
}

void usbmParser::ListingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListing(this);
}

usbmParser::ListingContext* usbmParser::listing() {
  ListingContext *_localctx = _tracker.createInstance<ListingContext>(_ctx, getState());
  enterRule(_localctx, 28, usbmParser::RuleListing);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(usbmParser::CODE);
    setState(124);
    match(usbmParser::LISTING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XrefContext ------------------------------------------------------------------

usbmParser::XrefContext::XrefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::XrefContext::XREF() {
  return getToken(usbmParser::XREF, 0);
}

std::vector<usbmParser::Title_idContext *> usbmParser::XrefContext::title_id() {
  return getRuleContexts<usbmParser::Title_idContext>();
}

usbmParser::Title_idContext* usbmParser::XrefContext::title_id(size_t i) {
  return getRuleContext<usbmParser::Title_idContext>(i);
}

std::vector<tree::TerminalNode *> usbmParser::XrefContext::KW_SEP() {
  return getTokens(usbmParser::KW_SEP);
}

tree::TerminalNode* usbmParser::XrefContext::KW_SEP(size_t i) {
  return getToken(usbmParser::KW_SEP, i);
}


size_t usbmParser::XrefContext::getRuleIndex() const {
  return usbmParser::RuleXref;
}

void usbmParser::XrefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXref(this);
}

void usbmParser::XrefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXref(this);
}

usbmParser::XrefContext* usbmParser::xref() {
  XrefContext *_localctx = _tracker.createInstance<XrefContext>(_ctx, getState());
  enterRule(_localctx, 30, usbmParser::RuleXref);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(usbmParser::XREF);
    setState(127);
    title_id();
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == usbmParser::KW_SEP) {
      setState(128);
      match(usbmParser::KW_SEP);
      setState(129);
      title_id();
      setState(134);
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

//----------------- StringContext ------------------------------------------------------------------

usbmParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::StringContext::SQ_STRING() {
  return getToken(usbmParser::SQ_STRING, 0);
}

tree::TerminalNode* usbmParser::StringContext::DQ_STRING() {
  return getToken(usbmParser::DQ_STRING, 0);
}


size_t usbmParser::StringContext::getRuleIndex() const {
  return usbmParser::RuleString;
}

void usbmParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void usbmParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

usbmParser::StringContext* usbmParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 32, usbmParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    _la = _input->LA(1);
    if (!(_la == usbmParser::DQ_STRING

    || _la == usbmParser::SQ_STRING)) {
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

//----------------- TextContext ------------------------------------------------------------------

usbmParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* usbmParser::TextContext::TEXT() {
  return getToken(usbmParser::TEXT, 0);
}


size_t usbmParser::TextContext::getRuleIndex() const {
  return usbmParser::RuleText;
}

void usbmParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}

void usbmParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<usbmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}

usbmParser::TextContext* usbmParser::text() {
  TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, getState());
  enterRule(_localctx, 34, usbmParser::RuleText);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(usbmParser::TEXT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> usbmParser::_decisionToDFA;
atn::PredictionContextCache usbmParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN usbmParser::_atn;
std::vector<uint16_t> usbmParser::_serializedATN;

std::vector<std::string> usbmParser::_ruleNames = {
  "file", "toolkit", "location", "keyword", "title", "title_id", "syntax", 
  "description", "example", "kw_notes", "note", "notes", "noteheader", "notelist", 
  "listing", "xref", "string", "text"
};

std::vector<std::string> usbmParser::_literalNames = {
  "", "':'", "", "", "", "", "", "", "", "", "", "", "", "", "", "'{{'", 
  "'}}'", "'(('", "'))'", "'<<'", "'>>'", "", "'[['", "']]'"
};

std::vector<std::string> usbmParser::_symbolicNames = {
  "", "", "TITLE", "TOOLKIT", "SYNTAX", "LOCATION", "DESCRIPTION", "KW", 
  "KEYWORD", "KW_SEP", "XREF", "EXAMPLE", "NOTE", "NOTES", "CODE", "OPEN_1", 
  "CLOSE_1", "OPEN_3", "CLOSE_3", "OPEN_4", "CLOSE_4", "TEXT", "OPEN_2", 
  "CLOSE_2", "LISTING", "DQ_STRING", "SQ_STRING", "COMMENT_SL", "COMMENT_ML", 
  "TITLE_ID", "NUMBER", "WS"
};

dfa::Vocabulary usbmParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> usbmParser::_tokenNames;

usbmParser::Initializer::Initializer() {
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
    0x3, 0x21, 0x8e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 
    0x2, 0x2a, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x2b, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x36, 
    0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x37, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3c, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3f, 0xb, 0x5, 0x3, 0x5, 0x7, 0x5, 0x42, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x45, 0xb, 0x5, 0x3, 0x5, 0x7, 0x5, 0x48, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4b, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x6, 0x9, 0x57, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x58, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x6, 0xa, 0x5e, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0x5f, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0x64, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 
    0x68, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0x69, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x6, 0xd, 0x6f, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x70, 0x6, 0xd, 0x73, 
    0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x74, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x7c, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x85, 0xa, 
    0x11, 0xc, 0x11, 0xe, 0x11, 0x88, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x2, 0x2, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x2, 0x4, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 0x1b, 0x1c, 0x2, 0x89, 
    0x2, 0x26, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x33, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x4f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x54, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x16, 0x65, 0x3, 0x2, 0x2, 0x2, 0x18, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x76, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x89, 0x3, 0x2, 0x2, 0x2, 0x24, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x27, 0x5, 0x4, 0x3, 0x2, 0x27, 0x29, 0x5, 0x6, 0x4, 0x2, 
    0x28, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 
    0x5, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0x22, 0x12, 0x2, 0x2f, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x7, 0x7, 0x2, 0x2, 0x31, 0x32, 0x5, 0x22, 0x12, 
    0x2, 0x32, 0x7, 0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x5, 0xa, 0x6, 0x2, 
    0x34, 0x36, 0x5, 0xe, 0x8, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3d, 0x5, 
    0x10, 0x9, 0x2, 0x3a, 0x3c, 0x5, 0x12, 0xa, 0x2, 0x3b, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 0x5, 0x14, 0xb, 0x2, 0x41, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x5, 0x20, 
    0x11, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4d, 0x9, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xc, 0x7, 0x2, 0x4e, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x1f, 0x2, 0x2, 0x50, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x6, 0x2, 0x2, 0x52, 0x53, 0x5, 0x22, 
    0x12, 0x2, 0x53, 0xf, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x7, 0x8, 0x2, 
    0x2, 0x55, 0x57, 0x5, 0x24, 0x13, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
    0x7, 0xd, 0x2, 0x2, 0x5b, 0x5e, 0x5, 0x24, 0x13, 0x2, 0x5c, 0x5e, 0x5, 
    0x1e, 0x10, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x64, 0x5, 0x16, 0xc, 0x2, 0x62, 0x64, 0x5, 0x18, 0xd, 0x2, 0x63, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x7, 0xe, 0x2, 0x2, 0x66, 0x68, 0x5, 
    0x1c, 0xf, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x72, 0x7, 0xf, 0x2, 0x2, 
    0x6c, 0x6e, 0x5, 0x1a, 0xe, 0x2, 0x6d, 0x6f, 0x5, 0x1c, 0xf, 0x2, 0x6e, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x19, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x20, 0x2, 0x2, 
    0x77, 0x78, 0x7, 0x3, 0x2, 0x2, 0x78, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7c, 0x5, 0x24, 0x13, 0x2, 0x7a, 0x7c, 0x5, 0x1e, 0x10, 0x2, 0x7b, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x10, 0x2, 0x2, 0x7e, 0x7f, 0x7, 
    0x1a, 0x2, 0x2, 0x7f, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0xc, 
    0x2, 0x2, 0x81, 0x86, 0x5, 0xc, 0x7, 0x2, 0x82, 0x83, 0x7, 0xb, 0x2, 
    0x2, 0x83, 0x85, 0x5, 0xc, 0x7, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x88, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 0x21, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x9, 0x3, 0x2, 0x2, 0x8a, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x17, 0x2, 0x2, 0x8c, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x2b, 0x37, 0x3d, 0x43, 0x49, 0x58, 0x5d, 0x5f, 0x63, 
    0x69, 0x70, 0x74, 0x7b, 0x86, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

usbmParser::Initializer usbmParser::_init;
