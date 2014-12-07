/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiUISwitch.h"
#include "TiCore/TiUtils.h"
#include <Windows.h>

namespace Ti {
	namespace UI {
		// These are JavaScript methods they will call class methods
		const JSStaticFunction Switch::ClassMethods[] = {
				{ "setEnabled", _setEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getEnabled", _getEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFont", _setFont, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTitle", _setTitle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTitleOff", _setTitleOff, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTitleOn", _setTitleOn, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setValue", _setValue, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getValue", _getValue, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		Switch::~Switch()
		{
		}
		Switch::Switch(const std::string& name, const std::vector<Ti::Value>& args) : Ti::ViewProxy(name, args)
		{
			switch_ = ref new Windows::UI::Xaml::Controls::ToggleSwitch();
			setComponent(switch_);
		}

		Ti::Value Switch::eventAdded(const std::vector<Ti::Value>& args)
		{
			return Ti::ViewProxy::eventAdded(args);
		}
		Ti::Value Switch::eventRemoved(const std::vector<Ti::Value>& args)
		{
			return Ti::ViewProxy::eventRemoved(args);
		}

		// Public API
		// Sets the value of the enabled property.
		Ti::Value Switch::setEnabled(const std::vector<Ti::Value>& args)
		{
			switch_->IsEnabled = args[0].toBool();
			return Ti::Value::Undefined();
		}
		// Gets the value of the enabled property.
		Ti::Value Switch::getEnabled(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(switch_->IsEnabled);
		}
		// Sets the value of the font property.
		Ti::Value Switch::setFont(const std::vector<Ti::Value>& args)
		{
			OutputDebugString(L"[WARN] Switch.setFont() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
		// Sets the value of the title property.
		Ti::Value Switch::setTitle(const std::vector<Ti::Value>& args)
		{
			switch_->Header = Ti::Utils::GetPlatformString(args[0].toString());
			return Ti::Value::Undefined();
		}
		// Sets the value of the titleOff property.
		Ti::Value Switch::setTitleOff(const std::vector<Ti::Value>& args)
		{
			switch_->OffContent = Ti::Utils::GetPlatformString(args[0].toString());
			return Ti::Value::Undefined();
		}
		// Sets the value of the titleOn property.
		Ti::Value Switch::setTitleOn(const std::vector<Ti::Value>& args)
		{
			switch_->OnContent = Ti::Utils::GetPlatformString(args[0].toString());
			return Ti::Value::Undefined();
		}
		// Sets the value of the value property.
		Ti::Value Switch::setValue(const std::vector<Ti::Value>& args)
		{
			switch_->IsOn = args[0].toBool();
			return Ti::Value::Undefined();
		}
		// Gets the value of the value property.
		Ti::Value Switch::getValue(const std::vector<Ti::Value>& args)
		{
			return Ti::Value(switch_->IsOn);
		}
	}
}