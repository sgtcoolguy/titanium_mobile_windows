/**
 * Titanium.UI.Animation for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/Animation.hpp"

namespace Titanium
{
	namespace UI
	{


		Animation::Animation(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context),
			autoreverse__(false),
			backgroundColor__(""),
			bottom__(0),
			center__(js_context.CreateObject()),
			color__(""),
			curve__(ANIMATION_CURVE::EASE_IN),
			delay__(0),
			duration__(0),
			height__(0),
			left__(0),
			opacity__(0),
			opaque__(true),
			repeat__(1),
			right__(0),
			top__(0),
			transform__(js_context.CreateNull()),
			transition__(0),
			view__(js_context.CreateNull()),
			visible__(true),
			width__(0),
			zIndex__(1)
		{
			TITANIUM_LOG_DEBUG("Animation:: ctor ", this);
		}

		void Animation::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
			HAL_LOG_DEBUG("Animation:: postCallAsConstructor ", this);
		}

		bool Animation::get_autoreverse() const TITANIUM_NOEXCEPT
		{
			return autoreverse__;
		}

		void Animation::set_autoreverse(const bool& autoreverse) TITANIUM_NOEXCEPT
		{
			autoreverse__ = autoreverse;
		}

		std::string Animation::get_backgroundColor() const TITANIUM_NOEXCEPT
		{
			return backgroundColor__;
		}

		void Animation::set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT
		{
			backgroundColor__ = backgroundColor;
		}

		double Animation::get_bottom() const TITANIUM_NOEXCEPT
		{
			return bottom__;
		}

		void Animation::set_bottom(const double& bottom) TITANIUM_NOEXCEPT
		{
			bottom__ = bottom;
		}

		JSObject Animation::get_center() const TITANIUM_NOEXCEPT
		{
			return center__;
		}

		void Animation::set_center(const JSObject& center) TITANIUM_NOEXCEPT
		{
			center__ = center;
		}

		std::string Animation::get_color() const TITANIUM_NOEXCEPT
		{
			return color__;
		}

		void Animation::set_color(const std::string& color) TITANIUM_NOEXCEPT
		{
			color__ = color;
		}

		ANIMATION_CURVE Animation::get_curve() const TITANIUM_NOEXCEPT
		{
			return curve__;
		}

		void Animation::set_curve(const ANIMATION_CURVE& curve) TITANIUM_NOEXCEPT
		{
			curve__ = curve;
		}

		std::chrono::milliseconds Animation::get_delay() const TITANIUM_NOEXCEPT
		{
			return delay__;
		}
		
		void Animation::set_delay(const std::chrono::milliseconds& delay) TITANIUM_NOEXCEPT
		{
			delay__ = delay;
		}

		std::chrono::milliseconds Animation::get_duration() const TITANIUM_NOEXCEPT
		{
			return duration__;
		}

		void Animation::set_duration(const std::chrono::milliseconds& duration) TITANIUM_NOEXCEPT
		{
			duration__ = duration;
		}

		double Animation::get_height() const TITANIUM_NOEXCEPT
		{
			return height__;
		}

		void Animation::set_height(const double& height) TITANIUM_NOEXCEPT
		{
			height__ = height;
		}

		double Animation::get_left() const TITANIUM_NOEXCEPT
		{
			return left__;
		}

		void Animation::set_left(const double& left) TITANIUM_NOEXCEPT
		{
			left__ = left;
		}

		double Animation::get_opacity() const TITANIUM_NOEXCEPT
		{
			return opacity__;
		}

		void Animation::set_opacity(const double& opacity) TITANIUM_NOEXCEPT
		{
			opacity__ = opacity;
		}

		bool Animation::get_opaque() const TITANIUM_NOEXCEPT
		{
			return opaque__;
		}

		void Animation::set_opaque(const bool& opaque) TITANIUM_NOEXCEPT
		{
			opaque__ = opaque;
		}

		uint32_t Animation::get_repeat() const TITANIUM_NOEXCEPT
		{
			return repeat__;
		}

		void Animation::set_repeat(const uint32_t& repeat) TITANIUM_NOEXCEPT
		{
			repeat__ = repeat;
		}

		double Animation::get_right() const TITANIUM_NOEXCEPT
		{
			return right__;
		}

		void Animation::set_right(const double& right) TITANIUM_NOEXCEPT
		{
			right__ = right;
		}

		double Animation::get_top() const TITANIUM_NOEXCEPT
		{
			return top__;
		}

		void Animation::set_top(const double& top) TITANIUM_NOEXCEPT
		{
			top__ = top;
		}

		JSValue Animation::get_transform() const TITANIUM_NOEXCEPT
		{
			return transform__;
		}

		void Animation::set_transform(const JSValue& transform) TITANIUM_NOEXCEPT
		{
			transform__ = transform;
		}

		uint32_t Animation::get_transition() const TITANIUM_NOEXCEPT
		{
			return transition__;
		}

		void Animation::set_transition(const uint32_t& transition) TITANIUM_NOEXCEPT
		{
			transition__ = transition;
		}

		JSValue Animation::get_view() const TITANIUM_NOEXCEPT
		{
			return view__;
		}

		void Animation::set_view(const JSValue& view) TITANIUM_NOEXCEPT
		{
			view__ = view;
		}

		bool Animation::get_visible() const TITANIUM_NOEXCEPT
		{
			return visible__;
		}

		void Animation::set_visible(const bool& visible) TITANIUM_NOEXCEPT
		{
			visible__ = visible;
		}

		double Animation::get_width() const TITANIUM_NOEXCEPT
		{
			return width__;
		}

		void Animation::set_width(const double& width) TITANIUM_NOEXCEPT
		{
			width__ = width;
		}

		uint32_t Animation::get_zIndex() const TITANIUM_NOEXCEPT
		{
			return zIndex__;
		}
		
		void Animation::set_zIndex(const uint32_t& zIndex) TITANIUM_NOEXCEPT
		{
			zIndex__ = zIndex;
		}

		void Animation::JSExportInitialize() {
			JSExport<Animation>::SetClassVersion(1);
			JSExport<Animation>::SetParent(JSExport<Module>::Class());

			TITANIUM_ADD_PROPERTY(Animation, autoreverse);
			TITANIUM_ADD_PROPERTY(Animation, backgroundColor);
			TITANIUM_ADD_PROPERTY(Animation, bottom);
			TITANIUM_ADD_PROPERTY(Animation, center);
			TITANIUM_ADD_PROPERTY(Animation, color);
			TITANIUM_ADD_PROPERTY(Animation, curve);
			TITANIUM_ADD_PROPERTY(Animation, delay);
			TITANIUM_ADD_PROPERTY(Animation, duration);
			TITANIUM_ADD_PROPERTY(Animation, height);
			TITANIUM_ADD_PROPERTY(Animation, left);
			TITANIUM_ADD_PROPERTY(Animation, opacity);
			TITANIUM_ADD_PROPERTY(Animation, opaque);
			TITANIUM_ADD_PROPERTY(Animation, repeat);
			TITANIUM_ADD_PROPERTY(Animation, right);
			TITANIUM_ADD_PROPERTY(Animation, top);
			TITANIUM_ADD_PROPERTY(Animation, transform);
			TITANIUM_ADD_PROPERTY(Animation, transition);
			TITANIUM_ADD_PROPERTY(Animation, view);
			TITANIUM_ADD_PROPERTY(Animation, visible);
			TITANIUM_ADD_PROPERTY(Animation, width);
			TITANIUM_ADD_PROPERTY(Animation, zIndex);

			TITANIUM_ADD_FUNCTION(Animation, getAutoreverse);
			TITANIUM_ADD_FUNCTION(Animation, setAutoreverse);
			TITANIUM_ADD_FUNCTION(Animation, getBackgroundColor);
			TITANIUM_ADD_FUNCTION(Animation, setBackgroundColor);
			TITANIUM_ADD_FUNCTION(Animation, getBottom);
			TITANIUM_ADD_FUNCTION(Animation, setBottom);
			TITANIUM_ADD_FUNCTION(Animation, getCenter);
			TITANIUM_ADD_FUNCTION(Animation, setCenter);
			TITANIUM_ADD_FUNCTION(Animation, getColor);
			TITANIUM_ADD_FUNCTION(Animation, setColor);
			TITANIUM_ADD_FUNCTION(Animation, getCurve);
			TITANIUM_ADD_FUNCTION(Animation, setCurve);
			TITANIUM_ADD_FUNCTION(Animation, getDelay);
			TITANIUM_ADD_FUNCTION(Animation, setDelay);
			TITANIUM_ADD_FUNCTION(Animation, getDuration);
			TITANIUM_ADD_FUNCTION(Animation, setDuration);
			TITANIUM_ADD_FUNCTION(Animation, getHeight);
			TITANIUM_ADD_FUNCTION(Animation, setHeight);
			TITANIUM_ADD_FUNCTION(Animation, getLeft);
			TITANIUM_ADD_FUNCTION(Animation, setLeft);
			TITANIUM_ADD_FUNCTION(Animation, getOpacity);
			TITANIUM_ADD_FUNCTION(Animation, setOpacity);
			TITANIUM_ADD_FUNCTION(Animation, getOpaque);
			TITANIUM_ADD_FUNCTION(Animation, setOpaque);
			TITANIUM_ADD_FUNCTION(Animation, getRepeat);
			TITANIUM_ADD_FUNCTION(Animation, setRepeat);
			TITANIUM_ADD_FUNCTION(Animation, getRight);
			TITANIUM_ADD_FUNCTION(Animation, setRight);
			TITANIUM_ADD_FUNCTION(Animation, getTop);
			TITANIUM_ADD_FUNCTION(Animation, setTop);
			TITANIUM_ADD_FUNCTION(Animation, getTransform);
			TITANIUM_ADD_FUNCTION(Animation, setTransform);
			TITANIUM_ADD_FUNCTION(Animation, getTransition);
			TITANIUM_ADD_FUNCTION(Animation, setTransition);
			TITANIUM_ADD_FUNCTION(Animation, getView);
			TITANIUM_ADD_FUNCTION(Animation, setView);
			TITANIUM_ADD_FUNCTION(Animation, getVisible);
			TITANIUM_ADD_FUNCTION(Animation, setVisible);
			TITANIUM_ADD_FUNCTION(Animation, getWidth);
			TITANIUM_ADD_FUNCTION(Animation, setWidth);
			TITANIUM_ADD_FUNCTION(Animation, getZIndex);
			TITANIUM_ADD_FUNCTION(Animation, setZIndex);
		}

		TITANIUM_PROPERTY_GETTER(Animation, autoreverse)
		{
			return get_context().CreateBoolean(get_autoreverse());
		}

		TITANIUM_PROPERTY_SETTER(Animation, autoreverse)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_autoreverse(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, backgroundColor)
		{
			return get_context().CreateString(get_backgroundColor());
		}

		TITANIUM_PROPERTY_SETTER(Animation, backgroundColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_backgroundColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, bottom)
		{
			return get_context().CreateNumber(get_bottom());
		}

		TITANIUM_PROPERTY_SETTER(Animation, bottom)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_bottom(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, center)
		{
			return get_center();
		}

		TITANIUM_PROPERTY_SETTER(Animation, center)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_center(static_cast<JSObject>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, color)
		{
			return get_context().CreateString(get_color());
		}

		TITANIUM_PROPERTY_SETTER(Animation, color)
		{
			TITANIUM_ASSERT(argument.IsString());
			set_color(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, curve)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<ANIMATION_CURVE>::type>(get_curve()));
		}

		TITANIUM_PROPERTY_SETTER(Animation, curve)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_curve(Constants::to_ANIMATION_CURVE(static_cast<std::underlying_type<ANIMATION_CURVE>::type>(argument)));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, delay)
		{
			return get_context().CreateNumber(static_cast<double>(get_delay().count()));
		}

		TITANIUM_PROPERTY_SETTER(Animation, delay)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			const auto delay = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(argument)));
			set_delay(delay);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, duration)
		{
			return get_context().CreateNumber(static_cast<double>(get_duration().count()));
		}

		TITANIUM_PROPERTY_SETTER(Animation, duration)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			const auto duration = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(argument)));
			set_duration(duration);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, height)
		{
			return get_context().CreateNumber(get_height());
		}

		TITANIUM_PROPERTY_SETTER(Animation, height)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_height(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, left)
		{
			return get_context().CreateNumber(get_left());
		}

		TITANIUM_PROPERTY_SETTER(Animation, left)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_left(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, opacity)
		{
			return get_context().CreateNumber(get_opacity());
		}

		TITANIUM_PROPERTY_SETTER(Animation, opacity)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_opacity(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, opaque)
		{
			return get_context().CreateBoolean(get_opaque());
		}

		TITANIUM_PROPERTY_SETTER(Animation, opaque)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_opaque(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, repeat)
		{
			return get_context().CreateNumber(get_repeat());
		}

		TITANIUM_PROPERTY_SETTER(Animation, repeat)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_repeat(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, right)
		{
			return get_context().CreateNumber(get_right());
		}

		TITANIUM_PROPERTY_SETTER(Animation, right)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_right(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, top)
		{
			return get_context().CreateNumber(get_top());
		}

		TITANIUM_PROPERTY_SETTER(Animation, top)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_top(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, transform)
		{
			return get_transform();
		}

		TITANIUM_PROPERTY_SETTER(Animation, transform)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_transform(static_cast<JSObject>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, transition)
		{
			return get_context().CreateNumber(get_transition());
		}

		TITANIUM_PROPERTY_SETTER(Animation, transition)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_transition(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, view)
		{
			return get_view();
		}

		TITANIUM_PROPERTY_SETTER(Animation, view)
		{
			TITANIUM_ASSERT(argument.IsObject());
			set_view(static_cast<JSObject>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, visible)
		{
			return get_context().CreateBoolean(get_visible());
		}

		TITANIUM_PROPERTY_SETTER(Animation, visible)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_visible(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, width)
		{
			return get_context().CreateNumber(get_width());
		}

		TITANIUM_PROPERTY_SETTER(Animation, width)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_width(static_cast<double>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(Animation, zIndex)
		{
			return get_context().CreateNumber(get_zIndex());
		}

		TITANIUM_PROPERTY_SETTER(Animation, zIndex)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			set_zIndex(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_FUNCTION(Animation, getAutoreverse)
		{
			TITANIUM_LOG_WARN("Animation.getAutoreverse is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setAutoreverse)
		{
			if (arguments.size() >= 1) {
				js_set_autoreverse(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getBackgroundColor)
		{
			TITANIUM_LOG_WARN("Animation.getBackgroundColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setBackgroundColor)
		{
			if (arguments.size() >= 1) {
				js_set_backgroundColor(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getBottom)
		{
			TITANIUM_LOG_WARN("Animation.getBottom is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setBottom)
		{
			if (arguments.size() >= 1) {
				js_set_bottom(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getCenter)
		{
			TITANIUM_LOG_WARN("Animation.getCenter is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setCenter)
		{
			if (arguments.size() >= 1) {
				js_set_center(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getColor)
		{
			TITANIUM_LOG_WARN("Animation.getColor is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setColor)
		{
			if (arguments.size() >= 1) {
				js_set_color(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getCurve)
		{
			TITANIUM_LOG_WARN("Animation.getCurve is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setCurve)
		{
			if (arguments.size() >= 1) {
				js_set_curve(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getDelay)
		{
			TITANIUM_LOG_WARN("Animation.getDelay is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setDelay)
		{
			if (arguments.size() >= 1) {
				js_set_delay(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getDuration)
		{
			TITANIUM_LOG_WARN("Animation.getDuration is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setDuration)
		{
			if (arguments.size() >= 1) {
				js_set_duration(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getHeight)
		{
			TITANIUM_LOG_WARN("Animation.getHeight is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setHeight)
		{
			if (arguments.size() >= 1) {
				js_set_height(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getLeft)
		{
			TITANIUM_LOG_WARN("Animation.getLeft is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setLeft)
		{
			if (arguments.size() >= 1) {
				js_set_left(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getOpacity)
		{
			TITANIUM_LOG_WARN("Animation.getOpacity is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setOpacity)
		{
			if (arguments.size() >= 1) {
				js_set_opacity(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getOpaque)
		{
			TITANIUM_LOG_WARN("Animation.getOpaque is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setOpaque)
		{
			if (arguments.size() >= 1) {
				js_set_opaque(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getRepeat)
		{
			TITANIUM_LOG_WARN("Animation.getRepeat is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setRepeat)
		{
			if (arguments.size() >= 1) {
				js_set_repeat(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getRight)
		{
			TITANIUM_LOG_WARN("Animation.getRight is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setRight)
		{
			if (arguments.size() >= 1) {
				js_set_right(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getTop)
		{
			TITANIUM_LOG_WARN("Animation.getTop is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setTop)
		{
			if (arguments.size() >= 1) {
				js_set_top(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getTransform)
		{
			TITANIUM_LOG_WARN("Animation.getTransform is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setTransform)
		{
			if (arguments.size() >= 1) {
				js_set_transform(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getTransition)
		{
			TITANIUM_LOG_WARN("Animation.getTransition is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setTransition)
		{
			if (arguments.size() >= 1) {
				js_set_transition(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getView)
		{
			TITANIUM_LOG_WARN("Animation.getView is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setView)
		{
			if (arguments.size() >= 1) {
				js_set_view(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getVisible)
		{
			TITANIUM_LOG_WARN("Animation.getVisible is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setVisible)
		{
			if (arguments.size() >= 1) {
				js_set_visible(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getWidth)
		{
			TITANIUM_LOG_WARN("Animation.getWidth is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setWidth)
		{
			if (arguments.size() >= 1) {
				js_set_width(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, getZIndex)
		{
			TITANIUM_LOG_WARN("Animation.getZIndex is not implemented yet");
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(Animation, setZIndex)
		{
			if (arguments.size() >= 1) {
				js_set_zIndex(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium