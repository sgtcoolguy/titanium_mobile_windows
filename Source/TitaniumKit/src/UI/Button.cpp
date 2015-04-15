/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Button.hpp"

namespace Titanium
{
	namespace UI
	{
		Button::Button(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      title__(js_context.CreateString())
		{
			TITANIUM_LOG_DEBUG("Button:: ctor ", this);
		}

		Button::~Button() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("Button:: dtor ", this);
		}

		TITANIUM_PROPERTY_READWRITE(Button, std::string, title)

		void Button::JSExportInitialize()
		{
			JSExport<Button>::SetClassVersion(1);
			JSExport<Button>::SetParent(JSExport<View>::Class());
			
			TITANIUM_ADD_FUNCTION(Button, setTitle);
			TITANIUM_ADD_PROPERTY(Button, title);
		}

		TITANIUM_PROPERTY_GETTER(Button, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_PROPERTY_SETTER(Button, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION_AS_SETTER(Button, setTitle, title)

	} // namespace UI
}  // namespace Titanium
