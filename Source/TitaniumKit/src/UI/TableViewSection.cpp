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


    	TableViewSection::TableViewSection(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
        	: Module(js_context, arguments),
        	footerTitle__(""),
        	headerTitle__(""),
        	rowCount__(0)
    	{
    	}

		std::string TableViewSection::footerTitle() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::footerTitle: Unimplemented");
        	return footerTitle__;
		}

		JSValue TableViewSection::footerView() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::footerView: Unimplemented");
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		std::string TableViewSection::headerTitle() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::headerTitle: Unimplemented");
        	return headerTitle__;
		}

		JSValue TableViewSection::headerView() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::headerView: Unimplemented");
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		JSValue TableViewSection::rowCount() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::rowCount: Unimplemented");
			return get_context().CreateNull();
		}

		JSValue TableViewSection::rows() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewSection::rows: Unimplemented");
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		JSValue TableViewSection::add(JSValue row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection::add: Unimplemented");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::remove(JSValue row) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection::remove: Unimplemented");
			return get_context().CreateUndefined();
		}


		void TableViewSection::JSExportInitialize() {
			JSExport<TableViewSection>::SetClassVersion(1);
			JSExport<TableViewSection>::SetParent(JSExport<Module>::Class());

			JSExport<TableViewSection>::AddValueProperty("footerTitle", std::mem_fn(&TableViewSection::js_footerTitle));
			JSExport<TableViewSection>::AddValueProperty("footerView", std::mem_fn(&TableViewSection::js_footerView));
			JSExport<TableViewSection>::AddValueProperty("headerTitle", std::mem_fn(&TableViewSection::js_headerTitle));
			JSExport<TableViewSection>::AddValueProperty("headerView", std::mem_fn(&TableViewSection::js_headerView));
			JSExport<TableViewSection>::AddValueProperty("rowCount", std::mem_fn(&TableViewSection::rowCount));
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
		}

		JSValue TableViewSection::js_footerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(footerTitle());
		}

		JSValue TableViewSection::js_footerView() const TITANIUM_NOEXCEPT
		{
			return footerView();
		}

		JSValue TableViewSection::js_headerTitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(headerTitle());
		}

		JSValue TableViewSection::js_headerView() const TITANIUM_NOEXCEPT
		{
			return headerView();
		}

		JSValue TableViewSection::js_rows() const TITANIUM_NOEXCEPT
		{
			return rows();
		}

		JSValue TableViewSection::js_add(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.add is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.TableViewRow());
				const auto row = static_cast<JSObject>(_0);
				// add(row);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_remove(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.remove is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.TableViewRow());
				const auto row = static_cast<JSObject>(_0);
				// remove(row);
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
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string footerTitle = static_cast<std::string>(_0);
				// setFooterTitle(footerTitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getFooterView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_setFooterView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.setFooterView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto footerView = static_cast<JSObject>(_0);
				// setFooterView(footerView);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getHeaderTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_setHeaderTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.setHeaderTitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string headerTitle = static_cast<std::string>(_0);
				// setHeaderTitle(headerTitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getHeaderView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_setHeaderView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.setHeaderView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsTitanium.UI.View());
				const auto headerView = static_cast<JSObject>(_0);
				// setHeaderView(headerView);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getRowCount(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getRowCount is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewSection::js_getRows(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewSection.getRows is not implemented yet");
			return get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium