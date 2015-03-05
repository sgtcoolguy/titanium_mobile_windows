/**
 * Titanium.UI.TableViewRow for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TableViewRow.hpp"

namespace Titanium
{
	namespace UI
	{
    	TableViewRow::TableViewRow(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
        	: View(js_context, arguments),
        	color__(""),
        	hasCheck__(false),
        	hasChild__(false),
        	title__("")
    	{
    	}

		std::string TableViewRow::color() const TITANIUM_NOEXCEPT
    	{
        	return color__;
		}

		void TableViewRow::setColor(std::string color) TITANIUM_NOEXCEPT {
			color__ = color;
		}

		Font TableViewRow::font() const TITANIUM_NOEXCEPT
    	{
        	return font__;
		}

		void TableViewRow::setFont(Font font) TITANIUM_NOEXCEPT {
			font__ = font;
		}

		bool TableViewRow::hasCheck() const TITANIUM_NOEXCEPT
    	{
        	return hasCheck__;
		}

		void TableViewRow::setHasCheck(bool hasCheck) TITANIUM_NOEXCEPT {
			hasCheck__ = hasCheck;
		}

		bool TableViewRow::hasChild() const TITANIUM_NOEXCEPT
    	{
        	return hasChild__;
		}

		void TableViewRow::setHasChild(bool hasChild) TITANIUM_NOEXCEPT {
			hasChild__ = hasChild;
		}

		std::string TableViewRow::title() const TITANIUM_NOEXCEPT
    	{
        	return title__;
		}

		void TableViewRow::setTitle(std::string title) TITANIUM_NOEXCEPT {
			title__ = title;
		}

		void TableViewRow::JSExportInitialize() {
			JSExport<TableViewRow>::SetClassVersion(1);
			JSExport<TableViewRow>::SetParent(JSExport<View>::Class());

			JSExport<TableViewRow>::AddValueProperty("color", std::mem_fn(&TableViewRow::js_color), std::mem_fn(&TableViewRow::js_set_color));
			JSExport<TableViewRow>::AddValueProperty("font", std::mem_fn(&TableViewRow::js_font), std::mem_fn(&TableViewRow::js_set_font));
			JSExport<TableViewRow>::AddValueProperty("hasCheck", std::mem_fn(&TableViewRow::js_hasCheck), std::mem_fn(&TableViewRow::js_set_hasCheck));
			JSExport<TableViewRow>::AddValueProperty("hasChild", std::mem_fn(&TableViewRow::js_hasChild), std::mem_fn(&TableViewRow::js_set_hasChild));
			JSExport<TableViewRow>::AddValueProperty("title", std::mem_fn(&TableViewRow::js_title), std::mem_fn(&TableViewRow::js_set_title));

			JSExport<TableViewRow>::AddFunctionProperty("getColor", std::mem_fn(&TableViewRow::js_getColor));
			JSExport<TableViewRow>::AddFunctionProperty("setColor", std::mem_fn(&TableViewRow::js_setColor));
			JSExport<TableViewRow>::AddFunctionProperty("getFont", std::mem_fn(&TableViewRow::js_getFont));
			JSExport<TableViewRow>::AddFunctionProperty("setFont", std::mem_fn(&TableViewRow::js_setFont));
			JSExport<TableViewRow>::AddFunctionProperty("getHasCheck", std::mem_fn(&TableViewRow::js_getHasCheck));
			JSExport<TableViewRow>::AddFunctionProperty("setHasCheck", std::mem_fn(&TableViewRow::js_setHasCheck));
			JSExport<TableViewRow>::AddFunctionProperty("getHasChild", std::mem_fn(&TableViewRow::js_getHasChild));
			JSExport<TableViewRow>::AddFunctionProperty("setHasChild", std::mem_fn(&TableViewRow::js_setHasChild));
			JSExport<TableViewRow>::AddFunctionProperty("getTitle", std::mem_fn(&TableViewRow::js_getTitle));
			JSExport<TableViewRow>::AddFunctionProperty("setTitle", std::mem_fn(&TableViewRow::js_setTitle));

			JSExport<TableViewRow>::AddValueProperty("_TableViewRow", std::mem_fn(&TableViewRow::_TableViewRow));
		}

		JSValue TableViewRow::_TableViewRow() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_color() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(color());
		}

		JSValue TableViewRow::js_font() const TITANIUM_NOEXCEPT
		{
			return Font_to_js(get_context(), font());
		}

		JSValue TableViewRow::js_hasCheck() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(hasCheck());
		}

		JSValue TableViewRow::js_hasChild() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(hasChild());
		}

		JSValue TableViewRow::js_title() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(title());
		}

		JSValue TableViewRow::js_getColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_color();
		}

		bool TableViewRow::js_set_color(const JSValue& argument) TITANIUM_NOEXCEPT {
			TITANIUM_ASSERT(argument.IsString());
			setColor(static_cast<std::string>(argument));
			return true;
		}

		JSValue TableViewRow::js_setColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_font();
		}

		bool TableViewRow::js_set_font(const JSValue& argument) TITANIUM_NOEXCEPT {
			TITANIUM_ASSERT(argument.IsObject());
			setFont(js_to_Font(static_cast<JSObject>(argument)));
			return true;
		}

		JSValue TableViewRow::js_setFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_font(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getHasCheck(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_hasCheck();
		}

		bool TableViewRow::js_set_hasCheck(const JSValue& argument) TITANIUM_NOEXCEPT {
			TITANIUM_ASSERT(argument.IsBoolean());
			setHasCheck(static_cast<bool>(argument));
			return true;
		}

		JSValue TableViewRow::js_setHasCheck(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_hasCheck(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getHasChild(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_hasChild();
		}

		bool TableViewRow::js_set_hasChild(const JSValue& argument) TITANIUM_NOEXCEPT {
			TITANIUM_ASSERT(argument.IsBoolean());
			setHasChild(static_cast<bool>(argument));
			return true;
		}

		JSValue TableViewRow::js_setHasChild(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_hasChild(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_title();
		}

		bool TableViewRow::js_set_title(const JSValue& argument) TITANIUM_NOEXCEPT {
			TITANIUM_ASSERT(argument.IsString());
			setTitle(static_cast<std::string>(argument));
			return true;
		}

		JSValue TableViewRow::js_setTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_title(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
} // namespace Titanium