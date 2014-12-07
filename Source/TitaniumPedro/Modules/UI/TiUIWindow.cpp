/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUIWindow.h"
#include <Windows.h>
#include "Modules/UI/TiUIView.h"
#include "TiCore/TiWebColor.h"
#include "TiCore/TiConstants.h"

static std::vector<Ti::UI::Window*> all_page_contents_;

ref class MyCanvas sealed : public Windows::UI::Xaml::Controls::Canvas
{
	/*
public:
	MyCanvas() : Windows::UI::Xaml::Controls::Canvas()
	{
		std::clog << "HERE" << std::endl;
	}
	virtual ~MyCanvas()
	{
		std::clog << "DEAD" << std::endl;
	}
	*/
};


namespace Ti {
	namespace UI {

		const JSStaticFunction Window::ClassMethods[] = {
				{ "setFlagSecure", _setFlagSecure, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setExitOnClose", _setExitOnClose, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setFullscreen", _setFullscreen, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setModal", _setModal, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setNavBarHidden", _setNavBarHidden, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getOrientation", _getOrientation, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setOrientationModes", _setOrientationModes, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setStatusBarStyle", _setStatusBarStyle, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "getToolbar", _getToolbar, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setTransitionAnimation", _setTransitionAnimation, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "close", _close, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "hideNavBar", _hideNavBar, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "showNavBar", _showNavBar, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "hideTabBar", _hideTabBar, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "open", _open, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ "setToolbar", _setToolbar, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
				{ 0, 0, 0 }
		};

		Window::Window(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) 
		{
			windows_content_ = ref new MyCanvas(); // Windows::UI::Xaml::Controls::Canvas();
			setComponent(windows_content_);
		}
		Ti::Value Window::eventAdded(const std::vector<Ti::Value>& arguments)
		{
			const auto eventName = arguments[0].toString();
			if (eventName == Ti::Constants::EventBackButton) {
				back_button_events_count_++;
			}
			return Ti::ViewProxy::eventAdded(arguments);
		}
		Ti::Value Window::eventRemoved(const std::vector<Ti::Value>& arguments) {
			const auto eventName = arguments[0].toString();
			if (eventName == Ti::Constants::EventBackButton) {
				back_button_events_count_--;
			}
			return Ti::ViewProxy::eventRemoved(arguments);
		}

		void Window::onComponentSizeChange(const Layout::Rect& rect)
		{
			if (layout_node_->parent) {
				ViewProxy::onComponentSizeChange(rect);
				return;
			}

			layout_node_->element.measuredHeight = rect.height;
			layout_node_->element.measuredWidth = rect.width;
			auto root = Ti::Layout::nodeRequestLayout(layout_node_);
			if (root) {
				Ti::Layout::nodeLayout(root);
			}

			// TODO: Check if EventPostLayout is set before creating this object
			Ti::Value val;
			val.setProperty("x", Ti::Value(rect.x));
			val.setProperty("y", Ti::Value(rect.y));
			val.setProperty("width", Ti::Value(rect.width));
			val.setProperty("height", Ti::Value(rect.height));
			fireEvent(Ti::Constants::EventPostLayout, val);
		}

		void Window::onLayoutEngineCallback(Layout::Rect rect, const std::string& name) 
		{
			// do nothing on window, unless is a child of something else
			if (layout_node_->parent) {
				ViewProxy::onLayoutEngineCallback(rect, name);
				return;
			}
		}

		// Boolean value indicating if the application should exit when the Android
		// Back button is pressed while the window is being shown.
		Ti::Value Window::setExitOnClose(const std::vector<Ti::Value>& arguments) {
			exit_on_close_ = arguments[0].toBool();
			return Ti::Value::Undefined();
		}

		// Treat the content of the window as secure, preventing it from
		// appearing in screenshots or from being viewed on non-secure
		// displays.
		Ti::Value Window::setFlagSecure(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setFlagSecure() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the fullscreen property.
		Ti::Value Window::setFullscreen(const std::vector<Ti::Value>& arguments) {
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
			
			auto statusBar = Windows::UI::ViewManagement::StatusBar::GetForCurrentView();
			arguments.at(0).toBool() ? statusBar->HideAsync() : statusBar->ShowAsync();
#endif
			OutputDebugString(L"[WARN] Window.setFullscreen() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the modal property.
		Ti::Value Window::setModal(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setModal() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the navBarHidden property.
		Ti::Value Window::setNavBarHidden(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setNavBarHidden() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Gets the value of the orientation property.
		Ti::Value Window::getOrientation(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.getOrientation() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the orientationModes property.
		Ti::Value Window::setOrientationModes(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setOrientationModes() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the statusBarStyle property.
		Ti::Value Window::setStatusBarStyle(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setStatusBarStyle() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Gets the value of the toolbar property.
		Ti::Value Window::getToolbar(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.getToolbar() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the value of the transitionAnimation property.
		Ti::Value Window::setTransitionAnimation(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setTransitionAnimation() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Opens the window.
		Ti::Value Window::open(const std::vector<Ti::Value>& arguments) {
			// Don't allow GC to get rid of this object, this is a window and must be alive until closed!
			if (PageManager::Open(this)) {
				self_ = get_shared_ptr_for_proxy();
			}


			return Ti::Value::Undefined();
		}
		// Closes the window.
		Ti::Value Window::close(const std::vector<Ti::Value>& arguments) {
			if (exit_on_close_) {
				// We need to suspend the app, not kill it
				// And this kills it, so we need to find a better way
				Windows::UI::Xaml::Application::Current->Exit();
			}
				// Unprotect this proxy and allow GC to do it's job
			if (PageManager::Close(this)) {
				self_ = nullptr;
			}
			return Ti::Value::Undefined();
		}

		// Hides the navigation bar.
		Ti::Value Window::hideNavBar(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.hideNavBar() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Hides the tab bar. Must be called before opening the window.
		Ti::Value Window::hideTabBar(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.hideTabBar() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Sets the array of items to show in the window's toolbar.
		Ti::Value Window::setToolbar(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.setToolbar() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}

		// Makes the navigation bar visible.
		Ti::Value Window::showNavBar(const std::vector<Ti::Value>& arguments) {
			OutputDebugString(L"[WARN] Window.showNavBar() not implemented yet. Returning Undefined\n");
			return Ti::Value::Undefined();
		}
	}
} // namespace Ti { namespace UI {
