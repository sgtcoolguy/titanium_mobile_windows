/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeViewExample.hpp"

NativeViewLayoutDelegate::NativeViewLayoutDelegate(JSObject& this_object)
{
	this_object.SetProperty("NativeViewLayoutDelegate_called", this_object.get_context().CreateBoolean(true));
}

void NativeViewLayoutDelegate::set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT
{
	ViewLayoutDelegate::set_backgroundColor(backgroundColor);
	TITANIUM_LOG_DEBUG("NativeViewExample:: set_backgroundColor(", backgroundColor, ")");
}

NativeViewExample::NativeViewExample(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::UI::View(js_context)
{
	TITANIUM_LOG_DEBUG("NativeViewExample:: ctor ", this);
}

void NativeViewExample::postInitialize(JSObject& js_object) 
{
	Titanium::UI::View::postInitialize(js_object);	
	Titanium::UI::View::setLayoutDelegate<NativeViewLayoutDelegate>(js_object);
}

NativeViewExample::~NativeViewExample() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeViewExample:: dtor ", this);
}

void NativeViewExample::JSExportInitialize()
{
	JSExport<NativeViewExample>::SetClassVersion(1);
	JSExport<NativeViewExample>::SetParent(JSExport<Titanium::UI::View>::Class());
}
