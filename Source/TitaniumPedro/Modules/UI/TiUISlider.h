/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUISLIDER_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUISLIDER_H_

#include "TiCore/TiViewProxy.h"

// This is a Ti.UI.Slider
// Internally, it is a Slider as well
namespace Ti{
	namespace UI {

		class Slider : public Ti::ViewProxy, public virtual_enable_shared_from_this < Slider > {

			TI_CREATE_PROXY(Slider);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }

		public:

			// The slider can have a desired width, but has a hard coded height.
			virtual bool ignoreHeight() const { return true; }
			std::string defaultWidth() const override { return Ti::Constants::SizeFILL; }
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments);

		protected:

			Slider(const std::string& name, const std::vector<Ti::Value>& arguments);

			virtual ~Slider() {
				slider_ = nullptr;
			}
			// Sets the value of the value property.
			Ti::Value setValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Slider, setValue);
			// Gets the value of the value property.
			Ti::Value getValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Slider, getValue);

		private:

			Windows::Foundation::EventRegistrationToken change_event_;
			unsigned int change_event_count_{ 0 };
			Windows::UI::Xaml::Controls::Slider^ slider_{ nullptr };

		};

	}	// namespace UI {
}
#endif	// _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUISLIDER_H_
