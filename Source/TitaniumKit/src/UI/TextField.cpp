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
			leftButtonMode__ = leftButtonMode;
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

		void TextField::set_returnKeyType(const RETURNKEY& returnKeyType) TITANIUM_NOEXCEPT
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
			TITANIUM_ADD_PROPERTY(TextField, autocapitalization);
			TITANIUM_ADD_PROPERTY(TextField, borderStyle);
			TITANIUM_ADD_PROPERTY(TextField, clearButtonMode);
			TITANIUM_ADD_PROPERTY(TextField, color);
			TITANIUM_ADD_PROPERTY(TextField, editable);
			TITANIUM_ADD_PROPERTY(TextField, ellipsize);
			TITANIUM_ADD_PROPERTY(TextField, enableReturnKey);
			TITANIUM_ADD_PROPERTY(TextField, hintText);
			TITANIUM_ADD_PROPERTY(TextField, keyboardType);
			TITANIUM_ADD_PROPERTY(TextField, leftButtonMode);
			TITANIUM_ADD_PROPERTY(TextField, maxLength);
			TITANIUM_ADD_PROPERTY(TextField, passwordMask);
			TITANIUM_ADD_PROPERTY(TextField, returnKeyType);
			TITANIUM_ADD_PROPERTY(TextField, rightButtonMode);
			TITANIUM_ADD_PROPERTY(TextField, suppressReturn);
			TITANIUM_ADD_PROPERTY(TextField, textAlign);
			TITANIUM_ADD_PROPERTY(TextField, value);
			TITANIUM_ADD_PROPERTY(TextField, verticalAlign);
			// methods
			TITANIUM_ADD_FUNCTION(TextField, blur);
			TITANIUM_ADD_FUNCTION(TextField, focus);
			TITANIUM_ADD_FUNCTION(TextField, hasText);
			// property accessor methods
			TITANIUM_ADD_FUNCTION(TextField, getAutocapitalization);
			TITANIUM_ADD_FUNCTION(TextField, setAutocapitalization);
			TITANIUM_ADD_FUNCTION(TextField, getBorderStyle);
			TITANIUM_ADD_FUNCTION(TextField, setBorderStyle);
			TITANIUM_ADD_FUNCTION(TextField, getClearButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, setClearButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, getColor);
			TITANIUM_ADD_FUNCTION(TextField, setColor);
			TITANIUM_ADD_FUNCTION(TextField, getEditable);
			TITANIUM_ADD_FUNCTION(TextField, setEditable);
			TITANIUM_ADD_FUNCTION(TextField, getEllipsize);
			TITANIUM_ADD_FUNCTION(TextField, setEllipsize);
			TITANIUM_ADD_FUNCTION(TextField, getEnableReturnKey);
			TITANIUM_ADD_FUNCTION(TextField, setEnableReturnKey);
			TITANIUM_ADD_FUNCTION(TextField, getHintText);
			TITANIUM_ADD_FUNCTION(TextField, setHintText);
			TITANIUM_ADD_FUNCTION(TextField, getKeyboardType);
			TITANIUM_ADD_FUNCTION(TextField, setKeyboardType);
			TITANIUM_ADD_FUNCTION(TextField, getLeftButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, setLeftButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, getMaxLength);
			TITANIUM_ADD_FUNCTION(TextField, setMaxLength);
			TITANIUM_ADD_FUNCTION(TextField, getPasswordMask);
			TITANIUM_ADD_FUNCTION(TextField, setPasswordMask);
			TITANIUM_ADD_FUNCTION(TextField, getReturnKeyType);
			TITANIUM_ADD_FUNCTION(TextField, setReturnKeyType);
			TITANIUM_ADD_FUNCTION(TextField, getRightButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, setRightButtonMode);
			TITANIUM_ADD_FUNCTION(TextField, getSuppressReturn);
			TITANIUM_ADD_FUNCTION(TextField, setSuppressReturn);
			TITANIUM_ADD_FUNCTION(TextField, getTextAlign);
			TITANIUM_ADD_FUNCTION(TextField, setTextAlign);
			TITANIUM_ADD_FUNCTION(TextField, getValue);
			TITANIUM_ADD_FUNCTION(TextField, setValue);
			TITANIUM_ADD_FUNCTION(TextField, getVerticalAlign);
			TITANIUM_ADD_FUNCTION(TextField, setVerticalAlign);
		}

		TITANIUM_PROPERTY_GETTER(TextField, autocapitalization)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(get_autocapitalization()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, autocapitalization)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			autocapitalization__ = Constants::to_TEXT_AUTOCAPITALIZATION(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(argument));
			set_autocapitalization(autocapitalization__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getAutocapitalization)
		{
			return js_get_autocapitalization();
		}

		TITANIUM_FUNCTION(TextField, setAutocapitalization)
		{
			if (arguments.size() >= 1) {
				js_set_autocapitalization(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, borderStyle)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BORDERSTYLE>::type>(get_borderStyle()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, borderStyle)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			borderStyle__ = Constants::to_INPUT_BORDERSTYLE(static_cast<std::underlying_type<INPUT_BORDERSTYLE>::type>(argument));
			set_borderStyle(borderStyle__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getBorderStyle)
		{
			return js_get_borderStyle();
		}

		TITANIUM_FUNCTION(TextField, setBorderStyle)
		{
			if (arguments.size() >= 1) {
				js_set_borderStyle(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, clearButtonMode)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_clearButtonMode()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, clearButtonMode)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			clearButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(argument));
			set_clearButtonMode(clearButtonMode__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getClearButtonMode)
		{
			return js_get_clearButtonMode();
		}

		TITANIUM_FUNCTION(TextField, setClearButtonMode)
		{
			if (arguments.size() >= 1) {
				js_set_clearButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, color)
		{
			return get_context().CreateString(get_color());
		}

		TITANIUM_PROPERTY_SETTER(TextField, color)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getColor)
		{
			return js_get_color();
		}

		TITANIUM_FUNCTION(TextField, setColor)
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, editable)
		{
			return get_context().CreateBoolean(get_editable());
		}

		TITANIUM_PROPERTY_SETTER(TextField, editable)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			editable__ = static_cast<bool>(argument);
			set_editable(editable__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getEditable)
		{
			return js_get_editable();
		}

		TITANIUM_FUNCTION(TextField, setEditable)
		{
			if (arguments.size() >= 1) {
				js_set_editable(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, ellipsize)
		{
			return get_context().CreateBoolean(get_ellipsize());
		}

		TITANIUM_PROPERTY_SETTER(TextField, ellipsize)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			ellipsize__ = static_cast<bool>(argument);
			set_ellipsize(ellipsize__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getEllipsize)
		{
			return js_get_ellipsize();
		}

		TITANIUM_FUNCTION(TextField, setEllipsize)
		{
			if (arguments.size() >= 1) {
				js_set_ellipsize(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, enableReturnKey)
		{
			return get_context().CreateBoolean(get_enableReturnKey());
		}

		TITANIUM_PROPERTY_SETTER(TextField, enableReturnKey)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			enableReturnKey__ = static_cast<bool>(argument);
			set_enableReturnKey(enableReturnKey__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getEnableReturnKey)
		{
			return js_get_enableReturnKey();
		}

		TITANIUM_FUNCTION(TextField, setEnableReturnKey)
		{
			if (arguments.size() >= 1) {
				js_set_enableReturnKey(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, hintText)
		{
			return get_context().CreateString(get_hintText());
		}

		TITANIUM_PROPERTY_SETTER(TextField, hintText)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_hintText(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getHintText)
		{
			return js_get_hintText();
		}

		TITANIUM_FUNCTION(TextField, setHintText)
		{
			if (arguments.size() >= 1) {
				js_set_hintText(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, keyboardType)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<KEYBOARD>::type>(get_keyboardType()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, keyboardType)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			keyboardType__ = Constants::to_KEYBOARD(static_cast<std::underlying_type<KEYBOARD>::type>(argument));
			set_keyboardType(keyboardType__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getKeyboardType)
		{
			return js_get_keyboardType();
		}

		TITANIUM_FUNCTION(TextField, setKeyboardType)
		{
			if (arguments.size() >= 1) {
				js_set_keyboardType(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, leftButtonMode)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_leftButtonMode()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, leftButtonMode)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			leftButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(argument));
			set_leftButtonMode(leftButtonMode__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getLeftButtonMode)
		{
			return js_get_leftButtonMode();
		}

		TITANIUM_FUNCTION(TextField, setLeftButtonMode)
		{
			if (arguments.size() >= 1) {
				js_set_leftButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, maxLength)
		{
			return get_context().CreateNumber(get_maxLength());
		}

		TITANIUM_PROPERTY_SETTER(TextField, maxLength)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_maxLength(static_cast<int32_t>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getMaxLength)
		{
			return js_get_maxLength();
		}

		TITANIUM_FUNCTION(TextField, setMaxLength)
		{
			if (arguments.size() >= 1) {
				js_set_maxLength(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, passwordMask)
		{
			return get_context().CreateBoolean(get_passwordMask());
		}

		TITANIUM_PROPERTY_SETTER(TextField, passwordMask)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_passwordMask(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getPasswordMask)
		{
			return js_get_passwordMask();
		}

		TITANIUM_FUNCTION(TextField, setPasswordMask)
		{
			if (arguments.size() >= 1) {
				js_set_passwordMask(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, returnKeyType)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<RETURNKEY>::type>(get_returnKeyType()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, returnKeyType)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			returnKeyType__ = Constants::to_RETURNKEY(static_cast<std::underlying_type<RETURNKEY>::type>(argument));
			set_returnKeyType(returnKeyType__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getReturnKeyType)
		{
			return js_get_returnKeyType();
		}

		TITANIUM_FUNCTION(TextField, setReturnKeyType)
		{
			if (arguments.size() >= 1) {
				js_set_returnKeyType(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, rightButtonMode)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<INPUT_BUTTONMODE>::type>(get_rightButtonMode()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, rightButtonMode)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			rightButtonMode__ = Constants::to_INPUT_BUTTONMODE(static_cast<std::underlying_type<KEYBOARD>::type>(argument));
			set_rightButtonMode(rightButtonMode__);
			return true;
		}

		TITANIUM_FUNCTION(TextField, getRightButtonMode)
		{
			return js_get_rightButtonMode();
		}

		TITANIUM_FUNCTION(TextField, setRightButtonMode)
		{
			if (arguments.size() >= 1) {
				js_set_rightButtonMode(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, suppressReturn)
		{
			return get_context().CreateBoolean(get_suppressReturn());
		}

		TITANIUM_PROPERTY_SETTER(TextField, suppressReturn)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_suppressReturn(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getSuppressReturn)
		{
			return js_get_suppressReturn();
		}

		TITANIUM_FUNCTION(TextField, setSuppressReturn)
		{
			if (arguments.size() >= 1) {
				js_set_suppressReturn(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, textAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, textAlign)
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

		TITANIUM_FUNCTION(TextField, getTextAlign)
		{
			return js_get_textAlign();
		}

		TITANIUM_FUNCTION(TextField, setTextAlign)
		{
			if (arguments.size() >= 1) {
				js_set_textAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, value)
		{
			return get_context().CreateString(get_value());
		}

		TITANIUM_PROPERTY_SETTER(TextField, value)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_value(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_FUNCTION(TextField, getValue)
		{
			return js_get_value();
		}

		TITANIUM_FUNCTION(TextField, setValue)
		{
			if (arguments.size() >= 1) {
				js_set_value(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(TextField, verticalAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
		}

		TITANIUM_PROPERTY_SETTER(TextField, verticalAlign)
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

		TITANIUM_FUNCTION(TextField, getVerticalAlign)
		{
			return js_get_verticalAlign();
		}

		TITANIUM_FUNCTION(TextField, setVerticalAlign)
		{
			if (arguments.size() >= 1) {
				js_set_verticalAlign(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TextField, blur)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			blur();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TextField, focus)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			focus();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(TextField, hasText)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			return get_context().CreateBoolean(hasText());
		}
	} // namespace UI
}  // namespace Titanium
