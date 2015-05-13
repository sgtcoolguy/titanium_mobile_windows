/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_
#define _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_

#include "detail/TitaniumWindowsBase.hpp"
#include "TitaniumWindows/NativeModuleLoader.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

		class TITANIUMWINDOWS_EXPORT WindowsNativeModuleLoader final : public ::TitaniumWindows::NativeModuleLoader
		{
		public:
			WindowsNativeModuleLoader();
			~WindowsNativeModuleLoader();

			virtual bool registerNativeModule(const JSObject& parent, const std::string& path) const override final;
		};
}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_
