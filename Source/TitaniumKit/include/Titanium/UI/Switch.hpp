/**
 * TitaniumKit Titanium.UI.Switch
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_SWITCH_HPP_
#define _TITANIUM_SWITCH_HPP_

#include "Titanium/UI/Constants.hpp"
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

			TITANIUM_PROPERTY_DEF(value);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);

			private:
				bool value__;
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_SWITCH_HPP_