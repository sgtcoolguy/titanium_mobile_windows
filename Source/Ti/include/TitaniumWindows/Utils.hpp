/**
 * Titanium.Utils for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UTILS_HPP_
#define _TITANIUMWINDOWS_UTILS_HPP_

#include "Titanium/Utils.hpp"
#include "TitaniumWindows_Ti_EXPORT.h"

using namespace Windows::Security::Cryptography;
using namespace Windows::Security::Cryptography::Core;
using namespace Windows::Storage::Streams;

namespace TitaniumWindows
{
	using namespace HAL;

	using Blob_shared_ptr_t = std::shared_ptr<Titanium::Blob>;

	/*!
	  @class Utils
	  @ingroup Titanium.Utils

	  @discussion This is the Titanium.Utils implementation for Windows.
	*/
	class TITANIUMWINDOWS_TI_EXPORT Utils final : public Titanium::Utils, public JSExport<Utils>
	{

	public:
		Utils(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~Utils()                  = default;
		Utils(const Utils&)            = default;
		Utils& operator=(const Utils&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Utils(Utils&&)                 = default;
		Utils& operator=(Utils&&)      = default;
#endif

		static void JSExportInitialize();

	private:
		virtual std::string generateHash(::Platform::String^ hashName, std::vector<std::uint8_t> data);

		virtual std::string md5HexDigest(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string md5HexDigest(const std::string& obj) TITANIUM_NOEXCEPT;
		virtual std::string sha1(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string sha1(const std::string& obj) TITANIUM_NOEXCEPT;
		virtual std::string sha256(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT;
		virtual std::string sha256(const std::string& obj) TITANIUM_NOEXCEPT;

	};
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_UTILS_HPP_