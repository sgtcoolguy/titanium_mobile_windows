/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/NetworkModule.hpp"

namespace Titanium
{
	NetworkModule::NetworkModule(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Module(js_context),
		network_lan__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TYPE::LAN))),
		network_mobile__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TYPE::MOBILE))),
		network_none__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TYPE::NONE))),
		network_unknown__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TYPE::UNKNOWN))),
		network_wifi__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TYPE::WIFI))),
		notification_type_alert__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::NOTIFICATION_TYPE::ALERT))),
		notification_type_badge__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::NOTIFICATION_TYPE::BADGE))),
		notification_type_newsstand__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::NOTIFICATION_TYPE::NEWSSTAND))),
		notification_type_sound__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::NOTIFICATION_TYPE::SOUND))),
		progress_unknown__(js_context.CreateNumber(Titanium::Network::Constants::PROGRESS_UNKNOWN)),
		tls_version_1_0__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TLS_VERSION::ONE_ZERO))),
		tls_version_1_1__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TLS_VERSION::ONE_ONE))),
		tls_version_1_2__(js_context.CreateNumber(Titanium::Network::Constants::to_underlying_type(Titanium::Network::TLS_VERSION::ONE_TWO)))
	{
	}

	Titanium::Network::TYPE NetworkModule::get_networkType() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("NetworkModule::get_networkType: Unimplemented");
		return Titanium::Network::TYPE::UNKNOWN;
	}

	std::string NetworkModule::get_networkTypeName() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("NetworkModule::get_networkTypeName: Unimplemented");
		return Titanium::Network::Constants::to_string(get_networkType());
	}

	bool NetworkModule::get_online() const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("NetworkModule::get_online: Unimplemented");
		return false;
	}

	JSObject NetworkModule::createHTTPClient(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Network::createHTTPClient: ");

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Network_property = Titanium.GetProperty("Network");
		TITANIUM_ASSERT(Network_property.IsObject());  // precondition
		JSObject Network = static_cast<JSObject>(Network_property);

		JSValue HTTPClient_property = Network.GetProperty("HTTPClient");
		TITANIUM_ASSERT(HTTPClient_property.IsObject());  // precondition
		JSObject HTTPClient = static_cast<JSObject>(HTTPClient_property);

		auto httpClient = HTTPClient.CallAsConstructor();
		applyProperties(parameters, httpClient);
		return httpClient;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NETWORK_LAN)
	{
		return network_lan__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NETWORK_MOBILE)
	{
		return network_mobile__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NETWORK_NONE)
	{
		return network_none__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NETWORK_UNKNOWN)
	{
		return network_none__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NETWORK_WIFI)
	{
		return network_wifi__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NOTIFICATION_TYPE_ALERT)
	{
		return notification_type_alert__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NOTIFICATION_TYPE_BADGE)
	{
		return notification_type_badge__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NOTIFICATION_TYPE_NEWSSTAND)
	{
		return notification_type_newsstand__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, NOTIFICATION_TYPE_SOUND)
	{
		return notification_type_sound__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, PROGRESS_UNKNOWN)
	{
		return progress_unknown__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, TLS_VERSION_1_0)
	{
		return tls_version_1_0__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, TLS_VERSION_1_1)
	{
		return tls_version_1_1__;
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, TLS_VERSION_1_2)
	{
		return tls_version_1_2__;
	}

	void NetworkModule::JSExportInitialize()
	{
		JSExport<NetworkModule>::SetClassVersion(1);
		JSExport<NetworkModule>::SetParent(JSExport<Module>::Class());
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NETWORK_LAN);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NETWORK_MOBILE);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NETWORK_NONE);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NETWORK_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NETWORK_WIFI);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NOTIFICATION_TYPE_ALERT);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NOTIFICATION_TYPE_BADGE);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NOTIFICATION_TYPE_NEWSSTAND);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, NOTIFICATION_TYPE_SOUND);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, PROGRESS_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, TLS_VERSION_1_0);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, TLS_VERSION_1_1);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, TLS_VERSION_1_2);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, networkType);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, networkTypeName);
		TITANIUM_ADD_PROPERTY_READONLY(NetworkModule, online);
		TITANIUM_ADD_FUNCTION(NetworkModule, createHTTPClient);
	}

	TITANIUM_FUNCTION(NetworkModule, createHTTPClient)
	{
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);
		return createHTTPClient(parameters, this_object);
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, networkType)
	{
		return get_context().CreateNumber(Titanium::Network::Constants::to_underlying_type(get_networkType()));
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, networkTypeName)
	{
		return get_context().CreateString(get_networkTypeName());
	}

	TITANIUM_PROPERTY_GETTER(NetworkModule, online)
	{
		return get_context().CreateBoolean(get_online());
	}
}
