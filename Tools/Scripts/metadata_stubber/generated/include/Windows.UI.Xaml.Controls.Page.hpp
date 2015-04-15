
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Page
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_
#define _TITANIUM_WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		using namespace HAL;

		class TITANIUMKIT_EXPORT Page : public Module, public JSExport<Page>
		{

		public:
			TITANIUM_PROPERTY_DEF(TopAppBar);
				TITANIUM_PROPERTY_DEF(NavigationCacheMode);
				TITANIUM_PROPERTY_DEF(BottomAppBar);
				TITANIUM_PROPERTY_READONLY_DEF(Frame);
			TITANIUM_PROPERTY_READONLY_DEF(BottomAppBarProperty);
			TITANIUM_PROPERTY_READONLY_DEF(FrameProperty);
			TITANIUM_PROPERTY_READONLY_DEF(TopAppBarProperty);

			TITANIUM_FUNCTION_DEF(OnNavigatedFrom);
			TITANIUM_FUNCTION_DEF(OnNavigatedTo);
			TITANIUM_FUNCTION_DEF(OnNavigatingFrom);

			Page(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Page() = default;
			Page(const Page&) = default;
			Page& operator=(const Page&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Page(Page&&)                 = default;
			Page& operator=(Page&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Controls::Page^ unwrap();
			void wrap(Windows::UI::Xaml::Controls::Page^ object);

		private:
			Windows::UI::Xaml::Controls::Page^ wrapped__;
		};

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _TITANIUM_WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_
