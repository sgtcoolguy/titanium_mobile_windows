/**
 * TitaniumKit Titanium.Codec
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_CODEC_CONSTANTS_HPP_
#define _TITANIUM_CODEC_CONSTANTS_HPP_

#include "Titanium/detail/TiBase.hpp"

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
			Double,
			Unknown
		};

		/*!
		  @struct
		  @discussion Named parameters for Titanium.Codec.decodeNumber.
		  This is an abstract type. Any object meeting this description can be used where this type is used.
		  See http://docs.appcelerator.com/titanium/3.0/#!/api/DecodeNumberDict  
		*/
		struct DecodeNumberDict 
		{
			ByteOrder byteOrder { ByteOrder::Unknown };
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
			ByteOrder byteOrder { ByteOrder::Unknown };
			std::shared_ptr<Buffer> dest { nullptr };
			std::uint32_t position { 0 };
			double source { 0 };
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
			std::uint32_t destPosition { 0 };
			std::string source;
			std::uint32_t sourceLength { 0 };
			std::uint32_t sourcePosition { 0 };
			bool expand_buffer_if_needed { false }; // expand dest buffer if needed
		};
		
		TITANIUMKIT_EXPORT EncodeStringDict  js_to_EncodeStringDict(const JSObject& object);
		TITANIUMKIT_EXPORT JSObject EncodeStringDict_to_js(const JSContext& js_context, EncodeStringDict  value);

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

#endif // _TITANIUM_CODEC_CONSTANTS_HPP_