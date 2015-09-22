/**
* Titanium.UI.Picker for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/Picker.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/UI/PickerColumn.hpp"
#include "Titanium/UI/PickerRow.hpp"
#include "TitaniumWindows/UI/PickerRow.hpp"
#include "TitaniumWindows/UI/PickerColumn.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace Windows::UI::Xaml::Controls;
		using namespace Windows::UI::Xaml;

		Picker::Picker(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::Picker(js_context)
		{
			TITANIUM_LOG_DEBUG("Picker::ctor ", this);
		}

		Picker::~Picker() 
		{
			TITANIUM_LOG_DEBUG("Picker::dtor ", this);
		}

		void Picker::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::Picker::postCallAsConstructor(js_context, arguments);
			Titanium::UI::Picker::setLayoutDelegate<WindowsViewLayoutDelegate>();

			parent__ = ref new Windows::UI::Xaml::Controls::Grid();

			// Fill width
			layoutDelegate__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);
			layoutDelegate__->set_autoLayoutForWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutDelegate<WindowsViewLayoutDelegate>()->setComponent(parent__);

			// PICKER_TYPE_PLAIN by default
			set_type(Titanium::UI::PICKER_TYPE::PLAIN);
		}

		void Picker::set_type(const Titanium::UI::PICKER_TYPE& type) TITANIUM_NOEXCEPT
		{
			// Remove existing picker
			if (parent__->Children->Size > 0) {
				parent__->Children->RemoveAt(0);
			}

			if (type__ == Titanium::UI::PICKER_TYPE::PLAIN && plainPicker__ != nullptr) {
				plainPicker__  = nullptr;
			} else if (type__ == Titanium::UI::PICKER_TYPE::DATE && datePicker__ != nullptr) {
				datePicker__ = nullptr;
			} else if (type__ == Titanium::UI::PICKER_TYPE::TIME && timePicker__ != nullptr) {
				timePicker__ = nullptr;
			}

			// Update property
			Titanium::UI::Picker::set_type(type);

			// Create new picker
			if (type == Titanium::UI::PICKER_TYPE::PLAIN) {
				plainPicker__  = ref new Windows::UI::Xaml::Controls::Grid();
				parent__->Children->Append(plainPicker__);
				parent__->SetColumn(plainPicker__, 0);
				parent__->SetRow(plainPicker__, 0);
			} else if (type == Titanium::UI::PICKER_TYPE::DATE) {
				datePicker__  = ref new Windows::UI::Xaml::Controls::DatePicker();
				parent__->Children->Append(datePicker__);
				parent__->SetColumn(datePicker__, 0);
				parent__->SetRow(datePicker__, 0);
			} else if (type == Titanium::UI::PICKER_TYPE::TIME) {
				timePicker__  = ref new Windows::UI::Xaml::Controls::TimePicker();
				parent__->Children->Append(timePicker__);
				parent__->SetColumn(timePicker__, 0);
				parent__->SetRow(timePicker__, 0);
			}
		}

		void Picker::add_columns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Picker::add_columns(columns);
			createColumns(columns);
		}

		void Picker::set_columns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns) TITANIUM_NOEXCEPT
		{
			Titanium::UI::Picker::set_columns(columns);
			plainPicker__->Children->Clear();
			createColumns(columns);
		}

		void Picker::createColumns(const std::vector<std::shared_ptr<Titanium::UI::PickerColumn>>& columns)
		{
			if (type__ == Titanium::UI::PICKER_TYPE::PLAIN) {
				for (const auto c : columns) {
					const auto column = std::dynamic_pointer_cast<TitaniumWindows::UI::PickerColumn>(c);
					const auto picker = column->getComponent();

					column->refreshRows();

					plainPicker__->Children->Append(picker);

					const auto cdef = ref new ColumnDefinition();
					cdef->Width = GridLengthHelper::FromValueAndType(1.0, GridUnitType::Star); // <RowDefinition Height="*"/>
					plainPicker__->ColumnDefinitions->Append(cdef);
					plainPicker__->SetColumn(picker, (plainPicker__->Children->Size - 1));
					plainPicker__->SetRow(picker, 0);
				}
			} else {
				TITANIUM_LOG_WARN("Picker::add: Unable to modify columns. This only works with plain picker");
			}
		}

		void Picker::add_rows(const std::vector<std::shared_ptr<Titanium::UI::PickerRow>>& rows) TITANIUM_NOEXCEPT
		{
			if (type__ == Titanium::UI::PICKER_TYPE::PLAIN) {
				std::shared_ptr<Titanium::UI::PickerColumn> column;
				if (columns__.size() == 0) {
					// Create new column if no column is created
					auto Column_ctor = get_context().CreateObject(JSExport<TitaniumWindows::UI::PickerColumn>::Class());
					column = Column_ctor.CallAsConstructor().GetPrivate<TitaniumWindows::UI::PickerColumn>();
				} else {
					// Add to existing column
					column = columns__.at(0);
				}
				for (const auto row : rows) {
					column->addRow(row);
				}
				add_columns({ column });
			}
		}

		void Picker::JSExportInitialize()
		{
			JSExport<Picker>::SetClassVersion(1);
			JSExport<Picker>::SetParent(JSExport<Titanium::UI::Picker>::Class());
		}

	} // namespace UI
} // namespace TitaniumWindows
