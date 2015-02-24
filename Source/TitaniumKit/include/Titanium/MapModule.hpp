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

namespace Titanium
{
	using namespace HAL;

	/*!
	  @class
	  @discussion This is the Titanium Map Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.MapModule
	*/
	class TITANIUMKIT_EXPORT MapModule : public Module, public JSExport<MapModule>
	{

	public:

		enum class MapType {
			HYBRID_TYPE,
			SATELLITE_TYPE,
			STANDARD_TYPE,
			TERRAIN_TYPE
		};

		enum class AnnotationType {
			ANNOTATION_DRAG_STATE_CANCEL,
			ANNOTATION_DRAG_STATE_DRAG,
			ANNOTATION_DRAG_STATE_END,
			ANNOTATION_DRAG_STATE_NONE,
			ANNOTATION_DRAG_STATE_START,
			ANNOTATION_GREEN,
			ANNOTATION_PURPLE,
			ANNOTATION_RED
		};

		enum class OverlayType {
			OVERLAY_LEVEL_ABOVE_LABELS,
			OVERLAY_LEVEL_ABOVE_ROADS
		};

		enum class ServiceType {
			SERVICE_DISABLED,
			SERVICE_INVALID,
			SERVICE_MISSING,
			SERVICE_VERSION_UPDATE_REQUIRED
		};

		virtual JSValue HYBRID_TYPE() const TITANIUM_NOEXCEPT;
		virtual JSValue SATELLITE_TYPE() const TITANIUM_NOEXCEPT;
		virtual JSValue STANDARD_TYPE() const TITANIUM_NOEXCEPT;
		virtual JSValue TERRAIN_TYPE() const TITANIUM_NOEXCEPT;

		virtual JSValue ANNOTATION_DRAG_STATE_CANCEL() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_DRAG_STATE_DRAG() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_DRAG_STATE_END() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_DRAG_STATE_NONE() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_DRAG_STATE_START() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_GREEN() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_PURPLE() const TITANIUM_NOEXCEPT;
		virtual JSValue ANNOTATION_RED() const TITANIUM_NOEXCEPT;

		virtual JSValue OVERLAY_LEVEL_ABOVE_LABELS() const TITANIUM_NOEXCEPT;
		virtual JSValue OVERLAY_LEVEL_ABOVE_ROADS() const TITANIUM_NOEXCEPT;

		virtual JSValue SERVICE_DISABLED() const TITANIUM_NOEXCEPT;
		virtual JSValue SERVICE_INVALID() const TITANIUM_NOEXCEPT;
		virtual JSValue SERVICE_MISSING() const TITANIUM_NOEXCEPT;
		virtual JSValue SERVICE_VERSION_UPDATE_REQUIRED() const TITANIUM_NOEXCEPT;

		virtual JSValue SUCCESS() const TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createMapView
		  @discussion Creates and returns an instance of <Titanium.Map.View>.
		*/
		virtual JSValue createView(JSObject parameters) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createAnnotation
		  @discussion Creates and returns an instance of <Titanium.Map.Annotation>.
		*/
		virtual JSValue createAnnotation(JSObject parameters) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createRoute
		  @discussion Creates and returns an instance of <Titanium.Map.View>.
		*/
		virtual JSValue createRoute(JSObject parameters) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract createCamera
		  @discussion Creates and returns an instance of <Titanium.Map.View>.
		*/
		virtual JSValue createCamera(JSObject parameters) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract isGooglePlayServicesAvailable
		  @discussion Creates and returns an instance of <Titanium.Map.View>.
		*/
		virtual JSValue isGooglePlayServicesAvailable() TITANIUM_NOEXCEPT;

		MapModule(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
		virtual ~MapModule() = default;
		MapModule(const MapModule&) = default;
		MapModule& operator=(const MapModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		MapModule(MapModule&&)                 = default;
		MapModule& operator=(MapModule&&)      = default;
#endif

		static void JSExportInitialize();

		virtual JSValue js_createView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createAnnotation(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createRoute(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_createCamera(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
		virtual JSValue js_isGoogleMapServicesAvailable(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)

#pragma warning(pop)

	private:
		JSValue hybrid_type__;
		JSValue satellite_type__;
		JSValue standard_type__;
		JSValue terrain_type__;
		JSValue annotation_drag_state_cancel__;
		JSValue annotation_drag_state_drag__;
		JSValue annotation_drag_state_end__;
		JSValue annotation_drag_state_none__;
		JSValue annotation_drag_state_start__;
		JSValue annotation_green__;
		JSValue annotation_purple__;
		JSValue annotation_red__;
		JSValue overlay_level_above_labels__;
		JSValue overlay_level_above_roads__;
		JSValue service_disabled__;
		JSValue service_invalid__;
		JSValue service_missing__;
		JSValue service_version_update_required__;
		JSValue success__;
	};
} // namespace Titanium
#endif // _TITANIUM_MAP_HPP_