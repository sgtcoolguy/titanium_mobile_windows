/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeViewExample.hpp"

NativeViewExample::NativeViewExample(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::UI::View(js_context)
{
	TITANIUM_LOG_DEBUG("NativeViewExample:: ctor 1 ", this);
}

NativeViewExample::NativeViewExample(const NativeViewExample& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
    : Titanium::UI::View(rhs, arguments)
{
	TITANIUM_LOG_DEBUG("NativeViewExample:: ctor 2 ", this);
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

void NativeViewExample::set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_INFO("NativeViewExample::set_backgroundColor: backgroundColor = ", backgroundColor);
}
