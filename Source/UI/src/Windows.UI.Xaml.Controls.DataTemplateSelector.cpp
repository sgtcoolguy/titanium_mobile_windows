/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.DataTemplateSelector
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyObject.hpp"
#include "Windows.UI.Xaml.DataTemplate.hpp"
#include "Windows.UI.Xaml.Controls.DataTemplateSelector.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{

		DataTemplateSelector::DataTemplateSelector(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void DataTemplateSelector::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::DataTemplateSelector^ DataTemplateSelector::unwrapWindows_UI_Xaml_Controls_DataTemplateSelector() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::DataTemplateSelector^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Controls::DataTemplateSelector^ DataTemplateSelector::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_DataTemplateSelector();
		}

		void DataTemplateSelector::wrap(::Windows::UI::Xaml::Controls::DataTemplateSelector^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void DataTemplateSelector::JSExportInitialize()
		{
			JSExport<DataTemplateSelector>::SetClassVersion(1);
			JSExport<DataTemplateSelector>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_FUNCTION(DataTemplateSelector, SelectTemplate);
			TITANIUM_ADD_FUNCTION(DataTemplateSelector, SelectTemplate);
		}

		TITANIUM_FUNCTION(DataTemplateSelector, SelectTemplate)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_item = static_cast<JSObject>(_0);
			auto wrapper_item = object_item.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto item = wrapper_item->unwrapTitanium_Module();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_container = static_cast<JSObject>(_1);
			auto wrapper_container = object_container.GetPrivate<Windows::UI::Xaml::DependencyObject>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto container = wrapper_container->unwrapWindows_UI_Xaml_DependencyObject();


			auto context = get_context();
			auto method_result = unwrap()->SelectTemplate(item, container);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(DataTemplateSelector, SelectTemplate)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_item = static_cast<JSObject>(_0);
			auto wrapper_item = object_item.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto item = wrapper_item->unwrapTitanium_Module();


			auto context = get_context();
			auto method_result = unwrap()->SelectTemplate(item);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DataTemplate>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DataTemplate>();
			result_wrapper->wrap(method_result);


			return result; 
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
