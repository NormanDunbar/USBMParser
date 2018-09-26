grammar usbm ;

//--------------------------------------------------------------
// P A R S E R   R U L E S
//--------------------------------------------------------------

//--------------------------------------------------------------
// START RULE: File is where we would normally start parsing and
// it should start with a toolkit name and the location to be 
// used for all keywords in the toolkit.
//--------------------------------------------------------------
file        : toolkit 
              location 
              (keyword)+ 
            ;

//--------------------------------------------------------------
// Toolkit - just a descriptive name.
//--------------------------------------------------------------
toolkit     : TOOLKIT string ;

//--------------------------------------------------------------
// Location - just a descriptive name.
//--------------------------------------------------------------
location    : LOCATION string ;

//--------------------------------------------------------------
// Keywords, one per keyword, surprisingly. These are a title or
// name (ie, the actual keyword itself), followed by one or more
// syntax entries, a description, notes, examples and a cross-
// reference, all as appropriate. Only the title, at least one
// syntax and the description are mandatory. Regardless, any 
// entries that appear must be in the following order.
//--------------------------------------------------------------
keyword     : title 
              (syntax)+ 
              description
              (example)*
              (kw_notes)*
              (xref)*
            ;

//--------------------------------------------------------------
// Title is 'kw:' or 'keyword:' and the keyword name.
//--------------------------------------------------------------
title       : (KW | KEYWORD) 
              title_id 
            ;

title_id    : TITLE_ID ;

//--------------------------------------------------------------
// Each syntax entry is 'syntax:' and a string.
//--------------------------------------------------------------
syntax      : SYNTAX string ;

//--------------------------------------------------------------
// Description starts with 'description:' followed by free 
// format text. Text will have to be delimited though. There
// must be at least one text section though.
//--------------------------------------------------------------
description : DESCRIPTION 
              (text)+
            ;

//--------------------------------------------------------------
// Example starts with 'example:' followed by multiple free 
// format text or code listings. Text will have to be delimited
// though.
//--------------------------------------------------------------
example     : EXAMPLE
              (text | listing)+
            ;

//--------------------------------------------------------------
// Notes can be 'note:' and one note, or 'notes:' followed by a
// list of numbers, a colon, and the note itself. The notes are
// delimited text and/or listings.
//--------------------------------------------------------------
kw_notes    : note 
            | notes  
            ;
            
note        : NOTE
              (notelist)+
            ;

notes       : NOTES 
              (noteheader 
                (notelist)+
              )+
            ;

noteheader  : NUMBER ':' ;

notelist    : (text | listing)
            ;
         
         
//--------------------------------------------------------------
// Listings are delimited code lines.
//--------------------------------------------------------------
listing     : CODE
              LISTING
            ;              

//--------------------------------------------------------------
// The cross reference is 'xref:' followed by a list of one or 
// more keywords separated by comma (and optional space).
//--------------------------------------------------------------
xref        : XREF 
              title_id 
              (KW_SEP title_id)*
            ;

            
//--------------------------------------------------------------
// Strings are either single or double quote delimited.
//--------------------------------------------------------------
string      : SQ_STRING 
            | DQ_STRING 
            ;

//--------------------------------------------------------------
// Text is just a paragraph of text. I need this as a separate
// parser rule to make the parser write out text and listing in
// the corrrect order for Examples.
//--------------------------------------------------------------
text        : TEXT
            ;
//--------------------------------------------------------------
// L E X E R   R U L E S
//--------------------------------------------------------------

TITLE       : T I T L E ':' ;
TOOLKIT     : T O O L K I T ':' ;
SYNTAX      : S Y N T A X ':' ;
LOCATION    : L O C A T I O N ':' ;
DESCRIPTION : D E S C R I P T I O N ':' ;
KW          : K W ':' ;
KEYWORD     : K E Y W O R D ':' ;
KW_SEP      : ',' ' '? ;
XREF        : X R E F ':' ;
EXAMPLE     : E X A M P L E ':' ;
NOTE        : N O T E ':' ;
NOTES       : N O T E S ':' ;
CODE        : C O D E ':' ;


