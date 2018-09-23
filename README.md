# USBMParser
This is a ANTLR4 generated parser for a work in progress project to read in a text file describing the features of a QL Toolkit command, and from that, to generate the ReStructuredText source file for the Sphinx-doc build of the Online SuperBasic Manual (OSBM).

Building this code requires:

* ANTLR 4.7.1 or higher, parser generator jar file. 
* ANTLR 4.7.1 or higher, C++ Runtime library.
* Half a brain! 

The code reads in a single text file, and writes out, to the _current_ directory, one ``*.rst`` file for every keyword found in the source file. This makes life easier for the person doing the actual updating of the OSBM. (Oh! That would be me then! ;-) )

# Source File Format
It's a bit like a wiki, only (at least in the initial version) not a very good wiki! The following is a template file for a toolkit. I might explain it as we go along.

## File Header

The header of the file is as follows:

````
TOOLKIT: "Toolkit Name"
LOCATION: "What the Toolkit is known as in the QL world"
````

For example, a version 1.16 of the Dilwyn Jones Toolkit might be described as follows:
````
TOOLKIT: "DJToolkit version 1.16"
LOCATION "DJTK 1v16"
````

The location can be the same as the toolkit name, which is basically a descriptive comment, but the location specified will be used in all the keywords in the toolkit.

After the header, we have each keyword, as follows. There must be at least one keyword, but there is no limit to how many there can be - other than memory, file size limits etc.

## Keywords - Minimum Requirements

````
KEYWORD: keyword_name
SYNTAX: "How to call the keyword"
SYNTAX: "There may be multiple SYNTAX lines"
SYNTAX: "But one, at least, is required."
````

``KEYWORD`` can be abbreviated to ``KW``. As noted there can be more than one ``SYNTAX`` for the keywords. Again, there's no limits, within reason.

All keywords must have a ``KEYWORD`` or ``KW``, at least one ``SYNTAX`` and a ``DESCRIPTION`` as follows.

````
DESCRIPTION: {{
The description is a list of separate paragraphs, each wrapped in ``{{`` and ``}}`` - at least in this version.
}}

