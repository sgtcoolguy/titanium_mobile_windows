/**
 * TitaniumKit PushNotificationConfig
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Network/PushNotificationConfig.hpp"

namespace Titanium
{
	namespace Network
	{
		using namespace HAL;

		PushNotificationConfig js_to_PushNotificationConfig(const JSObject& object)
		{
			std::vector<Network::TYPE> types;
			const auto js_types_property = object.GetProperty("types");
			if (js_types_property.IsObject()) {
				const auto js_types_object = static_cast<JSObject>(js_types_property);
				if (js_types_object.IsArray()) {
					const auto js_types = static_cast<std::vector<JSValue>>(static_cast<JSArray>(js_types_object));
					for (const auto t : js_types) {
						types.push_back(Titanium::Network::Constants::to_TYPE(static_cast<std::underlying_type<Network::TYPE>::type>(t)));
					}
				}
			}

			PushNotificationConfig config {
				object.GetProperty("callback"),
				object.GetProperty("error"),
				object.GetProperty("success"),
				types
			};
			
			return config;
		};

		JSObject PushNotificationConfig_to_js(const JSContext& js_context, const PushNotificationConfig& config)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("callback", config.callback);
			object.SetProperty("error",    config.error);
			object.SetProperty("success",  config.success);

			std::vector<JSValue> js_types;
			for (const auto t : config.types) {
				js_types.push_back(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(t)));
			}
			object.SetProperty("types", js_context.CreateArray(js_types));

			return object;
		}
	} // namespace Network
} // namespace Titanium
