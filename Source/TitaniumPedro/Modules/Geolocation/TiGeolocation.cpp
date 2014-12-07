/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiGeolocation.h"
#include <Windows.h>

#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiUtils.h"
#include "TiCore/TiConstants.h"

#include <boost/algorithm/string.hpp>

#include <ppltasks.h>

namespace Ti { namespace Geolocation {

	// These are JavaScript methods they will call class methods
	const JSStaticFunction Geolocation::ClassMethods[] = {
		{"setAccuracy" ,_setAccuracy ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getAccuracy" ,_getAccuracy ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setDistanceFilter" ,_setDistanceFilter ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getDistanceFilter" ,_getDistanceFilter ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setHeadingFilter" ,_setHeadingFilter ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getHeadingFilter" ,_getHeadingFilter ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getLastGeolocation" ,_getLastGeolocation ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getLocationServicesEnabled", _getLocationServicesEnabled, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
		{"forwardGeocoder" ,_forwardGeocoder ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getCurrentHeading" ,_getCurrentHeading ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getCurrentPosition" ,_getCurrentPosition ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"reverseGeocoder" ,_reverseGeocoder ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{0,0,0}
	};
	
	Geolocation::~Geolocation(){
		geolocator_->PositionChanged::remove(positionToken_);
		geolocator_->StatusChanged::remove(statusToken_);
	}
	Geolocation::Geolocation(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args){
		geolocator_ = ref new Geolocator();
		geolocator_->MovementThreshold = 1;
		geolocator_->ReportInterval = 0;
		geolocator_->DesiredAccuracy = PositionAccuracy::High;
	}

	Ti::Value Geolocation::Initialize(const std::string& ns, Ti::Value& obj) {
		Ti::Value geoModule;

		geoModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
		geoModule.setProperty("TiGeolocation", Geolocation::CreateConstructor());

		Ti::Value result = Ti::evaluateScriptFileInObject("TitaniumPedro/ti.geolocation.js", geoModule);
		std::string r = result.toString();

		result.setProperty("ACCURACY_BEST", Ti::Value(static_cast<double>(Accuracy::Best)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_BEST_FOR_NAVIGATION", Ti::Value(static_cast<double>(Accuracy::Best_For_Navigation)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_HIGH", Ti::Value(static_cast<double>(Accuracy::High)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_HUNDRED_METERS", Ti::Value(static_cast<double>(Accuracy::Hundred_Meters)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_KILOMETER", Ti::Value(static_cast<double>(Accuracy::Kilometer)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_LOW", Ti::Value(static_cast<double>(Accuracy::Low)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_NEAREST_TEN_METERS", Ti::Value(static_cast<double>(Accuracy::Nearest_Ten_Meters)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("ACCURACY_THREE_KILOMETERS", Ti::Value(static_cast<double>(Accuracy::Three_Kilometers)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);

		obj.setProperty(ns, result);

		return result;
	}

	// Public API

	// Get the events as they are added to the object
	Ti::Value Geolocation::eventAdded(const std::vector<Ti::Value>& arguments)
	{
		auto arg = arguments[0].toString();

		// Location event
		if (arg == Ti::Constants::EventLocation) {
			if (location_event_count_ == 0) {
				auto weak = get_weak_ptr_for_proxy();
				location_event_ = geolocator_->PositionChanged += ref new TypedEventHandler<Geolocator^, PositionChangedEventArgs^>([=](Geolocator^ locator, PositionChangedEventArgs^ args) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					auto latitude = args->Position->Coordinate->Latitude;
					auto longitude = args->Position->Coordinate->Longitude;
					auto altitude = args->Position->Coordinate->Altitude->Value;
					auto altitudeAccuracy = args->Position->Coordinate->AltitudeAccuracy->Value;
					auto speed = args->Position->Coordinate->Speed->Value;

					Ti::Utils::RunOnUIThread([=](){
						auto proxy = weak.lock();
						assert(proxy != nullptr);

						Ti::Value obj;
						obj.setProperty("latitude", Ti::Value(latitude));
						obj.setProperty("longitude", Ti::Value(longitude));
						obj.setProperty("altitude", Ti::Value(altitude));
						obj.setProperty("altitudeAccuracy", Ti::Value(altitudeAccuracy));
						obj.setProperty("speed", Ti::Value(speed));

						lastGeolocation_ = obj;

						proxy->fireEvent(Ti::Constants::EventLocation, obj);
					});
				});
			}
			location_event_count_++;

		// Heading event
		} else if (arg == Ti::Constants::EventHeading) {
			if (heading_event_count_ == 0) {
				auto weak = get_weak_ptr_for_proxy();
				heading_event_ = geolocator_->PositionChanged += ref new TypedEventHandler<Geolocator^, PositionChangedEventArgs^>([this, weak](Geolocator^ locator, PositionChangedEventArgs^ args) {
					auto proxy = weak.lock();
					assert(proxy != nullptr);

					auto heading = args->Position->Coordinate->Heading->Value;

					Ti::Utils::RunOnUIThread([=](){
						auto proxy = weak.lock();
						assert(proxy != nullptr);

						Ti::Value obj;
						obj.setProperty("heading", Ti::Value(heading));

						if (abs(heading - heading_) > headingFilter_) {
							heading_ = heading;
							proxy->fireEvent(Ti::Constants::EventHeading, obj);
						}
					});
				});
			}
			heading_event_count_++;
		}
		return Ti::Proxy::eventAdded(arguments);
	}

	Ti::Value Geolocation::eventRemoved(const std::vector<Ti::Value>& arguments)
	{
		auto arg = arguments[0].toString();

		// Location event
		if (arg == Ti::Constants::EventLocation) {
			location_event_count_--;
			if (location_event_count_ == 0) {
				geolocator_->PositionChanged -= location_event_;
			}

		// Heading event
		} else if (arg == Ti::Constants::EventHeading) {
			heading_event_count_--;
			if (heading_event_count_ == 0) {
				geolocator_->PositionChanged -= heading_event_;
			}
		}
		return Ti::Proxy::eventRemoved(arguments);
	}

	// Sets the value of the accuracy property.
	Ti::Value Geolocation::setAccuracy(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			accuracy_ = static_cast<Accuracy>((int)args.at(0).toDouble());

			switch (accuracy_) {
				case Accuracy::Best:
				case Accuracy::Best_For_Navigation:
				case Accuracy::High:
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(0);
					geolocator_->DesiredAccuracy = PositionAccuracy::High;
				break;

				default:
				case Accuracy::Low: {
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(0);
					geolocator_->DesiredAccuracy = PositionAccuracy::Default;
				}
				break;

				case Accuracy::Nearest_Ten_Meters: {
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(10);
				}
				break;

				case Accuracy::Hundred_Meters: {
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(100);
				}
				break;

				case Accuracy::Kilometer: {
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(1000);
				}
				break;

				case Accuracy::Three_Kilometers: {
					geolocator_->DesiredAccuracyInMeters = static_cast<unsigned int>(3000);
				}
				break;
			}

		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the accuracy property.
	Ti::Value Geolocation::getAccuracy(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(static_cast<double>(accuracy_));
	}

	// Sets the value of the distanceFilter property.
	Ti::Value Geolocation::setDistanceFilter(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			distanceFilter_ = args.at(0).toDouble();
			geolocator_->MovementThreshold = distanceFilter_;
		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the distanceFilter property.
	Ti::Value Geolocation::getDistanceFilter(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(distanceFilter_);
	}

	// Sets the value of the headingFilter property.
	Ti::Value Geolocation::setHeadingFilter(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			headingFilter_ = args.at(0).toDouble();
		}
		return Ti::Value::Undefined();
	}

	// Gets the value of the headingFilter property.
	Ti::Value Geolocation::getHeadingFilter(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(headingFilter_);
	}

	// Gets the value of the lastGeolocation property.
	Ti::Value Geolocation::getLastGeolocation(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(lastGeolocation_);
	}

	// Gets the value of the locationServicesEnabled property.
	Ti::Value Geolocation::getLocationServicesEnabled(const std::vector<Ti::Value>& args)
	{
		PositionStatus status = geolocator_->LocationStatus;
		switch (status) {
			case PositionStatus::Ready:
				locationServicesEnabled_ = true;
				break;
			case PositionStatus::Disabled:
			case PositionStatus::Initializing:
			case PositionStatus::NoData:
			case PositionStatus::NotAvailable:
			case PositionStatus::NotInitialized:
			default:
				locationServicesEnabled_ = false;
				break;
		};
		return Ti::Value(locationServicesEnabled_);
	}

	// Resolves an address to a location.
	Ti::Value Geolocation::forwardGeocoder(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 2) {

			auto address = args.at(0);
			auto callback = args.at(1);
			if (!callback.isFunction()) {
				// TODO : throw exception
				return Ti::Value::Undefined();
			}

			auto requestString = std::string("http://api.appcelerator.net/p/v1/geo?d=f");

			//TODO : Use real GUID, MID, SID
			requestString += std::string("&aguid=") + std::string("25FE4B6E-7DA9-4344-B55B-25195570860F");
			requestString += std::string("&mid=") + std::string("com.appcelerator.uuid");
			requestString += std::string("&sid=") + std::string("sid");
			requestString += std::string("&q=") + address.toString();
			//requestString += std::string("&c=") + std::string("US");

			auto requestUri = ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(requestString));

			const auto callback_ref = callback.JSObjectRef();
			JSValueProtect(Ti::Runtime::instance().globalContext(), callback_ref);

			auto httpClient = ref new HttpClient();
			concurrency::create_task(httpClient->GetAsync(requestUri)).then([=](HttpResponseMessage^ response) {
				std::vector<std::string> split_response;
				boost::split(split_response, Ti::Utils::GetPlatformString(response->Content->ToString()), boost::is_any_of(","));

				Ti::Value forwardGeocodeResponse;

				if (split_response.size() > 0 && split_response.at(0) == "200") {
					double accuracy = atof(split_response.at(1).c_str());
					double latitude = atof(split_response.at(2).c_str());
					double longitude = atof(split_response.at(3).c_str());

					forwardGeocodeResponse.setProperty("accuracy", Ti::Value(accuracy));
					forwardGeocodeResponse.setProperty("address", address);
					forwardGeocodeResponse.setProperty("latitude", Ti::Value(latitude));
					forwardGeocodeResponse.setProperty("longitude", Ti::Value(longitude));
					forwardGeocodeResponse.setProperty("success", Ti::Value(true));
					forwardGeocodeResponse.setProperty("error", Ti::Value(""));
					forwardGeocodeResponse.setProperty("code", Ti::Value(0.0));
				}
				else {
					forwardGeocodeResponse.setProperty("success", Ti::Value(false));
					forwardGeocodeResponse.setProperty("error", Ti::Value("no results"));
					forwardGeocodeResponse.setProperty("code", Ti::Value(static_cast<double>(-1)));
				}

				const JSValueRef jsArgs[] = { forwardGeocodeResponse.JSValueRef() };
				JSObjectCallAsFunction(Ti::Runtime::instance().globalContext(), callback_ref, Ti::Runtime::instance().globalObject(), 1, jsArgs, nullptr);
				JSValueUnprotect(Ti::Runtime::instance().globalContext(), callback_ref);
			});
		}
		return Ti::Value::Undefined();
	}

	// Retrieves the current compass heading.
	Ti::Value Geolocation::getCurrentHeading(const std::vector<Ti::Value>& args) {

		auto callback = args.at(0);
		if (!callback.isFunction()) {
			// TODO : throw exception
			return Ti::Value::Undefined();
		}

		const auto callback_ref = callback.JSObjectRef();
		JSValueProtect(Ti::Runtime::instance().globalContext(), callback_ref);
		concurrency::create_task(geolocator_->GetGeopositionAsync()).then([this, callback_ref](Geoposition^ position) {
			auto data = position->Coordinate;
			Ti::Value headingResponse;

			headingResponse.setProperty("code", Ti::Value(0.0));
			headingResponse.setProperty("error", Ti::Value(""));

			Ti::Value headingData;
			headingData.setProperty("accuracy", Ti::Value(data->Accuracy));
			headingData.setProperty("magneticHeading", Ti::Value(data->Heading->Value));
			headingData.setProperty("timestamp", Ti::Value(static_cast<double>(data->Timestamp.UniversalTime)));
			headingData.setProperty("trueHeading", Ti::Value(data->Heading->Value));

			heading_ = data->Heading->Value;

			headingData.setProperty("x", Ti::Value(0.0));
			headingData.setProperty("y", Ti::Value(0.0));
			headingData.setProperty("z", Ti::Value(0.0));

			headingResponse.setProperty("success", Ti::Value(true));

			const JSValueRef jsArgs[] = { headingResponse.JSValueRef() };
			JSObjectCallAsFunction(Ti::Runtime::instance().globalContext(), callback_ref, Ti::Runtime::instance().globalObject(), 1, jsArgs, nullptr);
			JSValueUnprotect(Ti::Runtime::instance().globalContext(), callback_ref);
		});

		return Ti::Value::Undefined();
	}

	// Retrieves location from the device.
	Ti::Value Geolocation::getCurrentPosition(const std::vector<Ti::Value>& args) {
		auto callback = args.at(0);
		if (!callback.isFunction()) {
			// TODO : throw exception
			return Ti::Value::Undefined();
		}

		const auto callback_ref = callback.JSObjectRef();
		JSValueProtect(Ti::Runtime::instance().globalContext(), callback_ref);
		concurrency::create_task(geolocator_->GetGeopositionAsync()).then([this, callback_ref](Geoposition^ position) {
			auto data = position->Coordinate;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
			Ti::Value locationResult;

			locationResult.setProperty("code", Ti::Value(0.0));

			Ti::Value provider;
			provider.setProperty("power", Ti::Value(1.0));
			provider.setProperty("name", Ti::Value("network"));
			provider.setProperty("accuracy", Ti::Value(2.0));
			locationResult.setProperty("provider", provider);

			Ti::Value coords;
			coords.setProperty("altitude", Ti::Value(data->Altitude->Value));
			coords.setProperty("speed", Ti::Value(data->Speed->Value));
			coords.setProperty("longitude", Ti::Value(data->Longitude));
			coords.setProperty("heading", Ti::Value(data->Heading->Value));
			coords.setProperty("latitude", Ti::Value(data->Latitude));
			coords.setProperty("timestamp", Ti::Value(static_cast<double>(data->Timestamp.UniversalTime)));
			coords.setProperty("altitudeAccuracy", Ti::Value(data->AltitudeAccuracy->Value));
			coords.setProperty("accuracy", Ti::Value(data->Accuracy));
			locationResult.setProperty("coords", coords);

			lastGeolocation_.setProperty("longitude", Ti::Value(data->Longitude));
			lastGeolocation_.setProperty("latitude", Ti::Value(data->Latitude));

			locationResult.setProperty("success", Ti::Value(true));

			const JSValueRef jsArgs[] = { locationResult.JSValueRef() };
			JSObjectCallAsFunction(Ti::Runtime::instance().globalContext(), callback_ref, Ti::Runtime::instance().globalObject(), 1, jsArgs, nullptr);
			JSValueUnprotect(Ti::Runtime::instance().globalContext(), callback_ref);
		});

		return Ti::Value::Undefined();
	}

	// Tries to resolve a location to an address.
	Ti::Value Geolocation::reverseGeocoder(const std::vector<Ti::Value>& args) {

		auto latitude = args.at(0);
		auto longitude = args.at(1);
		auto callback = args.at(2);
		if (!callback.isFunction()) {
			// TODO : throw exception
			return Ti::Value::Undefined();
		}

		auto requestString = std::string("http://api.appcelerator.net/p/v1/geo?d=r");

		//TODO : Use real GUID, MID, SID
		requestString += std::string("&aguid=") + std::string("25FE4B6E-7DA9-4344-B55B-25195570860F");
		requestString += std::string("&mid=") + std::string("com.appcelerator.uuid");
		requestString += std::string("&sid=") + std::string("sid");
		requestString += std::string("&q=") + latitude.toString() + "," + longitude.toString();
		//requestString += std::string("&c=") + std::string("US");

		auto requestUri = ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(requestString));

		const auto callback_ref = callback.JSObjectRef();
		JSValueProtect(Ti::Runtime::instance().globalContext(), callback_ref);

		auto httpClient = ref new HttpClient();
		concurrency::create_task(httpClient->GetAsync(requestUri)).then([=](HttpResponseMessage^ response) {
			const JSValueRef jsArgs[] = { Ti::Value(Ti::Utils::GetPlatformString(response->Content->ToString())).toJSONObject().JSValueRef() };
			JSObjectCallAsFunction(Ti::Runtime::instance().globalContext(), callback_ref, Ti::Runtime::instance().globalObject(), 1, jsArgs, nullptr);
			JSValueUnprotect(Ti::Runtime::instance().globalContext(), callback_ref);
		});

		return Ti::Value::Undefined();
	}
}}