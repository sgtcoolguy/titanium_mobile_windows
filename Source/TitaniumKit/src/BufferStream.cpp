/**
 * TitaniumKit Titanium.BufferStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/BufferStream.hpp"
#include "Titanium/Buffer.hpp"

namespace Titanium
{

	BufferStream::BufferStream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: IOStream(js_context)
	{

	}

	void BufferStream::construct(const std::shared_ptr<Buffer>& buffer)
	{
		TITANIUM_ASSERT(buffer != nullptr);
		buffer__ = buffer;
	}

	std::int32_t BufferStream::read(const std::shared_ptr<Buffer>& write_buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		const auto read_buffer_length = buffer__->get_length();
		const auto write_buffer_length = write_buffer->get_length();
		if (totalBytesProcessed__ >= read_buffer_length || offset >= write_buffer_length) {
			return -1;
		}

		std::uint32_t  bytesToRead = length;
		if (totalBytesProcessed__ + bytesToRead > read_buffer_length) {
			bytesToRead = read_buffer_length - totalBytesProcessed__;
		}

		bytesToRead = write_buffer->copy(buffer__, offset, totalBytesProcessed__, bytesToRead);

		totalBytesProcessed__ += bytesToRead;
		return bytesToRead;
	}

	std::uint32_t BufferStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		if (!isWritable()) {
			HAL::detail::ThrowRuntimeError("Titanium::BufferStream::write", "Unable to write to a Stream which is read-only.");
		}
		if (modes__.find(Filesystem::MODE::APPEND) != modes__.end()) {
			buffer__->append(buffer, offset, length);
		} else {
			if (buffer__->get_length() <= totalBytesProcessed__) {
				return 0;
			}
			buffer__->copy(buffer, totalBytesProcessed__, offset, length);
		}
		totalBytesProcessed__ += length;
		return length;
	}

	void BufferStream::close() TITANIUM_NOEXCEPT
	{

	}

	void BufferStream::JSExportInitialize() 
	{
		JSExport<BufferStream>::SetClassVersion(1);
		JSExport<BufferStream>::SetParent(JSExport<IOStream>::Class());
	}

} // namespace Titanium