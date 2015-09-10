/**
 * TitaniumKit Titanium.IOStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_IOSTREAM_HPP_
#define _TITANIUM_IOSTREAM_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	using namespace HAL;

	class Buffer;

	/*!
	  @class
	  @discussion This is the Titanium IOStream Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.IOStream
	*/
	class TITANIUMKIT_EXPORT IOStream : public Module, public JSExport<IOStream>
	{

	public:

		/*!
		  @method
		  @abstract read
		  @discussion Reads data from this stream into a buffer.
		*/
		virtual std::int32_t read(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT;
		virtual void readAsync(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length, const std::function<void(const std::int32_t&)>&) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract write
		  @discussion Writes data from a buffer to this stream.
		*/
		virtual std::uint32_t write(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT;
		virtual void writeAsync(const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length, const std::function<void(const std::int32_t&)>&) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract isWriteable
		  @discussion Indicates whether this stream is writeable.
		*/
		virtual bool isWriteable() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract isReadable
		  @discussion Indicates whether this stream is readable.
		*/
		virtual bool isReadable() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract close
		  @discussion Closes this stream.
		*/
		virtual void close() TITANIUM_NOEXCEPT;

		IOStream(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~IOStream()                  = default;
		IOStream(const IOStream&)            = default;
		IOStream& operator=(const IOStream&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		IOStream(IOStream&&)                 = default;
		IOStream& operator=(IOStream&&)      = default;
#endif

		static void JSExportInitialize();

		TITANIUM_FUNCTION_DEF(read);
		TITANIUM_FUNCTION_DEF(write);
		TITANIUM_FUNCTION_DEF(isWriteable);
		TITANIUM_FUNCTION_DEF(isReadable);
		TITANIUM_FUNCTION_DEF(close);

	protected:
#pragma warning(push)
#pragma warning(disable : 4251)
#pragma warning(pop)
	};

} // namespace Titanium
#endif // _TITANIUM_IOSTREAM_HPP_