//--------------------------------------------------------------
// TEXT delimiters. 
// We need to delimit chunks of text and to do this we define an
// opening and closing delimiter, like strings. In this case it
// could be possible for the delimiter to appear in the text, so
// each chunk of text is delimited by one of a number of pairs
// of delimiters.
//--------------------------------------------------------------
OPEN_1      : '{{' ;
CLOSE_1     : '}}' ;
OPEN_3      : '((' ;
CLOSE_3     : '))' ;
OPEN_4      : '<<' ;
CLOSE_4     : '>>' ;


TEXT        : OPEN_1 (.)*? CLOSE_1
            | OPEN_3 (.)*? CLOSE_3 
            | OPEN_4 (.)*? CLOSE_4 
            ;

//--------------------------------------------------------------
// TEXT delimiters. 
// We need to delimit chunks of text and to do this we define an
// opening and closing delimiter, like strings. In this case it
// could be possible for the delimiter to appear in the text, so
// each chunk of text is delimited by one of a number of pairs
// of delimiters.
//--------------------------------------------------------------
OPEN_2      : '[[' ;
CLOSE_2     : ']]' ;

LISTING     : OPEN_2 (.)*? CLOSE_2 
            ;


//--------------------------------------------------------------
// STRINGS
//--------------------------------------------------------------
// These will have to be handled in the parser. As the
// escape character is retained. Escaping is by doubling
// up the quote that is embedded, or preceding it with
// a backslash.
//
// 'This ''works'' so does \'this\'.' 
// 'But this doesn''t work with different escapes of \' quotes.'
//
// CR/LF is not allowed in strings.
//--------------------------------------------------------------
DQ_STRING   : D_QUOTE (~[\r\n"] | '""')* D_QUOTE 
            | D_QUOTE (~[\r\n"] | '\\"')* D_QUOTE
            ;
            
SQ_STRING   : S_QUOTE (~[\r\n'] | '\'\'')* S_QUOTE 
            |  S_QUOTE (~[\r\n'] | '\\\'')* S_QUOTE 
            ;
            
//--------------------------------------------------------------
// COMMENTS
//--------------------------------------------------------------
// For single line comments, anything from the '#' to the end of
// the line is ignored.
// For multi-line comments, it's pretty much the same, anything
// between '/*' and '*/' is ignored.
//--------------------------------------------------------------
COMMENT_SL  : '#' ~('\n')*? '\n' -> skip;
COMMENT_ML  : '/*' .*? '*/' -> skip;


// These have to be at the end.
// Ids are a letter or underscore, any number of letters, digits or underscores
// and a final, optional percent or dollar.
TITLE_ID    : [A-Za-z_][A-Za-z0-9_]*[%$]? ;
NUMBER      : DIGIT (DIGIT)* ;

//--------------------------------------------------------------
// TEXT really stuffs things up, if it goes before 
// TITLE_ID, we get errors, likewise, after TITLE_ID. Sigh.
//
// BASICALLY, don't use it.
//--------------------------------------------------------------
//TEXT        : ~('\n')*? '\n';

WS          : [ \t\r\n]+ -> skip ;



// ----------
// Fragments.
// ----------

fragment
S_QUOTE     : '\'' ;

fragment
D_QUOTE     : '"' ;

fragment
A           : [Aa] ;
             
fragment    
B           : [Bb] ;
             
fragment    
C           : [Cc] ;
             
fragment    
D           : [Dd] ;
             
fragment    
E           : [Ee] ;
             
fragment    
F           : [Ff] ;
             
fragment    
G           : [Gg] ;
             
fragment    
H           : [Hh] ;
             
fragment    
I           : [Ii] ;
             
fragment    
J           : [Jj] ;
             
fragment    
K           : [Kk] ;
             
fragment    
L           : [Ll] ;
             
fragment    
M           : [Mm] ;
             
fragment    
N           : [Nn] ;
             
fragment    
O           : [Oo] ;
             
fragment    
P           : [Pp] ;
             
fragment    
Q           : [Qq] ;
             
fragment    
R           : [Rr] ;
             
fragment
S           : [Ss] ;
             
fragment    
T           : [Tt] ;
             
fragment    
U           : [Uu] ;
             
fragment    
V           : [Vv] ;
             
fragment    
W           : [Ww] ;
             
fragment    
X           : [Xx] ;
             
fragment    
Y           : [Yy] ;
             
fragment    
Z           : [Zz] ;
            
fragment    
DIGIT       : [0-9] ;
            
fragment    
LETTER      : [A-Za-z] ;
