# JFC
Joe's Foundation Classes
Cross-platform class library

This project contains shared code that I've written and 
used in one or more of my projects.  It is perpetually
under construction, and probably shouldn't be used
by any sane individual.

Requirements
------------

    * Doxygen 1.8.0+ (for markdown support) and GraphViz.
    * GNU GCC toolchain
    * Git (obviously)
    * CPPUNIT (for unit tests)
    * Boost

Building and Installing
-----------------------

```bash
  $ mkdir build
  $ cd build
  $ cmake ..
  $ make
```

To make the doxygen documentation: 

```bash
  $ make doc
```

Running Unit Tests
------------------

This project contains some unit tests.  To execute, use the cmake
test harness.

```bash
  $ ctest -V
```

  
