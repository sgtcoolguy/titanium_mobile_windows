/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_GEOLOCATION_PROXY_H__
#define __TI_GEOLOCATION_PROXY_H__

#include "TiCore/TiProxy.h"

using namespace Windows::Devices::Geolocation;
using namespace Windows::Foundation;
using namespace Windows::Services::Maps;
using namespace Windows::Web::Http;

namespace Ti { namespace Geolocation {
	class Geolocation final : public Ti::Proxy, public virtual_enable_shared_from_this < Geolocation > {
		TI_CREATE_PROXY(Geolocation)
	public:

		enum class Accuracy {
			Best,
			High,
			Best_For_Navigation,
			Hundred_Meters,
			Kilometer,
			Low,
			Nearest_Ten_Meters,
			Three_Kilometers,
		};

		static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);

		virtual Ti::Value eventAdded(const std::vector<Ti::Value>& arguments);
		virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& arguments);

	private:

		Geolocator^ geolocator_;

		EventRegistrationToken positionToken_;
		EventRegistrationToken statusToken_;

		Accuracy accuracy_;
		double distanceFilter_{ 0 };
		double heading_{ 0 };
		double headingFilter_{ 0 };
		Ti::Value lastGeolocation_;
		bool locationServicesEnabled_{ false };

		Windows::Foundation::EventRegistrationToken location_event_;
		unsigned int location_event_count_{ 0 };

		Windows::Foundation::EventRegistrationToken heading_event_;
		unsigned int heading_event_count_{ 0 };

	protected:
		static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
		Geolocation(const std::string&, const std::vector<Ti::Value>&);
		virtual ~Geolocation();

		// Sets the value of the accuracy property.
		Ti::Value setAccuracy(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, setAccuracy);

		// Gets the value of the accuracy property.
		Ti::Value getAccuracy(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getAccuracy);

		// Sets the value of the distanceFilter property.
		Ti::Value setDistanceFilter(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, setDistanceFilter);

		// Gets the value of the distanceFilter property.
		Ti::Value getDistanceFilter(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getDistanceFilter);

		// Sets the value of the headingFilter property.
		Ti::Value setHeadingFilter(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, setHeadingFilter);

		// Gets the value of the headingFilter property.
		Ti::Value getHeadingFilter(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getHeadingFilter);

		// Gets the value of the locationServicesEnabled property.
		Ti::Value getLastGeolocation(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getLastGeolocation);

		Ti::Value getLocationServicesEnabled(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getLocationServicesEnabled);

		// Resolves an address to a location.
		Ti::Value forwardGeocoder(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, forwardGeocoder);

		// Retrieves the current compass heading.
		Ti::Value getCurrentHeading(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getCurrentHeading);

		// Retrieves the last known location from the device.
		Ti::Value getCurrentPosition(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, getCurrentPosition);

		// Tries to resolve a location to an address.
		Ti::Value reverseGeocoder(const std::vector<Ti::Value>& args);
		TI_CREATE_METHOD(Geolocation, reverseGeocoder);
};
}}
#endif // defined(__TI_GEOLOCATION_PROXY_H__)
