/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Point.hpp"

namespace Titanium
{
	namespace UI
	{
		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Module(js_context)
		{
			TITANIUM_LOG_DEBUG("View:: ctor ", this);
		}

		View::~View() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("View:: dtor ", this);
		}

		void View::postInitialize(JSObject& this_object)
		{
			Titanium::Module::postInitialize(this_object);
		}

		void View::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::Module::postCallAsConstructor(js_context, arguments);	
			setLayoutPolicy<ViewLayoutPolicy>();
		}

		void View::animate(JSObject& animation, JSObject& callback) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("View::animate");
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Module>::Class());
			JSExport<View>::AddFunctionProperty("add", std::mem_fn(&View::js_add));
			JSExport<View>::AddFunctionProperty("animate", std::mem_fn(&View::js_animate));
			JSExport<View>::AddFunctionProperty("hide", std::mem_fn(&View::js_hide));
			JSExport<View>::AddFunctionProperty("show", std::mem_fn(&View::js_show));
			JSExport<View>::AddValueProperty("children", std::mem_fn(&View::js_get_children));
			JSExport<View>::AddValueProperty("backgroundColor", std::mem_fn(&View::js_get_backgroundColor), std::mem_fn(&View::js_set_backgroundColor));
			JSExport<View>::AddValueProperty("borderColor", std::mem_fn(&View::js_get_borderColor), std::mem_fn(&View::js_set_borderColor));
			JSExport<View>::AddValueProperty("borderRadius", std::mem_fn(&View::js_get_borderRadius), std::mem_fn(&View::js_set_borderRadius));
			JSExport<View>::AddValueProperty("borderWidth", std::mem_fn(&View::js_get_borderWidth), std::mem_fn(&View::js_set_borderWidth));
			JSExport<View>::AddValueProperty("opacity", std::mem_fn(&View::js_get_opacity), std::mem_fn(&View::js_set_opacity));
			JSExport<View>::AddValueProperty("tintColor", std::mem_fn(&View::js_get_tintColor), std::mem_fn(&View::js_set_tintColor));
			JSExport<View>::AddValueProperty("touchEnabled", std::mem_fn(&View::js_get_touchEnabled), std::mem_fn(&View::js_set_touchEnabled));
			JSExport<View>::AddValueProperty("visible", std::mem_fn(&View::js_get_visible), std::mem_fn(&View::js_set_visible));
			JSExport<View>::AddValueProperty("top", std::mem_fn(&View::js_get_top), std::mem_fn(&View::js_set_top));
			JSExport<View>::AddValueProperty("left", std::mem_fn(&View::js_get_left), std::mem_fn(&View::js_set_left));
			JSExport<View>::AddValueProperty("bottom", std::mem_fn(&View::js_get_bottom), std::mem_fn(&View::js_set_bottom));
			JSExport<View>::AddValueProperty("center", std::mem_fn(&View::js_get_center), std::mem_fn(&View::js_set_center));
			JSExport<View>::AddValueProperty("right", std::mem_fn(&View::js_get_right), std::mem_fn(&View::js_set_right));
			JSExport<View>::AddValueProperty("width", std::mem_fn(&View::js_get_width), std::mem_fn(&View::js_set_width));
			JSExport<View>::AddValueProperty("height", std::mem_fn(&View::js_get_height), std::mem_fn(&View::js_set_height));
			JSExport<View>::AddValueProperty("layout", std::mem_fn(&View::js_get_layout), std::mem_fn(&View::js_set_layout));
		}

		JSValue View::js_add(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() >= 1);
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			JSObject view = static_cast<JSObject>(_0);
			layoutPolicy__->add(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		JSValue View::js_animate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() >= 1);
			const auto _0 = arguments.at(0);
			TITANIUM_ASSERT(_0.IsObject());
			JSObject animation = static_cast<JSObject>(_0);
			// TODO Convert the animation object into a Ti.UI.Animation if it isn't one already?

			JSObject callback = this_object.get_context().CreateObject();
			if (arguments.size() > 1) {
				const auto _1 = arguments.at(1);
				TITANIUM_ASSERT(_1.IsObject());
				callback = static_cast<JSObject>(_1);
				TITANIUM_ASSERT(callback.IsFunction());
			}

			animate(animation, callback);
			return get_context().CreateUndefined();
		}

		JSValue View::js_hide(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			layoutPolicy__->hide();
			return get_context().CreateUndefined();
		}

		JSValue View::js_show(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			layoutPolicy__->show();
			return get_context().CreateUndefined();
		}

		JSValue View::js_get_backgroundColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_backgroundColor());
		}

		bool View::js_set_backgroundColor(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			bool result = false;
			std::string backgroundColorName = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_backgroundColor: backgroundColor = ", backgroundColorName);
			layoutPolicy__->set_backgroundColor(backgroundColorName);
			result = true;
			return result;
		}

		JSValue View::js_get_borderColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_borderColor());
		}

		bool View::js_set_borderColor(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutPolicy__->set_borderColor(static_cast<std::string>(argument));
			return true;
		}

		JSValue View::js_get_borderRadius() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(layoutPolicy__->get_borderRadius());
		}

		bool View::js_set_borderRadius(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			layoutPolicy__->set_borderRadius(static_cast<uint32_t>(argument));
			return true;
		}

		JSValue View::js_get_borderWidth() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(layoutPolicy__->get_borderWidth());
		}

		bool View::js_set_borderWidth(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsNumber());
			layoutPolicy__->set_borderWidth(static_cast<uint32_t>(argument));
			return true;
		}

		JSValue View::js_get_opacity() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateNumber(layoutPolicy__->get_opacity());
		}

		bool View::js_set_opacity(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			if (argument.IsNumber()) {
				layoutPolicy__->set_opacity(static_cast<double>(argument));
			}
			return true;
		}

		JSValue View::js_get_tintColor() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_tintColor());
		}

		bool View::js_set_tintColor(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutPolicy__->set_tintColor(static_cast<std::string>(argument));
			return true;
		}

		JSValue View::js_get_touchEnabled() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(layoutPolicy__->get_touchEnabled());
		}

		bool View::js_set_touchEnabled(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			layoutPolicy__->set_touchEnabled(static_cast<bool>(argument));
			return true;
		}

		JSValue View::js_get_visible() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(layoutPolicy__->get_visible());
		}

		bool View::js_set_visible(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			layoutPolicy__->set_visible(static_cast<bool>(argument));
			return true;
		}

		bool View::js_set_center(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			layoutPolicy__->set_center(js_to_Point(static_cast<JSObject>(argument)));
			return true;
		}
		
		JSValue View::js_get_center() const TITANIUM_NOEXCEPT
		{
			return Point_to_js(get_context(), layoutPolicy__->get_center());
		}

		JSValue View::js_get_top() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_top());
		}

		bool View::js_set_top(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			// FIXME What does setting top to null mean? Because corporate directory does it...
			if (argument.IsNull()) {
				return false;
			}
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_top: top = ", value);
			layoutPolicy__->set_top(value);
			result = true;
			return result;
		}

		JSValue View::js_get_left() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_left());
		}

		bool View::js_set_left(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_left: left = ", value);
			layoutPolicy__->set_left(value);
			result = true;
			return result;
		}

		JSValue View::js_get_width() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_width());
		}

		bool View::js_set_width(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_width: width = ", value);
			layoutPolicy__->set_width(value);
			result = true;
			return result;
		}

		JSValue View::js_get_height() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_height());
		}

		bool View::js_set_height(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_height: height = ", value);
			layoutPolicy__->set_height(value);
			result = true;
			return result;
		}

		JSValue View::js_get_bottom() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_bottom());
		}

		bool View::js_set_bottom(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_bottom: bottom = ", value);
			layoutPolicy__->set_bottom(value);
			result = true;
			return result;
		}

		JSValue View::js_get_right() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_right());
		}

		bool View::js_set_right(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_right: right = ", value);
			layoutPolicy__->set_right(value);
			result = true;
			return result;
		}

		JSValue View::js_get_layout() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(layoutPolicy__->get_layout());
		}

		bool View::js_set_layout(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			bool result = false;
			std::string value = static_cast<std::string>(argument);
			TITANIUM_LOG_INFO("View::js_set_layout: layout = ", value);
			layoutPolicy__->set_layout(value);
			result = true;
			return result;
		}
		
		JSValue View::js_get_children() const TITANIUM_NOEXCEPT
		{
			std::vector<JSValue> js_children;
			const auto children = layoutPolicy__->get_children();
			for (auto child : children) {
				js_children.push_back(child->get_object());
			}
			return get_context().CreateArray(js_children);
		}

	} // namespace UI
}  // namespace Titanium
