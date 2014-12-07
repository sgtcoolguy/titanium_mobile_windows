cmake_minimum_required (VERSION 3.0.0)
project (TitaniumRuss)

if(NOT "${CMAKE_SYSTEM_NAME}" MATCHES "Windows(Phone|Store)")
  message("This project supports Windows Phone / Store only. Please choose a different system.")
endif()

get_filename_component(APPCELERATOR_CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake ABSOLUTE)
list(INSERT CMAKE_MODULE_PATH 0 ${APPCELERATOR_CMAKE_MODULE_PATH})

find_package(JavaScriptCore REQUIRED)
add_definitions(-DSTATICALLY_LINKED_WITH_JavaScriptCore)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${JavaScriptCore_INCLUDE_DIR}
  )

# Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SOURCE_FILES
  TiApp.cpp
  TiApp.h
  
  common/Module.cpp
  common/Module.h
  common/SourceFile.cpp
  common/SourceFile.h
  common/Utils.cpp
  common/Utils.h
  
  hyperloop/hyperloop_common.cpp
  hyperloop/hyperloop_common.h
  hyperloop/hyperloop_Logger.cpp
  hyperloop/hyperloop_Logger.h
  hyperloop/hyperloop_require.cpp
  hyperloop/hyperloop_windows.cpp
  hyperloop/hyperloop_windows.h
  
  Titanium/Titanium.cpp
  Titanium/Titanium.h
  
  Titanium/UI/Layout/Common.cpp
  Titanium/UI/Layout/Common.h
  Titanium/UI/Layout/Composite.cpp
  Titanium/UI/Layout/Composite.h
  Titanium/UI/Layout/Element.cpp
  Titanium/UI/Layout/Element.h
  Titanium/UI/Layout/Horizontal.cpp
  Titanium/UI/Layout/Horizontal.h
  Titanium/UI/Layout/ParseProperty.cpp
  Titanium/UI/Layout/ParseProperty.h
  Titanium/UI/Layout/Vertical.cpp
  Titanium/UI/Layout/Vertical.h
  
  Titanium/UI/UI.cpp
  Titanium/UI/UI.h
  Titanium/UI/UIPrototype.cpp
  Titanium/UI/UIPrototype.h
  Titanium/UI/View.cpp
  Titanium/UI/View.h
  Titanium/UI/Window.cpp
  Titanium/UI/Window.h
  )


add_library(TitaniumRuss SHARED ${SOURCE_FILES})
set_target_properties(TitaniumRuss PROPERTIES VS_WINRT_COMPONENT "true")
set_target_properties(TitaniumRuss PROPERTIES FOLDER TitaniumRuss)
target_link_libraries(TitaniumRuss ${JavaScriptCore_LIBRARIES})
