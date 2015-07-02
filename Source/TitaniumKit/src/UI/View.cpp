/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Point.hpp"
#include "Titanium/UI/Animation.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace UI
	{
		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : Module(js_context)
		{
		}

		View::~View() TITANIUM_NOEXCEPT
		{
		}

		void View::postInitialize(JSObject& this_object)
		{
			Titanium::Module::postInitialize(this_object);
		}

		void View::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::Module::postCallAsConstructor(js_context, arguments);	
			setLayoutDelegate();
		}

		void View::animate(const std::shared_ptr<Animation>& animation, JSObject& callback) TITANIUM_NOEXCEPT
		{
			layoutDelegate__->animate(animation, callback, get_object());
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Module>::Class());
			// methods

			TITANIUM_ADD_FUNCTION(View, add);
			TITANIUM_ADD_FUNCTION(View, animate);
			TITANIUM_ADD_FUNCTION(View, hide);
			TITANIUM_ADD_FUNCTION(View, remove);
			TITANIUM_ADD_FUNCTION(View, show);

			// properties
			TITANIUM_ADD_PROPERTY(View, backgroundColor);
			TITANIUM_ADD_PROPERTY(View, borderColor);
			TITANIUM_ADD_PROPERTY(View, borderRadius);
			TITANIUM_ADD_PROPERTY(View, borderWidth);
			TITANIUM_ADD_PROPERTY(View, bottom);
			TITANIUM_ADD_PROPERTY(View, center);
			TITANIUM_ADD_PROPERTY_READONLY(View, children);
			TITANIUM_ADD_PROPERTY(View, height);
			TITANIUM_ADD_PROPERTY(View, layout);
			TITANIUM_ADD_PROPERTY(View, left);
			TITANIUM_ADD_PROPERTY(View, opacity);
			TITANIUM_ADD_PROPERTY_READONLY(View, rect);
			TITANIUM_ADD_PROPERTY(View, right);
			TITANIUM_ADD_PROPERTY_READONLY(View, size);
			TITANIUM_ADD_PROPERTY(View, tintColor);
			TITANIUM_ADD_PROPERTY(View, top);
			TITANIUM_ADD_PROPERTY(View, touchEnabled);
			TITANIUM_ADD_PROPERTY(View, visible);
			TITANIUM_ADD_PROPERTY(View, width);
		}

		TITANIUM_FUNCTION(View, add)
		{
			ENSURE_OBJECT_AT_INDEX(view, 0);
			layoutDelegate__->add(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(View, animate)
		{
			ENSURE_OBJECT_AT_INDEX(object, 0);

			ENSURE_OPTIONAL_OBJECT_AT_INDEX(callback, 1);

			// Convert the animation object into a Ti.UI.Animation if it isn't one already
			auto animation = object.GetPrivate<Titanium::UI::Animation>();
			if (animation == nullptr) {
				// It's not already backed by a native class, we need to generate one from it!
				JSValue Titanium_property = get_context().get_global_object().GetProperty("Titanium");
				TITANIUM_ASSERT(Titanium_property.IsObject());
				JSObject Titanium = static_cast<JSObject>(Titanium_property);
					
				JSValue UI_property = Titanium.GetProperty("UI");
				TITANIUM_ASSERT(UI_property.IsObject());
				JSObject UI = static_cast<JSObject>(UI_property);
					
				JSValue Animation_property = UI.GetProperty("Animation");
				TITANIUM_ASSERT(Animation_property.IsObject());
				JSObject Animation_Class = static_cast<JSObject>(Animation_property);
				
				auto instance = Animation_Class.CallAsConstructor();
				Titanium::Module::applyProperties(object, instance);
				animation = instance.GetPrivate<Titanium::UI::Animation>();
			}

			animate(animation, callback);
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(View, hide)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			layoutDelegate__->hide();
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(View, remove)
		{
			ENSURE_OBJECT_AT_INDEX(view, 0);
			layoutDelegate__->remove(view.GetPrivate<View>());
			return get_context().CreateUndefined();
		}

		TITANIUM_FUNCTION(View, show)
		{
			TITANIUM_ASSERT(arguments.size() == 0);
			layoutDelegate__->show();
			return get_context().CreateUndefined();
		}

		TITANIUM_PROPERTY_GETTER(View, backgroundColor)
		{
			return get_context().CreateString(layoutDelegate__->get_backgroundColor());
		}

		TITANIUM_PROPERTY_SETTER(View, backgroundColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutDelegate__->set_backgroundColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, borderColor)
		{
			return get_context().CreateString(layoutDelegate__->get_borderColor());
		}

		TITANIUM_PROPERTY_SETTER(View, borderColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutDelegate__->set_borderColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, borderRadius)
		{
			return get_context().CreateNumber(layoutDelegate__->get_borderRadius());
		}

		TITANIUM_PROPERTY_SETTER(View, borderRadius)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			layoutDelegate__->set_borderRadius(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, borderWidth)
		{
			return get_context().CreateNumber(layoutDelegate__->get_borderWidth());
		}

		TITANIUM_PROPERTY_SETTER(View, borderWidth)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			layoutDelegate__->set_borderWidth(static_cast<uint32_t>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, bottom)
		{
			return get_context().CreateString(layoutDelegate__->get_bottom());
		}

		TITANIUM_PROPERTY_SETTER(View, bottom)
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_bottom(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_SETTER(View, center)
		{
			TITANIUM_ASSERT(argument.IsObject());
			layoutDelegate__->set_center(js_to_Point(static_cast<JSObject>(argument)));
			return true;
		}
		
		TITANIUM_PROPERTY_GETTER(View, center)
		{
			return Point_to_js(get_context(), layoutDelegate__->get_center());
		}

		TITANIUM_PROPERTY_GETTER(View, children)
		{
			std::vector<JSValue> js_children;
			const auto children = layoutDelegate__->get_children();
			for (auto child : children) {
				js_children.push_back(child->get_object());
			}
			return get_context().CreateArray(js_children);
		}

		TITANIUM_PROPERTY_GETTER(View, height)
		{
			return get_context().CreateString(layoutDelegate__->get_height());
		}

		TITANIUM_PROPERTY_SETTER(View, height)
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_height(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, layout)
		{
			return get_context().CreateString(layoutDelegate__->get_layout());
		}

		TITANIUM_PROPERTY_SETTER(View, layout)
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutDelegate__->set_layout(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, left)
		{
			return get_context().CreateString(layoutDelegate__->get_left());
		}

		TITANIUM_PROPERTY_SETTER(View, left)
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_left(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, opacity)
		{
			return get_context().CreateNumber(layoutDelegate__->get_opacity());
		}

		TITANIUM_PROPERTY_SETTER(View, opacity)
		{
			if (argument.IsNumber()) {
				layoutDelegate__->set_opacity(static_cast<double>(argument));
			}
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, rect)
		{
			return Titanium::UI::Dimension_to_js(get_context(), layoutDelegate__->get_rect());
		}

		TITANIUM_PROPERTY_GETTER(View, right)
		{
			return get_context().CreateString(layoutDelegate__->get_right());
		}

		TITANIUM_PROPERTY_SETTER(View, right)
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_right(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, size)
		{
			return Titanium::UI::Dimension_to_js(get_context(), layoutDelegate__->get_size());
		}

		TITANIUM_PROPERTY_GETTER(View, tintColor)
		{
			return get_context().CreateString(layoutDelegate__->get_tintColor());
		}

		TITANIUM_PROPERTY_SETTER(View, tintColor)
		{
			TITANIUM_ASSERT(argument.IsString());
			layoutDelegate__->set_tintColor(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, top)
		{
			return get_context().CreateString(layoutDelegate__->get_top());
		}

		TITANIUM_PROPERTY_SETTER(View, top)
		{
			// FIXME What does setting top to null mean? Because corporate directory does it...
			if (argument.IsNull()) {
				return false;
			}
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_top(static_cast<std::string>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, touchEnabled)
		{
			return get_context().CreateBoolean(layoutDelegate__->get_touchEnabled());
		}

		TITANIUM_PROPERTY_SETTER(View, touchEnabled)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			layoutDelegate__->set_touchEnabled(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, visible)
		{
			return get_context().CreateBoolean(layoutDelegate__->get_visible());
		}

		TITANIUM_PROPERTY_SETTER(View, visible)
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			layoutDelegate__->set_visible(static_cast<bool>(argument));
			return true;
		}

		TITANIUM_PROPERTY_GETTER(View, width)
		{
			return get_context().CreateString(layoutDelegate__->get_width());
		}

		TITANIUM_PROPERTY_SETTER(View, width)
		{
			TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
			layoutDelegate__->set_width(static_cast<std::string>(argument));
			return true;
		}

		void View::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			layoutDelegate__->disableEvent(event_name);
		}

		void View::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			layoutDelegate__->enableEvent(event_name);
		}

	} // namespace UI
}  // namespace Titanium
