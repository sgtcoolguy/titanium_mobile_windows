/**
 * TitaniumKit Titanium.Map.View
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Map/View.hpp"

namespace Titanium
{
	namespace Map
	{
		View::View(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Titanium::UI::View(js_context, arguments),
			animate__(false),
			compassEnabled__(false),
			enableZoomControls__(false),
			mapType__(Titanium::Map::MAP_TYPE::NORMAL),
			region__({0}),
			pitchEnabled__(false),
			rotateEnabled__(false),
			showsBuildings__(false),
			showsPointsOfInterest__(false),
			traffic__(false),
			userLocation__(false),
			userLocationButton__(false),
			zOrderOnTop__(false)
		{
		}
		
		void View::addAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			annotations__.push_back(annotation);
			TITANIUM_LOG_WARN("Map::View::addAnnotation: Unimplemented");
		}
		
		void View::addAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT
		{
			for (Annotation_shared_ptr_t annotation : annotations) {
				addAnnotation(annotation);
			}
		}
		
		void View::addRoute(const Route_shared_ptr_t& route) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::addRoute: Unimplemented");
		}
		
		void View::animateCamera(const CameraAnimationParams& animationParams, JSObject& callback) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::animateCamera: Unimplemented");
		}
		
		void View::deselectAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::deselectAnnotation: Unimplemented");
		}
		
		void View::removeAllAnnotations() TITANIUM_NOEXCEPT
		{
			removeAnnotations(get_annotations());
		}
		
		void View::removeAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			annotations__.erase(std::remove(annotations__.begin(), annotations__.end(), annotation), annotations__.end());
			TITANIUM_LOG_WARN("Map::View::removeAnnotation: Unimplemented");
		}
		
		void View::removeAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT
		{
			for (Annotation_shared_ptr_t annotation : annotations) {
				removeAnnotation(annotation); 
			}
		}
		
		void View::removeRoute(const Route_shared_ptr_t& route) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::removeRoute: Unimplemented");
		}
		
		void View::selectAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::selectAnnotation: Unimplemented");
		}

		void View::setLocation(const MapLocationTypev2& location) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::setLocation: Unimplemented");
		}

		void View::showAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::showAnnotations: Unimplemented");
		}

		void View::snapshot() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::snapshot: Unimplemented");
		}

		void View::zoom(const uint32_t& zoom) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::zoom: Unimplemented");
		}

		// properties
		bool View::get_animate() const TITANIUM_NOEXCEPT
		{
			return animate__;
		}

		void View::set_animate(const bool& animate) TITANIUM_NOEXCEPT
		{
			animate__ = animate;
		}

		std::vector<Annotation_shared_ptr_t> View::get_annotations() const TITANIUM_NOEXCEPT
		{
			return annotations__;
		}

		void View::set_annotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT
		{
			removeAllAnnotations();
			addAnnotations(annotations);
		}

		Camera_shared_ptr_t View::get_camera() const TITANIUM_NOEXCEPT
		{
			return camera__;
		}

		void View::set_camera(const Camera_shared_ptr_t& camera) TITANIUM_NOEXCEPT
		{
			camera__ = camera;
		}

		bool View::get_compassEnabled() const TITANIUM_NOEXCEPT
		{
			return compassEnabled__;
		}

		void View::set_compassEnabled(const bool& compass) TITANIUM_NOEXCEPT
		{
			compassEnabled__ = compass;
		}

		bool View::get_enableZoomControls() const TITANIUM_NOEXCEPT
		{
			return enableZoomControls__;
		}
		
		void View::set_enableZoomControls(const bool& zoomControls) TITANIUM_NOEXCEPT
		{
			enableZoomControls__ = zoomControls;
		}

		Titanium::Map::MAP_TYPE View::get_mapType() const TITANIUM_NOEXCEPT
		{
			return mapType__;
		}

		void View::set_mapType(const Titanium::Map::MAP_TYPE& mapType) TITANIUM_NOEXCEPT
		{
			mapType__ = mapType;
		}

		uint32_t View::get_maxZoomLevel() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::get_maxZoomLevel: Unimplemented");
			return 0;
		}

		uint32_t View::get_minZoomLevel() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Map::View::get_minZoomLevel: Unimplemented");
			return 0;
		}

		bool View::get_pitchEnabled() const TITANIUM_NOEXCEPT
		{
			return pitchEnabled__;
		}

		void View::set_pitchEnabled(const bool& pitch) TITANIUM_NOEXCEPT
		{
			pitchEnabled__ = pitch;
		}

		MapRegionTypev2 View::get_region() const TITANIUM_NOEXCEPT
		{
			return region__;
		}

		void View::set_region(const MapRegionTypev2& region) TITANIUM_NOEXCEPT
		{
			region__ = region;
		}

		bool View::get_rotateEnabled() const TITANIUM_NOEXCEPT
		{
			return rotateEnabled__;
		}

		void View::set_rotateEnabled(const bool& rotate) TITANIUM_NOEXCEPT
		{
			rotateEnabled__ = rotate;
		}

		bool View::get_showsBuildings() const TITANIUM_NOEXCEPT
		{
			return showsBuildings__;
		}

		void View::set_showsBuildings(const bool& buildings) TITANIUM_NOEXCEPT
		{
			showsBuildings__ = buildings;
		}

		bool View::get_showsPointsOfInterest() const TITANIUM_NOEXCEPT
		{
			return showsPointsOfInterest__;
		}

		void View::set_showsPointsOfInterest(const bool& poi) TITANIUM_NOEXCEPT
		{
			showsPointsOfInterest__ = poi;
		}

		bool View::get_traffic() const TITANIUM_NOEXCEPT
		{
			return traffic__;
		}

		void View::set_traffic(const bool& traffic) TITANIUM_NOEXCEPT
		{
			traffic__ = traffic;
		}

		bool View::get_userLocation() const TITANIUM_NOEXCEPT
		{
			return userLocation__;
		}

		void View::set_userLocation(const bool& userLocation) TITANIUM_NOEXCEPT
		{
			userLocation__ = userLocation;
		}

		bool View::get_userLocationButton() const TITANIUM_NOEXCEPT
		{
			return userLocationButton__;
		}

		void View::set_userLocationButton(const bool& userLocationButton) TITANIUM_NOEXCEPT
		{
			userLocationButton__ = userLocationButton;
		}

		bool View::get_zOrderOnTop() const TITANIUM_NOEXCEPT
		{
			return zOrderOnTop__;
		}

		void View::set_zOrderOnTop(const bool& zOrderOnTop) TITANIUM_NOEXCEPT
		{
			zOrderOnTop__ = zOrderOnTop;
		}

		void View::JSExportInitialize() {
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Module>::Class());
			
			// methods
			JSExport<View>::AddFunctionProperty("addAnnotation", std::mem_fn(&View::js_addAnnotation));
			JSExport<View>::AddFunctionProperty("addAnnotations", std::mem_fn(&View::js_addAnnotations));
			JSExport<View>::AddFunctionProperty("addRoute", std::mem_fn(&View::js_addRoute));
			JSExport<View>::AddFunctionProperty("animateCamera", std::mem_fn(&View::js_animateCamera));
			JSExport<View>::AddFunctionProperty("deselectAnnotation", std::mem_fn(&View::js_deselectAnnotation));
			JSExport<View>::AddFunctionProperty("removeAllAnnotations", std::mem_fn(&View::js_removeAllAnnotations));
			JSExport<View>::AddFunctionProperty("removeAnnotation", std::mem_fn(&View::js_removeAnnotation));
			JSExport<View>::AddFunctionProperty("removeAnnotations", std::mem_fn(&View::js_removeAnnotations));
			JSExport<View>::AddFunctionProperty("removeRoute", std::mem_fn(&View::js_removeRoute));
			JSExport<View>::AddFunctionProperty("selectAnnotation", std::mem_fn(&View::js_selectAnnotation));
			JSExport<View>::AddFunctionProperty("setLocation", std::mem_fn(&View::js_setLocation));
			JSExport<View>::AddFunctionProperty("showAnnotations", std::mem_fn(&View::js_showAnnotations));
			JSExport<View>::AddFunctionProperty("snapshot", std::mem_fn(&View::js_snapshot));
			JSExport<View>::AddFunctionProperty("zoom", std::mem_fn(&View::js_zoom));

			// properties
			JSExport<View>::AddValueProperty("animate", std::mem_fn(&View::js_get_animate), std::mem_fn(&View::js_set_animate));
			JSExport<View>::AddValueProperty("camera", std::mem_fn(&View::js_get_camera), std::mem_fn(&View::js_set_camera));
			JSExport<View>::AddValueProperty("annotations", std::mem_fn(&View::js_get_annotations), std::mem_fn(&View::js_set_annotations));
			JSExport<View>::AddValueProperty("compassEnabled", std::mem_fn(&View::js_get_compassEnabled), std::mem_fn(&View::js_set_compassEnabled));
			JSExport<View>::AddValueProperty("enableZoomControls", std::mem_fn(&View::js_get_enableZoomControls), std::mem_fn(&View::js_set_enableZoomControls));
			JSExport<View>::AddValueProperty("mapType", std::mem_fn(&View::js_get_mapType), std::mem_fn(&View::js_set_mapType));
			JSExport<View>::AddValueProperty("maxZoomLevel", std::mem_fn(&View::js_get_maxZoomLevel));
			JSExport<View>::AddValueProperty("minZoomLevel", std::mem_fn(&View::js_get_minZoomLevel));
			JSExport<View>::AddValueProperty("pitchEnabled", std::mem_fn(&View::js_get_pitchEnabled), std::mem_fn(&View::js_set_pitchEnabled));
			JSExport<View>::AddValueProperty("region", std::mem_fn(&View::js_get_region), std::mem_fn(&View::js_set_region));
			JSExport<View>::AddValueProperty("rotateEnabled", std::mem_fn(&View::js_get_rotateEnabled), std::mem_fn(&View::js_set_rotateEnabled));
			JSExport<View>::AddValueProperty("showsBuildings", std::mem_fn(&View::js_get_showsBuildings), std::mem_fn(&View::js_set_showsBuildings));
			JSExport<View>::AddValueProperty("showsPointsOfInterest", std::mem_fn(&View::js_get_showsPointsOfInterest), std::mem_fn(&View::js_set_showsPointsOfInterest));
			JSExport<View>::AddValueProperty("traffic", std::mem_fn(&View::js_get_traffic), std::mem_fn(&View::js_set_traffic));
			JSExport<View>::AddValueProperty("userLocation", std::mem_fn(&View::js_get_userLocation), std::mem_fn(&View::js_set_userLocation));
			JSExport<View>::AddValueProperty("userLocationButton", std::mem_fn(&View::js_get_userLocationButton), std::mem_fn(&View::js_set_userLocationButton));
			JSExport<View>::AddValueProperty("zOrderOnTop", std::mem_fn(&View::js_get_zOrderOnTop), std::mem_fn(&View::js_set_zOrderOnTop));

			// prperty setter functions
			JSExport<View>::AddFunctionProperty("setCamera", std::mem_fn(&View::js_setCamera));
			JSExport<View>::AddFunctionProperty("setAnnotations", std::mem_fn(&View::js_setAnnotations));
			JSExport<View>::AddFunctionProperty("setAnimate", std::mem_fn(&View::js_setAnimate));
			JSExport<View>::AddFunctionProperty("setCompassEnabled", std::mem_fn(&View::js_setCompassEnabled));
			JSExport<View>::AddFunctionProperty("setEnableZoomControls", std::mem_fn(&View::js_setEnableZoomControls));
			JSExport<View>::AddFunctionProperty("setMapType", std::mem_fn(&View::js_setMapType));
			JSExport<View>::AddFunctionProperty("setPitchEnabled", std::mem_fn(&View::js_setPitchEnabled));
			JSExport<View>::AddFunctionProperty("setRegion", std::mem_fn(&View::js_setRegion));
			JSExport<View>::AddFunctionProperty("setRotateEnabled", std::mem_fn(&View::js_setRotateEnabled));
			JSExport<View>::AddFunctionProperty("setShowsBuildings", std::mem_fn(&View::js_setShowsBuildings));
			JSExport<View>::AddFunctionProperty("setShowsPointsOfInterest", std::mem_fn(&View::js_setShowsPointsOfInterest));
			JSExport<View>::AddFunctionProperty("setTraffic", std::mem_fn(&View::js_setTraffic));
			JSExport<View>::AddFunctionProperty("setUserLocation", std::mem_fn(&View::js_setUserLocation));
			JSExport<View>::AddFunctionProperty("setUserLocationButton", std::mem_fn(&View::js_setUserLocationButton));
			JSExport<View>::AddFunctionProperty("setZOrderOnTop", std::mem_fn(&View::js_setZOrderOnTop));
		}

		JSValue View::js_addAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);

			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			addAnnotation(static_cast<JSObject>(_0).GetPrivate<Annotation>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_addAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() > 0);

			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			const auto _0Obj = static_cast<JSObject>(_0);
			TITANIUM_ASSERT(_0Obj.IsArray());
			const auto annotations = static_cast<JSArray>(_0Obj);
			addAnnotations(annotations.GetPrivateItems<Annotation>());
			return get_context().CreateUndefined();
		}

		JSValue View::js_addRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);

			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			addRoute(static_cast<JSObject>(_0).GetPrivate<Route>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_animateCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() > 1) {
				auto _0 = arguments.at(0);
				auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_0.IsObject());
				TITANIUM_ASSERT(_1.IsObject());
				auto callback = static_cast<JSObject>(_1);
				animateCamera(js_to_CameraAnimationParams(static_cast<JSObject>(_0)), callback);
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_deselectAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);

			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			deselectAnnotation(static_cast<JSObject>(_0).GetPrivate<Annotation>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_removeAllAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			removeAllAnnotations();
			return get_context().CreateUndefined();
		}

		JSValue View::js_removeAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);

			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			removeAnnotation(static_cast<JSObject>(_0).GetPrivate<Annotation>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_removeAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() > 0);

			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			const auto _0Obj = static_cast<JSObject>(_0);
			TITANIUM_ASSERT(_0Obj.IsArray());
			const auto annotations = static_cast<JSArray>(_0Obj);
			removeAnnotations(annotations.GetPrivateItems<Annotation>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_removeRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			removeRoute(static_cast<JSObject>(_0).GetPrivate<Route>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_selectAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			selectAnnotation(static_cast<JSObject>(_0).GetPrivate<Annotation>());
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_setLocation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			setLocation(js_to_MapLocationTypev2(static_cast<JSObject>(_0)));
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_showAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() > 0);
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			const auto _0Obj = static_cast<JSObject>(_0);
			TITANIUM_ASSERT(_0Obj.IsArray());
			const auto annotations = static_cast<JSArray>(_0Obj);
			showAnnotations(annotations.GetPrivateItems<Annotation>());
			return get_context().CreateUndefined();
		}

		JSValue View::js_snapshot(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			snapshot();
			return get_context().CreateUndefined();
		}

		JSValue View::js_zoom(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsNumber());
			zoom(static_cast<uint32_t>(_0));
			
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_animate() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_animate());
		}

		bool View::js_set_animate(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_animate(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_get_annotations() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> js_annotations;
			const auto annotations = get_annotations();
			for (auto annotation : annotations) {
				js_annotations.push_back(annotation->get_object());
			}
			return get_context().CreateArray(js_annotations);
		}

		bool View::js_set_annotations(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			if (!argument.IsObject()) {
				return false;
			}
			const auto annotations = static_cast<JSObject>(argument);
			if (!annotations.IsArray()) {
				return false;
			}
			set_annotations(static_cast<JSArray>(annotations).GetPrivateItems<Annotation>());
			return true;
		}

		JSValue View::js_get_camera() const TITANIUM_NOEXCEPT
		{
			return get_camera()->get_object();
		}

		bool View::js_set_camera(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_camera(static_cast<JSObject>(argument).GetPrivate<Camera>());
			return true;
		}

		JSValue View::js_setAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_annotations(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_setCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_camera(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_setAnimate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_animate(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_enableZoomControls() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_enableZoomControls());
		}

		bool View::js_set_enableZoomControls(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_enableZoomControls(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setEnableZoomControls(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_enableZoomControls(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_compassEnabled() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_compassEnabled());
		}

		bool View::js_set_compassEnabled(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_compassEnabled(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setCompassEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_compassEnabled(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_mapType() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(get_mapType()));
		}

		bool View::js_set_mapType(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_mapType(Titanium::Map::Constants::to_MAP_TYPE(static_cast<std::underlying_type<Titanium::Map::MAP_TYPE>::type>(argument)));
			return true;
		}

		JSValue View::js_setMapType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_mapType(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_maxZoomLevel() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_maxZoomLevel());
		}

		JSValue View::js_get_minZoomLevel() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_minZoomLevel());
		}

		JSValue View::js_get_pitchEnabled() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_pitchEnabled());
		}

		bool View::js_set_pitchEnabled(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_pitchEnabled(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setPitchEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_pitchEnabled(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_region() const TITANIUM_NOEXCEPT
		{
			return MapRegionTypev2_to_js(get_context(), get_region());
		}

		bool View::js_set_region(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			const auto region = static_cast<JSObject>(argument);
			set_region(js_to_MapRegionTypev2(region));
			return true;
		}

		JSValue View::js_setRegion(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_region(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_rotateEnabled() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_rotateEnabled());
		}

		bool View::js_set_rotateEnabled(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_rotateEnabled(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setRotateEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_rotateEnabled(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_showsBuildings() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_showsBuildings());
		}

		bool View::js_set_showsBuildings(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showsBuildings(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setShowsBuildings(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_showsBuildings(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_showsPointsOfInterest() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_showsPointsOfInterest());
		}

		bool View::js_set_showsPointsOfInterest(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showsPointsOfInterest(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setShowsPointsOfInterest(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_showsPointsOfInterest(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_traffic() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_traffic());
		}

		bool View::js_set_traffic(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_traffic(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setTraffic(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_traffic(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_userLocation() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_userLocation());
		}

		bool View::js_set_userLocation(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_userLocation(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setUserLocation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_userLocation(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_userLocationButton() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_userLocationButton());
		}

		bool View::js_set_userLocationButton(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_userLocationButton(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setUserLocationButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_userLocationButton(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_zOrderOnTop() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_zOrderOnTop());
		}

		bool View::js_set_zOrderOnTop(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_zOrderOnTop(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_setZOrderOnTop(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_zOrderOnTop(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

	} // namespace Map
}  // namespace Titanium