/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TextField.hpp"
#include <type_traits>

namespace Titanium
{
	namespace UI
	{
		TextField::TextField(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      autocapitalization__(TEXT_AUTOCAPITALIZATION::NONE),
		      borderStyle__(INPUT_BORDERSTYLE::NONE),
		      clearButtonMode__(INPUT_BUTTONMODE::NEVER),
			  color__(js_context.CreateString()),
			  editable__(js_context.CreateBoolean(true)),
			  ellipsize__(js_context.CreateBoolean(false)),
			  hintText__(js_context.CreateString()),
		      leftButtonMode__(INPUT_BUTTONMODE::NEVER),
			  maxLength__(js_context.CreateNumber(-1)),
			  passwordMask__(js_context.CreateBoolean(false)),
		      returnKeyType__(RETURNKEY::DEFAULT),
		      rightButtonMode__(INPUT_BUTTONMODE::NEVER),
			  suppressReturn__(js_context.CreateBoolean(false)),
		      textAlign__(TEXT_ALIGNMENT::LEFT),
			  value__(js_context.CreateString()),
		      verticalAlign__(TEXT_VERTICAL_ALIGNMENT::CENTER)
		{
		}

		TEXT_AUTOCAPITALIZATION TextField::get_autocapitalization() const TITANIUM_NOEXCEPT
		{
			return autocapitalization__;
		}

		void TextField::set_autocapitalization(const TEXT_AUTOCAPITALIZATION& autocapitalization) TITANIUM_NOEXCEPT
		{
			autocapitalization__ = autocapitalization;
		}

		INPUT_BORDERSTYLE TextField::get_borderStyle() const TITANIUM_NOEXCEPT
		{
			return borderStyle__;
		}

		void TextField::set_borderStyle(const INPUT_BORDERSTYLE& borderStyle) TITANIUM_NOEXCEPT
		{
			borderStyle__ = borderStyle;
		}

		INPUT_BUTTONMODE TextField::get_clearButtonMode() const TITANIUM_NOEXCEPT
		{
			return clearButtonMode__;
		}

		void TextField::set_clearButtonMode(const INPUT_BUTTONMODE& clearButtonMode) TITANIUM_NOEXCEPT
		{
			clearButtonMode__ = clearButtonMode;
		}

		std::string TextField::get_color() const TITANIUM_NOEXCEPT
		{
			return color__;
		}

		void TextField::set_color(const std::string& color) TITANIUM_NOEXCEPT
		{
			color__ = color;
		}

		bool TextField::get_editable() const TITANIUM_NOEXCEPT
		{
			return editable__;
		}

		void TextField::set_editable(const bool& editable) TITANIUM_NOEXCEPT
		{
			editable__ = editable;
		}

		bool TextField::get_ellipsize() const TITANIUM_NOEXCEPT
		{
			return ellipsize__;
		}

		void TextField::set_ellipsize(const bool& ellipsize) TITANIUM_NOEXCEPT
		{
			ellipsize__ = ellipsize;
		}

		bool TextField::get_enableReturnKey() const TITANIUM_NOEXCEPT
		{
			return enableReturnKey__;
		}

		void TextField::set_enableReturnKey(const bool& enableReturnKey) TITANIUM_NOEXCEPT
		{
			enableReturnKey__ = enableReturnKey;
		}

		std::string TextField::get_hintText() const TITANIUM_NOEXCEPT
		{
			return hintText__;
		}

		void TextField::set_hintText(const std::string& hintText) TITANIUM_NOEXCEPT
		{
			hintText__ = hintText;
		}

		KEYBOARD TextField::get_keyboardType() const TITANIUM_NOEXCEPT
		{
			return keyboardType__;
		}

		void TextField::set_keyboardType(const KEYBOARD& keyboardType) TITANIUM_NOEXCEPT
		{
			keyboardType__ = keyboardType;
		}

		INPUT_BUTTONMODE TextField::get_leftButtonMode() const TITANIUM_NOEXCEPT
		{
			return leftButtonMode__;
		}

		void TextField::set_leftButtonMode(const INPUT_BUTTONMODE& leftButtonMode) TITANIUM_NOEXCEPT
		{
			clearButtonMode__ = clearButtonMode;
		}

		int32_t TextField::get_maxLength() const TITANIUM_NOEXCEPT
		{
			return maxLength__;
		}

		void TextField::set_maxLength(const int32_t& maxLength) TITANIUM_NOEXCEPT
		{
			maxLength__ = maxLength;
		}

		bool TextField::get_passwordMask() const TITANIUM_NOEXCEPT
		{
			return passwordMask__;
		}

		void TextField::set_passwordMask(const bool& passwordMask) TITANIUM_NOEXCEPT
		{
			passwordMask__ = passwordMask;
		}

		RETURNKEY TextField::get_returnKeyType() const TITANIUM_NOEXCEPT
		{
			return returnKeyType__;
		}

		void TextField::set_returnKeyType(const RETURNKEY& keyboardType) TITANIUM_NOEXCEPT
		{
			returnKeyType__ = returnKeyType;
		}

		INPUT_BUTTONMODE TextField::get_rightButtonMode() const TITANIUM_NOEXCEPT
		{
			return rightButtonMode__;
		}

		void TextField::set_rightButtonMode(const INPUT_BUTTONMODE& rightButtonMode) TITANIUM_NOEXCEPT
		{
			rightButtonMode__ = rightButtonMode;
		}

		bool TextField::get_suppressReturn() const TITANIUM_NOEXCEPT
		{
			return suppressReturn__;
		}

		void TextField::set_suppressReturn(const bool& suppressReturn) TITANIUM_NOEXCEPT
		{
			suppressReturn__ = suppressReturn;
		}

		TEXT_ALIGNMENT TextField::get_textAlign() const TITANIUM_NOEXCEPT
		{
			return textAlign__;
		}

		void TextField::set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			textAlign__ = textAlign;
		}

