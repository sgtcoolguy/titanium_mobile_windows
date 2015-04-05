/**
 * Titanium.UI.TableView
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
		TableView::TableView(const JSContext& js_context) TITANIUM_NOEXCEPT
        	: View(js_context),
			search__(get_context().CreateUndefined()),
        	filterAttribute__(""),
        	filterAnchored__(false),
        	filterCaseInsensitive__(true),
        	footerTitle__(""),
        	headerTitle__(""),
        	maxRowHeight__(0),
        	minRowHeight__(0),
        	rowHeight__(0),
        	separatorColor__("")
    	{
			TITANIUM_LOG_INFO("TableView ctor");
    	}

		std::vector<TableViewSection_shared_ptr_t> TableView::get_sections() const TITANIUM_NOEXCEPT
    	{
        	return sections__;
		}

		void TableView::set_sections(const std::vector<TableViewSection_shared_ptr_t>& sections) TITANIUM_NOEXCEPT
    	{
        	sections__ = sections;
		}

		std::vector<JSObject> TableView::get_data() const TITANIUM_NOEXCEPT
    	{
        	return data__;
		}

		void TableView::setData(std::vector<JSObject>& data, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			data__ = data;
		}

		std::string TableView::get_filterAttribute() const TITANIUM_NOEXCEPT
    	{
        	return filterAttribute__;
		}

		bool TableView::get_filterAnchored() const TITANIUM_NOEXCEPT
    	{
        	return filterAnchored__;
		}

		bool TableView::get_filterCaseInsensitive() const TITANIUM_NOEXCEPT
    	{
        	return filterCaseInsensitive__;
		}

		std::string TableView::get_footerTitle() const TITANIUM_NOEXCEPT
    	{
        	return footerTitle__;
		}

		View_shared_ptr_t TableView::get_footerView() const TITANIUM_NOEXCEPT
    	{
			return footerView__;
		}

		std::string TableView::get_headerTitle() const TITANIUM_NOEXCEPT
    	{
        	return headerTitle__;
		}

		View_shared_ptr_t TableView::get_headerView() const TITANIUM_NOEXCEPT
    	{
			return headerView__;
		}

		double TableView::get_maxRowHeight() const TITANIUM_NOEXCEPT
    	{
        	return maxRowHeight__;
		}

		double TableView::get_minRowHeight() const TITANIUM_NOEXCEPT
    	{
        	return minRowHeight__;
		}

		double TableView::get_rowHeight() const TITANIUM_NOEXCEPT
    	{
        	return rowHeight__;
		}

		JSValue TableView::get_search() const TITANIUM_NOEXCEPT
    	{
			return get_context().CreateUndefined();
		}

		uint32_t TableView::get_sectionCount() const TITANIUM_NOEXCEPT
    	{
			return static_cast<uint32_t>(sections__.size());
		}

		std::string TableView::get_separatorColor() const TITANIUM_NOEXCEPT
    	{
        	return separatorColor__;
		}

		void TableView::appendRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::appendRow: Unimplemented");
		}

		void TableView::appendSection(const TableViewSection_shared_ptr_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.push_back(section);
			set_sections(sections__);
		}

		void TableView::deleteRow(const TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::deleteRow: Unimplemented");
		}

		void TableView::deleteSection(uint32_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			sections__.erase(sections__.begin()+section);
			set_sections(sections__);
		}

		void TableView::insertRowAfter(uint32_t index, JSValue row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowAfter: Unimplemented");
		}

		void TableView::insertSectionAfter(uint32_t index, JSValue section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertSectionAfter: Unimplemented");
		}

		void TableView::insertRowBefore(uint32_t index, JSValue row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertRowBefore: Unimplemented");
		}

		void TableView::insertSectionBefore(uint32_t index, JSValue section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::insertSectionBefore: Unimplemented");
		}

		void TableView::scrollToIndex(uint32_t index, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToIndex: Unimplemented");
		}

		void TableView::scrollToTop(uint32_t top, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::scrollToTop: Unimplemented");
		}

		void TableView::selectRow(uint32_t row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::selectRow: Unimplemented");
		}

		void TableView::updateRow(uint32_t index, TableViewRow_shared_ptr_t row, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::updateRow: Unimplemented");
		}

		void TableView::updateSection(uint32_t index, TableViewSection_shared_ptr_t section, const std::shared_ptr<TableViewAnimationProperties>& animation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableView::updateSection: Unimplemented");
		}

		void TableView::JSExportInitialize() {
			JSExport<TableView>::SetClassVersion(1);
			JSExport<TableView>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(TableView, data);
			TITANIUM_ADD_FUNCTION(TableView, getData);
			TITANIUM_ADD_FUNCTION(TableView, setData);

			TITANIUM_ADD_PROPERTY_READONLY(TableView, filterAttribute);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, filterAnchored);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, filterCaseInsensitive);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, footerTitle);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, footerView);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, headerTitle);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, headerView);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, maxRowHeight);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, minRowHeight);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, rowHeight);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, search);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, sectionCount);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, sections);
			TITANIUM_ADD_PROPERTY_READONLY(TableView, separatorColor);

			TITANIUM_ADD_FUNCTION(TableView, appendRow);
			TITANIUM_ADD_FUNCTION(TableView, appendSection);
			TITANIUM_ADD_FUNCTION(TableView, deleteRow);
			TITANIUM_ADD_FUNCTION(TableView, deleteSection);
			TITANIUM_ADD_FUNCTION(TableView, insertRowAfter);
			TITANIUM_ADD_FUNCTION(TableView, insertSectionAfter);
			TITANIUM_ADD_FUNCTION(TableView, insertRowBefore);
			TITANIUM_ADD_FUNCTION(TableView, insertSectionBefore);
			TITANIUM_ADD_FUNCTION(TableView, scrollToIndex);
			TITANIUM_ADD_FUNCTION(TableView, scrollToTop);
			TITANIUM_ADD_FUNCTION(TableView, selectRow);
			TITANIUM_ADD_FUNCTION(TableView, updateRow);
			TITANIUM_ADD_FUNCTION(TableView, updateSection);
			TITANIUM_ADD_FUNCTION(TableView, getFilterAttribute);
			TITANIUM_ADD_FUNCTION(TableView, setFilterAttribute);
			TITANIUM_ADD_FUNCTION(TableView, getFilterAnchored);
			TITANIUM_ADD_FUNCTION(TableView, setFilterAnchored);
			TITANIUM_ADD_FUNCTION(TableView, getFilterCaseInsensitive);
			TITANIUM_ADD_FUNCTION(TableView, setFilterCaseInsensitive);
			TITANIUM_ADD_FUNCTION(TableView, getFooterTitle);
			TITANIUM_ADD_FUNCTION(TableView, setFooterTitle);
			TITANIUM_ADD_FUNCTION(TableView, getFooterView);
			TITANIUM_ADD_FUNCTION(TableView, setFooterView);
			TITANIUM_ADD_FUNCTION(TableView, getHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableView, setHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableView, getHeaderView);
			TITANIUM_ADD_FUNCTION(TableView, setHeaderView);
			TITANIUM_ADD_FUNCTION(TableView, getMaxRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setMaxRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getMinRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setMinRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, setRowHeight);
			TITANIUM_ADD_FUNCTION(TableView, getSearch);
			TITANIUM_ADD_FUNCTION(TableView, setSearch);
			TITANIUM_ADD_FUNCTION(TableView, getSectionCount);
			TITANIUM_ADD_FUNCTION(TableView, getSections);
			TITANIUM_ADD_FUNCTION(TableView, setSections);
			TITANIUM_ADD_FUNCTION(TableView, getSeparatorColor);
			TITANIUM_ADD_FUNCTION(TableView, setSeparatorColor);
		}

		TITANIUM_PROPERTY_GETTER(TableView, data)
		{
			std::vector<JSValue> data_array;
			const auto rows = get_data();
			for (auto row : rows) {
				data_array.push_back(row);
			}
			return get_context().CreateArray(data_array);
		}

		TITANIUM_PROPERTY_SETTER(TableView, data)
		{
			TITANIUM_ASSERT(argument.IsObject());

			auto data_obj = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(data_obj.IsArray());
			auto data = static_cast<std::vector<JSValue>>(static_cast<JSArray>(data_obj));

			auto animation = get_context().CreateObject();

			std::vector<JSObject> tableObjects;
			for (uint32_t i=0;i<data.size();i++) {
				auto tableObject = static_cast<JSObject>(data[i]);
				tableObjects.push_back(tableObject);
			}
			setData(tableObjects, animation.GetPrivate<TableViewAnimationProperties>());

			return false;
		}

		TITANIUM_FUNCTION(TableView, getData)
		{
			return js_get_data();
		}

		TITANIUM_FUNCTION(TableView, setData)
		{
			if (arguments.size() >= 1) {
				js_set_data(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TableView, filterAttribute)
		{
			return get_context().CreateString(get_filterAttribute());
		}

		TITANIUM_PROPERTY_GETTER(TableView, filterAnchored)
		{
			return get_context().CreateBoolean(get_filterAnchored());
		}

		TITANIUM_PROPERTY_GETTER(TableView, filterCaseInsensitive)
		{
			return get_context().CreateBoolean(get_filterCaseInsensitive());
		}

		TITANIUM_PROPERTY_GETTER(TableView, footerTitle)
		{
			return get_context().CreateString(get_footerTitle());
		}

		TITANIUM_PROPERTY_GETTER(TableView, footerView)
		{
			return static_cast<JSValue>(get_footerView()->get_object());
		}

		TITANIUM_PROPERTY_GETTER(TableView, headerTitle)
		{
			return get_context().CreateString(get_headerTitle());
		}

		TITANIUM_PROPERTY_GETTER(TableView, headerView)
		{
			return static_cast<JSValue>(get_headerView()->get_object());
		}

		TITANIUM_PROPERTY_GETTER(TableView, maxRowHeight)
		{
			return get_context().CreateNumber(get_maxRowHeight());
		}

		TITANIUM_PROPERTY_GETTER(TableView, minRowHeight)
		{
			return get_context().CreateNumber(get_minRowHeight());
		}

		TITANIUM_PROPERTY_GETTER(TableView, rowHeight)
		{
			return get_context().CreateNumber(get_rowHeight());
		}

		TITANIUM_PROPERTY_GETTER(TableView, search)
		{
			return get_search();
		}

		TITANIUM_PROPERTY_GETTER(TableView, sections)
		{
			std::vector<JSValue> section_array;
			const auto section_objects = get_sections();
			for (auto section : section_objects) {
				section_array.push_back(section->get_object());
			}
			return get_context().CreateArray(section_array);
		}

		TITANIUM_PROPERTY_GETTER(TableView, sectionCount)
		{
			return get_context().CreateNumber(get_sectionCount());
		}

		TITANIUM_PROPERTY_GETTER(TableView, separatorColor)
		{
			return get_context().CreateString(get_separatorColor());
		}

		TITANIUM_FUNCTION(TableView, appendRow)
		{
			if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto row = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				appendRow(row.GetPrivate<TableViewRow>(), animation.GetPrivate<TableViewAnimationProperties>());
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				const auto animation = get_context().CreateObject();
				appendRow(row.GetPrivate<TableViewRow>(), animation.GetPrivate<TableViewAnimationProperties>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, appendSection)
		{
			if (arguments.size() < 1) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const auto section = static_cast<JSObject>(_0);
				const auto animation = static_cast<JSObject>(_1);
				appendSection(section.GetPrivate<TableViewSection>(), animation.GetPrivate<TableViewAnimationProperties>());
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto section = static_cast<JSObject>(_0);
				const auto animation = get_context().CreateObject();
				appendSection(section.GetPrivate<TableViewSection>(), animation.GetPrivate<TableViewAnimationProperties>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, deleteRow)
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

		TITANIUM_FUNCTION(TableView, deleteSection)
		{
			if (arguments.size() < 2) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 2) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				const uint32_t section = static_cast<uint32_t>(_0);
				const auto animation = static_cast<JSObject>(_1);
				deleteSection(section, animation.GetPrivate<TableViewAnimationProperties>());
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const uint32_t section = static_cast<uint32_t>(_0);
				const auto animation = get_context().CreateObject();
				deleteSection(section, animation.GetPrivate<TableViewAnimationProperties>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, insertRowAfter)
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

		TITANIUM_FUNCTION(TableView, insertSectionAfter)
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

		TITANIUM_FUNCTION(TableView, insertRowBefore)
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

		TITANIUM_FUNCTION(TableView, insertSectionBefore)
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

		TITANIUM_FUNCTION(TableView, scrollToIndex)
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

		TITANIUM_FUNCTION(TableView, scrollToTop)
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

		TITANIUM_FUNCTION(TableView, selectRow)
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

		TITANIUM_FUNCTION(TableView, updateRow)
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

		TITANIUM_FUNCTION(TableView, updateSection)
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

		TITANIUM_FUNCTION(TableView, getFilterAttribute)
		{
			TITANIUM_LOG_WARN("TableView.getFilterAttribute is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setFilterAttribute)
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

		TITANIUM_FUNCTION(TableView, getFilterAnchored)
		{
			TITANIUM_LOG_WARN("TableView.getFilterAnchored is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setFilterAnchored)
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

		TITANIUM_FUNCTION(TableView, getFilterCaseInsensitive)
		{
			TITANIUM_LOG_WARN("TableView.getFilterCaseInsensitive is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setFilterCaseInsensitive)
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

		TITANIUM_FUNCTION(TableView, getFooterTitle)
		{
			TITANIUM_LOG_WARN("TableView.getFooterTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setFooterTitle)
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

		TITANIUM_FUNCTION(TableView, getFooterView)
		{
			TITANIUM_LOG_WARN("TableView.getFooterView is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setFooterView)
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

		TITANIUM_FUNCTION(TableView, getHeaderTitle)
		{
			TITANIUM_LOG_WARN("TableView.getHeaderTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setHeaderTitle)
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

		TITANIUM_FUNCTION(TableView, getHeaderView)
		{
			TITANIUM_LOG_WARN("TableView.getHeaderView is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setHeaderView)
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

		TITANIUM_FUNCTION(TableView, getMaxRowHeight)
		{
			TITANIUM_LOG_WARN("TableView.getMaxRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setMaxRowHeight)
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

		TITANIUM_FUNCTION(TableView, getMinRowHeight)
		{
			TITANIUM_LOG_WARN("TableView.getMinRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setMinRowHeight)
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

		TITANIUM_FUNCTION(TableView, getRowHeight)
		{
			TITANIUM_LOG_WARN("TableView.getRowHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setRowHeight)
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

		TITANIUM_FUNCTION(TableView, getSearch)
		{
			TITANIUM_LOG_WARN("TableView.getSearch is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setSearch)
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

		TITANIUM_FUNCTION(TableView, getSectionCount)
		{
			TITANIUM_LOG_WARN("TableView.getSectionCount is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, getSections)
		{
			TITANIUM_LOG_WARN("TableView.getSections is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setSections)
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

		TITANIUM_FUNCTION(TableView, getSeparatorColor)
		{
			TITANIUM_LOG_WARN("TableView.getSeparatorColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableView, setSeparatorColor)
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