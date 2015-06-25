/**
 * TitaniumKit
 *
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_SLIDER_HPP_
#define _TITANIUM_UI_SLIDER_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium UI Slider.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Slider
		*/
		class TITANIUMKIT_EXPORT Slider : public View, public JSExport<Slider>
		{
		public:
			/*!
			  @method

			  @abstract max : Number

			  @discussion Maximum value of the slider.

			  Specifies the value of the slider when the thumb is all the way to the right. This value is inclusive.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, max);

			/*!
			  @method

			  @abstract min : Number

			  @discussion Minimum value of the slider.

			  Specifies the value of the slider when the thumb is all the way to the left. This value is inclusive.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, min);

			/*!
			  @method

			  @abstract value : String

			  @discussion Current value of the slider.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, value);

			Slider(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~Slider() = default;
			Slider(const Slider&) = default;
			Slider& operator=(const Slider&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Slider(Slider&&) = default;
			Slider& operator=(Slider&&) = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(max);
			TITANIUM_PROPERTY_DEF(min);
			TITANIUM_PROPERTY_DEF(value);

			TITANIUM_FUNCTION_DEF(getMax);
			TITANIUM_FUNCTION_DEF(setMax);
			TITANIUM_FUNCTION_DEF(getMin);
			TITANIUM_FUNCTION_DEF(setMin);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);

		private:
			double max__;
			double min__;
			double value__;
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_SLIDER_HPP_
