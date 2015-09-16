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

	std::int32_t IOStream::read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::read: Unimplemented");
		return -1;
	}

	void IOStream::readAsync(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length, const std::function<void(const std::int32_t&)>& callback) TITANIUM_NOEXCEPT
	{
		callback(read(buffer, offset, length));
	}

	std::uint32_t IOStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("IOStream::write: Unimplemented");
		return 0;
	}

	void IOStream::writeAsync(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length, const std::function<void(const std::int32_t&)>& callback) TITANIUM_NOEXCEPT
	{
		callback(write(buffer, offset, length));
	}

	bool IOStream::isWritable() TITANIUM_NOEXCEPT
	{
		return (modes__.find(Filesystem::MODE::WRITE) != modes__.end() || modes__.find(Filesystem::MODE::APPEND) != modes__.end());
	}

	bool IOStream::isReadable() TITANIUM_NOEXCEPT
	{
		return modes__.find(Filesystem::MODE::READ) != modes__.end();
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
		TITANIUM_ADD_FUNCTION(IOStream, isWritable);
		TITANIUM_ADD_FUNCTION(IOStream, isReadable);
		TITANIUM_ADD_FUNCTION(IOStream, close);
	}

	TITANIUM_FUNCTION(IOStream, read)
	{
		ENSURE_OBJECT_AT_INDEX(buffer_object, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 1, 0);
		const auto buffer = buffer_object.GetPrivate<Buffer>();
		if (buffer == nullptr) {
			HAL::detail::ThrowRuntimeError("Titanium::IOStream::read", "Titanium::IOStream::read: Invalid arguments");
		}
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 2, buffer->get_length());
		return get_context().CreateNumber(read(buffer, offset, length));
	}

	TITANIUM_FUNCTION(IOStream, write)
	{
		ENSURE_OBJECT_AT_INDEX(buffer_object, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 1, 0);
		const auto buffer = buffer_object.GetPrivate<Buffer>();
		if (buffer == nullptr) {
			HAL::detail::ThrowRuntimeError("Titanium::IOStream::read", "Titanium::IOStream::read: Invalid arguments");
		}
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 2, buffer->get_length());
		return get_context().CreateNumber(write(buffer, offset, length));
	}

	TITANIUM_FUNCTION(IOStream, isWritable)
	{
		return get_context().CreateBoolean(isWritable());
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