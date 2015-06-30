/**
 * Titanium.UI.TabGroup for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/TabGroup.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/UI/Tab.hpp"
#include "TitaniumWindows/UI/Window.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		TabGroup::TabGroup(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TabGroup(js_context)
		{
		}

		void TabGroup::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TabGroup::postCallAsConstructor(js_context, arguments);	
			
			// root Window object to make layout work
			window__ = js_context.CreateObject(JSExport<TitaniumWindows::UI::Window>::Class()).CallAsConstructor().GetPrivate<TitaniumWindows::UI::Window>();

			grid__  = ref new Windows::UI::Xaml::Controls::Grid();
			pivot__ = ref new Windows::UI::Xaml::Controls::Pivot();

			grid__->Children->Append(pivot__);

			Titanium::UI::TabGroup::setLayoutDelegate<WindowsViewLayoutDelegate>();
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(grid__);

			window__->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->add(get_object().GetPrivate<Titanium::UI::View>());
		}

		void TabGroup::open() TITANIUM_NOEXCEPT
		{
			Titanium::UI::TabGroup::open();
			window__->open(nullptr);
		}

		void TabGroup::close() TITANIUM_NOEXCEPT
		{
			Titanium::UI::TabGroup::close();
			window__->close(nullptr);
		}

		void TabGroup::addTab(const std::shared_ptr<Titanium::UI::Tab>& tab) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TabGroup::addTab(tab);
			const auto windows_tab = dynamic_cast<TitaniumWindows::UI::Tab*>(tab.get());
			if (windows_tab) {
				pivot__->Items->Append(windows_tab->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent());
			}
		}

		void TabGroup::JSExportInitialize() 
		{
			JSExport<TabGroup>::SetClassVersion(1);
			JSExport<TabGroup>::SetParent(JSExport<Titanium::UI::TabGroup>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows