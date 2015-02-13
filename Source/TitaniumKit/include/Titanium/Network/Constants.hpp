/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NETWORK_CONSTANTS_HPP_
#define _TITANIUM_NETWORK_CONSTANTS_HPP_

#include "Titanium/detail/TiBase.hpp"
#include <unordered_set>
#include <functional>

namespace Titanium
{
	namespace Network
	{
		enum class TITANIUMKIT_EXPORT TYPE {
			LAN,
			MOBILE,
			NONE,
			UNKNOWN,
			WIFI
		};

		enum class TITANIUMKIT_EXPORT NOTIFICATION_TYPE {
			ALERT,
			BADGE,
			NEWSSTAND,
			SOUND
		};

		enum class TITANIUMKIT_EXPORT TLS_VERSION {
			ONE_ZERO,
			ONE_ONE,
			ONE_TWO
		};
	} // namespace Network
}  // namespace Titanium

// Provide a hash function so that a Titanium::Network::TYPE can be stored in an
// unordered container.
namespace std
{
	using Titanium::Network::TYPE;
	template <>
	struct hash<TYPE>
	{
		using argument_type = TYPE;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};

	using Titanium::Network::NOTIFICATION_TYPE;
	template <>
	struct hash<NOTIFICATION_TYPE>
	{
		using argument_type = NOTIFICATION_TYPE;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};

	using Titanium::Network::TLS_VERSION;
	template <>
	struct hash<TLS_VERSION>
	{
		using argument_type = TLS_VERSION;
		using result_type = std::size_t;
		using underlying_type = std::underlying_type<argument_type>::type;
		std::hash<underlying_type> hash_function = std::hash<underlying_type>();

		result_type operator()(const argument_type& property_attribute) const
		{
			return hash_function(static_cast<underlying_type>(property_attribute));
		}
	};
}  // namespace std

namespace Titanium
{
	namespace Network
	{
		class TITANIUMKIT_EXPORT Constants final
		{
		public:

			static const int32_t PROGRESS_UNKNOWN = -1;

			static std::string to_string(const TYPE&) TITANIUM_NOEXCEPT;
			static TYPE to_TYPE(const std::string& typeName) TITANIUM_NOEXCEPT;
			static TYPE to_TYPE(std::underlying_type<TYPE>::type) TITANIUM_NOEXCEPT;
			static std::underlying_type<TYPE>::type to_underlying_type(const TYPE&) TITANIUM_NOEXCEPT;

			static std::string to_string(const NOTIFICATION_TYPE&) TITANIUM_NOEXCEPT;
			static NOTIFICATION_TYPE to_NOTIFICATION_TYPE(const std::string& notificationTypeName) TITANIUM_NOEXCEPT;
			static NOTIFICATION_TYPE to_NOTIFICATION_TYPE(std::underlying_type<NOTIFICATION_TYPE>::type) TITANIUM_NOEXCEPT;
			static std::underlying_type<NOTIFICATION_TYPE>::type to_underlying_type(const NOTIFICATION_TYPE&) TITANIUM_NOEXCEPT;

			static std::string to_string(const TLS_VERSION&) TITANIUM_NOEXCEPT;
			static TLS_VERSION to_TLS_VERSION(const std::string& tlsVersionName) TITANIUM_NOEXCEPT;
			static TLS_VERSION to_TLS_VERSION(std::underlying_type<TLS_VERSION>::type) TITANIUM_NOEXCEPT;
			static std::underlying_type<TLS_VERSION>::type to_underlying_type(const TLS_VERSION&) TITANIUM_NOEXCEPT;
		};
	} // namespace Network
}  // namespace Titanium

#endif  // _TITANIUM_NETWORK_CONSTANTS_HPP_
