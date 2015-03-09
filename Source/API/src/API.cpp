/**
* Titanium.API for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/
#define _SCL_SECURE_NO_WARNINGS

#include "TitaniumWindows/API.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <ppltasks.h>
#include <agents.h>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

namespace TitaniumWindows {

	concurrency::unbounded_buffer <std::string> API::buffer__;
	bool API::done__ { false };

	void file_reader::run() {

		// TODO Read in the settings, try to connect to the host/port/etc
		using namespace Windows::Storage;
		using namespace concurrency;

		// clang-format off

		// clang-format on
		// Parse the ini, try to connect using settings found in INI
		Windows::Storage::Streams::DataWriter^ writer = nullptr;
		try {
			// Get a handle on titanium_settings.ini file
			Platform::String^ content;
			concurrency::event read_event;
			create_task(Windows::ApplicationModel::Package::Current->InstalledLocation->GetFileAsync("titanium_settings.ini"))
				.then([](task<StorageFile^> task) {
				return FileIO::ReadTextAsync(task.get());
			}).then([&content, &read_event](task<Platform::String^> task) {
				try {
					content = task.get();
				} catch (...) { }
				read_event.set();
			}, concurrency::task_continuation_context::use_arbitrary());
			read_event.wait();

			std::stringstream ss(TitaniumWindows::Utility::ConvertString(content)); // put string into stream

			// Parse stream with INI parser
			boost::property_tree::ptree pt;
			boost::property_tree::ini_parser::read_ini(ss, pt);

			// Now pull out the ips/secret/port from the map
			auto port = TitaniumWindows::Utility::ConvertString(pt.get<std::string>("tcpPort"));
			Platform::String^ server_token = TitaniumWindows::Utility::ConvertString(pt.get<std::string>("serverToken"));

			std::vector<std::string> hosts;
			std::string ip_address_list = pt.get<std::string>("ipAddressList");
			boost::algorithm::split(hosts, ip_address_list, boost::algorithm::is_any_of(","));
			auto tcp_socket = ref new Windows::Networking::Sockets::StreamSocket();
			for (auto ip_address : hosts) {
				try {
					// Connect to the tcp socket on log relay!
					// TODO Set timeout based on value from ini! We need to use a cancellation token somehow!
					auto host = ref new Windows::Networking::HostName(TitaniumWindows::Utility::ConvertString(ip_address));

					concurrency::event connect_event;
					create_task(tcp_socket->ConnectAsync(host, port))
						.then([&writer, tcp_socket, &connect_event](task<void> connectTask) {
						try {
							connectTask.get();
							writer = ref new Windows::Storage::Streams::DataWriter(tcp_socket->OutputStream);
						} catch (...) { }
						connect_event.set();
					}, concurrency::task_continuation_context::use_arbitrary());
					connect_event.wait();

					// we write the server token to see if this log relay is really the log relay we're looking for
					if (writer != nullptr) {
						writer->WriteString(server_token + "\n");  // Logger assumes \n for newlines!
						writer->StoreAsync();
						break;
					}
				} catch (...) {
					// try next ip!
					TITANIUM_LOG_DEBUG("API::connect: Trying to connect failed, trying next IP...");
				}
			}
		} catch (...) {
			TITANIUM_LOG_DEBUG("API::connect: will use console log...");
		}

		try {
			std::string message;
			while (!API::done__) {
				message = concurrency::receive(API::buffer__);
				if (writer == nullptr) {
					std::clog << message << std::endl;
				} else {
					writer->WriteString(TitaniumWindows::Utility::ConvertString(message) + "\n");  // Logger assumes \n for newlines!
					writer->StoreAsync();
				}
			}
		} catch (...) {
			TITANIUM_LOG_ERROR("API::connect: Error");
		}
		done();
	}

	API::API(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::API(js_context) {
		TITANIUM_LOG_DEBUG("TitaniumWindows::API::ctor Initialize");
	}

	API::~API() TITANIUM_NOEXCEPT
	{
		done__ = true;
	}

	void API::log(const std::string& message) const TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::API::log");
		concurrency::asend(buffer__, message);
	}

	void API::JSExportInitialize() {
		JSExport<API>::SetClassVersion(1);
		JSExport<API>::SetParent(JSExport<Titanium::API>::Class());
	}

	void API::postInitialize(JSObject& this_object) 
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::API::postInitialize");
		connect();
	}

	void API::connect() {
		done__ = false;
		reader__.start();
	}
}  // namespace TitaniumWindows
