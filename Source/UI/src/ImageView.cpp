/**
* Titanium.UI.ImageView for Windows
*
* Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/ImageView.hpp"
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

		void ImageView::start(JSObject& this_object) TITANIUM_NOEXCEPT
		{
			using namespace concurrency;

			const auto current_window = Windows::UI::Xaml::Window::Current;
			const auto current_duration = get_duration().count();
			create_task([this, current_window, current_duration] {
				for (const auto& image : get_images()) {
					interruption_point(); // Check for cancellation.

					// Set new image on UI thread
					current_window->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this, image]() {
						set_image(image);
					}));
					// then wait for duration
					wait(current_duration); // FIXME signed/unsigned conversion!
				}
			}, start_token__.get_token());
		}

		void ImageView::stop(JSObject& this_object) TITANIUM_NOEXCEPT
		{
			start_token__.cancel();
		}
	} // namespace UI
} // namespace TitaniumWindows
