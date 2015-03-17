/**
 * Titanium.Map for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/MapModule.hpp"
#include "Titanium/UIModule.hpp"

namespace Titanium
{
    MapModule::MapModule(const JSContext& js_context) TITANIUM_NOEXCEPT
        : Module(js_context)
    {
		TITANIUM_LOG_DEBUG("MapModule:: ctor ", this);
	}

	void MapModule::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
		HAL_LOG_DEBUG("MapModule:: postCallAsConstructor ", this);
	}

	Map_View_shared_ptr_t MapModule::createView(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Map::createView");

		JSValue Titanium_property = this_object.get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Map_property = Titanium.GetProperty("Map");
		TITANIUM_ASSERT(Map_property.IsObject());  // precondition
		JSObject Map = static_cast<JSObject>(Map_property);

		JSValue View_property = Map.GetProperty("View");
		TITANIUM_ASSERT(View_property.IsObject());  // precondition
		JSObject MapView = static_cast<JSObject>(View_property);

		auto mapView = MapView.CallAsConstructor(parameters);
		Titanium::Module::applyProperties(parameters, mapView);
		return mapView.GetPrivate<Titanium::Map::View>();
	}

	Map_Annotation_shared_ptr_t MapModule::createAnnotation(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Map::createAnnotation");

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Map_property = Titanium.GetProperty("Map");
		TITANIUM_ASSERT(Map_property.IsObject());  // precondition
		JSObject Map = static_cast<JSObject>(Map_property);

		JSValue Proxy_property = Map.GetProperty("Annotation");
		TITANIUM_ASSERT(Proxy_property.IsObject());  // precondition
		JSObject Proxy = static_cast<JSObject>(Proxy_property);

		auto proxy = Proxy.CallAsConstructor(parameters);
		Titanium::Module::applyProperties(parameters, proxy);
		return proxy.GetPrivate<Titanium::Map::Annotation>();
	}

	Map_Route_shared_ptr_t MapModule::createRoute(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Map::createRoute");

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Map_property = Titanium.GetProperty("Map");
		TITANIUM_ASSERT(Map_property.IsObject());  // precondition
		JSObject Map = static_cast<JSObject>(Map_property);

		JSValue Proxy_property = Map.GetProperty("Route");
		TITANIUM_ASSERT(Proxy_property.IsObject());  // precondition
		JSObject Proxy = static_cast<JSObject>(Proxy_property);

		auto proxy = Proxy.CallAsConstructor(parameters);
		Titanium::Module::applyProperties(parameters, proxy);
		return proxy.GetPrivate<Titanium::Map::Route>();
	}

	Map_Camera_shared_ptr_t MapModule::createCamera(const JSObject& parameters, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		TITANIUM_LOG_DEBUG("Map::createCamera");

		JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Map_property = Titanium.GetProperty("Map");
		TITANIUM_ASSERT(Map_property.IsObject());  // precondition
		JSObject Map = static_cast<JSObject>(Map_property);

		JSValue Proxy_property = Map.GetProperty("Camera");
		TITANIUM_ASSERT(Proxy_property.IsObject());  // precondition
		JSObject Proxy = static_cast<JSObject>(Proxy_property);

		auto proxy = Proxy.CallAsConstructor(parameters);
		Titanium::Module::applyProperties(parameters, proxy);
		return proxy.GetPrivate<Titanium::Map::Camera>();
	}

	Titanium::Map::GOOGLE_PLAY_SERVICE_STATE MapModule::isGooglePlayServicesAvailable() TITANIUM_NOEXCEPT
	{
		return Titanium::Map::GOOGLE_PLAY_SERVICE_STATE::MISSING;
	}

	void MapModule::JSExportInitialize() {
		JSExport<MapModule>::SetClassVersion(1);
		JSExport<MapModule>::SetParent(JSExport<Module>::Class());

		JSExport<MapModule>::AddValueProperty("HYBRID_TYPE", std::mem_fn(&MapModule::js_get_HYBRID_TYPE));
		JSExport<MapModule>::AddValueProperty("SATELLITE_TYPE", std::mem_fn(&MapModule::js_get_SATELLITE_TYPE));
		JSExport<MapModule>::AddValueProperty("NORMAL_TYPE", std::mem_fn(&MapModule::js_get_NORMAL_TYPE));
		JSExport<MapModule>::AddValueProperty("TERRAIN_TYPE", std::mem_fn(&MapModule::js_get_TERRAIN_TYPE));
		
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_END", std::mem_fn(&MapModule::js_get_ANNOTATION_DRAG_STATE_END));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_DRAG_STATE_START", std::mem_fn(&MapModule::js_get_ANNOTATION_DRAG_STATE_START));

		JSExport<MapModule>::AddValueProperty("ANNOTATION_AZURE", std::mem_fn(&MapModule::js_get_ANNOTATION_AZURE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_BLUE", std::mem_fn(&MapModule::js_get_ANNOTATION_BLUE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_CYAN", std::mem_fn(&MapModule::js_get_ANNOTATION_CYAN));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_GREEN", std::mem_fn(&MapModule::js_get_ANNOTATION_GREEN));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_MAGENTA", std::mem_fn(&MapModule::js_get_ANNOTATION_MAGENTA));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_ORANGE", std::mem_fn(&MapModule::js_get_ANNOTATION_ORANGE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_PURPLE", std::mem_fn(&MapModule::js_get_ANNOTATION_PURPLE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_RED", std::mem_fn(&MapModule::js_get_ANNOTATION_RED));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_ROSE", std::mem_fn(&MapModule::js_get_ANNOTATION_ROSE));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_VIOLET", std::mem_fn(&MapModule::js_get_ANNOTATION_VIOLET));
		JSExport<MapModule>::AddValueProperty("ANNOTATION_YELLOW", std::mem_fn(&MapModule::js_get_ANNOTATION_YELLOW));
		
		JSExport<MapModule>::AddValueProperty("OVERLAY_LEVEL_ABOVE_LABELS", std::mem_fn(&MapModule::js_get_OVERLAY_LEVEL_ABOVE_LABELS));
		JSExport<MapModule>::AddValueProperty("OVERLAY_LEVEL_ABOVE_ROADS", std::mem_fn(&MapModule::js_get_OVERLAY_LEVEL_ABOVE_ROADS));
		
		JSExport<MapModule>::AddValueProperty("SERVICE_DISABLED", std::mem_fn(&MapModule::js_get_SERVICE_DISABLED));
		JSExport<MapModule>::AddValueProperty("SERVICE_INVALID", std::mem_fn(&MapModule::js_get_SERVICE_INVALID));
		JSExport<MapModule>::AddValueProperty("SERVICE_MISSING", std::mem_fn(&MapModule::js_get_SERVICE_MISSING));
		JSExport<MapModule>::AddValueProperty("SERVICE_VERSION_UPDATE_REQUIRED", std::mem_fn(&MapModule::js_get_SERVICE_VERSION_UPDATE_REQUIRED));
		JSExport<MapModule>::AddValueProperty("SUCCESS", std::mem_fn(&MapModule::js_get_SUCCESS));

		JSExport<MapModule>::AddFunctionProperty("createView", std::mem_fn(&MapModule::js_createView));
		JSExport<MapModule>::AddFunctionProperty("createAnnotation", std::mem_fn(&MapModule::js_createAnnotation));
		JSExport<MapModule>::AddFunctionProperty("createRoute", std::mem_fn(&MapModule::js_createRoute));
		JSExport<MapModule>::AddFunctionProperty("createCamera", std::mem_fn(&MapModule::js_createCamera));
		JSExport<MapModule>::AddFunctionProperty("isGooglePlayServicesAvailable", std::mem_fn(&MapModule::js_isGooglePlayServicesAvailable));
	}

	JSValue MapModule::js_get_HYBRID_TYPE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::MAP_TYPE::HYBRID));
	}

	JSValue MapModule::js_get_SATELLITE_TYPE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::MAP_TYPE::SATELLITE));
	}

	JSValue MapModule::js_get_NORMAL_TYPE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::MAP_TYPE::NORMAL));
	}

	JSValue MapModule::js_get_TERRAIN_TYPE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::MAP_TYPE::TERRAIN));
	}

	JSValue MapModule::js_get_ANNOTATION_DRAG_STATE_END() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_DRAG_STATE::END));
	}

	JSValue MapModule::js_get_ANNOTATION_DRAG_STATE_START() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_DRAG_STATE::START));
	}

	JSValue MapModule::js_get_ANNOTATION_AZURE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::AZURE));
	}
	
	JSValue MapModule::js_get_ANNOTATION_BLUE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::BLUE));
	}
	
	JSValue MapModule::js_get_ANNOTATION_CYAN() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::CYAN));
	}
		
	JSValue MapModule::js_get_ANNOTATION_GREEN() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::GREEN));
	}

	JSValue MapModule::js_get_ANNOTATION_MAGENTA() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::MAGENTA));
	}

	JSValue MapModule::js_get_ANNOTATION_ORANGE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::ORANGE));
	}

	JSValue MapModule::js_get_ANNOTATION_PURPLE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::PURPLE));
	}

	JSValue MapModule::js_get_ANNOTATION_RED() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::RED));
	}

	JSValue MapModule::js_get_ANNOTATION_ROSE() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::ROSE));
	}
		
	JSValue MapModule::js_get_ANNOTATION_VIOLET() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::VIOLET));
	}
		
	JSValue MapModule::js_get_ANNOTATION_YELLOW() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::ANNOTATION_COLOR::YELLOW));
	}

	JSValue MapModule::js_get_OVERLAY_LEVEL_ABOVE_LABELS() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::OVERLAY_LEVEL::ABOVE_LABELS));
	}

	JSValue MapModule::js_get_OVERLAY_LEVEL_ABOVE_ROADS() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::OVERLAY_LEVEL::ABOVE_ROADS));
	}

	JSValue MapModule::js_get_SERVICE_DISABLED() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::GOOGLE_PLAY_SERVICE_STATE::DISABLED));
	}

	JSValue MapModule::js_get_SERVICE_INVALID() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::GOOGLE_PLAY_SERVICE_STATE::INVALID));
	}

	JSValue MapModule::js_get_SERVICE_MISSING() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::GOOGLE_PLAY_SERVICE_STATE::MISSING));
	}

	JSValue MapModule::js_get_SERVICE_VERSION_UPDATE_REQUIRED() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::GOOGLE_PLAY_SERVICE_STATE::VERSION_UPDATE_REQUIRED));
	}

	JSValue MapModule::js_get_SUCCESS() const TITANIUM_NOEXCEPT
	{
		return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(Map::GOOGLE_PLAY_SERVICE_STATE::SUCCESS));
	}

	JSValue MapModule::js_createView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = this_object.get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createView(parameters, this_object)->get_object();
	}

	JSValue MapModule::js_createAnnotation(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = this_object.get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createAnnotation(parameters, this_object)->get_object();
	}

	JSValue MapModule::js_createRoute(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = this_object.get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createRoute(parameters, this_object)->get_object();
	}

	JSValue MapModule::js_createCamera(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		JSObject parameters = this_object.get_context().CreateObject();

		if (arguments.size() >= 1) {
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			parameters = static_cast<JSObject>(_0);
		}

		return createCamera(parameters, this_object)->get_object();
	}

	JSValue MapModule::js_isGooglePlayServicesAvailable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
	{
		return this_object.get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(isGooglePlayServicesAvailable()));
	}

} // namespace Titanium