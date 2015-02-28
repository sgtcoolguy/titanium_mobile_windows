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
        	: Module(js_context, arguments),
        	color__(""),
        	hasCheck__(false),
        	hasChild__(false),
        	leftImage__(""),
        	rightImage__(""),
        	selectedBackgroundColor__(""),
        	selectedBackgroundImage__(""),
        	title__("")
    	{
    	}

		std::string TableViewRow::color() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::color: Unimplemented");
        	return color__;
		}

		JSValue TableViewRow::font() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::font: Unimplemented");
			const auto script = "";
			return get_context().JSEvaluateScript(script);
		}

		bool TableViewRow::hasCheck() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::hasCheck: Unimplemented");
        	return hasCheck__;
		}

		bool TableViewRow::hasChild() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::hasChild: Unimplemented");
        	return hasChild__;
		}

		std::string TableViewRow::leftImage() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::leftImage: Unimplemented");
        	return leftImage__;
		}

		std::string TableViewRow::rightImage() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::rightImage: Unimplemented");
        	return rightImage__;
		}

		std::string TableViewRow::selectedBackgroundColor() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::selectedBackgroundColor: Unimplemented");
        	return selectedBackgroundColor__;
		}

		std::string TableViewRow::selectedBackgroundImage() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::selectedBackgroundImage: Unimplemented");
        	return selectedBackgroundImage__;
		}

		std::string TableViewRow::title() const TITANIUM_NOEXCEPT
    	{
        	TITANIUM_LOG_WARN("TableViewRow::title: Unimplemented");
        	return title__;
		}


		void TableViewRow::JSExportInitialize() {
			JSExport<TableViewRow>::SetClassVersion(1);
			JSExport<TableViewRow>::SetParent(JSExport<Module>::Class());

			JSExport<TableViewRow>::AddValueProperty("color", std::mem_fn(&TableViewRow::js_color));
			JSExport<TableViewRow>::AddValueProperty("font", std::mem_fn(&TableViewRow::js_font));
			JSExport<TableViewRow>::AddValueProperty("hasCheck", std::mem_fn(&TableViewRow::js_hasCheck));
			JSExport<TableViewRow>::AddValueProperty("hasChild", std::mem_fn(&TableViewRow::js_hasChild));
			JSExport<TableViewRow>::AddValueProperty("leftImage", std::mem_fn(&TableViewRow::js_leftImage));
			JSExport<TableViewRow>::AddValueProperty("rightImage", std::mem_fn(&TableViewRow::js_rightImage));
			JSExport<TableViewRow>::AddValueProperty("selectedBackgroundColor", std::mem_fn(&TableViewRow::js_selectedBackgroundColor));
			JSExport<TableViewRow>::AddValueProperty("selectedBackgroundImage", std::mem_fn(&TableViewRow::js_selectedBackgroundImage));
			JSExport<TableViewRow>::AddValueProperty("title", std::mem_fn(&TableViewRow::js_title));

			JSExport<TableViewRow>::AddFunctionProperty("getColor", std::mem_fn(&TableViewRow::js_getColor));
			JSExport<TableViewRow>::AddFunctionProperty("setColor", std::mem_fn(&TableViewRow::js_setColor));
			JSExport<TableViewRow>::AddFunctionProperty("getFont", std::mem_fn(&TableViewRow::js_getFont));
			JSExport<TableViewRow>::AddFunctionProperty("setFont", std::mem_fn(&TableViewRow::js_setFont));
			JSExport<TableViewRow>::AddFunctionProperty("getHasCheck", std::mem_fn(&TableViewRow::js_getHasCheck));
			JSExport<TableViewRow>::AddFunctionProperty("setHasCheck", std::mem_fn(&TableViewRow::js_setHasCheck));
			JSExport<TableViewRow>::AddFunctionProperty("getHasChild", std::mem_fn(&TableViewRow::js_getHasChild));
			JSExport<TableViewRow>::AddFunctionProperty("setHasChild", std::mem_fn(&TableViewRow::js_setHasChild));
			JSExport<TableViewRow>::AddFunctionProperty("getLeftImage", std::mem_fn(&TableViewRow::js_getLeftImage));
			JSExport<TableViewRow>::AddFunctionProperty("setLeftImage", std::mem_fn(&TableViewRow::js_setLeftImage));
			JSExport<TableViewRow>::AddFunctionProperty("getRightImage", std::mem_fn(&TableViewRow::js_getRightImage));
			JSExport<TableViewRow>::AddFunctionProperty("setRightImage", std::mem_fn(&TableViewRow::js_setRightImage));
			JSExport<TableViewRow>::AddFunctionProperty("getSelectedBackgroundColor", std::mem_fn(&TableViewRow::js_getSelectedBackgroundColor));
			JSExport<TableViewRow>::AddFunctionProperty("setSelectedBackgroundColor", std::mem_fn(&TableViewRow::js_setSelectedBackgroundColor));
			JSExport<TableViewRow>::AddFunctionProperty("getSelectedBackgroundImage", std::mem_fn(&TableViewRow::js_getSelectedBackgroundImage));
			JSExport<TableViewRow>::AddFunctionProperty("setSelectedBackgroundImage", std::mem_fn(&TableViewRow::js_setSelectedBackgroundImage));
			JSExport<TableViewRow>::AddFunctionProperty("getTitle", std::mem_fn(&TableViewRow::js_getTitle));
			JSExport<TableViewRow>::AddFunctionProperty("setTitle", std::mem_fn(&TableViewRow::js_setTitle));
		}

		JSValue TableViewRow::js_color() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(color());
		}

		JSValue TableViewRow::js_font() const TITANIUM_NOEXCEPT
		{
			return font();
		}

		JSValue TableViewRow::js_hasCheck() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(hasCheck());
		}

		JSValue TableViewRow::js_hasChild() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(hasChild());
		}

		JSValue TableViewRow::js_leftImage() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(leftImage());
		}

		JSValue TableViewRow::js_rightImage() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(rightImage());
		}

		JSValue TableViewRow::js_selectedBackgroundColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(selectedBackgroundColor());
		}

		JSValue TableViewRow::js_selectedBackgroundImage() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(selectedBackgroundImage());
		}

		JSValue TableViewRow::js_title() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(title());
		}

		JSValue TableViewRow::js_getColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setColor is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string color = static_cast<std::string>(_0);
				// setColor(color);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getFont is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setFont(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setFont is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				//TITANIUM_ASSERT(_0.IsFont());
				const auto font = static_cast<JSObject>(_0);
				// setFont(font);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getHasCheck(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getHasCheck is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setHasCheck(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setHasCheck is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsBoolean());
				const bool hasCheck = static_cast<bool>(_0);
				// setHasCheck(hasCheck);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getHasChild(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getHasChild is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setHasChild(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setHasChild is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsBoolean());
				const bool hasChild = static_cast<bool>(_0);
				// setHasChild(hasChild);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getLeftImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getLeftImage is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setLeftImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setLeftImage is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string leftImage = static_cast<std::string>(_0);
				// setLeftImage(leftImage);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getRightImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getRightImage is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setRightImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setRightImage is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string rightImage = static_cast<std::string>(_0);
				// setRightImage(rightImage);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getSelectedBackgroundColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getSelectedBackgroundColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setSelectedBackgroundColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setSelectedBackgroundColor is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string selectedBackgroundColor = static_cast<std::string>(_0);
				// setSelectedBackgroundColor(selectedBackgroundColor);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getSelectedBackgroundImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getSelectedBackgroundImage is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setSelectedBackgroundImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setSelectedBackgroundImage is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string selectedBackgroundImage = static_cast<std::string>(_0);
				// setSelectedBackgroundImage(selectedBackgroundImage);
			}
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_getTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.getTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue TableViewRow::js_setTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TableViewRow.setTitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string title = static_cast<std::string>(_0);
				// setTitle(title);
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium