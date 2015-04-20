/**
 * Windows Native Wrapper for Windows.UI.Xaml.Input.Pointer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Input.Pointer.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Input
				{

		Pointer::Pointer(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Module(js_context)
		{
		}

		void Pointer::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new ::Windows::UI::Xaml::Input::Pointer();
		}

		::Windows::UI::Xaml::Input::Pointer^ Pointer::unwrapWindows_UI_Xaml_Input_Pointer() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Input::Pointer^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		::Windows::UI::Xaml::Input::Pointer^ Pointer::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Input_Pointer();
		}

		void Pointer::wrap(::Windows::UI::Xaml::Input::Pointer^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void Pointer::JSExportInitialize()
		{
			JSExport<Pointer>::SetClassVersion(1);
			JSExport<Pointer>::SetParent(JSExport<Titanium::Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(Pointer, IsInContact);
			TITANIUM_ADD_PROPERTY_READONLY(Pointer, IsInRange);
			TITANIUM_ADD_PROPERTY_READONLY(Pointer, PointerDeviceType);
			TITANIUM_ADD_PROPERTY_READONLY(Pointer, PointerId);
		}

		TITANIUM_PROPERTY_GETTER(Pointer, IsInContact)
		{
			auto value = unwrap()->IsInContact;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Pointer, IsInRange)
		{
			auto value = unwrap()->IsInRange;
			auto context = get_context();
 			auto result = context.CreateBoolean(value); 

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Pointer, PointerDeviceType)
		{
			auto value = unwrap()->PointerDeviceType;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

		TITANIUM_PROPERTY_GETTER(Pointer, PointerId)
		{
			auto value = unwrap()->PointerId;
			auto context = get_context();
 			auto result = context.CreateNumber(value);

			return result;
		}

				} // namespace Input
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
