/**
 * Titanium.Geolocation for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Geolocation.hpp"
#include "Titanium/detail/TiImpl.hpp"

#include <boost/algorithm/string.hpp>
#include <ppltasks.h>
#include <collection.h>
#include <algorithm>
#include <boost/lexical_cast.hpp>

#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	using namespace Windows::Devices::Geolocation;
	using namespace Windows::Foundation;
	using namespace Windows::Web::Http;

	Geolocation::Geolocation(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::GeolocationModule(js_context)
	{
		loadAppxManifest();
	}

	void Geolocation::JSExportInitialize() {
		JSExport<Geolocation>::SetClassVersion(1);
		JSExport<Geolocation>::SetParent(JSExport<Titanium::GeolocationModule>::Class());
	}

	void Geolocation::ensureLoadGeolocator() 
	{
		if (geolocator_ == nullptr) {
			geolocator_ = ref new Geolocator();
			geolocator_->MovementThreshold = 1;
			geolocator_->ReportInterval = 0;
			geolocator_->DesiredAccuracy = PositionAccuracy::High;
		}
	}

	void Geolocation::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
	{
		ensureLoadGeolocator();

		// Location event
		if (event_name == "location") {
			location_event_ = geolocator_->PositionChanged += ref new TypedEventHandler<Geolocator^, PositionChangedEventArgs^>([=](Geolocator^ locator, PositionChangedEventArgs^ args) {
				const auto latitude = args->Position->Coordinate->Point->Position.Latitude;
				const auto longitude = args->Position->Coordinate->Point->Position.Longitude;
				const auto altitude = args->Position->Coordinate->Point->Position.Altitude;
				const auto altitudeAccuracy = args->Position->Coordinate->AltitudeAccuracy->Value;
				const auto speed = args->Position->Coordinate->Speed->Value;

				Utility::RunOnUIThread([=](){
					lastGeolocation__.SetProperty("latitude", get_context().CreateNumber(latitude));
					lastGeolocation__.SetProperty("longitude", get_context().CreateNumber(longitude));
					lastGeolocation__.SetProperty("altitude", get_context().CreateNumber(altitude));
					lastGeolocation__.SetProperty("altitudeAccuracy", get_context().CreateNumber(altitudeAccuracy));
					lastGeolocation__.SetProperty("speed", get_context().CreateNumber(speed));

					this->fireEvent("location", lastGeolocation__);
				});
			});

		// Heading event
		} else if (event_name == "heading") {
			heading_event_ = geolocator_->PositionChanged += ref new TypedEventHandler<Geolocator^, PositionChangedEventArgs^>([=](Geolocator^ locator, PositionChangedEventArgs^ args) {
				const auto heading = args->Position->Coordinate->Heading->Value;

				Utility::RunOnUIThread([=](){
					const auto old_heading = static_cast<double>(heading__.GetProperty("heading"));
					if (abs(heading - old_heading) > headingFilter__) {
						heading__.SetProperty("heading", get_context().CreateNumber(heading));

						this->fireEvent("heading", heading__);
					}
				});
			});
		}
	}

	void Geolocation::set_accuracy(const Titanium::Geolocation::ACCURACY& accuracy) TITANIUM_NOEXCEPT
	{
		using namespace Titanium::Geolocation;

		ensureLoadGeolocator();

		switch (accuracy) {
			case ACCURACY::BEST:
			case ACCURACY::HIGH:
			case ACCURACY::BEST_FOR_NAVIGATION:
				geolocator_->DesiredAccuracyInMeters = nullptr;
				geolocator_->DesiredAccuracy = PositionAccuracy::High;
			break;

			default:
			case ACCURACY::LOW: {
				geolocator_->DesiredAccuracyInMeters = nullptr;
				geolocator_->DesiredAccuracy = PositionAccuracy::Default;
			}
			break;

			case ACCURACY::NEAREST_TEN_METERS: {
				geolocator_->DesiredAccuracyInMeters = 10U;
			}
			break;

			case ACCURACY::HUNDRED_METERS: {
				geolocator_->DesiredAccuracyInMeters = 100U;
			}
			break;

			case ACCURACY::KILOMETER: {
				geolocator_->DesiredAccuracyInMeters = 1000U;
			}
			break;

			case ACCURACY::THREE_KILOMETERS: {
				geolocator_->DesiredAccuracyInMeters = 3000U;
			}
			break;
		}
		Titanium::GeolocationModule::set_accuracy(accuracy);
	}

	void Geolocation::set_distanceFilter(const double& distance) TITANIUM_NOEXCEPT
	{
		ensureLoadGeolocator();

		geolocator_->MovementThreshold = distance;
		Titanium::GeolocationModule::set_distanceFilter(distance);
	}

	void Geolocation::loadAppxManifest()
	{
		using namespace Windows::Data::Xml::Dom;
		using namespace Windows::Storage;
		using namespace concurrency;

		concurrency::event event;
		task<StorageFile^>(Windows::ApplicationModel::Package::Current->InstalledLocation->GetFileAsync("AppxManifest.xml")).then([&event, this](task<StorageFile^> fileTask) {
			try {
				task<XmlDocument^>(XmlDocument::LoadFromFileAsync(fileTask.get())).then([&event, this](task<XmlDocument^> docTask) {
					try {
						const auto doc = docTask.get();
						const auto items = doc->GetElementsByTagName("DeviceCapability");
						for (unsigned int i = 0; i < items->Length; i++) {
							const auto node = items->GetAt(i);
							const auto name = static_cast<Platform::String^>(node->Attributes->GetNamedItem("Name")->NodeValue);
							if (name == "location") {
								set_locationServicesEnabled(true);
							}
						}
					} catch (...) {
						set_locationServicesEnabled(false);
					}
					event.set();
				}, concurrency::task_continuation_context::use_arbitrary());
			} catch (...) {
				set_locationServicesEnabled(true);
				event.set();
			}
		}, concurrency::task_continuation_context::use_arbitrary());
		event.wait();
	}

	void Geolocation::forwardGeocoder(const std::string& address, JSObject callback) TITANIUM_NOEXCEPT
	{
		auto requestString = std::string("http://api.appcelerator.net/p/v1/geo?d=f");

			//TODO : Use real GUID, MID, SID
			requestString += std::string("&aguid=") + std::string("25FE4B6E-7DA9-4344-B55B-25195570860F");
			requestString += std::string("&mid=") + std::string("com.appcelerator.uuid");
			requestString += std::string("&sid=") + std::string("sid");
			requestString += std::string("&q=") + address;
			//requestString += std::string("&c=") + std::string("US");

			const auto requestUri = ref new Windows::Foundation::Uri(Utility::ConvertString(requestString));

			const auto httpClient = ref new HttpClient();
			concurrency::create_task(httpClient->GetAsync(requestUri)).then([this, address, callback](HttpResponseMessage^ response) {
				try {
					std::vector<std::string> split_response;
					boost::split(split_response, Utility::ConvertString(response->Content->ToString()), boost::is_any_of(","));

					JSObject forwardGeocodeResponse = get_context().CreateObject();

					if (split_response.size() > 0 && split_response.at(0) == "200") {
						const double accuracy = atof(split_response.at(1).c_str());
						const double latitude = atof(split_response.at(2).c_str());
						const double longitude = atof(split_response.at(3).c_str());

						forwardGeocodeResponse.SetProperty("accuracy", get_context().CreateNumber(accuracy));
						forwardGeocodeResponse.SetProperty("address", get_context().CreateString(address));
						forwardGeocodeResponse.SetProperty("latitude", get_context().CreateNumber(latitude));
						forwardGeocodeResponse.SetProperty("longitude", get_context().CreateNumber(longitude));
						forwardGeocodeResponse.SetProperty("success", get_context().CreateBoolean(true));
						forwardGeocodeResponse.SetProperty("error", get_context().CreateString(""));
						forwardGeocodeResponse.SetProperty("code", get_context().CreateNumber(0.0));
					}
					else {
						forwardGeocodeResponse.SetProperty("success", get_context().CreateBoolean(false));
						forwardGeocodeResponse.SetProperty("error", get_context().CreateString("no results"));
						forwardGeocodeResponse.SetProperty("code", get_context().CreateNumber(static_cast<double>(-1)));
					}

					// Cast callback as non-const JSObject
					// TODO : More elegant way of doing this
					auto cb = static_cast<JSObject>(callback);
					TITANIUM_ASSERT(cb.IsFunction());
					cb({ forwardGeocodeResponse }, get_context().get_global_object());
				} catch (...) {
					// TODO: Need to revisit - Geolocation module basically lacks exception handling during callback
					TITANIUM_LOG_WARN("Error duging Geolocation::forwardGeocoder");
				}
			});
	}

	void Geolocation::getCurrentHeading(JSObject callback) TITANIUM_NOEXCEPT
	{
		ensureLoadGeolocator();

		concurrency::create_task(geolocator_->GetGeopositionAsync()).then([this, callback](Geoposition^ position) {
			const auto data = position->Coordinate;
			JSObject headingResponse = get_context().CreateObject();

			headingResponse.SetProperty("code", get_context().CreateNumber(0.0));
			headingResponse.SetProperty("error", get_context().CreateString(""));

			JSObject headingData = get_context().CreateObject();
			headingData.SetProperty("accuracy", get_context().CreateNumber(data->Accuracy));
			headingData.SetProperty("magneticHeading", get_context().CreateNumber(data->Heading->Value));
			headingData.SetProperty("timestamp", get_context().CreateNumber(static_cast<double>(data->Timestamp.UniversalTime)));
			headingData.SetProperty("trueHeading", get_context().CreateNumber(data->Heading->Value));

			//heading_ = data->Heading->Value;

			headingData.SetProperty("x", get_context().CreateNumber(0.0));
			headingData.SetProperty("y", get_context().CreateNumber(0.0));
			headingData.SetProperty("z", get_context().CreateNumber(0.0));

			headingResponse.SetProperty("heading", headingData);
			headingResponse.SetProperty("success", get_context().CreateBoolean(true));

			// Cast callback as non-const JSObject
			// TODO : More elegant way of doing this
			auto cb = static_cast<JSObject>(callback);
			TITANIUM_ASSERT(cb.IsFunction());
			cb({headingResponse}, get_context().get_global_object());
		});
	}

	void Geolocation::getCurrentPosition(JSObject callback) TITANIUM_NOEXCEPT
	{
		ensureLoadGeolocator();

		concurrency::create_task(geolocator_->GetGeopositionAsync()).then([this, callback](Geoposition^ position) {
			const auto data = position->Coordinate;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
			JSObject locationResult = get_context().CreateObject();

			locationResult.SetProperty("code", get_context().CreateNumber(0.0));

			JSObject provider = get_context().CreateObject();
			provider.SetProperty("power", get_context().CreateNumber(1.0));
			provider.SetProperty("name", get_context().CreateString("network"));
			provider.SetProperty("accuracy", get_context().CreateNumber(2.0));
			locationResult.SetProperty("provider", provider);

			JSObject coords = get_context().CreateObject();
			coords.SetProperty("altitude", get_context().CreateNumber(data->Point->Position.Altitude));
			coords.SetProperty("speed", get_context().CreateNumber(data->Speed->Value));
			coords.SetProperty("longitude", get_context().CreateNumber(data->Point->Position.Longitude));
			coords.SetProperty("heading", get_context().CreateNumber(data->Heading->Value));
			coords.SetProperty("latitude", get_context().CreateNumber(data->Point->Position.Latitude));
			coords.SetProperty("timestamp", get_context().CreateNumber(static_cast<double>(data->Timestamp.UniversalTime)));
			//coords.SetProperty("altitudeAccuracy", get_context().CreateNumber(data->AltitudeAccuracy->Value));
			coords.SetProperty("accuracy", get_context().CreateNumber(data->Accuracy));
			locationResult.SetProperty("coords", coords);

			lastGeolocation__.SetProperty("longitude", get_context().CreateNumber(data->Point->Position.Longitude));
			lastGeolocation__.SetProperty("latitude", get_context().CreateNumber(data->Point->Position.Latitude));

			locationResult.SetProperty("success", get_context().CreateBoolean(true));

			// Cast callback as non-const JSObject
			// TODO : More elegant way of doing this
			auto cb = static_cast<JSObject>(callback);
			TITANIUM_ASSERT(cb.IsFunction());
			cb({locationResult}, get_context().get_global_object());
		});
	}

	void Geolocation::reverseGeocoder(const double& latitude, const double& longitude, JSObject callback) TITANIUM_NOEXCEPT
	{
		ensureLoadGeolocator();

		auto requestString = std::string("http://api.appcelerator.net/p/v1/geo?d=r");

		//TODO : Use real GUID, MID, SID
		requestString += std::string("&aguid=") + std::string("25FE4B6E-7DA9-4344-B55B-25195570860F");
		requestString += std::string("&mid=") + std::string("com.appcelerator.uuid");
		requestString += std::string("&sid=") + std::string("sid");
		requestString += std::string("&q="+boost::lexical_cast<std::string>(latitude)+","+boost::lexical_cast<std::string>(longitude));
		//requestString += std::string("&c=") + std::string("US");

		const auto requestUri = ref new Windows::Foundation::Uri(Utility::ConvertString(requestString));

		const auto httpClient = ref new HttpClient();
		concurrency::create_task(httpClient->GetAsync(requestUri)).then([this, callback](HttpResponseMessage^ response) {
			auto result = get_context().CreateValueFromJSON(Utility::ConvertString(response->Content->ToString()));

			// Cast callback as non-const JSObject
			// TODO : More elegant way of doing this
			auto cb = static_cast<JSObject>(callback);
			TITANIUM_ASSERT(cb.IsFunction());
			try {
				cb({result}, get_context().get_global_object());
			} catch (...) {
			}
		});
	}
}  // namespace TitaniumWindows