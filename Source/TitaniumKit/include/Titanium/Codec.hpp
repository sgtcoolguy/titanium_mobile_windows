/**
 * TitaniumKit Titanium.Codec
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_CODEC_HPP_
#define _TITANIUM_CODEC_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Codec/Constants.hpp"

namespace Titanium
{
	using namespace HAL;

	namespace Codec
	{
		/*!
		  @class
		  @discussion This is the Titanium Codec Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Codec
		*/
		class TITANIUMKIT_EXPORT CodecModule : public Module, public JSExport<CodecModule>
		{

		public:

			/*!
			  @method
			  @abstract getNativeByteOrder
			  @discussion Get the OS native byte order (either <Titanium.Codec.BIG_ENDIAN> or<Titanium.Codec.LITTLE_ENDIAN>).
			*/
			virtual ByteOrder getNativeByteOrder() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract encodeNumber
			  @discussion Encodes a number and writes it to a buffer.
			*/
			virtual std::uint32_t encodeNumber(const EncodeNumberDict& options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract decodeNumber
			  @discussion Decodes a number from the `source` buffer using the specified data type.
			*/
			virtual double decodeNumber(const DecodeNumberDict& options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract encodeString
			  @discussion Encodes a string into a series of bytes in a buffer using the specified character set.
			*/
			virtual std::uint32_t encodeString(const EncodeStringDict& options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract decodeString
			  @discussion Decodes the source buffer into a String using the supplied character set.
			*/
			virtual std::string decodeString(const DecodeStringDict& options) TITANIUM_NOEXCEPT;

			CodecModule(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~CodecModule()               = default;
			CodecModule(const CodecModule&)            = default;
			CodecModule& operator=(const CodecModule&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			CodecModule(CodecModule&&)                 = default;
			CodecModule& operator=(CodecModule&&)      = default;
	#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_ASCII);
			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_ISO_LATIN_1);
			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_UTF8);
			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_UTF16);
			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_UTF16BE);
			TITANIUM_PROPERTY_READONLY_DEF(CHARSET_UTF16LE);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_BYTE);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_SHORT);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_INT);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_FLOAT);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_LONG);
			TITANIUM_PROPERTY_READONLY_DEF(TYPE_DOUBLE);
			TITANIUM_PROPERTY_READONLY_DEF(BIG_ENDIAN);
			TITANIUM_PROPERTY_READONLY_DEF(LITTLE_ENDIAN);

			TITANIUM_FUNCTION_DEF(getNativeByteOrder);
			TITANIUM_FUNCTION_DEF(encodeNumber);
			TITANIUM_FUNCTION_DEF(decodeNumber);
			TITANIUM_FUNCTION_DEF(encodeString);
			TITANIUM_FUNCTION_DEF(decodeString);

		protected:
			static std::uint32_t GetBOMOffsetForUnicode(const std::vector<std::uint8_t>& data, const std::uint32_t& offset, const CharSet& charset, const ByteOrder& byteOrder);
	#pragma warning(push)
	#pragma warning(disable : 4251)
			JSValue CHARSET_ASCII__;
			JSValue CHARSET_ISO_LATIN_1__;
			JSValue CHARSET_UTF8__;
			JSValue CHARSET_UTF16__;
			JSValue CHARSET_UTF16BE__;
			JSValue CHARSET_UTF16LE__;
			JSValue TYPE_BYTE__;
			JSValue TYPE_SHORT__;
			JSValue TYPE_INT__;
			JSValue TYPE_FLOAT__;
			JSValue TYPE_LONG__;
			JSValue TYPE_DOUBLE__;
			JSValue BIG_ENDIAN__;
			JSValue LITTLE_ENDIAN__;
	#pragma warning(pop)
		};

	} // namespace Codec
} // namespace Titanium
#endif // _TITANIUM_CODEC_HPP_