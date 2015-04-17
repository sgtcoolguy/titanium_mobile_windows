/**
 * Windows Native Wrapper for Windows.UI.Xaml.DataTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DataTemplate.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		DataTemplate::DataTemplate(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkTemplate(js_context, arguments)
		{
		}

		void DataTemplate::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::DataTemplate();
		}

		Windows::UI::Xaml::DataTemplate^ DataTemplate::unwrapWindows_UI_Xaml_DataTemplate()
		{
			return dynamic_cast<Windows::UI::Xaml::DataTemplate^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void DataTemplate::wrap(Windows::UI::Xaml::DataTemplate^ object)
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
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->LoadContent();
			return get_context().CreateBoolean(result); 
		}

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
