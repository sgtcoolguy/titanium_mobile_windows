/**
 * Titanium.UI.Tab for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_TAB_HPP_
#define _TITANIUMWINDOWS_TAB_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/Tab.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.Tab implementation for Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT Tab final : public Titanium::UI::Tab, public JSExport<Tab>
		{

		public:
			Tab(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~Tab()                  = default;
			Tab(const Tab&)            = default;
			Tab& operator=(const Tab&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Tab(Tab&&)                 = default;
			Tab& operator=(Tab&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;
			virtual void set_title(const std::string& title) TITANIUM_NOEXCEPT override;
			virtual void set_window(const std::shared_ptr<Titanium::UI::Window>& window) TITANIUM_NOEXCEPT override;

		private:
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			Windows::UI::Xaml::Controls::PivotItem^ pivotItem__;
#endif
		};
	}  // namespace UI
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_TAB_HPP_