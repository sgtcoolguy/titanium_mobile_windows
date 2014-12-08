# FindTitaniumWindows_Platform
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Platform. Once done this will define:
#  
#  TitaniumWindows_Platform_FOUND       - system has TitaniumWindows_Platform
#  TitaniumWindows_Platform_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Platform_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Platform_LIBRARIES   - link these to use TitaniumWindows_Platform

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Platform QUIET TitaniumWindows_Platform)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Platform_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Platform)

find_path(TitaniumWindows_Platform_INCLUDE_DIRS
  NAMES TitaniumWindows/Platform.hpp
  HINTS ${TitaniumWindows_Platform_HOME}/include ${PC_TitaniumWindows_Platform_INCLUDE_DIRS} ${PC_TitaniumWindows_Platform_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Platform_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Platform_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Platform_ARCH "arm")
endif()

find_library(TitaniumWindows_Platform_LIBRARIES
  NAMES TitaniumWindows_Platform
  HINTS ${TitaniumWindows_Platform_HOME}/${TitaniumWindows_Platform_ARCH} ${PC_TitaniumWindows_Platform_LIBRARY_DIRS} ${PC_TitaniumWindows_Platform_LIBDIR}
  PATHS ENV TitaniumWindows_Platform_HOME
  PATH_SUFFIXES ${TitaniumWindows_Platform_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Platform DEFAULT_MSG TitaniumWindows_Platform_INCLUDE_DIRS TitaniumWindows_Platform_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Platform_FOUND        = ${TitaniumWindows_Platform_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Platform_INCLUDE_DIRS = ${TitaniumWindows_Platform_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Platform_LIBRARY_DIR  = ${TitaniumWindows_Platform_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Platform_LIBRARIES    = ${TitaniumWindows_Platform_LIBRARIES}")
