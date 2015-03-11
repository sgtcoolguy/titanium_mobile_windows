/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_VIEW_HPP_
#define _TITANIUM_UI_VIEW_HPP_

#include "Titanium/Module.hpp"
#include <vector>
#include <memory>
#include "Titanium/UI/Animation.hpp"
#include "Titanium/UI/ViewLayoutPolicy.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class View;

		/*!
		  @class

		  @discussion This is the Titanium UI View.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.View
		*/
		class TITANIUMKIT_EXPORT View : public Module, public JSExport<View>
		{
		public:
			/*!
			  @method

			  @abstract animate( animation, callback ) : void

			  @discussion Animates this view.

			  The Animation object or dictionary passed to this method defines the end state for the animation, the duration of the animation, and other properties.

			  Note that if you use animate to move a view, the view's actual position is changed, but its layout properties, such as top, left, center and so on are not changed--these reflect the original values set by the user, not the actual position of the view.

			  The rect property can be used to determine the actual size and position of the view. Note that on Mobile Web and Tizen, the rect property is not updated after animation. This is a known issue TIMOB-8930.

			  @param animation : Titanium.UI.Animation/Dictionary<Titanium.UI.Animation>
			  Either a dictionary of animation properties or an Animation object.

			  @param callback : Callback<Object>
			  Function to be invoked upon completion of the animation.

			  @result void
			*/
			virtual void animate(JSObject& animation, JSObject& callback) TITANIUM_NOEXCEPT;

			View(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~View() TITANIUM_NOEXCEPT;  //= default;
			View(const View&) = default;
			View& operator=(const View&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			View(View&&) = default;
			View& operator=(View&&) = default;
#endif

			// TODO: The following functions can automatically be generated
			// from the YAML API docs.
			static void JSExportInitialize();

			virtual JSValue js_add(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_animate(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_hide(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;
			virtual JSValue js_show(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_backgroundColor() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_backgroundColor(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_borderColor() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_borderColor(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_borderRadius() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_borderRadius(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_borderWidth() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_borderWidth(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_opacity() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_opacity(const JSValue& argument) TITANIUM_NOEXCEPT final;
			
			virtual JSValue js_get_tintColor() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_tintColor(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_touchEnabled() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_touchEnabled(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_visible() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_visible(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_top() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_top(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_left() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_left(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_bottom() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_bottom(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_right() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_right(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_width() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_width(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_height() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_height(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual JSValue js_get_layout() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_layout(const JSValue& argument) TITANIUM_NOEXCEPT final;
			
			virtual JSValue js_get_children() const TITANIUM_NOEXCEPT final;
			
			virtual JSValue js_get_center() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_center(const JSValue& argument) TITANIUM_NOEXCEPT final;

			virtual void postInitialize(JSObject& this_object) override;
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			template<typename T>
			std::shared_ptr<T> getViewLayoutPolicy()
			{
				return std::dynamic_pointer_cast<T>(layoutPolicy__);
			}

		protected:
			template<typename T, typename... Us>
			void setLayoutPolicy(Us&&... constructor_arguments) TITANIUM_NOEXCEPT
			{
				layoutPolicy__ = std::make_shared<T>(std::forward<Us>(constructor_arguments)...);
				layoutPolicy__->postInitialize();
			}

#pragma warning(push)
#pragma warning(disable : 4251)
			std::shared_ptr<ViewLayoutPolicy> layoutPolicy__;
#pragma warning(pop)
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_VIEW_HPP_
