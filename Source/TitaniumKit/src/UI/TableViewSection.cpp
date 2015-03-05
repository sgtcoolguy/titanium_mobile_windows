/**
 * Titanium.UI.TableViewSection for Windows
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
        	headerTitle__(""),
        	rowCount__(0)
    	{
			TITANIUM_LOG_INFO("Titanium::UI::TableViewSection ctor");
    	}

		std::string TableViewSection::footerTitle() const TITANIUM_NOEXCEPT
    	{
        	return footerTitle__;
		}

		View_shared_ptr_t TableViewSection::footerView() const TITANIUM_NOEXCEPT
    	{
        	return footerView__;
		}

		std::string TableViewSection::headerTitle() const TITANIUM_NOEXCEPT
    	{
        	return headerTitle__;
		}

		View_shared_ptr_t TableViewSection::headerView() const TITANIUM_NOEXCEPT
    	{
        	return headerView__;
		}

		uint32_t TableViewSection::rowCount() const TITANIUM_NOEXCEPT
    	{
        	return rowCount__;
		}

		std::vector<TableViewRow_shared_ptr_t> TableViewSection::rows() const TITANIUM_NOEXCEPT
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

		void TableViewSection::JSExportInitialize() {
			JSExport<TableViewSection>::SetClassVersion(1);
			JSExport<TableViewSection>::SetParent(JSExport<Module>::Class());

			JSExport<TableViewSection>::AddValueProperty("footerTitle", std::mem_fn(&TableViewSection::js_footerTitle));
			JSExport<TableViewSection>::AddValueProperty("footerView", std::mem_fn(&TableViewSection::js_footerView));
			JSExport<TableViewSection>::AddValueProperty("headerTitle", std::mem_fn(&TableViewSection::js_headerTitle));
			JSExport<TableViewSection>::AddValueProperty("headerView", std::mem_fn(&TableViewSection::js_headerView));
			JSExport<TableViewSection>::AddValueProperty("rowCount", std::mem_fn(&TableViewSection::js_rowCount));
			JSExport<TableViewSection>::AddValueProperty("rows", std::mem_fn(&TableViewSection::js_rows));

			JSExport<TableViewSection>::AddFunctionProperty("add", std::mem_fn(&TableViewSection::js_add));
			JSExport<TableViewSection>::AddFunctionProperty("remove", std::mem_fn(&TableViewSection::js_remove));
			JSExport<TableViewSection>::AddFunctionProperty("getFooterTitle", std::mem_fn(&TableViewSection::js_getFooterTitle));
			JSExport<TableViewSection>::AddFunctionProperty("setFooterTitle", std::mem_fn(&TableViewSection::js_setFooterTitle));
			JSExport<TableViewSection>::AddFunctionProperty("getFooterView", std::mem_fn(&TableViewSection::js_getFooterView));
			JSExport<TableViewSection>::AddFunctionProperty("setFooterView", std::mem_fn(&TableViewSection::js_setFooterView));
			JSExport<TableViewSection>::AddFunctionProperty("getHeaderTitle", std::mem_fn(&TableViewSection::js_getHeaderTitle));
			JSExport<TableViewSection>::AddFunctionProperty("setHeaderTitle", std::mem_fn(&TableViewSection::js_setHeaderTitle));
			JSExport<TableViewSection>::AddFunctionProperty("getHeaderView", std::mem_fn(&TableViewSection::js_getHeaderView));
			JSExport<TableViewSection>::AddFunctionProperty("setHeaderView", std::mem_fn(&TableViewSection::js_setHeaderView));
			JSExport<TableViewSection>::AddFunctionProperty("getRowCount", std::mem_fn(&TableViewSection::js_getRowCount));
			JSExport<TableViewSection>::AddFunctionProperty("getRows", std::mem_fn(&TableViewSection::js_getRows));

			JSExport<TableViewSection>::AddValueProperty("_TableViewSection", std::mem_fn(&TableViewSection::_TableViewSection));
		}

		JSValue TableViewSection::_TableViewSection() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_footerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(footerTitle());
		}

		JSValue TableViewSection::js_footerView() const TITANIUM_NOEXCEPT
		{
			auto view = footerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		JSValue TableViewSection::js_headerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(headerTitle());
		}

		JSValue TableViewSection::js_headerView() const TITANIUM_NOEXCEPT
		{
			auto view = headerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		JSValue TableViewSection::js_rowCount() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(rowCount());
		}

		JSValue TableViewSection::js_rows() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> js_items;
			for (auto& item : rows()) {
				js_items.push_back(item->get_object());
			}
			return get_context().CreateArray(js_items);
		}

		JSValue TableViewSection::js_add(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				add(row.GetPrivate<TableViewRow>());
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_remove(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto row = static_cast<JSObject>(_0);
				remove(row.GetPrivate<TableViewRow>());
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getFooterTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_setFooterTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue TableViewSection::js_getFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_footerView();
		}

		JSValue TableViewSection::js_setFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue TableViewSection::js_getHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_headerTitle();
		}

		JSValue TableViewSection::js_setHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.setHeaderTitle is not implemented yet");
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string headerTitle = static_cast<std::string>(_0);
				// setHeaderTitle(headerTitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_headerView();
		}

		JSValue TableViewSection::js_setHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
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

		JSValue TableViewSection::js_getRowCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(rowCount());
		}

		JSValue TableViewSection::js_getRows(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_rows();
		}

	} // namespace UI
} // namespace Titanium