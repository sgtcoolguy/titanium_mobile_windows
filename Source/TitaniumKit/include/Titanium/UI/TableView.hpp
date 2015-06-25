/**
 * Titanium.UI.TableView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TABLEVIEW_HPP_
#define _TITANIUM_TABLEVIEW_HPP_

#include "Titanium/UI/View.hpp"

#include <vector>
#include <unordered_map>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class TableViewAnimationProperties;
		class TableViewRow;
		class TableViewSection;

		using TableViewSection_shared_ptr_t = std::shared_ptr<TableViewSection>;
		using TableViewRow_shared_ptr_t = std::shared_ptr<TableViewRow>;
		using View_shared_ptr_t = std::shared_ptr<View>;

		/*!
		  @class
		  @discussion This is the Titanium TableView Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TableView
		*/
		class TITANIUMKIT_EXPORT TableView : public View, public JSExport<TableView>
		{

		public:

			/*!
			  @property
			  @abstract data
			  @discussion Rows of the table view.
			*/
			virtual std::vector<JSObject> get_data() const TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setData
			  @discussion Sets the data in the table.
			*/
			virtual void setData(std::vector<JSObject>& data, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterAttribute
			  @discussion Filter attribute to be used when searching.
			*/
			virtual std::string get_filterAttribute() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterAnchored
			  @discussion Determines whether the search is limited to the start of the string
			*/
			virtual bool get_filterAnchored() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterCaseInsensitive
			  @discussion Determines whether the search is case insensitive.
			*/
			virtual bool get_filterCaseInsensitive() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerTitle
			  @discussion Table view footer title.
			*/
			virtual std::string get_footerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerView
			  @discussion Table view footer as a view that will be rendered instead of a label.
			*/
			virtual View_shared_ptr_t get_footerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Table view header title.
			*/
			virtual std::string get_headerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerView
			  @discussion Table view header as a view that will be rendered instead of a label.
			*/
			virtual View_shared_ptr_t get_headerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract maxRowHeight
			  @discussion Maximum row height for table view rows.
			*/
			virtual double get_maxRowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract minRowHeight
			  @discussion Minimum row height for table view rows.
			*/
			virtual double get_minRowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rowHeight
			  @discussion Default row height for table view rows.
			*/
			virtual double get_rowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract search
			  @discussion Search field to use for the table view.
			*/
			virtual JSValue get_search() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract sectionCount
			  @discussion Number of sections in this table view.
			*/
			virtual uint32_t get_sectionCount() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract sections
			  @discussion Sections of this table.
			*/
			virtual std::vector<TableViewSection_shared_ptr_t> get_sections() const TITANIUM_NOEXCEPT;
			virtual void set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract separatorColor
			  @discussion Separator line color between rows, as a color name or hex triplet.
			*/
			virtual std::string get_separatorColor() const TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendRow
			  @discussion Appends a single row or an array of rows to the end of the table.
			*/
			virtual void appendRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendSection
			  @discussion Appends a single section or an array of sections to the end of the table.
			*/
			virtual void appendSection(const TableViewSection_shared_ptr_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteRow
			  @discussion Deletes an existing row.
			*/
			virtual void deleteRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteSection
			  @discussion Deletes an existing section.
			*/
			virtual void deleteSection(uint32_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertRowAfter
			  @discussion Inserts a row after another row.
			*/
			virtual void insertRowAfter(uint32_t index, JSValue row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertSectionAfter
			  @discussion Inserts a section after another section.
			*/
			virtual void insertSectionAfter(uint32_t index, JSValue section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertRowBefore
			  @discussion Inserts a row before another row.
			*/
			virtual void insertRowBefore(uint32_t index, JSValue row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertSectionBefore
			  @discussion Inserts a section before another section.
			*/
			virtual void insertSectionBefore(uint32_t index, JSValue section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scrollToIndex
			  @discussion Scrolls the table view to ensure that the specified row is on screen.
			*/
			virtual void scrollToIndex(uint32_t index, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scrollToTop
			  @discussion Scrolls the table to a specific top position where 0 is the topmost y position in the table view.
			*/
			virtual void scrollToTop(uint32_t top, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract selectRow
			  @discussion Programmatically selects a row. In Android, it sets the currently selected item. If in touch mode,the item will not be selected but it will still be positioned appropriately. If the specified selection position is less than 0, then the item at position 0 will be selected.
			*/
			virtual void selectRow(uint32_t row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract updateRow
			  @discussion Updates an existing row, optionally with animation.
			*/
			virtual void updateRow(uint32_t index, TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract updateSection
			  @discussion Updates an existing section, optionally with animation.
			*/
			virtual void updateSection(uint32_t index, TableViewSection_shared_ptr_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT;

			TableView(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~TableView() = default;
			TableView(const TableView&) = default;
			TableView& operator=(const TableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableView(TableView&&)                 = default;
			TableView& operator=(TableView&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(data);
			TITANIUM_PROPERTY_READONLY_DEF(filterAttribute);
			TITANIUM_PROPERTY_READONLY_DEF(filterAnchored);
			TITANIUM_PROPERTY_READONLY_DEF(filterCaseInsensitive);
			TITANIUM_PROPERTY_READONLY_DEF(footerTitle);
			TITANIUM_PROPERTY_READONLY_DEF(footerView);
			TITANIUM_PROPERTY_READONLY_DEF(headerTitle);
			TITANIUM_PROPERTY_READONLY_DEF(headerView);
			TITANIUM_PROPERTY_READONLY_DEF(maxRowHeight);
			TITANIUM_PROPERTY_READONLY_DEF(minRowHeight);
			TITANIUM_PROPERTY_READONLY_DEF(rowHeight);
			TITANIUM_PROPERTY_READONLY_DEF(search);
			TITANIUM_PROPERTY_READONLY_DEF(sectionCount);
			TITANIUM_PROPERTY_READONLY_DEF(sections);
			TITANIUM_PROPERTY_READONLY_DEF(separatorColor);
			TITANIUM_FUNCTION_DEF(appendRow);
			TITANIUM_FUNCTION_DEF(appendSection);
			TITANIUM_FUNCTION_DEF(deleteRow);
			TITANIUM_FUNCTION_DEF(deleteSection);
			TITANIUM_FUNCTION_DEF(insertRowAfter);
			TITANIUM_FUNCTION_DEF(insertSectionAfter);
			TITANIUM_FUNCTION_DEF(insertRowBefore);
			TITANIUM_FUNCTION_DEF(insertSectionBefore);
			TITANIUM_FUNCTION_DEF(scrollToIndex);
			TITANIUM_FUNCTION_DEF(scrollToTop);
			TITANIUM_FUNCTION_DEF(selectRow);
			TITANIUM_FUNCTION_DEF(updateRow);
			TITANIUM_FUNCTION_DEF(updateSection);
			TITANIUM_FUNCTION_DEF(getData);
			TITANIUM_FUNCTION_DEF(setData);
			TITANIUM_FUNCTION_DEF(getFilterAttribute);
			TITANIUM_FUNCTION_DEF(setFilterAttribute);
			TITANIUM_FUNCTION_DEF(getFilterAnchored);
			TITANIUM_FUNCTION_DEF(setFilterAnchored);
			TITANIUM_FUNCTION_DEF(getFilterCaseInsensitive);
			TITANIUM_FUNCTION_DEF(setFilterCaseInsensitive);
			TITANIUM_FUNCTION_DEF(getFooterTitle);
			TITANIUM_FUNCTION_DEF(setFooterTitle);
			TITANIUM_FUNCTION_DEF(getFooterView);
			TITANIUM_FUNCTION_DEF(setFooterView);
			TITANIUM_FUNCTION_DEF(getHeaderTitle);
			TITANIUM_FUNCTION_DEF(setHeaderTitle);
			TITANIUM_FUNCTION_DEF(getHeaderView);
			TITANIUM_FUNCTION_DEF(setHeaderView);
			TITANIUM_FUNCTION_DEF(getMaxRowHeight);
			TITANIUM_FUNCTION_DEF(setMaxRowHeight);
			TITANIUM_FUNCTION_DEF(getMinRowHeight);
			TITANIUM_FUNCTION_DEF(setMinRowHeight);
			TITANIUM_FUNCTION_DEF(getRowHeight);
			TITANIUM_FUNCTION_DEF(setRowHeight);
			TITANIUM_FUNCTION_DEF(getSearch);
			TITANIUM_FUNCTION_DEF(setSearch);
			TITANIUM_FUNCTION_DEF(getSectionCount);
			TITANIUM_FUNCTION_DEF(getSections);
			TITANIUM_FUNCTION_DEF(setSections);
			TITANIUM_FUNCTION_DEF(getSeparatorColor);
			TITANIUM_FUNCTION_DEF(setSeparatorColor);

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::vector<JSObject> data__;
				std::string filterAttribute__;
				bool filterAnchored__;
				bool filterCaseInsensitive__;
				std::string footerTitle__;
				View_shared_ptr_t footerView__;
				std::string headerTitle__;
				View_shared_ptr_t headerView__;
				double maxRowHeight__;
				double minRowHeight__;
				double rowHeight__;
				JSValue search__;
				std::vector<TableViewSection_shared_ptr_t> sections__;
				std::string separatorColor__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEW_HPP_