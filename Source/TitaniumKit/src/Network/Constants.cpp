/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Network/Constants.hpp"
#include <unordered_map>
#include <mutex>

namespace Titanium
{
	namespace Network
	{
		std::string Constants::to_string(const TYPE& networkType) TITANIUM_NOEXCEPT
		{
			static std::string unknown_string = "UNKNOWN";
			static std::unordered_map<TYPE, std::string> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[TYPE::LAN]    = "LAN";
				map[TYPE::MOBILE] = "MOBILE";
				map[TYPE::NONE]   = "NONE";
				map[TYPE::UNKNOWN] = "UNKNOWN";
				map[TYPE::WIFI]	= "WIFI";
			});

			std::string string = unknown_string;
			const auto position = map.find(networkType);
			if (position != map.end()) {
				string = position->second;
			}

			return string;
		}

		TYPE Constants::to_TYPE(const std::string& networkTypeName) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::string, TYPE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map["LAN"]    = TYPE::LAN;
				map["MOBILE"] = TYPE::MOBILE;
				map["NONE"]   = TYPE::NONE;
				map["UNKNOWN"] = TYPE::UNKNOWN;
				map["WIFI"]    = TYPE::WIFI;
			});

			TYPE networkType = TYPE::UNKNOWN;
			const auto position = map.find(networkTypeName);
			if (position != map.end()) {
				networkType = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_TYPE: Titanium::Network::TYPE with name '", networkTypeName, "' does not exist");
			}

			return networkType;
		}

		TYPE Constants::to_TYPE(std::underlying_type<TYPE>::type networkType_underlying_type) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::underlying_type<TYPE>::type, TYPE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[static_cast<std::underlying_type<TYPE>::type>(TYPE::LAN)]    = TYPE::LAN;
				map[static_cast<std::underlying_type<TYPE>::type>(TYPE::MOBILE)] = TYPE::MOBILE;
				map[static_cast<std::underlying_type<TYPE>::type>(TYPE::NONE)] = TYPE::NONE;
				map[static_cast<std::underlying_type<TYPE>::type>(TYPE::UNKNOWN)] = TYPE::UNKNOWN;
				map[static_cast<std::underlying_type<TYPE>::type>(TYPE::WIFI)]    = TYPE::WIFI;
			});

			TYPE networkType = TYPE::UNKNOWN;
			const auto position = map.find(networkType_underlying_type);
			if (position != map.end()) {
				networkType = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_TYPE: Titanium::Network::TYPE with value '", networkType_underlying_type, "' does not exist");
			}

			return networkType;
		}

		std::underlying_type<TYPE>::type Constants::to_underlying_type(const TYPE& networkType) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<TYPE>::type>(networkType);
		}

		std::string Constants::to_string(const NOTIFICATION_TYPE& notificationType) TITANIUM_NOEXCEPT
		{
			static std::string unknown_string = "ALERT";
			static std::unordered_map<NOTIFICATION_TYPE, std::string> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[NOTIFICATION_TYPE::ALERT] = "ALERT";
				map[NOTIFICATION_TYPE::BADGE] = "BADGE";
				map[NOTIFICATION_TYPE::NEWSSTAND] = "NEWSSTAND";
				map[NOTIFICATION_TYPE::SOUND]     = "SOUND";
			});

			std::string string = unknown_string;
			const auto position = map.find(notificationType);
			if (position != map.end()) {
				string = position->second;
			}

			return string;
		}

		NOTIFICATION_TYPE Constants::to_NOTIFICATION_TYPE(const std::string& notificationTypeName) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::string, NOTIFICATION_TYPE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map["ALERT"] = NOTIFICATION_TYPE::ALERT;
				map["BADGE"] = NOTIFICATION_TYPE::BADGE;
				map["NEWSSTAND"] = NOTIFICATION_TYPE::NEWSSTAND;
				map["SOUND"]     = NOTIFICATION_TYPE::SOUND;
			});

			NOTIFICATION_TYPE notificationType = NOTIFICATION_TYPE::ALERT;
			const auto position = map.find(notificationTypeName);
			if (position != map.end()) {
				notificationType = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_NOTIFICATION_TYPE: Titanium::Network::NOTIFICATION_TYPE with name '", notificationTypeName, "' does not exist");
			}

			return notificationType;
		}

		NOTIFICATION_TYPE Constants::to_NOTIFICATION_TYPE(std::underlying_type<NOTIFICATION_TYPE>::type notificationType_underlying_type) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::underlying_type<NOTIFICATION_TYPE>::type, NOTIFICATION_TYPE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[static_cast<std::underlying_type<NOTIFICATION_TYPE>::type>(NOTIFICATION_TYPE::ALERT)]     = NOTIFICATION_TYPE::ALERT;
				map[static_cast<std::underlying_type<NOTIFICATION_TYPE>::type>(NOTIFICATION_TYPE::BADGE)] = NOTIFICATION_TYPE::BADGE;
				map[static_cast<std::underlying_type<NOTIFICATION_TYPE>::type>(NOTIFICATION_TYPE::NEWSSTAND)] = NOTIFICATION_TYPE::NEWSSTAND;
				map[static_cast<std::underlying_type<NOTIFICATION_TYPE>::type>(NOTIFICATION_TYPE::SOUND)]     = NOTIFICATION_TYPE::SOUND;
			});

			NOTIFICATION_TYPE notificationType = NOTIFICATION_TYPE::ALERT;
			const auto position = map.find(notificationType_underlying_type);
			if (position != map.end()) {
				notificationType = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_NOTIFICATION_TYPE: Titanium::Network::NOTIFICATION_TYPE with value '", notificationType_underlying_type, "' does not exist");
			}

			return notificationType;
		}

		std::underlying_type<NOTIFICATION_TYPE>::type Constants::to_underlying_type(const NOTIFICATION_TYPE& notificationType) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<NOTIFICATION_TYPE>::type>(notificationType);
		}

		std::string Constants::to_string(const TLS_VERSION& version) TITANIUM_NOEXCEPT
		{
			static std::string unknown_string = "1_0";
			static std::unordered_map<TLS_VERSION, std::string> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[TLS_VERSION::_1_0] = "1_0";
				map[TLS_VERSION::_1_1]  = "1_1";
				map[TLS_VERSION::_1_2]  = "1_2";
			});

			std::string string = unknown_string;
			const auto position = map.find(version);
			if (position != map.end()) {
				string = position->second;
			}

			return string;
		}

		TLS_VERSION Constants::to_TLS_VERSION(const std::string& versionName) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::string, TLS_VERSION> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map["1_0"]  = TLS_VERSION::_1_0;
				map["1_1"] 	= TLS_VERSION::_1_1;
				map["1_2"]  = TLS_VERSION::_1_2;
			});

			TLS_VERSION version = TLS_VERSION::_1_0;
			const auto position = map.find(versionName);
			if (position != map.end()) {
				version = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_TLS_VERSION: Titanium::Network::TLS_VERSION with name '", versionName, "' does not exist");
			}

			return version;
		}

		TLS_VERSION Constants::to_TLS_VERSION(std::underlying_type<TLS_VERSION>::type version_underlying_type) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::underlying_type<TLS_VERSION>::type, TLS_VERSION> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[static_cast<std::underlying_type<TLS_VERSION>::type>(TLS_VERSION::_1_0)] = TLS_VERSION::_1_0;
				map[static_cast<std::underlying_type<TLS_VERSION>::type>(TLS_VERSION::_1_1)] = TLS_VERSION::_1_1;
				map[static_cast<std::underlying_type<TLS_VERSION>::type>(TLS_VERSION::_1_2)] = TLS_VERSION::_1_2;
			});

			TLS_VERSION version = TLS_VERSION::_1_0;
			const auto position = map.find(version_underlying_type);
			if (position != map.end()) {
				version = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_TLS_VERSION: Titanium::Network::TLS_VERSION with value '", version_underlying_type, "' does not exist");
			}

			return version;
		}

		std::underlying_type<TLS_VERSION>::type Constants::to_underlying_type(const TLS_VERSION& version) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<TLS_VERSION>::type>(version);
		}

		std::string Constants::to_string(const MODE& mode) TITANIUM_NOEXCEPT
		{
			static std::string unknown_string = "READ";
			static std::unordered_map<MODE, std::string> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[MODE::READ]        = "READ";
				map[MODE::WRITE]       = "WRITE";
				map[MODE::READ_WRITE]  = "READ_WRITE";
			});

			std::string string = unknown_string;
			const auto position = map.find(mode);
			if (position != map.end()) {
				string = position->second;
			}

			return string;
		}

		MODE Constants::to_MODE(const std::string& modeName) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::string, MODE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map["1_0"]  = MODE::READ;
				map["1_1"] 	= MODE::WRITE;
				map["1_2"]  = MODE::READ_WRITE;
			});

			MODE mode = MODE::READ;
			const auto position = map.find(modeName);
			if (position != map.end()) {
				mode = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_MODE: Titanium::Network::MODE with name '", modeName, "' does not exist");
			}

			return mode;
		}

		MODE Constants::to_MODE(std::underlying_type<MODE>::type mode_underlying_type) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::underlying_type<MODE>::type, MODE> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[static_cast<std::underlying_type<MODE>::type>(MODE::READ)] = MODE::READ;
				map[static_cast<std::underlying_type<MODE>::type>(MODE::WRITE)] = MODE::WRITE;
				map[static_cast<std::underlying_type<MODE>::type>(MODE::READ_WRITE)] = MODE::READ_WRITE;
			});

			MODE mode = MODE::READ;
			const auto position = map.find(mode_underlying_type);
			if (position != map.end()) {
				mode = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_MODE: Titanium::Network::MODE with value '", mode_underlying_type, "' does not exist");
			}

			return mode;
		}

		std::underlying_type<MODE>::type Constants::to_underlying_type(const MODE& mode) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<MODE>::type>(mode);
		}

		std::string Constants::to_string(const SOCKET& socket) TITANIUM_NOEXCEPT
		{
			static std::string unknown_string = "ERROR";
			static std::unordered_map<SOCKET, std::string> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[SOCKET::INITIALIZED] = "INITIALIZED";
				map[SOCKET::CONNECTED]   = "CONNECTED";
				map[SOCKET::LISTENING]   = "LISTENING";
				map[SOCKET::CLOSED]      = "CLOSED";
				map[SOCKET::ERROR]       = "ERROR";
			});

			std::string string = unknown_string;
			const auto position = map.find(socket);
			if (position != map.end()) {
				string = position->second;
			}

			return string;
		}

		SOCKET Constants::to_SOCKET(const std::string& socketName) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::string, SOCKET> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map["INITIALIZED"] = SOCKET::INITIALIZED;
				map["CONNECTED"]   = SOCKET::CONNECTED;
				map["LISTENING"]   = SOCKET::LISTENING;
				map["CLOSED"]      = SOCKET::CLOSED;
				map["ERROR"]       = SOCKET::ERROR;
			});

			SOCKET socket = SOCKET::INITIALIZED;
			const auto position = map.find(socketName);
			if (position != map.end()) {
				socket = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_SOCKET: Titanium::Network::SOCKET with name '", socketName, "' does not exist");
			}

			return socket;
		}

		SOCKET Constants::to_SOCKET(std::underlying_type<SOCKET>::type socket_underlying_type) TITANIUM_NOEXCEPT
		{
			static std::unordered_map<std::underlying_type<SOCKET>::type, SOCKET> map;
			static std::once_flag of;
			std::call_once(of, []() {
				map[static_cast<std::underlying_type<SOCKET>::type>(SOCKET::INITIALIZED)] = SOCKET::INITIALIZED;
				map[static_cast<std::underlying_type<SOCKET>::type>(SOCKET::CONNECTED)] = SOCKET::CONNECTED;
				map[static_cast<std::underlying_type<SOCKET>::type>(SOCKET::LISTENING)] = SOCKET::LISTENING;
				map[static_cast<std::underlying_type<SOCKET>::type>(SOCKET::CLOSED)] = SOCKET::CLOSED;
				map[static_cast<std::underlying_type<SOCKET>::type>(SOCKET::ERROR)] = SOCKET::ERROR;
			});

			SOCKET socket = SOCKET::ERROR;
			const auto position = map.find(socket_underlying_type);
			if (position != map.end()) {
				socket = position->second;
			} else {
				TITANIUM_LOG_WARN("Constants::to_SOCKET: Titanium::Network::SOCKET with value '", socket_underlying_type, "' does not exist");
			}

			return socket;
		}

		std::underlying_type<SOCKET>::type Constants::to_underlying_type(const SOCKET& socket) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<SOCKET>::type>(socket);
		}

	} // namespace Network
}  // namespace Titanium
