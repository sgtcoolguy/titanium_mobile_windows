/**
 * TitaniumKit Titanium.BlobStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/BlobStream.hpp"
#include "Titanium/Blob.hpp"
#include "Titanium/Buffer.hpp"

namespace Titanium
{

	BlobStream::BlobStream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: IOStream(js_context)
	{

	}

	void BlobStream::construct(const std::shared_ptr<Blob>& blob) 
	{
		TITANIUM_ASSERT(blob != nullptr);
		blob__ = blob;
	}

	std::int32_t BlobStream::read(const std::shared_ptr<Buffer>& write_buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		const auto buffer_ctor = get_context().JSEvaluateScript("Ti.Buffer"); \
		const auto buffer_object = static_cast<JSObject>(buffer_ctor).CallAsConstructor();
		auto source_buffer = buffer_object.GetPrivate<Buffer>();
		source_buffer->construct(blob__->getData());

		const auto read_buffer_length  = source_buffer->get_length();
		const auto write_buffer_length = write_buffer->get_length();
		if (totalBytesProcessed__ >= read_buffer_length || offset >= write_buffer_length) {
			return -1;
		}

		auto bytesToRead = length;
		if (totalBytesProcessed__ + bytesToRead > read_buffer_length) {
			bytesToRead = read_buffer_length - totalBytesProcessed__;
		}
		bytesToRead = write_buffer->copy(source_buffer, offset, totalBytesProcessed__, bytesToRead);

		totalBytesProcessed__ += bytesToRead;
		return bytesToRead;
	}

	std::uint32_t BlobStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		HAL::detail::ThrowRuntimeError("Titanium::BlobStream", "Invalid operation: BlobStream is read-only");
		return 0;
	}

	void BlobStream::close() TITANIUM_NOEXCEPT
	{

	}

	void BlobStream::JSExportInitialize() 
	{
		JSExport<BlobStream>::SetClassVersion(1);
		JSExport<BlobStream>::SetParent(JSExport<IOStream>::Class());
	}

} // namespace Titanium