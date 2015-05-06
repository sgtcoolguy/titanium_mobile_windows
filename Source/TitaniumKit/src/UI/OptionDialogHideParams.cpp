/**
 * TitaniumKit OptionDialogHideParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/OptionDialogHideParams.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		OptionDialogHideParams js_to_OptionDialogHideParams(const JSObject& object)
		{
			OptionDialogHideParams dict;
			if (object.HasProperty("animated")) {
				dict.animated = static_cast<bool>(object.GetProperty("animated"));
			}
			return dict;
		};

		JSObject OptionDialogHideParams_to_js(const JSContext& js_context, const OptionDialogHideParams& dict)
		{
			auto object = js_context.CreateObject();
			object.SetProperty("animated", js_context.CreateBoolean(dict.animated));
			return object;
		};
	} // namespace UI
} // namespace Titanium