		std::string TextField::get_value() const TITANIUM_NOEXCEPT
		{
			return value__;
		}

		void TextField::set_value(const std::string& value) TITANIUM_NOEXCEPT
		{
			value__ = value;
		}

		TEXT_VERTICAL_ALIGNMENT TextField::get_verticalAlign() const TITANIUM_NOEXCEPT
		{
			return verticalAlign__;
		}

		void TextField::set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			verticalAlign__ = verticalAlign;
		}

		void TextField::blur() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("TextField::blur");
		}

		void TextField::focus() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("TextField::focus");
		}

		bool TextField::hasText() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("TextField::hasText");
			return false;
		}

		void TextField::JSExportInitialize()
		{
			JSExport<TextField>::SetClassVersion(1);
			JSExport<TextField>::SetParent(JSExport<View>::Class());
			// properties
			JSExport<TextField>::AddValueProperty("autocapitalization", std::mem_fn(&TextField::js_get_autocapitalization), std::mem_fn(&TextField::js_set_autocapitalization));
			JSExport<TextField>::AddValueProperty("borderStyle", std::mem_fn(&TextField::js_get_borderStyle), std::mem_fn(&TextField::js_set_borderStyle));
			JSExport<TextField>::AddValueProperty("clearButtonMode", std::mem_fn(&TextField::js_get_clearButtonMode), std::mem_fn(&TextField::js_set_clearButtonMode));
			JSExport<TextField>::AddValueProperty("color", std::mem_fn(&TextField::js_get_color), std::mem_fn(&TextField::js_set_color));
			JSExport<TextField>::AddValueProperty("editable", std::mem_fn(&TextField::js_get_editable), std::mem_fn(&TextField::js_set_editable));
			JSExport<TextField>::AddValueProperty("ellipsize", std::mem_fn(&TextField::js_get_ellipsize), std::mem_fn(&TextField::js_set_ellipsize));
			JSExport<TextField>::AddValueProperty("enableReturnKey", std::mem_fn(&TextField::js_get_enableReturnKey), std::mem_fn(&TextField::js_set_enableReturnKey));
			JSExport<TextField>::AddValueProperty("hintText", std::mem_fn(&TextField::js_get_hintText), std::mem_fn(&TextField::js_set_hintText));
			JSExport<TextField>::AddValueProperty("keyboardType", std::mem_fn(&TextField::js_get_keyboardType), std::mem_fn(&TextField::js_set_keyboardType));
			JSExport<TextField>::AddValueProperty("leftButtonMode", std::mem_fn(&TextField::js_get_leftButtonMode), std::mem_fn(&TextField::js_set_leftButtonMode));
			JSExport<TextField>::AddValueProperty("maxLength", std::mem_fn(&TextField::js_get_maxLength), std::mem_fn(&TextField::js_set_maxLength));
			JSExport<TextField>::AddValueProperty("passwordMask", std::mem_fn(&TextField::js_get_passwordMask), std::mem_fn(&TextField::js_set_passwordMask));
			JSExport<TextField>::AddValueProperty("returnKeyType", std::mem_fn(&TextField::js_get_returnKeyType), std::mem_fn(&TextField::js_set_returnKeyType));
			JSExport<TextField>::AddValueProperty("rightButtonMode", std::mem_fn(&TextField::js_get_rightButtonMode), std::mem_fn(&TextField::js_set_rightButtonMode));
			JSExport<TextField>::AddValueProperty("suppressReturn", std::mem_fn(&TextField::js_get_suppressReturn), std::mem_fn(&TextField::js_set_suppressReturn));
			JSExport<TextField>::AddValueProperty("textAlign", std::mem_fn(&TextField::js_get_textAlign), std::mem_fn(&TextField::js_set_textAlign));
			JSExport<TextField>::AddValueProperty("value", std::mem_fn(&TextField::js_get_value), std::mem_fn(&TextField::js_set_value));
			JSExport<TextField>::AddValueProperty("verticalAlign", std::mem_fn(&TextField::js_get_verticalAlign), std::mem_fn(&TextField::js_set_verticalAlign));
			// methods
			JSExport<TextField>::AddFunctionProperty("blur", std::mem_fn(&TextField::js_blur));
			JSExport<TextField>::AddFunctionProperty("focus", std::mem_fn(&TextField::js_focus));
			JSExport<TextField>::AddFunctionProperty("hasText", std::mem_fn(&TextField::js_hasText));
			// property accessor methods
			JSExport<TextField>::AddFunctionProperty("getAutocapitalization", std::mem_fn(&TextField::js_getAutocapitalization));
			JSExport<TextField>::AddFunctionProperty("setAutocapitalization", std::mem_fn(&TextField::js_setAutocapitalization));
			JSExport<TextField>::AddFunctionProperty("getBorderStyle", std::mem_fn(&TextField::js_getBorderStyle));
			JSExport<TextField>::AddFunctionProperty("setBorderStyle", std::mem_fn(&TextField::js_setBorderStyle));
			JSExport<TextField>::AddFunctionProperty("getClearButtonMode", std::mem_fn(&TextField::js_getClearButtonMode));
			JSExport<TextField>::AddFunctionProperty("setClearButtonMode", std::mem_fn(&TextField::js_setClearButtonMode));
			JSExport<TextField>::AddFunctionProperty("getColor", std::mem_fn(&TextField::js_getColor));
			JSExport<TextField>::AddFunctionProperty("setColor", std::mem_fn(&TextField::js_setColor));
			JSExport<TextField>::AddFunctionProperty("getEditable", std::mem_fn(&TextField::js_getEditable));
			JSExport<TextField>::AddFunctionProperty("setEditable", std::mem_fn(&TextField::js_setEditable));
			JSExport<TextField>::AddFunctionProperty("getEllipsize", std::mem_fn(&TextField::js_getEllipsize));
			JSExport<TextField>::AddFunctionProperty("setEllipsize", std::mem_fn(&TextField::js_setEllipsize));
			JSExport<TextField>::AddFunctionProperty("getEnableReturnKey", std::mem_fn(&TextField::js_getEnableReturnKey));
			JSExport<TextField>::AddFunctionProperty("setEnableReturnKey", std::mem_fn(&TextField::js_setEnableReturnKey));
			JSExport<TextField>::AddFunctionProperty("getHintText", std::mem_fn(&TextField::js_getHintText));
			JSExport<TextField>::AddFunctionProperty("setHintText", std::mem_fn(&TextField::js_setHintText));
			JSExport<TextField>::AddFunctionProperty("getKeyboardType", std::mem_fn(&TextField::js_getKeyboardType));
			JSExport<TextField>::AddFunctionProperty("setKeyboardType", std::mem_fn(&TextField::js_setKeyboardType));
			JSExport<TextField>::AddFunctionProperty("getLeftButtonMode", std::mem_fn(&TextField::js_getLeftButtonMode));
			JSExport<TextField>::AddFunctionProperty("setLeftButtonMode", std::mem_fn(&TextField::js_setLeftButtonMode));
			JSExport<TextField>::AddFunctionProperty("getMaxLength", std::mem_fn(&TextField::js_getMaxLength));
			JSExport<TextField>::AddFunctionProperty("setMaxLength", std::mem_fn(&TextField::js_setMaxLength));
			JSExport<TextField>::AddFunctionProperty("getPasswordMask", std::mem_fn(&TextField::js_getPasswordMask));
			JSExport<TextField>::AddFunctionProperty("setPasswordMask", std::mem_fn(&TextField::js_setPasswordMask));
			JSExport<TextField>::AddFunctionProperty("getReturnKeyType", std::mem_fn(&TextField::js_getReturnKeyType));
			JSExport<TextField>::AddFunctionProperty("setReturnKeyType", std::mem_fn(&TextField::js_setReturnKeyType));
			JSExport<TextField>::AddFunctionProperty("getRightButtonMode", std::mem_fn(&TextField::js_getRightButtonMode));
			JSExport<TextField>::AddFunctionProperty("setRightButtonMode", std::mem_fn(&TextField::js_setRightButtonMode));
			JSExport<TextField>::AddFunctionProperty("getSuppressReturn", std::mem_fn(&TextField::js_getSuppressReturn));
			JSExport<TextField>::AddFunctionProperty("setSuppressReturn", std::mem_fn(&TextField::js_setSuppressReturn));
			JSExport<TextField>::AddFunctionProperty("getTextAlign", std::mem_fn(&TextField::js_getTextAlign));
			JSExport<TextField>::AddFunctionProperty("setTextAlign", std::mem_fn(&TextField::js_setTextAlign));
			JSExport<TextField>::AddFunctionProperty("getValue", std::mem_fn(&TextField::js_getValue));
			JSExport<TextField>::AddFunctionProperty("setValue", std::mem_fn(&TextField::js_setValue));
			JSExport<TextField>::AddFunctionProperty("getVerticalAlign", std::mem_fn(&TextField::js_getVerticalAlign));
			JSExport<TextField>::AddFunctionProperty("setVerticalAlign", std::mem_fn(&TextField::js_setVerticalAlign));
		}

		JSValue TextField::js_get_autocapitalization() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(get_autocapitalization()));
		}

		bool TextField::js_set_autocapitalization(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			autocapitalization__ = Constants::to_TEXT_AUTOCAPITALIZATION(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(argument));
			set_autocapitalization(autocapitalization__);
			return true;
		}

		JSValue TextField::js_getAutocapitalization(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_autocapitalization();
		}

		JSValue TextField::js_setAutocapitalization(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_autocapitalization(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_borderStyle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BORDERSTYLE>::type>(get_borderStyle()));
		}

		bool TextField::js_set_borderStyle(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			borderStyle__ = Constants::to_INPUT_BORDERSTYLE(static_cast<std::underlying_type<INPUT_BORDERSTYLE>::type>(argument));
			set_borderStyle(borderStyle__);
			return true;
		}

		JSValue TextField::js_getBorderStyle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_borderStyle();
		}

		JSValue TextField::js_setBorderStyle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_borderStyle(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_clearButtonMode() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_clearButtonMode()));
		}

		bool TextField::js_set_clearButtonMode(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			clearButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(argument));
			set_clearButtonMode(clearButtonMode__);
			return true;
		}

		JSValue TextField::js_getClearButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_clearButtonMode();
		}

		JSValue TextField::js_setClearButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_clearButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_color() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_color());
		}

		bool TextField::js_set_color(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		JSValue TextField::js_getColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_color();
		}

		JSValue TextField::js_setColor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_editable() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_editable());
		}

		bool TextField::js_set_editable(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			editable__ = static_cast<bool>(argument);
			set_editable(editable__);
			return true;
		}

		JSValue TextField::js_getEditable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_editable();
		}

		JSValue TextField::js_setEditable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_editable(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_ellipsize() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_ellipsize());
		}

		bool TextField::js_set_ellipsize(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			ellipsize__ = static_cast<bool>(argument);
			set_ellipsize(ellipsize__);
			return true;
		}

		JSValue TextField::js_getEllipsize(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_ellipsize();
		}

		JSValue TextField::js_setEllipsize(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_ellipsize(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_enableReturnKey() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_enableReturnKey());
		}

		bool TextField::js_set_enableReturnKey(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			enableReturnKey__ = static_cast<bool>(argument);
			set_enableReturnKey(enableReturnKey__);
			return true;
		}

		JSValue TextField::js_getEnableReturnKey(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_enableReturnKey();
		}

		JSValue TextField::js_setEnableReturnKey(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_enableReturnKey(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_hintText() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_hintText());
		}

		bool TextField::js_set_hintText(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_hintText(static_cast<std::string>(argument));
			return true;
		}

		JSValue TextField::js_getHintText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_hintText();
		}

		JSValue TextField::js_setHintText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_hintText(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_keyboardType() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<KEYBOARD>::type>(get_keyboardType()));
		}

		bool TextField::js_set_keyboardType(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			keyboardType__ = Constants::to_KEYBOARD(static_cast<std::underlying_type<KEYBOARD>::type>(argument));
			set_keyboardType(keyboardType__);
			return true;
		}

		JSValue TextField::js_getKeyboardType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_keyboardType();
		}

		JSValue TextField::js_setKeyboardType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_keyboardType(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_leftButtonMode() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_leftButtonMode()));
		}

		bool TextField::js_set_leftButtonMode(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			leftButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(argument));
			set_leftButtonMode(leftButtonMode__);
			return true;
		}

		JSValue TextField::js_getLeftButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_leftButtonMode();
		}

		JSValue TextField::js_setLeftButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_leftButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_maxLength() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_maxLength());
		}

		bool TextField::js_set_maxLength(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_maxLength(static_cast<int32_t>(argument));
			return true;
		}

		JSValue TextField::js_getMaxLength(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_maxLength();
		}

		JSValue TextField::js_setMaxLength(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_maxLength(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_passwordMask() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_passwordMask());
		}

		bool TextField::js_set_passwordMask(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_passwordMask(static_cast<bool>(argument));
			return true;
		}

		JSValue TextField::js_getPasswordMask(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_passwordMask();
		}

		JSValue TextField::js_setPasswordMask(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_passwordMask(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_returnKeyType() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<RETURNKEY>::type>(get_returnKeyType()));
		}

		bool TextField::js_set_returnKeyType(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			returnKeyType__ = Constants::to_RETURNKEY(static_cast<std::underlying_type<RETURNKEY>::type>(argument));
			set_returnKeyType(returnKeyType__);
			return true;
		}

		JSValue TextField::js_getReturnKeyType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_returnKeyType();
		}

		JSValue TextField::js_setReturnKeyType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_returnKeyType(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_rightButtonMode() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_rightButtonMode()));
		}

		bool TextField::js_set_rightButtonMode(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			rightButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<KEYBOARD>::type>(argument));
			set_rightButtonMode(rightButtonMode__);
			return true;
		}

		JSValue TextField::js_getRightButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_rightButtonMode();
		}

		JSValue TextField::js_setRightButtonMode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_rightButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_suppressReturn() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_suppressReturn());
		}

		bool TextField::js_set_suppressReturn(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_suppressReturn(static_cast<bool>(argument));
			return true;
		}

		JSValue TextField::js_getSuppressReturn(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_suppressReturn();
		}

		JSValue TextField::js_setSuppressReturn(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_suppressReturn(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_textAlign() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
		}

		bool TextField::js_set_textAlign(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			bool result = false;
			if (argument.IsNumber()) {
				textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(argument));
				set_textAlign(textAlign__);
				result = true;
			} else if (argument.IsString()) {
				textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::string>(argument));
				set_textAlign(textAlign__);
				result = true;
			}

			return result;
		}

		JSValue TextField::js_getTextAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_textAlign();
		}

		JSValue TextField::js_setTextAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_textAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_value() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_value());
		}

		bool TextField::js_set_value(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_value(static_cast<std::string>(argument));
			return true;
		}

		JSValue TextField::js_getValue(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_value();
		}

		JSValue TextField::js_setValue(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_value(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_get_verticalAlign() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
		}

		bool TextField::js_set_verticalAlign(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			bool result = false;
			if (argument.IsNumber()) {
				verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(argument));
				set_verticalAlign(verticalAlign__);
				result = true;
			} else if (argument.IsString()) {
				verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::string>(argument));
				set_verticalAlign(verticalAlign__);
				result = true;
			}

			return result;
		}

		JSValue TextField::js_getVerticalAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_verticalAlign();
		}

		JSValue TextField::js_setVerticalAlign(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_verticalAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_blur(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			blur();
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_focus(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			focus();
			return get_context().CreateUndefined();
		}

		JSValue TextField::js_hasText(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			return get_context().CreateBoolean(hasText());
		}
	} // namespace UI
}  // namespace Titanium
