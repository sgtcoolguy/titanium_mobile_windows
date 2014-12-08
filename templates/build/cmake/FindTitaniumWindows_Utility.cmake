# FindTitaniumWindows_Utility
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Utility. Once done this will define:
#  
#  TitaniumWindows_Utility_FOUND       - system has TitaniumWindows_Utility
#  TitaniumWindows_Utility_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Utility_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Utility_LIBRARIES   - link these to use TitaniumWindows_Utility

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Utility QUIET TitaniumWindows_Utility)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Utility_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Utility)

find_path(TitaniumWindows_Utility_INCLUDE_DIRS
  NAMES TitaniumWindows/Utility.hpp
  HINTS ${TitaniumWindows_Utility_HOME}/include ${PC_TitaniumWindows_Utility_INCLUDE_DIRS} ${PC_TitaniumWindows_Utility_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Utility_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Utility_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Utility_ARCH "arm")
endif()

find_library(TitaniumWindows_Utility_LIBRARIES
  NAMES TitaniumWindows_Utility
  HINTS ${TitaniumWindows_Utility_HOME}/${TitaniumWindows_Utility_ARCH} ${PC_TitaniumWindows_Utility_LIBRARY_DIRS} ${PC_TitaniumWindows_Utility_LIBDIR}
  PATHS ENV TitaniumWindows_Utility_HOME
  PATH_SUFFIXES ${TitaniumWindows_Utility_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Utility DEFAULT_MSG TitaniumWindows_Utility_INCLUDE_DIRS TitaniumWindows_Utility_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Utility_FOUND        = ${TitaniumWindows_Utility_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Utility_INCLUDE_DIRS = ${TitaniumWindows_Utility_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Utility_LIBRARY_DIR  = ${TitaniumWindows_Utility_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Utility_LIBRARIES    = ${TitaniumWindows_Utility_LIBRARIES}")
