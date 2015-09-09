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

	std::int32_t BufferStream::read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BufferStream::read: Unimplemented");
		return -1;
	}

	std::uint32_t BufferStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BufferStream::write: Unimplemented");
		return 0;
	}

	bool BufferStream::isWriteable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BufferStream::isWriteable: Unimplemented");
		return false;
	}

	bool BufferStream::isReadable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BufferStream::isReadable: Unimplemented");
		return false;
	}

	void BufferStream::close() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BufferStream::close: Unimplemented");
	}

	void BufferStream::JSExportInitialize() 
	{
		JSExport<BufferStream>::SetClassVersion(1);
		JSExport<BufferStream>::SetParent(JSExport<IOStream>::Class());
	}

} // namespace Titanium