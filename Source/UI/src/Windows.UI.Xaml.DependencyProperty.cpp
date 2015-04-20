/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyProperty
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.PropertyMetadata.hpp"
#include "Windows.UI.Xaml.DependencyProperty.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{

		DependencyProperty::DependencyProperty(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void DependencyProperty::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::DependencyProperty();
		}

		::Windows::UI::Xaml::DependencyProperty^ DependencyProperty::unwrapWindows_UI_Xaml_DependencyProperty() const
		{
			return dynamic_cast<::Windows::UI::Xaml::DependencyProperty^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::DependencyProperty^ DependencyProperty::unwrap() const
		{
			return unwrapWindows_UI_Xaml_DependencyProperty();
		}

		void DependencyProperty::wrap(::Windows::UI::Xaml::DependencyProperty^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void DependencyProperty::JSExportInitialize()
		{
			JSExport<DependencyProperty>::SetClassVersion(1);
			JSExport<DependencyProperty>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(DependencyProperty, UnsetValue);
			TITANIUM_ADD_FUNCTION(DependencyProperty, GetMetadata);
			TITANIUM_ADD_FUNCTION(DependencyProperty, Register);
			TITANIUM_ADD_FUNCTION(DependencyProperty, RegisterAttached);
		}

		TITANIUM_PROPERTY_GETTER(DependencyProperty, UnsetValue)
		{
			auto value = unwrap()->UnsetValue;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<>::Class());
			auto native_wrapper = object.GetPrivate<>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(DependencyProperty, GetMetadata)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->GetMetadata();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(DependencyProperty, Register)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->Register();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(DependencyProperty, RegisterAttached)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()->RegisterAttached();
			return get_context().CreateBoolean(result); 
		}

			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
