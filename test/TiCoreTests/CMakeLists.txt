# Author: Matt Langston
# Date: 2014.09.20
cmake_minimum_required(VERSION 3.0.0)
project(TiCoreTests)

get_filename_component(TITANIUM_MOBILE_WINDOWS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../Source ABSOLUTE)

list(INSERT CMAKE_MODULE_PATH 0 ${TITANIUM_MOBILE_WINDOWS_SOURCE_DIR}/cmake)

# Define helper functions and macros.
include(${TITANIUM_MOBILE_WINDOWS_SOURCE_DIR}/cmake/internal_utils.cmake)

config_compiler_and_linker()  # Defined in internal_utils.cmake.

# Allow "make test" to work.
enable_testing()

find_package(JavaScriptCore REQUIRED)
add_definitions(-DSTATICALLY_LINKED_WITH_JavaScriptCore)

get_filename_component(TitaniumPedro_SOURCE_DIR ${TITANIUM_MOBILE_WINDOWS_SOURCE_DIR}/TitaniumPedro ABSOLUTE)

get_filename_component(TiCore2_SRC_DIR ${PROJECT_SOURCE_DIR}/../TiValue/TiValue ABSOLUTE)

get_filename_component(Util_SOURCE_DIR ${TITANIUM_MOBILE_WINDOWS_SOURCE_DIR}/Util ABSOLUTE)
add_subdirectory(${Util_SOURCE_DIR} ${CMAKE_BINARY_DIR}/Util)

include_directories(
  ${TitaniumPedro_SOURCE_DIR}
  ${TiCore2_SRC_DIR}
	${Util_SOURCE_DIR}/include
  ${JavaScriptCore_INCLUDE_DIRS}
	${GTEST_INCLUDE_DIRS}
  )

set(TiCore_SOURCES
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiRuntime.h
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiRuntime.cpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiRuntimeFunctions.h
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiRuntimeFunctions.cpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiValue.h
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiValue.cpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/ProxyCacheManager.hpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/ProxyCacheManager.cpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/BaseProxy.h
  ${TitaniumPedro_SOURCE_DIR}/TiCore/BaseProxy.cpp
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiProxy.h
  ${TitaniumPedro_SOURCE_DIR}/TiCore/TiProxy.cpp
  ${TiCore2_SRC_DIR}/ExampleProxy.h
  ${TiCore2_SRC_DIR}/ExampleProxy.cpp
  )

# Some of the following sources won't compile due to a MSVC compiler
# bug.
# if(NOT WIN32)
#   list(APPEND TiCore_SOURCES
#     ${TiCore2_SRC_DIR}/BaseProxy2.h
#     ${TiCore2_SRC_DIR}/BaseProxy2.cpp
#     ${TiCore2_SRC_DIR}/TiProxy2.h
#     ${TiCore2_SRC_DIR}/TiProxy2.cpp
#     ${TiCore2_SRC_DIR}/ExampleProxy2.h
#     ${TiCore2_SRC_DIR}/ExampleProxy2.cpp
#     )
# endif()

add_library(TiCore ${TiCore_SOURCES})

target_link_libraries(TiCore Util ${JavaScriptCore_LIBRARIES})

cxx_test(TiCoreTests . TiCore)
