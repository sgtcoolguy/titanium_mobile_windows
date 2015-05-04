/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.Animation.TransitionCollection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IIterator`1&lt;class Windows.UI.Xaml.Media.Animation.Transition&gt;.hpp"
#include "Windows.UI.Xaml.Media.Animation.Transition[].hpp"
#include "Windows.Foundation.Collections.IVectorView`1&lt;class Windows.UI.Xaml.Media.Animation.Transition&gt;.hpp"
#include "Windows.UI.Xaml.Media.Animation.Transition.hpp"
#include "Windows.UI.Xaml.Media.Animation.TransitionCollection.hpp"

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
					namespace Animation
					{

		TransitionCollection::TransitionCollection(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void TransitionCollection::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Media::Animation::TransitionCollection^ TransitionCollection::unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::Animation::TransitionCollection^>(wrapped__);
		}

		::Windows::UI::Xaml::Media::Animation::TransitionCollection^ TransitionCollection::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_Animation_TransitionCollection();
		}

		void TransitionCollection::wrap(::Windows::UI::Xaml::Media::Animation::TransitionCollection^ object)
		{
			wrapped__ = object;
		}

		void TransitionCollection::JSExportInitialize()
		{
			JSExport<TransitionCollection>::SetClassVersion(1);
			JSExport<TransitionCollection>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TransitionCollection, Size);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetView);
			TITANIUM_ADD_FUNCTION(TransitionCollection, IndexOf);
			TITANIUM_ADD_FUNCTION(TransitionCollection, SetAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, InsertAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAt);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Append);
			TITANIUM_ADD_FUNCTION(TransitionCollection, RemoveAtEnd);
			TITANIUM_ADD_FUNCTION(TransitionCollection, Clear);
			TITANIUM_ADD_FUNCTION(TransitionCollection, GetMany);
			TITANIUM_ADD_FUNCTION(TransitionCollection, ReplaceAll);
			TITANIUM_ADD_FUNCTION(TransitionCollection, First);
		}

		TITANIUM_PROPERTY_GETTER(TransitionCollection, Size)
		{
			auto value = unwrap()->Size;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

		TITANIUM_FUNCTION(TransitionCollection, GetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto context = get_context();
			auto method_result = unwrap()->GetAt(index);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Animation::Transition>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(TransitionCollection, GetView)
		{
			auto context = get_context();
			auto method_result = unwrap()->GetView();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IVectorView`1<class Windows::UI::Xaml::Media::Animation::Transition>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IVectorView`1<class Windows::UI::Xaml::Media::Animation::Transition>>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(TransitionCollection, IndexOf)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();


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

		TITANIUM_FUNCTION(TransitionCollection, SetAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();


			unwrap()->SetAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, InsertAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();


			unwrap()->InsertAt(index, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAt)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto index = static_cast<uint32_t>(_0);


			unwrap()->RemoveAt(index);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Append)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Media_Animation_Transition();


			unwrap()->Append(value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, RemoveAtEnd)
		{
			unwrap()->RemoveAtEnd();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, Clear)
		{
			unwrap()->Clear();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, GetMany)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsNumber(), "Expected Number");
			auto startIndex = static_cast<uint32_t>(_0);


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_1);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition[>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_Media_Animation_Transition[();


			auto context = get_context();
			auto method_result = unwrap()->GetMany(startIndex, &items);

 			auto result = context.CreateNumber(method_result);

			_0 = _0.get_context().CreateNumber(items);
			_1 = _1.get_context().CreateNumber(items);
			return result;
		}

		TITANIUM_FUNCTION(TransitionCollection, ReplaceAll)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_items = static_cast<JSObject>(_0);
			auto wrapper_items = object_items.GetPrivate<Windows::UI::Xaml::Media::Animation::Transition[]>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto items = wrapper_items->unwrapWindows_UI_Xaml_Media_Animation_Transition[]();


			unwrap()->ReplaceAll(items);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(TransitionCollection, First)
		{
			auto context = get_context();
			auto method_result = unwrap()->First();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::Foundation::Collections::IIterator`1<class Windows::UI::Xaml::Media::Animation::Transition>>::Class());
			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IIterator`1<class Windows::UI::Xaml::Media::Animation::Transition>>();
			result_wrapper->wrap(method_result);

			return result;
		}

					} // namespace Animation
				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
