/**
 * TitaniumKit ViewLayoutPolicy
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/UI/WindowsViewLayoutPolicy.hpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <collection.h>

namespace TitaniumWindows
{
	namespace UI
	{
		WindowsViewLayoutPolicy::WindowsViewLayoutPolicy(Titanium::UI::View* view) TITANIUM_NOEXCEPT
			: ViewLayoutPolicy(),
			  view__(view)
		{
			TITANIUM_LOG_DEBUG("WindowsViewLayoutPolicy::ctor");
		}

		void WindowsViewLayoutPolicy::postInitialize() TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::postInitialize();
		}

		void WindowsViewLayoutPolicy::add(const std::shared_ptr<Titanium::UI::View>& view) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::add(view);

			auto nativeView = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(getComponent());

			if (nativeView == nullptr) {
				TITANIUM_LOG_WARN("WindowsViewLayoutPolicy::add: Unknown component");
				return;
			}

			auto newView = view->getViewLayoutPolicy<TitaniumWindows::UI::WindowsViewLayoutPolicy>();
			auto nativeChildView = newView->getComponent();
			if (nativeChildView != nullptr) {
				Titanium::LayoutEngine::nodeAddChild(layout_node__, newView->getLayoutNode());
				if (isLoaded()) {
					auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);
					if (root) {
						Titanium::LayoutEngine::nodeLayout(root);
					}
				}

				nativeView->Children->Append(nativeChildView);
			} else {
				TITANIUM_LOG_WARN("WindowsViewLayoutPolicy::add: Unknown child component");
			}
		}

		void WindowsViewLayoutPolicy::hide() TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::hide();
			getComponent()->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		}

		void WindowsViewLayoutPolicy::show() TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::show();
			getComponent()->Visibility = Windows::UI::Xaml::Visibility::Visible;
		}

		void WindowsViewLayoutPolicy::animate(JSObject& animation, JSObject& callback, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::animate(animation, callback, this_object);

			

			bool has_delay = false;
			Windows::Foundation::TimeSpan begin_time;
			begin_time.Duration = 0;
			if (animation.HasProperty("delay")) {
				has_delay = true;
				const auto raw_delay = animation.GetProperty("delay");
				const auto delay = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(raw_delay)));
				std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> delay_ticks = delay;
				begin_time.Duration = delay_ticks.count();
			}

			// Convert duration to type we need
			const auto raw_duration = animation.GetProperty("duration");
			const auto duration = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(static_cast<std::uint32_t>(raw_duration)));
			std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano>> timer_interval_ticks = duration;
			Windows::Foundation::TimeSpan time_span;
			time_span.Duration = timer_interval_ticks.count() + begin_time.Duration;

			bool autoreverse = false;
			if (animation.HasProperty("autoreverse")) {
				autoreverse = static_cast<bool>(animation.GetProperty("autoreverse"));
			}

			// repeat count
			double repeat = 1;
			if (animation.HasProperty("repeat")) {
				repeat = static_cast<double>(animation.GetProperty("repeat"));
			}

			// Storyboard where we attach all the animations
			const auto storyboard = ref new Windows::UI::Xaml::Media::Animation::Storyboard();
			if (has_delay) {
				storyboard->BeginTime = begin_time; // FIXME This seems to apply to every iteration of repeat, but we probably only want it to happen the first time?
			}
			storyboard->AutoReverse = autoreverse;
			
			if (repeat == 0) {
				storyboard->RepeatBehavior = Windows::UI::Xaml::Media::Animation::RepeatBehaviorHelper::Forever;
			} else if (repeat != 1) {
				storyboard->RepeatBehavior = Windows::UI::Xaml::Media::Animation::RepeatBehaviorHelper::FromCount(repeat);
			}

			auto component = getComponent();
			const auto propertyNames = animation.GetPropertyNames();
			for (const auto& property_name : static_cast<std::vector<JSString>>(propertyNames)) {
				// Create an animation!
				auto property = animation.GetProperty(property_name);
				Windows::UI::Xaml::Media::Animation::Timeline^ anim;
				if (property_name == "color" || property_name == "backgroundColor") {
					auto color_anim = ref new Windows::UI::Xaml::Media::Animation::ColorAnimation();
					const auto color = ColorForName(static_cast<std::string>(property));
					color_anim->To = color;

					if (property_name == "color") { // foreground
						// TODO What if component isn't subclass of Control?
						if (is_control__) {
							storyboard->SetTargetProperty(color_anim, "(Control.Foreground).(SolidColorBrush.Color)");
						}
					} else { // background
						if (is_panel__) {
							storyboard->SetTargetProperty(color_anim, "(Panel.Background).(SolidColorBrush.Color)");
						} else if (is_control__) {
							storyboard->SetTargetProperty(color_anim, "(Control.Background).(SolidColorBrush.Color)");
						}
					}
					anim = color_anim;
				} else {
					// properties which are doubles
					auto double_anim = ref new Windows::UI::Xaml::Media::Animation::DoubleAnimation();
					double_anim->To = static_cast<double>(property);

					if (property_name == "opacity") {
						storyboard->SetTargetProperty(double_anim, "Opacity");
						// FIXME top and left don't work for ImageView
					} else if (property_name == "top") { // bottom?
						getComponent()->RenderTransform = ref new Windows::UI::Xaml::Media::TranslateTransform();
						storyboard->SetTargetProperty(double_anim, "(UIElement.RenderTransform).(TranslateTransform.Y)");
					} else if (property_name == "left") { // right?
						// TODO If "right", we need to calculate the current position of "right", take the diff and then do a transform By, not To
						getComponent()->RenderTransform = ref new Windows::UI::Xaml::Media::TranslateTransform();
						storyboard->SetTargetProperty(double_anim, "(UIElement.RenderTransform).(TranslateTransform.X)");
					} else {
						// Not a property we support!
						continue;
					}
					anim = double_anim;
				}
				if (anim) {
					storyboard->SetTarget(anim, getComponent());
					storyboard->Children->Append(anim);
				}
			}

			storyboard->Completed += ref new Windows::Foundation::EventHandler<Platform::Object ^>([callback, this_object](Platform::Object^ sender, Platform::Object ^ e) mutable {
				if (callback.IsFunction()) {
					callback(this_object);
				}
				// TODO Fire complete event on animation object!
			});
			storyboard->Begin();
		}

		void WindowsViewLayoutPolicy::set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_backgroundColor(backgroundColor);

			auto background = ref new Windows::UI::Xaml::Media::SolidColorBrush(ColorForName(backgroundColor));

			if (is_panel__) {
				dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(component__)->Background = background;
			} else if (is_control__) {
				dynamic_cast<Windows::UI::Xaml::Controls::Control^>(component__)->Background = background;
			} else {
				TITANIUM_LOG_WARN("WindowsViewLayoutPolicy::set_backgroundColor: Unknown component");
			}
		}

		void WindowsViewLayoutPolicy::set_borderColor(const std::string& borderColor) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_borderColor(borderColor);
		}

		void WindowsViewLayoutPolicy::set_borderRadius(const uint32_t& borderRadius) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_borderRadius(borderRadius);
		}

		void WindowsViewLayoutPolicy::set_borderWidth(const uint32_t& borderWidth) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_borderWidth(borderWidth);

			if (is_control__) {
				dynamic_cast<Windows::UI::Xaml::Controls::Control^>(component__)->BorderThickness = borderWidth;
			} else {
				TITANIUM_LOG_WARN("WindowsViewLayoutPolicy::set_borderWidth: Unknown component");
			}
		}

		void WindowsViewLayoutPolicy::set_opacity(const double& opacity) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_opacity(opacity);
			getComponent()->Opacity = opacity;
		}

		Titanium::UI::Dimension WindowsViewLayoutPolicy::get_rect() const TITANIUM_NOEXCEPT
		{
			Titanium::UI::Dimension d;
			d.x = static_cast<uint32_t>(oldRect__.x);
			d.y = static_cast<uint32_t>(oldRect__.y);
			d.width = static_cast<uint32_t>(oldRect__.width);
			d.height = static_cast<uint32_t>(oldRect__.height);
			return d;
		}

		Titanium::UI::Dimension WindowsViewLayoutPolicy::get_size() const TITANIUM_NOEXCEPT
		{
			Titanium::UI::Dimension d;
			d.x = 0;
			d.y = 0;
			d.width = static_cast<uint32_t>(oldRect__.width);
			d.height = static_cast<uint32_t>(oldRect__.height);
			return d;
		}
		void WindowsViewLayoutPolicy::set_tintColor(const std::string& tintColor) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_tintColor(tintColor);
		}

		void WindowsViewLayoutPolicy::set_touchEnabled(const bool& touchEnabled) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_touchEnabled(touchEnabled);
		}

		void WindowsViewLayoutPolicy::set_top(const std::string& top) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_top(top);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Top, top);
		}

		void WindowsViewLayoutPolicy::set_left(const std::string& left) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_left(left);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Left, left);
		}

		void WindowsViewLayoutPolicy::set_bottom(const std::string& bottom) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_bottom(bottom);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Bottom, bottom);
		}

		void WindowsViewLayoutPolicy::set_right(const std::string& right) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_right(right);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Right, right);
		}

		void WindowsViewLayoutPolicy::set_center(const Titanium::UI::Point& center) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_center(center);
		}

		void WindowsViewLayoutPolicy::set_width(const std::string& width) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_width(width);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Width, width);
		}

		void WindowsViewLayoutPolicy::set_minWidth(const std::string& width) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_minWidth(width);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::MinWidth, width);
		}

		void WindowsViewLayoutPolicy::set_height(const std::string& height) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_height(height);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::Height, height);
		}

		void WindowsViewLayoutPolicy::set_minHeight(const std::string& height) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_minHeight(height);
			setLayoutProperty(Titanium::LayoutEngine::ValueName::MinHeight, height);
		}

		void WindowsViewLayoutPolicy::set_layout(const std::string& layout) TITANIUM_NOEXCEPT
		{
			Titanium::UI::ViewLayoutPolicy::set_layout(layout);

			if (layout == "horizontal") {
				layout_node__->element.layoutType = Titanium::LayoutEngine::LayoutType::Horizontal;
			} else if (layout == "vertical") {
				layout_node__->element.layoutType = Titanium::LayoutEngine::LayoutType::Vertical;
			} else {
				layout_node__->element.layoutType = Titanium::LayoutEngine::LayoutType::Composite;
			}

			if (isLoaded()) {
				auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);
				if (root) {
					Titanium::LayoutEngine::nodeLayout(root);
				}
			}
		}

		void WindowsViewLayoutPolicy::disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			if (event_name == "focus") {
				getComponent()->GotFocus -= focus_event__;
				return;
			} else if (event_name == "postlayout") {
				postlayout_listening__ = false;
				return;
			}
		}

		void WindowsViewLayoutPolicy::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT
		{
			const JSContext ctx = view__->get_context();

			 if (event_name == "focus") {
				 focus_event__ = getComponent()->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler([this, ctx](Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
					JSObject eventArgs = ctx.CreateObject();
					eventArgs.SetProperty("source", view__->get_object());
					eventArgs.SetProperty("type", ctx.CreateString("focus"));
					view__->fireEvent("focus", eventArgs);
				});
				return;
			 } else if (event_name == "postlayout") {
				 postlayout_listening__ = true;
				 return;
			 }
		}

		static void onLayoutCallback(Titanium::LayoutEngine::Node* node)
		{
			auto view = static_cast<WindowsViewLayoutPolicy*>(node->data);
			auto rect = Titanium::LayoutEngine::RectMake(node->element.measuredLeft, node->element.measuredTop, node->element.measuredWidth, node->element.measuredHeight);
			view->onLayoutEngineCallback(rect, node->name);
		}

		void WindowsViewLayoutPolicy::setComponent(Windows::UI::Xaml::FrameworkElement^ component)
		{
			using namespace Windows::UI::Xaml;
			using namespace Windows::UI::Xaml::Controls;

			TITANIUM_ASSERT(component__ == nullptr);

			component__  = component;
			is_panel__   = dynamic_cast<Windows::UI::Xaml::Controls::Panel^>(component__) != nullptr;
			is_control__ = dynamic_cast<Windows::UI::Xaml::Controls::Control^>(component__) != nullptr;

			loaded_event__ = component__->Loaded += ref new RoutedEventHandler([this](Platform::Object^ sender, RoutedEventArgs^ e) {
				auto component = getComponent();
				auto rect = Titanium::LayoutEngine::RectMake(
					Canvas::GetLeft(component),
					Canvas::GetTop(component),
					component->ActualWidth,
					component->ActualHeight
				);

				onComponentLoaded(rect);
			});

			size_change_event__ = component__->SizeChanged += ref new Windows::UI::Xaml::SizeChangedEventHandler([this](Platform::Object^ sender, SizeChangedEventArgs^ e) {
				auto component = getComponent();
				auto rect = Titanium::LayoutEngine::RectMake(
					Canvas::GetLeft(component),
					Canvas::GetTop(component),
					e->NewSize.Width,
					e->NewSize.Height
				);

				onComponentSizeChange(rect);
			});

			layout_node__ = new Titanium::LayoutEngine::Node;
			layout_node__->data = this;
			layout_node__->onLayout = onLayoutCallback;

			if (get_defaultWidth() == Titanium::UI::LAYOUT::SIZE) {
				is_width_size__ = true;
				layout_node__->properties.defaultWidthType = Titanium::LayoutEngine::ValueType::Size;
			} else if (get_defaultWidth() == Titanium::UI::LAYOUT::FILL) {
				layout_node__->properties.defaultWidthType = Titanium::LayoutEngine::ValueType::Fill;
			}

			if (get_defaultHeight() == Titanium::UI::LAYOUT::SIZE) {
				is_height_size__ = true;
				layout_node__->properties.defaultHeightType = Titanium::LayoutEngine::ValueType::Size;
			} else if (get_defaultHeight() == Titanium::UI::LAYOUT::FILL) {
				layout_node__->properties.defaultHeightType = Titanium::LayoutEngine::ValueType::Fill;
			}
		}

		void WindowsViewLayoutPolicy::onLayoutEngineCallback(Titanium::LayoutEngine::Rect rect, const std::string& name)
		{
			using namespace Windows::UI::Xaml::Controls;
			using namespace Windows::UI::Xaml;
			if (is_height_size__ && rect.height == 0)
				return;
			if (is_width_size__ && rect.width == 0)
				return;
			if (rect.width < 0 || rect.height < 0)
				return;
			if (Titanium::LayoutEngine::RectIsEmpty(rect))
				return;
			if (Titanium::LayoutEngine::RectIsEqualToRect(oldRect__, rect))
				return;

			auto component = getComponent();
			auto panel = is_panel__ ? safe_cast<Panel^>(component) : nullptr;
			auto parentLayout = layout_node__->parent;

			auto setWidth = false;
			auto setHeight = false;
			auto setWidthOnWidget = !is_width_size__;
			auto setHeightOnWidget = !is_height_size__;

			if (!is_panel__ && is_width_size__ && parentLayout != nullptr) {
				if (rect.width > parentLayout->element.measuredWidth && parentLayout->element.measuredWidth > 0) {
					rect.width = parentLayout->element.measuredWidth;
					setWidthOnWidget = true;
				} else if (layout_node__->properties.width.valueType == Titanium::LayoutEngine::Fixed) {
					setWidthOnWidget = true;
				}
			}

			if (!is_panel__ && is_height_size__ && parentLayout != nullptr) {
				if (rect.height > parentLayout->element.measuredHeight && parentLayout->element.measuredHeight > 0) {
					rect.height = parentLayout->element.measuredHeight;
					setHeightOnWidget = true;
				} else if (layout_node__->properties.height.valueType == Titanium::LayoutEngine::Fixed) {
					setHeightOnWidget = true;
				}
			}

			oldRect__ = Titanium::LayoutEngine::RectMake(rect.x, rect.y, rect.width, rect.height);

			if (is_panel__) {
				for (auto child : panel->Children) {
					child->Visibility = Visibility::Collapsed;
				}

				setWidth = true;
				setHeight = true;
			}

			if ((!is_panel__ && setWidthOnWidget) || setWidth) {
				component->Width = rect.width;
			}

			if ((!is_panel__ && setHeightOnWidget) || setHeight) {
				component->Height = rect.height;
			}

			Canvas::SetLeft(component, rect.x);
			Canvas::SetTop(component, rect.y);

			if (is_panel__) {
				for (auto child : panel->Children) {
					child->Visibility = Visibility::Visible;
				}
			}
		}

		void WindowsViewLayoutPolicy::onComponentLoaded(const Titanium::LayoutEngine::Rect& rect)
		{
			is_loaded__ = true;

			auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);

			if (root) {
				Titanium::LayoutEngine::nodeLayout(root);
			}
		}

		void WindowsViewLayoutPolicy::onComponentSizeChange(const Titanium::LayoutEngine::Rect& rect)
		{
			bool needsLayout = false;

			if (is_width_size__ && !is_panel__) {
				layout_node__->properties.width.value = rect.width;
				layout_node__->properties.width.valueType = Titanium::LayoutEngine::Fixed;
				needsLayout = isLoaded();
			}

			if (is_height_size__ && !is_panel__) {
				layout_node__->properties.height.value = rect.height;
				layout_node__->properties.height.valueType = Titanium::LayoutEngine::Fixed;
				needsLayout = isLoaded();
			}

			if (needsLayout) {
				auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);
				if (root) {
					Titanium::LayoutEngine::nodeLayout(root);
				}
			}

			if (postlayout_listening__) {
				// Fire postlayout event
				JSContext ctx = view__->get_context();
				JSObject  eventArgs = ctx.CreateObject();
				eventArgs.SetProperty("source", view__->get_object());
				eventArgs.SetProperty("type", ctx.CreateString("postlayout"));
				view__->fireEvent("postlayout", eventArgs);
			}
		}


		void WindowsViewLayoutPolicy::setLayoutProperty(const Titanium::LayoutEngine::ValueName& name, const std::string& value)
		{
			Titanium::LayoutEngine::InputProperty prop;
			prop.name = name;
			prop.value = value;

			if (prop.value == Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::SIZE)) {
				prop.value = "UI.SIZE";
			} else if (prop.value == Titanium::UI::Constants::to_string(Titanium::UI::LAYOUT::FILL)) {
				prop.value = "UI.FILL";
			}

			Titanium::LayoutEngine::populateLayoutPoperties(prop, &layout_node__->properties, 1);

			if (isLoaded()) {
				auto root = Titanium::LayoutEngine::nodeRequestLayout(layout_node__);
				if (root) {
					Titanium::LayoutEngine::nodeLayout(root);
				}
			}
		}

		/////////// Color //////////////

		inline bool isASCIIHexDigit(char c)
		{
			return (c >= '0' && c <= '9') || ((c | 0x20) >= 'a' && (c | 0x20) <= 'f');
		}

		inline int toASCIIHexValue(char c)
		{
			return (c & 0xF) + (c < 'A' ? 0 : 9);
		}

		Windows::UI::Color WindowsViewLayoutPolicy::ColorForHexCode(const std::string& hexCode)
		{
			unsigned length = hexCode.size();
			unsigned char alpha = 255;
			if ((length != 3) && (length != 4) && (length != 6) && (length != 7) && (length != 8)) {
				TITANIUM_LOG_WARN("View::ColorForHexCode: invalid hexCode = ", hexCode);
				return Windows::UI::Colors::Transparent;
			}
			unsigned value = 0;

			for (size_t i = 0; i < length; ++i) {
				unsigned char thisChar = hexCode[i];
				if (thisChar == '#')
					continue;
				if (!isASCIIHexDigit(thisChar)) {
					return Windows::UI::Colors::Transparent;
				}
				value <<= 4;
				value |= toASCIIHexValue(thisChar);
			}

			if (length < 6) {
				value = ((value & 0xF000) << 16) |
				        ((value & 0xFF00) << 12) |
				        ((value & 0xFF0) << 8) |
				        ((value & 0xFF) << 4) |
				        (value & 0xF);
			}

			if ((length % 4) == 0) {
				alpha = ((value >> 24) & 0xFF) * 255;
			}

			int red = (value >> 16) & 0xFF;
			int green = (value >> 8) & 0xFF;
			int blue = value & 0xFF;
			return Windows::UI::ColorHelper::FromArgb(alpha, red, green, blue);
		}

#if defined(INSERT_WINDOWS_UI_COLOR)
#error "LOGIC ERROR: INSERT_WINDOWS_UI_COLOR already defined."
#endif

		inline std::string toLowerCase(const std::string& string)
		{
			std::string copy(string);
			std::transform(string.begin(), string.end(), copy.begin(), std::tolower);
			return copy;
		}

#define INSERT_WINDOWS_UI_COLOR(COLOR_NAME) color_name_map.insert(std::make_pair(toLowerCase(#COLOR_NAME), Windows::UI::Colors::##COLOR_NAME));

		// Can this be optimized? MS is giving a lot of choices for colors!
		Windows::UI::Color WindowsViewLayoutPolicy::ColorForName(const std::string& colorName)
		{
			// pre condition
			TITANIUM_ASSERT(!colorName.empty());

			static const Windows::UI::Color defaultColor = Windows::UI::Colors::Transparent;
			using ColorNameMap_t = std::unordered_map<std::string, Windows::UI::Color>;
			static ColorNameMap_t color_name_map;
			static std::once_flag of;
			std::call_once(of, [] {
			INSERT_WINDOWS_UI_COLOR(AliceBlue);
			INSERT_WINDOWS_UI_COLOR(AntiqueWhite);
			INSERT_WINDOWS_UI_COLOR(Aqua);
			INSERT_WINDOWS_UI_COLOR(Aquamarine);
			INSERT_WINDOWS_UI_COLOR(Azure);
			INSERT_WINDOWS_UI_COLOR(Beige);
			INSERT_WINDOWS_UI_COLOR(Bisque);
			INSERT_WINDOWS_UI_COLOR(Black);
			INSERT_WINDOWS_UI_COLOR(BlanchedAlmond);
			INSERT_WINDOWS_UI_COLOR(Blue);
			INSERT_WINDOWS_UI_COLOR(BlueViolet);
			INSERT_WINDOWS_UI_COLOR(Brown);
			INSERT_WINDOWS_UI_COLOR(BurlyWood);
			INSERT_WINDOWS_UI_COLOR(CadetBlue);
			INSERT_WINDOWS_UI_COLOR(Chartreuse);
			INSERT_WINDOWS_UI_COLOR(Chocolate);
			INSERT_WINDOWS_UI_COLOR(Coral);
			INSERT_WINDOWS_UI_COLOR(CornflowerBlue);
			INSERT_WINDOWS_UI_COLOR(Cornsilk);
			INSERT_WINDOWS_UI_COLOR(Crimson);
			INSERT_WINDOWS_UI_COLOR(Cyan);
			INSERT_WINDOWS_UI_COLOR(DarkBlue);
			INSERT_WINDOWS_UI_COLOR(DarkCyan);
			INSERT_WINDOWS_UI_COLOR(DarkGoldenrod);
			INSERT_WINDOWS_UI_COLOR(DarkGray);
			INSERT_WINDOWS_UI_COLOR(DarkGreen);
			INSERT_WINDOWS_UI_COLOR(DarkKhaki);
			INSERT_WINDOWS_UI_COLOR(DarkMagenta);
			INSERT_WINDOWS_UI_COLOR(DarkOliveGreen);
			INSERT_WINDOWS_UI_COLOR(DarkOrange);
			INSERT_WINDOWS_UI_COLOR(DarkOrchid);
			INSERT_WINDOWS_UI_COLOR(DarkRed);
			INSERT_WINDOWS_UI_COLOR(DarkSalmon);
			INSERT_WINDOWS_UI_COLOR(DarkSeaGreen);
			INSERT_WINDOWS_UI_COLOR(DarkSlateBlue);
			INSERT_WINDOWS_UI_COLOR(DarkSlateGray);
			INSERT_WINDOWS_UI_COLOR(DarkTurquoise);
			INSERT_WINDOWS_UI_COLOR(DarkViolet);
			INSERT_WINDOWS_UI_COLOR(DeepPink);
			INSERT_WINDOWS_UI_COLOR(DeepSkyBlue);
			INSERT_WINDOWS_UI_COLOR(DimGray);
			INSERT_WINDOWS_UI_COLOR(DodgerBlue);
			INSERT_WINDOWS_UI_COLOR(Firebrick);
			INSERT_WINDOWS_UI_COLOR(FloralWhite);
			INSERT_WINDOWS_UI_COLOR(ForestGreen);
			INSERT_WINDOWS_UI_COLOR(Fuchsia);
			INSERT_WINDOWS_UI_COLOR(Gainsboro);
			INSERT_WINDOWS_UI_COLOR(GhostWhite);
			INSERT_WINDOWS_UI_COLOR(Gold);
			INSERT_WINDOWS_UI_COLOR(Goldenrod);
			INSERT_WINDOWS_UI_COLOR(Gray);
			INSERT_WINDOWS_UI_COLOR(Green);
			INSERT_WINDOWS_UI_COLOR(GreenYellow);
			INSERT_WINDOWS_UI_COLOR(Honeydew);
			INSERT_WINDOWS_UI_COLOR(HotPink);
			INSERT_WINDOWS_UI_COLOR(IndianRed);
			INSERT_WINDOWS_UI_COLOR(Indigo);
			INSERT_WINDOWS_UI_COLOR(Ivory);
			INSERT_WINDOWS_UI_COLOR(Khaki);
			INSERT_WINDOWS_UI_COLOR(Lavender);
			INSERT_WINDOWS_UI_COLOR(LavenderBlush);
			INSERT_WINDOWS_UI_COLOR(LawnGreen);
			INSERT_WINDOWS_UI_COLOR(LemonChiffon);
			INSERT_WINDOWS_UI_COLOR(LightBlue);
			INSERT_WINDOWS_UI_COLOR(LightCoral);
			INSERT_WINDOWS_UI_COLOR(LightCyan);
			INSERT_WINDOWS_UI_COLOR(LightGoldenrodYellow);
			INSERT_WINDOWS_UI_COLOR(LightGray);
			INSERT_WINDOWS_UI_COLOR(LightGreen);
			INSERT_WINDOWS_UI_COLOR(LightPink);
			INSERT_WINDOWS_UI_COLOR(LightSalmon);
			INSERT_WINDOWS_UI_COLOR(LightSeaGreen);
			INSERT_WINDOWS_UI_COLOR(LightSkyBlue);
			INSERT_WINDOWS_UI_COLOR(LightSlateGray);
			INSERT_WINDOWS_UI_COLOR(LightSteelBlue);
			INSERT_WINDOWS_UI_COLOR(LightYellow);
			INSERT_WINDOWS_UI_COLOR(Lime);
			INSERT_WINDOWS_UI_COLOR(LimeGreen);
			INSERT_WINDOWS_UI_COLOR(Linen);
			INSERT_WINDOWS_UI_COLOR(Magenta);
			INSERT_WINDOWS_UI_COLOR(Maroon);
			INSERT_WINDOWS_UI_COLOR(MediumAquamarine);
			INSERT_WINDOWS_UI_COLOR(MediumBlue);
			INSERT_WINDOWS_UI_COLOR(MediumOrchid);
			INSERT_WINDOWS_UI_COLOR(MediumPurple);
			INSERT_WINDOWS_UI_COLOR(MediumSeaGreen);
			INSERT_WINDOWS_UI_COLOR(MediumSlateBlue);
			INSERT_WINDOWS_UI_COLOR(MediumSpringGreen);
			INSERT_WINDOWS_UI_COLOR(MediumTurquoise);
			INSERT_WINDOWS_UI_COLOR(MediumVioletRed);
			INSERT_WINDOWS_UI_COLOR(MidnightBlue);
			INSERT_WINDOWS_UI_COLOR(MintCream);
			INSERT_WINDOWS_UI_COLOR(MistyRose);
			INSERT_WINDOWS_UI_COLOR(Moccasin);
			INSERT_WINDOWS_UI_COLOR(NavajoWhite);
			INSERT_WINDOWS_UI_COLOR(Navy);
			INSERT_WINDOWS_UI_COLOR(OldLace);
			INSERT_WINDOWS_UI_COLOR(Olive);
			INSERT_WINDOWS_UI_COLOR(OliveDrab);
			INSERT_WINDOWS_UI_COLOR(Orange);
			INSERT_WINDOWS_UI_COLOR(OrangeRed);
			INSERT_WINDOWS_UI_COLOR(Orchid);
			INSERT_WINDOWS_UI_COLOR(PaleGoldenrod);
			INSERT_WINDOWS_UI_COLOR(PaleGreen);
			INSERT_WINDOWS_UI_COLOR(PaleTurquoise);
			INSERT_WINDOWS_UI_COLOR(PaleVioletRed);
			INSERT_WINDOWS_UI_COLOR(PapayaWhip);
			INSERT_WINDOWS_UI_COLOR(PeachPuff);
			INSERT_WINDOWS_UI_COLOR(Peru);
			INSERT_WINDOWS_UI_COLOR(Pink);
			INSERT_WINDOWS_UI_COLOR(Plum);
			INSERT_WINDOWS_UI_COLOR(PowderBlue);
			INSERT_WINDOWS_UI_COLOR(Purple);
			INSERT_WINDOWS_UI_COLOR(Red);
			INSERT_WINDOWS_UI_COLOR(RosyBrown);
			INSERT_WINDOWS_UI_COLOR(RoyalBlue);
			INSERT_WINDOWS_UI_COLOR(SaddleBrown);
			INSERT_WINDOWS_UI_COLOR(Salmon);
			INSERT_WINDOWS_UI_COLOR(SandyBrown);
			INSERT_WINDOWS_UI_COLOR(SeaGreen);
			INSERT_WINDOWS_UI_COLOR(SeaShell);
			INSERT_WINDOWS_UI_COLOR(Sienna);
			INSERT_WINDOWS_UI_COLOR(Silver);
			INSERT_WINDOWS_UI_COLOR(SkyBlue);
			INSERT_WINDOWS_UI_COLOR(SlateBlue);
			INSERT_WINDOWS_UI_COLOR(SlateGray);
			INSERT_WINDOWS_UI_COLOR(Snow);
			INSERT_WINDOWS_UI_COLOR(SpringGreen);
			INSERT_WINDOWS_UI_COLOR(SteelBlue);
			INSERT_WINDOWS_UI_COLOR(Tan);
			INSERT_WINDOWS_UI_COLOR(Teal);
			INSERT_WINDOWS_UI_COLOR(Thistle);
			INSERT_WINDOWS_UI_COLOR(Tomato);
			INSERT_WINDOWS_UI_COLOR(Transparent);
			INSERT_WINDOWS_UI_COLOR(Turquoise);
			INSERT_WINDOWS_UI_COLOR(Violet);
			INSERT_WINDOWS_UI_COLOR(Wheat);
			INSERT_WINDOWS_UI_COLOR(White);
			INSERT_WINDOWS_UI_COLOR(WhiteSmoke);
			INSERT_WINDOWS_UI_COLOR(Yellow);
			INSERT_WINDOWS_UI_COLOR(YellowGreen);
			});

			if (colorName[0] == '#') {
				return ColorForHexCode(colorName.substr(1));
			}

			auto position = color_name_map.find(toLowerCase(colorName));

			Windows::UI::Color color = defaultColor;
			if (position != color_name_map.end()) {
				color = position->second;
			}

			return color;
		}
	} // namespace UI
}  // namespace Titanium
