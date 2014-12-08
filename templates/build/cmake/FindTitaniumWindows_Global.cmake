# FindTitaniumWindows_Global
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Global. Once done this will define:
#  
#  TitaniumWindows_Global_FOUND       - system has TitaniumWindows_Global
#  TitaniumWindows_Global_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Global_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Global_LIBRARIES   - link these to use TitaniumWindows_Global

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Global QUIET TitaniumWindows_Global)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Global_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Global)

find_path(TitaniumWindows_Global_INCLUDE_DIRS
  NAMES TitaniumWindows/GlobalObject.hpp
  HINTS ${TitaniumWindows_Global_HOME}/include ${PC_TitaniumWindows_Global_INCLUDE_DIRS} ${PC_TitaniumWindows_Global_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Global_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Global_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Global_ARCH "arm")
endif()

find_library(TitaniumWindows_Global_LIBRARIES
  NAMES TitaniumWindows_Global
  HINTS ${TitaniumWindows_Global_HOME}/${TitaniumWindows_Global_ARCH} ${PC_TitaniumWindows_Global_LIBRARY_DIRS} ${PC_TitaniumWindows_Global_LIBDIR}
  PATHS ENV TitaniumWindows_Global_HOME
  PATH_SUFFIXES ${TitaniumWindows_Global_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Global DEFAULT_MSG TitaniumWindows_Global_INCLUDE_DIRS TitaniumWindows_Global_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Global_FOUND        = ${TitaniumWindows_Global_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Global_INCLUDE_DIRS = ${TitaniumWindows_Global_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Global_LIBRARY_DIR  = ${TitaniumWindows_Global_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Global_LIBRARIES    = ${TitaniumWindows_Global_LIBRARIES}")
