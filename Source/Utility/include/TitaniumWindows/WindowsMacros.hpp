/**
 * Windows specific macros
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_WINDOWSMACROS_HPP_
#define _TITANIUMWINDOWS_WINDOWSMACROS_HPP_

#include <sdkddkver.h>

/* 
  - IS_WINDOWS_10     ... Windows 10
  - IS_WINDOWS_MOBILE ... Windows 10 Mobile
  - IS_WINDOWS_PHONE  ... Windows Phone
*/
#if (WINVER >= 0x0A00)
#define IS_WINDOWS_10
#define IS_WINDOWS_MOBILE (Windows::System::Profile::AnalyticsInfo::VersionInfo->DeviceFamily == "Windows.Mobile")
#else
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#define IS_WINDOWS_PHONE
#endif
#endif

#endif  // _TITANIUMWINDOWS_WINDOWSMACROS_HPP_
