/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUIView.h"

namespace Ti
{
	namespace UI
	{
		JSStaticFunction const View::ClassMethods[] = {
				{ 0, 0, 0 }
		};
		View::View(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			canvas_ = ref new Windows::UI::Xaml::Controls::Canvas();
			setComponent(canvas_);
		}

	}
}