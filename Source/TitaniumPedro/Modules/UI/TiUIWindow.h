/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOW_H
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOW_H

#include "TiCore/TiViewProxy.h"
#include "Modules/UI/TiPageManager.h"

namespace Ti {
	namespace UI     {

		class Window final : public Ti::ViewProxy, public virtual_enable_shared_from_this<Window>
		{
			TI_CREATE_PROXY(Window);
			static JSClassRef Parent() {
				return Ti::ViewProxy::ClassDef();
			}

		public:

			virtual bool ignoreHeight() const { return true; }
			virtual bool ignoreWidth() const { return true; }
			virtual std::string defaultHeight() const { return Ti::Constants::SizeFILL; }
			virtual std::string defaultWidth() const { return Ti::Constants::SizeFILL; }
			virtual bool isWindow() const { return true; }
			// for the PageManager
			bool hasBackButtonEvent() const {
				return back_button_events_count_ > 0;
			}
			bool existsOnClose() const {
				return exit_on_close_;
			}
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments);

		protected:

			Window(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~Window() {
				// On GC, null out the Page
				windows_content_ = nullptr;
			}
			virtual void onComponentSizeChange(const Layout::Rect&);
			virtual void onLayoutEngineCallback(Layout::Rect rect, const std::string& name);
			
		private:
			Windows::UI::Xaml::Controls::Canvas^		windows_content_;
			int                                         back_button_events_count_{ 0 };
			bool                                        exit_on_close_{ false };
			std::string                                 title_;
			std::shared_ptr<Window>                     self_{ nullptr };


			// Boolean value indicating if the application should exit when the Android
			// Back button is pressed while the window is being shown.
			TI_CREATE_METHOD(Window, setExitOnClose);
			Ti::Value setExitOnClose(const std::vector<Ti::Value>& arguments);
			// Treat the content of the window as secure, preventing it from
			// appearing in screenshots or from being viewed on non-secure
			// displays.
			TI_CREATE_METHOD(Window, setFlagSecure);
			Ti::Value setFlagSecure(const std::vector<Ti::Value>& arguments);
			// Sets the value of the fullscreen property.
			TI_CREATE_METHOD(Window, setFullscreen);
			Ti::Value setFullscreen(const std::vector<Ti::Value>& arguments);
			// Sets the value of the modal property.
			TI_CREATE_METHOD(Window, setModal);
			Ti::Value setModal(const std::vector<Ti::Value>& arguments);
			// Sets the value of the navBarHidden property.
			TI_CREATE_METHOD(Window, setNavBarHidden);
			Ti::Value setNavBarHidden(const std::vector<Ti::Value>& arguments);
			// Gets the value of the orientation property.
			TI_CREATE_METHOD(Window, getOrientation);
			Ti::Value getOrientation(const std::vector<Ti::Value>& arguments);
			// Sets the value of the orientationModes property.
			TI_CREATE_METHOD(Window, setOrientationModes);
			Ti::Value setOrientationModes(const std::vector<Ti::Value>& arguments);
			// Sets the value of the statusBarStyle property.
			TI_CREATE_METHOD(Window, setStatusBarStyle);
			Ti::Value setStatusBarStyle(const std::vector<Ti::Value>& arguments);
			// Gets the value of the toolbar property.
			TI_CREATE_METHOD(Window, getToolbar);
			Ti::Value getToolbar(const std::vector<Ti::Value>& arguments);
			// Sets the value of the transitionAnimation property.
			TI_CREATE_METHOD(Window, setTransitionAnimation);
			Ti::Value setTransitionAnimation(const std::vector<Ti::Value>& arguments);
			// Closes the window.
			TI_CREATE_METHOD(Window, close);
			Ti::Value close(const std::vector<Ti::Value>& arguments);
			// Hides the navigation bar.
			TI_CREATE_METHOD(Window, hideNavBar);
			Ti::Value hideNavBar(const std::vector<Ti::Value>& arguments);
			// Hides the tab bar. Must be called before opening the window.
			TI_CREATE_METHOD(Window, hideTabBar);
			Ti::Value hideTabBar(const std::vector<Ti::Value>& arguments);
			// Opens the window.
			TI_CREATE_METHOD(Window, open);
			Ti::Value open(const std::vector<Ti::Value>& arguments);
			// Sets the array of items to show in the window's toolbar.
			TI_CREATE_METHOD(Window, setToolbar);
			Ti::Value setToolbar(const std::vector<Ti::Value>& arguments);
			// Makes the navigation bar visible.
			TI_CREATE_METHOD(Window, showNavBar);
			Ti::Value showNavBar(const std::vector<Ti::Value>& arguments);
		};

	}
} 

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWINDOW_H
