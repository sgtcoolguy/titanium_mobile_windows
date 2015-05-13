/**
 * NativeModuleLoader for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/detail/GlobalBase.hpp"
#include "TitaniumWindows/NativeModuleLoader.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	NativeModuleLoader::NativeModuleLoader()
	{

	}

	bool NativeModuleLoader::registerNativeModule(const JSObject& parent, const std::string& path) const
	{
		return false;
	}

}  // namespace TitaniumWindows

