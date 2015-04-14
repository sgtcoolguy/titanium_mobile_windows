/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/AlertDialog.hpp"

namespace Titanium
{
	namespace UI
	{
		AlertDialog::AlertDialog(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Module(js_context),
			  cancel__(-1),
		      message__(js_context.CreateString()),
		      title__(js_context.CreateString())
		{
			TITANIUM_LOG_DEBUG("AlertDialog:: ctor ", this);
		}

		AlertDialog::~AlertDialog() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("AlertDialog:: dtor ", this);
		}

		void AlertDialog::hide() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("AlertDialog::hide");
		}

		void AlertDialog::show() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("AlertDialog::show");
		}

		TITANIUM_PROPERTY_READWRITE(AlertDialog, std::vector<std::string>, buttonNames)

		void AlertDialog::addButton(const std::string& buttonName) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("AlertDialog::addButton not implemented");
		}

		TITANIUM_PROPERTY_READWRITE(AlertDialog, int32_t, cancel)

		TITANIUM_PROPERTY_READWRITE(AlertDialog, std::string, message)

		TITANIUM_PROPERTY_READWRITE(AlertDialog, std::string, title)

		void AlertDialog::JSExportInitialize()
		{
			JSExport<AlertDialog>::SetClassVersion(1);
			JSExport<AlertDialog>::SetParent(JSExport<Module>::Class());
			TITANIUM_ADD_FUNCTION(AlertDialog, hide);
			TITANIUM_ADD_FUNCTION(AlertDialog, show);
			TITANIUM_ADD_PROPERTY(AlertDialog, buttonNames);
			TITANIUM_ADD_PROPERTY(AlertDialog, cancel);
			TITANIUM_ADD_PROPERTY(AlertDialog, message);
			TITANIUM_ADD_PROPERTY(AlertDialog, title);
		}

		TITANIUM_FUNCTION(AlertDialog, hide)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			hide();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(AlertDialog, show)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			show();
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(AlertDialog, buttonNames)
		{
			auto context = get_context();
			std::vector<JSValue> jsButtonNames = std::vector<JSValue>();
			for (auto &buttonName : buttonNames__) {
				jsButtonNames.push_back(context.CreateString(buttonName));
			}
			return context.CreateArray(jsButtonNames);
		}

		TITANIUM_PROPERTY_SETTER(AlertDialog, buttonNames)
		{
			TITANIUM_ASSERT(argument.IsObject());
			auto object = static_cast<JSObject>(argument);

			// This allows us to see the size of the array
			const auto string_count = object.GetPropertyNames().GetCount();
			if (string_count == 0) {
				TITANIUM_LOG_WARN("AlertDialog::js_set_buttonNames no button names given");
				return false;
			}

			// convert the array into std::vector
			buttonNames__ = std::vector<std::string>();
			for (unsigned i = 0; i < string_count; ++i) {
				// TODO verify that the array has something at this index, JS arrays can be sparse!
				JSValue button_name = object.GetProperty(i);

				// Precondition
				TITANIUM_ASSERT(button_name.IsString());
				std::string name = static_cast<std::string>(button_name);
				buttonNames__.push_back(name);
				addButton(name);
			}
			return true;
		}

		TITANIUM_PROPERTY_GETTER(AlertDialog, message)
		{
			return get_context().CreateString(get_message());
		}

		TITANIUM_PROPERTY_SETTER(AlertDialog, message)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_message(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(AlertDialog, cancel)
		{
			return get_context().CreateNumber(get_cancel());
		}

		TITANIUM_PROPERTY_SETTER(AlertDialog, cancel)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_cancel(static_cast<int32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(AlertDialog, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_PROPERTY_SETTER(AlertDialog, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}
	} // namespace UI
}  // namespace Titanium
