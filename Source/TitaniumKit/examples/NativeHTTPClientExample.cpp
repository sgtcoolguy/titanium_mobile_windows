/**
 * TitaniumKit
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeHTTPClientExample.hpp"
#include "Titanium/detail/TiLogger.hpp"

NativeHTTPClientExample::NativeHTTPClientExample(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::Network::HTTPClient(js_context)
{
	TITANIUM_LOG_DEBUG("NativeHTTPClientExample:: ctor ", this);
}

NativeHTTPClientExample::~NativeHTTPClientExample() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeHTTPClientExample:: dtor ", this);
}

void NativeHTTPClientExample::JSExportInitialize()
{
	JSExport<NativeHTTPClientExample>::SetClassVersion(1);
	JSExport<NativeHTTPClientExample>::SetParent(JSExport<Titanium::Network::HTTPClient>::Class());
}
