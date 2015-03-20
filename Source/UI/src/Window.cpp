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
		Window::Window(const JSContext& js_context) TITANIUM_NOEXCEPT
  			: Titanium::UI::Window(js_context)
		{
		}

		void Window::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Window::postCallAsConstructor(js_context, arguments);	
			
			canvas__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::Window::setLayoutPolicy<WindowLayoutPolicy>();

			layoutPolicy__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutPolicy__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(canvas__);
		}

		void Window::close(const std::shared_ptr<Titanium::UI::CloseWindowParams>& params) const TITANIUM_NOEXCEPT
		{
			// FIXME How do we handle this? It should navigate to the next window/page in a stack...
			layoutPolicy__->hide();

			// See https://github.com/appcelerator/titanium_mobile_windows.bak/blob/master/Source/TitaniumPedro/Modules/UI/TiPageManager.cpp
			auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			if (rootFrame->CanGoBack) {
				// Since all the pages in the frame back stack are the same
				// type (Page::typeid) Just remove the first one
				rootFrame->BackStack->RemoveAt(0);
			} else {
				// This is the first and only window, remove it
				rootFrame->Content = nullptr;
				Windows::UI::Xaml::Application::Current->Exit();
			}
		}

		void Window::open(const std::shared_ptr<Titanium::UI::OpenWindowParams>& params) const TITANIUM_NOEXCEPT
		{
			auto rootFrame = dynamic_cast<Windows::UI::Xaml::Controls::Frame^>(Windows::UI::Xaml::Window::Current->Content);
			rootFrame->Navigate(Windows::UI::Xaml::Controls::Page::typeid);
			auto page = dynamic_cast<Windows::UI::Xaml::Controls::Page^>(rootFrame->Content);
			page->Content = canvas__;
		}

		void Window::JSExportInitialize()
		{
			JSExport<Window>::SetClassVersion(1);
			JSExport<Window>::SetParent(JSExport<Titanium::UI::Window>::Class());
		}

		void Window::set_fullscreen(const bool& fullscreen) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Window::set_fullscreen(fullscreen);
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
			auto statusBar = Windows::UI::ViewManagement::StatusBar::GetForCurrentView();
			fullscreen ? statusBar->HideAsync() : statusBar->ShowAsync();
#endif
		}

		WindowLayoutPolicy::WindowLayoutPolicy() TITANIUM_NOEXCEPT
			: WindowsViewLayoutPolicy()
		{
		}

		void WindowLayoutPolicy::onComponentSizeChange(const Titanium::LayoutEngine::Rect& rect)
		{
			if (layout_node__->parent) {
				WindowsViewLayoutPolicy::onComponentSizeChange(rect);
				return;
			}

			layout_node__->element.measuredHeight = rect.height;
			layout_node__->element.measuredWidth = rect.width;
			auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);
			if (root) {
				Titanium::LayoutEngine::nodeLayout(root);
			}

			// TODO: Check if EventPostLayout is set before creating this object
			/*
			Ti::Value val;
			val.setProperty("x", Ti::Value(rect.x));
			val.setProperty("y", Ti::Value(rect.y));
			val.setProperty("width", Ti::Value(rect.width));
			val.setProperty("height", Ti::Value(rect.height));
			fireEvent(Ti::Constants::EventPostLayout, val);
			*/
		}

		void WindowLayoutPolicy::onLayoutEngineCallback(Titanium::LayoutEngine::Rect rect, const std::string& name)
		{
			// We leave top level window alone unless the window is a child view
			if (layout_node__->parent) {
				WindowsViewLayoutPolicy::onLayoutEngineCallback(rect, name);
				return;
			}
		}
	} // namespace UI
} // namespace TitaniumWindows
