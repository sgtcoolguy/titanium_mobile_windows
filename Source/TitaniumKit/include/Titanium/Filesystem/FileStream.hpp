/**
 * TitaniumKit Titanium.Filesystem.FileStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_FILESYSTEM_FILESTREAM_HPP_
#define _TITANIUM_FILESYSTEM_FILESTREAM_HPP_

#include "Titanium/IOStream.hpp"

namespace Titanium
{
	namespace Filesystem
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium FileStream Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Filesystem.FileStream
		*/
		class TITANIUMKIT_EXPORT FileStream : public IOStream, public JSExport<FileStream>
		{

		public:

			/*!
			  @method
			  @abstract read
			  @discussion Reads data from this stream into a buffer.
			*/
			virtual std::int32_t read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract write
			  @discussion Writes data from a buffer to this stream.
			*/
			virtual std::uint32_t write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract isWriteable
			  @discussion Indicates whether this stream is writeable.
			*/
			virtual bool isWriteable() TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract isReadable
			  @discussion Indicates whether this stream is readable.
			*/
			virtual bool isReadable() TITANIUM_NOEXCEPT override;

			/*!
			  @method
			  @abstract close
			  @discussion Closes this stream.
			*/
			virtual void close() TITANIUM_NOEXCEPT override;

			FileStream(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~FileStream()                    = default;
			FileStream(const FileStream&)            = default;
			FileStream& operator=(const FileStream&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			FileStream(FileStream&&)                 = default;
			FileStream& operator=(FileStream&&)      = default;
#endif

			static void JSExportInitialize();

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
#pragma warning(pop)
		};

	} // namespace Filesystem
} // namespace Titanium
#endif // _TITANIUM_FILESYSTEM_FILESTREAM_HPP_