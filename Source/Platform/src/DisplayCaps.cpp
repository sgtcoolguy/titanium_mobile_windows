/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/DisplayCaps.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <objbase.h>

namespace TitaniumWindows
{
	DisplayCaps::DisplayCaps(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
	    : Titanium::Platform::DisplayCaps(js_context, arguments)
	{
		TITANIUM_LOG_DEBUG("DisplayCaps::ctor");
	}

	void DisplayCaps::JSExportInitialize()
	{
		JSExport<DisplayCaps>::SetClassVersion(1);
		JSExport<DisplayCaps>::SetParent(JSExport<Titanium::Platform::DisplayCaps>::Class());
	}

	std::string DisplayCaps::density() const TITANIUM_NOEXCEPT
	{
		// On Windows, there's no string value to describe screen density like "high" and "medium".
		// Returning empty string for now
		return "";
	}

	double DisplayCaps::dpi() const TITANIUM_NOEXCEPT
	{
		auto display = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
		TITANIUM_ASSERT(display);
		return display->LogicalDpi;
	}

	double DisplayCaps::logicalDensityFactor() const TITANIUM_NOEXCEPT
	{
		auto display = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
		TITANIUM_ASSERT(display);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
		return display->RawPixelsPerViewPixel;
#else
		return static_cast<int>(display->ResolutionScale) / 100.0;
#endif
	}

	double DisplayCaps::platformHeight() const TITANIUM_NOEXCEPT
	{
		TITANIUM_ASSERT(Windows::UI::Xaml::Window::Current);
		return Windows::UI::Xaml::Window::Current->Bounds.Height;
	}

	double DisplayCaps::platformWidth() const TITANIUM_NOEXCEPT
	{
		TITANIUM_ASSERT(Windows::UI::Xaml::Window::Current);
		return Windows::UI::Xaml::Window::Current->Bounds.Width;
	}

	double DisplayCaps::xdpi() const TITANIUM_NOEXCEPT
	{
		auto display = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
		TITANIUM_ASSERT(display);
		return display->RawDpiX;
	}

	double DisplayCaps::ydpi() const TITANIUM_NOEXCEPT
	{
		auto display = Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
		TITANIUM_ASSERT(display);
		return display->RawDpiY;
	}
}  // namespace TitaniumWindows
