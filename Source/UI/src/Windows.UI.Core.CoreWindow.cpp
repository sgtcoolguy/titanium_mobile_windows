/**
 * Windows Native Wrapper for Windows.UI.Core.CoreWindow
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.CoreDispatcher.hpp"
#include "Windows.Foundation.Collections.IPropertySet.hpp"
#include "Windows.UI.Core.CoreCursor.hpp"
#include "Windows.UI.Core.CoreWindow.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Core
			{

		CoreWindow::CoreWindow(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void CoreWindow::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Core::CoreWindow();
		}

		::Windows::UI::Core::CoreWindow^ CoreWindow::unwrapWindows_UI_Core_CoreWindow() const
		{
			return dynamic_cast<::Windows::UI::Core::CoreWindow^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Core::CoreWindow^ CoreWindow::unwrap() const
		{
			return unwrapWindows_UI_Core_CoreWindow();
		}

		void CoreWindow::wrap(::Windows::UI::Core::CoreWindow^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void CoreWindow::JSExportInitialize()
		{
			JSExport<CoreWindow>::SetClassVersion(1);
			JSExport<CoreWindow>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY(CoreWindow, PointerCursor);
			TITANIUM_ADD_PROPERTY(CoreWindow, IsInputEnabled);
			TITANIUM_ADD_PROPERTY(CoreWindow, FlowDirection);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, AutomationHostProvider);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, Bounds);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, CustomProperties);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, Dispatcher);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, PointerPosition);
			TITANIUM_ADD_PROPERTY_READONLY(CoreWindow, Visible);
			TITANIUM_ADD_FUNCTION(CoreWindow, Activate);
			TITANIUM_ADD_FUNCTION(CoreWindow, Close);
			TITANIUM_ADD_FUNCTION(CoreWindow, GetAsyncKeyState);
			TITANIUM_ADD_FUNCTION(CoreWindow, GetKeyState);
			TITANIUM_ADD_FUNCTION(CoreWindow, ReleasePointerCapture);
			TITANIUM_ADD_FUNCTION(CoreWindow, SetPointerCapture);
			TITANIUM_ADD_FUNCTION(CoreWindow, GetForCurrentThread);
		}

		TITANIUM_PROPERTY_SETTER(CoreWindow, PointerCursor)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Core::CoreCursor>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Core_CoreCursor();
			unwrap()->PointerCursor = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, PointerCursor)
		{
			auto value = unwrap()->PointerCursor;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreCursor>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Core::CoreCursor>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(CoreWindow, IsInputEnabled)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
			unwrap()->IsInputEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, IsInputEnabled)
		{
			auto value = unwrap()->IsInputEnabled;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_PROPERTY_SETTER(CoreWindow, FlowDirection)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Core::CoreWindowFlowDirection>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
			unwrap()->FlowDirection = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, FlowDirection)
		{
			auto value = unwrap()->FlowDirection;
			auto context = get_context();
			return context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, AutomationHostProvider)
		{
			auto value = unwrap()->AutomationHostProvider;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<object>::Class());
			auto native_wrapper = object.GetPrivate<object>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Bounds)
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

		TITANIUM_PROPERTY_GETTER(CoreWindow, CustomProperties)
		{
			auto value = unwrap()->CustomProperties;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::Foundation::Collections::IPropertySet>::Class());
			auto native_wrapper = object.GetPrivate<Windows::Foundation::Collections::IPropertySet>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Dispatcher)
		{
			auto value = unwrap()->Dispatcher;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, PointerPosition)
		{
			auto value = unwrap()->PointerPosition;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("X", context.CreateNumber(static_cast<double>(value.X)));
			result.SetProperty("Y", context.CreateNumber(static_cast<double>(value.Y)));
			return result; 
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Visible)
		{
			auto value = unwrap()->Visible;
			auto context = get_context();
 			return context.CreateBoolean(value); 
		}

		TITANIUM_FUNCTION(CoreWindow, Activate)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->Activate();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, Close)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->Close();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetAsyncKeyState)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetAsyncKeyState();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetKeyState)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetKeyState();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(CoreWindow, ReleasePointerCapture)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->ReleasePointerCapture();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, SetPointerCapture)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			unwrap()->SetPointerCapture();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetForCurrentThread)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetForCurrentThread();
			return get_context().CreateBoolean(result); 
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
