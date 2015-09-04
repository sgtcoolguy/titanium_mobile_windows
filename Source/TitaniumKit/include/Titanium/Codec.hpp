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

namespace Titanium
{
	using namespace HAL;

	class Buffer;

	namespace Codec
	{
		enum class TITANIUMKIT_EXPORT ByteOrder
		{
			BigEndian,
			LittleEndian,
			Unknown
		};

		enum class TITANIUMKIT_EXPORT CharSet
		{
			ASCII,
			ISO_LATIN_1,
			UTF8,
			UTF16,
			UTF16BE,
			UTF16LE
		};

		enum class TITANIUMKIT_EXPORT Type
		{
			Byte,
			Short,
			Int,
			Float,
			Long,
			Double
		};

		/*!
		  @struct
		  @discussion Named parameters for Titanium.Codec.decodeNumber.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/3.0/#!/api/DecodeNumberDict  
		*/
		struct DecodeNumberDict 
		{
			ByteOrder byteOrder { ByteOrder::LittleEndian };
			std::uint32_t position { 0 };
			std::shared_ptr<Buffer> source { nullptr };
			Type type { Type::Int };
		};
		
		TITANIUMKIT_EXPORT DecodeNumberDict  js_to_DecodeNumberDict(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject DecodeNumberDict_to_js(const JSContext& js_context, DecodeNumberDict  value);

		/*!
		  @struct
		  @discussion Named parameters for Titanium.Codec.decodeString
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/3.0/#!/api/DecodeStringDict  
		*/
		struct DecodeStringDict 
		{
			CharSet charset { CharSet::UTF8 };
			std::uint32_t length { 0 };
			std::uint32_t position { 0 };
			std::shared_ptr<Buffer> source { nullptr };
		};
		
		TITANIUMKIT_EXPORT DecodeStringDict  js_to_DecodeStringDict(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject DecodeStringDict_to_js(const JSContext& js_context, DecodeStringDict  value);

		/*!
		  @struct
		  @discussion Named parameters for Titanium.Codec.encodeNumber.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/3.0/#!/api/EncodeNumberDict  
		*/
		struct EncodeNumberDict 
		{
			ByteOrder byteOrder { ByteOrder::LittleEndian };
			std::shared_ptr<Buffer> dest { nullptr };
			std::uint32_t position { 0 };
			std::uint32_t source { 0 };
			Type type { Type::Int };
		};
		
		TITANIUMKIT_EXPORT EncodeNumberDict  js_to_EncodeNumberDict(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject EncodeNumberDict_to_js(const JSContext& js_context, EncodeNumberDict  value);

		/*!
		  @struct
		  @discussion Named parameters for Titanium.Codec.encodeString.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/3.0/#!/api/EncodeStringDict  
		*/
		struct EncodeStringDict 
		{
			CharSet charset { CharSet::UTF8 };
			std::shared_ptr<Buffer> dest { nullptr };
			std::string source { "" };
			std::uint32_t sourceLength { 0 };
			std::uint32_t sourcePosition { 0 };
		};
		
		TITANIUMKIT_EXPORT EncodeStringDict  js_to_EncodeStringDict(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject EncodeStringDict_to_js(const JSContext& js_context, EncodeStringDict  value);

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
			virtual std::uint32_t encodeNumber(EncodeNumberDict options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract decodeNumber
			  @discussion Decodes a number from the `source` buffer using the specified data type.
			*/
			virtual std::uint32_t decodeNumber(DecodeNumberDict options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract encodeString
			  @discussion Encodes a string into a series of bytes in a buffer using the specified character set.
			*/
			virtual std::uint32_t encodeString(EncodeStringDict options) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract decodeString
			  @discussion Decodes the source buffer into a String using the supplied character set.
			*/
			virtual std::string decodeString(DecodeStringDict options) TITANIUM_NOEXCEPT;

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

		class TITANIUMKIT_EXPORT Constants final
		{
		public:
			static std::string to_string(const ByteOrder&) TITANIUM_NOEXCEPT;
			static std::string to_string(const CharSet&) TITANIUM_NOEXCEPT;
			static std::string to_string(const Type&) TITANIUM_NOEXCEPT;
			
			static ByteOrder to_ByteOrder(const std::string& fieldTypeName) TITANIUM_NOEXCEPT;
			static CharSet to_CharSet(const std::string& fieldTypeName) TITANIUM_NOEXCEPT;
			static Type to_Type(const std::string& fieldTypeName) TITANIUM_NOEXCEPT;

			static ByteOrder to_ByteOrder(std::underlying_type<ByteOrder>::type) TITANIUM_NOEXCEPT;
			static CharSet to_CharSet(std::underlying_type<CharSet>::type) TITANIUM_NOEXCEPT;
			static Type to_Type(std::underlying_type<Type>::type) TITANIUM_NOEXCEPT;
			
			static std::underlying_type<ByteOrder>::type to_underlying_type(const ByteOrder&) TITANIUM_NOEXCEPT;
			static std::underlying_type<CharSet>::type to_underlying_type(const CharSet&) TITANIUM_NOEXCEPT;
			static std::underlying_type<Type>::type to_underlying_type(const Type&) TITANIUM_NOEXCEPT;
		};
	} // namespace Codec
} // namespace Titanium

// Provide a hash function so that constants can be stored in an
// unordered container.
namespace std
{
	using Titanium::Codec::ByteOrder;
	template <>
	struct hash<ByteOrder>
	{
		using argument_type = ByteOrder;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};

	using Titanium::Codec::CharSet;
	template <>
	struct hash<CharSet>
	{
		using argument_type = CharSet;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};

	using Titanium::Codec::Type;
	template <>
	struct hash<Type>
	{
		using argument_type = Type;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};
} // namespace std
#endif // _TITANIUM_CODEC_HPP_