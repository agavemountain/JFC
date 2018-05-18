#ifndef _JFC_H_
#define _JFC_H_

/*! \mainpage

 \section intro Introduction

 Welcome to Joe's Foundation Class Library.  This is a C++ library
 that contains classes, templates, design patterns and idioms that are being merged
 from other projects, for better reuse.

 Please note, that in almost every case there are better options such as
 boost, pico, and a slew of other, better maintained libraries.  Almost all
 of the code here came from various constraints such as legacy compiler versions,
 wierd computer architectures, or other constraints that you probably don't have.

  \section Categories
 Click on the link(s) below on the description of some of the code:

 - \ref designpatterns


 \tableofcontents

 \section Requirements

 - Doxygen 1.8.0+ (for markdown support) and GraphViz.
 - GNU GCC toolchain
 - Git (obviously)
 - CPPUNIT (for unit tests)

\section make Building and Installing


 \code
 $ mkdir build
 $ cmake ..
 $ make; make install
 \endcode

 \section Generating Documentation

 This project uses doxygen to generate the documentation.  To generate
 this documentation, you must have doxygen installed.  Simple execute doxygen:
 \code
 $ make doc
 \endcode

 \section Running Unit Tests

 You can run unit tests (if cppunit is installed on your development workstation):

 \code
 $ ctest -V
 \endcode

*/






#endif

