# USBM Grammar & Source Files

The USBMParser was generated from a grammar file, `usbm.g4` which describes how the source file should look and if it doesn't look correct, the parser will complain.

You can have a look in the `usbm.g4` file to see the actual grammar, and there's an example file `Example_source.txt` in the same directory, which can be used for testing.

The content of the latter file will resemble the following:

````
toolkit: "DJToolkit 1.16"
location: "DJToolkit 1.16"


kw: get_word%
syntax: "x% = get_word%(#channel)"
description:
{{
    Returns an integer read from the channel as the next two bytes.
}}



kw: b_get$
syntax: "x% = b_get$(#channel)"
description:
{{
    Returns a string read from the channel as the next two bytes
    which determine the length, followed by that number of bytes.
}}{{
    If you want to, you can have multiple paragraphs in here
    but, they must be separated.
}}



kw: CLS
syntax: "CLS #channel"
syntax: 'CLS #channel, part'
description: 
{{This is a description of the CLS command.}}
{{The command can be used to, clear the whole screen, clear the line that the cursor is on, clear the screen above the cursor line or clear the screen below the cursor line.}}
{{It's very, very, useful as a command for, ahem, clearing the screen!}}

example:
{{This example shows how to clear the whole screen:}}
code: [[cls]]
notes:
1:{{
CLS cannot be used to clear non display channels.

Doing so would be a tad interesting, if you ask me!
}}

{{This, for example, would not work:}}

code: [[
1000 OPEN #3, "flp1_boot"
1010 CLS #3
1020 ...
]]

666: ((The number of the beast!))
667:<<The neighbour of the beast :-)>>
xref: CLEAR_SCREEN

keyword: STOP
syntax: "STOP"
description:
<<
This is a description.
>>
xref: FRED$, BARNEY%, WIL_MA, BET_TY

/*
 * This is a 
 * multi-line
 * comment
 */
 
kw: PRINT
syntax: "PRINT [#channel][!,;/] [print list] [!,;/]"
description:((
This is a description.
))
example:
{{This example shows how to print an integer variable:}}
code: [[PRINT intVariable%]]

{{This example shows a useless SuperBASIC program with CLS used too:}}
code: [[
1000 something$ = "Hello World!"
1010 cls
1020 print something$
1030 goto 1020
]]
xref: PRINT_USING,LPRINT,LLIST


 
kw: PRINT2
syntax: "PRINT2 something"
description:<<
This is another flipping description.>>
note: {{
This is a free
format
text note for the PRINT2 command.
}}

````

Admittedly, it's not pretty and as new versions of `USBMParser` appear, it _should_ get easier and less cluttered. That's the hope anyway.

Having said that, it's a damned sight easier to run the `USBMParser` against a file like that, than to have to install python, sphinx-doc, latex and all the rest, just to be able to update the Online SuperBASIC manual (OSBM).

Hopefully you agree?


Cheers,
Norm.
