/**
 * Titanium for Windows
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
#include "OutputDebugStringBuf.hpp"
#include <iostream>
#include "TitaniumWindows/WindowsNativeModuleLoader.hpp"

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
		auto module_loader = new TitaniumWindows::WindowsNativeModuleLoader();
    ref new TitaniumWindows::Application(module_loader);
  }));

  return 0;
}
