/**
 * TitaniumKit ViewLayoutPolicy
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ViewLayoutPolicy.hpp"

namespace Titanium
{
	namespace UI
	{
		ViewLayoutPolicy::ViewLayoutPolicy() TITANIUM_NOEXCEPT :
			opacity__(1.0),
			borderRadius__(0),
			borderWidth__(0),
			touchEnabled__(true),
			visible__(true),
			defaultWidth__(Titanium::UI::LAYOUT::SIZE),
			defaultHeight__(Titanium::UI::LAYOUT::SIZE)
		{

		}

		ViewLayoutPolicy::~ViewLayoutPolicy() 
		{

		}

		void ViewLayoutPolicy::add(const std::shared_ptr<Titanium::UI::View>& view) TITANIUM_NOEXCEPT
		{
			children__.push_back(view);
		}

		void ViewLayoutPolicy::animate(JSObject& animation, JSObject& callback, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ViewLayoutPolicy::animate: Unimplemented");
		}

		void ViewLayoutPolicy::hide() TITANIUM_NOEXCEPT
		{
			set_visible(false);
		}

		void ViewLayoutPolicy::show() TITANIUM_NOEXCEPT
		{
			set_visible(true);
		}

		std::vector<std::shared_ptr<Titanium::UI::View>> ViewLayoutPolicy::get_children() const TITANIUM_NOEXCEPT
		{
			return children__;
		}

		std::string ViewLayoutPolicy::get_backgroundColor() const TITANIUM_NOEXCEPT
		{
			return backgroundColor__;
		}

		void ViewLayoutPolicy::set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT
		{
			backgroundColor__ = backgroundColor;
		}

		std::string ViewLayoutPolicy::get_borderColor() const TITANIUM_NOEXCEPT
		{
			return borderColor__;
		}

		void ViewLayoutPolicy::set_borderColor(const std::string& borderColor) TITANIUM_NOEXCEPT
		{
			borderColor__ = borderColor;
		}

		uint32_t ViewLayoutPolicy::get_borderRadius() const TITANIUM_NOEXCEPT
		{
			return borderRadius__;
		}

		void ViewLayoutPolicy::set_borderRadius(const uint32_t& borderRadius) TITANIUM_NOEXCEPT
		{
			borderRadius__ = borderRadius;
		}

		uint32_t ViewLayoutPolicy::get_borderWidth() const TITANIUM_NOEXCEPT
		{
			return borderWidth__;
		}

		void ViewLayoutPolicy::set_borderWidth(const uint32_t& borderWidth) TITANIUM_NOEXCEPT
		{
			borderWidth__ = borderWidth;
		}

		double ViewLayoutPolicy::get_opacity() const TITANIUM_NOEXCEPT
		{
			return opacity__;
		}

		void ViewLayoutPolicy::set_opacity(const double& opacity) TITANIUM_NOEXCEPT
		{
			opacity__ = opacity;
		}

		Dimension ViewLayoutPolicy::get_rect() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ViewLayoutPolicy::get_rect: Unimplemented");
			Dimension dimension;
			return dimension;
		}

		Dimension ViewLayoutPolicy::get_size() const TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ViewLayoutPolicy::get_size: Unimplemented");
			Dimension dimension;
			return dimension;
		}

		bool ViewLayoutPolicy::get_visible() const TITANIUM_NOEXCEPT
		{
			return visible__;
		}

		void ViewLayoutPolicy::set_visible(const bool& visible) TITANIUM_NOEXCEPT
		{
			visible__ = visible;
		}

		std::string ViewLayoutPolicy::get_tintColor() const TITANIUM_NOEXCEPT
		{
			return tintColor__;
		}

		void ViewLayoutPolicy::set_tintColor(const std::string& tintColor) TITANIUM_NOEXCEPT
		{
			tintColor__ = tintColor;
		}

		bool ViewLayoutPolicy::get_touchEnabled() const TITANIUM_NOEXCEPT
		{
			return touchEnabled__;
		}

		void ViewLayoutPolicy::set_touchEnabled(const bool& touchEnabled) TITANIUM_NOEXCEPT
		{
			touchEnabled__ = touchEnabled;
		}

		std::string ViewLayoutPolicy::get_top() const TITANIUM_NOEXCEPT
		{
			return top__;
		}

		void ViewLayoutPolicy::set_top(const std::string& top) TITANIUM_NOEXCEPT
		{
			top__ = top;
		}

		std::string ViewLayoutPolicy::get_left() const TITANIUM_NOEXCEPT
		{
			return left__;
		}

		void ViewLayoutPolicy::set_left(const std::string& left) TITANIUM_NOEXCEPT
		{
			left__ = left;
		}

		std::string ViewLayoutPolicy::get_bottom() const TITANIUM_NOEXCEPT
		{
			return bottom__;
		}

		void ViewLayoutPolicy::set_bottom(const std::string& bottom) TITANIUM_NOEXCEPT
		{
			bottom__ = bottom;
		}

		std::string ViewLayoutPolicy::get_right() const TITANIUM_NOEXCEPT
		{
			return right__;
		}

		void ViewLayoutPolicy::set_right(const std::string& right) TITANIUM_NOEXCEPT
		{
			right__ = right;
		}

		Point ViewLayoutPolicy::get_center() const TITANIUM_NOEXCEPT
		{
			return center__;
		}

		void ViewLayoutPolicy::set_center(const Point& center) TITANIUM_NOEXCEPT
		{
			center__ = center;
		}

		std::string ViewLayoutPolicy::get_width() const TITANIUM_NOEXCEPT
		{
			return width__;
		}

		void ViewLayoutPolicy::set_width(const std::string& width) TITANIUM_NOEXCEPT
		{
			width__ = width;
		}

		std::string ViewLayoutPolicy::get_minWidth() const TITANIUM_NOEXCEPT
		{
			return minWidth__;
		}

		void ViewLayoutPolicy::set_minWidth(const std::string& width) TITANIUM_NOEXCEPT
		{
			minWidth__ = width;
		}

		std::string ViewLayoutPolicy::get_height() const TITANIUM_NOEXCEPT
		{
			return height__;
		}

		void ViewLayoutPolicy::set_height(const std::string& height) TITANIUM_NOEXCEPT
		{
			height__ = height;
		}

		std::string ViewLayoutPolicy::get_minHeight() const TITANIUM_NOEXCEPT
		{
			return minHeight__;
		}

		void ViewLayoutPolicy::set_minHeight(const std::string& height) TITANIUM_NOEXCEPT
		{
			minHeight__ = height;
		}

		std::string ViewLayoutPolicy::get_layout() const TITANIUM_NOEXCEPT
		{
			return layout__;
		}

		void ViewLayoutPolicy::set_layout(const std::string& layout) TITANIUM_NOEXCEPT
		{
			layout__ = layout;
		}

		Titanium::UI::LAYOUT ViewLayoutPolicy::get_defaultWidth() const TITANIUM_NOEXCEPT
		{
			return defaultWidth__;
		}

		void ViewLayoutPolicy::set_defaultWidth(const Titanium::UI::LAYOUT& value) TITANIUM_NOEXCEPT
		{
			defaultWidth__ = value;
		}

		Titanium::UI::LAYOUT ViewLayoutPolicy::get_defaultHeight() const TITANIUM_NOEXCEPT
		{
			return defaultHeight__;
		}

		void ViewLayoutPolicy::set_defaultHeight(const Titanium::UI::LAYOUT& value) TITANIUM_NOEXCEPT
		{
			defaultHeight__ = value;
		}

		void ViewLayoutPolicy::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ViewLayoutPolicy::disableEvent: Unimplemented");
		}

		void ViewLayoutPolicy::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("ViewLayoutPolicy::enableEvent: Unimplemented");
		}
	} // namespace UI
}  // namespace Titanium
