/**
* Titanium.UI.Picker for Windows
*
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_UI_PICKER_HPP_
#define _TITANIUMWINDOWS_UI_PICKER_HPP_

#include "TitaniumWindows_UI_EXPORT.h"
#include "Titanium/UI/Picker.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutDelegate.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.Picker implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT Picker final : public Titanium::UI::Picker, public JSExport<Picker>
		{
		public:

			/*!
			@method
			@abstract add
			@discussion Adds rows or columns to the picker.
			*/
			virtual void add_rows(const std::vector<std::shared_ptr<Titanium::UI::PickerRow>>& rows) TITANIUM_NOEXCEPT override;
			virtual void add_columns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns) TITANIUM_NOEXCEPT override;

			/*!
			@property
			@abstract type
			@discussion Determines the type of picker displayed
			*/
			virtual void set_type(const Titanium::UI::PICKER_TYPE& type) TITANIUM_NOEXCEPT override;

			/*!
			@property
			@abstract columns
			@discussion Columns used for this picker, as an array of <Titanium.UI.PickerColumn> objects.
			*/
			virtual void set_columns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns) TITANIUM_NOEXCEPT override;

			Picker(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Picker();
			Picker(const Picker&) = default;
			Picker& operator=(const Picker&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Picker(Picker&&) = default;
			Picker& operator=(Picker&&) = default;
#endif

			static void JSExportInitialize();
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			Windows::UI::Xaml::Controls::Grid^       parent__;      // Parent view
			Windows::UI::Xaml::Controls::Grid^       plainPicker__; // For PICKER_TYPE_PLAIN
			Windows::UI::Xaml::Controls::DatePicker^ datePicker__;  // For PICKER_TYPE_DATE
			Windows::UI::Xaml::Controls::TimePicker^ timePicker__;  // For PICKER_TYPE_TIME

			void createColumns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns);
#pragma warning(pop)
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_PICKER_HPP_
