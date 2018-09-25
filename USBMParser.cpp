#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

// Don't forget to change this each time. :o)
#define USBM_VERSION 0.02

// Temporary working filename for the output
// until we work out the sanitised keyword name.
#define TEMPFILE "Test_file.rst"


#include "antlr4-runtime.h"
#include "usbmLexer.h"
#include "usbmParser.h"
#include "usbmBaseListener.h"

using namespace antlr4;
//using namespace your_namespace;

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::transform;
using std::vector;


class myListener : public usbmBaseListener {
private:

// Stores the current toolkit name.
string toolkitName;

// Stores the global location for all keywords in a toolkit.
string locationName;
size_t locationLength;

// Storage for all the various syntax sentences.
vector<string> syntaxList;
size_t syntaxMaxLength = 0;

// Running counter for multiple notes.
size_t currentNote = 1;

// Running counter for cross reference lists.
size_t xrefCounter = 0;

// Sanitised Keyword name.
string keywordFile;



// Output file.
// A new file is created for each keyword. So it's best we run this
// in a blank "toolkit" directory, to avoid polluting the current one.
ofstream *tkFile;


public:

    //-------------------------------------------------------------------------
    //                                                                     FILE
    //-------------------------------------------------------------------------
    void enterFile(usbmParser::FileContext  *ctx) override {
        // Just write a comment to the screen.

        cout << endl << "USBMParser, version " << USBM_VERSION << endl
             << "SuperBASIC Online Manual Updater" << endl
             << "by Norman Dunbar." << endl << endl;
    }


    
    //-------------------------------------------------------------------------
    //                                                                  TOOLKIT
    //-------------------------------------------------------------------------
    void enterToolkit(usbmParser::ToolkitContext  *ctx) override { 
        // Extract the toolkit name and print it.

        toolkitName = ctx->string()->getText();

        // Trim off quotes.
        toolkitName.erase(0, 1);
        toolkitName.erase(toolkitName.length() -1, 1);

        // Write it out as a comment to the screen.
        cout << "Processing toolkit: " << toolkitName << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                 LOCATION
    //-------------------------------------------------------------------------
    void enterLocation(usbmParser::LocationContext  *ctx) override {
        // Here, grab, and save the location.

        locationName = ctx->string()->getText();

        // Remove leading quote.
        locationName.erase(0, 1);
        locationLength = locationName.length();

        // And the trailing quote.
        locationName.erase(locationLength -1, 1);
        --locationLength;
        
        cout << "All keywords located at: " << locationName << endl << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                  KEYWORD
    //-------------------------------------------------------------------------
    void enterKeyword(usbmParser::KeywordContext *ctx) override {
	    // When entering the keyword rule, create a file for this 
        // particular keyword.We don't have the sanitised name yet
        // so use a temporary file and rename it in exitKeyword().

        string keywordName = ctx->title()->title_id()->TITLE_ID()->getText();
        cout << endl << "Keyword: " << keywordName << endl;

        tkFile = new ofstream(TEMPFILE, std::ofstream::out);
        if (!tkFile->good()) {
            cerr << "Failed creating " << TEMPFILE << ", cannot continue." << endl;
            exit;
        } else {
            cout << TEMPFILE << " opened ok." << endl;
        }

        *tkFile << "..\tFile created by USBM version " << USBM_VERSION << endl
                << "..\tWritten by Norman Dunbar." << endl << endl
                << "..\tToolkit: " << toolkitName << endl
                << "..\tLocation: " << locationName << endl << endl;

        // Clear out previous syntaxes, ready for the 
        // next keyword. Ditto the note counter.
        syntaxList.clear();
        syntaxMaxLength = 0;
        currentNote = 1;
    }



    //-------------------------------------------------------------------------
    //                                                                  KEYWORD
    //-------------------------------------------------------------------------
    void exitKeyword(usbmParser::KeywordContext *ctx) override {
	    // Do something when leaving the keyword rule.

        // Throw a few lines to finish the file.
        *tkFile << endl << endl;
        cout << endl;

        // Close the current file.
        tkFile->close();

        // We also now have the sanitised name, so rename the file.
        // Delete it first, as some operating systems (Hello Windows) will
        // error out if the file exists. (Ignore removal errors.)
        int errorCode = std::remove((keywordFile + ".rst").c_str());
        errorCode = std::rename(TEMPFILE, (keywordFile + ".rst").c_str());
        if (errorCode) {
            cerr << "Cannot rename " 
                 << TEMPFILE << " to " 
                 << keywordFile << ".rst. Error code: " 
                 << errorCode 
                 << endl;
        }
    }



    //-------------------------------------------------------------------------
    //                                                                  LISTING
    //-------------------------------------------------------------------------
    void enterListing(usbmParser::ListingContext  *ctx) override { 
	    // Do something when entering the listing rule.

        cout << "Listing...";

        // The code header first.
        *tkFile << "::" << endl << endl;

        // The whole code section is wrapped in '[[' and ']]'
        string thisListing = ctx->LISTING()->getText();
        thisListing.erase(0, 2);

        // Lose any leading linefeeds. With carriage returns too.
        char c = thisListing[0];
        while (c == '\r' || c == '\n') {

            // Carriage return?
            if (c == '\r') {
                thisListing.erase(0,1);
            }

            // Line feed?
            if (c == '\n') {
                thisListing.erase(0, 1);
            }

            // What next?
            c = thisListing[0];
        }
            

        string::size_type listingLength = thisListing.length() - 2;
        thisListing = thisListing.substr(0, listingLength);

        // Replace all linefeeds with with a tab afterwards.
        string::size_type lfPos = -1;
        while (true) {
            lfPos = thisListing.find('\n', lfPos +1);
            if (lfPos == string::npos) {
                break;
            }

            thisListing.insert(lfPos + 1, 1, '\t');
        }

        // Write it out.
        *tkFile << '\t' << thisListing << endl << endl;       
    };



    //-------------------------------------------------------------------------
    //                                                                 TITLE_ID
    //-------------------------------------------------------------------------
    void enterTitle_id(usbmParser::Title_idContext  *ctx) override {
        // TITLE_IDs are used in a few places. 
        //
        // Keywords:
        //    Convert to a label for a reference;
        //    Print the label with leading underscore, trailing colon;
        //    Print a blank line;
        //    Print the title;
        //    Underline it.
        //
        // XREF:
        //    Convert to a label for a reference;
        //    Print a comma, if necessary, and the label.

        // Extract the keyword.
        string keywordName = ctx->TITLE_ID()->getText();
        string labelText = keywordName;

        // Convert to lower case first.
        transform(labelText.begin(), labelText.end(), labelText.begin(), ::tolower);
        
        // Replace underscores with hyphens.
        for (auto x = labelText.begin(); x != labelText.end(); x++) {
            if (*x == '_') {
                *x = '-';
            }
        }
        
        // Replace spaces with two hyphens.
        // But there are no spaces in keyword names!

        // Replace percent with -pct.
        // Replace dollar with -dlr.
        string::size_type lastIndex = keywordName.length() -1;
        char lastChar = keywordName[lastIndex];

        switch (lastChar) {
            case '%': 
                labelText[lastIndex] = '-';
                labelText += "pct";
                break;

            case '$': 
                labelText[lastIndex] = '-';
                labelText += "dlr";
                break;
        }

        // At this point we have both the keyword as presented and
        // a label for use as an anchor and for links to said anchor.
        // If this is a title_id rule from a keyword, we need to do one
        // thing, and if from a cross reference, we do another. 
        // Read on. :o)

        // Find the parent rule for this rule.
        // For some reason, although a ParserRuleContext has getParent()
        // the compiler says "no"!. That's Java for you. However, in C++
        // there's a 'parent' field in the context. It just needs casting.

        string underLine(keywordName.length(), '=');

        ParserRuleContext *parentCtx = reinterpret_cast<ParserRuleContext *>(ctx->parent);
        
        int parentRuleIndex = -1;
        if (parentCtx) {
            parentRuleIndex = parentCtx->getRuleIndex();
        };
        
        switch (parentRuleIndex) {
            case usbmParser::RuleTitle:
                // Handle keyword title (aka name).
                // Write out the label & blank line
                *tkFile << "..\t_"<<labelText << ':' << endl << endl; 

                // Write out the actual keyword.
                *tkFile << keywordName << endl;

                // Underline the keyword.
                *tkFile << underLine << endl << endl;

                // Save the label, no leading underscore, as
                // the sanitised file name.
                keywordFile = labelText;
                break;

            case usbmParser::RuleXref:
                // Handle Xrefs.

                // Print a comma if this is not the first xref.
                if (xrefCounter) {
                    *tkFile << ", ";
                }
                xrefCounter++;

                // Then the link text.
                *tkFile << ":ref:`" << labelText << '`';
                break;
        }
        
    }


    
    //-------------------------------------------------------------------------
    //                                                                   SYNTAX
    //-------------------------------------------------------------------------
    void enterSyntax(usbmParser::SyntaxContext  *ctx) override {

        cout << "Syntax...";
        cout.flush();

        // Grab the current syntax.
        string thisSyntax = ctx->string()->getText();

        // Remove leading quote.
        thisSyntax.erase(0, 1);

        // Grab the length & trim the trailing quote.
        string::size_type syntaxLength = thisSyntax.length();
        thisSyntax.erase(syntaxLength -1, 1);
        --syntaxLength;

        // If bigger, save in the syntaxMaxLength.
        if (syntaxLength > syntaxMaxLength) {
            syntaxMaxLength = syntaxLength;
        }

        // Save this syntax in the list.
        syntaxList.push_back(thisSyntax);
    }



    //-------------------------------------------------------------------------
    //                                                              DESCRIPTION
    //-------------------------------------------------------------------------
    void enterDescription(usbmParser::DescriptionContext  *ctx) override { 
        // There must be a description, so, when we enter its
        // rule, we now have all the syntaxes that were supplied
        // and the location, so we can build the table for those
        // First of all.
        //
        // +----------+-----+
        // | Syntax   | ... |
        // +----------+-----+
        // | Location | ... |
        // +----------+-----+
        //
        // or
        //
        // +----------+------+
        // | Syntax   || ... |
        // |          || ... |
        // +----------+------+
        // | Location | ...  |
        // +----------+------+
        //

        cout << "Description...";
        cout.flush();

        // Is the last cell width the locationLength or the syntaxMaxLength?
        string::size_type cellWidth = (locationLength > syntaxMaxLength ? locationLength : syntaxMaxLength);

        // Do we have more than one syntax?
        string::size_type syntaxCount = syntaxList.size();
        size_t extraCount = (syntaxCount > 1 ? 1 : 0);

        // Build '----' string for table separators.
        string dashes(cellWidth + 2 + extraCount, '-');

        // Build the padding for the syntax and location cell entries.
        string spaces(cellWidth + 2 + extraCount, ' ');

        // Do the syntaxes first. 
        // We have a set of dashes first.
        *tkFile << "+----------+" << dashes << '+' << endl;
        
        // For the first syntax, we need 'Syntax'.
        string syntaxTitle = "| Syntax   |";
        for (auto x = syntaxList.begin(); x != syntaxList.end(); x++) {
            *tkFile << syntaxTitle;
            syntaxTitle = "|          |";
            
            // Extra '|' if required.
            if (extraCount) {
                *tkFile << '|';
            }

            // Now the syntax and padding.
            *tkFile << ' ' << *x 
                    << spaces.substr(0, cellWidth - (*x).length()) 
                    << " |" << endl;
        }

        // Then close the syntax row, ready for location.
        *tkFile << "+----------+" << dashes << '+' << endl;  
        
        // Add location next.
        *tkFile << "| Location | " << locationName 
                << spaces.substr(0, cellWidth - locationLength);

            // Extra space required?
            if (extraCount) {
                *tkFile << ' ';
            }

            *tkFile << " | " << endl;

        // Then close the location row.
        *tkFile << "+----------+" << dashes << '+' << endl << endl; 

        // And now, the description will follow in the enterText
        // and enterListing functions, in order, as necessary.
      
    }



    //-------------------------------------------------------------------------
    //                                                              DESCRIPTION
    //-------------------------------------------------------------------------
    void exitDescription(usbmParser::DescriptionContext  *ctx) override {
        // Because we have so much cr4p going on on entry
        // to a description (see above) it's easier to put
        // the description stuff on exit from parsing it.

        *tkFile << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                  EXAMPLE
    //-------------------------------------------------------------------------
    void enterExample(usbmParser::ExampleContext  *ctx) override { 
        // Because the example section has both code and text
        // parts, the actual content of the example section consists
        // of the heading only. The code and/or text sections will
        // be processed elsewhere in enterText() and/or enterListing().

        cout << "Example...";
        cout.flush();

        *tkFile << "**Example**" << endl << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                     NOTE
    //-------------------------------------------------------------------------
    void enterNote(usbmParser::NoteContext  *ctx) override {
        // For one NOTE, just do the heading.

        cout << "Note...";
        cout.flush();

        *tkFile << "**Note**" << endl << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                    NOTES
    //-------------------------------------------------------------------------
    void enterNotes(usbmParser::NotesContext  *ctx) override {
        // For Notes, we need to keep a, ahem, note of the number.

        cout << "Notes...";
        cout.flush();
    }



    //-------------------------------------------------------------------------
    //                                                               NOTEHEADER
    //-------------------------------------------------------------------------
    void enterNoteheader(usbmParser::NoteheaderContext  *ctx) override {
        // For note headers, we need to keep a, ahem, note of the number.

        cout << "Noteheader...";
        cout.flush();

        *tkFile << "**Note " 
                << currentNote++
                << "**" << endl << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                 NOTELIST
    //-------------------------------------------------------------------------
    void enterNotelist(usbmParser::NotelistContext  *ctx) override {
        // For notelists, we need to keep a, ahem, note of the number.

        cout << "Notelist...";
        cout.flush();
    }



    //-------------------------------------------------------------------------
    //                                                                     XREF
    //-------------------------------------------------------------------------
    void enterXref(usbmParser::XrefContext  *ctx) override {
        // For Cross References, just do the title and a quick
        // 'See also:' text. Zero the count of items in the
        // cross reference list.

        xrefCounter = 0;

        cout << "Cross Reference...";
        cout.flush();

        // Each xref is a title_id rule, so that gets processed
        // somewhere else. (EnterTitle_id() probably!)
        *tkFile << "**CROSS-REFERENCE**" << endl
                << endl << "See also: ";
    }

    //-------------------------------------------------------------------------
    //                                                                     XREF
    //-------------------------------------------------------------------------
    void exitXref(usbmParser::XrefContext  *ctx) override {
        // For Cross References, we just close the list with a 
        // full stop and a new line.

        *tkFile << '.' << endl;
    }



    //-------------------------------------------------------------------------
    //                                                                     TEXT
    //-------------------------------------------------------------------------
    void enterText(usbmParser::TextContext *ctx) override {
        // Process one text paragraph.

        cout << "Text...";
        cout.flush();

        string thisText = ctx->TEXT()->getText();
        thisText.erase(0, 2);
        string::size_type textLength = thisText.length() -2;
        thisText.erase(textLength, 2);

        // The text must start in the first column, so
        // trim off any leading tabs etc.
        thisText = thisText.substr(thisText.find_first_not_of(" \t\r\n")); 

        // Strip out the tab/cr/lf characters replacing with space.
        for (auto x = thisText.begin(); x != thisText.end(); x++) {
            switch (*x) {
                case '\n':
                case '\r':
                case '\t': 
                    *x = ' ';
                    break;                    
            }
        }

        // Remove all double spaces.
        string::size_type spacePos = 0;
        while (true) {
            spacePos = thisText.find("  ", spacePos);
            if (spacePos == string::npos) {
                break;
            }

            thisText.erase(spacePos, 1);            
        }

        // Finally, write the text. Each text is a paragraph.
        *tkFile << thisText << endl << endl;
    }

};      // End of class.



//=============================================================================
//                                                                         MAIN
//=============================================================================
int main(int argc, const char* argv[]) {

    // Open input file from command line.
    ifstream stream;
    stream.open(argv[1]);

    // Convert for ANTLR4.
    ANTLRInputStream input(stream);
    
    // We need a lexer to tokenise the input file.
    usbmLexer lexer(&input);

    // Grab the lexer's tokens.
    CommonTokenStream tokens(&lexer);

    // We now need a parser to parse those tokens into a parse tree.
    usbmParser parser(&tokens);

    // Grab the parse tree, top rule is to be 'file'.
    tree::ParseTree *tree = parser.file();

    // Now, create the listener we will use when walking the tree.
    myListener listener;

    // And walk the tree, calling the listener for every rule.
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return 0;
}
