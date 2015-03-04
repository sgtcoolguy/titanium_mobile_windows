/**
 * Titanium.Map.View for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Map/View.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/Map/Annotation.hpp"

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
using namespace Windows::Devices::Geolocation;
#endif

namespace TitaniumWindows
{
	namespace Map
	{
		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Map::View(js_context)
		{
			TITANIUM_LOG_DEBUG("View::ctor Initialize");

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapview__ = ref new MapControl();

				// Set service token
			// TODO : Load this from app properties, windows_map_service_token?
			mapview__->MapServiceToken = "VrSrmXR8B5bgklWrs0CK_w";

			// Layout engine
			TitaniumWindows::UI::ViewBase::setDefaultHeight(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			TitaniumWindows::UI::ViewBase::setDefaultWidth(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			TitaniumWindows::UI::ViewBase::setComponent(mapview__);

			zoom(12); // use a default zoom of 12 for Windows?
#endif
		}

		View::~View()
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapview__ = nullptr;
#endif
		}

		void View::JSExportInitialize() 
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::Map::View>::Class());
		}

		uint32_t View::get_maxZoomLevel() const TITANIUM_NOEXCEPT
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			return static_cast<uint32_t>(mapview__->MaxZoomLevel); // should be 20
#else
			return 20;
#endif
		}

		uint32_t View::get_minZoomLevel() const TITANIUM_NOEXCEPT
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			return static_cast<uint32_t>(mapview__->MinZoomLevel); // should be 1
#else
			return 1;
#endif
		}

		void View::set_mapType(const Titanium::Map::MAP_TYPE& mapType) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_mapType(mapType);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			if (mapType == Titanium::Map::MAP_TYPE::HYBRID) {
				mapview__->Style = MapStyle::AerialWithRoads;
			} else if (mapType == Titanium::Map::MAP_TYPE::SATELLITE) {
				mapview__->Style = MapStyle::Aerial;
			} else if (mapType == Titanium::Map::MAP_TYPE::NORMAL) {
				mapview__->Style = MapStyle::Road;
			}
#endif
		}

		void View::set_region(const Titanium::Map::MapRegionTypev2& region) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_region(region);

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			// If there are deltas, use them
			if (region.latitudeDelta > 0 && region.longitudeDelta > 0) {
				BasicGeoposition top_left = { region.latitude - region.latitudeDelta, region.longitude - region.longitudeDelta };
				BasicGeoposition bottom_right = { region.latitude + region.latitudeDelta, region.longitude + region.longitudeDelta };

				auto bounds = ref new GeoboundingBox(bottom_right, top_left);
				mapview__->TrySetViewBoundsAsync(bounds, nullptr, MapAnimationKind::Default);
			} else {
				// no deltas, use the long/lat and zoom
				BasicGeoposition location = { region.latitude, region.longitude };
				auto gp = ref new Geopoint(location);

				if (region.zoom > 0) {
					mapview__->TrySetViewAsync(gp, static_cast<double>(region.zoom));
				} else {
					mapview__->TrySetViewAsync(gp);
				}
			}
#endif
		}

		void View::set_showsBuildings(const bool& buildings) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_showsBuildings(buildings);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapview__->LandmarksVisible = buildings;
#endif
		}

		void View::set_traffic(const bool& traffic) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_traffic(traffic);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapview__->TrafficFlowVisible = traffic;
#endif
		}

		void View::addAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::addAnnotation(annotation);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			auto native_annotation_ptr = annotation->get_object().GetPrivate<TitaniumWindows::Map::Annotation>();
			if (native_annotation_ptr != nullptr) {
				mapview__->MapElements->Append(native_annotation_ptr->GetMapIcon());
			}
#endif
		}

		void View::removeAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::removeAnnotation(annotation);

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			for (size_t i = 0; i < mapview__->MapElements->Size; i++) {
				auto element = mapview__->MapElements->GetAt(i);
				MapIcon^ icon = dynamic_cast<MapIcon^>(element);
				if (icon == nullptr) {
					continue; // not an annotation
				}
				// find annotation identified by title or a reference.
				auto annotation_ptr = annotation->get_object().GetPrivate<TitaniumWindows::Map::Annotation>()->GetMapIcon();
				if (icon == annotation_ptr || annotation_ptr->Title->Equals(icon->Title)) {
					mapview__->MapElements->RemoveAt(i);
					break;
				}
			}
#endif
		}

		void View::zoom(const uint32_t& zoom) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::zoom(zoom);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			if (zoom != 0) // no zoom specified in the region object?
			{
				// TODO Enforce min/max zoom levels?
				mapview__->ZoomLevel = zoom;
			}
#endif
		}

		void View::set_bottom(const std::string& bottom) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_bottom(bottom);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Bottom, bottom);
		}

		void View::set_height(const std::string& height) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_height(height);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Height, height);
		}

		void View::set_left(const std::string& left) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_left(left);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Left, left);
		}

		void View::set_layout(const std::string& layout) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_layout(layout);
			TitaniumWindows::UI::ViewBase::setLayout(layout);
		}

		void View::set_right(const std::string& right) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_right(right);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Right, right);
		}

		void View::set_top(const std::string& top) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_top(top);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Top, top);
		}

		void View::set_width(const std::string& width) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_width(width);
			TitaniumWindows::UI::ViewBase::setLayoutProperty(Titanium::LayoutEngine::ValueName::Width, width);
		}

	} // namespace Map
}  // namespace Titanium
