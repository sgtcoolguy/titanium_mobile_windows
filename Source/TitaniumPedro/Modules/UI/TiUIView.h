/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIVIEW_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIVIEW_H_

#include "TiCore/TiViewProxy.h"

// This is Ti.UI.View
// Uses a Canvas internally
namespace Ti {
	namespace UI {

		class View : public Ti::ViewProxy, public virtual_enable_shared_from_this < View >
		{
			TI_CREATE_PROXY(View);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			// A Ti.UI.View will be as big as it can unless otherwise specified.
			virtual std::string defaultHeight() const {return Ti::Constants::SizeFILL;}
			virtual std::string defaultWidth() const {return Ti::Constants::SizeFILL;}

		protected:

			View(const std::string& name, const std::vector<Ti::Value>& arguments);

			virtual ~View() {
				// Null the canvas on GC
				canvas_ = nullptr;
			}

		private:

			// Event handler for "click" event
			Windows::UI::Xaml::Controls::Canvas^ canvas_;

		};

	}	// namespace UI {
}
#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIVIEW_H_
