/**
 * Windows Native Wrapper for Windows.UI.Xaml.ResourceDictionary
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.Foundation.Collections.IKeyValuePair`2&lt;object,object&gt;&gt;.hpp"
#include "Windows.Foundation.Collections.IMapView`2&lt;object,object&gt;.hpp"
#include "Windows.Foundation.Collections.IMap`2&lt;object,object&gt;.hpp"
#include "Windows.Foundation.Collections.IVector`1&lt;class Windows.UI.Xaml.ResourceDictionary&gt;.hpp"
#include "Windows.Foundation.Uri.hpp"
#include "Windows.UI.Xaml.ResourceDictionary.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		ResourceDictionary::ResourceDictionary(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void ResourceDictionary::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::ResourceDictionary^ ResourceDictionary::unwrapWindows_UI_Xaml_ResourceDictionary() const
		{
			return dynamic_cast<::Windows::UI::Xaml::ResourceDictionary^>(wrapped__);
		}

		::Windows::UI::Xaml::ResourceDictionary^ ResourceDictionary::unwrap() const
		{
			return unwrapWindows_UI_Xaml_ResourceDictionary();
		}

		void ResourceDictionary::wrap(::Windows::UI::Xaml::ResourceDictionary^ object)
		{
			wrapped__ = object;
		}

		void ResourceDictionary::JSExportInitialize()
		{
			JSExport<ResourceDictionary>::SetClassVersion(1);
			JSExport<ResourceDictionary>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(ResourceDictionary, Size);
			TITANIUM_ADD_PROPERTY(ResourceDictionary, Source);
			TITANIUM_ADD_PROPERTY_READONLY(ResourceDictionary, MergedDictionaries);
			TITANIUM_ADD_PROPERTY_READONLY(ResourceDictionary, ThemeDictionaries);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, Lookup);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, HasKey);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, GetView);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, Insert);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, Remove);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, Clear);
			TITANIUM_ADD_FUNCTION(ResourceDictionary, First);
		}

		TITANIUM_PROPERTY_GETTER(ResourceDictionary, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_PROPERTY_SETTER(ResourceDictionary, Source)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::Foundation::Uri>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_Foundation_Uri();


			unwrap()->Source = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ResourceDictionary, Source)
		{
			auto value = unwrap()->Source;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Uri>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Uri>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ResourceDictionary, MergedDictionaries)
		{
			auto value = unwrap()->MergedDictionaries;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::ResourceDictionary>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVector`1<class Windows::UI::Xaml::ResourceDictionary>>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(ResourceDictionary, ThemeDictionaries)
		{
			auto value = unwrap()->ThemeDictionaries;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IMap`2<object,object>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IMap`2<object,object>>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(ResourceDictionary, Lookup)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_key = static_cast<JSObject>(_0);
			auto wrapper_key = object_key.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto key = wrapper_key->unwrapPlatform_Object();


			auto context = get_context();
			auto method_result = unwrap()->Lookup(key);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(ResourceDictionary, HasKey)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_key = static_cast<JSObject>(_0);
			auto wrapper_key = object_key.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto key = wrapper_key->unwrapPlatform_Object();


			auto context = get_context();
			auto method_result = unwrap()->HasKey(key);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

		TITANIUM_FUNCTION(ResourceDictionary, GetView)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetView();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IMapView`2<object,object>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IMapView`2<object,object>>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(ResourceDictionary, Insert)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_key = static_cast<JSObject>(_0);
			auto wrapper_key = object_key.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto key = wrapper_key->unwrapPlatform_Object();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapPlatform_Object();


			auto context = get_context();
			auto method_result = unwrap()->Insert(key, value);

 			auto result = context.CreateBoolean(method_result); 

			return result;
		}

		TITANIUM_FUNCTION(ResourceDictionary, Remove)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_key = static_cast<JSObject>(_0);
			auto wrapper_key = object_key.GetPrivate<Platform::Object>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto key = wrapper_key->unwrapPlatform_Object();


			unwrap()->Remove(key);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(ResourceDictionary, Clear)
		{
			unwrap()->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(ResourceDictionary, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1<class Windows::Foundation::Collections::IKeyValuePair`2<object,object>>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1<class Windows::Foundation::Collections::IKeyValuePair`2<object,object>>>();
			result_wrapper->wrap(method_result);

			return result;
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
