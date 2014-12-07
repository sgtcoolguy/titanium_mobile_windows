cmake_minimum_required(VERSION 3.0)
project(Russ)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "WindowsPhone")
  set(PLATFORM WP)
  add_definitions("-DPHONE")
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "WindowsStore")
  set(PLATFORM STORE)
else()
  message(FATAL_ERROR "This app supports Store / Phone only. Please edit the target platform.")
endif()

# We only support Windows Store/Phone 8.1
set(CMAKE_SYSTEM_VERSION "8.1")

# Variable naming the built executable.
set(EXE_NAME ${PROJECT_NAME})

# Variables required to generate the app manifest.
set(APP_MANIFEST_NAME Package.appxmanifest)
set(SHORT_NAME ${EXE_NAME})
set(PACKAGE_GUID "b6931098-20d0-4c57-8e65-0f9cde7e00e9")

# Generate the app manifest.
configure_file(
  cmake/Package.${PLATFORM}.appxmanifest.in
  ${CMAKE_CURRENT_BINARY_DIR}/${APP_MANIFEST_NAME}
  @ONLY)

set(SOURCE_FILES
  src/Main.cpp
  )

set(HEADER_FILES
  )

set(CONTENT_FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${APP_MANIFEST_NAME}
  Assets/Logo.png
  Assets/SmallLogo.png
  Assets/SplashScreen.png
  Assets/StoreLogo.png
  src/app.js
  )

set(RESOURCE_FILES
  ${CONTENT_FILES}
  )

set_property(SOURCE ${CONTENT_FILES}         PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${DEBUG_CONTENT_FILES}   PROPERTY VS_DEPLOYMENT_CONTENT $<CONFIG:Debug>)
set_property(SOURCE ${RELEASE_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT $<OR:$<CONFIG:Release>,$<CONFIG:RelWithDebInfo>,$<CONFIG:MinSizeRel>>)

source_group("Source Files"   FILES ${SOURCE_FILES})
source_group("Header Files"   FILES ${HEADER_FILES})
source_group("Resource Files" FILES ${RESOURCE_FILES})

# Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${EXE_NAME} WIN32 ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILES})
set_property(TARGET ${EXE_NAME} PROPERTY VS_WINRT_COMPONENT TRUE)

get_filename_component(TITANIUMRUSS_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../Source/TitaniumRuss ABSOLUTE)
#message("MDL: TITANIUMRUSS_SOURCE_DIR = ${TITANIUMRUSS_SOURCE_DIR}")
add_subdirectory(${TITANIUMRUSS_SOURCE_DIR} "${CMAKE_BINARY_DIR}/TitaniumRuss")

target_link_libraries(${EXE_NAME} TitaniumRuss)
