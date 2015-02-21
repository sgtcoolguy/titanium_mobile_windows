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
			mapType__(get_context().CreateNumber(0)),
			region__({0}),
			zoomLevel__(0)
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

		int MapView::mapType() const TITANIUM_NOEXCEPT {
			return mapType__;
		}

		void MapView::setMapType(int mapType) TITANIUM_NOEXCEPT {
			mapType__ = mapType;
			OnSetMapType();
		}

		void MapView::OnSetMapType() TITANIUM_NOEXCEPT {
		}

		MapView::MapRegionType MapView::getMapRegionType(JSObject& mapRegionType) {
			MapRegionType region;

			region.latitude = static_cast<double>(mapRegionType.GetProperty("latitude"));
			region.latitudeDelta = static_cast<double>(mapRegionType.GetProperty("latitudeDelta"));
			region.longitude = static_cast<double>(mapRegionType.GetProperty("longitude"));
			region.longitudeDelta = static_cast<double>(mapRegionType.GetProperty("longitudeDelta"));

			return region;
		}

		JSValue MapView::region() const TITANIUM_NOEXCEPT {
			JSObject region = get_context().CreateObject();

			region.SetProperty("latitude", get_context().CreateNumber(region__.latitude));
			region.SetProperty("latitudeDelta", get_context().CreateNumber(region__.latitudeDelta));
			region.SetProperty("longitude", get_context().CreateNumber(region__.longitude));
			region.SetProperty("longitudeDelta", get_context().CreateNumber(region__.longitudeDelta));

			return static_cast<JSValue>(region);
		}

		void MapView::setRegion(JSObject region) TITANIUM_NOEXCEPT {
			region__ = getMapRegionType(region);
			OnSetRegion();
		}

		void MapView::OnSetRegion() TITANIUM_NOEXCEPT {
		}

		void MapView::setZoomLevel(int zoom) TITANIUM_NOEXCEPT {
			zoomLevel__ = zoom;
		}

		JSValue MapView::addAnnotation(JSObject& annotation) TITANIUM_NOEXCEPT {
			return get_context().CreateUndefined();
		}

		JSValue MapView::js_get_mapType() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(mapType());
		}

		bool MapView::js_set_mapType(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			setMapType(static_cast<int>(argument));
			return true;
		}

		JSValue MapView::js_setMapType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				auto _0 = arguments[0];
				TITANIUM_ASSERT(_0.IsNumber());
				setMapType(static_cast<int>(_0));
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
				setZoomLevel(static_cast<int>(_0));
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
}  // namespace Titanium