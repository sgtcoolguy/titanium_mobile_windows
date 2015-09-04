/**
 * TitaniumKit Titanium.BufferStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/BufferStream.hpp"

namespace Titanium
{

	BufferStream::BufferStream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: IOStream(js_context)
	{

	}

	void BufferStream::JSExportInitialize() 
	{
		JSExport<BufferStream>::SetClassVersion(1);
		JSExport<BufferStream>::SetParent(JSExport<IOStream>::Class());
	}

} // namespace Titanium