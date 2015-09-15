/**
 * TitaniumKit Titanium.Filesystem.FileStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Filesystem/FileStream.hpp"

namespace Titanium
{
	namespace Filesystem
	{

		FileStream::FileStream(const JSContext& js_context) TITANIUM_NOEXCEPT
			: IOStream(js_context)
		{
		}


		std::int32_t FileStream::read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("FileStream::read: Unimplemented");
			return -1;
		}

		std::uint32_t FileStream::write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("FileStream::write: Unimplemented");
			return 0;
		}

		bool FileStream::isWritable() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("FileStream::isWriteable: Unimplemented");
			return false;
		}

		bool FileStream::isReadable() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("FileStream::isReadable: Unimplemented");
			return false;
		}

		void FileStream::close() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("FileStream::close: Unimplemented");
		}
		
		void FileStream::JSExportInitialize() 
		{
			JSExport<FileStream>::SetClassVersion(1);
			JSExport<FileStream>::SetParent(JSExport<IOStream>::Class());
		}
	} // namespace Filesystem
} // namespace Titanium