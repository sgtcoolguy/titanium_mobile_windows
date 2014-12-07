# Author: Matt Langston
# Date: 2013.02.17
cmake_minimum_required(VERSION 3.0.0)
project(gtest_example)

get_filename_component(APPCELERATOR_CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../../Source/cmake ABSOLUTE)
list(INSERT CMAKE_MODULE_PATH 0 ${APPCELERATOR_CMAKE_MODULE_PATH})

# Define helper functions and macros.
include(${CMAKE_MODULE_PATH}/internal_utils.cmake)

config_compiler_and_linker()  # Defined in internal_utils.cmake.

# Allow "make test" to work.
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
