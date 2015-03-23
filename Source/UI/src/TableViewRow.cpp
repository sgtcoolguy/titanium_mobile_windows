/**
 * Titanium.UI.TableViewRow for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/detail/TiBase.hpp"
#include "TitaniumWindows/UI/TableViewRow.hpp"
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

			Titanium::UI::TableViewRow::setLayoutPolicy<WindowsViewLayoutPolicy>(this);
			layoutPolicy__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutPolicy__->set_defaultHeight(Titanium::UI::LAYOUT::SIZE);

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(content__);
		}

		void TableViewRow::JSExportInitialize() {
			JSExport<TableViewRow>::SetClassVersion(1);
			JSExport<TableViewRow>::SetParent(JSExport<Titanium::UI::TableViewRow>::Class());
		}

		void TableViewRow::add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (title__ != nullptr) {
				unsigned int index = -1;
				content__->Children->IndexOf(title__->getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent(), &index);
				if (index > -1) {
					content__->Children->RemoveAt(index);
				}
			}

			auto view_ptr = view.GetPrivate<Titanium::UI::View>();
			auto newView = std::dynamic_pointer_cast<TitaniumWindows::UI::WindowsViewLayoutPolicy>(view_ptr);
			auto nativeChildView = newView->getComponent();
			if (nativeChildView != nullptr) {
				content__->Children->Append(nativeChildView);
			}
			
			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->add(view_ptr);
		}

		void TableViewRow::setTitle(std::string title) TITANIUM_NOEXCEPT
		{
			if (title__ == nullptr && content__->Children->Size == 0) {

				JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
				TITANIUM_ASSERT(Titanium_property.IsObject());
				JSObject Titanium = static_cast<JSObject>(Titanium_property);

				JSValue UI_property = Titanium.GetProperty("UI");
				TITANIUM_ASSERT(UI_property.IsObject());
				JSObject UI = static_cast<JSObject>(UI_property);

				JSValue Label_property = UI.GetProperty("Label");
				TITANIUM_ASSERT(Label_property.IsObject());
				JSObject Label = static_cast<JSObject>(Label_property);

				auto label = Label.CallAsConstructor();
				title__ = label.GetPrivate<TitaniumWindows::UI::Label>();

				title__->set_text(title);
				content__->Children->Append(title__->getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent());
			}
			Titanium::UI::TableViewRow::setTitle(title);
		}
	}  // namespace UI
}  // namespace TitaniumWindows