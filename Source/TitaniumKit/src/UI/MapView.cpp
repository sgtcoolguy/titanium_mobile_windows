/**
 * TitaniumKit Titanium.UI.MapView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/MapView.hpp"

namespace Titanium
{
	namespace UI
	{
		MapView::MapView(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: View(js_context, arguments),
			mapType__(Titanium::Map::MAP_TYPE::NORMAL),
			region__({0}),
			zoom__(16)
		{
		}

		void MapView::JSExportInitialize() {
			JSExport<MapView>::SetClassVersion(1);
			JSExport<MapView>::SetParent(JSExport<Module>::Class());

			JSExport<MapView>::AddValueProperty("mapType", std::mem_fn(&js_get_mapType), std::mem_fn(&js_set_mapType));
			JSExport<MapView>::AddFunctionProperty("setMapType", std::mem_fn(&js_setMapType));

			JSExport<MapView>::AddValueProperty("region", std::mem_fn(&js_get_region), std::mem_fn(&js_set_region));
			JSExport<MapView>::AddFunctionProperty("setRegion", std::mem_fn(&js_setRegion));

			JSExport<MapView>::AddFunctionProperty("zoom", std::mem_fn(&js_setZoomLevel));
		}

		Titanium::Map::MAP_TYPE MapView::mapType() const TITANIUM_NOEXCEPT {
			return mapType__;
		}

		void MapView::setMapType(Titanium::Map::MAP_TYPE mapType) TITANIUM_NOEXCEPT {
			mapType__ = mapType;
		}

		MapView::MapRegionType MapView::getMapRegionType(JSObject& mapRegionType) {
			MapRegionType region;

			region.bearing = static_cast<double>(mapRegionType.GetProperty("bearing"));
			region.latitude = static_cast<double>(mapRegionType.GetProperty("latitude"));
			region.latitudeDelta = static_cast<double>(mapRegionType.GetProperty("latitudeDelta"));
			region.longitude = static_cast<double>(mapRegionType.GetProperty("longitude"));
			region.longitudeDelta = static_cast<double>(mapRegionType.GetProperty("longitudeDelta"));
			region.tilt = static_cast<double>(mapRegionType.GetProperty("tilt"));
			region.zoom = static_cast<double>(mapRegionType.GetProperty("zoom"));

			return region;
		}

		JSValue MapView::region() const TITANIUM_NOEXCEPT {
			JSObject region = get_context().CreateObject();

			region.SetProperty("bearing", get_context().CreateNumber(region__.bearing));
			region.SetProperty("latitude", get_context().CreateNumber(region__.latitude));
			region.SetProperty("latitudeDelta", get_context().CreateNumber(region__.latitudeDelta));
			region.SetProperty("longitude", get_context().CreateNumber(region__.longitude));
			region.SetProperty("longitudeDelta", get_context().CreateNumber(region__.longitudeDelta));
			region.SetProperty("tilt", get_context().CreateNumber(region__.tilt));
			region.SetProperty("zoom", get_context().CreateNumber(region__.zoom));

			return static_cast<JSValue>(region);
		}

		void MapView::setRegion(JSObject& region) TITANIUM_NOEXCEPT {
			region__ = getMapRegionType(region);
		}

		void MapView::setZoom(int zoom) TITANIUM_NOEXCEPT {
			zoom__ = zoom;
		}

		JSValue MapView::addAnnotation(JSObject& annotation) TITANIUM_NOEXCEPT {
			return get_context().CreateUndefined();
		}

		JSValue MapView::js_get_mapType() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(mapType()));
		}

		bool MapView::js_set_mapType(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			setMapType(Titanium::Map::Constants::to_MAP_TYPE(static_cast<std::underlying_type<Titanium::Map::MAP_TYPE>::type>(argument)));
			return true;
		}

		JSValue MapView::js_setMapType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				auto _0 = arguments[0];
				TITANIUM_ASSERT(_0.IsNumber());
				setMapType(Titanium::Map::Constants::to_MAP_TYPE(static_cast<std::underlying_type<Titanium::Map::MAP_TYPE>::type>(_0)));
			}
			return get_context().CreateUndefined();
		}

		JSValue MapView::js_get_region() const TITANIUM_NOEXCEPT
		{
			return region();
		}

		bool MapView::js_set_region(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			setRegion(static_cast<JSObject>(argument));
			return true;
		}

		JSValue MapView::js_setRegion(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				auto _0 = arguments[0];
				TITANIUM_ASSERT(_0.IsObject());
				setRegion(static_cast<JSObject>(_0));
			}
			return get_context().CreateUndefined();
		}

		JSValue MapView::js_setZoomLevel(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				auto _0 = arguments[0];
				TITANIUM_ASSERT(_0.IsNumber());
				setZoom(static_cast<int>(_0));
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
}  // namespace Titanium