# FindTitaniumWindows
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows. Once done this will define:
#  
#  TitaniumWindows_FOUND       - system has TitaniumWindows
#  TitaniumWindows_INCLUDE_DIRS - the include directory
#  TitaniumWindows_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_LIBRARIES   - link these to use TitaniumWindows

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows QUIET TitaniumWindows)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows)

find_path(TitaniumWindows_INCLUDE_DIRS
  NAMES TitaniumWindows.hpp
  HINTS ${TitaniumWindows_HOME}/include ${PC_TitaniumWindows_INCLUDE_DIRS} ${PC_TitaniumWindows_INCLUDEDIR}
  PATHS ENV TitaniumWindows_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_ARCH "arm")
endif()

find_library(TitaniumWindows_LIBRARIES
  NAMES TitaniumWindows
  HINTS ${TitaniumWindows_HOME}/${TitaniumWindows_ARCH} ${PC_TitaniumWindows_LIBRARY_DIRS} ${PC_TitaniumWindows_LIBDIR}
  PATHS ENV TitaniumWindows_HOME
  PATH_SUFFIXES ${TitaniumWindows_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows DEFAULT_MSG TitaniumWindows_INCLUDE_DIRS TitaniumWindows_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_FOUND        = ${TitaniumWindows_FOUND}")
# message(STATUS "MDL: TitaniumWindows_INCLUDE_DIRS = ${TitaniumWindows_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_LIBRARY_DIR  = ${TitaniumWindows_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_LIBRARIES    = ${TitaniumWindows_LIBRARIES}")
