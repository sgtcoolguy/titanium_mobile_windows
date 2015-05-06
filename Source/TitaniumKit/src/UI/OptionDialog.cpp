/**
 * TitaniumKit Titanium.UI.OptionDialog
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/OptionDialog.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{


		OptionDialog::OptionDialog(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context),
			cancel__(-1),
			destructive__(-1),
			opaquebackground__(false),
			persistent__(true),
			selectedIndex__(0),
			title__(""),
			titleid__("")
		{
		}

		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::shared_ptr<View>, androidView)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::vector<std::string>, buttonNames)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::int32_t, cancel)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::int32_t, destructive)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::vector<std::string>, options)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, bool, opaquebackground)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, bool, persistent)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::uint32_t, selectedIndex)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::string, title)
		TITANIUM_PROPERTY_READWRITE(OptionDialog, std::string, titleid)

		void OptionDialog::show(const std::shared_ptr<OptionDialogShowParams>& params) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("OptionDialog::show");
		}

		void OptionDialog::hide(const std::shared_ptr<OptionDialogHideParams>& params) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("OptionDialog::hide");
		}

		void OptionDialog::JSExportInitialize() 
		{
			JSExport<OptionDialog>::SetClassVersion(1);
			JSExport<OptionDialog>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(OptionDialog, androidView);
			TITANIUM_ADD_PROPERTY(OptionDialog, buttonNames);
			TITANIUM_ADD_PROPERTY(OptionDialog, cancel);
			TITANIUM_ADD_PROPERTY(OptionDialog, destructive);
			TITANIUM_ADD_PROPERTY(OptionDialog, options);
			TITANIUM_ADD_PROPERTY(OptionDialog, opaquebackground);
			TITANIUM_ADD_PROPERTY(OptionDialog, persistent);
			TITANIUM_ADD_PROPERTY(OptionDialog, selectedIndex);
			TITANIUM_ADD_PROPERTY(OptionDialog, title);
			TITANIUM_ADD_PROPERTY(OptionDialog, titleid);

			TITANIUM_ADD_FUNCTION(OptionDialog, show);
			TITANIUM_ADD_FUNCTION(OptionDialog, hide);
			TITANIUM_ADD_FUNCTION(OptionDialog, getAndroidView);
			TITANIUM_ADD_FUNCTION(OptionDialog, setAndroidView);
			TITANIUM_ADD_FUNCTION(OptionDialog, getButtonNames);
			TITANIUM_ADD_FUNCTION(OptionDialog, setButtonNames);
			TITANIUM_ADD_FUNCTION(OptionDialog, getCancel);
			TITANIUM_ADD_FUNCTION(OptionDialog, setCancel);
			TITANIUM_ADD_FUNCTION(OptionDialog, getDestructive);
			TITANIUM_ADD_FUNCTION(OptionDialog, setDestructive);
			TITANIUM_ADD_FUNCTION(OptionDialog, getOptions);
			TITANIUM_ADD_FUNCTION(OptionDialog, setOptions);
			TITANIUM_ADD_FUNCTION(OptionDialog, getOpaquebackground);
			TITANIUM_ADD_FUNCTION(OptionDialog, setOpaquebackground);
			TITANIUM_ADD_FUNCTION(OptionDialog, getPersistent);
			TITANIUM_ADD_FUNCTION(OptionDialog, setPersistent);
			TITANIUM_ADD_FUNCTION(OptionDialog, getSelectedIndex);
			TITANIUM_ADD_FUNCTION(OptionDialog, setSelectedIndex);
			TITANIUM_ADD_FUNCTION(OptionDialog, getTitle);
			TITANIUM_ADD_FUNCTION(OptionDialog, setTitle);
			TITANIUM_ADD_FUNCTION(OptionDialog, getTitleid);
			TITANIUM_ADD_FUNCTION(OptionDialog, setTitleid);
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, androidView)
		{
			const auto view = get_androidView();
			if (view != nullptr) {
				return view->get_object();
			}
			return get_context().CreateNull();
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, androidView)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_androidView(static_cast<JSObject>(argument).GetPrivate<View>());
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, buttonNames)
		{
			std::vector<JSValue> names;
			for (auto name : get_buttonNames()) {
				names.push_back(get_context().CreateString(name));
			}
			return get_context().CreateArray(names);
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, buttonNames)
		{
			TITANIUM_ASSERT(argument.IsObject());
			auto js_arg = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(js_arg.IsArray());

			auto names = static_cast<JSArray>(js_arg);
			auto js_names = static_cast<std::vector<JSValue>>(names);
			std::vector<std::string> buttonNames;
			for (auto name : js_names) {
				buttonNames.push_back(static_cast<std::string>(name));
			}
			set_buttonNames(buttonNames);

			return true;
	}

		TITANIUM_PROPERTY_GETTER(OptionDialog, cancel)
		{
			return get_context().CreateNumber(get_cancel());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, cancel)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_cancel(static_cast<std::int32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, destructive)
		{
			return get_context().CreateNumber(get_destructive());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, destructive)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_destructive(static_cast<std::int32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, options)
		{
			std::vector<JSValue> options;
			for (auto option : get_options()) {
				options.push_back(get_context().CreateString(option));
			}
			return get_context().CreateArray(options);
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, options)
		{
			TITANIUM_ASSERT(argument.IsObject());
			auto js_arg = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(js_arg.IsArray());

			auto options = static_cast<JSArray>(js_arg);
			auto js_options = static_cast<std::vector<JSValue>>(options);
			std::vector<std::string> dialogOptions;
			for (auto option : js_options) {
				dialogOptions.push_back(static_cast<std::string>(option));
			}
			set_options(dialogOptions);

			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, opaquebackground)
		{
			return get_context().CreateBoolean(get_opaquebackground());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, opaquebackground)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_opaquebackground(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, persistent)
		{
			return get_context().CreateBoolean(get_persistent());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, persistent)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_persistent(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, selectedIndex)
		{
			return get_context().CreateNumber(get_selectedIndex());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, selectedIndex)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_selectedIndex(static_cast<std::uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, title)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(OptionDialog, titleid)
		{
			return get_context().CreateString(get_titleid());
		}

		TITANIUM_PROPERTY_SETTER(OptionDialog, titleid)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_titleid(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(OptionDialog, show)
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(params, 0);

			show(params.GetPrivate<OptionDialogShowParams>());

			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(OptionDialog, hide)
		{
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(params, 0);

			hide(params.GetPrivate<OptionDialogHideParams>());

			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getAndroidView, androidView)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setAndroidView, androidView)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getButtonNames, buttonNames)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setButtonNames, buttonNames)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getCancel, cancel)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setCancel, cancel)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getDestructive, destructive)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setDestructive, destructive)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getOptions, options)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setOptions, options)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getOpaquebackground, opaquebackground)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setOpaquebackground, opaquebackground)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getPersistent, persistent)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setPersistent, persistent)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getSelectedIndex, selectedIndex)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setSelectedIndex, selectedIndex)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getTitle, title)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setTitle, title)
		TITANIUM_FUNCTION_AS_GETTER(OptionDialog, getTitleid, titleid)
		TITANIUM_FUNCTION_AS_SETTER(OptionDialog, setTitleid, titleid)

	} // namespace UI
} // namespace Titanium