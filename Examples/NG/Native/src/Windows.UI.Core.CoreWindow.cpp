/**
 * Windows Native Wrapper for Windows.UI.Core.CoreWindow
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.Foundation.Collections.IPropertySet.hpp"
#include "Windows.UI.Core.CoreCursor.hpp"
#include "Windows.UI.Core.CoreDispatcher.hpp"
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
			: Titanium::Platform::Object(js_context)
		{
			TITANIUM_LOG_DEBUG("CoreWindow::ctor");
		}

		void CoreWindow::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("CoreWindow::postCallAsConstructor ", this);

		}

		::Windows::UI::Core::CoreWindow^ CoreWindow::unwrapWindows_UI_Core_CoreWindow() const
		{
			return dynamic_cast<::Windows::UI::Core::CoreWindow^>(wrapped__);
		}

		::Windows::UI::Core::CoreWindow^ CoreWindow::unwrap() const
		{
			return unwrapWindows_UI_Core_CoreWindow();
		}

		void CoreWindow::wrap(::Windows::UI::Core::CoreWindow^ object)
		{
			wrapped__ = object;
		}

		void CoreWindow::JSExportInitialize()
		{
			JSExport<CoreWindow>::SetClassVersion(1);
			JSExport<CoreWindow>::SetParent(JSExport<Titanium::Platform::Object>::Class());

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
			auto object_value = static_cast<JSObject>(argument);
 
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Core_CoreCursor();

			unwrap()->PointerCursor = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, PointerCursor)
		{
			auto value = unwrap()->PointerCursor;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreCursor>();
			result_wrapper->wrap(value);

		}

		TITANIUM_PROPERTY_SETTER(CoreWindow, IsInputEnabled)
		{ 
			auto value = static_cast<bool>(argument);

			unwrap()->IsInputEnabled = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, IsInputEnabled)
		{
			auto value = unwrap()->IsInputEnabled;
			auto context = get_context();


		}

		TITANIUM_PROPERTY_SETTER(CoreWindow, FlowDirection)
		{
			auto value = static_cast<::Windows::UI::Core::CoreWindowFlowDirection>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 

			unwrap()->FlowDirection = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, FlowDirection)
		{
			auto value = unwrap()->FlowDirection;
			auto context = get_context();

			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, AutomationHostProvider)
		{
			auto value = unwrap()->AutomationHostProvider;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Platform::Object>();
			result_wrapper->wrap(value);

		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Bounds)
		{
			auto value = unwrap()->Bounds;
			auto context = get_context();

			auto result = context.CreateObject();








		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, CustomProperties)
		{
			auto value = unwrap()->CustomProperties;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::Foundation::Collections::IPropertySet>();
			result_wrapper->wrap(value);

		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Dispatcher)
		{
			auto value = unwrap()->Dispatcher;
			auto context = get_context();

			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			result_wrapper->wrap(value);

		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, PointerPosition)
		{
			auto value = unwrap()->PointerPosition;
			auto context = get_context();

			auto result = context.CreateObject();




		}

		TITANIUM_PROPERTY_GETTER(CoreWindow, Visible)
		{
			auto value = unwrap()->Visible;
			auto context = get_context();


		}

		TITANIUM_FUNCTION(CoreWindow, Activate)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->Activate();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::Activate with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, Close)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->Close();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::Close with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetAsyncKeyState)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto virtualKey = static_cast<::Windows::System::VirtualKey>(static_cast<int32_t>(_0)); // TODO Look up enum in metadata to know what type it's value is? 

				auto method_result = unwrap()->GetAsyncKeyState(virtualKey);
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(method_result))); // FIXME What if the enum isn't an int based one?!

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::GetAsyncKeyState with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetKeyState)
		{
			auto context = get_context();
			if (arguments.size() == 1) {
				auto _0 = arguments.at(0);
			auto virtualKey = static_cast<::Windows::System::VirtualKey>(static_cast<int32_t>(_0)); // TODO Look up enum in metadata to know what type it's value is? 

				auto method_result = unwrap()->GetKeyState(virtualKey);
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(method_result))); // FIXME What if the enum isn't an int based one?!

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::GetKeyState with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, ReleasePointerCapture)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->ReleasePointerCapture();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::ReleasePointerCapture with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, SetPointerCapture)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				unwrap()->SetPointerCapture();
				return context.CreateUndefined(); 
			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::SetPointerCapture with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

		TITANIUM_FUNCTION(CoreWindow, GetForCurrentThread)
		{
			auto context = get_context();
			if (arguments.size() == 0) {
				auto method_result = ::Windows::UI::Core::CoreWindow::GetForCurrentThread();
			auto result_wrapper = result.GetPrivate<Windows::UI::Core::CoreWindow>();
			result_wrapper->wrap(method_result);

			}

			// Catch-all if no arg count matches!
			TITANIUM_LOG_DEBUG("No method signature matched CoreWindow::GetForCurrentThread with # of args: ", arguments.size());
			return context.CreateUndefined(); 
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium