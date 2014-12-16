# FindHAL
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 

set(HAL_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(HAL_ARCH "arm")
endif()

# Create imported target HAL
add_library(HAL SHARED IMPORTED)

set_target_properties(HAL PROPERTIES
  COMPATIBLE_INTERFACE_STRING "HAL_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${WINDOWS_SOURCE_DIR}/lib/HAL/include"
  INTERFACE_HAL_MAJOR_VERSION "0"
#  INTERFACE_LINK_LIBRARIES "${WINDOWS_SOURCE_DIR}/lib/JavaScriptCore/${HAL_ARCH}/JavaScriptCore-$(Configuration).lib"
)

set_target_properties(HAL PROPERTIES
  IMPORTED_IMPLIB "${WINDOWS_SOURCE_DIR}/lib/HAL/${HAL_ARCH}/HAL.lib"
  IMPORTED_LOCATION "${WINDOWS_SOURCE_DIR}/lib/HAL/${HAL_ARCH}/HAL.dll"
  )
