/**
* Titanium.UI.PickerRow for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/PickerRow.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{

		PickerRow::PickerRow(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::PickerRow(js_context)
		{
			TITANIUM_LOG_DEBUG("PickerRow::ctor ", this);
		}

		PickerRow::~PickerRow() 
		{
			TITANIUM_LOG_DEBUG("PickerRow::dtor ", this);
		}

		void PickerRow::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::PickerRow::postCallAsConstructor(js_context, arguments);
			label__ = ref new Windows::UI::Xaml::Controls::TextBlock();
			Titanium::UI::PickerRow::setLayoutDelegate<WindowsViewLayoutDelegate>();
			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(label__);
		}

		void PickerRow::set_color(const std::string& colorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::PickerRow::set_color(colorName);
			const auto color_obj = WindowsViewLayoutDelegate::ColorForName(colorName);
			label__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(color_obj);
		}

		void PickerRow::set_title(const std::string& text) TITANIUM_NOEXCEPT
		{
			Titanium::UI::PickerRow::set_title(text);
			label__->Text = TitaniumWindows::Utility::ConvertUTF8String(text);
		}

		void PickerRow::JSExportInitialize()
		{
			JSExport<PickerRow>::SetClassVersion(1);
			JSExport<PickerRow>::SetParent(JSExport<Titanium::UI::PickerRow>::Class());
		}

	} // namespace UI
} // namespace TitaniumWindows
