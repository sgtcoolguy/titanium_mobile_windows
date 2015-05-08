/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_
#define _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_

#include "TitaniumWindows/NativeModuleLoader.hpp"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>

// FIXME This will only work if we generate _all_ type wrappers and include them here. Otherwise we need to move this into the user's app and limit to those types used...

namespace TitaniumWindows
{
	using namespace HAL;

	bool WindowsNativeModuleLoader::registerNativeModule(const JSObject& parent, const std::string& path) const
	{
		auto context = parent.get_context();
		auto global = context.get_global_object();

		// TODO Instantiate the type! Do we need some huge if/else block to test string for types, generated from list of all possible types?
		JSObject instantiated;
		if (path == 'Windows.UI.Xaml.Controls.Page') {
			instantiated = js_context.CreateObject(JSExport<Titanium::Windows::UI::Xaml::Controls::Page>::Class());
		}
		if (instantiated == nullptr) {
			return false;
		}

		// Split type/path by '.', then build up the namespaces!
		JSObject current_object = global;
		#pragma warning(push)
#pragma warning(disable:4996)
			std::vector<std::string> parts;
			boost::split(parts, path, boost::is_any_of("."));
#pragma warning(pop)
		for (size_t i = 0, len = parts.size(); i < len - 1; i++) {
			auto name = parts.at(i);

			if (!current_object.HasProperty(name)) {
				auto child_object = context.CreateObject();
				current_object.SetProperty(name, child_object);
				current_object = child_object;
			} else {
				auto current_value = current_object.GetProperty(name);
				TITANIUM_ASSERT(current_value.IsObject());
				current_object = static_cast<JSObject>(current_value);
			}
		}
		current_object.SetProperty("base_name", instantiated);

		return true;
	}
}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_WindowsNativeModuleLoader_HPP_
