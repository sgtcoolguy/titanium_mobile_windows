# FindTitaniumWindows_API
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_API. Once done this will define:
#  
#  TitaniumWindows_API_FOUND       - system has TitaniumWindows_API
#  TitaniumWindows_API_INCLUDE_DIRS - the include directory
#  TitaniumWindows_API_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_API_LIBRARIES   - link these to use TitaniumWindows_API

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_API QUIET TitaniumWindows_API)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_API_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_API)

find_path(TitaniumWindows_API_INCLUDE_DIRS
  NAMES TitaniumWindows/API.hpp
  HINTS ${TitaniumWindows_API_HOME}/include ${PC_TitaniumWindows_API_INCLUDE_DIRS} ${PC_TitaniumWindows_API_INCLUDEDIR}
  PATHS ENV TitaniumWindows_API_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_API_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_API_ARCH "arm")
endif()

find_library(TitaniumWindows_API_LIBRARIES
  NAMES TitaniumWindows_API
  HINTS ${TitaniumWindows_API_HOME}/${TitaniumWindows_API_ARCH} ${PC_TitaniumWindows_API_LIBRARY_DIRS} ${PC_TitaniumWindows_API_LIBDIR}
  PATHS ENV TitaniumWindows_API_HOME
  PATH_SUFFIXES ${TitaniumWindows_API_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_API DEFAULT_MSG TitaniumWindows_API_INCLUDE_DIRS TitaniumWindows_API_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_API_FOUND        = ${TitaniumWindows_API_FOUND}")
# message(STATUS "MDL: TitaniumWindows_API_INCLUDE_DIRS = ${TitaniumWindows_API_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_API_LIBRARY_DIR  = ${TitaniumWindows_API_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_API_LIBRARIES    = ${TitaniumWindows_API_LIBRARIES}")
