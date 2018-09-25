# How to Compile USBMParser

These instructions are specific to Windows & Linux, 64 bit systems. Currently (as of September 23rd 2018) the library files in the ``ANTLR4`` directory were built on 64 bit Linux and 64bit Windows 7 systems, hence, those are what they are able to be used on.

The runtime libraries were built on Linux with g++ 5.1 and on WIndows with the TDM version of g++ 5.1 for Windows. (From http://tdm-gcc.tdragon.net/download).

You will sadly, require the Java Runtime to be available on your ``$PATH`` somewhere, but _only_ if you need to regenerate the grammar into C++ files.



## Do This Bit Once 

### On Linux 64bit

````
cd USBMParser
export CLASSPATH=`pwd`/ANTLR4/antlr-4.7.1-complete.jar
export LD_LIBRARY_PATH=`pwd`/ANTLR4/
alias antlr4="java org.antlr.v4.Tool"
````

### On Linux 32bit

````
cd USBMParser
export CLASSPATH=`pwd`/ANTLR4/antlr-4.7.1-complete.jar
export LD_LIBRARY_PATH=`pwd`/ANTLR4/Linux32
alias antlr4="java org.antlr.v4.Tool"
````

### On Windows 64bit

````
cd USBMParser
set CLASSPATH="path\to\ANTLR4\antlr-4.7.1-complete.jar"
set PATH=%PATH%;"path\to\ANTLR4\Win64"
````

### On Windows 32bit

````
cd USBMParser
set CLASSPATH="path\to\ANTLR4\antlr-4.7.1-complete.jar"
set PATH=%PATH%;"path\to\ANTLR4\Win32"
````

## Generate C++ Files From the Grammar

_Before you start_, look in the ``generated_source`` directory. If there _are_ files there, then skip this section and go straight to "Compiling" below. You only need this section if there are no files yet generated. The files you should fine will have extensions of `interp`, `tokens`, `h` and `cpp`.


### Linux - Default - No Namespace.

````
antlr4 -Dlanguage=Cpp usbm.g4 -o generated_source
````

**Note**: In the above 'language' and 'Cpp' are case dependent, anything other than the exact letter case shown above will cause errors.


### Windows - Default - No Namespace.

````
java org.antlr.v4.Tool -Dlanguage=Cpp usbm.g4 -o generated_source
````

**Note**: In the above 'language' and 'Cpp' are case dependent, anything other than the exact letter case shown above will cause errors.


### Linux - Choose a Namespace

The default generation doesn't use a namespace in C++, however, if you wish to, you can generate the C++ files with namespace support. The command line to do this is as follows:

````
antlr4 -Dlanguage=Cpp usbm.g4 -o generated_source -package your_namespace
````

### Windows - Default - No Namespace.

````
java org.antlr.v4.Tool -Dlanguage=Cpp usbm.g4 -o generated_source -package your_namespace
````

### Both - Edit Main File

If you generated a namespace, then you will now also have to edit the file ``USBMParser.cpp``. Look around line 20 for this code:

````
using namespace antlr4;
//using namespace your_namespace;
````

You will need to uncomment the second line and replace `your_namespace` with whatever you typed on the command line for the `package` parameter.



## Compiling

Compiling reequires a C++11 (or higher) C++ compiler. On Linux, `g++` will suffice, on WIndows, it's also best to use g++, see the top of this document for details of where it can be downloaded. 

The following should be considered:

* There are include files in the `ANTLR4/include` directory that are required;
* There are include files in the `generated_source` directory that are also required.
* There are libraries in the `ANTLR4` directory to be used at link time;
* There are `*.cpp` files in the 1generated_source` directory which are required.

### Compiling On Linux 64bit

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

### Compiling On Linux 32bit

The command line to compile the application, with all these considerations, on 32bit Linux systems is as follows. You can type it all on one line - don't include the back slashes - or _exactly_ as shown below with nothing at all after the '\' at the end of each line.

````
g++ USBMParser.cpp generated_source/*.cpp \
    -o USBMParser \
    -I ANTLR4/include \
    -I generated_source \
    -std=c++11 \
    -L ANTLR4/Linux32 \
    -l antlr4-runtime
````
### Compiling On Windows 64bit

Windows doesn't like commands spreading over multiple lines, so everything that follows is on one single solitary lonesome line by itself. It also doesn't appear to like wildcards in the source file names, so prepare to type!

````
g++ USBMParser.cpp generated_source/usbmLexer.cpp generated_source/usbmListener.cpp generated_source/usbmBaseListener.cpp  generated_source/usbmParser.cpp -I ANTLR4\include -I generated_source -std=c++11 -L ANTLR4\Win64 -l antlr4-runtime -Wno-attributes -o USBMParse.exe
````

You will see a few warnings like these:

````
ANTLR4\include/antlr4-common.h:81:31: warning: declaration 'class std::exception ' does not declare anything
   class ANTLR4CPP_PUBLIC std::exception; // Needed for VS 2015.
````

These are caused by the code being massaged for older versions of Visual Studio and can be ignored when compiling with g++. (Or, forward declarations of classes in header files give spurious warnings!)


# Execution

Once compiled, you should have a file named `USBMParser` in the current directory.

The application creates its output files, one per keyword, in the current directory, so to avoid messing things up too much, the best course of action is:

````
cd output_files
#  rm *
../USBMParser ../Example_source.txt
````

On Windows, if you get an error about a missing `libantlr4-runtime.dll` then you didn't add the `ANTLR4\Win64` folder to your `%PATH%`. If you did, and still get the error, copy the file named `libantlr4-runtime.dll` from the `ANTLR4\Win64` folder to the location of the `USBMParser.exe` file. Windows is weird!

When execution has completed, you will see a number of files, some strangely named, in the `output_files` directory, or, wherever you happened to be when you executed the application.

Those are the ReStructuredText files (`*.rst`) which need to be used to update the Online SuperBASIC Manual - OSBM.

If you have a toolkit that you would like to see documented within the OSBM, then simply generated a source file, process it with OSBMParser, and zip up the resulting files and send them to Norm. Simple.



