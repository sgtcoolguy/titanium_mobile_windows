/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.AppBar
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Controls.AppBar.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{

		AppBar::AppBar(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::Controls::ContentControl(js_context)
		{
		}

		void AppBar::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Controls::AppBar^ AppBar::unwrapWindows_UI_Xaml_Controls_AppBar() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::AppBar^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::AppBar^ AppBar::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_AppBar();
		}

		void AppBar::wrap(::Windows::UI::Xaml::Controls::AppBar^ object)
		{
			wrapped__ = object;
		}

		void AppBar::JSExportInitialize()
		{
			JSExport<AppBar>::SetClassVersion(1);
			JSExport<AppBar>::SetParent(JSExport<Windows::UI::Xaml::Controls::ContentControl>::Class());

			TITANIUM_ADD_PROPERTY(AppBar, IsSticky);
			TITANIUM_ADD_PROPERTY(AppBar, IsOpen);
			TITANIUM_ADD_PROPERTY_READONLY(AppBar, IsOpenProperty);
			TITANIUM_ADD_PROPERTY_READONLY(AppBar, IsStickyProperty);
		}

		TITANIUM_PROPERTY_SETTER(AppBar, IsSticky)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsSticky = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(AppBar, IsSticky)
		{
			auto value = unwrap()->IsSticky;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_SETTER(AppBar, IsOpen)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);


			unwrap()->IsOpen = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(AppBar, IsOpen)
		{
			auto value = unwrap()->IsOpen;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(AppBar, IsOpenProperty)
		{
			auto value = unwrap()->IsOpenProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(AppBar, IsStickyProperty)
		{
			auto value = unwrap()->IsStickyProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
