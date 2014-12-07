/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_UI_SWITCH_PROXY_H__
#define __TI_UI_SWITCH_PROXY_H__

#include "TiCore/TiViewProxy.h"

namespace Ti {
	namespace UI {
		class Switch : public Ti::ViewProxy, public virtual_enable_shared_from_this<Switch>
		{
			TI_CREATE_PROXY(Switch)
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:

			virtual bool ingoreHeight() const { return true; }
			virtual bool ingoreWidth() const { return false; }
			virtual std::string defaultHeight() const { return Ti::Constants::SizeSIZE; }
			virtual std::string defaultWidth() const { return Ti::Constants::SizeSIZE; }
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>&);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&);
		protected:
			Switch(const std::string&, const std::vector<Ti::Value>&);
			virtual ~Switch();

			// JavaScript's public API

			// Sets the value of the enabled property.
			Ti::Value setEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setEnabled);
			// Gets the value of the enabled property.
			Ti::Value getEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, getEnabled);
			// Sets the value of the font property.
			Ti::Value setFont(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setFont);
			// Sets the value of the title property.
			Ti::Value setTitle(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setTitle);
			// Sets the value of the titleOff property.
			Ti::Value setTitleOff(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setTitleOff);
			// Sets the value of the titleOn property.
			Ti::Value setTitleOn(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setTitleOn);
			// Sets the value of the value property.
			Ti::Value setValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, setValue);
			// Gets the value of the value property.
			Ti::Value getValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(Switch, getValue);
		private:
			Windows::UI::Xaml::Controls::ToggleSwitch^ switch_;

		};
	}
}
#endif // defined(__TI_UI_SWITCH_PROXY_H__)