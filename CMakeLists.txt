# Copyright 2015 Atria Dynamics LLC
#
# Written by Joe Turner <joe@atriadynamics.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##############################################################################

# Check to see if this is an out-of-source build or not
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    MESSAGE("           ____")
	MESSAGE("          (_oo_)          Something is wrong...")
	MESSAGE("           (O)")
	MESSAGE("          __||__    \\)    It looks like you are attempting")
	MESSAGE("       []/______\\[] /     to build in the root directory.")
	MESSAGE("       / \\______/ \\/")
	MESSAGE("      /    /__\\           Please don't.")
	MESSAGE("     (\\   /____\\")

	MESSAGE("Source directory = ${CMAKE_SOURCE_DIR}")
	MESSAGE("Binary directory = ${CMAKE_BINARY_DIR}")
    MESSAGE(FATAL_ERROR "Prevented in-tree built. This is bad practice.")	
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

##############################################################################
# Project Setup
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(atriacore)
ENABLE_LANGUAGE(CXX)
ENABLE_LANGUAGE(C)
ENABLE_TESTING()

#
# select the release build type by default to get optimization flags
#
IF(NOT CMAKE_BUILD_TYPE)	
   SET(CMAKE_BUILD_TYPE "Release")
   MESSAGE(STATUS "Build type not specified: defaulting to release.")
ENDIF(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

##############################################################################
# Find CppUnit
##############################################################################
INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(CPPUNIT "cppunit")
IF(NOT CPPUNIT_FOUND)
	FIND_PATH(CPPUNIT_INCLUDE_DIRS cppunit/TestCase.h
	  /usr/local/include
	  /usr/include
	)

	FIND_LIBRARY(CPPUNIT_LIBRARIES cppunit
	           ${CPPUNIT_INCLUDE_DIRS}/../lib
	           /usr/local/lib
	           /usr/lib)

	IF(CPPUNIT_INCLUDE_DIRS)
	  IF(CPPUNIT_LIBRARIES)
	    SET(CPPUNIT_FOUND "YES")
	    SET(CPPUNIT_LIBRARIES ${CPPUNIT_LIBRARIES} ${CMAKE_DL_LIBS})
	  ENDIF(CPPUNIT_LIBRARIES)
	ENDIF(CPPUNIT_INCLUDE_DIRS)

	INCLUDE(FindPackageHandleStandardArgs)
	FIND_PACKAGE_HANDLE_STANDARD_ARGS(CPPUNIT DEFAULT_MSG CPPUNIT_LIBRARIES CPPUNIT_INCLUDE_DIRS)
ENDIF(NOT CPPUNIT_FOUND)

IF(CPPUNIT_FOUND)
	MESSAGE("FOUND cppunit.")
ELSE()
	MESSAGE("CPPUNIT NOT FOUND.")
ENDIF(CPPUNIT_FOUND)


##############################################################################
# Doxygen
##############################################################################
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(doc
	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  	COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
endif(DOXYGEN_FOUND)


include_directories(${CMAKE_SOURCE_DIR}/include)

##############################################################################
# Add subdirectories
##############################################################################
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(unit-tests)

##############################################################################
# Print Summary
##############################################################################
MESSAGE(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "Building for version: ${VERSION}")



