/**
* Titanium.UI.AlertDialog for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/AlertDialog.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/API.hpp"
#include "Titanium/detail/TiLogger.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Popups;
		using namespace Windows::Foundation;

		std::vector<Windows::UI::Popups::MessageDialog^> AlertDialog::dialogs__;

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

			auto maxButtons = buttonNames__.size();
			if (buttonNames__.size() > MaxButtonCount) {
				auto Titanium_property = get_context().get_global_object().GetProperty("Titanium");
				TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
				auto Titanium = static_cast<JSObject>(Titanium_property);

				auto Object_property = Titanium.GetProperty("API");
				TITANIUM_ASSERT(Object_property.IsObject());  // precondition
				auto api = static_cast<JSObject>(Object_property);
				auto native_api = api.GetPrivate<Titanium::API>();
				native_api->error("Number of buttons exceeds platform maximum (" + std::to_string(MaxButtonCount) + "), list will be truncated.");
				maxButtons = MaxButtonCount;
			}
			for (size_t i = 0; i < maxButtons; i++) {
				dialog->Commands->Append(ref new Windows::UI::Popups::UICommand(TitaniumWindows::Utility::ConvertUTF8String(buttonNames__[i]), nullptr, PropertyValue::CreateInt32(i)));
			}

			try {
				dialogs__.push_back(dialog);
				if (dialogs__.size() == 1) {
					static std::function<void(IUICommand^)> on_click;
					on_click = [this](IUICommand^ command) {
						std::int32_t index = 0;
						if (command != nullptr) {
							auto casted = dynamic_cast<IPropertyValue^>(command->Id);
							if (casted != nullptr) {
								index = casted->GetInt32();
							}
						}
						const JSContext ctx = get_context();
						JSObject eventArgs = ctx.CreateObject();
						eventArgs.SetProperty("index", ctx.CreateNumber(index));
						eventArgs.SetProperty("cancel", ctx.CreateBoolean(index == get_cancel()));
						fireEvent("click", eventArgs);

						// display next dialog in queue
						if (dialogs__.size() > 1) {
							dialogs__.erase(dialogs__.begin());
							concurrency::create_task(dialogs__.front()->ShowAsync()).then(on_click);
						}
					};
					concurrency::create_task(dialog->ShowAsync()).then(on_click);
				}
			} catch (::Platform::COMException^ ce) {
				// Typically would have happened on phone if we supplied more than max buttons allowed
				detail::ThrowRuntimeError("Ti.UI.AlertDialog", "Exception during show(): " + Utility::ConvertUTF8String(ce->Message));
			} catch (...) {
				detail::ThrowRuntimeError("Ti.UI.AlertDialog", "Exception during show()");
			}
		}
	} // namespace UI
} // namespace TitaniumWindows
