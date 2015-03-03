/**
 * Titanium.Map.View for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Map/View.hpp"
#include "TitaniumWindows/Utility.hpp"

using namespace Windows::Devices::Geolocation;

namespace TitaniumWindows
{
	namespace Map
	{
		View::View(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::Map::View(js_context, arguments),
			mapview__(ref new MapControl())
		{
			TITANIUM_LOG_DEBUG("View::ctor Initialize");

			// Set service token
			// TODO : Load this from app properties, windows_map_service_token?
			mapview__->MapServiceToken = "VrSrmXR8B5bgklWrs0CK_w";

			// Layout engine
			TitaniumWindows::UI::ViewBase::setDefaultHeight(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			TitaniumWindows::UI::ViewBase::setDefaultWidth(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			TitaniumWindows::UI::ViewBase::setComponent(mapview__);

			zoom(12); // use a default zoom of 12 for Windows?
		}

		View::~View()
		{
			mapview__ = nullptr;
		}

		void View::JSExportInitialize() 
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::Map::View>::Class());
		}

		uint32_t View::get_maxZoomLevel() const TITANIUM_NOEXCEPT
		{
			return static_cast<uint32_t>(mapview__->MaxZoomLevel); // should be 20
		}

		uint32_t View::get_minZoomLevel() const TITANIUM_NOEXCEPT
		{
			return static_cast<uint32_t>(mapview__->MinZoomLevel); // should be 1
		}

		void View::set_mapType(const Titanium::Map::MAP_TYPE& mapType) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_mapType(mapType);
			if (mapType == Titanium::Map::MAP_TYPE::HYBRID) {
				mapview__->Style = MapStyle::AerialWithRoads;
			} else if (mapType == Titanium::Map::MAP_TYPE::SATELLITE) {
				mapview__->Style = MapStyle::Aerial;
			} else if (mapType == Titanium::Map::MAP_TYPE::NORMAL) {
				mapview__->Style = MapStyle::Road;
			}
		}

		void View::set_region(const Titanium::Map::MapRegionTypev2& region) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_region(region);
			
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
		}

		void View::set_showsBuildings(const bool& buildings) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_showsBuildings(buildings);
			mapview__->LandmarksVisible = buildings;
		}

		void View::set_traffic(const bool& traffic) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::set_traffic(traffic);
			mapview__->TrafficFlowVisible = traffic;
		}

		void View::addAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::addAnnotation(annotation);
			BasicGeoposition bgp = { annotation->get_latitude(), annotation->get_longitude() };
			auto gp = ref new Geopoint(bgp);

			auto mapIcon1 = ref new MapIcon();
			mapIcon1->Title = TitaniumWindows::Utility::ConvertString(annotation->get_title());
			mapIcon1->Location = gp;
			mapIcon1->NormalizedAnchorPoint = Windows::Foundation::Point(0.5, 1.0);
			mapIcon1->ZIndex = 2;
			mapview__->MapElements->Append(mapIcon1);
		}

		void View::removeAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::removeAnnotation(annotation);

			for (size_t i = 0; i < mapview__->MapElements->Size; i++) {
				auto element = mapview__->MapElements->GetAt(i);
				MapIcon^ icon = dynamic_cast<MapIcon^>(element);
				if (icon == nullptr) {
					continue; // not an annotation
				}
				// Determine if the icon matches the annotation!
				if (annotation->get_latitude() != icon->Location->Position.Latitude) {
					continue; // latitude doesn't match
				}
				if (annotation->get_longitude() != icon->Location->Position.Longitude) {
					continue; // longitude doesn't match
				}
				// FIXME Title is optional!
				if (!TitaniumWindows::Utility::ConvertString(annotation->get_title())->Equals(icon->Title)) {
					continue; // title doesn't match
				}
				// match, let's get rid of it!
				mapview__->MapElements->RemoveAt(i);
				break;
			}
		}

		void View::zoom(const uint32_t& zoom) TITANIUM_NOEXCEPT
		{
			Titanium::Map::View::zoom(zoom);
			if (zoom != 0) // no zoom specified in the region object?
			{
				// TODO Enforce min/max zoom levels?
				mapview__->ZoomLevel = zoom;
			}
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
