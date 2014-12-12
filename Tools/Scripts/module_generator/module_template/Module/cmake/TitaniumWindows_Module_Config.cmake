# Titanium.{#Module#} for Windows
# Author: {#Author#}
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.

include(CMakeFindDependencyMacro)
find_dependency(TitaniumKit)

include("${CMAKE_BINARY_DIR}/TitaniumWindows_{#Module#}_Targets.cmake")
