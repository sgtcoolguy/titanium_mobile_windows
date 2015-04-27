/**
 * Windows Native Wrapper for Windows.UI.Xaml.Style
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.SetterBaseCollection.hpp"
#include "Windows.UI.Xaml.Style.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		Style::Style(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void Style::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Style^ Style::unwrapWindows_UI_Xaml_Style() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Style^>(wrapped__);
		}

		::Windows::UI::Xaml::Style^ Style::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Style();
		}

		void Style::wrap(::Windows::UI::Xaml::Style^ object)
		{
			wrapped__ = object;
		}

		void Style::JSExportInitialize()
		{
			JSExport<Style>::SetClassVersion(1);
			JSExport<Style>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY(Style, TargetType);
			TITANIUM_ADD_PROPERTY(Style, BasedOn);
			TITANIUM_ADD_PROPERTY_READONLY(Style, IsSealed);
			TITANIUM_ADD_PROPERTY_READONLY(Style, Setters);
			TITANIUM_ADD_FUNCTION(Style, Seal);
		}

		TITANIUM_PROPERTY_SETTER(Style, TargetType)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto value = ::Windows::UI::Xaml::Interop::TypeName(NaN0);
			// Assign fields explicitly since we cheated on constructor args
			auto Name = object_value.GetProperty("Name");
			value.Name = static_cast<int32_t>(Name);
			auto Kind = object_value.GetProperty("Kind");
			value.Kind = static_cast<int32_t>(Kind);


			unwrap()->TargetType = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Style, TargetType)
		{
			auto value = unwrap()->TargetType;
			auto context = get_context();
			auto result = context.CreateObject();
			result.SetProperty("Name", context.CreateNumber(static_cast<int32_t>(value.Name)));
			result.SetProperty("Kind", context.CreateNumber(static_cast<int32_t>(value.Kind)));

			return result;
		}

		TITANIUM_PROPERTY_SETTER(Style, BasedOn)
		{
 			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object_value = static_cast<JSObject>(argument);
			auto wrapper_value = object_value.GetPrivate<Windows::UI::Xaml::Style>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper_value->unwrapWindows_UI_Xaml_Style();


			unwrap()->BasedOn = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Style, BasedOn)
		{
			auto value = unwrap()->BasedOn;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::Style>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::Style>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Style, IsSealed)
		{
			auto value = unwrap()->IsSealed;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Style, Setters)
		{
			auto value = unwrap()->Setters;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto result = context.CreateObject(JSExport<Windows::UI::Xaml::SetterBaseCollection>::Class());
			auto result_wrapper = result.GetPrivate<Windows::UI::Xaml::SetterBaseCollection>();
			result_wrapper->wrap(value);

			return result;
		}

		TITANIUM_FUNCTION(Style, Seal)
		{
			unwrap()->Seal();
			return get_context().CreateUndefined(); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
