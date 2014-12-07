/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiUISearchBar.h"
#include <Windows.h>

namespace Ti { namespace UI {
	// These are JavaScript methods they will call class methods
	const JSStaticFunction SearchBar::ClassMethods[] = {
		{"setAutocapitalization" ,_setAutocapitalization ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getAutocapitalization" ,_getAutocapitalization ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setAutocorrect" ,_setAutocorrect ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getAutocorrect" ,_getAutocorrect ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setBarColor" ,_setBarColor ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getBarColor" ,_getBarColor ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setEnabled" ,_setEnabled ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getEnabled" ,_getEnabled ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setHintText" ,_setHintText ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getHintText" ,_getHintText ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setHinttextid" ,_setHinttextid ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getHinttextid" ,_getHinttextid ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setKeyboardType" ,_setKeyboardType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getKeyboardType" ,_getKeyboardType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setPrompt" ,_setPrompt ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getPrompt" ,_getPrompt ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setPromptid" ,_setPromptid ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getPromptid" ,_getPromptid ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setShowBookmark" ,_setShowBookmark ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getShowBookmark" ,_getShowBookmark ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setShowCancel" ,_setShowCancel ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getShowCancel" ,_getShowCancel ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setValue" ,_setValue ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getValue" ,_getValue ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"blur" ,_blur ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"finishLayout" ,_finishLayout ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"focus" ,_focus ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"startLayout" ,_startLayout ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"updateLayout" ,_updateLayout ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{0,0,0}
	};
	
	SearchBar::~SearchBar()
	{
	
	}
	SearchBar::SearchBar(const std::string& name, const std::vector<Ti::Value>& args) : Ti::ViewProxy(name, args)
	{

		search_box_ = ref new Windows::UI::Xaml::Controls::TextBox();
		setComponent(search_box_);
	}

	Ti::Value SearchBar::eventAdded(const std::vector<Ti::Value>& args)
	{
		return Ti::ViewProxy::eventAdded(args);
	}
	Ti::Value SearchBar::eventRemoved(const std::vector<Ti::Value>& args)
	{
		return Ti::ViewProxy::eventRemoved(args);
	}

	// Public API
	// Sets the value of the autocapitalization property.
	Ti::Value SearchBar::setAutocapitalization(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setAutocapitalization() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the autocapitalization property.
	Ti::Value SearchBar::getAutocapitalization(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getAutocapitalization() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the autocorrect property.
	Ti::Value SearchBar::setAutocorrect(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setAutocorrect() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the autocorrect property.
	Ti::Value SearchBar::getAutocorrect(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getAutocorrect() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the barColor property.
	Ti::Value SearchBar::setBarColor(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setBarColor() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the barColor property.
	Ti::Value SearchBar::getBarColor(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getBarColor() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the enabled property.
	Ti::Value SearchBar::setEnabled(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setEnabled() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the enabled property.
	Ti::Value SearchBar::getEnabled(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getEnabled() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the hintText property.
	Ti::Value SearchBar::setHintText(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setHintText() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the hintText property.
	Ti::Value SearchBar::getHintText(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getHintText() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the hinttextid property.
	Ti::Value SearchBar::setHinttextid(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setHinttextid() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the hinttextid property.
	Ti::Value SearchBar::getHinttextid(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getHinttextid() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the keyboardType property.
	Ti::Value SearchBar::setKeyboardType(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setKeyboardType() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the keyboardType property.
	Ti::Value SearchBar::getKeyboardType(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getKeyboardType() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the prompt property.
	Ti::Value SearchBar::setPrompt(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setPrompt() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the prompt property.
	Ti::Value SearchBar::getPrompt(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getPrompt() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the promptid property.
	Ti::Value SearchBar::setPromptid(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setPromptid() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the promptid property.
	Ti::Value SearchBar::getPromptid(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getPromptid() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the showBookmark property.
	Ti::Value SearchBar::setShowBookmark(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setShowBookmark() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the showBookmark property.
	Ti::Value SearchBar::getShowBookmark(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getShowBookmark() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Shows or hides the cancel button.
	Ti::Value SearchBar::setShowCancel(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setShowCancel() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the showCancel property.
	Ti::Value SearchBar::getShowCancel(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getShowCancel() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Sets the value of the value property.
	Ti::Value SearchBar::setValue(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.setValue() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Gets the value of the value property.
	Ti::Value SearchBar::getValue(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.getValue() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Causes the search bar to lose focus.
	Ti::Value SearchBar::blur(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.blur() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Finishes a batch update of the View's layout properties and schedules a layout pass of the 
	// view tree.
	Ti::Value SearchBar::finishLayout(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.finishLayout() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Causes the search bar to gain focus.
	Ti::Value SearchBar::focus(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.focus() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Starts a batch update of this view's layout properties.
	Ti::Value SearchBar::startLayout(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.startLayout() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
	// Performs a batch update of all supplied layout properties and schedules a layout pass after 
	// they have been updated.
	Ti::Value SearchBar::updateLayout(const std::vector<Ti::Value>& args)
	{
		OutputDebugString(L"[WARN] SearchBar.updateLayout() not implemented yet. Returning Undefined\n");
		return Ti::Value::Undefined();
	}
}}