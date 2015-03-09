/**
* Titanium.API for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_API_HPP_
#define _TITANIUMWINDOWS_API_HPP_

#include "TitaniumWindows/detail/APIBase.hpp"
#include <agents.h>

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  This is an agent that is meant to connect over TCP to the CLi and forward logs over the socket. If unable to make a connection,
	  or not running under CLI we will forward logs to std::clog.
	*/
	class log_forwarder : public concurrency::agent
	{
	public:
		explicit log_forwarder() {}

		// Retrieves any error that occurs during the life of the agent.
		bool get_error(std::exception& e)
		{
			return try_receive(_error, e);
		}

	protected:
		void run();

	private:
		concurrency::overwrite_buffer<std::exception> _error;
	};

	/*!
	  @class

	  @discussion This is the Titanium.API implementation for Windows.
	*/
	class TITANIUMWINDOWS_API_EXPORT API final : public Titanium::API, public JSExport<API>
	{
	public:
		static bool done__;
#pragma warning(push)
#pragma warning(disable : 4251)
		static concurrency::unbounded_buffer<std::string> buffer__; // Buffer used to store log messages that we haven't written yet
		log_forwarder reader__; // agent/thread that writes the actual log messages to CLI/debug
#pragma warning(pop)

		virtual void postInitialize(JSObject& js_object) override;

		API(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~API() TITANIUM_NOEXCEPT;
		API(const API&) = default;
		API& operator=(const API&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		API(API&&) = default;
		API& operator=(API&&) = default;
#endif

		static void JSExportInitialize();

	protected:
		virtual void log(const std::string& message) const TITANIUM_NOEXCEPT override final;

	private:
		void connect();
	};
}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_API_HPP_
