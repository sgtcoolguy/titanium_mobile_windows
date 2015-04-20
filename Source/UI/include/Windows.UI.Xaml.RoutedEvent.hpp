/**
 * Windows Native Wrapper for Windows.UI.Xaml.RoutedEvent
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_
#define _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{


		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT RoutedEvent : public Titanium::Module, public JSExport<RoutedEvent>
		{

		public:


			RoutedEvent(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~RoutedEvent() = default;
			RoutedEvent(const RoutedEvent&) = default;
			RoutedEvent& operator=(const RoutedEvent&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			RoutedEvent(RoutedEvent&&)                 = default;
			RoutedEvent& operator=(RoutedEvent&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			::Windows::UI::Xaml::RoutedEvent^ unwrapWindows_UI_Xaml_RoutedEvent() const;
			void wrap(::Windows::UI::Xaml::RoutedEvent^ object);

		protected:
			::Windows::UI::Xaml::RoutedEvent^ wrapped__;

		private:
			::Windows::UI::Xaml::RoutedEvent^ unwrap() const;

		};

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
#endif // _WINDOWS_UI_XAML_ROUTEDEVENT_HPP_
