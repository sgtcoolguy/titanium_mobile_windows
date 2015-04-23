/**
 * Windows Native Wrapper for Windows.UI.Xaml.TriggerCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.UI.Xaml.TriggerBase&gt;.hpp"
#include "Windows.UI.Xaml.TriggerBase[].hpp"
#include "Windows.Foundation.Collections.IVectorView`1&lt;class Windows.UI.Xaml.TriggerBase&gt;.hpp"
#include "Windows.UI.Xaml.TriggerBase.hpp"
#include "Windows.UI.Xaml.TriggerCollection.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		TriggerCollection::TriggerCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void TriggerCollection::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::TriggerCollection^ TriggerCollection::unwrapWindows_UI_Xaml_TriggerCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::TriggerCollection^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::TriggerCollection^ TriggerCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_TriggerCollection();
		}

		void TriggerCollection::wrap(::Windows::UI::Xaml::TriggerCollection^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void TriggerCollection::JSExportInitialize()
		{
			JSExport<TriggerCollection>::SetClassVersion(1);
			JSExport<TriggerCollection>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TriggerCollection, Size);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetView);
			TITANIUM_ADD_FUNCTION(TriggerCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(TriggerCollection, SetAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(TriggerCollection, Append);
			TITANIUM_ADD_FUNCTION(TriggerCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(TriggerCollection, Clear);
			TITANIUM_ADD_FUNCTION(TriggerCollection, GetMany);
			TITANIUM_ADD_FUNCTION(TriggerCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(TriggerCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(TriggerCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_FUNCTION(TriggerCollection, GetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto context = get_context();
			auto method_result = unwrap()->GetAt(index);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::TriggerBase>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(TriggerCollection, GetView)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetView();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::TriggerBase&gt;>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVectorView`1&lt;class Windows::UI::Xaml::TriggerBase&gt;>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(TriggerCollection, IndexOf)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();


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

		TITANIUM_FUNCTION(TriggerCollection, SetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();


			unwrap()->SetAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, InsertAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();


			unwrap()->InsertAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, RemoveAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			unwrap()->RemoveAt(index);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, Append)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::TriggerBase>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_TriggerBase();


			unwrap()->Append(value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, RemoveAtEnd)
		{
			unwrap()->RemoveAtEnd();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, Clear)
		{
			unwrap()->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, GetMany)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto startIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_1);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::TriggerBase[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_TriggerBase[]();


			auto context = get_context();
			auto method_result = unwrap()->GetMany(startIndex, items);

 			auto result = context.CreateNumber(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(TriggerCollection, ReplaceAll)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_0);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::TriggerBase[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_TriggerBase[]();


			unwrap()->ReplaceAll(items);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TriggerCollection, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1&lt;class Windows::UI::Xaml::TriggerBase&gt;>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1&lt;class Windows::UI::Xaml::TriggerBase&gt;>();
			result_wrapper->wrap(method_result);


			return result; 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
