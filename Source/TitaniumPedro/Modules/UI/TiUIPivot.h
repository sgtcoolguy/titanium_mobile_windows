/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#if 0

#ifndef __TI_UI_PIVOT_PROXY_H__
#define __TI_UI_PIVOT_PROXY_H__

#include "TiCore/TiViewProxy.h"

// This is Ti.UI.View
// Uses a Canvas internally
namespace Ti{
	namespace UI {

		class Pivot : public Ti::ViewProxy, public virtual_enable_shared_from_this < Pivot > {

		public:

			// A Ti.UI.View will be as big as it can unless otherwise specified.
			virtual std::string defaultHeight() const {
				return Ti::Constants::SizeFILL;
			}

			virtual std::string defaultWidth() const {
				return Ti::Constants::SizeFILL;
			}


		protected:

			Pivot(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
				setComponent(_canvas);
			}

			virtual ~Pivot() {
				// Null the canvas on GC
				_canvas = nullptr;
			}

		private:

			// Event handler for "click" event
			void OnTapped(Platform::Object ^ sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^ e);
			Windows::UI::Xaml::Controls::Canvas^ _canvas = ref new Windows::UI::Xaml::Controls::Canvas();


			////////////////////////////////////////////////////////////////////////
			//
			// Proxy macro infrastructure goes below here.
			//
			////////////////////////////////////////////////////////////////////////

			TI_CREATE_PROXY(Pivot);

			static JSClassRef Parent() {
				return Ti::ViewProxy::ClassDef();
			}

		};

	}	// namespace UI {
}
#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIVIEW_H_
#endif
