/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.Page
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.Page.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		Page::Page(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::UserControl(js_context, arguments)
		{
		}

		void Page::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::Controls::Page();
		}

		Windows::UI::Xaml::Controls::Page^ Page::unwrapWindows_UI_Xaml_Controls_Page()
		{
			return dynamic_cast<Windows::UI::Xaml::Controls::Page^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void Page::wrap(Windows::UI::Xaml::Controls::Page^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Page::JSExportInitialize()
		{
			JSExport<Page>::SetClassVersion(1);
			JSExport<Page>::SetParent(JSExport<Windows::UI::Xaml::Controls::UserControl>::Class());

			TITANIUM_ADD_PROPERTY(Page, TopAppBar);
			TITANIUM_ADD_PROPERTY(Page, NavigationCacheMode);
			TITANIUM_ADD_PROPERTY(Page, BottomAppBar);
			TITANIUM_ADD_PROPERTY_READONLY(Page, Frame);
			TITANIUM_ADD_PROPERTY_READONLY(Page, BottomAppBarProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Page, FrameProperty);
			TITANIUM_ADD_PROPERTY_READONLY(Page, TopAppBarProperty);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatedFrom);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatedTo);
			TITANIUM_ADD_FUNCTION(Page, OnNavigatingFrom);
		}

		TITANIUM_PROPERTY_SETTER(Page, TopAppBar)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::AppBar>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Controls_AppBar();
			wrapped__->TopAppBar = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Page, TopAppBar)
		{
			auto value = wrapped__->TopAppBar;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::AppBar>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::AppBar>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_SETTER(Page, NavigationCacheMode)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
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
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrapWindows_UI_Xaml_Controls_AppBar();
			wrapped__->BottomAppBar = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Page, BottomAppBar)
		{
			auto value = wrapped__->BottomAppBar;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::AppBar>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::AppBar>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Page, Frame)
		{
			auto value = wrapped__->Frame;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::Controls::Frame>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::Controls::Frame>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Page, BottomAppBarProperty)
		{
			auto value = wrapped__->BottomAppBarProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Page, FrameProperty)
		{
			auto value = wrapped__->FrameProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_PROPERTY_GETTER(Page, TopAppBarProperty)
		{
			auto value = wrapped__->TopAppBarProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			native_wrapper->wrap(value);
			return object;
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
