/**
 * TitaniumKit Titanium.UI.ActivityIndicatorStyle
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_ACTIVITYINDICATORSTYLE_HPP_
#define _TITANIUM_ACTIVITYINDICATORSTYLE_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @enum

		  @abstract These constants are for use with the
		  Titanium.UI.ActivityIndicator.style property.
		  @constant BIG Large white spinning indicator.
		  @constant BIG_DARK Large gray spinning indicator.
		  @constant DARK Small gray spinning indicator.
		  @constant PLAIN Small white spinning indicator.
		*/
		enum class TITANIUMKIT_EXPORT ACTIVITY_INDICATOR_STYLE {
			BIG,
			BIG_DARK,
			DARK,
			PLAIN
		};

		/*!
		  @class
		  @discussion This is the Titanium ActivityIndicatorStyle Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.ActivityIndicatorStyle
		*/
		class TITANIUMKIT_EXPORT ActivityIndicatorStyle : public JSExportObject, public JSExport<ActivityIndicatorStyle>
		{

		public:

			TITANIUM_PROPERTY_READONLY_DEF(BIG);
			TITANIUM_PROPERTY_READONLY_DEF(BIG_DARK);
			TITANIUM_PROPERTY_READONLY_DEF(DARK);
			TITANIUM_PROPERTY_READONLY_DEF(PLAIN);

			ActivityIndicatorStyle(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ActivityIndicatorStyle() = default;
			ActivityIndicatorStyle(const ActivityIndicatorStyle&) = default;
			ActivityIndicatorStyle& operator=(const ActivityIndicatorStyle&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ActivityIndicatorStyle(ActivityIndicatorStyle&&)                 = default;
			ActivityIndicatorStyle& operator=(ActivityIndicatorStyle&&)      = default;
#endif

			static void JSExportInitialize();

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			JSValue big__;
			JSValue big_dark__;
			JSValue dark__;
			JSValue plain__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_ACTIVITYINDICATORSTYLE_HPP_