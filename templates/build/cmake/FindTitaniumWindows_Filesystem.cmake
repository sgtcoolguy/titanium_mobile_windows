# FindTitaniumWindows_Filesystem
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Filesystem. Once done this will define:
#  
#  TitaniumWindows_Filesystem_FOUND       - system has TitaniumWindows_Filesystem
#  TitaniumWindows_Filesystem_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Filesystem_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Filesystem_LIBRARIES   - link these to use TitaniumWindows_Filesystem

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Filesystem QUIET TitaniumWindows_Filesystem)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Filesystem_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Filesystem)

find_path(TitaniumWindows_Filesystem_INCLUDE_DIRS
  NAMES TitaniumWindows/Filesystem.hpp
  HINTS ${TitaniumWindows_Filesystem_HOME}/include ${PC_TitaniumWindows_Filesystem_INCLUDE_DIRS} ${PC_TitaniumWindows_Filesystem_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Filesystem_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Filesystem_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Filesystem_ARCH "arm")
endif()

find_library(TitaniumWindows_Filesystem_LIBRARIES
  NAMES TitaniumWindows_Filesystem
  HINTS ${TitaniumWindows_Filesystem_HOME}/${TitaniumWindows_Filesystem_ARCH} ${PC_TitaniumWindows_Filesystem_LIBRARY_DIRS} ${PC_TitaniumWindows_Filesystem_LIBDIR}
  PATHS ENV TitaniumWindows_Filesystem_HOME
  PATH_SUFFIXES ${TitaniumWindows_Filesystem_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Filesystem DEFAULT_MSG TitaniumWindows_Filesystem_INCLUDE_DIRS TitaniumWindows_Filesystem_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Filesystem_FOUND        = ${TitaniumWindows_Filesystem_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Filesystem_INCLUDE_DIRS = ${TitaniumWindows_Filesystem_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Filesystem_LIBRARY_DIR  = ${TitaniumWindows_Filesystem_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Filesystem_LIBRARIES    = ${TitaniumWindows_Filesystem_LIBRARIES}")
