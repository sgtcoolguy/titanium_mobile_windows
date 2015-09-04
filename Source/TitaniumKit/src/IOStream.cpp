/**
 * TitaniumKit Titanium.IOStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/IOStream.hpp"
#include "Titanium/Buffer.hpp"

namespace Titanium
{

	IOStream::IOStream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
	{
	}


	std::uint32_t IOStream::read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::read: Unimplemented");
		return 0;
	}

	std::uint32_t IOStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::write: Unimplemented");
		return 0;
	}

	bool IOStream::isWriteable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::isWriteable: Unimplemented");
		return false;
	}

	bool IOStream::isReadable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::isReadable: Unimplemented");
		return false;
	}

	void IOStream::close() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::close: Unimplemented");
	}

	void IOStream::JSExportInitialize() 
	{
		JSExport<IOStream>::SetClassVersion(1);
		JSExport<IOStream>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_FUNCTION(IOStream, read);
		TITANIUM_ADD_FUNCTION(IOStream, write);
		TITANIUM_ADD_FUNCTION(IOStream, isWriteable);
		TITANIUM_ADD_FUNCTION(IOStream, isReadable);
		TITANIUM_ADD_FUNCTION(IOStream, close);
	}

	TITANIUM_FUNCTION(IOStream, read)
	{
		ENSURE_OBJECT_AT_INDEX(buffer, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 1, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 2, 0);
		read(buffer.GetPrivate<Buffer>(), offset, length);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(IOStream, write)
	{
		ENSURE_OBJECT_AT_INDEX(buffer, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 1, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 2, 0);
		write(buffer.GetPrivate<Buffer>(), offset, length);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(IOStream, isWriteable)
	{
		return get_context().CreateBoolean(isWriteable());
	}

	TITANIUM_FUNCTION(IOStream, isReadable)
	{
		return get_context().CreateBoolean(isReadable());
	}

	TITANIUM_FUNCTION(IOStream, close)
	{
		close();
		return get_context().CreateUndefined();
	}
} // namespace Titanium