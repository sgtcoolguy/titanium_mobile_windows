/**
 * TitaniumKit AcceptDict
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Network/Socket/AcceptDict.hpp"

namespace Titanium
{
	namespace Network
	{
		namespace Socket
		{
			using namespace HAL;

			AcceptDict js_to_AcceptDict(const JSObject& object)
			{
				const auto timeout = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(
														static_cast<std::uint32_t>(object.GetProperty("timeout"))));
				AcceptDict config {
					object.GetProperty("error"),
					timeout
				};
				
				return config;
			};

			JSObject AcceptDict_to_js(const JSContext& js_context, const AcceptDict& config)
			{
				auto object = js_context.CreateObject();
				object.SetProperty("error",    config.error);
				object.SetProperty("timeout",  js_context.CreateNumber(static_cast<double>(config.timeout.count())));
				return object;
			}
		} // namespace Socket
	} // namespace Network
} // namespace Titanium
