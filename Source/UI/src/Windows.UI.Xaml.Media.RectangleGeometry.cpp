/**
 * Windows Native Wrapper for Windows.UI.Xaml.Media.RectangleGeometry
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Media.RectangleGeometry.hpp"

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

		RectangleGeometry::RectangleGeometry(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Media::Geometry(js_context)
		{
		}

		void RectangleGeometry::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::Media::RectangleGeometry();
		}

		::Windows::UI::Xaml::Media::RectangleGeometry^ RectangleGeometry::unwrapWindows_UI_Xaml_Media_RectangleGeometry() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Media::RectangleGeometry^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Media::RectangleGeometry^ RectangleGeometry::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Media_RectangleGeometry();
		}

		void RectangleGeometry::wrap(::Windows::UI::Xaml::Media::RectangleGeometry^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void RectangleGeometry::JSExportInitialize()
		{
			JSExport<RectangleGeometry>::SetClassVersion(1);
			JSExport<RectangleGeometry>::SetParent(JSExport<Windows::UI::Xaml::Media::Geometry>::Class());

			TITANIUM_ADD_PROPERTY(RectangleGeometry, Rect);
			TITANIUM_ADD_PROPERTY_READONLY(RectangleGeometry, RectProperty);
		}

		TITANIUM_PROPERTY_SETTER(RectangleGeometry, Rect)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new Windows::Foundation::Rect(0, 0, 0, 0);
			unwrap()->Rect = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(RectangleGeometry, Rect)
		{
			auto value = unwrap()->Rect;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(value.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(value.Y)));
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(value.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(value.Height)));
			return result; 
		}

		TITANIUM_PROPERTY_GETTER(RectangleGeometry, RectProperty)
		{
			auto value = unwrap()->RectProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

				} // namespace Media
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
