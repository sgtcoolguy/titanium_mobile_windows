/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.GeneralTransform
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Media.GeneralTransform.hpp"

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

		GeneralTransform::GeneralTransform(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void GeneralTransform::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::Media::GeneralTransform();
		}

		::Windows::UI::Xaml::Media::GeneralTransform^ GeneralTransform::unwrapWindows_UI_Xaml_Media_GeneralTransform() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::GeneralTransform^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Media::GeneralTransform^ GeneralTransform::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_GeneralTransform();
		}

		void GeneralTransform::wrap(::Windows::UI::Xaml::Media::GeneralTransform^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void GeneralTransform::JSExportInitialize()
		{
			JSExport<GeneralTransform>::SetClassVersion(1);
			JSExport<GeneralTransform>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(GeneralTransform, Inverse);
			TITANIUM_ADD_PROPERTY_READONLY(GeneralTransform, InverseCore);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TransformPoint);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TryTransform);
			TITANIUM_ADD_FUNCTION(GeneralTransform, TransformBounds);
		}

		TITANIUM_PROPERTY_GETTER(GeneralTransform, Inverse)
		{
			auto value = unwrap()->Inverse;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::GeneralTransform>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::GeneralTransform>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(GeneralTransform, InverseCore)
		{
			auto value = unwrap()->InverseCore;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::GeneralTransform>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::GeneralTransform>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(GeneralTransform, TransformPoint)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_point = static_cast<JSObject>(_0);
			auto point = ::Windows::Foundation::Point(0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto X = object_point.GetProperty("X");
			point.X = static_cast<double>(X);
			auto Y = object_point.GetProperty("Y");
			point.Y = static_cast<double>(Y);


			auto context = get_context();
			auto method_result = unwrap()->TransformPoint(point);

			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(method_result.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(method_result.Y)));


			return result; 
		}

		TITANIUM_FUNCTION(GeneralTransform, TryTransform)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_inPoint = static_cast<JSObject>(_0);
			auto inPoint = ::Windows::Foundation::Point(0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto X = object_inPoint.GetProperty("X");
			inPoint.X = static_cast<double>(X);
			auto Y = object_inPoint.GetProperty("Y");
			inPoint.Y = static_cast<double>(Y);


			auto _1 = arguments.at(1);
			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_outPoint = static_cast<JSObject>(_1);
			auto outPoint = ::Windows::Foundation::Point(0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto X = object_outPoint.GetProperty("X");
			outPoint.X = static_cast<double>(X);
			auto Y = object_outPoint.GetProperty("Y");
			outPoint.Y = static_cast<double>(Y);


			auto context = get_context();
			auto method_result = unwrap()->TryTransform(inPoint, outPoint);

 			auto result = context.CreateBoolean(method_result); 


			return result; 
		}

		TITANIUM_FUNCTION(GeneralTransform, TransformBounds)
		{
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_rect = static_cast<JSObject>(_0);
			auto rect = ::Windows::Foundation::Rect(0, 0, 0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto X = object_rect.GetProperty("X");
			rect.X = static_cast<double>(X);
			auto Y = object_rect.GetProperty("Y");
			rect.Y = static_cast<double>(Y);
			auto Width = object_rect.GetProperty("Width");
			rect.Width = static_cast<double>(Width);
			auto Height = object_rect.GetProperty("Height");
			rect.Height = static_cast<double>(Height);


			auto context = get_context();
			auto method_result = unwrap()->TransformBounds(rect);

			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(method_result.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(method_result.Y)));
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(method_result.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(method_result.Height)));


			return result; 
		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
