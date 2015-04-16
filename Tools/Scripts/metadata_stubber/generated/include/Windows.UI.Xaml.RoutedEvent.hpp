/**
 * Windows Native Wrapper for Windows.UI.Xaml.RoutedEvent
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_
#define _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{


		using namespace HAL;

		class TITANIUMKIT_EXPORT RoutedEvent : public Titanium::Module, public JSExport<RoutedEvent>
		{

		public:


			RoutedEvent(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~RoutedEvent() = default;
			RoutedEvent(const RoutedEvent&) = default;
			RoutedEvent& operator=(const RoutedEvent&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			RoutedEvent(RoutedEvent&&)                 = default;
			RoutedEvent& operator=(RoutedEvent&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::RoutedEvent^ unwrapWindows_UI_Xaml_RoutedEvent();
			void wrap(Windows::UI::Xaml::RoutedEvent^ object);

		protected:
			Windows::UI::Xaml::RoutedEvent^ wrapped__;
		};

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_
