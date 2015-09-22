/**
 * TitaniumKit Titanium.UI.Picker
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_PICKER_HPP_
#define _TITANIUM_UI_PICKER_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Constants.hpp"
#include "Titanium/UI/Font.hpp"
#include <chrono>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class PickerColumn;
		class PickerRow;

		/*!
		  @struct
		  @discussion An abstract datatype for specifying a properties for showPickerDateDialog
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.Picker-method-showDatePickerDialog
		*/
		struct PickerDialogOption
		{
			std::string title;
			std::string okButtonTitle;
			std::chrono::system_clock::time_point value;
			JSValue callback; // need to keep these references to prevent from GC
			std::function<void(const bool& cancel, const std::chrono::system_clock::time_point& value)> oncallback;
		};
		
		TITANIUMKIT_EXPORT PickerDialogOption js_to_PickerDialogOption(const JSObject& object);

		/*!
		  @class
		  @discussion This is the Titanium Picker Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Picker
		*/
		class TITANIUMKIT_EXPORT Picker : public View, public JSExport<Picker>
		{

		public:

			/*!
			  @property
			  @abstract columns
			  @discussion Columns used for this picker, as an array of <Titanium.UI.PickerColumn> objects.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::vector<std::shared_ptr<PickerColumn>>, columns);

			/*!
			  @property
			  @abstract countDownDuration
			  @discussion Duration in milliseconds used for a Countdown Timer picker.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, countDownDuration);

			/*!
			  @property
			  @abstract format24
			  @discussion Determines whether the Time pickers display in 24-hour or 12-hour clock format.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, format24);

			/*!
			  @property
			  @abstract locale
			  @discussion Locale used when displaying Date and Time picker values.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, locale);

			/*!
			  @property
			  @abstract maxDate
			  @discussion Maximum date displayed when a Date picker is in use.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::system_clock::time_point, maxDate);

			/*!
			  @property
			  @abstract minDate
			  @discussion Minimum date displayed when a Date picker is in use.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::system_clock::time_point, minDate);

			/*!
			  @property
			  @abstract minuteInterval
			  @discussion Interval in minutes displayed when one of the Time types of pickers is in use.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::minutes, minuteInterval);

			/*!
			  @property
			  @abstract selectionIndicator
			  @discussion Determines whether the visual selection indicator is shown.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, selectionIndicator);

			/*!
			  @property
			  @abstract useSpinner
			  @discussion Determines whether the non-native Android control, with a spinning wheel that looks and behaves like the iOS picker, is invoked rather than the default native "dropdown" style.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, useSpinner);

			/*!
			  @property
			  @abstract value
			  @discussion Date and time value for Date and Time pickers.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::chrono::system_clock::time_point, value);

			/*!
			  @property
			  @abstract visibleItems
			  @discussion Number of visible rows to display. This is only applicable to a plain picker and when the `useSpinner` is `true`.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, visibleItems);

			/*!
			  @property
			  @abstract calendarViewShown
			  @discussion Determines whether the calenderView is visible.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, calendarViewShown);

			/*!
			  @property
			  @abstract font
			  @discussion Font to use for text.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(Font, font);

			/*!
			  @property
			  @abstract type
			  @discussion Determines the type of picker displayed
			*/
			TITANIUM_PROPERTY_IMPL_DEF(PICKER_TYPE, type);

			/*!
			  @method
			  @abstract add
			  @discussion Adds rows or columns to the picker.
			*/
			virtual void add_rows(const std::vector<std::shared_ptr<PickerRow>>& rows) TITANIUM_NOEXCEPT;
			virtual void add_columns(const std::vector<std::shared_ptr<PickerColumn>>& columns) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract reloadColumn
			  @discussion Repopulates values for a column.
			*/
			virtual void reloadColumn(const std::shared_ptr<PickerColumn>& column) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract getSelectedRow
			  @discussion Gets the selected row for a column, or `null` if none exists.
			*/
			virtual std::shared_ptr<PickerRow> getSelectedRow(const std::uint32_t& index) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setSelectedRow
			  @discussion Selects a column's row.
			*/
			virtual void setSelectedRow(const std::uint32_t& column, const std::uint32_t& row, const bool& animated) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setValue
			  @discussion Sets the date and time value property for Date pickers.
			*/
			virtual void setValue(std::chrono::system_clock::time_point date, const bool& suppressEvent) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract showDatePickerDialog
			  @discussion Shows Date picker as a modal dialog.
			*/
			virtual void showDatePickerDialog(const PickerDialogOption& option) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract showTimePickerDialog
			  @discussion Shows Time picker as a modal dialog.
			*/
			virtual void showTimePickerDialog(const PickerDialogOption& option) TITANIUM_NOEXCEPT;

			Picker(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~Picker()                = default;
			Picker(const Picker&)            = default;
			Picker& operator=(const Picker&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Picker(Picker&&)                 = default;
			Picker& operator=(Picker&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(columns);
			TITANIUM_PROPERTY_DEF(countDownDuration);
			TITANIUM_PROPERTY_DEF(format24);
			TITANIUM_PROPERTY_DEF(locale);
			TITANIUM_PROPERTY_DEF(maxDate);
			TITANIUM_PROPERTY_DEF(minDate);
			TITANIUM_PROPERTY_DEF(minuteInterval);
			TITANIUM_PROPERTY_DEF(selectionIndicator);
			TITANIUM_PROPERTY_DEF(useSpinner);
			TITANIUM_PROPERTY_DEF(value);
			TITANIUM_PROPERTY_DEF(visibleItems);
			TITANIUM_PROPERTY_DEF(calendarViewShown);
			TITANIUM_PROPERTY_DEF(font);
			TITANIUM_PROPERTY_DEF(type);

			TITANIUM_FUNCTION_DEF(add);
			TITANIUM_FUNCTION_DEF(reloadColumn);
			TITANIUM_FUNCTION_DEF(showDatePickerDialog);
			TITANIUM_FUNCTION_DEF(showTimePickerDialog);
			TITANIUM_FUNCTION_DEF(getSelectedRow);
			TITANIUM_FUNCTION_DEF(setSelectedRow);
			TITANIUM_FUNCTION_DEF(getColumns);
			TITANIUM_FUNCTION_DEF(setColumns);
			TITANIUM_FUNCTION_DEF(getCountDownDuration);
			TITANIUM_FUNCTION_DEF(setCountDownDuration);
			TITANIUM_FUNCTION_DEF(getFormat24);
			TITANIUM_FUNCTION_DEF(setFormat24);
			TITANIUM_FUNCTION_DEF(getLocale);
			TITANIUM_FUNCTION_DEF(setLocale);
			TITANIUM_FUNCTION_DEF(getMaxDate);
			TITANIUM_FUNCTION_DEF(setMaxDate);
			TITANIUM_FUNCTION_DEF(getMinDate);
			TITANIUM_FUNCTION_DEF(setMinDate);
			TITANIUM_FUNCTION_DEF(getMinuteInterval);
			TITANIUM_FUNCTION_DEF(setMinuteInterval);
			TITANIUM_FUNCTION_DEF(getSelectionIndicator);
			TITANIUM_FUNCTION_DEF(setSelectionIndicator);
			TITANIUM_FUNCTION_DEF(getUseSpinner);
			TITANIUM_FUNCTION_DEF(setUseSpinner);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);
			TITANIUM_FUNCTION_DEF(getVisibleItems);
			TITANIUM_FUNCTION_DEF(setVisibleItems);
			TITANIUM_FUNCTION_DEF(getCalendarViewShown);
			TITANIUM_FUNCTION_DEF(setCalendarViewShown);
			TITANIUM_FUNCTION_DEF(getFont);
			TITANIUM_FUNCTION_DEF(setFont);
			TITANIUM_FUNCTION_DEF(getType);
			TITANIUM_FUNCTION_DEF(setType);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::vector<std::shared_ptr<PickerColumn>> columns__;
			std::chrono::milliseconds countDownDuration__;
			bool format24__;
			std::string locale__;
			std::chrono::system_clock::time_point maxDate__;
			std::chrono::system_clock::time_point minDate__;
			std::chrono::minutes minuteInterval__;
			bool selectionIndicator__;
			bool useSpinner__;
			std::chrono::system_clock::time_point value__;
			std::uint32_t visibleItems__;
			bool calendarViewShown__;
			Font font__;
			PICKER_TYPE type__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_PICKER_HPP_