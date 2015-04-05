/**
 * Titanium.UI.TableViewRow
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
    	TableViewRow::TableViewRow(const JSContext& js_context) TITANIUM_NOEXCEPT
        	: View(js_context),
        	color__(""),
        	hasCheck__(false),
        	hasChild__(false),
        	title__("")
    	{
    	}

		std::string TableViewRow::get_color() const TITANIUM_NOEXCEPT
    	{
        	return color__;
		}

		void TableViewRow::setColor(std::string color) TITANIUM_NOEXCEPT {
			color__ = color;
		}

		Font TableViewRow::get_font() const TITANIUM_NOEXCEPT
    	{
        	return font__;
		}

		void TableViewRow::setFont(Font font) TITANIUM_NOEXCEPT {
			font__ = font;
		}

		bool TableViewRow::get_hasCheck() const TITANIUM_NOEXCEPT
    	{
        	return hasCheck__;
		}

		void TableViewRow::setHasCheck(bool hasCheck) TITANIUM_NOEXCEPT {
			hasCheck__ = hasCheck;
		}

		bool TableViewRow::get_hasChild() const TITANIUM_NOEXCEPT
    	{
        	return hasChild__;
		}

		void TableViewRow::setHasChild(bool hasChild) TITANIUM_NOEXCEPT {
			hasChild__ = hasChild;
		}

		std::string TableViewRow::get_title() const TITANIUM_NOEXCEPT
    	{
        	return title__;
		}

		void TableViewRow::setTitle(std::string title) TITANIUM_NOEXCEPT {
			title__ = title;
		}

		void TableViewRow::JSExportInitialize() {
			JSExport<TableViewRow>::SetClassVersion(1);
			JSExport<TableViewRow>::SetParent(JSExport<View>::Class());

			TITANIUM_ADD_PROPERTY(TableViewRow, color);
			TITANIUM_ADD_PROPERTY(TableViewRow, font);
			TITANIUM_ADD_PROPERTY(TableViewRow, hasCheck);
			TITANIUM_ADD_PROPERTY(TableViewRow, hasChild);
			TITANIUM_ADD_PROPERTY(TableViewRow, title);

			TITANIUM_ADD_FUNCTION(TableViewRow, getColor);
			TITANIUM_ADD_FUNCTION(TableViewRow, setColor);
			TITANIUM_ADD_FUNCTION(TableViewRow, getFont);
			TITANIUM_ADD_FUNCTION(TableViewRow, setFont);
			TITANIUM_ADD_FUNCTION(TableViewRow, getHasCheck);
			TITANIUM_ADD_FUNCTION(TableViewRow, setHasCheck);
			TITANIUM_ADD_FUNCTION(TableViewRow, getHasChild);
			TITANIUM_ADD_FUNCTION(TableViewRow, setHasChild);
			TITANIUM_ADD_FUNCTION(TableViewRow, getTitle);
			TITANIUM_ADD_FUNCTION(TableViewRow, setTitle);
		}

		TITANIUM_PROPERTY_GETTER(TableViewRow, color)
		{
			return get_context().CreateString(get_color());
		}

		TITANIUM_PROPERTY_GETTER(TableViewRow, font)
		{
			return Font_to_js(get_context(), get_font());
		}

		TITANIUM_PROPERTY_GETTER(TableViewRow, hasCheck)
		{
			return get_context().CreateBoolean(get_hasCheck());
		}

		TITANIUM_PROPERTY_GETTER(TableViewRow, hasChild)
		{
			return get_context().CreateBoolean(get_hasChild());
		}

		TITANIUM_PROPERTY_GETTER(TableViewRow, title)
		{
			return get_context().CreateString(get_title());
		}

		TITANIUM_FUNCTION(TableViewRow, getColor)
		{
			return js_get_color();
		}

		TITANIUM_PROPERTY_SETTER(TableViewRow, color) 
		{
			TITANIUM_ASSERT(argument.IsString());
			setColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TableViewRow, setColor)
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewRow, getFont)
		{
			return js_get_font();
		}

		TITANIUM_PROPERTY_SETTER(TableViewRow, font) 
		{
			TITANIUM_ASSERT(argument.IsObject());
			setFont(js_to_Font(static_cast<JSObject>(argument)));
			return true;
		}

		TITANIUM_FUNCTION(TableViewRow, setFont)
		{
			if (arguments.size() >= 1) {
				js_set_font(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewRow, getHasCheck)
		{
			return js_get_hasCheck();
		}

		TITANIUM_PROPERTY_SETTER(TableViewRow, hasCheck) 
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			setHasCheck(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TableViewRow, setHasCheck)
		{
			if (arguments.size() >= 1) {
				js_set_hasCheck(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewRow, getHasChild)
		{
			return js_get_hasChild();
		}

		TITANIUM_PROPERTY_SETTER(TableViewRow, hasChild) 
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			setHasChild(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TableViewRow, setHasChild)
		{
			if (arguments.size() >= 1) {
				js_set_hasChild(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TableViewRow, getTitle)
		{
			return js_get_title();
		}

		TITANIUM_PROPERTY_SETTER(TableViewRow, title) 
		{
			TITANIUM_ASSERT(argument.IsString());
			setTitle(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TableViewRow, setTitle)
		{
			if (arguments.size() >= 1) {
				js_set_title(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}
	} // namespace UI
} // namespace Titanium