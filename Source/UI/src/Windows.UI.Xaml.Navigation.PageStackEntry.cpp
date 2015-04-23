/**
 * Windows Native Wrapper for Windows.UI.Xaml.Navigation.PageStackEntry
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyProperty.hpp"
#include "Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo.hpp"
#include "Windows.UI.Xaml.Navigation.PageStackEntry.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Navigation
				{

		PageStackEntry::PageStackEntry(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void PageStackEntry::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Navigation::PageStackEntry^ PageStackEntry::unwrapWindows_UI_Xaml_Navigation_PageStackEntry() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Navigation::PageStackEntry^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Navigation::PageStackEntry^ PageStackEntry::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Navigation_PageStackEntry();
		}

		void PageStackEntry::wrap(::Windows::UI::Xaml::Navigation::PageStackEntry^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void PageStackEntry::JSExportInitialize()
		{
			JSExport<PageStackEntry>::SetClassVersion(1);
			JSExport<PageStackEntry>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(PageStackEntry, NavigationTransitionInfo);
			TITANIUM_ADD_PROPERTY_READONLY(PageStackEntry, Parameter);
			TITANIUM_ADD_PROPERTY_READONLY(PageStackEntry, SourcePageType);
			TITANIUM_ADD_PROPERTY_READONLY(PageStackEntry, SourcePageTypeProperty);
		}

		TITANIUM_PROPERTY_GETTER(PageStackEntry, NavigationTransitionInfo)
		{
			auto value = unwrap()->NavigationTransitionInfo;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(PageStackEntry, Parameter)
		{
			auto value = unwrap()->Parameter;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<object>::Class());
			auto result_wrapper = result.GetPrivate<object>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(PageStackEntry, SourcePageType)
		{
			auto value = unwrap()->SourcePageType;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Name", context.CreateNumber(static_cast<int32_t>(value.Name)));
			result.SetProperty("Kind", context.CreateNumber(static_cast<int32_t>(value.Kind)));

			return result;
		}

		TITANIUM_PROPERTY_GETTER(PageStackEntry, SourcePageTypeProperty)
		{
			auto value = unwrap()->SourcePageTypeProperty;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::DependencyProperty>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::DependencyProperty>();
			result_wrapper->wrap(value);

			return result;
		}

				} // namespace Navigation
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
