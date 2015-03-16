/**
 * TitaniumKit Titanium.Utils
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UTILS_HPP_
#define _TITANIUM_UTILS_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Blob.hpp"
#include "Titanium/Filesystem/File.hpp"

namespace Titanium
{
	using namespace HAL;

	using Blob_shared_ptr_t = std::shared_ptr<Blob>;
	using File_shared_ptr_t = std::shared_ptr<Filesystem::File>;

	/*!
	  @class
	  @discussion This is the Titanium Utils Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Utils
	*/
	class TITANIUMKIT_EXPORT Utils : public Module, public JSExport<Utils>
	{

	public:

		/*!
		  @method
		  @abstract base64decode
		  @discussion Returns the specified data decoded from Base64.
		*/
		virtual Blob_shared_ptr_t base64decode(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual Blob_shared_ptr_t base64decode(std::string& obj) TITANIUM_NOEXCEPT;
		virtual Blob_shared_ptr_t base64decode(File_shared_ptr_t obj) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract base64encode
		  @discussion Returns the specified data encoded to Base64.
		*/
		virtual Blob_shared_ptr_t base64encode(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual Blob_shared_ptr_t base64encode(std::string& obj) TITANIUM_NOEXCEPT;
		virtual Blob_shared_ptr_t base64encode(File_shared_ptr_t obj) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract md5HexDigest
		  @discussion Returns a MD5 digest of the specified data as a hex-based String.
		*/
		virtual std::string md5HexDigest(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string md5HexDigest(std::string& obj) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract sha1
		  @discussion Returns a SHA-1 hash of the specified data as a hex-based String.
		*/
		virtual std::string sha1(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string sha1(std::string& obj) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract sha256
		  @discussion Returns a SHA-256 hash of the specified data as a hex-based String.
		*/
		virtual std::string sha256(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string sha256(std::string& obj) TITANIUM_NOEXCEPT;

		Utils(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~Utils() = default;
		Utils(const Utils&) = default;
		Utils& operator=(const Utils&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Utils(Utils&&)                 = default;
		Utils& operator=(Utils&&)      = default;
#endif

		static void JSExportInitialize();

		virtual JSValue js_base64decode(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_base64encode(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_md5HexDigest(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_sha1(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_sha256(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

		protected:
	};
} // namespace Titanium
#endif // _TITANIUM_UTILS_HPP_