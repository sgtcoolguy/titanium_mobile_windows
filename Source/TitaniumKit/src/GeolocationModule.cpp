/**
 * TitaniumKit Titanium.Geolocation
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/detail/TiImpl.hpp"
#include "Titanium/GeolocationModule.hpp"

namespace Titanium
{
	GeolocationModule::GeolocationModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context, "Titanium.Geolocation"),
		accuracy_best__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::BEST))),
		accuracy_best_for_navigation__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::BEST_FOR_NAVIGATION))),
		accuracy_high__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::HIGH))),
		accuracy_hundred_meters__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::HUNDRED_METERS))),
		accuracy_kilometer__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::KILOMETER))),
		accuracy_low__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::LOW))),
		accuracy_nearest_ten_meters__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::NEAREST_TEN_METERS))),
		accuracy_three_kilometers__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACCURACY::THREE_KILOMETERS))),
		accuracy__(Geolocation::ACCURACY::BEST),
		activitytype_automotive_navigation__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACTIVITYTYPE::AUTOMOTIVE_NAVIGATION))),
		activitytype_fitness__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACTIVITYTYPE::FITNESS))),
		activitytype_other__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACTIVITYTYPE::OTHER))),
		activitytype_other_navigation__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ACTIVITYTYPE::OTHER_NAVIGATION))),
		activityType__(Geolocation::ACTIVITYTYPE::OTHER),
		authorization_always__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::ALWAYS))),
		authorization_authorized__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::AUTHORIZED))),
		authorization_denied__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::DENIED))),
		authorization_restricted__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::RESTRICTED))),
		authorization_unknown__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::UNKNOWN))),
		authorization_when_in_use__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::AUTHORIZATION::WHEN_IN_USE))),
		locationServicesAuthorization__(Geolocation::AUTHORIZATION::UNKNOWN),
		error_denied__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::DENIED))),
		error_heading_failure__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::HEADING_FAILIURE))),
		error_location_unknown__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::LOCATION_UNKNOWN))),
		error_network__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::NETWORK))),
		error_region_monitoring_delayed__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::REGION_MONITORING_DELAYED))),
		error_region_monitoring_denied__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::REGION_MONITORING_DENIED))),
		error_region_monitoring_failure__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::REGION_MONITORING_FAILIURE))),
		error_timeout__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::ERROR::TIMEOUT))),
		provider_gps__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::PROVIDER::GPS))),
		provider_network__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::PROVIDER::NETOWORK))),
		provider_passive__(js_context.CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(Titanium::Geolocation::PROVIDER::PASSIVE))),
		distanceFilter__(0),
		headingFilter__(0),
		hasCompass__(false),
		locationServicesEnabled__(false),
		lastGeolocation__(get_context().CreateObject()),
		heading__(get_context().CreateObject())
	{
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_BEST)
	{
		return accuracy_best__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_BEST_FOR_NAVIGATION)
	{
		return accuracy_best_for_navigation__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_HUNDRED_METERS)
	{
		return accuracy_hundred_meters__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_KILOMETER)
	{
		return accuracy_kilometer__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_NEAREST_TEN_METERS)
	{
		return accuracy_nearest_ten_meters__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_THREE_KILOMETERS)
	{
		return accuracy_three_kilometers__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_HIGH)
	{
		return accuracy_high__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACCURACY_LOW)
	{
		return accuracy_low__;
	}

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, Geolocation::ACCURACY, accuracy)

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACTIVITYTYPE_AUTOMOTIVE_NAVIGATION)
	{
			return activitytype_automotive_navigation__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACTIVITYTYPE_FITNESS)
	{
			return activitytype_fitness__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACTIVITYTYPE_OTHER)
	{
			return activitytype_other__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ACTIVITYTYPE_OTHER_NAVIGATION)
	{
			return activitytype_other_navigation__;
	}

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, Geolocation::ACTIVITYTYPE, activityType)

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_ALWAYS)
	{
			return authorization_always__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_AUTHORIZED)
	{
			return authorization_authorized__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_DENIED)
	{
			return authorization_denied__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_RESTRICTED)
	{
			return authorization_restricted__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_UNKNOWN)
	{
			return authorization_unknown__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, AUTHORIZATION_WHEN_IN_USE)
	{
			return authorization_when_in_use__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_DENIED)
	{
			return error_denied__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_HEADING_FAILURE)
	{
			return error_heading_failure__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_LOCATION_UNKNOWN)
	{
			return error_location_unknown__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_NETWORK)
	{
			return error_network__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_REGION_MONITORING_DELAYED)
	{
			return error_region_monitoring_delayed__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_REGION_MONITORING_DENIED)
	{
			return error_region_monitoring_denied__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_REGION_MONITORING_FAILURE)
	{
			return error_region_monitoring_failure__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, ERROR_TIMEOUT)
	{
			return error_timeout__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, PROVIDER_GPS)
	{
			return provider_gps__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, PROVIDER_NETWORK)
	{
			return provider_network__;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, PROVIDER_PASSIVE)
	{
			return provider_passive__;
	}

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, double, distanceFilter)

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, double, headingFilter)

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, bool, hasCompass)

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, Geolocation::AUTHORIZATION, locationServicesAuthorization)

	TITANIUM_PROPERTY_READWRITE(GeolocationModule, bool, locationServicesEnabled)

	const JSObject& GeolocationModule::get_lastGeolocation() const TITANIUM_NOEXCEPT
	{
		return lastGeolocation__;
	}

	TITANIUM_PROPERTY_WRITE(GeolocationModule, JSObject, lastGeolocation)

	void GeolocationModule::forwardGeocoder(const std::string& address, JSObject callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("GeolocationModule::forwardGeocoder: Unimplemented");
	}

	void GeolocationModule::getCurrentHeading(JSObject callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("GeolocationModule::getCurrentHeading: Unimplemented");
	}

	void GeolocationModule::getCurrentPosition(JSObject callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("GeolocationModule::getCurrentPosition: Unimplemented");
	}

	void GeolocationModule::reverseGeocoder(const double& latitude, const double& longitude, JSObject callback) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("GeolocationModule::reverseGeocoder: Unimplemented");
	}

	void GeolocationModule::JSExportInitialize() {
		JSExport<GeolocationModule>::SetClassVersion(1);
		JSExport<GeolocationModule>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_BEST);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_BEST_FOR_NAVIGATION);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_HUNDRED_METERS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_KILOMETER);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_NEAREST_TEN_METERS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_THREE_KILOMETERS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_HIGH);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACCURACY_LOW);
			
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACTIVITYTYPE_AUTOMOTIVE_NAVIGATION);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACTIVITYTYPE_FITNESS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACTIVITYTYPE_OTHER);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ACTIVITYTYPE_OTHER_NAVIGATION);

		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_ALWAYS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_AUTHORIZED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_DENIED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_RESTRICTED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, AUTHORIZATION_WHEN_IN_USE);

		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_DENIED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_HEADING_FAILURE);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_LOCATION_UNKNOWN);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_NETWORK);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_REGION_MONITORING_DELAYED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_REGION_MONITORING_DENIED);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_REGION_MONITORING_FAILURE);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, ERROR_TIMEOUT);

		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, PROVIDER_GPS);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, PROVIDER_NETWORK);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, PROVIDER_PASSIVE);

		TITANIUM_ADD_PROPERTY(GeolocationModule, accuracy);
		TITANIUM_ADD_PROPERTY(GeolocationModule, activityType);
		TITANIUM_ADD_PROPERTY(GeolocationModule, distanceFilter);
		TITANIUM_ADD_PROPERTY(GeolocationModule, headingFilter);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, hasCompass);
		TITANIUM_ADD_PROPERTY(GeolocationModule, locationServicesAuthorization);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, locationServicesEnabled);
		TITANIUM_ADD_PROPERTY_READONLY(GeolocationModule, lastGeolocation);

		TITANIUM_ADD_FUNCTION(GeolocationModule, forwardGeocoder);
		TITANIUM_ADD_FUNCTION(GeolocationModule, getCurrentHeading);
		TITANIUM_ADD_FUNCTION(GeolocationModule, getCurrentPosition);
		TITANIUM_ADD_FUNCTION(GeolocationModule, reverseGeocoder);
		TITANIUM_ADD_FUNCTION(GeolocationModule, getAccuracy);
		TITANIUM_ADD_FUNCTION(GeolocationModule, setAccuracy);
		TITANIUM_ADD_FUNCTION(GeolocationModule, getHasCompass);

		TITANIUM_ADD_FUNCTION(GeolocationModule, getDistanceFilter);
		TITANIUM_ADD_FUNCTION(GeolocationModule, setDistanceFilter);

		TITANIUM_ADD_FUNCTION(GeolocationModule, getHeadingFilter);
		TITANIUM_ADD_FUNCTION(GeolocationModule, setHeadingFilter);

		TITANIUM_ADD_FUNCTION(GeolocationModule, getLocationServicesEnabled);
		TITANIUM_ADD_FUNCTION(GeolocationModule, getLastGeolocation);
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, accuracy)
	{
		return get_context().CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(get_accuracy()));
	}

	TITANIUM_PROPERTY_SETTER(GeolocationModule, accuracy)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		const auto accuracy = Titanium::Geolocation::Constants::to_ACCURACY(static_cast<std::underlying_type<Geolocation::ACCURACY>::type>(argument));
		set_accuracy(accuracy);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, activityType)
	{
		return get_context().CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(get_activityType()));
	}

	TITANIUM_PROPERTY_SETTER(GeolocationModule, activityType)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		const auto activityType = Titanium::Geolocation::Constants::to_ACTIVITYTYPE(static_cast<std::underlying_type<Geolocation::ACTIVITYTYPE>::type>(argument));
		set_activityType(activityType);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, distanceFilter)
	{
		return get_context().CreateNumber(get_distanceFilter());
	}

	TITANIUM_PROPERTY_SETTER(GeolocationModule, distanceFilter)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		set_distanceFilter(static_cast<double>(argument));
		return true;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, headingFilter)
	{
		return get_context().CreateNumber(get_headingFilter());
	}

	TITANIUM_PROPERTY_SETTER(GeolocationModule, headingFilter)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		set_headingFilter(static_cast<double>(argument));
		return true;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, hasCompass)
	{
		return get_context().CreateBoolean(get_hasCompass());
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, locationServicesAuthorization)
	{
		return get_context().CreateNumber(Titanium::Geolocation::Constants::to_underlying_type(get_locationServicesAuthorization()));
	}

	TITANIUM_PROPERTY_SETTER(GeolocationModule, locationServicesAuthorization)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		const auto authorization = Titanium::Geolocation::Constants::to_AUTHORIZATION(static_cast<std::underlying_type<Geolocation::AUTHORIZATION>::type>(argument));
		set_locationServicesAuthorization(authorization);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, locationServicesEnabled)
	{
		return get_context().CreateBoolean(get_locationServicesEnabled());
	}

	TITANIUM_PROPERTY_GETTER(GeolocationModule, lastGeolocation)
	{
		return get_lastGeolocation();
	}

	TITANIUM_FUNCTION(GeolocationModule, forwardGeocoder)
	{
		if (arguments.size() >= 2) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			const auto _1 = arguments.at(1);
			TITANIUM_ASSERT(_1.IsObject());
			const std::string address = static_cast<std::string>(_0);
			const auto callback = static_cast<JSObject>(_1);
			forwardGeocoder(address, callback);
		} else if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsString());
			const std::string address = static_cast<std::string>(_0);
			forwardGeocoder(address, get_context().CreateObject());
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(GeolocationModule, getCurrentHeading)
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			const auto callback = static_cast<JSObject>(_0);
			getCurrentHeading(callback);
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(GeolocationModule, getCurrentPosition)
	{
		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			const auto callback = static_cast<JSObject>(_0);
			getCurrentPosition(callback);
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(GeolocationModule, reverseGeocoder)
	{
		if (arguments.size() >= 3) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsNumber());
			const auto _1 = arguments.at(1);
			TITANIUM_ASSERT(_1.IsNumber());
			const auto _2 = arguments.at(2);
			TITANIUM_ASSERT(_2.IsObject());
			const double latitude = static_cast<double>(_0);
			const double longitude = static_cast<double>(_1);
			const auto callback = static_cast<JSObject>(_2);
			reverseGeocoder(latitude, longitude, callback);
		} else if (arguments.size() >= 2) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsNumber());
			const auto _1 = arguments.at(1);
			TITANIUM_ASSERT(_1.IsNumber());
			const double latitude = static_cast<double>(_0);
			const double longitude = static_cast<double>(_1);
			reverseGeocoder(latitude, longitude, get_context().CreateObject());
		} else if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsNumber());
			const double latitude = static_cast<double>(_0);
			reverseGeocoder(latitude, 0, get_context().CreateObject());
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getAccuracy, accuracy)
	TITANIUM_FUNCTION_AS_SETTER(GeolocationModule, setAccuracy, accuracy)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getActivityType, activityType)
	TITANIUM_FUNCTION_AS_SETTER(GeolocationModule, setActivityType, activityType)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getDistanceFilter, distanceFilter)
	TITANIUM_FUNCTION_AS_SETTER(GeolocationModule, setDistanceFilter, distanceFilter)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getHeadingFilter, headingFilter)
	TITANIUM_FUNCTION_AS_SETTER(GeolocationModule, setHeadingFilter, headingFilter)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getHasCompass, hasCompass)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getLocationServicesAuthorization, locationServicesAuthorization)
	TITANIUM_FUNCTION_AS_SETTER(GeolocationModule, setLocationServicesAuthorization, locationServicesAuthorization)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getLocationServicesEnabled, locationServicesEnabled)

	TITANIUM_FUNCTION_AS_GETTER(GeolocationModule, getLastGeolocation, lastGeolocation)

} // namespace Titanium