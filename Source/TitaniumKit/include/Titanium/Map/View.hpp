/**
 * TitaniumKit Titanium.Map.View
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MAP_VIEW_HPP_
#define _TITANIUM_MAP_VIEW_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/Map/Constants.hpp"
#include "Titanium/Map/MapRegionTypev2.hpp"
#include "Titanium/Map/MapLocationTypev2.hpp"
#include "Titanium/Map/CameraAnimationParams.hpp"
#include "Titanium/Map/Annotation.hpp"
#include "Titanium/Map/Route.hpp"
#include "Titanium/Map/Camera.hpp"

#include <vector>

namespace Titanium 
{
	namespace Map
	{
		using namespace HAL;
		using Annotation_shared_ptr_t = std::shared_ptr<Annotation>;
		using Route_shared_ptr_t = std::shared_ptr<Route>;
		using Camera_shared_ptr_t = std::shared_ptr<Camera>;

		/*!
		  @class
		  @discussion This is the Titanium Map View Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Modules.Map.View
		 */
		class TITANIUMKIT_EXPORT View : public Titanium::UI::View, public JSExport<View> 
		{

		public:

			// properties
			virtual bool get_animate() const TITANIUM_NOEXCEPT final;
			virtual void set_animate(const bool& animate) TITANIUM_NOEXCEPT;

			virtual std::vector<Annotation_shared_ptr_t> get_annotations() const TITANIUM_NOEXCEPT final;
			virtual void set_annotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT;

			virtual Camera_shared_ptr_t get_camera() const TITANIUM_NOEXCEPT final;
			virtual void set_camera(const Camera_shared_ptr_t& camera) TITANIUM_NOEXCEPT;

			virtual bool get_compassEnabled() const TITANIUM_NOEXCEPT final;
			virtual void set_compassEnabled(const bool& compass) TITANIUM_NOEXCEPT;

			virtual bool get_enableZoomControls() const TITANIUM_NOEXCEPT final;
			virtual void set_enableZoomControls(const bool& zoomControls) TITANIUM_NOEXCEPT;

			virtual Titanium::Map::MAP_TYPE get_mapType() const TITANIUM_NOEXCEPT final;
			virtual void set_mapType(const Titanium::Map::MAP_TYPE& mapType) TITANIUM_NOEXCEPT;

			virtual uint32_t get_maxZoomLevel() const TITANIUM_NOEXCEPT;

			virtual uint32_t get_minZoomLevel() const TITANIUM_NOEXCEPT;

			virtual bool get_pitchEnabled() const TITANIUM_NOEXCEPT final;
			virtual void set_pitchEnabled(const bool& pitch) TITANIUM_NOEXCEPT;

			virtual MapRegionTypev2 get_region() const TITANIUM_NOEXCEPT final;
			virtual void set_region(const MapRegionTypev2& region) TITANIUM_NOEXCEPT;

			virtual bool get_rotateEnabled() const TITANIUM_NOEXCEPT final;
			virtual void set_rotateEnabled(const bool& rotate) TITANIUM_NOEXCEPT;

			virtual bool get_showsBuildings() const TITANIUM_NOEXCEPT final;
			virtual void set_showsBuildings(const bool& buildings) TITANIUM_NOEXCEPT;

			virtual bool get_showsPointsOfInterest() const TITANIUM_NOEXCEPT final;
			virtual void set_showsPointsOfInterest(const bool& poi) TITANIUM_NOEXCEPT;

			virtual bool get_traffic() const TITANIUM_NOEXCEPT final;
			virtual void set_traffic(const bool& traffic) TITANIUM_NOEXCEPT;

			virtual bool get_userLocation() const TITANIUM_NOEXCEPT final;
			virtual void set_userLocation(const bool& userLocation) TITANIUM_NOEXCEPT;

			virtual bool get_userLocationButton() const TITANIUM_NOEXCEPT final;
			virtual void set_userLocationButton(const bool& userLocationButton) TITANIUM_NOEXCEPT;

			virtual bool get_zOrderOnTop() const TITANIUM_NOEXCEPT final;
			virtual void set_zOrderOnTop(const bool& zOrderOnTop) TITANIUM_NOEXCEPT;

			// Methods
			virtual void addAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT;
			virtual void addAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT;
			virtual void addRoute(const Route_shared_ptr_t& route) TITANIUM_NOEXCEPT;
			virtual void animateCamera(const CameraAnimationParams& animationParams, JSObject& callback) TITANIUM_NOEXCEPT;
			virtual void deselectAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT;
			virtual void removeAllAnnotations() TITANIUM_NOEXCEPT;
			virtual void removeAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT;
			virtual void removeAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT;
			virtual void removeRoute(const Route_shared_ptr_t& route) TITANIUM_NOEXCEPT;
			virtual void selectAnnotation(const Annotation_shared_ptr_t& annotation) TITANIUM_NOEXCEPT;
			virtual void setLocation(const MapLocationTypev2& location) TITANIUM_NOEXCEPT;
			virtual void showAnnotations(const std::vector<Annotation_shared_ptr_t>& annotations) TITANIUM_NOEXCEPT;
			virtual void snapshot() TITANIUM_NOEXCEPT;
			virtual void zoom(const uint32_t& level) TITANIUM_NOEXCEPT;

			View(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~View() = default;
			View(const View&) = default;
			View& operator=(const View&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			View(View&&)                 = default;
			View& operator=(View&&)      = default;
#endif

			static void JSExportInitialize();
			
			virtual JSValue js_addAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_addAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_addRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_animateCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_deselectAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_removeAllAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_removeAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_removeAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_removeRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_selectAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLocation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_showAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_snapshot(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_zoom(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_animate() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_animate(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setAnimate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_annotations() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_annotations(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setAnnotations(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_camera() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_camera(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_compassEnabled() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_compassEnabled(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setCompassEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_enableZoomControls() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_enableZoomControls(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setEnableZoomControls(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_mapType() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_mapType(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setMapType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_maxZoomLevel() const TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_minZoomLevel() const TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_pitchEnabled() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_pitchEnabled(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setPitchEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_region() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_region(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRegion(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_rotateEnabled() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_rotateEnabled(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRotateEnabled(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_showsBuildings() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_showsBuildings(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setShowsBuildings(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_showsPointsOfInterest() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_showsPointsOfInterest(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setShowsPointsOfInterest(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_traffic() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_traffic(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setTraffic(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_userLocation() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_userLocation(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setUserLocation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_userLocationButton() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_userLocationButton(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setUserLocationButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_zOrderOnTop() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_zOrderOnTop(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setZOrderOnTop(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			bool animate__;
			std::vector<Annotation_shared_ptr_t> annotations__;
			Camera_shared_ptr_t camera__;
			bool compassEnabled__;
			bool enableZoomControls__;
			Titanium::Map::MAP_TYPE mapType__;
			bool pitchEnabled__;
			MapRegionTypev2 region__;
			bool rotateEnabled__;
			bool showsBuildings__;
			bool showsPointsOfInterest__;
			bool traffic__;
			bool userLocation__;
			bool userLocationButton__;
			bool zOrderOnTop__;
#pragma warning(pop)
		};
	} // namespace Map
}  // namespace Titanium
#endif // _TITANIUM_MAP_VIEW_HPP_