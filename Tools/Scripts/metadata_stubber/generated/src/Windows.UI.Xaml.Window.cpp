
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Window
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Windows.UI.Xaml.Window.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		Window::Window(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments)
		{
		}

		void Window::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			wrapped__ = ref new Windows::UI::Xaml::Window();
		}

		Windows::UI::Xaml::Window^ Window::unwrap()
		{
			return wrapped__;
		}

		void Window::wrap(Windows::UI::Xaml::Window^ object)
		{
			wrapped__ = object;
		}

		void Window::JSExportInitialize()
		{
			JSExport<Window>::SetClassVersion(1);
			JSExport<Window>::SetParent(JSExport<Module>::Class());

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
			// FIXME What if wrapper is nullptr? We need to figure out how to translate the arg into a native object!
			// TODO Now get the wrapper's underlying native object, it's wrapped__ field...
			auto value = wrapper->unwrap();
			wrapped__->Content = value;
			return true;
		}
		TITANIUM_PROPERTY_GETTER(Window, Content)
		{
			auto value = wrapped__->Content;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::UIElement>::Class());
			object.wrap(value);
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
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreWindow>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_GETTER(Window, Dispatcher)
		{
			auto value = wrapped__->Dispatcher;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			object.wrap(value);
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
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Window>::Class());
			object.wrap(value);
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

