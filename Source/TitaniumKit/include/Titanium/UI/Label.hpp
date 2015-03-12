/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_LABEL_HPP_
#define _TITANIUM_UI_LABEL_HPP_

#include "Titanium/UI/Constants.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium UI Label.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Label
		*/
		class TITANIUMKIT_EXPORT Label : public View, public JSExport<Label>
		{
		public:
			/*!
			  @method

			  @abstract color : String

			  @discussion Color of the label text, as a color name or hex triplet.
			*/
			virtual std::string get_color() const TITANIUM_NOEXCEPT final;
			virtual void set_color(const std::string& color) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract ellipsize : Boolean

			  @discussion Turn on/off the addition of ellipses at the end of the label if the text is too large to fit.

			  Default: false
			*/
			virtual bool get_ellipsize() const TITANIUM_NOEXCEPT final;
			virtual void set_ellipsize(const bool& ellipsize) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract font : Font

			  @discussion Font to use for the label text.
			*/
			virtual JSValue get_font() const TITANIUM_NOEXCEPT final;
			virtual void set_fontFamily(const std::string& family) TITANIUM_NOEXCEPT;
			virtual void set_fontSize(const JSValue& size) TITANIUM_NOEXCEPT;
			virtual void set_fontStyle(const std::string& style) TITANIUM_NOEXCEPT;
			virtual void set_fontWeight(const std::string& weight) TITANIUM_NOEXCEPT;
			virtual void set_textStyle(const TEXT_STYLE& style) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract text : String

			  @discussion Label text.
			*/
			virtual std::string get_text() const TITANIUM_NOEXCEPT final;
			virtual void set_text(const std::string& title) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract textAlign : String/Number

			  @discussion Text alignment.
			*/
			virtual TEXT_ALIGNMENT get_textAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract verticalAlign : String/Number

			  @discussion Vertical text alignment, specified using one of the vertical alignment constants from Titanium.UI.
			*/
			virtual TEXT_VERTICAL_ALIGNMENT get_verticalAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract wordWrap : Boolean

			  @discussion Enable or disable word wrapping in the label.
			*/
			virtual bool get_wordWrap() const TITANIUM_NOEXCEPT final;
			virtual void set_wordWrap(const bool& wordWrap) TITANIUM_NOEXCEPT;

			Label(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Label() = default;
			Label(const Label&) = default;
			Label& operator=(const Label&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Label(Label&&) = default;
			Label& operator=(Label&&) = default;
#endif

			// TODO: The following functions can automatically be generated
			// from the YAML API docs.
			static void JSExportInitialize();

			virtual JSValue js_get_color() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_color(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_ellipsize() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_ellipsize(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getEllipsize(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setEllipsize(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_font() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_font(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFont(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFont(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_text() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_text(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getText(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setText(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_textAlign() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_textAlign(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getTextAlign(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setTextAlign(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_verticalAlign() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_verticalAlign(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getVerticalAlign(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setVerticalAlign(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_wordWrap() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_wordWrap(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getWordWrap(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setWordWrap(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::string color__;
			bool ellipsize__;
			JSObject font__;
			std::string text__;
			TEXT_ALIGNMENT textAlign__;
			TEXT_VERTICAL_ALIGNMENT verticalAlign__;
			bool wordWrap__;
#pragma warning(pop)
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_LABEL_HPP_
