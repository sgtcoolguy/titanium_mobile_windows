/**
 * Windows Native Wrapper for Windows.UI.Xaml.DataTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.UI.Xaml.DataTemplate.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		DataTemplate::DataTemplate(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkTemplate(js_context)
		{
		}

		void DataTemplate::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::DataTemplate^ DataTemplate::unwrapWindows_UI_Xaml_DataTemplate() const
		{
			return dynamic_cast<::Windows::UI::Xaml::DataTemplate^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::DataTemplate^ DataTemplate::unwrap() const
		{
			return unwrapWindows_UI_Xaml_DataTemplate();
		}

		void DataTemplate::wrap(::Windows::UI::Xaml::DataTemplate^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void DataTemplate::JSExportInitialize()
		{
			JSExport<DataTemplate>::SetClassVersion(1);
			JSExport<DataTemplate>::SetParent(JSExport<Windows::UI::Xaml::FrameworkTemplate>::Class());

			TITANIUM_ADD_FUNCTION(DataTemplate, LoadContent);
		}

		TITANIUM_FUNCTION(DataTemplate, LoadContent)
		{
			auto context = get_context();
			auto method_result = unwrap()->LoadContent();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyObject>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyObject>();
			result_wrapper->wrap(method_result);


			return result; 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
