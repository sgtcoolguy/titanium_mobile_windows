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
        	return rows__.size();
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

			JSExport<TableViewSection>::AddValueProperty("footerTitle", std::mem_fn(&TableViewSection::js_get_footerTitle));
			JSExport<TableViewSection>::AddValueProperty("footerView", std::mem_fn(&TableViewSection::js_get_footerView));
			JSExport<TableViewSection>::AddValueProperty("headerTitle", std::mem_fn(&TableViewSection::js_get_headerTitle), std::mem_fn(&TableViewSection::js_set_headerTitle));
			JSExport<TableViewSection>::AddValueProperty("headerView", std::mem_fn(&TableViewSection::js_get_headerView));
			JSExport<TableViewSection>::AddValueProperty("rowCount", std::mem_fn(&TableViewSection::js_get_rowCount));
			JSExport<TableViewSection>::AddValueProperty("rows", std::mem_fn(&TableViewSection::js_get_rows));

			JSExport<TableViewSection>::AddFunctionProperty("add", std::mem_fn(&TableViewSection::js_add));
			JSExport<TableViewSection>::AddFunctionProperty("remove", std::mem_fn(&TableViewSection::js_remove));
			JSExport<TableViewSection>::AddFunctionProperty("rowAtIndex", std::mem_fn(&TableViewSection::js_rowAtIndex));
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
		}

		JSValue TableViewSection::js_get_footerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_footerTitle());
		}

		JSValue TableViewSection::js_get_footerView() const TITANIUM_NOEXCEPT
		{
			auto view = get_footerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		JSValue TableViewSection::js_get_headerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_headerTitle());
		}

		JSValue TableViewSection::js_get_headerView() const TITANIUM_NOEXCEPT
		{
			auto view = get_headerView();
			if (view) {
				return view->get_object();
			}  else {
				return get_context().CreateNull();	
			}
		}

		JSValue TableViewSection::js_get_rowCount() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_rowCount());
		}

		JSValue TableViewSection::js_get_rows() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> js_items;
			for (auto& item : get_rows()) {
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

		JSValue TableViewSection::js_rowAtIndex(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const auto index = static_cast<uint32_t>(_0);
				rowAtIndex(index);
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
			return js_get_footerView();
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
			return js_get_headerTitle();
		}

		bool TableViewSection::js_set_headerTitle(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_headerTitle(static_cast<std::string>(argument));
			return true;
		}

		JSValue TableViewSection::js_setHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_headerTitle(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_headerView();
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
			return get_context().CreateNumber(get_rowCount());
		}

		JSValue TableViewSection::js_getRows(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_rows();
		}
	} // namespace UI
} // namespace Titanium