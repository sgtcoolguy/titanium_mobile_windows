/**
* Titanium.UI.AlertDialog for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/AlertDialog.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Popups;
		using namespace Windows::Foundation;

		AlertDialog::AlertDialog(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Titanium::UI::AlertDialog(js_context)
		{
			TITANIUM_LOG_DEBUG("AlertDialog::ctor");
		}

		void AlertDialog::JSExportInitialize()
		{
			JSExport<AlertDialog>::SetClassVersion(1);
			JSExport<AlertDialog>::SetParent(JSExport<Titanium::UI::AlertDialog>::Class());
		}

		void AlertDialog::hide() TITANIUM_NOEXCEPT
		{
			// TODO Implement!
		}

		void AlertDialog::show() TITANIUM_NOEXCEPT
		{
			std::string title   = get_title();
			std::string message = get_message();

			Windows::UI::Popups::MessageDialog^ dialog = ref new Windows::UI::Popups::MessageDialog(TitaniumWindows::Utility::ConvertUTF8String(message), TitaniumWindows::Utility::ConvertUTF8String(title));
			dialog->DefaultCommandIndex = 0;

			const auto cancelIndex = get_cancel();
			if (cancelIndex >= 0) {
				dialog->CancelCommandIndex = get_cancel();
			}

			for (std::vector<std::string>::size_type i = 0; i != buttonNames__.size(); i++) {
				dialog->Commands->Append(ref new Windows::UI::Popups::UICommand(TitaniumWindows::Utility::ConvertUTF8String(buttonNames__[i]), nullptr, PropertyValue::CreateInt32(i)));
			}

			concurrency::create_task(dialog->ShowAsync()).then([this](IUICommand^ command) {
				const auto index = dynamic_cast<IPropertyValue^>(command->Id)->GetInt32();
				const JSContext ctx = get_context();
				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("index", ctx.CreateNumber(index));
				eventArgs.SetProperty("cancel", ctx.CreateBoolean(index == get_cancel()));
				fireEvent("click", eventArgs);
			});
		}
	} // namespace UI
} // namespace TitaniumWindows
