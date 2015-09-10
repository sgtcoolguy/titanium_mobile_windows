/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_CODEC_HPP_
#define _TITANIUMWINDOWS_CODEC_HPP_

#include "Titanium/Codec.hpp"
#include "TitaniumWindows_Ti_EXPORT.h"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class

	  @discussion This is Codec module implementation for Windows.
	*/
	class TITANIUMWINDOWS_TI_EXPORT Codec final : public Titanium::Codec::CodecModule, public JSExport<Codec>
	{
	public:

		/*!
		@method
		@abstract getNativeByteOrder
		@discussion Get the OS native byte order (either <Titanium.Codec.BIG_ENDIAN> or<Titanium.Codec.LITTLE_ENDIAN>).
		*/
		virtual Titanium::Codec::ByteOrder getNativeByteOrder() TITANIUM_NOEXCEPT;

		/*!
		@method
		@abstract encodeNumber
		@discussion Encodes a number and writes it to a buffer.
		*/
		virtual std::uint32_t encodeNumber(const Titanium::Codec::EncodeNumberDict& options) TITANIUM_NOEXCEPT override;

		/*!
		@method
		@abstract decodeNumber
		@discussion Decodes a number from the `source` buffer using the specified data type.
		*/
		virtual double decodeNumber(const Titanium::Codec::DecodeNumberDict& options) TITANIUM_NOEXCEPT override;

		/*!
		@method
		@abstract encodeString
		@discussion Encodes a string into a series of bytes in a buffer using the specified character set.
		*/
		virtual std::uint32_t encodeString(const Titanium::Codec::EncodeStringDict& options) TITANIUM_NOEXCEPT override;

		/*!
		@method
		@abstract decodeString
		@discussion Decodes the source buffer into a String using the supplied character set.
		*/
		virtual std::string decodeString(const Titanium::Codec::DecodeStringDict& options) TITANIUM_NOEXCEPT override;

		Codec(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~Codec();
		Codec(const Codec&) = default;
		Codec& operator=(const Codec&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Codec(Codec&&) = default;
		Codec& operator=(Codec&&) = default;
#endif

		static void JSExportInitialize();

	protected:

		const std::uint8_t SHORT_DOWNCAST_BITS = 6;
		const std::uint8_t INT_DOWNCAST_BITS   = 4;

		// Get BinaryStringEncoding from Titanium::Codec::CharSet
		static Windows::Security::Cryptography::BinaryStringEncoding GetWindowsEncoding(const Titanium::Codec::CharSet&, const Titanium::Codec::ByteOrder&);
		static Windows::Storage::Streams::ByteOrder GetWindowsByteOrder(const Titanium::Codec::ByteOrder&);
		Windows::Storage::Streams::DataWriter^ writer__;
	};

}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_CODEC_HPP_
