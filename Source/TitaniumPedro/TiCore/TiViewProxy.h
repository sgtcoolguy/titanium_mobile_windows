/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIVIEWPROXY_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIVIEWPROXY_H_

#include "Layout/TiLayout.h"
#include "TiCore/TiProxy.h"
#include "TiCore/TiWebColor.h"
#include "TiCore/TiConstants.h"

// This is the base class for all Views
namespace Ti {

	class ViewProxy : public Proxy, public virtual_enable_shared_from_this<ViewProxy>
	{
		TI_CREATE_PROXY(ViewProxy);

		static JSClassRef Parent() {
			return Ti::Proxy::ClassDef();
		}

	public:
		Layout::Node* layout_node_;
		// Default layout values
		// Used to assign the native component and get it back
		virtual Windows::UI::Xaml::FrameworkElement^ getComponent() const {
			assert(component_);
			return component_;
		}

		// These methods are required by the layout engine
		virtual void setComponent(Windows::UI::Xaml::FrameworkElement^ component);

		virtual Ti::Value eventAdded(const std::vector<Ti::Value>&) override;
		virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&) override;
		virtual void onLayoutEngineCallback(Layout::Rect rect, const std::string& name);

	protected:
		virtual bool ignoreHeight() const {
			return false;
		}

		virtual bool ignoreWidth() const {
			return false;
		}

		virtual std::string defaultHeight() const {
			return Ti::Constants::SizeSIZE;
		}

		virtual std::string defaultWidth() const {
			return Ti::Constants::SizeSIZE;
		}
		void setLayoutProperty(const Ti::Layout::ValueName&, const std::string&);

		explicit ViewProxy(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args) {
		}

		virtual ~ViewProxy();

		virtual void onComponentLoaded(const Layout::Rect&);
		virtual void onComponentSizeChange(const Layout::Rect&);
		virtual bool isWindow() const {
			return false;
		}
		virtual bool isLoaded() const {
			return is_loaded_;
		}

		TI_CREATE_METHOD(ViewProxy, setWidth);
		virtual Ti::Value setWidth(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setHeight);
		virtual Ti::Value setHeight(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setLeft);
		virtual Ti::Value setLeft(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setRight);
		virtual Ti::Value setRight(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setTop);
		virtual Ti::Value setTop(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setBottom);
		virtual Ti::Value setBottom(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setLayout);
		virtual Ti::Value setLayout(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setCenter);
		virtual Ti::Value setCenter(const std::vector<Ti::Value>& args);

		TI_CREATE_METHOD(ViewProxy, setBackgroundColor);
		virtual Ti::Value setBackgroundColor(const std::vector<Ti::Value>& args);
	private:
		Windows::Foundation::EventRegistrationToken size_change_event_;
		Windows::Foundation::EventRegistrationToken loaded_event_;

		bool is_width_size_{ false };
		bool is_height_size_{ false };
		bool is_panel_{ false };
		bool is_control_{ false };
		bool is_loaded_{ false };
		Layout::Rect oldRect;
		Windows::UI::Xaml::FrameworkElement^ component_{ nullptr };

		// Event handlers, store the variables for "addEvent" and "removeEvent"
		Windows::Foundation::EventRegistrationToken click_event_;
		unsigned int click_event_count_ { 0 };
		Windows::Foundation::EventRegistrationToken touch_start_event_;
		unsigned int touch_start_event_count_ { 0 };
		Windows::Foundation::EventRegistrationToken touch_end_event_;
		unsigned int touch_end_event_count_ { 0 };
		Windows::Foundation::EventRegistrationToken touch_move_event_;
		unsigned int touch_move_event_count_ { 0 };
		Windows::Foundation::EventRegistrationToken touch_cancel_event_;
		unsigned int touch_cancel_event_count_ { 0 };
		unsigned int post_layout_event_count_{ 0 };



		// Every Titanium View will have these methods
		TI_CREATE_METHOD(ViewProxy, getSize);
		Ti::Value getSize(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, getRect);
		Ti::Value getRect(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setColor);
		virtual Ti::Value setColor(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, show);
		virtual Ti::Value show(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, hide);
		virtual Ti::Value hide(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, addView);
		Ti::Value addView(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, removeView);
		Ti::Value removeView(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setBorderColor);
		Ti::Value setBorderColor(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, setBorderWidth);
		Ti::Value setBorderWidth(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(ViewProxy, toImage);
		Ti::Value toImage(const std::vector<Ti::Value>& args);
		
	};

} // namespace Ti

#endif	// _TITANIUM_MOBILE_WINDOWS_TICORE_TIVIEWPROXY_H_
