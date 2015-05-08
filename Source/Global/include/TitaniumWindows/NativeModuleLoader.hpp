/**
 * NativeModuleLoader for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_NATIVE_MODULE_LOADER_HPP_
#define _TITANIUMWINDOWS_NATIVE_MODULE_LOADER_HPP_

#include "TitaniumWindows/detail/GlobalBase.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class

	  @discussion This is the callback mechanism to laod up a native type using require!
	*/
	class TITANIUMWINDOWS_GLOBAL_EXPORT NativeModuleLoader final
	{
	public:

		NativeModuleLoader() TITANIUM_NOEXCEPT;

		virtual bool registerNativeModule(const JSObject& parent, const std::string& path) const = 0;
	};

}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_NATIVE_MODULE_LOADER_HPP_
