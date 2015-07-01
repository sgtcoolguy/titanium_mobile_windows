/**
 * Titanium.UI.OptionDialog for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/OptionDialog.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiLogger.hpp"
#include <ppltasks.h>

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Popups;
		using namespace Windows::Foundation;

		OptionDialog::OptionDialog(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::OptionDialog(js_context)
		{
			TITANIUM_LOG_DEBUG("OptionDialog::ctor Initialize");
		}

		void OptionDialog::JSExportInitialize() {
			JSExport<OptionDialog>::SetClassVersion(1);
			JSExport<OptionDialog>::SetParent(JSExport<Titanium::UI::OptionDialog>::Class());
		}

		void OptionDialog::show(const Titanium::UI::OptionDialogShowParams& params) TITANIUM_NOEXCEPT
		{
			std::string title = get_title();

			Windows::UI::Popups::MessageDialog^ dialog = ref new MessageDialog(TitaniumWindows::Utility::ConvertUTF8String(title));
			dialog->DefaultCommandIndex = get_selectedIndex();

			const auto cancelIndex = get_cancel();
			if (cancelIndex >= 0) {
				dialog->CancelCommandIndex = get_cancel();
			}

			for (std::vector<std::string>::size_type i = 0; i != options__.size(); i++) {
				dialog->Commands->Append(ref new Windows::UI::Popups::UICommand(TitaniumWindows::Utility::ConvertUTF8String(options__[i]), nullptr, PropertyValue::CreateInt32(i)));
			}

			concurrency::create_task(dialog->ShowAsync()).then([this](IUICommand^ command) {
				std::int32_t index = 0;
				if (command != nullptr) {
					index = dynamic_cast<IPropertyValue^>(command->Id)->GetInt32();
				}
				const JSContext ctx = get_context();
				JSObject eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("index", ctx.CreateNumber(index));
				eventArgs.SetProperty("cancel", ctx.CreateBoolean(index == get_cancel()));
				eventArgs.SetProperty("destructive", ctx.CreateNumber(get_destructive()));
				fireEvent("click", eventArgs);
			});
		}

		void OptionDialog::hide(const Titanium::UI::OptionDialogHideParams& params) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("OptionDialog.hide is not implemented yet");
		}

	}  // namespace UI
}  // namespace TitaniumWindows