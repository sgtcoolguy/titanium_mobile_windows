/**
 * TitaniumKit Titanium.UI.MapView
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_MAPVIEW_HPP_
#define _TITANIUM_UI_MAPVIEW_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium 
{
	namespace UI 
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium MapView Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.MapView
		 */
		class TITANIUMKIT_EXPORT MapView : public View, public JSExport<MapView> 
		{

		public:

			struct MapRegionType {
				double latitude;
				double latitudeDelta;
				double longitude;
				double longitudeDelta;
			};

			virtual int mapType() const TITANIUM_NOEXCEPT;
			virtual void setMapType(int mapType) TITANIUM_NOEXCEPT;
			virtual void OnSetMapType() TITANIUM_NOEXCEPT;

			virtual JSValue region() const TITANIUM_NOEXCEPT;
			virtual void setRegion(JSObject region) TITANIUM_NOEXCEPT;
			virtual void OnSetRegion() TITANIUM_NOEXCEPT;

			virtual void setZoomLevel(int zoom) TITANIUM_NOEXCEPT;

			virtual JSValue addAnnotation(JSObject& annotation) TITANIUM_NOEXCEPT;

			virtual MapRegionType getMapRegionType(JSObject& mapRegionType) TITANIUM_NOEXCEPT;

			MapView(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
			virtual ~MapView() = default;
			MapView(const MapView&) = default;
			MapView& operator=(const MapView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			MapView(MapView&&)                 = default;
			MapView& operator=(MapView&&)      = default;
#endif

			static void JSExportInitialize();

			JSValue js_get_mapType() const TITANIUM_NOEXCEPT;
			bool js_set_mapType(const JSValue& argument) TITANIUM_NOEXCEPT;
			JSValue js_setMapType(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT;

			JSValue js_get_region() const TITANIUM_NOEXCEPT;
			bool js_set_region(const JSValue& argument) TITANIUM_NOEXCEPT;
			JSValue js_setRegion(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT;

			JSValue js_setZoomLevel(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT;

#pragma warning(push)
#pragma warning(disable : 4251)
			int mapType__;
			MapRegionType region__;
			int zoomLevel__;
#pragma warning(pop)
		};
	} // namespace UI
}  // namespace Titanium
#endif // _TITANIUM_UI_MAPVIEW_HPP_