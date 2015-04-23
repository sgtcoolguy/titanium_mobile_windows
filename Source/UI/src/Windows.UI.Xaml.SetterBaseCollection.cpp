/**
 * Windows Native Wrapper for Windows.UI.Xaml.SetterBaseCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.UI.Xaml.SetterBase&gt;.hpp"
#include "Windows.UI.Xaml.SetterBase[].hpp"
#include "Windows.Foundation.Collections.IVectorView`1&lt;class Windows.UI.Xaml.SetterBase&gt;.hpp"
#include "Windows.UI.Xaml.SetterBase.hpp"
#include "Windows.UI.Xaml.SetterBaseCollection.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		SetterBaseCollection::SetterBaseCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void SetterBaseCollection::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::SetterBaseCollection^ SetterBaseCollection::unwrapWindows_UI_Xaml_SetterBaseCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::SetterBaseCollection^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::SetterBaseCollection^ SetterBaseCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_SetterBaseCollection();
		}

		void SetterBaseCollection::wrap(::Windows::UI::Xaml::SetterBaseCollection^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void SetterBaseCollection::JSExportInitialize()
		{
			JSExport<SetterBaseCollection>::SetClassVersion(1);
			JSExport<SetterBaseCollection>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(SetterBaseCollection, IsSealed);
			TITANIUM_ADD_PROPERTY_READONLY(SetterBaseCollection, Size);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, GetAt);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, GetView);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, SetAt);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, Append);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, Clear);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, GetMany);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(SetterBaseCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(SetterBaseCollection, IsSealed)
		{
			auto value = unwrap()->IsSealed;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(SetterBaseCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_FUNCTION(SetterBaseCollection, GetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto context = get_context();
			auto method_result = unwrap()->GetAt(index);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::SetterBase>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::SetterBase>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, GetView)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetView();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::SetterBase&gt;>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::SetterBase&gt;>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, IndexOf)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::SetterBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_SetterBase();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_index = static_cast<JSObject>(_1);
			auto wrapper_index = object_index.GetPrivate<uint32&amp;>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto index = wrapper_index->unwrapuint32&amp;();


			auto context = get_context();
			auto method_result = unwrap()->IndexOf(value, index);

 			auto result = context.CreateBoolean(method_result); 


			return result; 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, SetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::SetterBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_SetterBase();


			unwrap()->SetAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, InsertAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::SetterBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_SetterBase();


			unwrap()->InsertAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, RemoveAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			unwrap()->RemoveAt(index);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, Append)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::SetterBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_SetterBase();


			unwrap()->Append(value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, RemoveAtEnd)
		{
			unwrap()->RemoveAtEnd();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, Clear)
		{
			unwrap()->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, GetMany)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto startIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_1);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::SetterBase[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_SetterBase[]();


			auto context = get_context();
			auto method_result = unwrap()->GetMany(startIndex, items);

 			auto result = context.CreateNumber(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, ReplaceAll)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_0);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::SetterBase[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_SetterBase[]();


			unwrap()->ReplaceAll(items);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(SetterBaseCollection, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1&lt;class Windows::UI::Xaml::SetterBase&gt;>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1&lt;class Windows::UI::Xaml::SetterBase&gt;>();
			result_wrapper->wrap(method_result);


			return result; 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
