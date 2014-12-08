# FindTitaniumWindows_Accelerometer
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 
#
# Try to find TitaniumWindows_Accelerometer. Once done this will define:
#  
#  TitaniumWindows_Accelerometer_FOUND       - system has TitaniumWindows_Accelerometer
#  TitaniumWindows_Accelerometer_INCLUDE_DIRS - the include directory
#  TitaniumWindows_Accelerometer_LIBRARY_DIR - the directory containing the library
#  TitaniumWindows_Accelerometer_LIBRARIES   - link these to use TitaniumWindows_Accelerometer

find_package(PkgConfig)

pkg_check_modules(PC_TitaniumWindows_Accelerometer QUIET TitaniumWindows_Accelerometer)

# Point to lib bundled in Titanium SDK
set(TitaniumWindows_Accelerometer_HOME ${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Accelerometer)

find_path(TitaniumWindows_Accelerometer_INCLUDE_DIRS
  NAMES TitaniumWindows/Accelerometer.hpp
  HINTS ${TitaniumWindows_Accelerometer_HOME}/include ${PC_TitaniumWindows_Accelerometer_INCLUDE_DIRS} ${PC_TitaniumWindows_Accelerometer_INCLUDEDIR}
  PATHS ENV TitaniumWindows_Accelerometer_HOME
  PATH_SUFFIXES include
  )

set(TitaniumWindows_Accelerometer_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Accelerometer_ARCH "arm")
endif()

find_library(TitaniumWindows_Accelerometer_LIBRARIES
  NAMES TitaniumWindows_Accelerometer
  HINTS ${TitaniumWindows_Accelerometer_HOME}/${TitaniumWindows_Accelerometer_ARCH} ${PC_TitaniumWindows_Accelerometer_LIBRARY_DIRS} ${PC_TitaniumWindows_Accelerometer_LIBDIR}
  PATHS ENV TitaniumWindows_Accelerometer_HOME
  PATH_SUFFIXES ${TitaniumWindows_Accelerometer_ARCH}
  )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(TitaniumWindows_Accelerometer DEFAULT_MSG TitaniumWindows_Accelerometer_INCLUDE_DIRS TitaniumWindows_Accelerometer_LIBRARIES)

# message(STATUS "MDL: CMAKE_CONFIGURATION_TYPES   = ${CMAKE_CONFIGURATION_TYPES}")
# message(STATUS "MDL: TitaniumWindows_Accelerometer_FOUND        = ${TitaniumWindows_Accelerometer_FOUND}")
# message(STATUS "MDL: TitaniumWindows_Accelerometer_INCLUDE_DIRS = ${TitaniumWindows_Accelerometer_INCLUDE_DIRS}")
# message(STATUS "MDL: TitaniumWindows_Accelerometer_LIBRARY_DIR  = ${TitaniumWindows_Accelerometer_LIBRARY_DIR}")
# message(STATUS "MDL: TitaniumWindows_Accelerometer_LIBRARIES    = ${TitaniumWindows_Accelerometer_LIBRARIES}")
