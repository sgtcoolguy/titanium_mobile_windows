/**
 * TitaniumKit Titanium.UI.Notification
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_NOTIFICATION_HPP_
#define _TITANIUM_NOTIFICATION_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium Notification Module.
		  See http://docs.appcelerator.com/platform/latest/#!/api/Titanium.UI.Notification
		*/
		class TITANIUMKIT_EXPORT Notification : public View, public JSExport<Notification>
		{

		public:

			/*!
			  @property
			  @abstract message
			  @discussion Notification text to display.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, message);

			/*!
			  @property
			  @abstract duration
			  @discussion Determines how long the notification stays on screen.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(NOTIFICATION_DURATION, duration);

			/*!
			  @property
			  @abstract xOffset
			  @discussion X offset from the default position, in pixels.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(int32_t, xOffset);

			/*!
			  @property
			  @abstract yOffset
			  @discussion Y offset from the default position, in pixels.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(int32_t, yOffset);

			/*!
			  @property
			  @abstract horizontalMargin
			  @discussion Horizontal placement of the notification, *as a fraction of the screen width*.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, horizontalMargin);

			/*!
			  @property
			  @abstract verticalMargin
			  @discussion Vertical placement of the notifcation, *as a fraction of the screen height*.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(double, verticalMargin);

			/*!
			  @method
			  @abstract show
			  @discussion Show the notification.
			*/
			virtual void show() TITANIUM_NOEXCEPT;

			Notification(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
			virtual ~Notification()                      = default;
			Notification(const Notification&)            = default;
			Notification& operator=(const Notification&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Notification(Notification&&)                 = default;
			Notification& operator=(Notification&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(message);
			TITANIUM_PROPERTY_DEF(duration);
			TITANIUM_PROPERTY_DEF(xOffset);
			TITANIUM_PROPERTY_DEF(yOffset);
			TITANIUM_PROPERTY_DEF(horizontalMargin);
			TITANIUM_PROPERTY_DEF(verticalMargin);

			TITANIUM_FUNCTION_DEF(show);
			TITANIUM_FUNCTION_DEF(getMessage);
			TITANIUM_FUNCTION_DEF(setMessage);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(setDuration);
			TITANIUM_FUNCTION_DEF(getXOffset);
			TITANIUM_FUNCTION_DEF(setXOffset);
			TITANIUM_FUNCTION_DEF(getYOffset);
			TITANIUM_FUNCTION_DEF(setYOffset);
			TITANIUM_FUNCTION_DEF(getHorizontalMargin);
			TITANIUM_FUNCTION_DEF(setHorizontalMargin);
			TITANIUM_FUNCTION_DEF(getVerticalMargin);
			TITANIUM_FUNCTION_DEF(setVerticalMargin);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::string message__;
			NOTIFICATION_DURATION duration__;
			int32_t xOffset__;
			int32_t yOffset__;
			double horizontalMargin__;
			double verticalMargin__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_NOTIFICATION_HPP_