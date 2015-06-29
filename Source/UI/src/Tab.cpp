/**
 * Titanium.UI.Tab for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/Tab.hpp"
#include "TitaniumWindows/UI/Window.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		Tab::Tab(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::Tab(js_context)
		{
		}

		void Tab::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Tab::postCallAsConstructor(js_context, arguments);	
			pivotItem__ = ref new Windows::UI::Xaml::Controls::PivotItem();
		}

		void Tab::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Tab::set_title(title);
			pivotItem__->Header = TitaniumWindows::Utility::ConvertUTF8String(title);
		}

		void Tab::set_window(const std::shared_ptr<Titanium::UI::Window>& window) TITANIUM_NOEXCEPT
		{
			if (window != window__) {
				const auto windows_window = dynamic_cast<TitaniumWindows::UI::Window*>(window.get());
				pivotItem__->Content = windows_window->getComponent();
			}

			Titanium::UI::Tab::set_window(window);
		}

		void Tab::JSExportInitialize() 
		{
			JSExport<Tab>::SetClassVersion(1);
			JSExport<Tab>::SetParent(JSExport<Titanium::UI::Tab>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows