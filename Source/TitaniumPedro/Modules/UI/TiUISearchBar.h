/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_UI_SEARCHBAR_PROXY_H__
#define __TI_UI_SEARCHBAR_PROXY_H__

#include "TiCore/TiViewProxy.h"

namespace Ti {
	namespace UI {
		class SearchBar : public Ti::ViewProxy, public virtual_enable_shared_from_this<SearchBar>
		{
			TI_CREATE_PROXY(SearchBar)
			static JSClassRef Parent() { return Ti::ViewProxy::ClassDef(); }
		public:
			// TODO: Change this to desired layout
			virtual bool ingoreHeight() const { return true; }
			virtual bool ingoreWidth() const { return false; }
			virtual std::string defaultHeight() const { return Ti::Constants::SizeSIZE; }
			virtual std::string defaultWidth() const { return Ti::Constants::SizeFILL; }
			// Events
			virtual Ti::Value eventAdded(const std::vector<Ti::Value>&);
			virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&);
		protected:
			SearchBar(const std::string&, const std::vector<Ti::Value>&);
			virtual ~SearchBar();

			// JavaScript's public API

			// Sets the value of the autocapitalization property.
			Ti::Value setAutocapitalization(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setAutocapitalization);
			// Gets the value of the autocapitalization property.
			Ti::Value getAutocapitalization(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getAutocapitalization);
			// Sets the value of the autocorrect property.
			Ti::Value setAutocorrect(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setAutocorrect);
			// Gets the value of the autocorrect property.
			Ti::Value getAutocorrect(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getAutocorrect);
			// Sets the value of the barColor property.
			Ti::Value setBarColor(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setBarColor);
			// Gets the value of the barColor property.
			Ti::Value getBarColor(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getBarColor);
			// Sets the value of the enabled property.
			Ti::Value setEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setEnabled);
			// Gets the value of the enabled property.
			Ti::Value getEnabled(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getEnabled);
			// Sets the value of the hintText property.
			Ti::Value setHintText(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setHintText);
			// Gets the value of the hintText property.
			Ti::Value getHintText(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getHintText);
			// Sets the value of the hinttextid property.
			Ti::Value setHinttextid(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setHinttextid);
			// Gets the value of the hinttextid property.
			Ti::Value getHinttextid(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getHinttextid);
			// Sets the value of the keyboardType property.
			Ti::Value setKeyboardType(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setKeyboardType);
			// Gets the value of the keyboardType property.
			Ti::Value getKeyboardType(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getKeyboardType);
			// Sets the value of the prompt property.
			Ti::Value setPrompt(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setPrompt);
			// Gets the value of the prompt property.
			Ti::Value getPrompt(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getPrompt);
			// Sets the value of the promptid property.
			Ti::Value setPromptid(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setPromptid);
			// Gets the value of the promptid property.
			Ti::Value getPromptid(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getPromptid);
			// Sets the value of the showBookmark property.
			Ti::Value setShowBookmark(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setShowBookmark);
			// Gets the value of the showBookmark property.
			Ti::Value getShowBookmark(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getShowBookmark);
			// Shows or hides the cancel button.
			Ti::Value setShowCancel(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setShowCancel);
			// Gets the value of the showCancel property.
			Ti::Value getShowCancel(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getShowCancel);
			// Sets the value of the value property.
			Ti::Value setValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, setValue);
			// Gets the value of the value property.
			Ti::Value getValue(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, getValue);
			// Causes the search bar to lose focus.
			Ti::Value blur(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, blur);
			// Finishes a batch update of the View's layout properties and schedules a layout pass of the 
			// view tree.
			Ti::Value finishLayout(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, finishLayout);
			// Causes the search bar to gain focus.
			Ti::Value focus(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, focus);
			// Starts a batch update of this view's layout properties.
			Ti::Value startLayout(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, startLayout);
			// Performs a batch update of all supplied layout properties and schedules a layout pass after 
			// they have been updated.
			Ti::Value updateLayout(const std::vector<Ti::Value>& args);
			TI_CREATE_METHOD(SearchBar, updateLayout);
		private:
			Windows::UI::Xaml::Controls::TextBox^ search_box_;
		};
	}
}
#endif // defined(__TI_UI_SEARCHBAR_PROXY_H__)