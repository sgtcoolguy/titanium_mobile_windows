/**
 * TitaniumKit Titanium.Map.Annotation
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Map/Annotation.hpp"

namespace Titanium
{
	namespace Map
	{

		Annotation::Annotation(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments),
			canShowCallout__(true),
			draggable__(false),
			latitude__(0),
			longitude__(0),
			pincolor__(ANNOTATION_COLOR::AZURE),
			showInfoWindow__(true),
			subtitle__(""),
			subtitleid__(""),
			title__(""),
			titleid__("")
		{
		}

		bool Annotation::get_canShowCallout() const TITANIUM_NOEXCEPT
		{
			return canShowCallout__;
		}

		void Annotation::set_canShowCallout(const bool& canShowCallout) TITANIUM_NOEXCEPT
		{
			canShowCallout__ = canShowCallout;
		}

		Titanium::UI::Point Annotation::get_centerOffset() const TITANIUM_NOEXCEPT
		{
			return centerOffset__;
		}

		void Annotation::set_centerOffset(const Titanium::UI::Point& centerOffset) TITANIUM_NOEXCEPT
		{
			centerOffset__ = centerOffset;
		}

		TiView_shared_ptr_t Annotation::get_customView() const TITANIUM_NOEXCEPT
		{
			return customView__;
		}

		void Annotation::set_customView(const TiView_shared_ptr_t& customView) TITANIUM_NOEXCEPT
		{
			customView__ = customView;
		}

		bool Annotation::get_draggable() const TITANIUM_NOEXCEPT
		{
			return draggable__;
		}

		void Annotation::set_draggable(const bool& draggable) TITANIUM_NOEXCEPT
		{
			draggable__ = draggable;
		}

		std::string Annotation::get_image() const TITANIUM_NOEXCEPT
		{
			return image__;
		}

		void Annotation::set_image(const std::string& image) TITANIUM_NOEXCEPT
		{
			image__ = image;
		}

		double Annotation::get_latitude() const TITANIUM_NOEXCEPT
		{
			return latitude__;
		}

		void Annotation::set_latitude(const double& latitude) TITANIUM_NOEXCEPT
		{
			latitude__ = latitude;
		}

		std::string Annotation::get_leftButton() const TITANIUM_NOEXCEPT
		{
			return leftButton__;
		}

		void Annotation::set_leftButton(const std::string& leftButton) TITANIUM_NOEXCEPT
		{
			leftButton__ = leftButton;
		}

		TiView_shared_ptr_t Annotation::get_leftView() const TITANIUM_NOEXCEPT
		{
			return leftView__;
		}

		void Annotation::set_leftView(const TiView_shared_ptr_t& leftView) TITANIUM_NOEXCEPT
		{
			leftView__ = leftView;
		}

		double Annotation::get_longitude() const TITANIUM_NOEXCEPT
		{
			return longitude__;
		}

		void Annotation::set_longitude(const double& longitude) TITANIUM_NOEXCEPT
		{
			longitude__ = longitude;
		}

		ANNOTATION_COLOR Annotation::get_pincolor() const TITANIUM_NOEXCEPT
		{
			return pincolor__;
		}

		void Annotation::set_pincolor(const ANNOTATION_COLOR& pincolor) TITANIUM_NOEXCEPT
		{
			pincolor__ = pincolor;
		}

		std::string Annotation::get_rightButton() const TITANIUM_NOEXCEPT
		{
			return rightButton__;
		}

		void Annotation::set_rightButton(const std::string& rightButton) TITANIUM_NOEXCEPT
		{
			rightButton__ = rightButton;
		}

		TiView_shared_ptr_t Annotation::get_rightView() const TITANIUM_NOEXCEPT
		{
			return rightView__;
		}

		void Annotation::set_rightView(const TiView_shared_ptr_t& rightView) TITANIUM_NOEXCEPT
		{
			rightView__ = rightView;
		}

		bool Annotation::get_showInfoWindow() const TITANIUM_NOEXCEPT
		{
			return showInfoWindow__;
		}

		void Annotation::set_showInfoWindow(const bool& showInfoWindow) TITANIUM_NOEXCEPT
		{
			showInfoWindow__ = showInfoWindow;
		}

		std::string Annotation::get_subtitle() const TITANIUM_NOEXCEPT
		{
			return subtitle__;
		}

		void Annotation::set_subtitle(const std::string& subtitle) TITANIUM_NOEXCEPT
		{
			subtitle__ = subtitle;
		}

		std::string Annotation::get_subtitleid() const TITANIUM_NOEXCEPT
		{
			return subtitleid__;
		}

		void Annotation::set_subtitleid(const std::string& subtitleid) TITANIUM_NOEXCEPT
		{
			subtitleid__ = subtitleid;
		}

		std::string Annotation::get_title() const TITANIUM_NOEXCEPT
		{
			return title__;
		}

		void Annotation::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			title__ = title;
		}

		std::string Annotation::get_titleid() const TITANIUM_NOEXCEPT
		{
			return titleid__;
		}

		void Annotation::set_titleid(const std::string& titleid) TITANIUM_NOEXCEPT
		{
			titleid__ = titleid;
		}

		void Annotation::JSExportInitialize()
		{
			JSExport<Annotation>::SetClassVersion(1);
			JSExport<Annotation>::SetParent(JSExport<Module>::Class());
			// Properties
			JSExport<Annotation>::AddValueProperty("canShowCallout", std::mem_fn(&Annotation::js_get_canShowCallout), std::mem_fn(&Annotation::js_set_canShowCallout));
			JSExport<Annotation>::AddValueProperty("centerOffset", std::mem_fn(&Annotation::js_get_centerOffset), std::mem_fn(&Annotation::js_set_centerOffset));
			JSExport<Annotation>::AddValueProperty("customView", std::mem_fn(&Annotation::js_get_customView), std::mem_fn(&Annotation::js_set_customView));
			JSExport<Annotation>::AddValueProperty("draggable", std::mem_fn(&Annotation::js_get_draggable), std::mem_fn(&Annotation::js_set_draggable));
			JSExport<Annotation>::AddValueProperty("image", std::mem_fn(&Annotation::js_get_image), std::mem_fn(&Annotation::js_set_image));
			JSExport<Annotation>::AddValueProperty("latitude", std::mem_fn(&Annotation::js_get_latitude), std::mem_fn(&Annotation::js_set_latitude));
			JSExport<Annotation>::AddValueProperty("leftButton", std::mem_fn(&Annotation::js_get_leftButton), std::mem_fn(&Annotation::js_set_leftButton));
			JSExport<Annotation>::AddValueProperty("leftView", std::mem_fn(&Annotation::js_get_leftView), std::mem_fn(&Annotation::js_set_leftView));
			JSExport<Annotation>::AddValueProperty("longitude", std::mem_fn(&Annotation::js_get_longitude), std::mem_fn(&Annotation::js_set_longitude));
			JSExport<Annotation>::AddValueProperty("pincolor", std::mem_fn(&Annotation::js_get_pincolor), std::mem_fn(&Annotation::js_set_pincolor));
			JSExport<Annotation>::AddValueProperty("rightButton", std::mem_fn(&Annotation::js_get_rightButton), std::mem_fn(&Annotation::js_set_rightButton));
			JSExport<Annotation>::AddValueProperty("rightView", std::mem_fn(&Annotation::js_get_rightView), std::mem_fn(&Annotation::js_set_rightView));
			JSExport<Annotation>::AddValueProperty("showInfoWindow", std::mem_fn(&Annotation::js_get_showInfoWindow), std::mem_fn(&Annotation::js_set_showInfoWindow));
			JSExport<Annotation>::AddValueProperty("subtitle", std::mem_fn(&Annotation::js_get_subtitle), std::mem_fn(&Annotation::js_set_subtitle));
			JSExport<Annotation>::AddValueProperty("subtitleid", std::mem_fn(&Annotation::js_get_subtitleid), std::mem_fn(&Annotation::js_set_subtitleid));
			JSExport<Annotation>::AddValueProperty("title", std::mem_fn(&Annotation::js_get_title), std::mem_fn(&Annotation::js_set_title));
			JSExport<Annotation>::AddValueProperty("titleid", std::mem_fn(&Annotation::js_get_titleid), std::mem_fn(&Annotation::js_set_titleid));
			// Methods
			JSExport<Annotation>::AddFunctionProperty("getCanShowCallout", std::mem_fn(&Annotation::js_getCanShowCallout));
			JSExport<Annotation>::AddFunctionProperty("setCanShowCallout", std::mem_fn(&Annotation::js_setCanShowCallout));
			JSExport<Annotation>::AddFunctionProperty("getCenterOffset", std::mem_fn(&Annotation::js_getCenterOffset));
			JSExport<Annotation>::AddFunctionProperty("setCenterOffset", std::mem_fn(&Annotation::js_setCenterOffset));
			JSExport<Annotation>::AddFunctionProperty("getCustomView", std::mem_fn(&Annotation::js_getCustomView));
			JSExport<Annotation>::AddFunctionProperty("setCustomView", std::mem_fn(&Annotation::js_setCustomView));
			JSExport<Annotation>::AddFunctionProperty("getDraggable", std::mem_fn(&Annotation::js_getDraggable));
			JSExport<Annotation>::AddFunctionProperty("setDraggable", std::mem_fn(&Annotation::js_setDraggable));
			JSExport<Annotation>::AddFunctionProperty("getImage", std::mem_fn(&Annotation::js_getImage));
			JSExport<Annotation>::AddFunctionProperty("setImage", std::mem_fn(&Annotation::js_setImage));
			JSExport<Annotation>::AddFunctionProperty("getLatitude", std::mem_fn(&Annotation::js_getLatitude));
			JSExport<Annotation>::AddFunctionProperty("setLatitude", std::mem_fn(&Annotation::js_setLatitude));
			JSExport<Annotation>::AddFunctionProperty("getLeftButton", std::mem_fn(&Annotation::js_getLeftButton));
			JSExport<Annotation>::AddFunctionProperty("setLeftButton", std::mem_fn(&Annotation::js_setLeftButton));
			JSExport<Annotation>::AddFunctionProperty("getLeftView", std::mem_fn(&Annotation::js_getLeftView));
			JSExport<Annotation>::AddFunctionProperty("setLeftView", std::mem_fn(&Annotation::js_setLeftView));
			JSExport<Annotation>::AddFunctionProperty("getLongitude", std::mem_fn(&Annotation::js_getLongitude));
			JSExport<Annotation>::AddFunctionProperty("setLongitude", std::mem_fn(&Annotation::js_setLongitude));
			JSExport<Annotation>::AddFunctionProperty("getPincolor", std::mem_fn(&Annotation::js_getPincolor));
			JSExport<Annotation>::AddFunctionProperty("setPincolor", std::mem_fn(&Annotation::js_setPincolor));
			JSExport<Annotation>::AddFunctionProperty("getRightButton", std::mem_fn(&Annotation::js_getRightButton));
			JSExport<Annotation>::AddFunctionProperty("setRightButton", std::mem_fn(&Annotation::js_setRightButton));
			JSExport<Annotation>::AddFunctionProperty("getRightView", std::mem_fn(&Annotation::js_getRightView));
			JSExport<Annotation>::AddFunctionProperty("setRightView", std::mem_fn(&Annotation::js_setRightView));
			JSExport<Annotation>::AddFunctionProperty("getSubtitle", std::mem_fn(&Annotation::js_getSubtitle));
			JSExport<Annotation>::AddFunctionProperty("setSubtitle", std::mem_fn(&Annotation::js_setSubtitle));
			JSExport<Annotation>::AddFunctionProperty("getSubtitleid", std::mem_fn(&Annotation::js_getSubtitleid));
			JSExport<Annotation>::AddFunctionProperty("setSubtitleid", std::mem_fn(&Annotation::js_setSubtitleid));
			JSExport<Annotation>::AddFunctionProperty("getTitle", std::mem_fn(&Annotation::js_getTitle));
			JSExport<Annotation>::AddFunctionProperty("setTitle", std::mem_fn(&Annotation::js_setTitle));
			JSExport<Annotation>::AddFunctionProperty("getTitleid", std::mem_fn(&Annotation::js_getTitleid));
			JSExport<Annotation>::AddFunctionProperty("setTitleid", std::mem_fn(&Annotation::js_setTitleid));
		}

		JSValue Annotation::js_get_canShowCallout() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_canShowCallout());
		}

		bool Annotation::js_set_canShowCallout(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_canShowCallout(static_cast<bool>(argument));
			return true;
		}

		JSValue Annotation::js_get_centerOffset() const TITANIUM_NOEXCEPT
		{
			return Titanium::UI::Point_to_js(get_context(), get_centerOffset());
		}

		bool Annotation::js_set_centerOffset(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_centerOffset(Titanium::UI::js_to_Point(static_cast<JSObject>(argument)));
			return true;
		}

		JSValue Annotation::js_get_customView() const TITANIUM_NOEXCEPT
		{
			return get_customView()->get_object();
		}

		bool Annotation::js_set_customView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_customView(static_cast<JSObject>(argument).GetPrivate<Titanium::UI::View>());
			return true;
		}

		JSValue Annotation::js_get_draggable() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_draggable());
		}

		bool Annotation::js_set_draggable(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_draggable(static_cast<bool>(argument));
			return true;
		}

		JSValue Annotation::js_get_image() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_image());
		}

		bool Annotation::js_set_image(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_image(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_latitude() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_latitude());
		}

		bool Annotation::js_set_latitude(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_latitude(static_cast<double>(argument));
			return true;
		}

		JSValue Annotation::js_get_leftButton() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_leftButton());
		}

		bool Annotation::js_set_leftButton(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_leftButton(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_leftView() const TITANIUM_NOEXCEPT
		{
			return get_leftView()->get_object();
		}

		bool Annotation::js_set_leftView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_leftView(static_cast<JSObject>(argument).GetPrivate<Titanium::UI::View>());
			return true;
		}

		JSValue Annotation::js_get_longitude() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_longitude());
		}

		bool Annotation::js_set_longitude(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_longitude(static_cast<double>(argument));
			return true;
		}

		JSValue Annotation::js_get_pincolor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(Titanium::Map::Constants::to_underlying_type(get_pincolor()));
		}

		bool Annotation::js_set_pincolor(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_pincolor(Constants::to_ANNOTATION_COLOR(static_cast<std::underlying_type<ANNOTATION_COLOR>::type>(argument)));
			return true;
		}

		JSValue Annotation::js_get_rightButton() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_rightButton());
		}

		bool Annotation::js_set_rightButton(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_rightButton(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_rightView() const TITANIUM_NOEXCEPT
		{
			return get_rightView()->get_object();
		}

		bool Annotation::js_set_rightView(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_rightView(static_cast<JSObject>(argument).GetPrivate<Titanium::UI::View>());
			return true;
		}

		JSValue Annotation::js_get_showInfoWindow() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_showInfoWindow());
		}

		bool Annotation::js_set_showInfoWindow(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_showInfoWindow(static_cast<bool>(argument));
			return true;
		}

		JSValue Annotation::js_get_subtitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_subtitle());
		}

		bool Annotation::js_set_subtitle(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_subtitle(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_subtitleid() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_subtitleid());
		}

		bool Annotation::js_set_subtitleid(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_subtitleid(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_title() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_title());
		}

		bool Annotation::js_set_title(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_title(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_get_titleid() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_titleid());
		}

		bool Annotation::js_set_titleid(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_titleid(static_cast<std::string>(argument));
			return true;
		}

		JSValue Annotation::js_getCanShowCallout(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_canShowCallout();
		}

		JSValue Annotation::js_setCanShowCallout(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_canShowCallout(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getCenterOffset(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_centerOffset();
		}

		JSValue Annotation::js_setCenterOffset(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_centerOffset(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getCustomView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_customView();
		}

		JSValue Annotation::js_setCustomView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_customView(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getDraggable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_draggable();
		}

		JSValue Annotation::js_setDraggable(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_draggable(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_image();
		}

		JSValue Annotation::js_setImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_image(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLatitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_latitude();
		}

		JSValue Annotation::js_setLatitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_latitude(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLeftButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_leftButton();
		}

		JSValue Annotation::js_setLeftButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_leftButton(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLeftView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_leftView();
		}

		JSValue Annotation::js_setLeftView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_leftView(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLongitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_longitude();
		}

		JSValue Annotation::js_setLongitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_longitude(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getPincolor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_pincolor();
		}

		JSValue Annotation::js_setPincolor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_pincolor(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getRightButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_rightButton();
		}

		JSValue Annotation::js_setRightButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_rightButton(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getRightView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_rightView();
		}

		JSValue Annotation::js_setRightView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_rightView(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getShowInfoWindow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_showInfoWindow();
		}

		JSValue Annotation::js_setShowInfoWindow(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_showInfoWindow(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getSubtitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_subtitle();
		}

		JSValue Annotation::js_setSubtitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_subtitle(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getSubtitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_subtitleid();
		}

		JSValue Annotation::js_setSubtitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_subtitleid(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_title();
		}

		JSValue Annotation::js_setTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_title(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getTitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_titleid();
		}

		JSValue Annotation::js_setTitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 1);
			
			js_set_titleid(arguments.at(0));
			
			return get_context().CreateUndefined();
		}

	} // namespace Map
} // namespace Titanium