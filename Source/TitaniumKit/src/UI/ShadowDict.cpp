/**
 * TitaniumKit ShadowDict
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ShadowDict.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		ShadowDict js_to_ShadowDict(const JSObject& object)
		{
			ShadowDict shadowDict;
			if (object.HasProperty("blurRadius")) {
				shadowDict.blurRadius = static_cast<double>(object.GetProperty("blurRadius"));
			}
			if (object.HasProperty("color")) {
				shadowDict.color = static_cast<std::string>(object.GetProperty("color"));
			}
			if (object.HasProperty("offset") && object.GetProperty("offset").IsObject()) {
				shadowDict.offset = js_to_Dimension(static_cast<JSObject>(object.GetProperty("offset")));
			}
			return shadowDict;
		};

		JSObject ShadowDict_to_js(const JSContext& js_context, const ShadowDict& shadowDict)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("blurRadius",  js_context.CreateNumber(static_cast<double>(shadowDict.blurRadius)));
			object.SetProperty("color",       js_context.CreateString(static_cast<std::string>(shadowDict.color)));
			object.SetProperty("offset",      Dimension_to_js(js_context, shadowDict.offset));
			return object;
		}
	} // namespace UI
} // namespace Titanium
