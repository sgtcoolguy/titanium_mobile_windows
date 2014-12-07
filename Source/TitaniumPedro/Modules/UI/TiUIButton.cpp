/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIButton.h"

namespace Ti
{

	namespace UI
	{
		JSStaticFunction const Button::ClassMethods[] = {
				{ "setTitle", _setTitle, 0 },
				{ 0, 0, 0 }
		};

		Button::Button(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			button_ = ref new Windows::UI::Xaml::Controls::Button();
			setComponent(button_);
		}

		Ti::Value Button::setTitle(const std::vector<Ti::Value>& arguments) {
			std::string title = arguments.at(0).toString();
			std::wstring wTitle = std::wstring(title.begin(), title.end());
			button_->Content = ref new Platform::String(wTitle.c_str());
			return Ti::Value::Undefined();
		}

	}
}
