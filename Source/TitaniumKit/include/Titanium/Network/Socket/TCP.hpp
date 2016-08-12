/**
 * TitaniumKit Titanium.Network.Socket.TCP
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TCP_HPP_
#define _TITANIUM_TCP_HPP_

#include "Titanium/Network/Socket.hpp"
#include "Titanium/IOStream.hpp"

namespace Titanium
{
	namespace Network
	{
		namespace Socket
		{

			using namespace HAL;

			struct AcceptDict;

			/*!
			  @class
			  @discussion This is the Titanium TCP Module.
			  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Network.Socket.TCP
			*/
			class TITANIUMKIT_EXPORT TCP : public IOStream, public JSExport<TCP>
			{

			public:

				/*!
				  @property
				  @abstract host
				  @discussion The host to connect to or listen on.
				*/
				TITANIUM_PROPERTY_IMPL_DEF(std::string, host);

				/*!
				  @property
				  @abstract port
				  @discussion The port to connect to or listen on.
				*/
				TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, port);

				/*!
				  @property
				  @abstract listenQueueSize
				  @discussion Max number of pending incoming connections to be allowed when the socket is in the [LISTENING](Titanium.Network.Socket.LISTENING) state.
				*/
				TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, listenQueueSize);

				/*!
				  @property
				  @abstract timeout
				  @discussion Timeout, in milliseconds, for `connect` and all `write` operations.
				*/
				TITANIUM_PROPERTY_IMPL_DEF(std::chrono::milliseconds, timeout);

				/*!
				  @property
				  @abstract state
				  @discussion Current state of the socket.
				*/
				TITANIUM_PROPERTY_IMPL_READONLY_DEF(State, state);

				/*!
				  @method
				  @abstract close
				  @discussion Closes a socket.
				*/
				virtual void close() TITANIUM_NOEXCEPT;

				/*!
				  @method
				  @abstract connect
				  @discussion Attempts to connect the socket to its host/port.
				*/
				virtual void connect() TITANIUM_NOEXCEPT;

				/*!
				  @method
				  @abstract listen
				  @discussion Attempts to start listening on the socket's host/port.
				*/
				virtual void listen() TITANIUM_NOEXCEPT;

				/*!
				  @method
				  @abstract accept
				  @discussion Tells a [LISTENING](Titanium.Network.Socket.LISTENING) socket to accept a connection request at the top of a listener's request queue when one becomes available.
				*/
				virtual void accept(const AcceptDict& options) TITANIUM_NOEXCEPT;

				TCP(const JSContext&) TITANIUM_NOEXCEPT;

				virtual ~TCP() = default;
				TCP(const TCP&) = default;
				TCP& operator=(const TCP&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
				TCP(TCP&&)                 = default;
				TCP& operator=(TCP&&)      = default;
	#endif

				static void JSExportInitialize();

				TITANIUM_PROPERTY_DEF(host);
				TITANIUM_PROPERTY_DEF(port);
				TITANIUM_PROPERTY_DEF(listenQueueSize);
				TITANIUM_PROPERTY_DEF(timeout);
				TITANIUM_PROPERTY_DEF(connected);
				TITANIUM_PROPERTY_DEF(error);
				TITANIUM_PROPERTY_DEF(accepted);
				TITANIUM_PROPERTY_READONLY_DEF(state);

				TITANIUM_FUNCTION_DEF(close);
				TITANIUM_FUNCTION_DEF(connect);
				TITANIUM_FUNCTION_DEF(listen);
				TITANIUM_FUNCTION_DEF(accept);
				TITANIUM_FUNCTION_DEF(getHost);
				TITANIUM_FUNCTION_DEF(setHost);
				TITANIUM_FUNCTION_DEF(getPort);
				TITANIUM_FUNCTION_DEF(setPort);
				TITANIUM_FUNCTION_DEF(getListenQueueSize);
				TITANIUM_FUNCTION_DEF(setListenQueueSize);
				TITANIUM_FUNCTION_DEF(getTimeout);
				TITANIUM_FUNCTION_DEF(setTimeout);
				TITANIUM_FUNCTION_DEF(getConnected);
				TITANIUM_FUNCTION_DEF(setConnected);
				TITANIUM_FUNCTION_DEF(getError);
				TITANIUM_FUNCTION_DEF(setError);
				TITANIUM_FUNCTION_DEF(getAccepted);
				TITANIUM_FUNCTION_DEF(setAccepted);
				TITANIUM_FUNCTION_DEF(getState);

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string host__;
				std::uint32_t port__;
				std::uint32_t listenQueueSize__;
				std::chrono::milliseconds timeout__;
				JSValue connected__;
				JSValue error__;
				JSValue accepted__;
				State state__;
#pragma warning(pop)
			};

		} // namespace Socket
	} // namespace Network
} // namespace Titanium
#endif // _TITANIUM_TCP_HPP_