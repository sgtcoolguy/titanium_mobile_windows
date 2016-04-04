/**
* Titanium.UI.PickerRow for Windows
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_UI_PICKERROW_HPP_
#define _TITANIUMWINDOWS_UI_PICKERROW_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/PickerRow.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class PickerRow
		  @ingroup Titanium.UI.PickerRow

		  @discussion This is the Titanium.UI.PickerRow implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT PickerRow final : public Titanium::UI::PickerRow, public JSExport<PickerRow>
		{
		public:
			PickerRow(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~PickerRow();
			PickerRow(const PickerRow&) = default;
			PickerRow& operator=(const PickerRow&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			PickerRow(PickerRow&&) = default;
			PickerRow& operator=(PickerRow&&) = default;
#endif

			static void JSExportInitialize();
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			Windows::UI::Xaml::Controls::ComboBoxItem^ getComboBoxItem() TITANIUM_NOEXCEPT
			{
				return item__;
			}

			virtual void set_color(const std::string& color) TITANIUM_NOEXCEPT override;
			virtual void set_title(const std::string& text) TITANIUM_NOEXCEPT override;
			virtual void set_font(const Titanium::UI::Font& font) TITANIUM_NOEXCEPT override;

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			Windows::UI::Xaml::Controls::ComboBoxItem^ item__;
			Windows::UI::Xaml::Controls::TextBlock^ label__;
#pragma warning(pop)
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_PICKERROW_HPP_
