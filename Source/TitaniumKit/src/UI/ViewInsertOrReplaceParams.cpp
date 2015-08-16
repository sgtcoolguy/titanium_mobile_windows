/**
 * TitaniumKit ViewInsertOrReplaceParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ViewInsertOrReplaceParams.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		ViewInsertOrReplaceParams js_to_ViewInsertOrReplaceParams(const JSObject& object)
		{
			ViewInsertOrReplaceParams params;
			if (object.HasProperty("view")) {
				params.view = static_cast<JSObject>(object.GetProperty("view")).GetPrivate<View>();
			}
			if (object.HasProperty("position")) {
				params.position = static_cast<std::uint32_t>(object.GetProperty("position"));
			}
			return params;
		};

		JSObject ViewInsertOrReplaceParams_to_js(const JSContext& js_context, const ViewInsertOrReplaceParams& params)
		{
			auto object = js_context.CreateObject();
			if (params.view != nullptr) {
				object.SetProperty("view", params.view->get_object());
			}
			object.SetProperty("position", js_context.CreateNumber(params.position));
			return object;
		}
	} // namespace UI
} // namespace Titanium
