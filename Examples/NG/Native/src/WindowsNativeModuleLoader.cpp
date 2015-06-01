/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "WindowsNativeModuleLoader.hpp"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
// INSERT_INCLUDES
// END_INCLUDES

// FIXME This will only work if we generate _all_ type wrappers and include them here. Otherwise we need to move this into the user's app and limit to those types used...

namespace TitaniumWindows
{
	using namespace HAL;

	WindowsNativeModuleLoader::WindowsNativeModuleLoader()
	{
	}

	WindowsNativeModuleLoader::~WindowsNativeModuleLoader()
	{
	}

	void WindowsNativeModuleLoader::registerValue(const JSContext& context, const std::string& name, const JSValue& value) const
	{
	
	}

	void WindowsNativeModuleLoader::registerEnums(const JSContext& context, const std::string& type_name) const
	{
		// INSERT_ENUMS
		// END_ENUMS
	}

	JSValue WindowsNativeModuleLoader::registerNativeModule(const JSContext& context, const std::string& path) const
	{
		JSObject instantiated = context.CreateObject();
		// TODO Use a std::map that we populate once and just check for a key with that name?
		// INSERT_SWITCH
		// END_SWITCH

		registerValue(context, path, instantiated);

		return static_cast<JSValue>(instantiated);
	}
}  // namespace TitaniumWindows

