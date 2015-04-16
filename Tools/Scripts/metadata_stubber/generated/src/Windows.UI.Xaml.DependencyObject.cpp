/**
 * Windows Native Wrapper for Windows.UI.Xaml.DependencyObject
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.DependencyObject.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{

		DependencyObject::DependencyObject(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context, arguments)
		{
		}

		void DependencyObject::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new Windows::UI::Xaml::DependencyObject();
		}

		Windows::UI::Xaml::DependencyObject^ DependencyObject::unwrapWindows_UI_Xaml_DependencyObject()
		{
			return dynamic_cast<Windows::UI::Xaml::DependencyObject^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void DependencyObject::wrap(Windows::UI::Xaml::DependencyObject^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void DependencyObject::JSExportInitialize()
		{
			JSExport<DependencyObject>::SetClassVersion(1);
			JSExport<DependencyObject>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(DependencyObject, Dispatcher);
			TITANIUM_ADD_FUNCTION(DependencyObject, GetValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, SetValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, ClearValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, ReadLocalValue);
			TITANIUM_ADD_FUNCTION(DependencyObject, GetAnimationBaseValue);
		}

		TITANIUM_PROPERTY_GETTER(DependencyObject, Dispatcher)
		{
			auto value = wrapped__->Dispatcher;
			auto context = get_context();
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto object = context.CreateObject(JSExport<Windows::UI::Core::CoreDispatcher>::Class());
			auto native_wrapper = object.GetPrivate<Windows::UI::Core::CoreDispatcher>();
			native_wrapper->wrap(value);
			return object;
		}

		TITANIUM_FUNCTION(DependencyObject, GetValue)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetValue();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(DependencyObject, SetValue)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->SetValue();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(DependencyObject, ClearValue)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			wrapped__->ClearValue();
			return get_context().CreateUndefined(); 
		}

		TITANIUM_FUNCTION(DependencyObject, ReadLocalValue)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->ReadLocalValue();
			return get_context().CreateBoolean(result); 
		}

		TITANIUM_FUNCTION(DependencyObject, GetAnimationBaseValue)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__->GetAnimationBaseValue();
			return get_context().CreateBoolean(result); 
		}

		} // namespace Xaml
	} // namespace UI
} // namespace Windows
