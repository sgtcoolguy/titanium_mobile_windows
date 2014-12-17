# FindLayoutEngine
# Author: Chris Williams
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

# Author: Chris Williams
# Created: 2014.12.02 

set(LayoutEngine_ARCH "x86")
if(CMAKE_GENERATOR MATCHES "^Visual Studio .+ ARM$")
  set(LayoutEngine_ARCH "arm")
endif()

# Create imported target LayoutEngine
add_library(LayoutEngine STATIC IMPORTED)

set_target_properties(LayoutEngine PROPERTIES
  COMPATIBLE_INTERFACE_STRING "LayoutEngine_MAJOR_VERSION"
  INTERFACE_INCLUDE_DIRECTORIES "${WINDOWS_SOURCE_DIR}/lib/LayoutEngine/include"
  INTERFACE_LayoutEngine_MAJOR_VERSION "0"
)
set_target_properties(LayoutEngine PROPERTIES
  IMPORTED_IMPLIB "${WINDOWS_SOURCE_DIR}/lib/LayoutEngine/${LayoutEngine_ARCH}/LayoutEngine.lib"
  )
