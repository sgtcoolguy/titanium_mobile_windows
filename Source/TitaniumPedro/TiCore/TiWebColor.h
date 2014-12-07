/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIWEBCOLOR_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIWEBCOLOR_H_

#include <string>
#include <Windows.h>

// Helper class to get color values from strings.

namespace Ti { namespace WebColor {

// Creates a native color object from a string.
Windows::UI::Color Color(const std::string& colorName);

// Creates a native color object from a hex value.
Windows::UI::Color ColorForHex(const std::string& hexCode);

}}	// namespace Ti { namespace WebColor {

#endif	// _TITANIUM_MOBILE_WINDOWS_TICORE_TIWEBCOLOR_H_
