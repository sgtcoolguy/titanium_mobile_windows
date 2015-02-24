/**
 * Titanium.Map for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/MapModule.hpp"

namespace Titanium
{
    MapModule::MapModule(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
        : Module(js_context, arguments),
		hybrid_type__(get_context().CreateNumber(static_cast<int>(MapType::HYBRID_TYPE))),
		satellite_type__(get_context().CreateNumber(static_cast<int>(MapType::SATELLITE_TYPE))),
		standard_type__(get_context().CreateNumber(static_cast<int>(MapType::STANDARD_TYPE))),
		terrain_type__(get_context().CreateNumber(static_cast<int>(MapType::TERRAIN_TYPE))),
		annotation_drag_state_cancel__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_DRAG_STATE_CANCEL))),
		annotation_drag_state_drag__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_DRAG_STATE_DRAG))),
		annotation_drag_state_end__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_DRAG_STATE_END))),
		annotation_drag_state_none__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_DRAG_STATE_NONE))),
		annotation_drag_state_start__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_DRAG_STATE_START))),
		annotation_green__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_GREEN))),
		annotation_purple__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_PURPLE))),
		annotation_red__(get_context().CreateNumber(static_cast<int>(AnnotationType::ANNOTATION_RED))),
		overlay_level_above_labels__(get_context().CreateNumber(static_cast<int>(OverlayType::OVERLAY_LEVEL_ABOVE_LABELS))),
		overlay_level_above_roads__(get_context().CreateNumber(static_cast<int>(OverlayType::OVERLAY_LEVEL_ABOVE_ROADS))),
		service_disabled__(get_context().CreateNumber(static_cast<int>(ServiceType::SERVICE_DISABLED))),
		service_invalid__(get_context().CreateNumber(static_cast<int>(ServiceType::SERVICE_INVALID))),
		service_missing__(get_context().CreateNumber(static_cast<int>(ServiceType::SERVICE_MISSING))),
		service_version_update_required__(get_context().CreateNumber(static_cast<int>(ServiceType::SERVICE_VERSION_UPDATE_REQUIRED))),
		success__(get_context().CreateNumber(0))
    {
	}

	static void applyProperties(JSObject& view, const JSObject& parameters)
	{
		if (parameters.GetPropertyNames().GetCount() > 0) {
			const auto propertyNames = parameters.GetPropertyNames();
			for (const auto& property_name : static_cast<std::vector<JSString>>(propertyNames)) {
				view.SetProperty(property_name, parameters.GetProperty(property_name));
			}
		}
	}

	JSValue MapModule::HYBRID_TYPE() const TITANIUM_NOEXCEPT
	{
		return hybrid_type__;
	}

	JSValue MapModule::SATELLITE_TYPE() const TITANIUM_NOEXCEPT
	{
		return satellite_type__;
	}

	JSValue MapModule::STANDARD_TYPE() const TITANIUM_NOEXCEPT
	{
		return standard_type__;
	}

	JSValue MapModule::TERRAIN_TYPE() const TITANIUM_NOEXCEPT
	{
		return terrain_type__;
	}

	JSValue MapModule::ANNOTATION_DRAG_STATE_CANCEL() const TITANIUM_NOEXCEPT
	{
		return annotation_drag_state_cancel__;
	}

	JSValue MapModule::ANNOTATION_DRAG_STATE_DRAG() const TITANIUM_NOEXCEPT
	{
		return annotation_drag_state_drag__;
	}

	JSValue MapModule::ANNOTATION_DRAG_STATE_END() const TITANIUM_NOEXCEPT
	{
		return annotation_drag_state_end__;
	}

	JSValue MapModule::ANNOTATION_DRAG_STATE_NONE() const TITANIUM_NOEXCEPT
	{
		return annotation_drag_state_none__;
	}

	JSValue MapModule::ANNOTATION_DRAG_STATE_START() const TITANIUM_NOEXCEPT
	{
		return annotation_drag_state_start__;
	}

	JSValue MapModule::ANNOTATION_GREEN() const TITANIUM_NOEXCEPT
	{
		return annotation_green__;
	}

	JSValue MapModule::ANNOTATION_PURPLE() const TITANIUM_NOEXCEPT
	{
		return annotation_purple__;
	}

	JSValue MapModule::ANNOTATION_RED() const TITANIUM_NOEXCEPT
	{
		return annotation_red__;
	}

	JSValue MapModule::OVERLAY_LEVEL_ABOVE_LABELS() const TITANIUM_NOEXCEPT
	{
		return overlay_level_above_labels__;
	}

	JSValue MapModule::OVERLAY_LEVEL_ABOVE_ROADS() const TITANIUM_NOEXCEPT
	{
		return overlay_level_above_roads__;
	}

	JSValue MapModule::SERVICE_DISABLED() const TITANIUM_NOEXCEPT
	{
		return service_disabled__;
	}

	JSValue MapModule::SERVICE_INVALID() const TITANIUM_NOEXCEPT
	{
		return service_invalid__;
	}

	JSValue MapModule::SERVICE_MISSING() const TITANIUM_NOEXCEPT
	{
		return service_missing__;
	}

	JSValue MapModule::SERVICE_VERSION_UPDATE_REQUIRED() const TITANIUM_NOEXCEPT
	{
		return service_version_update_required__;
	}

	JSValue MapModule::SUCCESS() const TITANIUM_NOEXCEPT
	{
		return success__;
	}

	JSValue MapModule::createView(JSObject parameters) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Map::createView");

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Map_property = Titanium.GetProperty("Map");
		TITANIUM_ASSERT(Map_property.IsObject());  // precondition
		JSObject Map = static_cast<JSObject>(Map_property);

		JSValue View_property = Map.GetProperty("View");
		TITANIUM_ASSERT(View_property.IsObject());  // precondition
		JSObject MapView = static_cast<JSObject>(View_property);

		applyProperties(MapView, parameters);
		
		return MapView.CallAsConstructor(parameters);
	}

	JSValue MapModule::createAnnotation(JSObject parameters) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Map::createAnnotation: Unimplemented");
		return get_context().CreateUndefined();
	}

	JSValue MapModule::createRoute(JSObject parameters) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Map::createRoute: Unimplemented");
		return get_context().CreateUndefined();
	}

	JSValue MapModule::createCamera(JSObject parameters) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Map::createCamera: Unimplemented");
		return get_context().CreateUndefined();
	}

	JSValue MapModule::isGooglePlayServicesAvailable() TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_WARN("Map::isGooglePlayServicesAvailable: Unimplemented");
		return get_context().CreateUndefined();
	}

	void MapModule::JSExportInitialize() {
		JSExport<MapModule>::SetClassVersion(1);
		JSExport<MapModule>::SetParent(JSExport<Module>::Class());

		JSExport<MapModule>::AddValueProperty("HYBRID_TYPE", std::mem_fn(&MapModule::HYBRID_TYPE));
		JSExport<MapModule>::AddValueProperty("SATELLITE_TYPE", std::mem_fn(&MapModule::SATELLITE_TYPE));
		JSExport<MapModule>::AddValueProperty("STANDARD_TYPE", std::mem_fn(&MapModule::STANDARD_TYPE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_CANCEL", std::mem_fn(&ANNOTATION_DRAG_STATE_CANCEL));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_DRAG", std::mem_fn(&ANNOTATION_DRAG_STATE_DRAG));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_END", std::mem_fn(&ANNOTATION_DRAG_STATE_END));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_NONE", std::mem_fn(&ANNOTATION_DRAG_STATE_NONE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_START", std::mem_fn(&ANNOTATION_DRAG_STATE_START));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_GREEN", std::mem_fn(&ANNOTATION_GREEN));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_PURPLE", std::mem_fn(&ANNOTATION_PURPLE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_RED", std::mem_fn(&ANNOTATION_RED));
		JSExport<MapModule>::AddValueProperty("OVERLAY_LEVEL_ABOVE_LABELS", std::mem_fn(&OVERLAY_LEVEL_ABOVE_LABELS));
		JSExport<MapModule>::AddValueProperty("OVERLAY_LEVEL_ABOVE_ROADS", std::mem_fn(&OVERLAY_LEVEL_ABOVE_ROADS));
		JSExport<MapModule>::AddValueProperty("SERVICE_DISABLED", std::mem_fn(&SERVICE_DISABLED));
		JSExport<MapModule>::AddValueProperty("SERVICE_INVALID", std::mem_fn(&SERVICE_INVALID));
		JSExport<MapModule>::AddValueProperty("SERVICE_MISSING", std::mem_fn(&SERVICE_MISSING));
		JSExport<MapModule>::AddValueProperty("SERVICE_VERSION_UPDATE_REQUIRED", std::mem_fn(&SERVICE_VERSION_UPDATE_REQUIRED));
		JSExport<MapModule>::AddValueProperty("SUCCESS", std::mem_fn(&SUCCESS));

		JSExport<MapModule>::AddFunctionProperty("createView", std::mem_fn(&MapModule::js_createView));
		JSExport<MapModule>::AddFunctionProperty("createAnnotation", std::mem_fn(&MapModule::js_createAnnotation));
		JSExport<MapModule>::AddFunctionProperty("createRoute", std::mem_fn(&MapModule::js_createRoute));
		JSExport<MapModule>::AddFunctionProperty("createCamera", std::mem_fn(&MapModule::js_createCamera));
		JSExport<MapModule>::AddFunctionProperty("isGoogleMapServicesAvailable", std::mem_fn(&MapModule::js_isGoogleMapServicesAvailable));
	}

	JSValue MapModule::js_createView(const std::vector<JSValue>& arguments, JSObject& this_object)
	{
		JSObject parameters = get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createView(parameters);
	}

	JSValue MapModule::js_createAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createAnnotation(parameters);
	}

	JSValue MapModule::js_createRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createRoute(parameters);
	}

	JSValue MapModule::js_createCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createCamera(parameters);
	}

	JSValue MapModule::js_isGoogleMapServicesAvailable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		return isGooglePlayServicesAvailable();
	}

} // namespace Titanium