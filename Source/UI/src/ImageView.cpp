/**
* Titanium.UI.ImageView for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/ImageView.hpp"
#include "LayoutEngine/LayoutEngine.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		ImageView::ImageView(const JSContext& js_context) TITANIUM_NOEXCEPT
			  : Titanium::UI::ImageView(js_context)
		{
			TITANIUM_LOG_DEBUG("ImageView::ctor");
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

			Titanium::UI::ImageView::setLayoutPolicy<WindowsViewLayoutPolicy>();

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(image__);

		}

		void ImageView::JSExportInitialize()
		{
			JSExport<ImageView>::SetClassVersion(1);
			JSExport<ImageView>::SetParent(JSExport<Titanium::UI::ImageView>::Class());
		}

		void ImageView::animate(JSObject& animation, JSObject& callback) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::animate(animation, callback);

			// Convert duration to type we need
			const auto raw_duration = animation.GetProperty("duration");
			const auto duration = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(raw_duration)));
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = duration;
			Windows::Foundation::TimeSpan time_span;
			time_span.Duration = timer_interval_ticks.count();

			bool has_delay = false;
			Windows::Foundation::TimeSpan begin_time;
			if (animation.HasProperty("delay")) {
				has_delay = true;
				const auto raw_delay = animation.GetProperty("delay");
				const auto delay = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(raw_delay)));
				std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> delay_ticks = delay;
				begin_time.Duration = delay_ticks.count();
			}

			bool autoreverse = false;
			if (animation.HasProperty("autoreverse")) {
				autoreverse = static_cast<bool>(animation.GetProperty("autoreverse"));
			}
			// repeat count
			uint32_t repeat = 1;
			if (animation.HasProperty("repeat")) {
				repeat = static_cast<uint32_t>(animation.GetProperty("repeat"));
			}
			repeat--;

			// Storyboard where we attach all the animations
			const auto storyboard = ref new Windows::UI::Xaml::Media::Animation::Storyboard();
			storyboard->Duration = time_span;
			if (has_delay) {
				storyboard->BeginTime = begin_time;
			}

			auto component = getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent();

			const auto propertyNames = animation.GetPropertyNames();
			for (const auto& property_name : static_cast<std::vector<JSString>>(propertyNames)) {
				auto property = animation.GetProperty(property_name);
				if (property_name == "opacity") {
					auto double_anim = ref new Windows::UI::Xaml::Media::Animation::DoubleAnimation();
					double_anim->AutoReverse = autoreverse;

					double_anim->Duration = time_span;
					if (has_delay) {
						double_anim->BeginTime = begin_time;
					}
					if (repeat > 0) {
						double_anim->RepeatBehavior = Windows::UI::Xaml::Media::Animation::RepeatBehaviorHelper::FromCount(repeat);
					}
					double_anim->To = static_cast<double>(property);
					storyboard->Children->Append(double_anim);
					storyboard->SetTarget(double_anim, component);
					storyboard->SetTargetProperty(double_anim, "Opacity");
				}
			}

			auto this_object = get_object();

			storyboard->Completed += ref new Windows::Foundation::EventHandler<Platform::Object ^>([callback, this_object](Platform::Object^ sender, Platform::Object ^ e) mutable {
				if (callback.IsFunction()) {
					callback(this_object);
				}
				// TODO Fire complete event on animation object!
			});
			storyboard->Begin();
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
			auto uri = ref new Windows::Foundation::Uri(ref new Platform::String(std::wstring(modified.begin(), modified.end()).c_str()));
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
			TITANIUM_LOG_DEBUG("ImageView::enableEvent: (event name '", event_name, "'");

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

	} // namespace UI
} // namespace TitaniumWindows
