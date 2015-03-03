/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/NetworkModule.hpp"

namespace Titanium
{
	static void applyProperties(JSObject& obj, const JSObject& parameters)
	{
		if (parameters.GetPropertyNames().GetCount() > 0) {
			const auto propertyNames = parameters.GetPropertyNames();
			for (const auto& property_name : static_cast<std::vector<JSString>>(propertyNames)) {
				obj.SetProperty(property_name, parameters.GetProperty(property_name));
			}
		}
	}

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
		Titanium::applyProperties(httpClient, parameters);
		return httpClient;
	}

	JSValue NetworkModule::NETWORK_LAN() const TITANIUM_NOEXCEPT
	{
		return network_lan__;
	}

	JSValue NetworkModule::NETWORK_MOBILE() const TITANIUM_NOEXCEPT
	{
		return network_mobile__;
	}

	JSValue NetworkModule::NETWORK_NONE() const TITANIUM_NOEXCEPT
	{
		return network_none__;
	}

	JSValue NetworkModule::NETWORK_UNKNOWN() const TITANIUM_NOEXCEPT
	{
		return network_none__;
	}

	JSValue NetworkModule::NETWORK_WIFI() const TITANIUM_NOEXCEPT
	{
		return network_wifi__;
	}

	JSValue NetworkModule::NOTIFICATION_TYPE_ALERT() const TITANIUM_NOEXCEPT
	{
		return notification_type_alert__;
	}

	JSValue NetworkModule::NOTIFICATION_TYPE_BADGE() const TITANIUM_NOEXCEPT
	{
		return notification_type_badge__;
	}

	JSValue NetworkModule::NOTIFICATION_TYPE_NEWSSTAND() const TITANIUM_NOEXCEPT
	{
		return notification_type_newsstand__;
	}

	JSValue NetworkModule::NOTIFICATION_TYPE_SOUND() const TITANIUM_NOEXCEPT
	{
		return notification_type_sound__;
	}

	JSValue NetworkModule::PROGRESS_UNKNOWN() const TITANIUM_NOEXCEPT
	{
		return progress_unknown__;
	}

	JSValue NetworkModule::TLS_VERSION_1_0() const TITANIUM_NOEXCEPT
	{
		return tls_version_1_0__;
	}

	JSValue NetworkModule::TLS_VERSION_1_1() const TITANIUM_NOEXCEPT
	{
		return tls_version_1_1__;
	}

	JSValue NetworkModule::TLS_VERSION_1_2() const TITANIUM_NOEXCEPT
	{
		return tls_version_1_2__;
	}

	void NetworkModule::JSExportInitialize()
	{
		JSExport<NetworkModule>::SetClassVersion(1);
		JSExport<NetworkModule>::SetParent(JSExport<Module>::Class());
		JSExport<NetworkModule>::AddValueProperty("NETWORK_LAN", std::mem_fn(&NetworkModule::NETWORK_LAN));
		JSExport<NetworkModule>::AddValueProperty("NETWORK_MOBILE", std::mem_fn(&NetworkModule::NETWORK_MOBILE));
		JSExport<NetworkModule>::AddValueProperty("NETWORK_NONE", std::mem_fn(&NetworkModule::NETWORK_NONE));
		JSExport<NetworkModule>::AddValueProperty("NETWORK_UNKNOWN", std::mem_fn(&NetworkModule::NETWORK_UNKNOWN));
		JSExport<NetworkModule>::AddValueProperty("NETWORK_WIFI", std::mem_fn(&NetworkModule::NETWORK_WIFI));
		JSExport<NetworkModule>::AddValueProperty("NOTIFICATION_TYPE_ALERT", std::mem_fn(&NetworkModule::NOTIFICATION_TYPE_ALERT));
		JSExport<NetworkModule>::AddValueProperty("NOTIFICATION_TYPE_BADGE", std::mem_fn(&NetworkModule::NOTIFICATION_TYPE_BADGE));
		JSExport<NetworkModule>::AddValueProperty("NOTIFICATION_TYPE_NEWSSTAND", std::mem_fn(&NetworkModule::NOTIFICATION_TYPE_NEWSSTAND));
		JSExport<NetworkModule>::AddValueProperty("NOTIFICATION_TYPE_SOUND", std::mem_fn(&NetworkModule::NOTIFICATION_TYPE_SOUND));
		JSExport<NetworkModule>::AddValueProperty("PROGRESS_UNKNOWN", std::mem_fn(&NetworkModule::PROGRESS_UNKNOWN));
		JSExport<NetworkModule>::AddValueProperty("TLS_VERSION_1_0", std::mem_fn(&NetworkModule::TLS_VERSION_1_0));
		JSExport<NetworkModule>::AddValueProperty("TLS_VERSION_1_1", std::mem_fn(&NetworkModule::TLS_VERSION_1_1));
		JSExport<NetworkModule>::AddValueProperty("TLS_VERSION_1_2", std::mem_fn(&NetworkModule::TLS_VERSION_1_2));
		JSExport<NetworkModule>::AddValueProperty("networkType", std::mem_fn(&NetworkModule::js_get_networkType));
		JSExport<NetworkModule>::AddValueProperty("networkTypeName", std::mem_fn(&NetworkModule::js_get_networkTypeName));
		JSExport<NetworkModule>::AddValueProperty("online", std::mem_fn(&NetworkModule::js_get_online));

		JSExport<NetworkModule>::AddFunctionProperty("createHTTPClient", std::mem_fn(&NetworkModule::js_createHTTPClient));
	}

	JSObject NetworkModule::js_createHTTPClient(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = get_context().CreateObject();
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue network_property = Titanium.GetProperty("Network");
		TITANIUM_ASSERT(network_property.IsObject());  // precondition

		return createHTTPClient(parameters, this_object);
	}

	JSValue NetworkModule::js_get_networkType() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Network::Constants::to_underlying_type(get_networkType()));
	}

	JSValue NetworkModule::js_get_networkTypeName() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateString(get_networkTypeName());
	}

	JSValue NetworkModule::js_get_online() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateBoolean(get_online());
	}
}
