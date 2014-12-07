/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIBUTTON_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIBUTTON_H_

#include "TiCore/TiViewProxy.h"
#include "TiCore/TiWebColor.h"

namespace Ti
{
	namespace UI
	{
		class Button : public Ti::ViewProxy, public virtual_enable_shared_from_this < Button >
		{
			TI_CREATE_PROXY(Button);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:


		protected:
			Button(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~Button() {
				button_ = nullptr;
			}
			TI_CREATE_METHOD(Button, setTitle);
			Ti::Value setTitle(const std::vector<Ti::Value>& arguments);

		private:
			Windows::UI::Xaml::Controls::Button^ button_;

		};

	}	// namespace UI {
}
#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIBUTTON_H_
