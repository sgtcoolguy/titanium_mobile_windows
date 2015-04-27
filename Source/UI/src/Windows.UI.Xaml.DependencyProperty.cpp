/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyProperty
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.PropertyMetadata.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		DependencyProperty::DependencyProperty(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void DependencyProperty::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::DependencyProperty^ DependencyProperty::unwrapWindows_UI_Xaml_DependencyProperty() const
		{
			return dynamic_cast<::Windows::UI::Xaml::DependencyProperty^>(wrapped__);
		}

		::Windows::UI::Xaml::DependencyProperty^ DependencyProperty::unwrap() const
		{
			return unwrapWindows_UI_Xaml_DependencyProperty();
		}

		void DependencyProperty::wrap(::Windows::UI::Xaml::DependencyProperty^ object)
		{
			wrapped__ = object;
		}

		void DependencyProperty::JSExportInitialize()
		{
			JSExport<DependencyProperty>::SetClassVersion(1);
			JSExport<DependencyProperty>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(DependencyProperty, UnsetValue);
			TITANIUM_ADD_FUNCTION(DependencyProperty, GetMetadata);
			TITANIUM_ADD_FUNCTION(DependencyProperty, Register);
			TITANIUM_ADD_FUNCTION(DependencyProperty, RegisterAttached);
		}

		TITANIUM_PROPERTY_GETTER(DependencyProperty, UnsetValue)
		{
			auto value = unwrap()->UnsetValue;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<>::Class());
			auto result_wrapper = result.GetPrivate<>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(DependencyProperty, GetMetadata)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_forType = static_cast<JSObject>(_0);
			auto forType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_forType.GetProperty("Name");
			forType.Name = static_cast<int32_t>(Name);
			auto Kind = object_forType.GetProperty("Kind");
			forType.Kind = static_cast<int32_t>(Kind);


			auto context = get_context();
			auto method_result = unwrap()->GetMetadata(forType);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::PropertyMetadata>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(DependencyProperty, Register)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsString(), "Expected String");
			auto name = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_0));


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_propertyType = static_cast<JSObject>(_1);
			auto propertyType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_propertyType.GetProperty("Name");
			propertyType.Name = static_cast<int32_t>(Name);
			auto Kind = object_propertyType.GetProperty("Kind");
			propertyType.Kind = static_cast<int32_t>(Kind);


			auto _2 = arguments.at(2);
			TITANIUM_ASSERT_AND_THROW(_2.IsObject(), "Expected Object");
			auto object_ownerType = static_cast<JSObject>(_2);
			auto ownerType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_ownerType.GetProperty("Name");
			ownerType.Name = static_cast<int32_t>(Name);
			auto Kind = object_ownerType.GetProperty("Kind");
			ownerType.Kind = static_cast<int32_t>(Kind);


			auto _3 = arguments.at(3);
 			TITANIUM_ASSERT_AND_THROW(_3.IsObject(), "Expected Object");
			auto object_typeMetadata = static_cast<JSObject>(_3);
			auto wrapper_typeMetadata = object_typeMetadata.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto typeMetadata = wrapper_typeMetadata->unwrapWindows_UI_Xaml_PropertyMetadata();


			auto context = get_context();
			auto method_result = unwrap()->Register(name, propertyType, ownerType, typeMetadata);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(method_result);

			return result;
		}

		TITANIUM_FUNCTION(DependencyProperty, RegisterAttached)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsString(), "Expected String");
			auto name = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_0));


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_propertyType = static_cast<JSObject>(_1);
			auto propertyType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_propertyType.GetProperty("Name");
			propertyType.Name = static_cast<int32_t>(Name);
			auto Kind = object_propertyType.GetProperty("Kind");
			propertyType.Kind = static_cast<int32_t>(Kind);


			auto _2 = arguments.at(2);
			TITANIUM_ASSERT_AND_THROW(_2.IsObject(), "Expected Object");
			auto object_ownerType = static_cast<JSObject>(_2);
			auto ownerType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_ownerType.GetProperty("Name");
			ownerType.Name = static_cast<int32_t>(Name);
			auto Kind = object_ownerType.GetProperty("Kind");
			ownerType.Kind = static_cast<int32_t>(Kind);


			auto _3 = arguments.at(3);
 			TITANIUM_ASSERT_AND_THROW(_3.IsObject(), "Expected Object");
			auto object_defaultMetadata = static_cast<JSObject>(_3);
			auto wrapper_defaultMetadata = object_defaultMetadata.GetPrivate<Windows::UI::Xaml::PropertyMetadata>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto defaultMetadata = wrapper_defaultMetadata->unwrapWindows_UI_Xaml_PropertyMetadata();


			auto context = get_context();
			auto method_result = unwrap()->RegisterAttached(name, propertyType, ownerType, defaultMetadata);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(method_result);

			return result;
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
