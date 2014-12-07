/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

//
// App.xaml.cpp
// Implementation of the App class.
//

#include "App.h"
#include <iostream>
#include <JavaScriptCore/JavaScript.h>
#include "TiCore/TiValue.h"
#include "TiCore/TiRuntime.h"
#include "TiCore/TiRuntimeFunctions.h"
#include "Modules/UI/UIModule.h"
#include "Modules/Ti/TiModule.h"
#include "Modules/XML/TiXML.h"
#include "Modules/Platform/TiPlatform.h"
#include "Util/OutputDebugStringBuf.hpp"
#include "Modules/Filesystem/TiFilesystem.h"
#include "Modules/Network/TiNetwork.h"
#include "Modules/Gesture/TiGesture.h"
#include "Modules/Accelerometer/TiAccelerometer.h"
#include "Modules/Database/TiDatabase.h"
#include "Modules/App/TiApp.h"
#include "Modules/Geolocation/TiGeolocation.h"
#include <Windows.h>
#include <collection.h>

using namespace TitaniumPedro;
using namespace Windows::UI::Xaml::Controls;

App::App() {
#ifndef NDEBUG
#ifdef _WIN32
	static Appcelerator::Util::OutputDebugStringBuf<char> charDebugOutput;
	std::cerr.rdbuf(&charDebugOutput);
	std::clog.rdbuf(&charDebugOutput);

	static Appcelerator::Util::OutputDebugStringBuf<wchar_t> wcharDebugOutput;
	std::wcerr.rdbuf(&wcharDebugOutput);
	std::wclog.rdbuf(&wcharDebugOutput);
#endif
#endif
}

App::~App() {
}

void App::OnLaunched(LaunchActivatedEventArgs^ args) {

	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);

#if _DEBUG
	if (IsDebuggerPresent()) {
		DebugSettings->EnableFrameRateCounter = true;
	}
#endif


	auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);
	// Do not repeat app initialization when the Window already has content,
	// just ensure that the window is active.
	if (rootFrame == nullptr) {
		rootFrame = ref new Frame();

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		// Removes the turnstile navigation for startup.
		if (rootFrame->ContentTransitions != nullptr) {
			_transitions = ref new Windows::UI::Xaml::Media::Animation::TransitionCollection();
			for (auto transition : rootFrame->ContentTransitions) {
				_transitions->Append(transition);
			}
		}

		rootFrame->ContentTransitions = nullptr;
		_firstNavigatedToken = rootFrame->Navigated += ref new Windows::UI::Xaml::Navigation::NavigatedEventHandler(this, &App::RootFrame_FirstNavigated);
#endif
		// Create a Frame to act as the navigation context and associate it with
		// a SuspensionManager key

		// TODO: Change this value to a cache size that is appropriate for your application.
		rootFrame->CacheSize = 1;

		if (args->PreviousExecutionState == ApplicationExecutionState::Terminated) {
			// TODO: Restore the saved session state only when appropriate, scheduling the
			// final launch steps after the restore is complete.
		}

		// Place the frame in the current Window
		Window::Current->Content = rootFrame;

		Ti::Value tiModule = TiModule::Initialize("Ti", Ti::Value(Ti::Runtime::instance().globalObject()));
		Ti::Runtime::instance().addPropertyToGlobalObject("Titanium", tiModule);
		Ti::Value uiModule = UI::UIModule::Initialize("UI", tiModule);
		Ti::Value platformModule = Ti::Platform::Platform::Initialize("Platform", tiModule);
		Ti::Value fsModule = Filesystem::FSModule::Initialize("Filesystem", tiModule);
		Ti::Value networkModule = Network::NetworkModule::Initialize("Network", tiModule);
		Ti::Value dbModule = Ti::Database::DBModule::Initialize("Database", tiModule);
		Ti::Value appModule = Ti::App::AppModule::Initialize("App", tiModule);
		Ti::App::AppModule::SetArguments(Ti::Utils::GetPlatformString(args->Arguments));
		Ti::Value xmlModule = Ti::XML::XMLModule::Initialize("XML", tiModule);
		Ti::Value gestureModule = Ti::Gesture::GestureModule::Initialize("Gesture", tiModule);
		Ti::Value accelerometerModule = Ti::Accelerometer::AccelerometerModule::Initialize("Accelerometer", tiModule);
		Ti::Value geolocationModule = Ti::Geolocation::Geolocation::Initialize("Geolocation", tiModule);

		Ti::requireJS("app");
	}
	// Ensure the current window is active
	Window::Current->Activate();
}

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
/// <summary>
/// Restores the content transitions after the app has launched.
/// </summary>
void App::RootFrame_FirstNavigated(Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	auto rootFrame = safe_cast<Frame^>(sender);

	Windows::UI::Xaml::Media::Animation::TransitionCollection^ newTransitions;
	if (_transitions == nullptr) {
		newTransitions = ref new Windows::UI::Xaml::Media::Animation::TransitionCollection();
		newTransitions->Append(ref new Windows::UI::Xaml::Media::Animation::NavigationThemeTransition());
	} else {
		newTransitions = _transitions;
	}

	rootFrame->ContentTransitions = newTransitions;
	rootFrame->Navigated -= _firstNavigatedToken;
}
#endif

void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e) {
}
