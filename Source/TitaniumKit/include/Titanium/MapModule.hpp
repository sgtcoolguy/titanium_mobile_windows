/**
 * Titanium.Map for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MAP_HPP_
#define _TITANIUM_MAP_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Map/Constants.hpp"
#include "Titanium/Map/Annotation.hpp"
#include "Titanium/Map/Camera.hpp"
#include "Titanium/Map/Route.hpp"
#include "Titanium/Map/View.hpp"

namespace Titanium
{
	using namespace HAL;

	using Map_Annotation_shared_ptr_t = std::shared_ptr<Titanium::Map::Annotation>;
	using Map_Camera_shared_ptr_t = std::shared_ptr<Titanium::Map::Camera>;
	using Map_Route_shared_ptr_t = std::shared_ptr<Titanium::Map::Route>;
	using Map_View_shared_ptr_t = std::shared_ptr<Titanium::Map::View>;

	/*!
	  @class
	  @discussion This is the Titanium Map Module.
	  See http://docs.appcelerator.com/titanium/3.0/#!/api/Modules.Map
	*/
	class TITANIUMKIT_EXPORT MapModule : public Module, public JSExport<MapModule>
	{

	public:

		/*!
		  @method
		  @abstract createAnnotation
		  @discussion Creates and returns an instance of <Titanium.Map.Annotation>.
		*/
		virtual Map_Annotation_shared_ptr_t createAnnotation(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createCamera
		  @discussion Creates and returns an instance of <Titanium.Map.Camera>.
		*/
		virtual Map_Camera_shared_ptr_t createCamera(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createRoute
		  @discussion Creates and returns an instance of <Titanium.Map.Route>.
		*/
		virtual Map_Route_shared_ptr_t createRoute(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createMapView
		  @discussion Creates and returns an instance of <Titanium.Map.View>.
		*/
		virtual Map_View_shared_ptr_t createView(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract isGooglePlayServicesAvailable
		  @discussion Returns a code to indicate whether Google Play Services is available on the device.
		*/
		Titanium::Map::GOOGLE_PLAY_SERVICE_STATE isGooglePlayServicesAvailable() TITANIUM_NOEXCEPT;

		MapModule(const JSContext&) TITANIUM_NOEXCEPT;
		virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

		virtual ~MapModule() = default;
		MapModule(const MapModule&) = default;
		MapModule& operator=(const MapModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		MapModule(MapModule&&)                 = default;
		MapModule& operator=(MapModule&&)      = default;
#endif

		static void JSExportInitialize();

		virtual JSValue js_get_HYBRID_TYPE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_SATELLITE_TYPE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_NORMAL_TYPE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_TERRAIN_TYPE() const TITANIUM_NOEXCEPT final;

		virtual JSValue js_get_ANNOTATION_DRAG_STATE_END() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_DRAG_STATE_START() const TITANIUM_NOEXCEPT final;

		virtual JSValue js_get_ANNOTATION_AZURE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_BLUE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_CYAN() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_GREEN() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_MAGENTA() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_ORANGE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_PURPLE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_RED() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_ROSE() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_VIOLET() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_ANNOTATION_YELLOW() const TITANIUM_NOEXCEPT final;

		virtual JSValue js_get_OVERLAY_LEVEL_ABOVE_LABELS() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_OVERLAY_LEVEL_ABOVE_ROADS() const TITANIUM_NOEXCEPT final;

		virtual JSValue js_get_SERVICE_DISABLED() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_SERVICE_INVALID() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_SERVICE_MISSING() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_SERVICE_VERSION_UPDATE_REQUIRED() const TITANIUM_NOEXCEPT final;
		virtual JSValue js_get_SUCCESS() const TITANIUM_NOEXCEPT final;

		virtual JSValue js_createAnnotation(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createCamera(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createRoute(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_isGooglePlayServicesAvailable(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
	};
} // namespace Titanium
#endif // _TITANIUM_MAP_HPP_