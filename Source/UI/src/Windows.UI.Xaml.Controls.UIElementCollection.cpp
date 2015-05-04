/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.UIElementCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.UI.Xaml.UIElement&gt;.hpp"
#include "Windows.UI.Xaml.UIElement[].hpp"
#include "Windows.Foundation.Collections.IVectorView`1&lt;class Windows.UI.Xaml.UIElement&gt;.hpp"
#include "Windows.UI.Xaml.UIElement.hpp"
#include "Windows.UI.Xaml.Controls.UIElementCollection.hpp"

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

		UIElementCollection::UIElementCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void UIElementCollection::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::UIElementCollection^ UIElementCollection::unwrapWindows_UI_Xaml_Controls_UIElementCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::UIElementCollection^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::UIElementCollection^ UIElementCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_UIElementCollection();
		}

		void UIElementCollection::wrap(::Windows::UI::Xaml::Controls::UIElementCollection^ object)
		{
			wrapped__ = object;
		}

		void UIElementCollection::JSExportInitialize()
		{
			JSExport<UIElementCollection>::SetClassVersion(1);
			JSExport<UIElementCollection>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(UIElementCollection, Size);
			TITANIUM_ADD_FUNCTION(UIElementCollection, GetAt);
			TITANIUM_ADD_FUNCTION(UIElementCollection, GetView);
			TITANIUM_ADD_FUNCTION(UIElementCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(UIElementCollection, SetAt);
			TITANIUM_ADD_FUNCTION(UIElementCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(UIElementCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(UIElementCollection, Append);
			TITANIUM_ADD_FUNCTION(UIElementCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(UIElementCollection, Clear);
			TITANIUM_ADD_FUNCTION(UIElementCollection, GetMany);
			TITANIUM_ADD_FUNCTION(UIElementCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(UIElementCollection, First);
			TITANIUM_ADD_FUNCTION(UIElementCollection, Move);
		}

		TITANIUM_PROPERTY_GETTER(UIElementCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, GetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto context = get_context();
			auto method_result = unwrap()->GetAt(index);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::UIElement>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::UIElement>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, GetView)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetView();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVectorView`1<class Windows::UI::Xaml::UIElement>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVectorView`1<class Windows::UI::Xaml::UIElement>>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, IndexOf)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_UIElement();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_1);


			auto context = get_context();
			auto method_result = unwrap()->IndexOf(value, &index);

 			auto result = context.CreateBoolean(method_result); 

			_0 = _0.get_context().CreateNumber(index);
			_1 = _1.get_context().CreateNumber(index);
			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, SetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_UIElement();


			unwrap()->SetAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, InsertAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_UIElement();


			unwrap()->InsertAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, RemoveAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			unwrap()->RemoveAt(index);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, Append)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_UIElement();


			unwrap()->Append(value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, RemoveAtEnd)
		{
			unwrap()->RemoveAtEnd();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, Clear)
		{
			unwrap()->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, GetMany)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto startIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_1);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::UIElement[>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_UIElement[();


			auto context = get_context();
			auto method_result = unwrap()->GetMany(startIndex, &items);

 			auto result = context.CreateNumber(method_result);

			_0 = _0.get_context().CreateNumber(items);
			_1 = _1.get_context().CreateNumber(items);
			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, ReplaceAll)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_0);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::UIElement[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_UIElement[]();


			unwrap()->ReplaceAll(items);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(UIElementCollection, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1<class Windows::UI::Xaml::UIElement>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1<class Windows::UI::Xaml::UIElement>>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(UIElementCollection, Move)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto oldIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto newIndex = static_cast<uint32_t>(_1);


			unwrap()->Move(oldIndex, newIndex);
			return get_context().CreateUndefined(); 
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
