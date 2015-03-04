/**
 * Titanium.Map.Annotation for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Map/Annotation.hpp"
#include "TitaniumWindows/Utility.hpp"

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
using namespace Windows::UI::Xaml::Controls::Maps;
using namespace Windows::Devices::Geolocation;
#endif

namespace TitaniumWindows
{
	namespace Map
	{

		void Annotation::set_latitude(const double& latitude) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_latitude(latitude);
			updateGeoLocation();
		}

		void Annotation::set_longitude(const double& longitude) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_longitude(longitude);
			updateGeoLocation();
		}

		void Annotation::updateGeoLocation() {
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			BasicGeoposition bgp = { get_latitude(), get_longitude() };
			mapicon__->Location = ref new Geopoint(bgp);
#endif
		}

		void Annotation::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_title(title);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapicon__->Title = TitaniumWindows::Utility::ConvertString(title);
#endif
		}

		Annotation::Annotation(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Map::Annotation(js_context)
		{
			TITANIUM_LOG_DEBUG("Annotation::ctor Initialize");
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapicon__ = ref new MapIcon();
			mapicon__->NormalizedAnchorPoint = Windows::Foundation::Point(0.5, 1.0);
			mapicon__->ZIndex = 2;
#endif
		}

		Annotation::~Annotation()
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapicon__ = nullptr;
#endif
		}

		void Annotation::JSExportInitialize() 
		{
			JSExport<Annotation>::SetClassVersion(1);
			JSExport<Annotation>::SetParent(JSExport<Titanium::Map::Annotation>::Class());
		}

	} // namespace Map
}  // namespace Titanium
