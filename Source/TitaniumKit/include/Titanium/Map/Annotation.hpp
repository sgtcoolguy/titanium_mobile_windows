/**
 * TitaniumKit Titanium.Map.Annotation
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MAP_ANNOTATION_HPP_
#define _TITANIUM_MAP_ANNOTATION_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace Map
	{

		using namespace HAL;
		using TiView_shared_ptr_t = std::shared_ptr<Titanium::UI::View>;

		/*!
		  @class
		  @discussion This is the Titanium Annotation Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Map.Annotation
		*/
		class TITANIUMKIT_EXPORT Annotation : public Module, public JSExport<Annotation>
		{

		public:

			/*!
			  @property
			  @abstract animate
			  @discussion Boolean to indicate whether the pin should animate when dropped.
			*/
			virtual bool get_animate() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract image
			  @discussion Image to use for the the pin.
			*/
			virtual std::string get_image() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract latitude
			  @discussion Latitude of the annotation, in decimal degrees.
			*/
			virtual double get_latitude() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract longitude
			  @discussion Longitude of the annotation, in decimal degrees.
			*/
			virtual double get_longitude() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract leftButton
			  @discussion Left button image on the annotation, specified as an image URL or an iOSbutton constant.
			*/
			virtual std::string get_leftButton() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract leftView
			  @discussion Left view that is displayed on the annotation.
			*/
			virtual TiView_shared_ptr_t get_leftView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract pincolor
			  @discussion Pin color. Specify one of: <Titanium.Map.ANNOTATION_GREEN>, <Titanium.Map.ANNOTATION_PURPLE> or <Titanium.Map.ANNOTATION_RED>.
			*/
			virtual double get_pincolor() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rightButton
			  @discussion Right button image on the annotation, specified as an image URL or an iOSbutton constant.
			*/
			virtual std::string get_rightButton() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rightView
			  @discussion Right view that is displayed on the annotation.
			*/
			virtual TiView_shared_ptr_t get_rightView() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract subtitle
			  @discussion Secondary title of the annotation view.
			*/
			virtual std::string get_subtitle() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract subtitleid
			  @discussion Key in the locale file to use for the subtitle property.
			*/
			virtual std::string get_subtitleid() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract title
			  @discussion Primary title of the annotation view.
			*/
			virtual std::string get_title() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract titleid
			  @discussion Key in the locale file to use for the title property.
			*/
			virtual std::string get_titleid() const TITANIUM_NOEXCEPT;

			Annotation(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Annotation() = default;
			Annotation(const Annotation&) = default;
			Annotation& operator=(const Annotation&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Annotation(Annotation&&)                 = default;
			Annotation& operator=(Annotation&&)      = default;
#endif

			static void JSExportInitialize();

			virtual JSValue js_get_animate() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_image() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_latitude() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_longitude() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_leftButton() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_leftView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_pincolor() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_rightButton() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_rightView() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_subtitle() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_subtitleid() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_title() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_titleid() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_getAnimate(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setAnimate(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getLatitude(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLatitude(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getLongitude(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLongitude(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getLeftButton(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLeftButton(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getLeftView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLeftView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getPincolor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setPincolor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRightButton(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRightButton(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRightView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRightView(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSubtitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSubtitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSubtitleid(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSubtitleid(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getTitleid(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setTitleid(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				bool animate__;
				std::string image__;
				double latitude__;
				double longitude__;
				std::string leftButton__;
				TiView_shared_ptr_t leftView__;
				double pincolor__;
				std::string rightButton__;
				TiView_shared_ptr_t rightView__;
				std::string subtitle__;
				std::string subtitleid__;
				std::string title__;
				std::string titleid__;
#pragma warning(pop)
		};

	} // namespace Map
} // namespace Titanium
#endif // _TITANIUM_MAP_ANNOTATION_HPP_