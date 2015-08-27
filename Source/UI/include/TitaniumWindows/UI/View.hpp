/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UI_VIEW_HPP_
#define _TITANIUMWINDOWS_UI_VIEW_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/View.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.View implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT View final : public Titanium::UI::View, public JSExport<View>
		{

		public:
			View(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~View();
			View(const View&) = default;
			View& operator=(const View&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			View(View&&) = default;
			View& operator=(View&&) = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;
			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

			virtual JSValue js_add(const std::vector<JSValue>& arguments, JSObject& this_object) override final;
			virtual void registerNativeUIWrapHook(std::function<JSObject(const JSContext&, const JSObject&)> requireCallback);

			virtual Windows::UI::Xaml::FrameworkElement^ getComponent() TITANIUM_NOEXCEPT;

#pragma warning(push)
#pragma warning(disable : 4251)
			std::function<JSObject(const JSContext&, const JSObject&)> native_wrapper_hook__;
#pragma warning(pop)

		private:

			void firePositionEvent(const std::string& event_name, Windows::UI::Xaml::FrameworkElement^ sender, Windows::Foundation::Point position);

			Windows::UI::Xaml::Controls::Canvas^ canvas__;

			// Event handlers
			Windows::Foundation::EventRegistrationToken click_event__;
			Windows::Foundation::EventRegistrationToken doubleclick_event__;
			Windows::Foundation::EventRegistrationToken focus_event__;
			Windows::Foundation::EventRegistrationToken touchstart_event__;
			Windows::Foundation::EventRegistrationToken touchend_event__;
			Windows::Foundation::EventRegistrationToken touchmove_event__;
			Windows::Foundation::EventRegistrationToken singletap_event__;
			Windows::Foundation::EventRegistrationToken doubletap_event__;
			Windows::Foundation::EventRegistrationToken longpress_event__;
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_VIEW_HPP_
