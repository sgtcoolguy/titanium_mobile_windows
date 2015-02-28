/**
 * Titanium.UI.TableView for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TableView.hpp"

namespace Titanium
{
	namespace UI
	{
    	TableView::TableView(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
        	: View(js_context, arguments),
        	backgroundColor__(""),
			search__(get_context().CreateUndefined()),
        	filterAttribute__(""),
        	filterAnchored__(false),
        	filterCaseInsensitive__(true),
        	footerTitle__(""),
        	headerTitle__(""),
        	maxRowHeight__(0),
        	minRowHeight__(0),
        	rowHeight__(0),
        	sectionCount__(0),
        	separatorColor__("")
    	{
    	}

		std::string TableView::backgroundColor() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::backgroundColor: Unimplemented");
        	return backgroundColor__;
		}

		std::vector<TableViewRow_shared_ptr_t> TableView::data() const TITANIUM_NOEXCEPT
    	{
        	return data__;
		}

		std::string TableView::filterAttribute() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::filterAttribute: Unimplemented");
        	return filterAttribute__;
		}

		bool TableView::filterAnchored() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::filterAnchored: Unimplemented");
        	return filterAnchored__;
		}

		bool TableView::filterCaseInsensitive() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::filterCaseInsensitive: Unimplemented");
        	return filterCaseInsensitive__;
		}

		std::string TableView::footerTitle() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::footerTitle: Unimplemented");
        	return footerTitle__;
		}

		JSValue TableView::footerView() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::footerView: Unimplemented");
			return get_context().CreateUndefined();
		}

		std::string TableView::headerTitle() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::headerTitle: Unimplemented");
        	return headerTitle__;
		}

		JSValue TableView::headerView() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::headerView: Unimplemented");
			return get_context().CreateUndefined();
		}

		double TableView::maxRowHeight() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::maxRowHeight: Unimplemented");
        	return maxRowHeight__;
		}

		double TableView::minRowHeight() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::minRowHeight: Unimplemented");
        	return minRowHeight__;
		}

		double TableView::rowHeight() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::rowHeight: Unimplemented");
        	return rowHeight__;
		}

		JSValue TableView::search() const TITANIUM_NOEXCEPT
    	{
			return get_context().CreateUndefined();
		}

		uint32_t TableView::sectionCount() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::sectionCount: Unimplemented");
			return 0;
		}

		JSValue TableView::sections() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::sections: Unimplemented");
			return get_context().CreateUndefined();
		}

		std::string TableView::separatorColor() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableView::separatorColor: Unimplemented");
        	return separatorColor__;
		}

		JSValue TableView::appendRow(JSValue row, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::appendRow: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::appendSection(JSValue section, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::appendSection: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::deleteRow(JSValue row, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::deleteRow: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::deleteSection(double section, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::deleteSection: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::insertRowAfter(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowAfter: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::insertSectionAfter(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertSectionAfter: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::insertRowBefore(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowBefore: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::insertSectionBefore(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertSectionBefore: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::scrollToIndex(double index, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToIndex: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::scrollToTop(double top, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToTop: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::selectRow(double row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::selectRow: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::setData(JSValue data, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::setData: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::updateRow(double index, JSValue row, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::updateRow: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableView::updateSection(double index, JSValue section, JSValue animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::updateSection: Unimplemented");
			return get_context().CreateUndefined();
		}

		void TableView::JSExportInitialize() {
			JSExport<TableView>::SetClassVersion(1);
			JSExport<TableView>::SetParent(JSExport<Module>::Class());

			JSExport<TableView>::AddValueProperty("backgroundColor", std::mem_fn(&TableView::js_backgroundColor));
			JSExport<TableView>::AddValueProperty("data", std::mem_fn(&TableView::js_data));
			JSExport<TableView>::AddValueProperty("filterAttribute", std::mem_fn(&TableView::js_filterAttribute));
			JSExport<TableView>::AddValueProperty("filterAnchored", std::mem_fn(&TableView::js_filterAnchored));
			JSExport<TableView>::AddValueProperty("filterCaseInsensitive", std::mem_fn(&TableView::js_filterCaseInsensitive));
			JSExport<TableView>::AddValueProperty("footerTitle", std::mem_fn(&TableView::js_footerTitle));
			JSExport<TableView>::AddValueProperty("footerView", std::mem_fn(&TableView::js_footerView));
			JSExport<TableView>::AddValueProperty("headerTitle", std::mem_fn(&TableView::js_headerTitle));
			JSExport<TableView>::AddValueProperty("headerView", std::mem_fn(&TableView::js_headerView));
			JSExport<TableView>::AddValueProperty("maxRowHeight", std::mem_fn(&TableView::js_maxRowHeight));
			JSExport<TableView>::AddValueProperty("minRowHeight", std::mem_fn(&TableView::js_minRowHeight));
			JSExport<TableView>::AddValueProperty("rowHeight", std::mem_fn(&TableView::js_rowHeight));
			JSExport<TableView>::AddValueProperty("search", std::mem_fn(&TableView::js_search));
			JSExport<TableView>::AddValueProperty("sectionCount", std::mem_fn(&TableView::js_sectionCount));
			JSExport<TableView>::AddValueProperty("sections", std::mem_fn(&TableView::js_sections));
			JSExport<TableView>::AddValueProperty("separatorColor", std::mem_fn(&TableView::js_separatorColor));

			JSExport<TableView>::AddFunctionProperty("appendRow", std::mem_fn(&TableView::js_appendRow));
			JSExport<TableView>::AddFunctionProperty("appendSection", std::mem_fn(&TableView::js_appendSection));
			JSExport<TableView>::AddFunctionProperty("deleteRow", std::mem_fn(&TableView::js_deleteRow));
			JSExport<TableView>::AddFunctionProperty("deleteSection", std::mem_fn(&TableView::js_deleteSection));
			JSExport<TableView>::AddFunctionProperty("insertRowAfter", std::mem_fn(&TableView::js_insertRowAfter));
			JSExport<TableView>::AddFunctionProperty("insertSectionAfter", std::mem_fn(&TableView::js_insertSectionAfter));
			JSExport<TableView>::AddFunctionProperty("insertRowBefore", std::mem_fn(&TableView::js_insertRowBefore));
			JSExport<TableView>::AddFunctionProperty("insertSectionBefore", std::mem_fn(&TableView::js_insertSectionBefore));
			JSExport<TableView>::AddFunctionProperty("scrollToIndex", std::mem_fn(&TableView::js_scrollToIndex));
			JSExport<TableView>::AddFunctionProperty("scrollToTop", std::mem_fn(&TableView::js_scrollToTop));
			JSExport<TableView>::AddFunctionProperty("selectRow", std::mem_fn(&TableView::js_selectRow));
			JSExport<TableView>::AddFunctionProperty("setData", std::mem_fn(&TableView::js_setData));
			JSExport<TableView>::AddFunctionProperty("updateRow", std::mem_fn(&TableView::js_updateRow));
			JSExport<TableView>::AddFunctionProperty("updateSection", std::mem_fn(&TableView::js_updateSection));
			JSExport<TableView>::AddFunctionProperty("getBackgroundColor", std::mem_fn(&TableView::js_getBackgroundColor));
			JSExport<TableView>::AddFunctionProperty("setBackgroundColor", std::mem_fn(&TableView::js_setBackgroundColor));
			JSExport<TableView>::AddFunctionProperty("getData", std::mem_fn(&TableView::js_getData));
			JSExport<TableView>::AddFunctionProperty("setData", std::mem_fn(&TableView::js_setData));
			JSExport<TableView>::AddFunctionProperty("getFilterAttribute", std::mem_fn(&TableView::js_getFilterAttribute));
			JSExport<TableView>::AddFunctionProperty("setFilterAttribute", std::mem_fn(&TableView::js_setFilterAttribute));
			JSExport<TableView>::AddFunctionProperty("getFilterAnchored", std::mem_fn(&TableView::js_getFilterAnchored));
			JSExport<TableView>::AddFunctionProperty("setFilterAnchored", std::mem_fn(&TableView::js_setFilterAnchored));
			JSExport<TableView>::AddFunctionProperty("getFilterCaseInsensitive", std::mem_fn(&TableView::js_getFilterCaseInsensitive));
			JSExport<TableView>::AddFunctionProperty("setFilterCaseInsensitive", std::mem_fn(&TableView::js_setFilterCaseInsensitive));
			JSExport<TableView>::AddFunctionProperty("getFooterTitle", std::mem_fn(&TableView::js_getFooterTitle));
			JSExport<TableView>::AddFunctionProperty("setFooterTitle", std::mem_fn(&TableView::js_setFooterTitle));
			JSExport<TableView>::AddFunctionProperty("getFooterView", std::mem_fn(&TableView::js_getFooterView));
			JSExport<TableView>::AddFunctionProperty("setFooterView", std::mem_fn(&TableView::js_setFooterView));
			JSExport<TableView>::AddFunctionProperty("getHeaderTitle", std::mem_fn(&TableView::js_getHeaderTitle));
			JSExport<TableView>::AddFunctionProperty("setHeaderTitle", std::mem_fn(&TableView::js_setHeaderTitle));
			JSExport<TableView>::AddFunctionProperty("getHeaderView", std::mem_fn(&TableView::js_getHeaderView));
			JSExport<TableView>::AddFunctionProperty("setHeaderView", std::mem_fn(&TableView::js_setHeaderView));
			JSExport<TableView>::AddFunctionProperty("getMaxRowHeight", std::mem_fn(&TableView::js_getMaxRowHeight));
			JSExport<TableView>::AddFunctionProperty("setMaxRowHeight", std::mem_fn(&TableView::js_setMaxRowHeight));
			JSExport<TableView>::AddFunctionProperty("getMinRowHeight", std::mem_fn(&TableView::js_getMinRowHeight));
			JSExport<TableView>::AddFunctionProperty("setMinRowHeight", std::mem_fn(&TableView::js_setMinRowHeight));
			JSExport<TableView>::AddFunctionProperty("getRowHeight", std::mem_fn(&TableView::js_getRowHeight));
			JSExport<TableView>::AddFunctionProperty("setRowHeight", std::mem_fn(&TableView::js_setRowHeight));
			JSExport<TableView>::AddFunctionProperty("getSearch", std::mem_fn(&TableView::js_getSearch));
			JSExport<TableView>::AddFunctionProperty("setSearch", std::mem_fn(&TableView::js_setSearch));
			JSExport<TableView>::AddFunctionProperty("getSectionCount", std::mem_fn(&TableView::js_getSectionCount));
			JSExport<TableView>::AddFunctionProperty("getSections", std::mem_fn(&TableView::js_getSections));
			JSExport<TableView>::AddFunctionProperty("setSections", std::mem_fn(&TableView::js_setSections));
			JSExport<TableView>::AddFunctionProperty("getSeparatorColor", std::mem_fn(&TableView::js_getSeparatorColor));
			JSExport<TableView>::AddFunctionProperty("setSeparatorColor", std::mem_fn(&TableView::js_setSeparatorColor));
		}

		JSValue TableView::js_backgroundColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(backgroundColor());
		}

		JSValue TableView::js_data() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> data_array;
			const auto rows = data();
			for (auto row : rows) {
				data_array.push_back(row->get_object());
			}
			return get_context().CreateArray(data_array);
		}

		JSValue TableView::js_filterAttribute() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(filterAttribute());
		}

		JSValue TableView::js_filterAnchored() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(filterAnchored());
		}

		JSValue TableView::js_filterCaseInsensitive() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(filterCaseInsensitive());
		}

		JSValue TableView::js_footerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(footerTitle());
		}

		JSValue TableView::js_footerView() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateUndefined(); //footerView();
		}

		JSValue TableView::js_headerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(headerTitle());
		}

		JSValue TableView::js_headerView() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateUndefined(); //headerView();
		}

		JSValue TableView::js_maxRowHeight() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(maxRowHeight());
		}

		JSValue TableView::js_minRowHeight() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(minRowHeight());
		}

		JSValue TableView::js_rowHeight() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(rowHeight());
		}

		JSValue TableView::js_search() const TITANIUM_NOEXCEPT
		{
			return search();
		}

		JSValue TableView::js_sections() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateUndefined(); //sections();
		}

		JSValue TableView::js_separatorColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(separatorColor());
		}

		JSValue TableView::js_appendRow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.appendRow is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const auto row = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// appendRow(row, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				// appendRow(row);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_appendSection(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.appendSection is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const auto section = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// appendSection(section, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto section = static_cast<JSObject>(_0);
				// appendSection(section);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_deleteRow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.deleteRow is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const auto row = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// deleteRow(row, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				// deleteRow(row);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_deleteSection(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.deleteSection is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const double section = static_cast<double>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// deleteSection(section, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double section = static_cast<double>(_0);
				// deleteSection(section);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_insertRowAfter(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.insertRowAfter is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertRowAfter(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// insertRowAfter(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertRowAfter(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_insertSectionAfter(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.insertSectionAfter is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertSectionAfter(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// insertSectionAfter(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertSectionAfter(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_insertRowBefore(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.insertRowBefore is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertRowBefore(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// insertRowBefore(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertRowBefore(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_insertSectionBefore(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.insertSectionBefore is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// insertSectionBefore(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// insertSectionBefore(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// insertSectionBefore(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_scrollToIndex(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.scrollToIndex is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// scrollToIndex(index, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// scrollToIndex(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_scrollToTop(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.scrollToTop is not implemented yet");
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTableViewAnimationProperties());
				const double top = static_cast<double>(_0);
				const auto animation = static_cast<JSObject>(_1);
				// scrollToTop(top, animation);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double top = static_cast<double>(_0);
				// scrollToTop(top);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_selectRow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.selectRow is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double row = static_cast<double>(_0);
				// selectRow(row);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_updateRow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.updateRow is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewRow());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// updateRow(index, row, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewRow());
				const double index = static_cast<double>(_0);
				const auto row = static_cast<JSObject>(_1);
				// updateRow(index, row);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// updateRow(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_updateSection(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.updateSection is not implemented yet");
			if (arguments.size() < 3) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 3) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewSection());
				const auto _2 = arguments.at(2);
				//TITANIUM_ASSERT(_2.IsTableViewAnimationProperties());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				const auto animation = static_cast<JSObject>(_2);
				// updateSection(index, section, animation);
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				//TITANIUM_ASSERT(_1.IsTitanium.UI.TableViewSection());
				const double index = static_cast<double>(_0);
				const auto section = static_cast<JSObject>(_1);
				// updateSection(index, section);
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double index = static_cast<double>(_0);
				// updateSection(index);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getBackgroundColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getBackgroundColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setBackgroundColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setBackgroundColor is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string backgroundColor = static_cast<std::string>(_0);
				// setBackgroundColor(backgroundColor);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getData(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getData is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setData(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setData is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto data = static_cast<JSObject>(_0);
				// setData(data);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getFilterAttribute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getFilterAttribute is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setFilterAttribute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setFilterAttribute is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string filterAttribute = static_cast<std::string>(_0);
				// setFilterAttribute(filterAttribute);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getFilterAnchored(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getFilterAnchored is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setFilterAnchored(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setFilterAnchored is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsBoolean());
				const bool filterAnchored = static_cast<bool>(_0);
				// setFilterAnchored(filterAnchored);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getFilterCaseInsensitive(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getFilterCaseInsensitive is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setFilterCaseInsensitive(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setFilterCaseInsensitive is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsBoolean());
				const bool filterCaseInsensitive = static_cast<bool>(_0);
				// setFilterCaseInsensitive(filterCaseInsensitive);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getFooterTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setFooterTitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string footerTitle = static_cast<std::string>(_0);
				// setFooterTitle(footerTitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getFooterView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setFooterView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto footerView = static_cast<JSObject>(_0);
				// setFooterView(footerView);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getHeaderTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setHeaderTitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string headerTitle = static_cast<std::string>(_0);
				// setHeaderTitle(headerTitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getHeaderView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setHeaderView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto headerView = static_cast<JSObject>(_0);
				// setHeaderView(headerView);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getMaxRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getMaxRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setMaxRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setMaxRowHeight is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double maxRowHeight = static_cast<double>(_0);
				// setMaxRowHeight(maxRowHeight);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getMinRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getMinRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setMinRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setMinRowHeight is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double minRowHeight = static_cast<double>(_0);
				// setMinRowHeight(minRowHeight);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setRowHeight(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setRowHeight is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double rowHeight = static_cast<double>(_0);
				// setRowHeight(rowHeight);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getSearch(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getSearch is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setSearch(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setSearch is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto search = static_cast<JSObject>(_0);
				// setSearch(search);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getSectionCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getSectionCount is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getSections(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getSections is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setSections(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setSections is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto sections = static_cast<JSObject>(_0);
				// setSections(sections);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_getSeparatorColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.getSeparatorColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableView::js_setSeparatorColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView.setSeparatorColor is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string separatorColor = static_cast<std::string>(_0);
				// setSeparatorColor(separatorColor);
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium