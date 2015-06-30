/**
 * Titanium.UI.Tab for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/Tab.hpp"
#include "TitaniumWindows/UI/Window.hpp"
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
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			Titanium::UI::Tab::postCallAsConstructor(js_context, arguments);	
			pivotItem__ = ref new Windows::UI::Xaml::Controls::PivotItem();

			Titanium::UI::Tab::setLayoutDelegate<WindowsViewLayoutDelegate>();
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(pivotItem__);
#endif
		}

		void Tab::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Tab::set_title(title);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			pivotItem__->Header = TitaniumWindows::Utility::ConvertUTF8String(title);
#endif
		}

		void Tab::set_window(const std::shared_ptr<Titanium::UI::Window>& window) TITANIUM_NOEXCEPT
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			if (window != window__) {
				const auto windows_window = dynamic_cast<TitaniumWindows::UI::Window*>(window.get());
				pivotItem__->Content = windows_window->getComponent();
			}
#endif
			Titanium::UI::Tab::set_window(window);
		}

		void Tab::JSExportInitialize() 
		{
			JSExport<Tab>::SetClassVersion(1);
			JSExport<Tab>::SetParent(JSExport<Titanium::UI::Tab>::Class());
		}

	}  // namespace UI
}  // namespace TitaniumWindows