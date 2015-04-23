/**
 * Windows Native Wrapper for Windows.UI.Xaml.PropertyMetadata
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.PropertyChangedCallback.hpp"
#include "Windows.UI.Xaml.CreateDefaultValueCallback.hpp"
#include "Windows.UI.Xaml.PropertyMetadata.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		PropertyMetadata::PropertyMetadata(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void PropertyMetadata::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::PropertyMetadata^ PropertyMetadata::unwrapWindows_UI_Xaml_PropertyMetadata() const
		{
			return dynamic_cast<::Windows::UI::Xaml::PropertyMetadata^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::PropertyMetadata^ PropertyMetadata::unwrap() const
		{
			return unwrapWindows_UI_Xaml_PropertyMetadata();
		}

		void PropertyMetadata::wrap(::Windows::UI::Xaml::PropertyMetadata^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void PropertyMetadata::JSExportInitialize()
		{
			JSExport<PropertyMetadata>::SetClassVersion(1);
			JSExport<PropertyMetadata>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(PropertyMetadata, CreateDefaultValueCallback);
			TITANIUM_ADD_PROPERTY_READONLY(PropertyMetadata, DefaultValue);
			TITANIUM_ADD_FUNCTION(PropertyMetadata, Create);
			TITANIUM_ADD_FUNCTION(PropertyMetadata, Create);
			TITANIUM_ADD_FUNCTION(PropertyMetadata, Create);
			TITANIUM_ADD_FUNCTION(PropertyMetadata, Create);
		}

		TITANIUM_PROPERTY_GETTER(PropertyMetadata, CreateDefaultValueCallback)
		{
			auto value = unwrap()->CreateDefaultValueCallback;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::CreateDefaultValueCallback>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::CreateDefaultValueCallback>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(PropertyMetadata, DefaultValue)
		{
			auto value = unwrap()->DefaultValue;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(PropertyMetadata, Create)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_defaultValue = static_cast<JSObject>(_0);
			auto wrapper_defaultValue = object_defaultValue.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto defaultValue = wrapper_defaultValue->unwrapTitanium_Module();


			auto context = get_context();
			auto method_result = unwrap()->Create(defaultValue);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::PropertyMetadata>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(PropertyMetadata, Create)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_defaultValue = static_cast<JSObject>(_0);
			auto wrapper_defaultValue = object_defaultValue.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto defaultValue = wrapper_defaultValue->unwrapTitanium_Module();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_propertyChangedCallback = static_cast<JSObject>(_1);
			auto wrapper_propertyChangedCallback = object_propertyChangedCallback.GetPrivate<Windows::UI::Xaml::PropertyChangedCallback>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto propertyChangedCallback = wrapper_propertyChangedCallback->unwrapWindows_UI_Xaml_PropertyChangedCallback();


			auto context = get_context();
			auto method_result = unwrap()->Create(defaultValue, propertyChangedCallback);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::PropertyMetadata>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(PropertyMetadata, Create)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_createDefaultValueCallback = static_cast<JSObject>(_0);
			auto wrapper_createDefaultValueCallback = object_createDefaultValueCallback.GetPrivate<Windows::UI::Xaml::CreateDefaultValueCallback>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto createDefaultValueCallback = wrapper_createDefaultValueCallback->unwrapWindows_UI_Xaml_CreateDefaultValueCallback();


			auto context = get_context();
			auto method_result = unwrap()->Create(createDefaultValueCallback);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::PropertyMetadata>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(PropertyMetadata, Create)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_createDefaultValueCallback = static_cast<JSObject>(_0);
			auto wrapper_createDefaultValueCallback = object_createDefaultValueCallback.GetPrivate<Windows::UI::Xaml::CreateDefaultValueCallback>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto createDefaultValueCallback = wrapper_createDefaultValueCallback->unwrapWindows_UI_Xaml_CreateDefaultValueCallback();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_propertyChangedCallback = static_cast<JSObject>(_1);
			auto wrapper_propertyChangedCallback = object_propertyChangedCallback.GetPrivate<Windows::UI::Xaml::PropertyChangedCallback>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto propertyChangedCallback = wrapper_propertyChangedCallback->unwrapWindows_UI_Xaml_PropertyChangedCallback();


			auto context = get_context();
			auto method_result = unwrap()->Create(createDefaultValueCallback, propertyChangedCallback);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::PropertyMetadata>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			result_wrapper->wrap(method_result);


			return result; 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
