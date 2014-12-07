# Util
# Author: Matthew D. Langston
#
# Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.
cmake_minimum_required(VERSION 3.0.0)

project(Util)

set(Util_VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

option(Util_DISABLE_TESTS "Disable compiling the tests" OFF)

# Define helper functions and macros.
include(${PROJECT_SOURCE_DIR}/cmake/internal_utils.cmake)

# Defined in internal_utils.cmake.
config_compiler_and_linker()
#config_cmake_system_framework_path(macosx)

# Allow "make test" to work.
enable_testing()

# We have a custom finder for JavaScriptCoreCPP.
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
find_package(JavaScriptCore REQUIRED)

set(SOURCE_Util
  include/Util/JSObjectRefRAII.hpp
  src/JSObjectRefRAII.cpp
  include/Util/Statistics.hpp
  src/Statistics.cpp
  include/Util/OutputDebugStringBuf.hpp
  include/Util/virtual_enable_shared_from_this_base.hpp
  )

source_group(Util FILES ${SOURCE_Util})

include_directories(
  ${JavaScriptCore_INCLUDE_DIRS}
  )

add_library(Util
  ${SOURCE_Util}
  )

include(GenerateExportHeader)
generate_export_header(Util)
#target_compile_definitions(Util PRIVATE Util_EXPORTS)
target_compile_definitions(Util PUBLIC UTIL_STATIC_DEFINE)

target_compile_definitions(Util PRIVATE STATICALLY_LINKED_WITH_JavaScriptCore)
target_include_directories(Util PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${JavaScriptCore_INCLUDE_DIRS}
  )

target_link_libraries(Util
  ${JavaScriptCore_LIBRARIES}
  )

if (NOT Util_DISABLE_TESTS)
  add_subdirectory(test)
endif()

set_property(TARGET Util PROPERTY VERSION ${Util_VERSION})
set_property(TARGET Util PROPERTY SOVERSION 0)
set_property(TARGET Util PROPERTY INTERFACE_Util_MAJOR_VERSION 0)
set_property(TARGET Util APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING Util_MAJOR_VERSION
  )

install(TARGETS Util EXPORT UtilTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
  )

export(EXPORT UtilTargets
  FILE "${CMAKE_BINARY_DIR}/UtilTargets.cmake"
)

configure_file(cmake/UtilConfig.cmake
  "${CMAKE_BINARY_DIR}/UtilConfig.cmake"
  COPY_ONLY
  )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/UtilConfigVersion.cmake"
  VERSION ${Util_VERSION}
  COMPATIBILITY AnyNewerVersion
  )

# Store the current build directory in the CMake user package registry
# so that find_package(Util) works.
export(PACKAGE Util)
