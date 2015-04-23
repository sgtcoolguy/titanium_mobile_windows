/**
 * Windows Native Wrapper for Windows.UI.Xaml.PropertyPath
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.PropertyPath.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		PropertyPath::PropertyPath(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void PropertyPath::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::PropertyPath^ PropertyPath::unwrapWindows_UI_Xaml_PropertyPath() const
		{
			return dynamic_cast<::Windows::UI::Xaml::PropertyPath^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::PropertyPath^ PropertyPath::unwrap() const
		{
			return unwrapWindows_UI_Xaml_PropertyPath();
		}

		void PropertyPath::wrap(::Windows::UI::Xaml::PropertyPath^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void PropertyPath::JSExportInitialize()
		{
			JSExport<PropertyPath>::SetClassVersion(1);
			JSExport<PropertyPath>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(PropertyPath, Path);
		}

		TITANIUM_PROPERTY_GETTER(PropertyPath, Path)
		{
			auto value = unwrap()->Path;
			auto context = get_context();
 			auto result = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(value));

			return result;
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
