/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUISlider.h"
#include "TiCore/TiConstants.h"

using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;

namespace Ti{
	namespace UI {

		JSStaticFunction const Slider::ClassMethods[] = {
				{ "setValue", _setValue, 0 },
				{ "getValue", _getValue, 0 },
				{ 0, 0, 0 }
		};

		Slider::Slider(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)	
		{
			slider_ = ref new Windows::UI::Xaml::Controls::Slider();
			setComponent(slider_);
		}

		// Get the events as they are added to the object
		Ti::Value Slider::eventAdded(const std::vector<Ti::Value>& arguments)
		{
			auto arg = arguments[0].toString();

			// Handle the "change" event unless it has already been set.
			if (arg == Ti::Constants::EventChange) {
				if (change_event_count_ == 0) {
					// Save the result from setting the event to a var, this way it
					// can be removed later Add the native event to the Slider.
					auto weak = get_weak_ptr_for_proxy();
					change_event_ = slider_->ValueChanged +=
						ref new RangeBaseValueChangedEventHandler([weak](Platform::Object^ sender, RangeBaseValueChangedEventArgs^ args) {
						auto proxy = weak.lock();
						assert(proxy != nullptr);
						// Create a event args
						Ti::Value obj;
						// Add the value to it
						obj.setProperty("value", Ti::Value(args->NewValue));
						// Fire the event!
						proxy->fireEvent(Ti::Constants::EventChange, obj);
					});
				}
				++change_event_count_;
			}
			return Ti::ViewProxy::eventAdded(arguments);
		}
		Ti::Value Slider::eventRemoved(const std::vector<Ti::Value>& arguments) 
		{
			auto arg = arguments[0].toString();
			if (arg == Ti::Constants::EventChange) {
				--change_event_count_;
				if (change_event_count_ == 0) {
					slider_->ValueChanged -= change_event_;
				}
			}
			return Ti::ViewProxy::eventRemoved(arguments);
		}


		Ti::Value Slider::setValue(const std::vector<Ti::Value>& args)
		{
			slider_->Value = args[0].toDouble();
			return Ti::Value::Undefined();
		}
		Ti::Value Slider::getValue(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(slider_->Value);
		}


	}	// namespace UI {
}