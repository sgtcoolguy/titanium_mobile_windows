/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.CacheMode
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.CacheMode.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Media
				{

		CacheMode::CacheMode(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void CacheMode::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::Media::CacheMode();
		}

		::Windows::UI::Xaml::Media::CacheMode^ CacheMode::unwrapWindows_UI_Xaml_Media_CacheMode() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::CacheMode^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Media::CacheMode^ CacheMode::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_CacheMode();
		}

		void CacheMode::wrap(::Windows::UI::Xaml::Media::CacheMode^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void CacheMode::JSExportInitialize()
		{
			JSExport<CacheMode>::SetClassVersion(1);
			JSExport<CacheMode>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
