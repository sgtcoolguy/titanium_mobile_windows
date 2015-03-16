/**
* Titanium.UI.ImageView for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/ImageView.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "LayoutEngine/LayoutEngine.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		ImageView::ImageView(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::ImageView(js_context)
		{
		}

		void ImageView::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			using namespace Windows::UI::Xaml;
			using namespace Windows::UI::Xaml::Controls;

			Titanium::UI::ImageView::postCallAsConstructor(js_context, arguments);	

			image__ = ref new Windows::UI::Xaml::Controls::Image();

			internal_load_event_ = image__->ImageOpened += ref new RoutedEventHandler([this](::Platform::Object^ sender, RoutedEventArgs^ e) {
				auto rect = Titanium::LayoutEngine::RectMake(
					Canvas::GetLeft(this->image__),
					Canvas::GetTop(this->image__),
					this->image__->ActualWidth,
					this->image__->ActualHeight
				);
				getViewLayoutPolicy<WindowsViewLayoutPolicy>()->onComponentSizeChange(rect);
			});

			Titanium::UI::ImageView::setLayoutPolicy<WindowsViewLayoutPolicy>(this);

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(image__);

		}

		void ImageView::JSExportInitialize()
		{
			JSExport<ImageView>::SetClassVersion(1);
			JSExport<ImageView>::SetParent(JSExport<Titanium::UI::ImageView>::Class());
		}

		void ImageView::set_image(const std::string& path) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ImageView::set_image(path);
			std::string modified = path;
			// if the path isn't an http/s URI already, fix URI to point to local files in app
			if (!boost::starts_with(modified, "http://") && !boost::starts_with(modified, "https://")) {
				// URIs must be absolute
				if (!boost::starts_with(modified, "/")) {
					modified = "/" + modified;
				}
				// use MS's in-app URL scheme
				modified = "ms-appx://" + modified;
			}
			auto uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertUTF8String(modified));
			auto image = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
			image__->Source = image;
		}

		void ImageView::set_images(const std::vector<std::string>& images) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ImageView::set_images(images);
			// HACK For now let's cheat and just set the first image as a static one
			set_image(images.at(0));
		}

		void ImageView::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			const JSContext ctx = this->get_context();

			using namespace Windows::UI::Xaml::Input;
			using namespace Windows::UI::Xaml;

			auto component = getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent();

			if (event_name == "click") {
				click_event_ = component->Tapped += ref new TappedEventHandler([this, ctx](::Platform::Object^ sender, TappedRoutedEventArgs^ e) {
					auto component = safe_cast<FrameworkElement^>(sender);
					auto position = e->GetPosition(component);

					JSObject  eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
					eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

					this->fireEvent("click", eventArgs);
				});
			}
		}

		void ImageView::start() TITANIUM_NOEXCEPT
		{
			using namespace concurrency;

			const auto images = get_images();
			const size_t image_count = images.size();

			const auto storyboard = ref new Windows::UI::Xaml::Media::Animation::Storyboard();
			Windows::Foundation::TimeSpan time_span;
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = get_duration();
			time_span.Duration = timer_interval_ticks.count() * image_count;
			storyboard->Duration = time_span;
			auto animation = ref new Windows::UI::Xaml::Media::Animation::ObjectAnimationUsingKeyFrames();
			// TODO Look at "reverse" property to determine if we should loop through in reverse order
			// TODO Look at repeatCount property to determine number of times to repeat
			storyboard->RepeatBehavior = Windows::UI::Xaml::Media::Animation::RepeatBehaviorHelper::Forever;
			
			for (size_t i = 0; i < image_count; i++) {
				auto image = images.at(i);

				std::string modified = image;
				// if the path isn't an http/s URI already, fix URI to point to local files in app
				if (!boost::starts_with(modified, "http://") && !boost::starts_with(modified, "https://")) {
					// URIs must be absolute
					if (!boost::starts_with(modified, "/")) {
						modified = "/" + modified;
					}
					// use MS's in-app URL scheme
					modified = "ms-appx://" + modified;
				}
				auto uri = ref new Windows::Foundation::Uri(TitaniumWindows::Utility::ConvertUTF8String(modified));
				auto keyFrame = ref new Windows::UI::Xaml::Media::Animation::DiscreteObjectKeyFrame();
				Windows::Foundation::TimeSpan key_time;
				key_time.Duration = timer_interval_ticks.count() * i;
				keyFrame->KeyTime = key_time;
				keyFrame->Value = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
				animation->KeyFrames->Append(keyFrame);
			}
			storyboard->Children->Append(animation);
			storyboard->SetTarget(animation, image__);
			storyboard->SetTargetProperty(animation, "(Image.Source)");

			storyboard->Begin();
		}

		void ImageView::stop() TITANIUM_NOEXCEPT
		{
			start_token__.cancel();
		}
	} // namespace UI
} // namespace TitaniumWindows
