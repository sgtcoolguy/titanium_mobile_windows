/**
 * TitaniumKit TitleAttributesParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TitleAttributesParams.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		TitleAttributesParams js_to_TitleAttributesParams(const JSObject& object)
		{
			TitleAttributesParams params;
			if (object.HasProperty("color")) {
				params.color = static_cast<std::string>(object.GetProperty("color"));
			}
			if (object.HasProperty("font") && object.GetProperty("font").IsObject()) {
				params.font = js_to_Font(static_cast<JSObject>(object.GetProperty("color")));
			}
			if (object.HasProperty("shadow") && object.GetProperty("shadow").IsObject()) {
				params.shadow = js_to_ShadowDict(static_cast<JSObject>(object.GetProperty("shadow")));
			}
			return params;
		};

		JSObject TitleAttributesParams_to_js(const JSContext& js_context, const TitleAttributesParams& params)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("color",   js_context.CreateString(params.color));
			object.SetProperty("font",    Font_to_js(js_context, params.font));
			object.SetProperty("shadow",  ShadowDict_to_js(js_context, params.shadow));
			return object;
		}
	} // namespace UI
} // namespace Titanium
