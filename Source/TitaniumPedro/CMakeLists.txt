
cmake_minimum_required (VERSION 3.0.0)
project (titanium)

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Windows(Phone|Store)")
  message("This project supports Windows Phone / Store only. Please choose a different system.")
endif()

get_filename_component(APPCELERATOR_CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake ABSOLUTE)
list(INSERT CMAKE_MODULE_PATH 0 ${APPCELERATOR_CMAKE_MODULE_PATH})

find_package(JavaScriptCore REQUIRED)
find_package(SQLite REQUIRED)
add_definitions(-DSTATICALLY_LINKED_WITH_JavaScriptCore)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${JavaScriptCore_INCLUDE_DIRS}
  ${SQLite_INCLUDE_DIRS}
  )

# Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(TiModule_CONTENT_FILES
  Modules/Ti/ti.js
  TiCore/ti.jsutils.js
)
set(TiCore_SOURCE_FILES
  TiCore/ProxyCacheManager.cpp
  TiCore/ProxyCacheManager.hpp
  TiCore/BaseProxy.cpp
  TiCore/BaseProxy.h
  TiCore/TiValue.h
  TiCore/TiValue.cpp
  TiCore/TiRuntime.cpp
  TiCore/TiRuntime.h
  TiCore/TiRuntimeFunctions.cpp
  TiCore/TiRuntimeFunctions.h
  TiCore/TiConstants.cpp
  TiCore/TiConstants.h
  TiCore/TimerProxy.cpp
  TiCore/TimerProxy.h
  TiCore/TiProxy.cpp
  TiCore/TiProxy.h
  TiCore/TiWebColor.cpp
  TiCore/TiWebColor.h
  TiCore/TiUtils.h
  TiCore/TiUtils.cpp
  TiCore/TiViewProxy.cpp
  TiCore/TiViewProxy.h
  TiCore.h
  Modules/Ti/TiModule.cpp
  Modules/Ti/TiModule.h
  ${TiModule_CONTENT_FILES}
)
set(TiUIModule_CONTENT_FILES
  Modules/UI/ti.ui.js
  Modules/UI/ti.ui.tabgroup.js
  Modules/UI/TiUIWebViewBinding.js
)

set(UIModule_SOURCE_FILES
  Modules/UI/TiPageManager.cpp
  Modules/UI/TiPageManager.h
  Modules/UI/TiUIAlertDialog.cpp
  Modules/UI/TiUIAlertDialog.h
  Modules/UI/TiUIButton.cpp
  Modules/UI/TiUIButton.h
  Modules/UI/TiUIEmailDialog.cpp
  Modules/UI/TiUIEmailDialog.h
  Modules/UI/TiUIImageButton.h
  Modules/UI/TiUIImageButton.cpp
  Modules/UI/TiUIImageView.h
  Modules/UI/TiUIImageView.cpp
  Modules/UI/TiUILabel.h
  Modules/UI/TiUILabel.cpp
  Modules/UI/TiUINotification.h
  Modules/UI/TiUINotification.cpp
  Modules/UI/TiUIPivot.h
  Modules/UI/TiUIPivot.cpp
  Modules/UI/TiUIPivotItem.h
  Modules/UI/TiUIPivotItem.cpp
  Modules/UI/TiUIProgressBar.cpp
  Modules/UI/TiUIProgressBar.h
  Modules/UI/TiUIScrollView.h
  Modules/UI/TiUIScrollView.cpp
  Modules/UI/TiUISearchBar.h
  Modules/UI/TiUISearchBar.cpp
  Modules/UI/TiUISlider.cpp
  Modules/UI/TiUISlider.h
  Modules/UI/TiUISwitch.h
  Modules/UI/TiUISwitch.cpp
  Modules/UI/TiUITableView.h
  Modules/UI/TiUITableView.cpp
  Modules/UI/TiUITableViewRow.h
  Modules/UI/TiUITableViewRow.cpp
  Modules/UI/TiUITextField.h
  Modules/UI/TiUITextField.cpp
  Modules/UI/TiUIView.cpp
  Modules/UI/TiUIView.h
  Modules/UI/TiUIWebView.h
  Modules/UI/TiUIWebView.cpp
  Modules/UI/TiUIWindow.cpp
  Modules/UI/TiUIWindow.h
  Modules/UI/TiUIWindowsProgressRing.cpp
  Modules/UI/TiUIWindowsProgressRing.h
  Modules/UI/UIModule.cpp
  Modules/UI/UIModule.h
  ${TiUIModule_CONTENT_FILES}
)
set(AppModule_SOURCE_FILES
  Modules/App/TiApp.cpp
  Modules/App/TiApp.h
  Modules/App/TiAppProperties.cpp
  Modules/App/TiAppProperties.h
  ${AppModule_CONTENT_FILES}
)
set(AppModule_CONTENT_FILES
  Modules/App/ti.app.js
)
set(FilesystemModule_SOURCE_FILES
  Modules/Filesystem/TiFilesystem.cpp
  Modules/Filesystem/TiFilesystem.h
  Modules/Filesystem/TiFilesystemFile.cpp
  Modules/Filesystem/TiFilesystemFile.h
)
set(NetworkModule_SOURCE_FILES
  Modules/Network/TiNetwork.cpp
  Modules/Network/TiNetwork.h
  Modules/Network/TiHTTPClient.cpp
  Modules/Network/TiHTTPClient.h
)
set(AccelerometerModule_SOURCE_FILES
  Modules/Accelerometer/TiAccelerometer.cpp
  Modules/Accelerometer/TiAccelerometer.h
)
set(GestureModule_SOURCE_FILES
  Modules/Gesture/TiGesture.cpp
  Modules/Gesture/TiGesture.h
  Modules/Gesture/ShakeGestureHelper.cpp
  Modules/Gesture/ShakeGestureHelper.h
)
set(DatabaseModule_SOURCE_FILES
  Modules/Database/TiDatabase.cpp
  Modules/Database/TiDatabase.h
  Modules/Database/TiDatabaseDB.cpp
  Modules/Database/TiDatabaseDB.h
  Modules/Database/TiDatabaseResultSet.cpp
  Modules/Database/TiDatabaseResultSet.h
)
set(GeolocationModule_CONTENT_FILES
  Modules/Geolocation/ti.geolocation.js
)
set(GeolocationModule_SOURCE_FILES
  Modules/Geolocation/TiGeolocation.cpp
  Modules/Geolocation/TiGeolocation.h
  ${GeolocationModule_CONTENT_FILES}
)
set(Layout_SOURCE_FILES
  Layout/TiLayout.h
  Layout/Common.cpp
  Layout/Composite.cpp
  Layout/Element.cpp
  Layout/Horizontal.cpp
  Layout/Node.cpp
  Layout/ParseProperty.cpp
  Layout/Vertical.cpp
)
set(PlatformModule_CONTENT_FILES
  Modules/Platform/ti.platform.js
)
set(PlatformModule_SOURCE_FILES
  Modules/Platform/TiPlatform.cpp
  Modules/Platform/TiPlatform.h
  Modules/Platform/TiPlatformDisplayCaps.cpp
  Modules/Platform/TiPlatformDisplayCaps.h
  ${PlatformModule_CONTENT_FILES}
)
set(XMLModule_CONTENT_FILES
  Modules/XML/ti.xml.js
  Modules/XML/dom.js
  Modules/XML/sax.js
  Modules/XML/dom-parser.js
)
set(XMLModule_SOURCE_FILES
  Modules/XML/TiXML.cpp
  Modules/XML/TiXML.h
  ${XMLModule_CONTENT_FILES}
)

