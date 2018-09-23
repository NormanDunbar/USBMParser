
// Generated from usbm.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "usbmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by usbmParser.
 */
class  usbmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(usbmParser::FileContext *ctx) = 0;
  virtual void exitFile(usbmParser::FileContext *ctx) = 0;

  virtual void enterToolkit(usbmParser::ToolkitContext *ctx) = 0;
  virtual void exitToolkit(usbmParser::ToolkitContext *ctx) = 0;

  virtual void enterLocation(usbmParser::LocationContext *ctx) = 0;
  virtual void exitLocation(usbmParser::LocationContext *ctx) = 0;

  virtual void enterKeyword(usbmParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(usbmParser::KeywordContext *ctx) = 0;

  virtual void enterTitle(usbmParser::TitleContext *ctx) = 0;
  virtual void exitTitle(usbmParser::TitleContext *ctx) = 0;

  virtual void enterTitle_id(usbmParser::Title_idContext *ctx) = 0;
  virtual void exitTitle_id(usbmParser::Title_idContext *ctx) = 0;

  virtual void enterSyntax(usbmParser::SyntaxContext *ctx) = 0;
  virtual void exitSyntax(usbmParser::SyntaxContext *ctx) = 0;

  virtual void enterDescription(usbmParser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(usbmParser::DescriptionContext *ctx) = 0;

  virtual void enterExample(usbmParser::ExampleContext *ctx) = 0;
  virtual void exitExample(usbmParser::ExampleContext *ctx) = 0;

  virtual void enterKw_notes(usbmParser::Kw_notesContext *ctx) = 0;
  virtual void exitKw_notes(usbmParser::Kw_notesContext *ctx) = 0;

  virtual void enterNote(usbmParser::NoteContext *ctx) = 0;
  virtual void exitNote(usbmParser::NoteContext *ctx) = 0;

  virtual void enterNotes(usbmParser::NotesContext *ctx) = 0;
  virtual void exitNotes(usbmParser::NotesContext *ctx) = 0;

  virtual void enterNoteheader(usbmParser::NoteheaderContext *ctx) = 0;
  virtual void exitNoteheader(usbmParser::NoteheaderContext *ctx) = 0;

  virtual void enterNotelist(usbmParser::NotelistContext *ctx) = 0;
  virtual void exitNotelist(usbmParser::NotelistContext *ctx) = 0;

  virtual void enterListing(usbmParser::ListingContext *ctx) = 0;
  virtual void exitListing(usbmParser::ListingContext *ctx) = 0;

  virtual void enterXref(usbmParser::XrefContext *ctx) = 0;
  virtual void exitXref(usbmParser::XrefContext *ctx) = 0;

  virtual void enterString(usbmParser::StringContext *ctx) = 0;
  virtual void exitString(usbmParser::StringContext *ctx) = 0;

  virtual void enterText(usbmParser::TextContext *ctx) = 0;
  virtual void exitText(usbmParser::TextContext *ctx) = 0;


};

