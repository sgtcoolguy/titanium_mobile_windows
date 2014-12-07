/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUINotification.h"
#include "Modules/UI/UIModule.h"
#include "TiCore/TiUtils.h"

namespace Ti {
	namespace UI {

		const JSStaticFunction Notification::ClassMethods[] = {
				{ "setDuration", _setDuration, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getDuration", _getDuration, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "setHorizontalMargin", _setHorizontalMargin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "getHorizontalMargin", _getHorizontalMargin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMessage", _setMessage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setMessage", _setMessage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "setVerticalMargin", _setVerticalMargin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "getVerticalMargin", _getVerticalMargin, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "setXOffset", _setXOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "getXOffset", _getXOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "setYOffset", _setYOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				//{ "getYOffset", _getYOffset, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "show", _show, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		Notification::Notification(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
		}

    // Gets the value of the duration property.
    Ti::Value Notification::getDuration(const std::vector<Ti::Value>& arguments) {
      return Ti::Value(static_cast<double>(duration_));
    }

    // Sets the value of the duration property.
    Ti::Value Notification::setDuration(const std::vector<Ti::Value>& arguments) {
      duration_ = static_cast<int>(arguments.at(0).toDouble());
      return Ti::Value::Undefined();
    }

		// Gets the value of the message property.
		Ti::Value Notification::getMessage(const std::vector<Ti::Value>& arguments)
		{
			return Ti::Value(message_);
		}

		// Sets the value of the message property.
		Ti::Value Notification::setMessage(const std::vector<Ti::Value>& arguments)
		{
			message_ = arguments.at(0).toString();
			return Ti::Value::Undefined();
		}

    Ti::Value Notification::show(const std::vector<Ti::Value>& arguments) {
      using namespace Windows::UI::Notifications;
      auto xml = ToastNotificationManager::GetTemplateContent(ToastTemplateType::ToastText02); // only 2 is supported on phone 8.1
      auto textNodes = xml->GetElementsByTagName("text");
      textNodes->GetAt(0)->AppendChild(xml->CreateTextNode(Ti::Utils::GetPlatformString(message_)));
      textNodes->GetAt(1)->AppendChild(xml->CreateTextNode(""));
#if WINAPI_FAMILY!=WINAPI_FAMILY_PHONE_APP
      // Specifying duration length is only supported on WinStore, phone always does short
      auto toast_node = xml->SelectSingleNode("/toast");
      auto attr = xml->CreateAttribute("duration");
      if (duration_ == ::UI::UIModule::NOTIFICATION_DURATION_LONG) {
        attr->NodeValue = "long";
      }
      else {
        attr->NodeValue = "short";
      }
      toast_node->Attributes->SetNamedItem(attr);
#endif
      auto notification = ref new ToastNotification(xml);
      auto notifier = ToastNotificationManager::CreateToastNotifier();
      notifier->Show(notification);
      return Ti::Value::Undefined();
    }
	}
} // namespace Ti { namespace UI {
