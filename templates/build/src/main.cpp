/**
 * Titanium for Windows
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#include "OutputDebugStringBuf.hpp"

#include <iostream>

#include <collection.h>

#include "HAL/HAL.hpp"
#include "TitaniumWindows/WindowsNativeModuleLoader.hpp"

//// NATIVE_MODULE_INCLUDES START

//// NATIVE_MODULE_INCLUDES END

using namespace HAL;

Windows::Foundation::Collections::IVector<Platform::String ^> ^ OnTitaniumModuleNames(int js_context_ref);
std::intptr_t OnTitaniumModuleRequire(std::intptr_t js_context_ref, Platform::String ^moduleId);
std::intptr_t OnTitaniumModulePreload(std::intptr_t js_context_ref);

int main(Platform::Array<Platform::String^>^) {

#if defined(_WIN32)
  static TitaniumWindows::OutputDebugStringBuf<char> charDebugOutput;
  std::cerr.rdbuf(&charDebugOutput);
  std::clog.rdbuf(&charDebugOutput);

  static TitaniumWindows::OutputDebugStringBuf<wchar_t> wcharDebugOutput;
  std::wcerr.rdbuf(&wcharDebugOutput);
  std::wclog.rdbuf(&wcharDebugOutput);
#endif

  Windows::UI::Xaml::Application::Start(ref new Windows::UI::Xaml::ApplicationInitializationCallback([](Windows::UI::Xaml::ApplicationInitializationCallbackParams^ params) {
    auto app = ref new TitaniumWindows::Application();
    app->TitaniumModulePreload += ref new TitaniumWindows::TitaniumModulePreloadHandler(&OnTitaniumModulePreload);
    app->TitaniumModuleRequire += ref new TitaniumWindows::TitaniumModuleRequireHandler(&OnTitaniumModuleRequire);
    app->TitaniumModuleNames += ref new TitaniumWindows::TitaniumModuleNamesHandler(&OnTitaniumModuleNames);
  }));

  return 0;
}

// This should return pointer to JSObject (key-value) which consists of module name & preloaded JSObject
std::intptr_t OnTitaniumModulePreload(std::intptr_t js_context_ref) {
  const auto js_context = JSContext(reinterpret_cast<JSContextRef>(js_context_ref));

  auto js_preloaded_module_map = js_context.CreateObject();

  //// INITIALLIZE PRELOADED NATIVE MODULE START

  //// TODO: native module initialization 
  //// js_preloaded_module_map.SetProperty("com.example.test", js_context.CreateObject(JSExport<Com::Example::Test>::Class()));

  //// INITIALLIZE PRELOADED NATIVE MODULE END

  return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(js_preloaded_module_map));
}

// This will be called when native module with supported name is not loaded. Return pointer to JSValue as the result of require.
std::intptr_t OnTitaniumModuleRequire(std::intptr_t js_context_ref, Platform::String^ moduleId) {
  const auto js_context = JSContext(reinterpret_cast<JSContextRef>(js_context_ref));
  auto module_loader = new TitaniumWindows::WindowsNativeModuleLoader();
  auto value = module_loader->registerNativeModule(js_context, TitaniumWindows::Utility::ConvertString(moduleId));
  //// INITIALLIZE SUPPORTED NATIVE MODULE START

  //// TODO: Initialize supported module here
  //// if (moduleId == "Windows.UI.Xaml.Controls.Button") {
  ////  return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(js_context.CreateObject(JSExport<Xaml::UI::Button>::Class())));
  //// } else if (moduleId == "Windows.UI.Xaml.Controls.ListView") {
  ////  return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(js_context.CreateObject(JSExport<Xaml::UI::ListView>::Class())));
  //// }

  //// INITIALLIZE SUPPORTED NATIVE MODULE END

  return reinterpret_cast<std::intptr_t>(static_cast<JSValueRef>(value));
}

// This should return collections of supported name module names such as Windows.Xaml.Controls.Button etc.
Windows::Foundation::Collections::IVector<Platform::String^>^ OnTitaniumModuleNames(std::intptr_t js_context_ref) {
  auto names = ref new ::Platform::Collections::Vector<::Platform::String^>();

  //// INSERT SUPPORTED NATIVE MODULE NAMES START

  //// TODO: Insert supported module names here
  //// names->Append("com.example.test");
  //// names->Append("Windows.UI.Xaml.Controls.Button");
  //// names->Append("Windows.UI.Xaml.Controls.ListView");

  //// INSERT SUPPORTED NATIVE MODULE NAMES END

  return names;
}