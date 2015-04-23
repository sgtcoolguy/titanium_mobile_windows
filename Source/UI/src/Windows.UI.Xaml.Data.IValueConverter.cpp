/**
 * Windows Native Wrapper for Windows.UI.Xaml.Data.IValueConverter
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Data.IValueConverter.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Data
				{

		IValueConverter::IValueConverter(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void IValueConverter::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Data::IValueConverter^ IValueConverter::unwrapWindows_UI_Xaml_Data_IValueConverter() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Data::IValueConverter^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Data::IValueConverter^ IValueConverter::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Data_IValueConverter();
		}

		void IValueConverter::wrap(::Windows::UI::Xaml::Data::IValueConverter^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void IValueConverter::JSExportInitialize()
		{
			JSExport<IValueConverter>::SetClassVersion(1);
			JSExport<IValueConverter>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_FUNCTION(IValueConverter, Convert);
			TITANIUM_ADD_FUNCTION(IValueConverter, ConvertBack);
		}

		TITANIUM_FUNCTION(IValueConverter, Convert)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_targetType = static_cast<JSObject>(_1);
			auto targetType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_targetType.GetProperty("Name");
			targetType.Name = static_cast<int32_t>(Name);
			auto Kind = object_targetType.GetProperty("Kind");
			targetType.Kind = static_cast<int32_t>(Kind);


			auto _2 = arguments.at(2);
 			TITANIUM_ASSERT_AND_THROW(_2.IsObject(), "Expected Object");
			auto object_parameter = static_cast<JSObject>(_2);
			auto wrapper_parameter = object_parameter.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto parameter = wrapper_parameter->unwrapTitanium_Module();


			auto _3 = arguments.at(3);
 			TITANIUM_ASSERT_AND_THROW(_3.IsString(), "Expected String");
			auto language = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_3));


			auto context = get_context();
			auto method_result = unwrap()->Convert(value, targetType, parameter, language);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

		TITANIUM_FUNCTION(IValueConverter, ConvertBack)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(_0);
			auto wrapper_value = object_value.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapTitanium_Module();


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_targetType = static_cast<JSObject>(_1);
			auto targetType = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_targetType.GetProperty("Name");
			targetType.Name = static_cast<int32_t>(Name);
			auto Kind = object_targetType.GetProperty("Kind");
			targetType.Kind = static_cast<int32_t>(Kind);


			auto _2 = arguments.at(2);
 			TITANIUM_ASSERT_AND_THROW(_2.IsObject(), "Expected Object");
			auto object_parameter = static_cast<JSObject>(_2);
			auto wrapper_parameter = object_parameter.GetPrivate<Titanium::Module>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto parameter = wrapper_parameter->unwrapTitanium_Module();


			auto _3 = arguments.at(3);
 			TITANIUM_ASSERT_AND_THROW(_3.IsString(), "Expected String");
			auto language = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(_3));


			auto context = get_context();
			auto method_result = unwrap()->ConvertBack(value, targetType, parameter, language);

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);


			return result; 
		}

				} // namespace Data
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
