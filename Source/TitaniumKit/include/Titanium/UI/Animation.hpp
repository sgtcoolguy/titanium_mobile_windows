/**
 * Titanium.UI.Animation for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_ANIMATION_HPP_
#define _TITANIUM_ANIMATION_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/UI/Constants.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium Animation Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Animation
		*/
		class TITANIUMKIT_EXPORT Animation : public Module, public JSExport<Animation>
		{

		public:

			/*!
			  @property
			  @abstract autoreverse
			  @discussion Specifies if the animation should be replayed in reverse upon completion.
			*/
			virtual bool get_autoreverse() const TITANIUM_NOEXCEPT final;
			virtual void set_autoreverse(const bool& autoreverse) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract backgroundColor
			  @discussion Value of the `backgroundColor` property at the end of the animation, as a color name or hex triplet.
			*/
			virtual std::string get_backgroundColor() const TITANIUM_NOEXCEPT final;
			virtual void set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract bottom
			  @discussion Value of the `bottom` property at the end of the animation.
			*/
			virtual double get_bottom() const TITANIUM_NOEXCEPT final;
			virtual void set_bottom(const double& bottom) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract center
			  @discussion Value of the `center` property at the end of the animation.
			*/
			virtual JSObject get_center() const TITANIUM_NOEXCEPT final;
			virtual void set_center(const JSObject& center) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract color
			  @discussion Value of the `color` property at the end of the animation, as a color name or hex triplet.
			*/
			virtual std::string get_color() const TITANIUM_NOEXCEPT final;
			virtual void set_color(const std::string& color) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract curve
			  @discussion Animation curve or easing function to apply to the animation.
			*/
			virtual ANIMATION_CURVE get_curve() const TITANIUM_NOEXCEPT final;
			virtual void set_curve(const ANIMATION_CURVE& curve) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract delay
			  @discussion Delay, in milliseconds before starting the animation.
			*/
			virtual std::chrono::milliseconds get_delay() const TITANIUM_NOEXCEPT final;
			virtual void set_delay(const std::chrono::milliseconds& delay) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract duration
			  @discussion Duration of the animation, in milliseconds.
			*/
			virtual std::chrono::milliseconds get_duration() const TITANIUM_NOEXCEPT final;
			virtual void set_duration(const std::chrono::milliseconds& duration) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract height
			  @discussion Value of the `height` property at the end of the animation.
			*/
			virtual double get_height() const TITANIUM_NOEXCEPT final;
			virtual void set_height(const double& height) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract left
			  @discussion Value of the `left` property at the end of the animation.
			*/
			virtual double get_left() const TITANIUM_NOEXCEPT final;
			virtual void set_left(const double& left) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract opacity
			  @discussion Value of the `opacity` property at the end of the animation.
			*/
			virtual double get_opacity() const TITANIUM_NOEXCEPT final;
			virtual void set_opacity(const double& opacity) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract opaque
			  @discussion Value of the `opaque` property at the end of the animation.
			*/
			virtual bool get_opaque() const TITANIUM_NOEXCEPT final;
			virtual void set_opaque(const bool& opaque) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract repeat
			  @discussion Number of times the animation should be performed.
			*/
			virtual uint32_t get_repeat() const TITANIUM_NOEXCEPT final;
			virtual void set_repeat(const uint32_t& repeat) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract right
			  @discussion Value of the `right` property at the end of the animation.
			*/
			virtual double get_right() const TITANIUM_NOEXCEPT final;
			virtual void set_right(const double& right) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract top
			  @discussion Value of the `top` property at the end of the animation.
			*/
			virtual double get_top() const TITANIUM_NOEXCEPT final;
			virtual void set_top(const double& top) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract transform
			  @discussion Animate the view from its current tranform to the specified transform.
			*/
			virtual JSValue get_transform() const TITANIUM_NOEXCEPT final;
			virtual void set_transform(const JSValue& transform) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract transition
			  @discussion Transition type to use during a transition animation.
			*/
			virtual uint32_t get_transition() const TITANIUM_NOEXCEPT final;
			virtual void set_transition(const uint32_t& transition) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract view
			  @discussion New view to transition to.
			*/
			virtual JSValue get_view() const TITANIUM_NOEXCEPT final;
			virtual void set_view(const JSValue& view) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract visible
			  @discussion Value of the `visible` property at the end of the animation.
			*/
			virtual bool get_visible() const TITANIUM_NOEXCEPT final;
			virtual void set_visible(const bool& visible) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract width
			  @discussion Value of the `width` property at the end of the animation.
			*/
			virtual double get_width() const TITANIUM_NOEXCEPT final;
			virtual void set_width(const double& width) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract zIndex
			  @discussion Value of the `zIndex` property at the end of the animation.
			*/
			virtual uint32_t get_zIndex() const TITANIUM_NOEXCEPT final;
			virtual void set_zIndex(const uint32_t& width) TITANIUM_NOEXCEPT;

			Animation(const JSContext&) TITANIUM_NOEXCEPT;
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual ~Animation() = default;
			Animation(const Animation&) = default;
			Animation& operator=(const Animation&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Animation(Animation&&)                 = default;
			Animation& operator=(Animation&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(autoreverse);
			TITANIUM_FUNCTION_DEF(getAutoreverse);
			TITANIUM_FUNCTION_DEF(setAutoreverse);

			TITANIUM_PROPERTY_DEF(backgroundColor);
			TITANIUM_FUNCTION_DEF(getBackgroundColor);
			TITANIUM_FUNCTION_DEF(setBackgroundColor);

			TITANIUM_PROPERTY_DEF(bottom);
			TITANIUM_FUNCTION_DEF(getBottom);
			TITANIUM_FUNCTION_DEF(setBottom);

			TITANIUM_PROPERTY_DEF(center);
			TITANIUM_FUNCTION_DEF(getCenter);
			TITANIUM_FUNCTION_DEF(setCenter);

			TITANIUM_PROPERTY_DEF(color);
			TITANIUM_FUNCTION_DEF(getColor);
			TITANIUM_FUNCTION_DEF(setColor);

			TITANIUM_PROPERTY_DEF(curve);
			TITANIUM_FUNCTION_DEF(getCurve);
			TITANIUM_FUNCTION_DEF(setCurve);

			TITANIUM_PROPERTY_DEF(delay);
			TITANIUM_FUNCTION_DEF(getDelay);
			TITANIUM_FUNCTION_DEF(setDelay);

			TITANIUM_PROPERTY_DEF(duration);
			TITANIUM_FUNCTION_DEF(getDuration);
			TITANIUM_FUNCTION_DEF(setDuration);

			TITANIUM_PROPERTY_DEF(height);
			TITANIUM_FUNCTION_DEF(getHeight);
			TITANIUM_FUNCTION_DEF(setHeight);

			TITANIUM_PROPERTY_DEF(left);
			TITANIUM_FUNCTION_DEF(getLeft);
			TITANIUM_FUNCTION_DEF(setLeft);

			TITANIUM_PROPERTY_DEF(opacity);
			TITANIUM_FUNCTION_DEF(getOpacity);
			TITANIUM_FUNCTION_DEF(setOpacity);

			TITANIUM_PROPERTY_DEF(opaque);
			TITANIUM_FUNCTION_DEF(getOpaque);
			TITANIUM_FUNCTION_DEF(setOpaque);

			TITANIUM_PROPERTY_DEF(repeat);
			TITANIUM_FUNCTION_DEF(getRepeat);
			TITANIUM_FUNCTION_DEF(setRepeat);

			TITANIUM_PROPERTY_DEF(right);
			TITANIUM_FUNCTION_DEF(getRight);
			TITANIUM_FUNCTION_DEF(setRight);

			TITANIUM_PROPERTY_DEF(top);
			TITANIUM_FUNCTION_DEF(getTop);
			TITANIUM_FUNCTION_DEF(setTop);

			TITANIUM_PROPERTY_DEF(transform);
			TITANIUM_FUNCTION_DEF(getTransform);
			TITANIUM_FUNCTION_DEF(setTransform);

			TITANIUM_PROPERTY_DEF(transition);
			TITANIUM_FUNCTION_DEF(getTransition);
			TITANIUM_FUNCTION_DEF(setTransition);

			TITANIUM_PROPERTY_DEF(view);
			TITANIUM_FUNCTION_DEF(getView);
			TITANIUM_FUNCTION_DEF(setView);

			TITANIUM_PROPERTY_DEF(visible);
			TITANIUM_FUNCTION_DEF(getVisible);
			TITANIUM_FUNCTION_DEF(setVisible);

			TITANIUM_PROPERTY_DEF(width);
			TITANIUM_FUNCTION_DEF(getWidth);
			TITANIUM_FUNCTION_DEF(setWidth);

			TITANIUM_PROPERTY_DEF(zIndex);
			TITANIUM_FUNCTION_DEF(getZIndex);
			TITANIUM_FUNCTION_DEF(setZIndex);

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				bool autoreverse__;
				std::string backgroundColor__;
				double bottom__;
				JSObject center__;
				std::string color__;
				ANIMATION_CURVE curve__;
				std::chrono::milliseconds delay__;
				std::chrono::milliseconds duration__;
				double height__;
				double left__;
				double opacity__;
				bool opaque__;
				uint32_t repeat__;
				double right__;
				double top__;
				JSValue transform__;
				uint32_t transition__;
				JSValue view__;
				bool visible__;
				double width__;
				uint32_t zIndex__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_ANIMATION_HPP_