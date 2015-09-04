/**
 * TitaniumKit Titanium.BufferStream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_BUFFERSTREAM_HPP_
#define _TITANIUM_BUFFERSTREAM_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/IOStream.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
	  @class
	  @discussion This is the Titanium BufferStream Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.BufferStream
	*/
	class TITANIUMKIT_EXPORT BufferStream : public IOStream, public JSExport<BufferStream>
	{

	public:

		BufferStream(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~BufferStream()                            = default;
		BufferStream(const BufferStream&)            = default;
		BufferStream& operator=(const BufferStream&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		BufferStream(BufferStream&&)                 = default;
		BufferStream& operator=(BufferStream&&)      = default;
#endif

		static void JSExportInitialize();

	protected:
#pragma warning(push)
#pragma warning(disable : 4251)
#pragma warning(pop)
	};

} // namespace Titanium
#endif // _TITANIUM_BUFFERSTREAM_HPP_