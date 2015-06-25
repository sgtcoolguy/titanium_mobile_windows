/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Picker.hpp"
#include "Titanium/detail/TiImpl.hpp"
#include <type_traits>

namespace Titanium
{
	namespace UI
	{
		Picker::Picker(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      type__(PICKER_TYPE::PLAIN)
		{
		}

		PICKER_TYPE Picker::get_type() const TITANIUM_NOEXCEPT
		{
			return type__;
		}

		void Picker::set_type(const PICKER_TYPE& type) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Picker::set_type: Unimplemented");
		}

		void Picker::JSExportInitialize()
		{
			JSExport<Picker>::SetClassVersion(1);
			JSExport<Picker>::SetParent(JSExport<View>::Class());
			TITANIUM_ADD_PROPERTY(Picker, type);
		}

		TITANIUM_PROPERTY_GETTER(Picker, type)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<PICKER_TYPE>::type>(get_type()));
		}

		TITANIUM_PROPERTY_SETTER(Picker, type)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			type__ = Constants::to_PICKER_TYPE(static_cast<std::underlying_type<PICKER_TYPE>::type>(argument));
			set_type(type__);
			return true;
		}
	} // namespace UI
}  // namespace Titanium
