# FindTitaniumWindows_Utils
# Author: Chris Williams
#
# Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2015.03.17

if(${CMAKE_SYSTEM_NAME} STREQUAL "WindowsPhone")
  set(PLATFORM wp)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "WindowsStore")
  set(PLATFORM store)
else()
  message(FATAL_ERROR "This app supports Store / Phone only.")
endif()

set(TitaniumWindows_Utils_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(TitaniumWindows_Utils_ARCH "arm")
endif()

# Taken and slightly modified from bUtilsld's TitaniumWindows_Utils_Targets.cmake file
# INTERFACE_INCLUDE_DIRECTORIES is modified to point to our pre-packaged include dir for module

# Create imported target TitaniumWindows_Utils
add_library(TitaniumWindows_Utils SHARED IMPORTED)

set_target_properties(TitaniumWindows_Utils PROPERTIES
  COMPATIBLE_INTERFACE_STRING "TitaniumWindows_Utils_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Utils/include;$<TARGET_PROPERTY:TitaniumKit,INTERFACE_INCLUDE_DIRECTORIES>;$<TARGET_PROPERTY:TitaniumWindows_Utility,INTERFACE_INCLUDE_DIRECTORIES>"
  INTERFACE_LINK_LIBRARIES "TitaniumKit;TitaniumWindows_Utility"
  INTERFACE_TitaniumWindows_Utils_MAJOR_VERSION "0"
)

set_target_properties(TitaniumWindows_Utils PROPERTIES
  IMPORTED_IMPLIB "${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Util/${PLATFORM}/${TitaniumWindows_Utils_ARCH}/TitaniumWindows_Utils.lib"
  IMPORTED_LOCATION "${WINDOWS_SOURCE_DIR}/lib/TitaniumWindows_Utils/${PLATFORM}/${TitaniumWindows_Utils_ARCH}/TitaniumWindows_Utils.dll"
  )
