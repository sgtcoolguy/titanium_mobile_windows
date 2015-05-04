/**
 * Windows Native Wrapper for Windows.UI.Core.DispatchedHandler
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Core.DispatchedHandler.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Core
			{

		DispatchedHandler::DispatchedHandler(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void DispatchedHandler::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Core::DispatchedHandler^ DispatchedHandler::unwrapWindows_UI_Core_DispatchedHandler() const
		{
			return dynamic_cast<::Windows::UI::Core::DispatchedHandler^>(wrapped__);
		}

		::Windows::UI::Core::DispatchedHandler^ DispatchedHandler::unwrap() const
		{
			return unwrapWindows_UI_Core_DispatchedHandler();
		}

		void DispatchedHandler::wrap(::Windows::UI::Core::DispatchedHandler^ object)
		{
			wrapped__ = object;
		}

		void DispatchedHandler::JSExportInitialize()
		{
			JSExport<DispatchedHandler>::SetClassVersion(1);
			JSExport<DispatchedHandler>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_FUNCTION(DispatchedHandler, Invoke);
		}

		TITANIUM_FUNCTION(DispatchedHandler, Invoke)
		{
			unwrap()->Invoke();
			return get_context().CreateUndefined(); 
		}

			} // namespace Core
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
