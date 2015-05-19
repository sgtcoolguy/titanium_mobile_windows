/**
 * TitaniumKit PushNotificationConfig
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_PUSHNOTIFICATIONCONFIG_HPP_
#define _TITANIUM_NETWORK_PUSHNOTIFICATIONCONFIG_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Network/Constants.hpp"
#include <vector>

namespace Titanium
{
	namespace Network
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion Simple object for specifying push notification options to registerForPushNotifications.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/PushNotificationConfig
		*/
		struct PushNotificationConfig
		{
			JSValue callback;
			JSValue error;
			JSValue success;
			std::vector<Titanium::Network::TYPE> types;
		};
		
		PushNotificationConfig js_to_PushNotificationConfig(const JSObject& object);
		JSObject PushNotificationConfig_to_js(const JSContext& js_context, const PushNotificationConfig& config);
		
	} // namespace Network
} // namespace Titanium
#endif // _TITANIUM_NETWORK_PUSHNOTIFICATIONCONFIG_HPP_
