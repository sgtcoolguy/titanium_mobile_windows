/**
* Titanium.UI.ImageView for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_UI_IMAGEVIEW_HPP_
#define _TITANIUMWINDOWS_UI_IMAGEVIEW_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include <algorithm>
#include <boost/algorithm/string/predicate.hpp>
#include "Titanium/UI/Animation.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.ImageView implementation for
		  Windows.
		*/
		class TITANIUMWINDOWS_UI_EXPORT ImageView final : public Titanium::UI::ImageView, public JSExport<ImageView>
		{
		public:
			ImageView(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~ImageView() = default;
			ImageView(const ImageView&) = default;
			ImageView& operator=(const ImageView&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			ImageView(ImageView&&) = default;
			ImageView& operator=(ImageView&&) = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void animate(const std::shared_ptr<Titanium::UI::Animation>& animation, JSObject& callback) TITANIUM_NOEXCEPT override;

			virtual void set_image(const std::string& image) TITANIUM_NOEXCEPT override final;
			virtual void set_images(const std::vector<std::string>& images) TITANIUM_NOEXCEPT override final;

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		private:
			Windows::Foundation::EventRegistrationToken internal_load_event_;
			Windows::UI::Xaml::Controls::Image^ image__;
#pragma warning(push)
#pragma warning(disable : 4251)
			std::string path_;
#pragma warning(pop)

			// Event handlers
			Windows::Foundation::EventRegistrationToken click_event_;
			Windows::Foundation::EventRegistrationToken touch_start_event_;
			Windows::Foundation::EventRegistrationToken touch_end_event_;
			Windows::Foundation::EventRegistrationToken touch_move_event_;
			Windows::Foundation::EventRegistrationToken touch_cancel_event_;
		};
	} // namespace UI
} // namespace TitaniumWindow

#endif  // _TITANIUMWINDOWS_UI_IMAGEVIEW_HPP_
