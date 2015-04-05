/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Slider.hpp"

namespace Titanium
{
	namespace UI
	{
		Slider::Slider(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      max__(js_context.CreateNumber(1)),
		      min__(js_context.CreateNumber(0)),
		      value__(js_context.CreateNumber(0))
		{
		}

		double Slider::get_max() const TITANIUM_NOEXCEPT
		{
			return max__;
		}

		void Slider::set_max(const double& max) TITANIUM_NOEXCEPT
		{
			max__ = max;
		}

		double Slider::get_min() const TITANIUM_NOEXCEPT
		{
			return min__;
		}

		void Slider::set_min(const double& min) TITANIUM_NOEXCEPT
		{
			min__ = min;
		}

		double Slider::get_value() const TITANIUM_NOEXCEPT
		{
			return value__;
		}

		void Slider::set_value(const double& value) TITANIUM_NOEXCEPT
		{
			value__ = value;
		}

		// TODO: The following functions can automatically be generated from
		// the YAML API docs.

		void Slider::JSExportInitialize()
		{
			JSExport<Slider>::SetClassVersion(1);
			JSExport<Slider>::SetParent(JSExport<View>::Class());
			TITANIUM_ADD_PROPERTY(Slider, max);
			TITANIUM_ADD_PROPERTY(Slider, min);
			TITANIUM_ADD_PROPERTY(Slider, value);
		}

		TITANIUM_PROPERTY_GETTER(Slider, max)
		{
			return get_context().CreateNumber(max__);
		}

		TITANIUM_PROPERTY_SETTER(Slider, max)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_max(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Slider, min)
		{
			return get_context().CreateNumber(min__);
		}

		TITANIUM_PROPERTY_SETTER(Slider, min)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_min(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Slider, value)
		{
			return get_context().CreateNumber(value__);
		}

		TITANIUM_PROPERTY_SETTER(Slider, value)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_value(static_cast<double>(argument));
			return true;
		}
	} // namespace UI
}  // namespace Titanium
