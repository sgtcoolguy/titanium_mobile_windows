/**
 * TitaniumKit Titanium.Utils
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Utils.hpp"

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/insert_linebreaks.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/archive/iterators/ostream_iterator.hpp>
#include <sstream>
#include <string>

namespace Titanium
{
	Utils::Utils(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
	{
	}

	Blob_shared_ptr_t Utils::base64decode(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		return base64decode(obj->get_text());
	}

	Blob_shared_ptr_t Utils::base64decode(File_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		Blob_shared_ptr_t blob = static_cast<JSObject>(obj->read()).GetPrivate<Blob>();
		return base64decode(blob->get_text());
	}

	Blob_shared_ptr_t Utils::base64decode(const std::string& input) TITANIUM_NOEXCEPT
	{
		using namespace boost::archive::iterators;

		std::stringstream out_stream;
		typedef transform_width<binary_from_base64<std::string::const_iterator>, 8, 6> base64_text;
		std::copy(base64_text(input.begin()), base64_text(input.end()), ostream_iterator<char>(out_stream));
		std::string result = out_stream.str();

		auto blob = get_context().CreateObject(JSExport<Titanium::Blob>::Class()).CallAsConstructor();
		auto blob_ptr = blob.GetPrivate<Titanium::Blob>();
		blob_ptr->construct(std::vector<unsigned char>(result.begin(), result.end()));
		return blob_ptr;
	}

	Blob_shared_ptr_t Utils::base64encode(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		return base64encode(obj->get_text());
	}

	Blob_shared_ptr_t Utils::base64encode(File_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		Blob_shared_ptr_t blob = static_cast<JSObject>(obj->read()).GetPrivate<Blob>();
		return base64encode(blob->get_text());
	}

	Blob_shared_ptr_t Utils::base64encode(const std::string& input) TITANIUM_NOEXCEPT
	{
		using namespace boost::archive::iterators;

		std::stringstream out_stream;
		typedef insert_linebreaks<base64_from_binary<transform_width<std::string::const_iterator, 6, 8>>, 72> base64_text;
		std::copy(base64_text(input.begin()), base64_text(input.end()), ostream_iterator<char>(out_stream));
		std::string result = out_stream.str().append((3-input.size()%3)%3, '=');

		auto blob = get_context().CreateObject(JSExport<Titanium::Blob>::Class()).CallAsConstructor();
		auto blob_ptr = blob.GetPrivate<Titanium::Blob>();
		blob_ptr->construct(std::vector<unsigned char>(result.begin(), result.end()));
		return blob_ptr;
	}

	std::string Utils::md5HexDigest(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::md5HexDigest: Unimplemented");
		return "";
	}

	std::string Utils::md5HexDigest(const std::string& obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::md5HexDigest: Unimplemented");
		return "";
	}

	std::string Utils::sha1(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::sha1: Unimplemented");
		return "";
	}

	std::string Utils::sha1(const std::string& obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::sha1: Unimplemented");
		return "";
	}

	std::string Utils::sha256(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::sha256: Unimplemented");
		return "";
	}

	std::string Utils::sha256(const std::string& obj) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Utils::sha256: Unimplemented");
		return "";
	}

	void Utils::JSExportInitialize() {
		JSExport<Utils>::SetClassVersion(1);
		JSExport<Utils>::SetParent(JSExport<Module>::Class());

		JSExport<Utils>::AddFunctionProperty("base64decode", std::mem_fn(&Utils::js_base64decode));
		JSExport<Utils>::AddFunctionProperty("base64encode", std::mem_fn(&Utils::js_base64encode));
		JSExport<Utils>::AddFunctionProperty("md5HexDigest", std::mem_fn(&Utils::js_md5HexDigest));
		JSExport<Utils>::AddFunctionProperty("sha1", std::mem_fn(&Utils::js_sha1));
		JSExport<Utils>::AddFunctionProperty("sha256", std::mem_fn(&Utils::js_sha256));
	}

	JSValue Utils::js_base64decode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);

			// Titanium.Blob / Titanium.Filesystem.File
			if (_0.IsObject()) {
				const auto js_obj = static_cast<JSObject>(_0);

				// Titanium.Blob
				const auto blob_obj = js_obj.GetPrivate<Blob>();
				if (blob_obj != nullptr) {
					return static_cast<JSValue>(base64decode(blob_obj)->get_object());
				}

				// Titanium.Filesystem.File
				const auto file_obj = js_obj.GetPrivate<Filesystem::File>();
				if (file_obj != nullptr) {
					return static_cast<JSValue>(base64decode(file_obj)->get_object());
				}

			// String
			} else if (_0.IsString()) {
				auto obj = static_cast<std::string>(_0);
				return static_cast<JSValue>(base64decode(obj)->get_object());
			}
		}
		return get_context().CreateUndefined();
	}

	JSValue Utils::js_base64encode(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);

			// Titanium.Blob / Titanium.Filesystem.File
			if (_0.IsObject()) {
				const auto js_obj = static_cast<JSObject>(_0);

				// Titanium.Blob
				const auto blob_obj = js_obj.GetPrivate<Blob>();
				if (blob_obj != nullptr) {
					return static_cast<JSValue>(base64encode(blob_obj)->get_object());
				}

				// Titanium.Filesystem.File
				const auto file_obj = js_obj.GetPrivate<Filesystem::File>();
				if (file_obj != nullptr) {
					return static_cast<JSValue>(base64encode(file_obj)->get_object());
				}

			// String
			} else if (_0.IsString()) {
				auto obj = static_cast<std::string>(_0);
				return static_cast<JSValue>(base64encode(obj)->get_object());
			}
		}
		return get_context().CreateUndefined();
	}

	JSValue Utils::js_md5HexDigest(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);

			// Titanium.Blob
			if (_0.IsObject()) {
				const auto js_obj = static_cast<JSObject>(_0);
				const auto obj = js_obj.GetPrivate<Blob>();
				if (obj != nullptr) {
					return get_context().CreateString(md5HexDigest(obj));
				}

			// String
			} else if (_0.IsString()) {
				auto obj = static_cast<std::string>(_0);
				return get_context().CreateString(md5HexDigest(obj));
			}
		}
		return get_context().CreateUndefined();
	}

	JSValue Utils::js_sha1(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			
			// Titanium.Blob
			if (_0.IsObject()) {
				const auto js_obj = static_cast<JSObject>(_0);
				const auto obj = js_obj.GetPrivate<Blob>();
				if (obj != nullptr) {
					return get_context().CreateString(sha1(obj));
				}

			// String
			} else if (_0.IsString()) {
				auto obj = static_cast<std::string>(_0);
				return get_context().CreateString(sha1(obj));
			}
		}
		return get_context().CreateUndefined();
	}

	JSValue Utils::js_sha256(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			
			// Titanium.Blob
			if (_0.IsObject()) {
				const auto js_obj = static_cast<JSObject>(_0);
				const auto obj = js_obj.GetPrivate<Blob>();
				if (obj != nullptr) {
					return get_context().CreateString(sha256(obj));
				}

			// String
			} else if (_0.IsString()) {
				auto obj = static_cast<std::string>(_0);
				return get_context().CreateString(sha256(obj));
			}
		}
		return get_context().CreateUndefined();
	}
} // namespace Titanium