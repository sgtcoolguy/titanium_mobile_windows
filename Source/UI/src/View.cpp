/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/View.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
  			: Titanium::UI::View(js_context),
		      canvas__(ref new Windows::UI::Xaml::Controls::Canvas())
		{
			TITANIUM_LOG_DEBUG("View::ctor");

			setDefaultHeight(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));
			setDefaultWidth(Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL));

			setComponent(canvas__);
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::UI::View>::Class());
		}

		void View::add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			auto nativeView = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(getComponent());

			if (nativeView == nullptr) {
				TITANIUM_LOG_DEBUG("View::add: nativeView = nullptr");
				return;
			}

			auto view_ptr = view.GetPrivate<Titanium::UI::View>();
			auto newView = std::dynamic_pointer_cast<TitaniumWindows::UI::ViewBase>(view_ptr);
			auto nativeChildView = newView->getComponent();
			if (nativeChildView != nullptr) {
				Titanium::LayoutEngine::nodeAddChild(layout_node_, newView->layout_node_);
				if (isLoaded()) {
					auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node_);
					if (root) {
						Titanium::LayoutEngine::nodeLayout(root);
					}
				}

				canvas__->Children->Append(nativeChildView);
			} else {
				TITANIUM_LOG_DEBUG("View::add: nativeChildView = nullptr");
			}
		}

		void View::animate(const JSObject& animation, JSObject& callback, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::animate(animation, callback, this_object);

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
					storyboard->SetTarget(double_anim, getComponent());
					storyboard->SetTargetProperty(double_anim, "Opacity");
				}
			}
			
			storyboard->Completed += ref new Windows::Foundation::EventHandler<Platform::Object ^>([callback, this_object](Platform::Object^ sender, Platform::Object ^ e) mutable {
				if (callback.IsFunction()) {
					callback(this_object); // FIXME Can't call this because emthod is not const, but var is when in lambda!
				}
				// TODO Fire complete event on animation object!
			});
			storyboard->Begin();
		}

		void View::hide(JSObject& this_object) TITANIUM_NOEXCEPT
		{
			getComponent()->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		}

		void View::show(JSObject& this_object) TITANIUM_NOEXCEPT
		{
			getComponent()->Visibility = Windows::UI::Xaml::Visibility::Visible;
		}

		void View::set_backgroundColor(const std::string& backgroundColorName) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_backgroundColor(backgroundColorName);
			const auto backgroundColor = ColorForName(backgroundColorName);
			canvas__->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(backgroundColor);
		}

		void View::set_opacity(const double& opacity) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_opacity(opacity);
			getComponent()->Opacity = opacity;
		}

		void View::set_bottom(const std::string& bottom) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_bottom(bottom);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Bottom, bottom);
		}

		void View::set_height(const std::string& height) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_height(height);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Height, height);
		}

		void View::set_left(const std::string& left) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_left(left);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Left, left);
		}

		void View::set_layout(const std::string& layout) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_layout(layout);
			setLayout(layout);
		}

		void View::set_right(const std::string& right) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_right(right);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Right, right);
		}

		void View::set_top(const std::string& top) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_top(top);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Top, top);
		}

		void View::set_width(const std::string& width) TITANIUM_NOEXCEPT
		{
			Titanium::UI::View::set_width(width);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Width, width);
		}

		void View::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_DEBUG("View::enableEvent: (event name '", event_name, "'");

			const JSContext ctx = this->get_context();

			using namespace Windows::UI::Xaml::Input;
			using namespace Windows::UI::Xaml;

			if (event_name == "touchmove") {
				if (touch_move_event_count_ == 0) {
					getComponent()->ManipulationMode = ManipulationModes::All;
					touch_move_event_ = getComponent()->ManipulationDelta += ref new ManipulationDeltaEventHandler([ctx, this](Platform::Object^ sender, ManipulationDeltaRoutedEventArgs^ e) {
						JSObject  delta = ctx.CreateObject();
						delta.SetProperty("x", ctx.CreateNumber(e->Delta.Translation.X));
						delta.SetProperty("y", ctx.CreateNumber(e->Delta.Translation.Y));

						JSObject  eventArgs = ctx.CreateObject();
						eventArgs.SetProperty("x", ctx.CreateNumber(e->Position.X));
						eventArgs.SetProperty("y", ctx.CreateNumber(e->Position.Y));
						eventArgs.SetProperty("delta", delta);

						this->fireEvent("touchmove", eventArgs);
					});
				}

				++touch_move_event_count_;

				return;
			}
		}
	} // namespace UI
} // namespace TitaniumWindows
