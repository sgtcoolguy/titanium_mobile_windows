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

		using namespace Windows::UI::Xaml::Controls;

		TabGroup::TabGroup(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::TabGroup(js_context)
		{
		}

		void TabGroup::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::TabGroup::postCallAsConstructor(js_context, arguments);	
			
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			// root Window object to make layout work
			window__ = js_context.CreateObject(JSExport<TitaniumWindows::UI::Window>::Class()).CallAsConstructor().GetPrivate<TitaniumWindows::UI::Window>();

			grid__  = ref new Grid();
			pivot__ = ref new Pivot();

			pivot__->SelectionChanged += ref new SelectionChangedEventHandler([this](Platform::Object^ sender, SelectionChangedEventArgs^ e) {
				TITANIUM_ASSERT(tabs__.size() > pivot__->SelectedIndex);
				set_activeTab(tabs__.at(pivot__->SelectedIndex), false);
			});

			grid__->Children->Append(pivot__);

			Titanium::UI::TabGroup::setLayoutDelegate<WindowsViewLayoutDelegate>();
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(grid__);

			window__->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->add(get_object().GetPrivate<Titanium::UI::View>());
#endif
		}

		void TabGroup::set_activeTab(const std::shared_ptr<Titanium::UI::Tab>& activeTab) TITANIUM_NOEXCEPT
		{
			set_activeTab(activeTab, true);
		}

		void TabGroup::set_activeTab(const std::shared_ptr<Titanium::UI::Tab>& activeTab, bool updateUI) TITANIUM_NOEXCEPT
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			if (updateUI && activeTab != activeTab__) {
				pivot__->SelectedItem = activeTab->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent();
			}
#endif
			Titanium::UI::TabGroup::set_activeTab(activeTab);
		}

		void TabGroup::open() TITANIUM_NOEXCEPT
		{
			window__->open(nullptr);
			Titanium::UI::TabGroup::open();
		}

		void TabGroup::close() TITANIUM_NOEXCEPT
		{
			Titanium::UI::TabGroup::close();
			window__->close(nullptr);
		}

		void TabGroup::addTab(const std::shared_ptr<Titanium::UI::Tab>& tab) TITANIUM_NOEXCEPT
		{
			Titanium::UI::TabGroup::addTab(tab);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			const auto windows_tab = dynamic_cast<TitaniumWindows::UI::Tab*>(tab.get());
			if (windows_tab) {
				pivot__->Items->Append(windows_tab->getViewLayoutDelegate<WindowsViewLayoutDelegate>()->getComponent());
			}
#endif
		}

		void TabGroup::JSExportInitialize() 
		{
			JSExport<TabGroup>::SetClassVersion(1);
			JSExport<TabGroup>::SetParent(JSExport<Titanium::UI::TabGroup>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows