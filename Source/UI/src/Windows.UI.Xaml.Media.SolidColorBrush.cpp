/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.SolidColorBrush
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Media.SolidColorBrush.hpp"

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

		SolidColorBrush::SolidColorBrush(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Media::Brush(js_context)
		{
		}

		void SolidColorBrush::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Media::SolidColorBrush^ SolidColorBrush::unwrapWindows_UI_Xaml_Media_SolidColorBrush() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::SolidColorBrush^>(wrapped__);
		}

		::Windows::UI::Xaml::Media::SolidColorBrush^ SolidColorBrush::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_SolidColorBrush();
		}

		void SolidColorBrush::wrap(::Windows::UI::Xaml::Media::SolidColorBrush^ object)
		{
			wrapped__ = object;
		}

		void SolidColorBrush::JSExportInitialize()
		{
			JSExport<SolidColorBrush>::SetClassVersion(1);
			JSExport<SolidColorBrush>::SetParent(JSExport<Windows::UI::Xaml::Media::Brush>::Class());

			TITANIUM_ADD_PROPERTY(SolidColorBrush, Color);
			TITANIUM_ADD_PROPERTY_READONLY(SolidColorBrush, ColorProperty);
		}

		TITANIUM_PROPERTY_SETTER(SolidColorBrush, Color)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Color(0, 0, 0, 0);
			// Assign fields explicitly since we cheated on constructor args
			auto A = object_value.GetProperty("A");
			value.A = static_cast<int32_t>(A);
			auto R = object_value.GetProperty("R");
			value.R = static_cast<int32_t>(R);
			auto G = object_value.GetProperty("G");
			value.G = static_cast<int32_t>(G);
			auto B = object_value.GetProperty("B");
			value.B = static_cast<int32_t>(B);


			unwrap()->Color = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(SolidColorBrush, Color)
		{
			auto value = unwrap()->Color;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("A", context.CreateNumber(static_cast<int32_t>(value.A)));
			result.SetProperty("R", context.CreateNumber(static_cast<int32_t>(value.R)));
			result.SetProperty("G", context.CreateNumber(static_cast<int32_t>(value.G)));
			result.SetProperty("B", context.CreateNumber(static_cast<int32_t>(value.B)));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(SolidColorBrush, ColorProperty)
		{
			auto value = unwrap()->ColorProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
