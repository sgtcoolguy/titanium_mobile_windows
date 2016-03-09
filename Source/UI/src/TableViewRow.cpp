/**
 * Titanium.UI.TableViewRow for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/UI/TableViewRow.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/UI/Label.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		TableViewRow::TableViewRow(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TableViewRow(js_context)
		{
			TITANIUM_LOG_DEBUG("TableViewRow::ctor Initialize");
		}

		void TableViewRow::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TableViewRow::postCallAsConstructor(js_context, arguments);
			content__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::TableViewRow::setLayoutDelegate<WindowsViewLayoutDelegate>();
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::SIZE);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(content__);
		}

		void TableViewRow::JSExportInitialize() 
		{
			JSExport<TableViewRow>::SetClassVersion(1);
			JSExport<TableViewRow>::SetParent(JSExport<Titanium::UI::TableViewRow>::Class());
		}

		void TableViewRow::ensureRowLabel() 
		{
			if (title__ == nullptr) {
				const auto Titanium_property = get_context().get_global_object().GetProperty("Titanium");
				TITANIUM_ASSERT(Titanium_property.IsObject());
				const auto Titanium = static_cast<JSObject>(Titanium_property);

				const auto UI_property = Titanium.GetProperty("UI");
				TITANIUM_ASSERT(UI_property.IsObject());
				const auto UI = static_cast<JSObject>(UI_property);

				const auto Label_property = UI.GetProperty("Label");
				TITANIUM_ASSERT(Label_property.IsObject());
				auto Label = static_cast<JSObject>(Label_property);

				const auto label = Label.CallAsConstructor();
				title__ = label.GetPrivate<TitaniumWindows::UI::Label>();
				title__->set_text("");
				title__->getViewLayoutDelegate()->set_left("0");

				add(label);
			}
		}

		void TableViewRow::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableViewRow::set_title(title);
			ensureRowLabel();
			title__->set_text(title);
		}

		void TableViewRow::set_color(const std::string& color) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TableViewRow::set_color(color);
			ensureRowLabel();
			title__->set_color(color);
		}

	}  // namespace UI
}  // namespace TitaniumWindows