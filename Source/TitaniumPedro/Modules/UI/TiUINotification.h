/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUINOTIFICATION_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUINOTIFICATION_H_

#include "TiCore/TiProxy.h"

namespace Ti
{
	namespace UI
	{
		class Notification : public Ti::Proxy, public virtual_enable_shared_from_this < Notification > 
		{
			TI_CREATE_PROXY(Notification);
			static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
		public:

		protected:
			Notification(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~Notification() {
			}

      // Gets the value of the duration property.
      TI_CREATE_METHOD(Notification, getDuration);
      Ti::Value getDuration(const std::vector<Ti::Value>& arguments);
      // Sets the value of the duration property.
      TI_CREATE_METHOD(Notification, setDuration);
      Ti::Value setDuration(const std::vector<Ti::Value>& arguments);
			// Gets the value of the message property.
			TI_CREATE_METHOD(Notification, getMessage);
			Ti::Value getMessage(const std::vector<Ti::Value>& arguments);
			// Sets the value of the message property.
			TI_CREATE_METHOD(Notification, setMessage);
			Ti::Value setMessage(const std::vector<Ti::Value>& arguments);
      // Shows the toast
      TI_CREATE_METHOD(Notification, show);
      Ti::Value show(const std::vector<Ti::Value>& arguments);

		private:

      std::string message_;
      unsigned int duration_;
		};

	}
}

#endif // #define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUINOTIFICATION_H_
