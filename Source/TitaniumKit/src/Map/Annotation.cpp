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
			animate__(false),
			latitude__(0),
			longitude__(0),
			pincolor__(0),
			subtitle__(""),
			subtitleid__(""),
			title__(""),
			titleid__("")
		{
		}

		bool Annotation::get_animate() const TITANIUM_NOEXCEPT
		{
			return animate__;
		}

		std::string Annotation::get_image() const TITANIUM_NOEXCEPT
		{
			return image__;
		}

		double Annotation::get_latitude() const TITANIUM_NOEXCEPT
		{
			return latitude__;
		}

		double Annotation::get_longitude() const TITANIUM_NOEXCEPT
		{
			return longitude__;
		}

		std::string Annotation::get_leftButton() const TITANIUM_NOEXCEPT
		{
			return leftButton__;
		}

		TiView_shared_ptr_t Annotation::get_leftView() const TITANIUM_NOEXCEPT
		{
			return leftView__;
		}

		double Annotation::get_pincolor() const TITANIUM_NOEXCEPT
		{
			return pincolor__;
		}

		std::string Annotation::get_rightButton() const TITANIUM_NOEXCEPT
		{
			return rightButton__;
		}

		TiView_shared_ptr_t Annotation::get_rightView() const TITANIUM_NOEXCEPT
		{
			return rightView__;
		}

		std::string Annotation::get_subtitle() const TITANIUM_NOEXCEPT
		{
			return subtitle__;
		}

		std::string Annotation::get_subtitleid() const TITANIUM_NOEXCEPT
		{
			return subtitleid__;
		}

		std::string Annotation::get_title() const TITANIUM_NOEXCEPT
		{
			return title__;
		}

		std::string Annotation::get_titleid() const TITANIUM_NOEXCEPT
		{
			return titleid__;
		}

		void Annotation::JSExportInitialize() {
			JSExport<Annotation>::SetClassVersion(1);
			JSExport<Annotation>::SetParent(JSExport<Module>::Class());

			JSExport<Annotation>::AddValueProperty("animate", std::mem_fn(&Annotation::js_get_animate));
			JSExport<Annotation>::AddValueProperty("image", std::mem_fn(&Annotation::js_get_image));
			JSExport<Annotation>::AddValueProperty("latitude", std::mem_fn(&Annotation::js_get_latitude));
			JSExport<Annotation>::AddValueProperty("longitude", std::mem_fn(&Annotation::js_get_longitude));
			JSExport<Annotation>::AddValueProperty("leftButton", std::mem_fn(&Annotation::js_get_leftButton));
			JSExport<Annotation>::AddValueProperty("leftView", std::mem_fn(&Annotation::js_get_leftView));
			JSExport<Annotation>::AddValueProperty("pincolor", std::mem_fn(&Annotation::js_get_pincolor));
			JSExport<Annotation>::AddValueProperty("rightButton", std::mem_fn(&Annotation::js_get_rightButton));
			JSExport<Annotation>::AddValueProperty("rightView", std::mem_fn(&Annotation::js_get_rightView));
			JSExport<Annotation>::AddValueProperty("subtitle", std::mem_fn(&Annotation::js_get_subtitle));
			JSExport<Annotation>::AddValueProperty("subtitleid", std::mem_fn(&Annotation::js_get_subtitleid));
			JSExport<Annotation>::AddValueProperty("title", std::mem_fn(&Annotation::js_get_title));
			JSExport<Annotation>::AddValueProperty("titleid", std::mem_fn(&Annotation::js_get_titleid));

			JSExport<Annotation>::AddFunctionProperty("getAnimate", std::mem_fn(&Annotation::js_getAnimate));
			JSExport<Annotation>::AddFunctionProperty("setAnimate", std::mem_fn(&Annotation::js_setAnimate));
			JSExport<Annotation>::AddFunctionProperty("getImage", std::mem_fn(&Annotation::js_getImage));
			JSExport<Annotation>::AddFunctionProperty("setImage", std::mem_fn(&Annotation::js_setImage));
			JSExport<Annotation>::AddFunctionProperty("getLatitude", std::mem_fn(&Annotation::js_getLatitude));
			JSExport<Annotation>::AddFunctionProperty("setLatitude", std::mem_fn(&Annotation::js_setLatitude));
			JSExport<Annotation>::AddFunctionProperty("getLongitude", std::mem_fn(&Annotation::js_getLongitude));
			JSExport<Annotation>::AddFunctionProperty("setLongitude", std::mem_fn(&Annotation::js_setLongitude));
			JSExport<Annotation>::AddFunctionProperty("getLeftButton", std::mem_fn(&Annotation::js_getLeftButton));
			JSExport<Annotation>::AddFunctionProperty("setLeftButton", std::mem_fn(&Annotation::js_setLeftButton));
			JSExport<Annotation>::AddFunctionProperty("getLeftView", std::mem_fn(&Annotation::js_getLeftView));
			JSExport<Annotation>::AddFunctionProperty("setLeftView", std::mem_fn(&Annotation::js_setLeftView));
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

		JSValue Annotation::js_get_animate() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_animate());
		}

		JSValue Annotation::js_get_image() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_image());
		}

		JSValue Annotation::js_get_latitude() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_latitude());
		}

		JSValue Annotation::js_get_longitude() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_longitude());
		}

		JSValue Annotation::js_get_leftButton() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_leftButton());
		}

		JSValue Annotation::js_get_leftView() const TITANIUM_NOEXCEPT
		{
			return get_leftView()->get_object();
		}

		JSValue Annotation::js_get_pincolor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(get_pincolor());
		}

		JSValue Annotation::js_get_rightButton() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_rightButton());
		}

		JSValue Annotation::js_get_rightView() const TITANIUM_NOEXCEPT
		{
			return get_rightView()->get_object();
		}

		JSValue Annotation::js_get_subtitle() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_subtitle());
		}

		JSValue Annotation::js_get_subtitleid() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_subtitleid());
		}

		JSValue Annotation::js_get_title() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_title());
		}

		JSValue Annotation::js_get_titleid() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_titleid());
		}

		JSValue Annotation::js_getAnimate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getAnimate is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setAnimate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setAnimate is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsBoolean());
				//set_animate(static_cast<bool>(_0));
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getImage is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setImage(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setImage is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto image = static_cast<JSObject>(_0);
				// setImage(image);
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLatitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getLatitude is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setLatitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setLatitude is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				// set_latitude(static_cast<double>(_0)); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLongitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getLongitude is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setLongitude(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setLongitude is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				// set_longitude(static_cast<double>(_0)); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLeftButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getLeftButton is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setLeftButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setLeftButton is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				// set_leftButton(static_cast<std::string>(_0)); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getLeftView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getLeftView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setLeftView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setLeftView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				const auto leftView = static_cast<JSObject>(_0);
				// setLeftView(leftView); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getPincolor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getPincolor is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setPincolor(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setPincolor is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsNumber());
				const double pincolor = static_cast<double>(_0);
				// setPincolor(pincolor); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getRightButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getRightButton is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setRightButton(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setRightButton is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto rightButton = static_cast<JSObject>(_0);
				// setRightButton(rightButton);
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getRightView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getRightView is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setRightView(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setRightView is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				// setRightView(rightView); // TODO
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getSubtitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getSubtitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setSubtitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setSubtitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string subtitle = static_cast<std::string>(_0);
				// setSubtitle(subtitle);
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getSubtitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getSubtitleid is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setSubtitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setSubtitleid is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string subtitleid = static_cast<std::string>(_0);
				// setSubtitleid(subtitleid);
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getTitle is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setTitle(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setTitle is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string title = static_cast<std::string>(_0);
				// setTitle(title);
			}
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_getTitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.getTitleid is not implemented yet");
			return get_context().CreateUndefined();
		}

		JSValue Annotation::js_setTitleid(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("Annotation.setTitleid is not implemented yet");
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			}
			else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsString());
				const std::string titleid = static_cast<std::string>(_0);
				// setTitleid(titleid);
			}
			return get_context().CreateUndefined();
		}

	} // namespace Map
} // namespace Titanium