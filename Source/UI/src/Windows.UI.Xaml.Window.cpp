/**
 * Windows Native Wrapper for Windows.UI.Xaml.Window
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Window.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		Window::Window(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context, arguments)
		{
		}

		void Window::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Window();
		}

		Windows::UI::Xaml::Window^ Window::unwrapWindows_UI_Xaml_Window()
		{
			return dynamic_cast<Windows::UI::Xaml::Window^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void Window::wrap(Windows::UI::Xaml::Window^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Window::JSExportInitialize()
		{
			JSExport<Window>::SetClassVersion(1);
			JSExport<Window>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY(Window, Content);
			TITANIUM_ADD_PROPERTY_READONLY(Window, Bounds);
			TITANIUM_ADD_PROPERTY_READONLY(Window, CoreWindow);
			TITANIUM_ADD_PROPERTY_READONLY(Window, Dispatcher);
			TITANIUM_ADD_PROPERTY_READONLY(Window, Visible);
			TITANIUM_ADD_PROPERTY_READONLY(Window, Current);
			TITANIUM_ADD_FUNCTION(Window, Activate);
			TITANIUM_ADD_FUNCTION(Window, Close);
		}

		TITANIUM_PROPERTY_SETTER(Window, Content)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_UIElement();
			wrapped__->Content = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Window, Content)
		{
			auto value = wrapped__->Content;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::UIElement>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::UIElement>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Window, Bounds)
		{
			auto value = wrapped__->Bounds;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(value.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(value.Y)));
			result.SetProperty("Width", context.CreateNumber(static_cast<double>(value.Width)));
			result.SetProperty("Height", context.CreateNumber(static_cast<double>(value.Height)));
			return result; 
		}

		TITANIUM_PROPERTY_GETTER(Window, CoreWindow)
		{
			auto value = wrapped__->CoreWindow;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreWindow>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Core::CoreWindow>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Window, Dispatcher)
		{
			auto value = wrapped__->Dispatcher;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Window, Visible)
		{
			auto value = wrapped__->Visible;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_GETTER(Window, Current)
		{
			auto value = wrapped__->Current;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Window>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Window>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(Window, Activate)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Activate();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Window, Close)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->Close();
			return get_context().CreateUndefined(); 
		}

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
