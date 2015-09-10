/**
 * TitaniumKit Titanium.BlobStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/BlobStream.hpp"

namespace Titanium
{

	BlobStream::BlobStream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: IOStream(js_context)
	{

	}

	std::int32_t BlobStream::read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BlobStream::read: Unimplemented");
		return -1;
	}

	std::uint32_t BlobStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BlobStream::write: Unimplemented");
		return 0;
	}

	bool BlobStream::isWriteable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BlobStream::isWriteable: Unimplemented");
		return false;
	}

	bool BlobStream::isReadable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BlobStream::isReadable: Unimplemented");
		return false;
	}

	void BlobStream::close() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("BlobStream::close: Unimplemented");
	}

	void BlobStream::JSExportInitialize() 
	{
		JSExport<BlobStream>::SetClassVersion(1);
		JSExport<BlobStream>::SetParent(JSExport<IOStream>::Class());
	}

} // namespace Titanium