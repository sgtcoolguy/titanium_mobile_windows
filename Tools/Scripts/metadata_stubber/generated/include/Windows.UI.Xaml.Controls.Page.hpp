
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Page
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_
#define _WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_

#include "Windows.UI.Xaml.Controls.UserControl.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{


		using namespace HAL;

		class TITANIUMKIT_EXPORT Page : public Windows::UI::Xaml::Controls::UserControl, public JSExport<Page>
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

			Windows::UI::Xaml::Controls::Page^ unwrap(); // TODO If we're going to extend the class from parent, we need unique unwrap method names per type!
			void wrap(Windows::UI::Xaml::Controls::Page^ object);

		protected:
			Windows::UI::Xaml::Controls::Page^ wrapped__; // TODO If this extends some parent class, do we need _another_ wrapped__ field? Shouldn't we just use some cast on the wrap method from parent?
		};

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_CONTROLS_PAGE_HPP_
