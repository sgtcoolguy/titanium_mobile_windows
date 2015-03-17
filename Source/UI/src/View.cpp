/**
 * Titanium.UI.View for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/View.hpp"
#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		View::View(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::UI::View(js_context)
		{
		}

		void View::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{
			Titanium::UI::View::postCallAsConstructor(js_context, arguments);	
			
			canvas__ = ref new Windows::UI::Xaml::Controls::Canvas();

			Titanium::UI::View::setLayoutPolicy<WindowsViewLayoutPolicy>();

			layoutPolicy__->set_defaultHeight(Titanium::UI::LAYOUT::FILL);
			layoutPolicy__->set_defaultWidth(Titanium::UI::LAYOUT::FILL);

			getViewLayoutPolicy<WindowsViewLayoutPolicy>()->setComponent(canvas__);
		}

		void View::JSExportInitialize()
		{
			JSExport<View>::SetClassVersion(1);
			JSExport<View>::SetParent(JSExport<Titanium::UI::View>::Class());
		}

		Windows::UI::Xaml::FrameworkElement^ View::getComponent() TITANIUM_NOEXCEPT
		{
			return getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent();
		}

		void View::animate(JSObject& animation, JSObject& callback) TITANIUM_NOEXCEPT
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
					callback(this_object); // FIXME Can't call this because emthod is not const, but var is when in lambda!
				}
				// TODO Fire complete event on animation object!
			});
			storyboard->Begin();
		}

		void View::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			const JSContext ctx = this->get_context();

			using namespace Windows::UI::Xaml::Input;
			using namespace Windows::UI::Xaml;

			if (event_name == "touchmove") {
				auto component = getViewLayoutPolicy<WindowsViewLayoutPolicy>()->getComponent();
				component->ManipulationMode = ManipulationModes::All;
				touch_move_event_ = component->ManipulationDelta += ref new ManipulationDeltaEventHandler([ctx, this](Platform::Object^ sender, ManipulationDeltaRoutedEventArgs^ e) {
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
		}
	} // namespace UI
} // namespace TitaniumWindows