{{If you have more than one paragraph, they must each be similarly wrapped. Line
break
are
reformatted, so don't make any difference.}}

{{
Multiple spaces         ie, more than two consecutively
are also minimised into a single space.}}

````

The above is the minimum requirements. For example:

````
toolkit: "DJToolkit Version 1.16"
location: "DJTK 1v16"


kw: get_word%
syntax: "x% = get_word%(#channel)"
description:
{{
    Returns an integer read from the channel as the next two bytes in normal QL 'big-endian' format.
}}
````
This will generate the following ReStructuredText file, named ``get-word-pct.rst``:

````
..      _get-word-pct
get_word%
=========

+----------+--------------------------+
| Syntax   | x% = get_word%(#channel) |
+----------+--------------------------+
| Location | DJTK 1v16                |
+----------+--------------------------+

Returns an integer read from the channel as the next two bytes in normal QL 'big-endian' format.

````

## Keywords - Optional Extensions

If there needs to be more of a description, or examples and/or notes, then all of the following sections are optional, however, if they are supplied, they must be supplied in the following order:

* Example;
* Note or Notes;
* Cross Reference.

### Example

An example is one or more paragraphs of text, similar to that described above, but with the option to include source code examples too. As before, the text paragraphs are delimited as shown above, and example blocks must be entered as follows:

````
EXAMPLE:
{{
    This example shows a very silly, old style SuperBASIC program, much loved by school children 
    (and some adults too) when visiting computer shops in the 1980's:}}
    
CODE:[[
1000 REMark A line of code - this is a comment
1010 CLS
1020 PRINT "Hello World"
1030 GOTO 1020
]]

{{
  However, since the QL was invented, and SuperBasic came on the scene, the above should perhaps be rewritten as follows:
  }}
  
CODE:
[[
1000 REMark A line of code - this is a comment
1010 CLS
1020 REPeat silly
1020   PRINT "Hello World"
1030 END REPeat silly
]]

````

The above shows that the actual code lines are entered exactly as they are in a listing, but the whole listing is prefixed and suffixed by ``[[`` and ``]]``. The above example will append the following to the output file:

````
**Example**

This example shows a very silly, old style SuperBASIC program, much loved by school children (and some adults too) when visiting computer shops in the 1980's:

::

    1000 REMark A line of code - this is a comment
    1010 CLS
    1020 PRINT "Hello World"
    1030 GOTO 1020

However, since the QL was invented, and SuperBasic came on the scene, the above should perhaps be rewritten as follows:

::

    1000 REMark A line of code - this is a comment
    1010 CLS
    1020 REPeat silly
    1020   PRINT "Hello World"
    1030 END REPeat silly
````
You can have as many text and listing 'paragraphs' as you like. 

### Note or Notes

You can have a single ``NOTE`` or multiple ``NOTES`` in a source file.

#### Note

A note is one or more paragraphs, text and/or listings as shown above in the **Example** section. These paragraphs make up the one single note that is allowed in the source file, per keyword. If you need more than a single note, then you are advised to use ``NOTES`` below, instead.

A note is defined as follows:

````
NOTE:
{{One, or more, paragraphs of wrapped text.}}

{{Like these, or, you can intersperse listings too...}}

CODE:[[
1000 REMark This is a code listing paragraph.
1020 ...
]]

{{ And another paragraph of text.}}
````

The output from the above would be as follows:

````
**Note**
One, or more, paragraphs of wrapped text.

Like these, or, you can intersperse listings too...

::

    1000 REMark This is a code listing paragraph.
    1020 ...

And another paragraph of text.
````

#### Notes

Notes are exactly the same as the single ``NOTE`` above, except there can be more than one. Notes are numbered and as with a single note, can be made of of any number of text and/or listing paragraphs.

````
NOTES:
1: {{This is note 1. You are advised to read it.}}
2: {{Note two will appear after note 1.}}
666:{{You might think 666 is the number of the beast (but you are incorrect, that's actually 616), but it isn't, in the output file, notes number consecutively, from one, by one, so this is note three.}}
````

And the rather silly example above would render down to the following text in the output file:

````
**Note 1**
This is note 1. You are advised to read it.

**Note 2**
Note two will appear after note 1.

**Note 3**
You might think 666 is the number of the beast (but you are incorrect, that's actually 616), but it isn't, in the output file, notes number consecutively, from one, by one, so this is note three.
````

### Cross Reference

Finally, the cross reference section of the source file generates a list of other commands, which are related to the one under discussion. For example:

````
XREF: get_byte%, get_word%, get_float, get_string$
````

You can, if you wish, put each one on a separate line or mix and match as you please. The list must be separated by a comma and an optional space. There must be one cross referenced keyword if you have a cross reference section.

The code above would generate the correctly formatted ReStructuredText output as follows:

````
**CROSS-REFERENCE**

See also: :ref:`get-byte-pct`, :ref:`get-word-pct`, :ref:`get-float`, :ref:`get-string-dlr`.
````

## Points to Note

### Strings

In the above examples, strings are required in the ``TOOLKIT``, ``LOCATION`` and ``SYNTAX`` entries. Strings can be single or double quoted. If you need to enclose a single or double quote, within the quotes string, you can either:

* Double up the enclosed quote is it is the same as the outer quotes, for example ``"This is a double quote "" embedded in a double quotes string"``
* Preceed the embedded quote with a backslash - ``" This double quote \" has been escaped by a back slash."``

The same applies if you are using single quotes. The best method is to wrap strings with double quotes embedded, using single quotes, and vice versa.

### Keywords

You might have noticed above that the code generated by the ``XREF`` looks a little strange. The ReStructuredText source file requires that a link to another page or section, which is what each entry in the cross reference is, is generated as shown. The keyword names are therefore translated to a proper link label - which you can also see above each and every keyword in the output files. The translations required are:

* The whole keyword must be lower cased;
* Any underscores are replaced by a single hyphen;
* Any hyphens are replaced by two conscutive hyphens;
* Spaces are replaced by hyphens;
* Dollar and percent signs are illegal in links and link labels, so these are, lisk the USBM itself, converted to ``-dlr`` or ``-pct`` accordingly.

### Output Filenames

The output filenames are named after the massaged keyword, so the ``get_word%`` keyword's output file will be ``get-word-pct.rst`` and _not_ ``get_word%.rst``.
