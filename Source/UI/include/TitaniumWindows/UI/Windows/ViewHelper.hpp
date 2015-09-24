/**
* View Helper for Windows
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#ifndef _TITANIUMWINDOWS_WINDOWS_VIEWHELPER_HPP_
#define _TITANIUMWINDOWS_WINDOWS_VIEWHELPER_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/Font.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		namespace ViewHelper
		{
			using namespace HAL;

			//
			// Setup TextBlock font from Titanium::UI::Font
			//
			TITANIUMWINDOWS_UI_EXPORT void SetFont(const JSContext& js_context, Windows::UI::Xaml::Controls::TextBlock^ textBlock, const Titanium::UI::Font& font);

		} // namespace ViewHelper
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_WINDOWS_VIEWHELPER_HPP_