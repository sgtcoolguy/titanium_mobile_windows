# JavaScriptCoreWRT
#
# Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
# Licensed under the terms of the Apache Public License.
# Please see the LICENSE included with this distribution for details.
cmake_minimum_required(VERSION 3.0.0)

project(JavaScriptCoreWRT)

set(JavaScriptCoreWRT_VERSION 0.5.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

option(JavaScriptCoreWRT_DISABLE_TESTS "Disable compiling the tests" OFF)

# Define helper functions and macros.
include(${PROJECT_SOURCE_DIR}/cmake/internal_utils.cmake)

# Target architecture, only available for iOS
set(ARCH "i386" CACHE STRING "Target Architecture")

# Target platform, only available on Xcode
# "macosx", "iphoneos" or "iphonesimulator"
set(PLATFORM "macosx" CACHE STRING "Target Platform")

# Build shared library by default
set(LIBRARY_BUILD_TYPE SHARED)

# Defined in internal_utils.cmake.
config_compiler_and_linker()

# Allow "make test" to work.
enable_testing()

# We have a custom finder for JavaScriptCoreWRT.
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
find_package(JavaScriptCore REQUIRED)

set(SOURCE_JavaScriptCoreWRT
  include/JS.h
  src/JS.cpp
  )

source_group(JavaScriptCoreWRT                   FILES ${SOURCE_JavaScriptCoreWRT})

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(JavaScriptCoreWRT ${LIBRARY_BUILD_TYPE}
  ${SOURCE_JavaScriptCoreWRT}
  )

include(GenerateExportHeader)
generate_export_header(JavaScriptCoreWRT)
target_compile_definitions(JavaScriptCoreWRT PRIVATE JavaScriptCoreWRT_EXPORTS)

target_compile_definitions(JavaScriptCoreWRT PRIVATE STATICALLY_LINKED_WITH_JavaScriptCore)
target_include_directories(JavaScriptCoreWRT PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${JavaScriptCore_INCLUDE_DIRS}
  )

target_link_libraries(JavaScriptCoreWRT
  ${JavaScriptCore_LIBRARIES}
  )

set_target_properties(JavaScriptCoreWRT PROPERTIES VS_WINRT_COMPONENT TRUE)

if (WIN32)
  # Silence this warning when lnking with the JavaScriptCore static
  # library:
  #
  # "warning LNK4099: PDB 'vc120.pdb' was not found with
  # 'JavaScriptCore-Debug.lib(...)' ...".
  set_property(TARGET JavaScriptCoreWRT APPEND PROPERTY LINK_FLAGS "/IGNORE:4099")
  
  # Silence this warning when lnking with the JavaScriptCore static
  # library for the i386 emulator:
  #
  # "JavaScriptCore-Debug.lib(JSStringRef.obj) : warning LNK4075:
  # ignoring '/EDITANDCONTINUE' due to '/SAFESEH' specification".
  #
  # According to "/IGNORE (Ignore Specific Warnings)" (see
  # http://msdn.microsoft.com/en-us/library/dn782850.aspx) some linker
  # warnings cannot be ignored and LNK4075 is one of them. However,
  # according to "/SAFESEH (Image has Safe Exception Handlers)" (see
  # http://msdn.microsoft.com/en-us/library/9a89h429.aspx):
  #
  # "/SAFESEH is only valid when linking for x86 targets."
  #
  # Therefore we test for the processor architecture we are targeting
  # and if its i386 (i.e. the emulator) then we pass /SAFESEH:NO to
  # the linker.
  include(${PROJECT_SOURCE_DIR}/cmake/TargetArch.cmake)
  target_architecture(target_architecture)
  if (${target_architecture} STREQUAL i386)
    set_property(TARGET JavaScriptCoreWRT APPEND_STRING PROPERTY LINK_FLAGS " /SAFESEH:NO")
  endif()

  # Silence this warning when lnking the Debug configuration:
  #
  # "LINK : warning LNK4075: ignoring '/INCREMENTAL' due to '/OPT:ICF'
  # specification ..."
  #
  # According to "/IGNORE (Ignore Specific Warnings)" (see
  # http://msdn.microsoft.com/en-us/library/dn782850.aspx) some linker
  # warnings cannot be ignored and LNK4075 is one of them. However,
  # according to "/INCREMENTAL (Link Incrementally)" (see
  # http://msdn.microsoft.com/en-us/library/4khtbfyf.aspx):
  #
  # "Most programs can be linked incrementally. However, some changes
  # are too great, and some options are incompatible with incremental
  # linking. LINK performs a full link if any of the following options
  # are specified:
  # ...
  # /OPT:REF is selected
  # /OPT:ICF is selected
  # ..."
  #
  # And according to "/OPT (Optimizations)" (see
  # http://msdn.microsoft.com/en-us/library/bxwfs976.aspx):
  #
  # "If /DEBUG is specified, the default for /OPT is NOREF, and all
  # functions are preserved in the image."
  #
  # As well as:
  #
  # "... we do not recommend that you use /OPT:ICF in debug builds ..."
  #
  # Therefore we disable /OPT:REF and /OPT:ICF for the Debug
  # configuration.
  set_property(TARGET JavaScriptCoreWRT APPEND_STRING PROPERTY LINK_FLAGS_DEBUG "/OPT:NOREF /OPT:NOICF")

  # When building against Release version of JSC, we see a warning from the linker:
  # JavaScriptCore-Release.lib(JSStringRef.obj) : MSIL .netmodule or module compiled with /GL found; restarting link # with /LTCG; add /LTCG to the link command line to improve linker performance
  #
  # Hence we'll turn on LTCG for release builds of JavaScriptCoreWRT...
  set_property(TARGET JavaScriptCoreWRT APPEND_STRING PROPERTY LINK_FLAGS_RELEASE "/LTCG")
endif()

if (NOT JavaScriptCoreWRT_DISABLE_TESTS)
  add_subdirectory(examples)
  add_subdirectory(test)
endif()

# Support find_package(JavaScriptCoreWRT 0.5 REQUIRED)

set_property(TARGET JavaScriptCoreWRT PROPERTY VERSION ${JavaScriptCoreWRT_VERSION})
set_property(TARGET JavaScriptCoreWRT PROPERTY SOVERSION 0)
set_property(TARGET JavaScriptCoreWRT PROPERTY INTERFACE_JavaScriptCoreWRT_MAJOR_VERSION 0)
set_property(TARGET JavaScriptCoreWRT APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING JavaScriptCoreWRT_MAJOR_VERSION
  )

install(TARGETS JavaScriptCoreWRT EXPORT JavaScriptCoreWRTTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
  )

export(EXPORT JavaScriptCoreWRTTargets
  FILE "${CMAKE_BINARY_DIR}/JavaScriptCoreWRTTargets.cmake"
)

configure_file(cmake/JavaScriptCoreWRTConfig.cmake
  "${CMAKE_BINARY_DIR}/JavaScriptCoreWRTConfig.cmake"
  COPYONLY
  )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/JavaScriptCoreWRTConfigVersion.cmake"
  VERSION ${JavaScriptCoreWRT_VERSION}
  COMPATIBILITY AnyNewerVersion
  )

# Store the current build directory in the CMake user package registry
# so that find_package(JavaScriptCoreWRT) works.
export(PACKAGE JavaScriptCoreWRT)

#[[
# TODO: Install files to external locations.

set(ConfigPackageLocation lib/cmake/JavaScriptCoreWRT)
install(EXPORT JavaScriptCoreWRTTargets
  DESTINATION ${ConfigPackageLocation}
  )

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/JavaScriptCoreWRTConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/JavaScriptCoreWRTConfigVersion.cmake"
  DESTINATION ${ConfigPackageLocation}
  COMPONENT Devel
  )
]]
