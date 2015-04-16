
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Canvas
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.Canvas.hpp"
 // TODO Include the headers for all the native types we use in here!

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		Canvas::Canvas(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::Panel(js_context, arguments)
		{
		}

		void Canvas::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			// TODO If this is not a "leaf" class, should we instantiate the type? How woudl we even know if it's a leaf?
			wrapped__ = ref new Windows::UI::Xaml::Controls::Canvas();
		}

		Windows::UI::Xaml::Controls::Canvas^ Canvas::unwrap()
		{
			return wrapped__;
		}

		void Canvas::wrap(Windows::UI::Xaml::Controls::Canvas^ object)
		{
			wrapped__ = object; // TODO Do we need to do some sort of cast here? wrapped__ may be up in a parent class and defined as the parent type...
		}

		void Canvas::JSExportInitialize()
		{
			JSExport<Canvas>::SetClassVersion(1);
			JSExport<Canvas>::SetParent(JSExport<Windows::UI::Xaml::Controls::Panel>::Class()); // FIXME Extend the parent class of the native type!

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
			auto value = wrapped__->LeftProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, TopProperty)
		{
			auto value = wrapped__->TopProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Canvas, ZIndexProperty)
		{
			auto value = wrapped__->ZIndexProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
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
			auto result = wrapped__->GetLeft();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetLeft)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SetLeft();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetTop)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetTop();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetTop)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SetTop();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Canvas, GetZIndex)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetZIndex();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(Canvas, SetZIndex)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SetZIndex();
			return get_context().CreateUndefined(); 
		}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
