/**
 * Windows Native Wrapper for Windows.UI.Xaml.Window
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.CoreDispatcher.hpp"
#include "Windows.UI.Core.CoreWindow.hpp"
#include "Windows.UI.Xaml.UIElement.hpp"
#include "Windows.UI.Xaml.Window.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		Window::Window(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void Window::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Window^ Window::unwrapWindows_UI_Xaml_Window() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Window^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Window^ Window::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Window();
		}

		void Window::wrap(::Windows::UI::Xaml::Window^ object)
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
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::UIElement>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_UIElement();


			unwrap()->Content = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Window, Content)
		{
			auto value = unwrap()->Content;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::UIElement>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::UIElement>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Window, Bounds)
		{
			auto value = unwrap()->Bounds;
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
			auto value = unwrap()->CoreWindow;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Core::CoreWindow>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreWindow>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Window, Dispatcher)
		{
			auto value = unwrap()->Dispatcher;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Window, Visible)
		{
			auto value = unwrap()->Visible;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Window, Current)
		{
			auto value = unwrap()->Current;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Window>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Window>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(Window, Activate)
		{
			unwrap()->Activate();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(Window, Close)
		{
			unwrap()->Close();
			return get_context().CreateUndefined(); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
