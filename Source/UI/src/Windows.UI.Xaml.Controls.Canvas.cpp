/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Canvas
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.UIElement.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Controls.Canvas.hpp"

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

		Canvas::Canvas(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Panel(js_context)
		{
		}

		void Canvas::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::Canvas^ Canvas::unwrapWindows_UI_Xaml_Controls_Canvas() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::Canvas^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::Canvas^ Canvas::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_Canvas();
		}

		void Canvas::wrap(::Windows::UI::Xaml::Controls::Canvas^ object)
		{
			wrapped__ = object;
		}

		void Canvas::JSExportInitialize()
		{
			JSExport<Canvas>::SetClassVersion(1);
			JSExport<Canvas>::SetParent(JSExport<Windows::UI::Xaml::Controls::Panel>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(Canvas, LeftProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Canvas, TopProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Canvas, ZIndexProperty);
			TITANIUM_ADD_FUNCTION(Canvas, GetLeft);
			TITANIUM_ADD_FUNCTION(Canvas, SetLeft);
			TITANIUM_ADD_FUNCTION(Canvas, GetTop);
			TITANIUM_ADD_FUNCTION(Canvas, SetTop);
			TITANIUM_ADD_FUNCTION(Canvas, GetZIndex);
			TITANIUM_ADD_FUNCTION(Canvas, SetZIndex);
		}

		TITANIUM_PROPERTY_GETTER(Canvas, LeftProperty)
		{
			auto value = unwrap()->LeftProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, TopProperty)
		{
			auto value = unwrap()->TopProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, ZIndexProperty)
		{
			auto value = unwrap()->ZIndexProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(Canvas, GetLeft)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto context = get_context();
			auto method_result = unwrap()->GetLeft(element);

			auto result = context.CreateNumber(static_cast<double>(method_result));

			return result;
		}

		TITANIUM_FUNCTION(Canvas, SetLeft)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto length = static_cast<double>(_1);


			unwrap()->SetLeft(element, length);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetTop)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto context = get_context();
			auto method_result = unwrap()->GetTop(element);

			auto result = context.CreateNumber(static_cast<double>(method_result));

			return result;
		}

		TITANIUM_FUNCTION(Canvas, SetTop)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto length = static_cast<double>(_1);


			unwrap()->SetTop(element, length);
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetZIndex)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto context = get_context();
			auto method_result = unwrap()->GetZIndex(element);

 			auto result = context.CreateNumber(method_result);

			return result;
		}

		TITANIUM_FUNCTION(Canvas, SetZIndex)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_element = static_cast<JSObject>(_0);
			auto wrapper_element = object_element.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto element = wrapper_element->unwrapWindows_UI_Xaml_UIElement();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(_1);


			unwrap()->SetZIndex(element, value);
			return get_context().CreateUndefined(); 
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
