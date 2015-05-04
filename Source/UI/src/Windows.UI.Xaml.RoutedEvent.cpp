/**
 * Windows Native Wrapper for Windows.UI.Xaml.RoutedEvent
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.RoutedEvent.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		RoutedEvent::RoutedEvent(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void RoutedEvent::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::RoutedEvent^ RoutedEvent::unwrapWindows_UI_Xaml_RoutedEvent() const
		{
			return dynamic_cast<::Windows::UI::Xaml::RoutedEvent^>(wrapped__);
		}

		::Windows::UI::Xaml::RoutedEvent^ RoutedEvent::unwrap() const
		{
			return unwrapWindows_UI_Xaml_RoutedEvent();
		}

		void RoutedEvent::wrap(::Windows::UI::Xaml::RoutedEvent^ object)
		{
			wrapped__ = object;
		}

		void RoutedEvent::JSExportInitialize()
		{
			JSExport<RoutedEvent>::SetClassVersion(1);
			JSExport<RoutedEvent>::SetParent(JSExport<Titanium::Platform::Object>::Class());

		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
