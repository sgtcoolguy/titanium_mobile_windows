/**
 * Windows Native Wrapper for Windows.UI.Xaml.Data.RelativeSource
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Data.RelativeSource.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Data
				{

		RelativeSource::RelativeSource(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::DependencyObject(js_context)
		{
		}

		void RelativeSource::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
		}

		::Windows::UI::Xaml::Data::RelativeSource^ RelativeSource::unwrapWindows_UI_Xaml_Data_RelativeSource() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Data::RelativeSource^>(wrapped__);
		}

		::Windows::UI::Xaml::Data::RelativeSource^ RelativeSource::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Data_RelativeSource();
		}

		void RelativeSource::wrap(::Windows::UI::Xaml::Data::RelativeSource^ object)
		{
			wrapped__ = object;
		}

		void RelativeSource::JSExportInitialize()
		{
			JSExport<RelativeSource>::SetClassVersion(1);
			JSExport<RelativeSource>::SetParent(JSExport<Windows::UI::Xaml::DependencyObject>::Class());

			TITANIUM_ADD_PROPERTY(RelativeSource, Mode);
		}

		TITANIUM_PROPERTY_SETTER(RelativeSource, Mode)
		{
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::Windows::UI::Xaml::Data::RelativeSourceMode>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->Mode = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(RelativeSource, Mode)
		{
			auto value = unwrap()->Mode;
			auto context = get_context();
			auto result = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value))); // FIXME What if the enum isn't an int based one?!

			return result;
		}

				} // namespace Data
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium
