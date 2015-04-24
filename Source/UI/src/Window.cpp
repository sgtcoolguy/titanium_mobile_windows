/**
 * Titanium.UI.Window for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/Window.hpp"
#include "TitaniumWindows/UI/View.hpp"
#include <windows.h>

namespace TitaniumWindows
{
	namespace UI
	{

		std::vector<std::shared_ptr<Window>> Window::window_stack__;

		Window::Window(const JSContext& js_context) TITANIUM_NOEXCEPT
  			: Titanium::UI::Window(js_context)
		{
		}

		void Window::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Window::postCallAsConstructor(js_context, arguments);	
			
			canvas__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::Window::setLayoutDelegate<WindowLayoutDelegate>();

			layoutDelegate__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(canvas__);
		}

		void Window::close(const std::shared_ptr<Titanium::UI::CloseWindowParams>& params) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Window::close(params);

			// Fire blur & close event on this window
			fireEvent("blur");
			fireEvent("close");

			// disable all events further because it doesn't make sense.
			disableEvents();

			auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			if (!get_exitOnClose() && window_stack__.size() > 1) {
				rootFrame->GoBack();
				window_stack__.pop_back();

				auto window = window_stack__.back();

				auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(rootFrame->Content);
				page->Content = window->getComponent();

				// reset bottom app bar
				page->BottomAppBar = nullptr;
				if (window->getBottomAppBar() != nullptr) {
					page->BottomAppBar = window->getBottomAppBar()->getComponent();
				}
			}
			else {
				// This is the first and only window, remove it
				rootFrame->Content = nullptr;
				window_stack__.clear();
				Windows::UI::Xaml::Application::Current->Exit();
			}
		}

		void Window::open(const std::shared_ptr<Titanium::UI::OpenWindowParams>& params) TITANIUM_NOEXCEPT
		{
			enableEvents();

			Titanium::UI::Window::open(params);

			auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			rootFrame->Navigate(Windows::UI::Xaml::Controls::Page::typeid);
			auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(rootFrame->Content);
			page->Content = canvas__;

			// reset bottom app bar
			page->BottomAppBar = nullptr;
			if (bottomAppBar__ != nullptr) {
				page->BottomAppBar = bottomAppBar__->getComponent();
			}

			if (window_stack__.size() > 0) {
				// Fire blur on the last window
				auto lastwin = window_stack__.back();
				lastwin->fireEvent("blur");
			}

			window_stack__.push_back(this->get_object().GetPrivate<Window>());

			// Fire open event on this window
			fireEvent("open");

			// Fire focus event on this window
			fireEvent("focus");
		}

		void Window::JSExportInitialize()
		{
			JSExport<Window>::SetClassVersion(1);
			JSExport<Window>::SetParent(JSExport<Titanium::UI::Window>::Class());
			TITANIUM_ADD_FUNCTION(Window, add);
		}

		TITANIUM_FUNCTION(Window, add) 
		{
			ENSURE_OBJECT_AT_INDEX(viewObj, 0);

			// check if it's command bar
			const auto commandBar = viewObj.GetPrivate<TitaniumWindows::UI::WindowsXaml::CommandBar>();
			if (commandBar == nullptr) {
				// delegate to parent
				return Titanium::UI::Window::js_add(arguments, this_object);
			}

			// TODO: assuming bottom bar here...but Windows app accepts both top and bottom.
			bottomAppBar__ = commandBar;

			const auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			const auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(rootFrame->Content);
			if (page != nullptr) {
				page->BottomAppBar = commandBar->getComponent();
			}

			return get_context().CreateUndefined();
		}

		void Window::set_fullscreen(const bool& fullscreen) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Window::set_fullscreen(fullscreen);
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
			auto statusBar = Windows::UI::ViewManagement::StatusBar::GetForCurrentView();
			fullscreen ? statusBar->HideAsync() : statusBar->ShowAsync();
#endif
		}

		WindowLayoutDelegate::WindowLayoutDelegate() TITANIUM_NOEXCEPT
			: WindowsViewLayoutDelegate()
		{
			
		}

		void WindowLayoutDelegate::onComponentSizeChange(const Titanium::LayoutEngine::Rect& rect)
		{
			if (layout_node__->parent) {
				WindowsViewLayoutDelegate::onComponentSizeChange(rect);
				return;
			}

			layout_node__->element.measuredHeight = rect.height;
			layout_node__->element.measuredWidth = rect.width;

			requestLayout(true);
		}

		void WindowLayoutDelegate::onLayoutEngineCallback(Titanium::LayoutEngine::Rect rect, const std::string& name)
		{
			// We leave top level window alone unless the window is a child view
			if (layout_node__->parent) {
				WindowsViewLayoutDelegate::onLayoutEngineCallback(rect, name);
				return;
			}
			oldRect__ = Titanium::LayoutEngine::RectMake(rect.x, rect.y, rect.width, rect.height);
		}
	} // namespace UI
} // namespace TitaniumWindows
