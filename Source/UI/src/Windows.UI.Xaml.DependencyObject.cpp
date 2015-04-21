/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyObject
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Core.CoreDispatcher.hpp"
#include "Windows.UI.Xaml.DependencyObject.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		DependencyObject::DependencyObject(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void DependencyObject::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::DependencyObject^ DependencyObject::unwrapWindows_UI_Xaml_DependencyObject() const
		{
			return dynamic_cast<::Windows::UI::Xaml::DependencyObject^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::DependencyObject^ DependencyObject::unwrap() const
		{
			return unwrapWindows_UI_Xaml_DependencyObject();
		}

		void DependencyObject::wrap(::Windows::UI::Xaml::DependencyObject^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void DependencyObject::JSExportInitialize()
		{
			JSExport<DependencyObject>::SetClassVersion(1);
			JSExport<DependencyObject>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(DependencyObject, Dispatcher);
			TITANIUM_ADD_FUNCTION(DependencyObject, GetValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, SetValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, ClearValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, ReadLocalValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, GetAnimationBaseValue);
		}

		TITANIUM_PROPERTY_GETTER(DependencyObject, Dispatcher)
		{
			auto value = unwrap()->Dispatcher;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(DependencyObject, GetValue)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_dp = static_cast<JSObject>(_0);
			auto wrapper_dp = object_dp.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto dp = wrapper_dp->unwrapWindows_UI_Xaml_DependencyProperty();


			auto context = get_context();
			auto method_result = unwrap()->GetValue(dp);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(DependencyObject, SetValue)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_dp = static_cast<JSObject>(_0);
			auto wrapper_dp = object_dp.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto dp = wrapper_dp->unwrapWindows_UI_Xaml_DependencyProperty();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_1);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			unwrap()->SetValue(dp, value);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(DependencyObject, ClearValue)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_dp = static_cast<JSObject>(_0);
			auto wrapper_dp = object_dp.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto dp = wrapper_dp->unwrapWindows_UI_Xaml_DependencyProperty();


			unwrap()->ClearValue(dp);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(DependencyObject, ReadLocalValue)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_dp = static_cast<JSObject>(_0);
			auto wrapper_dp = object_dp.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto dp = wrapper_dp->unwrapWindows_UI_Xaml_DependencyProperty();


			auto context = get_context();
			auto method_result = unwrap()->ReadLocalValue(dp);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(DependencyObject, GetAnimationBaseValue)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_dp = static_cast<JSObject>(_0);
			auto wrapper_dp = object_dp.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto dp = wrapper_dp->unwrapWindows_UI_Xaml_DependencyProperty();


			auto context = get_context();
			auto method_result = unwrap()->GetAnimationBaseValue(dp);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
