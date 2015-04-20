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
			wrapped__ = ref new ::Windows::UI::Xaml::Controls::Canvas();
		}

		::Windows::UI::Xaml::Controls::Canvas^ Canvas::unwrapWindows_UI_Xaml_Controls_Canvas() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::Canvas^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Controls::Canvas^ Canvas::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_Canvas();
		}

		void Canvas::wrap(::Windows::UI::Xaml::Controls::Canvas^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
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
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, TopProperty)
		{
			auto value = unwrap()->TopProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, ZIndexProperty)
		{
			auto value = unwrap()->ZIndexProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(Canvas, GetLeft)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetLeft();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetLeft)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->SetLeft();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetTop)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetTop();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetTop)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->SetTop();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetZIndex)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetZIndex();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetZIndex)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->SetZIndex();
			return get_context().CreateUndefined(); 
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
