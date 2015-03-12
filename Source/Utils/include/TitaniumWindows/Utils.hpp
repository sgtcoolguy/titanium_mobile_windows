/**
 * Titanium.Utils for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UTILS_HPP_
#define _TITANIUMWINDOWS_UTILS_HPP_

#include "TitaniumWindows/detail/UtilsBase.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
		@class

		@discussion This is the Titanium.UtilsModule implementation for Windows.
	*/
	class TITANIUMWINDOWS_UTILS_EXPORT UtilsModule final : public Titanium::UtilsModule, public JSExport<UtilsModule>
	{

	public:
		UtilsModule(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~UtilsModule()                  = default;
		UtilsModule(const UtilsModule&)            = default;
		UtilsModule& operator=(const UtilsModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		UtilsModule(UtilsModule&&)                 = default;
		UtilsModule& operator=(UtilsModule&&)      = default;
#endif

		static void JSExportInitialize();

	private:

		virtual JSValue base64decode(JSValue obj) TITANIUM_NOEXCEPT;
		virtual JSValue base64encode(JSValue obj) TITANIUM_NOEXCEPT;
		virtual std::string md5HexDigest(JSValue obj) TITANIUM_NOEXCEPT;
		virtual std::string sha1(JSValue obj) TITANIUM_NOEXCEPT;
		virtual std::string sha256(JSValue obj) TITANIUM_NOEXCEPT;

	};
}  // namespace TitaniumWindows
#endif // _TITANIUMWINDOWS_UTILS_HPP_