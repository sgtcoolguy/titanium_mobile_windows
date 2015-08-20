/**
 * TitaniumKit Titanium.UI.Switch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_SWITCH_HPP_
#define _TITANIUM_SWITCH_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium Switch Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Switch
		*/
		class TITANIUMKIT_EXPORT Switch : public View, public JSExport<Switch>
		{

		public:

			/*!
			  @property
			  @abstract color
			  @discussion Color to use for switch text, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, color);

			/*!
			  @property
			  @abstract enabled
			  @discussion Determines whether the switch is enabled.

			  Be careful not to confused this with the value property, which is used to turn the switch on and off.

			  Set to true to enable or false to disable the switch.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, enabled);

			/*!
			  @property
			  @abstract titleOff
			  @discussion Text to display on the switch in its "off" state, when the toggle button style is in use.

			  Set to an empty string to remove title text.

			  It is typically useful to set the width and/or height properties, to prevent the switch changing size between its on/off state.

			  Default: Off
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, titleOff);

			/*!
			  @property
			  @abstract titleOn
			  @discussion Text to display on the switch in its "on" state, when the toggle button style is in use.

			  Set to an empty string to remove title text.

			  It is typically useful to set the width and/or height properties, to prevent the switch changing size between its on/off state.

			  Default: On
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, titleOn);

			/*!
			  @property
			  @abstract value
			  @discussion Indicates whether the switch has been turned on or off by the user. May also be set programmatically.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, value);

			Switch(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Switch() = default;
			Switch(const Switch&) = default;
			Switch& operator=(const Switch&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Switch(Switch&&)                 = default;
			Switch& operator=(Switch&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(color);
			TITANIUM_FUNCTION_DEF(getColor);
			TITANIUM_FUNCTION_DEF(setColor);

			TITANIUM_PROPERTY_DEF(enabled);
			TITANIUM_FUNCTION_DEF(getEnabled);
			TITANIUM_FUNCTION_DEF(setEnabled);

			TITANIUM_PROPERTY_DEF(titleOff);
			TITANIUM_FUNCTION_DEF(getTitleOff);
			TITANIUM_FUNCTION_DEF(setTitleOff);

			TITANIUM_PROPERTY_DEF(titleOn);
			TITANIUM_FUNCTION_DEF(getTitleOn);
			TITANIUM_FUNCTION_DEF(setTitleOn);

			TITANIUM_PROPERTY_DEF(value);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);

			private:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string color__;
				bool enabled__;
				std::string titleOff__;
				std::string titleOn__;
				bool value__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_SWITCH_HPP_