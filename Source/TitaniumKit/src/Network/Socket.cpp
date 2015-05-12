/**
 * TitaniumKit Titanium.Network.Socket
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Network/Socket.hpp"

namespace Titanium
{
	namespace Network
	{


		SocketModule::SocketModule(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context)
			, initialized__(js_context.CreateNumber(static_cast<std::uint32_t>(Socket::State::Initialized)))
			, connected__(js_context.CreateNumber(static_cast<std::uint32_t>(Socket::State::Connected)))
			, listening__(js_context.CreateNumber(static_cast<std::uint32_t>(Socket::State::Listening)))
			, closed__(js_context.CreateNumber(static_cast<std::uint32_t>(Socket::State::Closed)))
			, error__(js_context.CreateNumber(static_cast<std::uint32_t>(Socket::State::Error)))
		{
		}

		void SocketModule::JSExportInitialize() 
		{
			JSExport<SocketModule>::SetClassVersion(1);
			JSExport<SocketModule>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY_READONLY(SocketModule, INITIALIZED);
			TITANIUM_ADD_PROPERTY_READONLY(SocketModule, CONNECTED);
			TITANIUM_ADD_PROPERTY_READONLY(SocketModule, LISTENING);
			TITANIUM_ADD_PROPERTY_READONLY(SocketModule, CLOSED);
			TITANIUM_ADD_PROPERTY_READONLY(SocketModule, ERROR);

			TITANIUM_ADD_FUNCTION(SocketModule, createTCP);
			TITANIUM_ADD_FUNCTION(SocketModule, createUDP);
		}

		TITANIUM_PROPERTY_GETTER(SocketModule, INITIALIZED)
		{
			return initialized__;
		}

		TITANIUM_PROPERTY_GETTER(SocketModule, CONNECTED)
		{
			return connected__;
		}

		TITANIUM_PROPERTY_GETTER(SocketModule, LISTENING)
		{
			return listening__;
		}

		TITANIUM_PROPERTY_GETTER(SocketModule, CLOSED)
		{
			return closed__;
		}

		TITANIUM_PROPERTY_GETTER(SocketModule, ERROR)
		{
			return error__;
		}

		TITANIUM_FUNCTION(SocketModule, createTCP)
		{
			TITANIUM_LOG_DEBUG("SocketModule::createTCP: ");

			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);

			JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
			TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
			JSObject Titanium = static_cast<JSObject>(Titanium_property);

			JSValue Network_property = Titanium.GetProperty("Network");
			TITANIUM_ASSERT(Network_property.IsObject());  // precondition
			JSObject Network = static_cast<JSObject>(Network_property);

			JSValue Socket_property = Network.GetProperty("Socket");
			TITANIUM_ASSERT(Socket_property.IsObject());  // precondition
			JSObject Socket = static_cast<JSObject>(Socket_property);

			JSValue TCP_property = Socket.GetProperty("TCP");
			TITANIUM_ASSERT(TCP_property.IsObject());  // precondition
			JSObject TCP = static_cast<JSObject>(TCP_property);

			auto tcp = TCP.CallAsConstructor();
			applyProperties(parameters, tcp);
			return tcp;
		}

		TITANIUM_FUNCTION(SocketModule, createUDP)
		{
			TITANIUM_LOG_DEBUG("SocketModule::createUDP: ");
			
			ENSURE_OPTIONAL_OBJECT_AT_INDEX(parameters, 0);

			JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
			TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
			JSObject Titanium = static_cast<JSObject>(Titanium_property);

			JSValue Network_property = Titanium.GetProperty("Network");
			TITANIUM_ASSERT(Network_property.IsObject());  // precondition
			JSObject Network = static_cast<JSObject>(Network_property);

			JSValue Socket_property = Network.GetProperty("Socket");
			TITANIUM_ASSERT(Socket_property.IsObject());  // precondition
			JSObject Socket = static_cast<JSObject>(Socket_property);

			JSValue UDP_property = Socket.GetProperty("UDP");
			TITANIUM_ASSERT(UDP_property.IsObject());  // precondition
			JSObject UDP = static_cast<JSObject>(UDP_property);

			auto udp = UDP.CallAsConstructor();
			applyProperties(parameters, udp);
			return udp;
		}

	} // namespace Network
} // namespace Titanium