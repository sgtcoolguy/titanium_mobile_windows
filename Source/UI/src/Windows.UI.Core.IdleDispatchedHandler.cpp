/**
 * Windows Native Wrapper for Windows.UI.Core.IdleDispatchedHandler
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.IdleDispatchedHandler.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Core
			{

		IdleDispatchedHandler::IdleDispatchedHandler(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void IdleDispatchedHandler::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Core::IdleDispatchedHandler^ IdleDispatchedHandler::unwrapWindows_UI_Core_IdleDispatchedHandler() const
		{
			return dynamic_cast<::Windows::UI::Core::IdleDispatchedHandler^>(wrapped__);
		}

		::Windows::UI::Core::IdleDispatchedHandler^ IdleDispatchedHandler::unwrap() const
		{
			return unwrapWindows_UI_Core_IdleDispatchedHandler();
		}

		void IdleDispatchedHandler::wrap(::Windows::UI::Core::IdleDispatchedHandler^ object)
		{
			wrapped__ = object;
		}

		void IdleDispatchedHandler::JSExportInitialize()
		{
			JSExport<IdleDispatchedHandler>::SetClassVersion(1);
			JSExport<IdleDispatchedHandler>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_FUNCTION(IdleDispatchedHandler, Invoke);
		}

		TITANIUM_FUNCTION(IdleDispatchedHandler, Invoke)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_e = static_cast<JSObject>(_0);
			auto wrapper_e = object_e.GetPrivate<Windows::UI::Core::IdleDispatchedHandlerArgs>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto e = wrapper_e->unwrapWindows_UI_Core_IdleDispatchedHandlerArgs();


			unwrap()->Invoke(e);
			return get_context().CreateUndefined(); 
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
