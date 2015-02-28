/**
 * Titanium.UI.TableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TABLEVIEW_HPP_
#define _TITANIUM_TABLEVIEW_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/TableViewRow.hpp"
#include "Titanium/UI/TableViewSection.hpp"
#include <vector>
#include <unordered_map>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

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
			  @abstract backgroundColor
			  @discussion Background color of the view, as a color name or hex triplet.
			*/
			virtual std::string backgroundColor() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract data
			  @discussion Rows of the table view.
			*/
			virtual std::vector<TableViewRow_shared_ptr_t> data() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterAttribute
			  @discussion Filter attribute to be used when searching.
			*/
			virtual std::string filterAttribute() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterAnchored
			  @discussion Determines whether the search is limited to the start of the string
			*/
			virtual bool filterAnchored() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract filterCaseInsensitive
			  @discussion Determines whether the search is case insensitive.
			*/
			virtual bool filterCaseInsensitive() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerTitle
			  @discussion Table view footer title.
			*/
			virtual std::string footerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract footerView
			  @discussion Table view footer as a view that will be rendered instead of a label.
			*/
			virtual JSValue footerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerTitle
			  @discussion Table view header title.
			*/
			virtual std::string headerTitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract headerView
			  @discussion Table view header as a view that will be rendered instead of a label.
			*/
			virtual JSValue headerView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract maxRowHeight
			  @discussion Maximum row height for table view rows.
			*/
			virtual double maxRowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract minRowHeight
			  @discussion Minimum row height for table view rows.
			*/
			virtual double minRowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rowHeight
			  @discussion Default row height for table view rows.
			*/
			virtual double rowHeight() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract search
			  @discussion Search field to use for the table view.
			*/
			virtual JSValue search() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract sectionCount
			  @discussion Number of sections in this table view.
			*/
			virtual uint32_t sectionCount() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract sections
			  @discussion Sections of this table.
			*/
			virtual JSValue sections() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract separatorColor
			  @discussion Separator line color between rows, as a color name or hex triplet.
			*/
			virtual std::string separatorColor() const TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendRow
			  @discussion Appends a single row or an array of rows to the end of the table.
			*/
			virtual JSValue appendRow(JSValue row, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract appendSection
			  @discussion Appends a single section or an array of sections to the end of the table.
			*/
			virtual JSValue appendSection(JSValue section, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteRow
			  @discussion Deletes an existing row.
			*/
			virtual JSValue deleteRow(JSValue row, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract deleteSection
			  @discussion Deletes an existing section.
			*/
			virtual JSValue deleteSection(double section, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertRowAfter
			  @discussion Inserts a row after another row.
			*/
			virtual JSValue insertRowAfter(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertSectionAfter
			  @discussion Inserts a section after another section.
			*/
			virtual JSValue insertSectionAfter(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertRowBefore
			  @discussion Inserts a row before another row.
			*/
			virtual JSValue insertRowBefore(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract insertSectionBefore
			  @discussion Inserts a section before another section.
			*/
			virtual JSValue insertSectionBefore(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scrollToIndex
			  @discussion Scrolls the table view to ensure that the specified row is on screen.
			*/
			virtual JSValue scrollToIndex(double index, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract scrollToTop
			  @discussion Scrolls the table to a specific top position where 0 is the topmost y position in the table view.
			*/
			virtual JSValue scrollToTop(double top, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract selectRow
			  @discussion Programmatically selects a row. In Android, it sets the currently selected item. If in touch mode,the item will not be selected but it will still be positioned appropriately. If the specified selection position is less than 0, then the item at position 0 will be selected.
			*/
			virtual JSValue selectRow(double row) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setData
			  @discussion Sets the data in the table.
			*/
			virtual JSValue setData(JSValue data, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract updateRow
			  @discussion Updates an existing row, optionally with animation.
			*/
			virtual JSValue updateRow(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract updateSection
			  @discussion Updates an existing section, optionally with animation.
			*/
			virtual JSValue updateSection(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT;

			TableView(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~TableView() = default;
			TableView(const TableView&) = default;
			TableView& operator=(const TableView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableView(TableView&&)                 = default;
			TableView& operator=(TableView&&)      = default;
#endif

			static void JSExportInitialize();

			virtual JSValue js_backgroundColor() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_data() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_filterAttribute() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_filterAnchored() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_filterCaseInsensitive() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_footerTitle() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_footerView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_headerTitle() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_headerView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_maxRowHeight() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_minRowHeight() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_rowHeight() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_search() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_sectionCount() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_sections() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_separatorColor() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_appendRow(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_appendSection(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_deleteRow(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_deleteSection(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_insertRowAfter(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_insertSectionAfter(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_insertRowBefore(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_insertSectionBefore(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_scrollToIndex(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_scrollToTop(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_selectRow(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_updateRow(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_updateSection(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getBackgroundColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setBackgroundColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getData(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setData(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFilterAttribute(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFilterAttribute(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFilterAnchored(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFilterAnchored(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFilterCaseInsensitive(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFilterCaseInsensitive(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFooterTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFooterTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFooterView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFooterView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHeaderTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHeaderTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHeaderView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHeaderView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getMaxRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setMaxRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getMinRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setMinRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRowHeight(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSearch(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSearch(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSectionCount(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSections(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSections(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSeparatorColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSeparatorColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string backgroundColor__;
				std::vector<TableViewRow_shared_ptr_t> data__;
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
				uint32_t sectionCount__;
				std::vector<TableViewSection_shared_ptr_t> sections__;
				std::string separatorColor__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEW_HPP_