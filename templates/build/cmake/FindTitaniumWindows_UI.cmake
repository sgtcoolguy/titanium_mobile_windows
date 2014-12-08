# FindTitaniumWindows_UI
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_UI. Once done this will define:
#  
#  TitaniumWindows_UI_FOUND       - system has TitaniumWindows_UI
#  TitaniumWindows_UI_INCLUDE_DIRS - the include directory
#  TitaniumWindows_UI_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_UI_LIBRARIES   - link these to use TitaniumWindows_UI

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_UI QUIET TitaniumWindows_UI)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_UI_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_UI)

find_path(TitaniumWindows_UI_INCLUDE_DIRS
  NAMES TitaniumWindows/UI.hpp
  HINTS ${TitaniumWindows_UI_HOME}/include ${PC_TitaniumWindows_UI_INCLUDE_DIRS} ${PC_TitaniumWindows_UI_INCLUDEDIR}
  PATHS ENV TitaniumWindows_UI_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_UI_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_UI_ARCH "arm")
endif()

find_library(TitaniumWindows_UI_LIBRARIES
  NAMES TitaniumWindows_UI
  HINTS ${TitaniumWindows_UI_HOME}/${TitaniumWindows_UI_ARCH} ${PC_TitaniumWindows_UI_LIBRARY_DIRS} ${PC_TitaniumWindows_UI_LIBDIR}
  PATHS ENV TitaniumWindows_UI_HOME
  PATH_SUFFIXES ${TitaniumWindows_UI_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_UI DEFAULT_MSG TitaniumWindows_UI_INCLUDE_DIRS TitaniumWindows_UI_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_UI_FOUND        = ${TitaniumWindows_UI_FOUND}")
# message(STATUS "MDL: TitaniumWindows_UI_INCLUDE_DIRS = ${TitaniumWindows_UI_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_UI_LIBRARY_DIR  = ${TitaniumWindows_UI_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_UI_LIBRARIES    = ${TitaniumWindows_UI_LIBRARIES}")
