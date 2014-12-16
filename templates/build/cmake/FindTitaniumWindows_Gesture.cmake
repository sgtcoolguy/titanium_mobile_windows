# FindTitaniumWindows_Gesture
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Gesture. Once done this will define:
#  
#  TitaniumWindows_Gesture_FOUND       - system has TitaniumWindows_Gesture
#  TitaniumWindows_Gesture_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Gesture_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Gesture_LIBRARIES   - link these to use TitaniumWindows_Gesture

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Gesture QUIET TitaniumWindows_Gesture)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Gesture_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Gesture)

find_path(TitaniumWindows_Gesture_INCLUDE_DIRS
  NAMES TitaniumWindows/Gesture.hpp
  HINTS ${TitaniumWindows_Gesture_HOME}/include ${PC_TitaniumWindows_Gesture_INCLUDE_DIRS} ${PC_TitaniumWindows_Gesture_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Gesture_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Gesture_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Gesture_ARCH "arm")
endif()

find_library(TitaniumWindows_Gesture_LIBRARIES
  NAMES TitaniumWindows_Gesture
  HINTS ${TitaniumWindows_Gesture_HOME}/${TitaniumWindows_Gesture_ARCH} ${PC_TitaniumWindows_Gesture_LIBRARY_DIRS} ${PC_TitaniumWindows_Gesture_LIBDIR}
  PATHS ENV TitaniumWindows_Gesture_HOME
  PATH_SUFFIXES ${TitaniumWindows_Gesture_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Gesture DEFAULT_MSG TitaniumWindows_Gesture_INCLUDE_DIRS TitaniumWindows_Gesture_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Gesture_FOUND        = ${TitaniumWindows_Gesture_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Gesture_INCLUDE_DIRS = ${TitaniumWindows_Gesture_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Gesture_LIBRARY_DIR  = ${TitaniumWindows_Gesture_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Gesture_LIBRARIES    = ${TitaniumWindows_Gesture_LIBRARIES}")
