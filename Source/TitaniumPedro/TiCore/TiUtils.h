/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIUTILS_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIUTILS_H_

#include <string>
#include <ctime>
#include <codecvt>
#include <vector>

namespace Ti { namespace Utils {

//
// Run a task on the UI thread
//
template<class T> static void RunOnUIThread(T handler) {
	auto dispatcher = Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher;
	dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler(handler));
}

//
// Run a task on the UI thread with a specified priority
//
template<class T> static void RunOnUIThread(Windows::UI::Core::CoreDispatcherPriority priority, T handler) {
	auto dispatcher = Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher;
	dispatcher->RunAsync(priority, ref new Windows::UI::Core::DispatchedHandler(handler));
}

//
// Convert std::string into Platform::String^
//
static ::Platform::String^ GetPlatformString(const std::string& s_str) {
	const std::wstring b(s_str.begin(), s_str.end());
	const wchar_t *wcString = b.c_str();
	return ref new ::Platform::String(wcString);
}

//
// Convert Platform::String^ into std::string
//
static std::string GetPlatformString(::Platform::String^ str) {
	return std::string(str->Begin(), str->End());
}

//
// Convert Platform::String^ into UTF-8 std::string
//
static std::string GetPlatformUTF8String(::Platform::String^ str) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return std::string(converter.to_bytes(str->Data()));
}

//
// Return millisecond since epoch from Windows DateTime
//
static double GetMSecSinceEpoch(Windows::Foundation::DateTime d) {
	Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
	cal->SetDateTime(d);
	
	std::tm tm = { cal->Second, cal->Minute, cal->Hour+(cal->Period==1?0:12), cal->Day, cal->Month-1, cal->Year - 1900, 0, 0, -1 };
	const std::time_t t = std::mktime(&tm);
	
	return t * 1000;
}

// get content from IBuffer
std::vector<unsigned char> GetContentFromBuffer(Windows::Storage::Streams::IBuffer^ buffer);

// get content from storage file
std::vector<unsigned char> GetContentFromFile(Windows::Storage::StorageFile^ file);

// get mime type from extension
const std::string MimeTypeForExtension(std::string& path);

}} // namespace Ti { namespace Utils {
   
#endif  // _TITANIUM_MOBILE_WINDOWS_TICORE_TIUTILS_H_
   