set_property(SOURCE ${AppModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${GeolocationModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${TiModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${TiUIModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${XMLModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)
set_property(SOURCE ${PlatformModule_CONTENT_FILES} PROPERTY VS_DEPLOYMENT_CONTENT 1)

set(BlobModule_SOURCE_FILES
  Modules/Blob/TiBlob.cpp
  Modules/Blob/TiBlob.h
)

set(SOURCE_FILES
  ${TiCore_SOURCE_FILES}
  ${UIModule_SOURCE_FILES}
  ${AppModule_SOURCE_FILES}
  ${FilesystemModule_SOURCE_FILES}
  ${NetworkModule_SOURCE_FILES}
  ${DatabaseModule_SOURCE_FILES}
  ${Layout_SOURCE_FILES}
  ${PlatformModule_SOURCE_FILES}
  ${XMLModule_SOURCE_FILES}
  ${BlobModule_SOURCE_FILES}
  ${AccelerometerModule_SOURCE_FILES}
  ${GestureModule_SOURCE_FILES}
  ${GeolocationModule_SOURCE_FILES}
  App.cpp
  App.h
  )

source_group("TiCore" FILES ${TiCore_SOURCE_FILES})
source_group("UIModule" FILES ${UIModule_SOURCE_FILES})
source_group("AppModule" FILES ${AppModule_SOURCE_FILES})
source_group("FilesystemModule" FILES ${FilesystemModule_SOURCE_FILES})
source_group("NetworkModule" FILES ${NetworkModule_SOURCE_FILES})
source_group("DatabaseModule" FILES ${DatabaseModule_SOURCE_FILES})
source_group("Layout" FILES ${Layout_SOURCE_FILES})
source_group("XML" FILES ${XMLModule_SOURCE_FILES})
source_group("PlatformModule" FILES ${PlatformModule_SOURCE_FILES})
source_group("Blob" FILES ${BlobModule_SOURCE_FILES})
source_group("Accelerometer" FILES ${AccelerometerModule_SOURCE_FILES})
source_group("Gesture" FILES ${GestureModule_SOURCE_FILES})
source_group("Geolocation" FILES ${GeolocationModule_SOURCE_FILES})
source_group("App"  FILES
  App.cpp
  App.h
)
get_filename_component(UTIL_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../Util ABSOLUTE)
add_subdirectory(${UTIL_SOURCE_DIR} ${CMAKE_BINARY_DIR}/Util)

add_library(TitaniumPedro SHARED ${SOURCE_FILES})
set_target_properties(TitaniumPedro PROPERTIES VS_WINRT_COMPONENT "true")
set_target_properties(TitaniumPedro PROPERTIES FOLDER TitaniumPedro)

target_link_libraries(TitaniumPedro Util ${JavaScriptCore_LIBRARIES})
target_link_libraries(TitaniumPedro Util ${SQLite_LIBRARIES})

# Boost support
set( Boost_USE_STATIC_LIBS    ON  )
set( Boost_USE_MULTITHREADED  ON  )
set( Boost_USE_STATIC_RUNTIME OFF )

# Travis only supports Boost 1.55, which is good enough for now.
find_package( Boost 1.55.0 REQUIRED )

include_directories(${Boost_INCLUDE_DIRS})
