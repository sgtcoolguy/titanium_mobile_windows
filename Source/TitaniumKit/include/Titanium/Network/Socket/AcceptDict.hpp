/**
 * TitaniumKit AcceptDict
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_SOCKET_ACCEPTDICT_HPP_
#define _TITANIUM_NETWORK_SOCKET_ACCEPTDICT_HPP_

#include "Titanium/detail/TiBase.hpp"

namespace Titanium
{
	namespace Network
	{
		namespace Socket
		{
			using namespace HAL;

			/*!
			  @struct
			  @discussion Simple object for specifying push notification options to registerForPushNotifications.
			  This is an abstract type. Any object meeting this description can be used where this type is used.
			  See http://docs.appcelerator.com/titanium/latest/#!/api/AcceptDict
			*/
			struct AcceptDict
			{
				JSValue error;
				std::chrono::milliseconds timeout;
			};
			
			AcceptDict js_to_AcceptDict(const JSObject& object);
			JSObject AcceptDict_to_js(const JSContext& js_context, const AcceptDict& config);

		} // namespace Socket
	} // namespace Network
} // namespace Titanium
#endif // _TITANIUM_NETWORK_SOCKET_ACCEPTDICT_HPP_
