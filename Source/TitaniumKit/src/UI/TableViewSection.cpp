/**
 * Titanium.UI.TableViewSection
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TableViewSection.hpp"

namespace Titanium
{
	namespace UI
	{
    	TableViewSection::TableViewSection(const JSContext& js_context) TITANIUM_NOEXCEPT
        	: Module(js_context),
        	footerTitle__(""),
        	headerTitle__("")
    	{
			TITANIUM_LOG_INFO("Titanium::UI::TableViewSection ctor");
    	}

		std::string TableViewSection::get_footerTitle() const TITANIUM_NOEXCEPT
    	{
        	return footerTitle__;
		}

		View_shared_ptr_t TableViewSection::get_footerView() const TITANIUM_NOEXCEPT
    	{
        	return footerView__;
		}

		std::string TableViewSection::get_headerTitle() const TITANIUM_NOEXCEPT
    	{
        	return headerTitle__;
		}

		void TableViewSection::set_headerTitle(const std::string& title) TITANIUM_NOEXCEPT
    	{
        	headerTitle__ = title;
		}

		View_shared_ptr_t TableViewSection::get_headerView() const TITANIUM_NOEXCEPT
    	{
        	return headerView__;
		}

		uint32_t TableViewSection::get_rowCount() const TITANIUM_NOEXCEPT
    	{
        	return static_cast<uint32_t>(rows__.size());
		}

		std::vector<TableViewRow_shared_ptr_t> TableViewSection::get_rows() const TITANIUM_NOEXCEPT
    	{
        	return rows__;
		}

		void TableViewSection::add(TableViewRow_shared_ptr_t row) TITANIUM_NOEXCEPT
		{
			rows__.push_back(row);
		}

		void TableViewSection::remove(TableViewRow_shared_ptr_t row) TITANIUM_NOEXCEPT
		{
			rows__.erase(find(rows__.begin(), rows__.end(), row));
		}

		TableViewRow_shared_ptr_t TableViewSection::rowAtIndex(uint32_t index) TITANIUM_NOEXCEPT
		{
			return rows__.at(index);
		}

		void TableViewSection::JSExportInitialize() {
			JSExport<TableViewSection>::SetClassVersion(1);
			JSExport<TableViewSection>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(TableViewSection, footerTitle);
			TITANIUM_ADD_PROPERTY_READONLY(TableViewSection, footerView);
			TITANIUM_ADD_PROPERTY(TableViewSection, headerTitle);
			TITANIUM_ADD_PROPERTY_READONLY(TableViewSection, headerView);
			TITANIUM_ADD_PROPERTY_READONLY(TableViewSection, rowCount);
			TITANIUM_ADD_PROPERTY_READONLY(TableViewSection, rows);

			TITANIUM_ADD_FUNCTION(TableViewSection, add);
			TITANIUM_ADD_FUNCTION(TableViewSection, remove);
			TITANIUM_ADD_FUNCTION(TableViewSection, rowAtIndex);
			TITANIUM_ADD_FUNCTION(TableViewSection, getFooterTitle);
			TITANIUM_ADD_FUNCTION(TableViewSection, setFooterTitle);
			TITANIUM_ADD_FUNCTION(TableViewSection, getFooterView);
			TITANIUM_ADD_FUNCTION(TableViewSection, setFooterView);
			TITANIUM_ADD_FUNCTION(TableViewSection, getHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableViewSection, setHeaderTitle);
			TITANIUM_ADD_FUNCTION(TableViewSection, getHeaderView);
			TITANIUM_ADD_FUNCTION(TableViewSection, setHeaderView);
			TITANIUM_ADD_FUNCTION(TableViewSection, getRowCount);
			TITANIUM_ADD_FUNCTION(TableViewSection, getRows);
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, footerTitle)
		{
			return get_context().CreateString(get_footerTitle());
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, footerView)
		{
			auto view = get_footerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, headerTitle)
		{
			return get_context().CreateString(get_headerTitle());
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, headerView)
		{
			auto view = get_headerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, rowCount)
		{
			return get_context().CreateNumber(get_rowCount());
		}

		TITANIUM_PROPERTY_GETTER(TableViewSection, rows)
		{
			std::vector<JSValue> js_items;
			for (auto& item : get_rows()) {
				js_items.push_back(item->get_object());
			}
			return get_context().CreateArray(js_items);
		}

		TITANIUM_FUNCTION(TableViewSection, add)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				add(row.GetPrivate<TableViewRow>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, remove)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				remove(row.GetPrivate<TableViewRow>());
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, rowAtIndex)
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto index = static_cast<uint32_t>(_0);
				rowAtIndex(index);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, getFooterTitle)
		{
			TITANIUM_LOG_WARN("TableViewSection.getFooterTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, setFooterTitle)
		{
			TITANIUM_LOG_WARN("TableViewSection.setFooterTitle is not implemented yet");
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string footerTitle = static_cast<std::string>(_0);
				// setFooterTitle(footerTitle);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, getFooterView)
		{
			return js_get_footerView();
		}

		TITANIUM_FUNCTION(TableViewSection, setFooterView)
		{
			TITANIUM_LOG_WARN("TableViewSection.setFooterView is not implemented yet");
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto footerView = static_cast<JSObject>(_0);
				// setFooterView(footerView);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, getHeaderTitle)
		{
			return js_get_headerTitle();
		}

		TITANIUM_PROPERTY_SETTER(TableViewSection, headerTitle)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_headerTitle(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TableViewSection, setHeaderTitle)
		{
			if (arguments.size() >= 1) {
				js_set_headerTitle(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, getHeaderView)
		{
			return js_get_headerView();
		}

		TITANIUM_FUNCTION(TableViewSection, setHeaderView)
		{
			TITANIUM_LOG_WARN("TableViewSection.setHeaderView is not implemented yet");
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto headerView = static_cast<JSObject>(_0);
				//setHeaderView(headerView);
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewSection, getRowCount)
		{
			return get_context().CreateNumber(get_rowCount());
		}

		TITANIUM_FUNCTION(TableViewSection, getRows)
		{
			return js_get_rows();
		}
	} // namespace UI
} // namespace Titanium