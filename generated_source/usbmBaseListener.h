
// Generated from usbm.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "usbmListener.h"


/**
 * This class provides an empty implementation of usbmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  usbmBaseListener : public usbmListener {
public:

  virtual void enterFile(usbmParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(usbmParser::FileContext * /*ctx*/) override { }

  virtual void enterToolkit(usbmParser::ToolkitContext * /*ctx*/) override { }
  virtual void exitToolkit(usbmParser::ToolkitContext * /*ctx*/) override { }

  virtual void enterLocation(usbmParser::LocationContext * /*ctx*/) override { }
  virtual void exitLocation(usbmParser::LocationContext * /*ctx*/) override { }

  virtual void enterKeyword(usbmParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(usbmParser::KeywordContext * /*ctx*/) override { }

  virtual void enterTitle(usbmParser::TitleContext * /*ctx*/) override { }
  virtual void exitTitle(usbmParser::TitleContext * /*ctx*/) override { }

  virtual void enterTitle_id(usbmParser::Title_idContext * /*ctx*/) override { }
  virtual void exitTitle_id(usbmParser::Title_idContext * /*ctx*/) override { }

  virtual void enterSyntax(usbmParser::SyntaxContext * /*ctx*/) override { }
  virtual void exitSyntax(usbmParser::SyntaxContext * /*ctx*/) override { }

  virtual void enterDescription(usbmParser::DescriptionContext * /*ctx*/) override { }
  virtual void exitDescription(usbmParser::DescriptionContext * /*ctx*/) override { }

  virtual void enterExample(usbmParser::ExampleContext * /*ctx*/) override { }
  virtual void exitExample(usbmParser::ExampleContext * /*ctx*/) override { }

  virtual void enterKw_notes(usbmParser::Kw_notesContext * /*ctx*/) override { }
  virtual void exitKw_notes(usbmParser::Kw_notesContext * /*ctx*/) override { }

  virtual void enterNote(usbmParser::NoteContext * /*ctx*/) override { }
  virtual void exitNote(usbmParser::NoteContext * /*ctx*/) override { }

  virtual void enterNotes(usbmParser::NotesContext * /*ctx*/) override { }
  virtual void exitNotes(usbmParser::NotesContext * /*ctx*/) override { }

  virtual void enterNoteheader(usbmParser::NoteheaderContext * /*ctx*/) override { }
  virtual void exitNoteheader(usbmParser::NoteheaderContext * /*ctx*/) override { }

  virtual void enterNotelist(usbmParser::NotelistContext * /*ctx*/) override { }
  virtual void exitNotelist(usbmParser::NotelistContext * /*ctx*/) override { }

  virtual void enterListing(usbmParser::ListingContext * /*ctx*/) override { }
  virtual void exitListing(usbmParser::ListingContext * /*ctx*/) override { }

  virtual void enterXref(usbmParser::XrefContext * /*ctx*/) override { }
  virtual void exitXref(usbmParser::XrefContext * /*ctx*/) override { }

  virtual void enterString(usbmParser::StringContext * /*ctx*/) override { }
  virtual void exitString(usbmParser::StringContext * /*ctx*/) override { }

  virtual void enterText(usbmParser::TextContext * /*ctx*/) override { }
  virtual void exitText(usbmParser::TextContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

