/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILABEL_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILABEL_H_

#include "TiCore/TiViewProxy.h"
#include <algorithm>

namespace Ti
{
	namespace UI
	{
		class Label : public Ti::ViewProxy, public virtual_enable_shared_from_this < Label > 
		{
			TI_CREATE_PROXY(Label);
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			// The TIViewProxy defaults for height and width are correct.

		protected:
			Label(const std::string& name, const std::vector<Ti::Value>& arguments);
			virtual ~Label() {
			}

      // override setColor because TextBlock is not a subclass of Control, so impl in ViewProxy won't work
      virtual Ti::Value setColor(const std::vector<Ti::Value>& arguments) override {
        text_block_->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(Ti::WebColor::Color(arguments.at(0).toString()));
        return Ti::ViewProxy::setColor(arguments);
      }

			// Gets the value of the ellipsize property.
			TI_CREATE_METHOD(Label, getEllipsize);
			Ti::Value getEllipsize(const std::vector<Ti::Value>& arguments);
			// Sets the value of the ellipsize property.
			TI_CREATE_METHOD(Label, setEllipsize);
			Ti::Value setEllipsize(const std::vector<Ti::Value>& arguments);
			// Gets the value of the font property.
			TI_CREATE_METHOD(Label, setFont);
			Ti::Value setFont(const std::vector<Ti::Value>& arguments);
			// Sets the value of the highlightedColor property.
			TI_CREATE_METHOD(Label, setHighlightedColor);
			Ti::Value setHighlightedColor(const std::vector<Ti::Value>& arguments);
			// Gets the value of the text property.
			TI_CREATE_METHOD(Label, getText);
			Ti::Value getText(const std::vector<Ti::Value>& arguments);
			// Sets the value of the text property.
			TI_CREATE_METHOD(Label, setText);
			Ti::Value setText(const std::vector<Ti::Value>& arguments);
			// Gets the value of the textAlign property.
			TI_CREATE_METHOD(Label, getTextAlign);
			Ti::Value getTextAlign(const std::vector<Ti::Value>& arguments);
			// Sets the value of the textAlign property.
			TI_CREATE_METHOD(Label, setTextAlign);
			Ti::Value setTextAlign(const std::vector<Ti::Value>& arguments);
			// Gets the value of the verticalAlign property.
			TI_CREATE_METHOD(Label, getVerticalAlign);
			Ti::Value getVerticalAlign(const std::vector<Ti::Value>& arguments);
			TI_CREATE_METHOD(Label, setVerticalAlign);
			Ti::Value setVerticalAlign(const std::vector<Ti::Value>& arguments);

			// Gets the value of the wordWrap property.
			TI_CREATE_METHOD(Label, getWordWrap);
			Ti::Value getWordWrap(const std::vector<Ti::Value>& arguments);

			// Sets the value of the wordWrap property.
			TI_CREATE_METHOD(Label, setWordWrap);
			Ti::Value setWordWrap(const std::vector<Ti::Value>& arguments);

		private:

			Windows::UI::Xaml::Controls::TextBlock^ text_block_{ nullptr };
			std::string highlighted_color_;
		};

	}
}

#endif // #define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUILABEL_H_
