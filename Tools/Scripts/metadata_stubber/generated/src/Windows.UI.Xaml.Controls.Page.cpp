
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Page
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Windows.UI.Xaml.Controls.Page.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		Page::Page(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments)
		{
		}

		void Page::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			wrapped__ = ref new Windows::UI::Xaml::Controls::Page();
		}

		Windows::UI::Xaml::Controls::Page^ Page::unwrap()
		{
			return wrapped__;
		}

		void Page::wrap(Windows::UI::Xaml::Controls::Page^ object)
		{
			wrapped__ = object;
		}

		void Page::JSExportInitialize()
		{
			JSExport<Page>::SetClassVersion(1);
			JSExport<Page>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(Page, TopAppBar);
				TITANIUM_ADD_PROPERTY(Page, NavigationCacheMode);
				TITANIUM_ADD_PROPERTY(Page, BottomAppBar);
				TITANIUM_ADD_PROPERTY_READONLY(Page, Frame);
			TITANIUM_ADD_PROPERTY_READONLY(Page, BottomAppBarProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Page, FrameProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Page, TopAppBarProperty);
			TITANIUM_ADD_FUNCTION(Page, .ctor);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatedFrom);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatedTo);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatingFrom);
		}

		TITANIUM_PROPERTY_SETTER(Page, TopAppBar)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::AppBar>();
			// FIXME What if wrapper is nullptr? We need to figure out how to translate the arg into a native object!
			// TODO Now get the wrapper's underlying native object, it's wrapped__ field...
			auto value = wrapper->unwrap();
			wrapped__->TopAppBar = value;
			return true;
		}
		TITANIUM_PROPERTY_GETTER(Page, TopAppBar)
		{
			auto value = wrapped__->TopAppBar;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::AppBar>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_SETTER(Page, NavigationCacheMode)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument); // TODO Look up enum in metadata to know what type it's value is? 
			wrapped__->NavigationCacheMode = value;
			return true;
		}
		TITANIUM_PROPERTY_GETTER(Page, NavigationCacheMode)
		{
			auto value = wrapped__->NavigationCacheMode;
			auto context = get_context();
			return context.CreateNumber(value);
		}
		TITANIUM_PROPERTY_SETTER(Page, BottomAppBar)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::AppBar>();
			// FIXME What if wrapper is nullptr? We need to figure out how to translate the arg into a native object!
			// TODO Now get the wrapper's underlying native object, it's wrapped__ field...
			auto value = wrapper->unwrap();
			wrapped__->BottomAppBar = value;
			return true;
		}
		TITANIUM_PROPERTY_GETTER(Page, BottomAppBar)
		{
			auto value = wrapped__->BottomAppBar;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::AppBar>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_GETTER(Page, Frame)
		{
			auto value = wrapped__->Frame;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::Frame>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_GETTER(Page, BottomAppBarProperty)
		{
			auto value = wrapped__->BottomAppBarProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_GETTER(Page, FrameProperty)
		{
			auto value = wrapped__->FrameProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			object.wrap(value);
			return object;
		}
		TITANIUM_PROPERTY_GETTER(Page, TopAppBarProperty)
		{
			auto value = wrapped__->TopAppBarProperty;
			auto context = get_context();
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			object.wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(Page, .ctor)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
					wrapped__->.ctor();
			return get_context().CreateUndefined(); 
				}
		TITANIUM_FUNCTION(Page, OnNavigatedFrom)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
					wrapped__->OnNavigatedFrom();
			return get_context().CreateUndefined(); 
				}
		TITANIUM_FUNCTION(Page, OnNavigatedTo)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
					wrapped__->OnNavigatedTo();
			return get_context().CreateUndefined(); 
				}
		TITANIUM_FUNCTION(Page, OnNavigatingFrom)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
					wrapped__->OnNavigatingFrom();
			return get_context().CreateUndefined(); 
				}

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows

