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

		std::string Button::get_title() const TITANIUM_NOEXCEPT
		{
			return title__;
		}

		void Button::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			title__ = title;
		}

		void Button::JSExportInitialize()
		{
			JSExport<Button>::SetClassVersion(1);
			JSExport<Button>::SetParent(JSExport<View>::Class());
			
			TITANIUM_ADD_FUNCTION(Button, setTitle);
			TITANIUM_ADD_PROPERTY(Button, title);
		}

		TITANIUM_PROPERTY_GETTER(Button, title)
		{
			return get_context().CreateString(title__);
		}

		TITANIUM_PROPERTY_SETTER(Button, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			const std::string title = static_cast<std::string>(argument);
			TITANIUM_LOG_DEBUG("Button::js_set_title: title = ", title);
			set_title(title);
			return true;
		}

		TITANIUM_FUNCTION(Button, setTitle)
		{
			if (arguments.size() > 0) {
				js_set_title(arguments.at(0));
			}
			return this_object.get_context().CreateUndefined();
		}

	} // namespace UI
}  // namespace Titanium
