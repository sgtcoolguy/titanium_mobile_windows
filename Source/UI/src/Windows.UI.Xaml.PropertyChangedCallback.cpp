/**
 * Windows Native Wrapper for Windows.UI.Xaml.PropertyChangedCallback
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.PropertyChangedCallback.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		PropertyChangedCallback::PropertyChangedCallback(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void PropertyChangedCallback::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::PropertyChangedCallback^ PropertyChangedCallback::unwrapWindows_UI_Xaml_PropertyChangedCallback() const
		{
			return dynamic_cast<::Windows::UI::Xaml::PropertyChangedCallback^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::PropertyChangedCallback^ PropertyChangedCallback::unwrap() const
		{
			return unwrapWindows_UI_Xaml_PropertyChangedCallback();
		}

		void PropertyChangedCallback::wrap(::Windows::UI::Xaml::PropertyChangedCallback^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void PropertyChangedCallback::JSExportInitialize()
		{
			JSExport<PropertyChangedCallback>::SetClassVersion(1);
			JSExport<PropertyChangedCallback>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_FUNCTION(PropertyChangedCallback, Invoke);
		}

		TITANIUM_FUNCTION(PropertyChangedCallback, Invoke)
		{
			auto _0 = arguments.at(0);
 			TITANIUM_ASSERT_AND_THROW(_0.IsObject(), "Expected Object");
			auto object_d = static_cast<JSObject>(_0);
			auto wrapper_d = object_d.GetPrivate<Windows::UI::Xaml::DependencyObject>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto d = wrapper_d->unwrapWindows_UI_Xaml_DependencyObject();


			auto _1 = arguments.at(1);
 			TITANIUM_ASSERT_AND_THROW(_1.IsObject(), "Expected Object");
			auto object_e = static_cast<JSObject>(_1);
			auto wrapper_e = object_e.GetPrivate<Windows::UI::Xaml::DependencyPropertyChangedEventArgs>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto e = wrapper_e->unwrapWindows_UI_Xaml_DependencyPropertyChangedEventArgs();


			unwrap()->Invoke(d, e);
			return get_context().CreateUndefined(); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
