/**
 * Windows Native Wrapper for Windows.UI.Xaml.CreateDefaultValueCallback
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.CreateDefaultValueCallback.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		CreateDefaultValueCallback::CreateDefaultValueCallback(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Platform::Object(js_context)
		{
		}

		void CreateDefaultValueCallback::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::CreateDefaultValueCallback^ CreateDefaultValueCallback::unwrapWindows_UI_Xaml_CreateDefaultValueCallback() const
		{
			return dynamic_cast<::Windows::UI::Xaml::CreateDefaultValueCallback^>(wrapped__);
		}

		::Windows::UI::Xaml::CreateDefaultValueCallback^ CreateDefaultValueCallback::unwrap() const
		{
			return unwrapWindows_UI_Xaml_CreateDefaultValueCallback();
		}

		void CreateDefaultValueCallback::wrap(::Windows::UI::Xaml::CreateDefaultValueCallback^ object)
		{
			wrapped__ = object;
		}

		void CreateDefaultValueCallback::JSExportInitialize()
		{
			JSExport<CreateDefaultValueCallback>::SetClassVersion(1);
			JSExport<CreateDefaultValueCallback>::SetParent(JSExport<Titanium::Platform::Object>::Class());

			TITANIUM_ADD_FUNCTION(CreateDefaultValueCallback, Invoke);
		}

		TITANIUM_FUNCTION(CreateDefaultValueCallback, Invoke)
		{
			auto context = get_context();
			auto method_result = unwrap()->Invoke();

			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(method_result);

			return result;
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
