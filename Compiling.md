# How to Compile USBMParser

These instructions are specific to Linux 64 bit systems. Currently (as of September 23rd 2018) the library files in the ``ANTLR4`` directory were built on a 64 bit Linux system, hence, that is what they are able to be used on.

However, as time passes, and I build some more library files, other systems will be able to build the application too.

You will sadly, require the Java Runtime to be available on your ``$PATH`` somewhere, but _only_ if you need to regenerate the grammar into C++ files.


## Do This Bit Once 

````
cd USBMParser
export CLASSPATH=`pwd`/ANTLR4/antlr-4.7.1-complete.jar
export LD_LIBRARY_PATH=`pwd`/ANTLR4/
alias antlr4="java org.antlr.v4.Tool"
````


## Generate C++ Files From the Grammar

Before you start, look in the ``generated_source`` directory. If there are files there, then skip this section and go straight to "Compiling" below. You only need this section if there are no files yet generated.

### Default - No Namespace.

````
antlr4 -Dlanguage=Cpp usbm.g4 -o generated_source
````

## Choose a Namespace

The default generation doesn't use a namespace in C++, however, if you wish to, you can generate the C++ files with namespace support. The command line to do this is as follows:

````
antlr4 -Dlanguage=Cpp usbm.g4 -o generated_source -package your_namespace
````

You will now also have to edit the file ``USBMParser.cpp`` and, look around line 20 for this code:

````
using namespace antlr4;
//using namespace your_namespace;
````

You will need to uncomment the second line and replace `your_namespace` with whatever you typed on the command line for the `package` parameter.



## Compiling

Compiling reequires a C++11 (or higher) C++ compiler. On Linux, `g++` will suffice. The following should be considered:

* There are include files in the `ANTLR4/include` directory that are required;
* There are include files in the `generated_source` directory that are also required.
* There are libraries in the `ANTLR4` directory to be used at link time;
* There are `*.cpp` files in the 1generated_source` directory which are required.

The command line to compile the application, with all these considerations is as follows. You can type it all on one line - don't include the back slashes - or _exactly_ as shown below with nothing at all after the '\' at the end of each line.

````
g++ USBMParser.cpp generated_source/*.cpp \
    -o USBMParser \
    -I ANTLR4/include \
    -I generated_source \
    -std=c++11 \
    -L ANTLR4 \
    -l antlr4-runtime
````

# Execution

Once compiled, you should have a file named `USBMParser` in the current directory.

The application creates its output files, one per keyword, in the current directory, so to avoid messing things up too much, the best course of action is:

````
cd output_files
#  rm *
../USBMParser ../Example_source.txt
````

When completed, you will see a number of files, some strangely named, in the `output_files` directory, or, wherever you happened to be when you executed the application.

Those are the ReStructuredText files (`*.rst`) which need to be used to update the Online SuperBASIC Manual - OSBM.

If you have a toolkit that you would like to see documented within the OSBM, then simply generated a source file, process it with OSBMParser, and zip up the resulting files and send them to Norm. Simple.



