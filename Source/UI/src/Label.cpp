/**
* Titanium.UI.Label for Windows
*
* Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/UI/Label.hpp"

#define DEFAULT_FONT_SIZE 20

namespace TitaniumWindows { namespace UI {

  Label::Label(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::UI::Label(js_context)
    , label__(ref new Windows::UI::Xaml::Controls::TextBlock()) {
    TITANIUM_LOG_DEBUG("Label::ctor Initialize");
  }

  Label::Label(const Label& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
		: Titanium::UI::Label(rhs, arguments)
    , label__(ref new Windows::UI::Xaml::Controls::TextBlock()) {
	label__->TextWrapping = Windows::UI::Xaml::TextWrapping::Wrap;
	label__->TextTrimming = Windows::UI::Xaml::TextTrimming::Clip;
	label__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
	label__->FontSize = DEFAULT_FONT_SIZE;
	setComponent(label__);
    TITANIUM_LOG_DEBUG("Label::ctor CallAsConstructor");
  }

  void Label::JSExportInitialize() {
	JSExport<Label>::SetClassVersion(1);
	JSExport<Label>::SetParent(JSExport<Titanium::UI::Label>::Class());
  }
  
  bool Label::setTextArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT{
    TITANIUM_ASSERT(argument.IsString());
    const std::string text = static_cast<std::string>(argument);
    label__->Text = ref new Platform::String(std::wstring(text.begin(), text.end()).c_str());
    TITANIUM_LOG_DEBUG("Label::setTextArgumentValidator: text = ", text);
    set_text(argument);
    return true;
  }

  bool Label::setBackgroundColorArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString());
    bool result = false;
    std::string backgroundColorName = static_cast<std::string>(argument);
    TITANIUM_LOG_INFO("Label::setBackgroundColorArgumentValidator: backgroundColor = ", backgroundColorName);
    const auto backgroundColor = ColorForName(backgroundColorName);
    //label__->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(backgroundColor);
    set_backgroundColor(argument);
    result = true;
    return result;
  }

  bool Label::setTopArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
    bool result = false;
    std::string value = static_cast<std::string>(argument);
    TITANIUM_LOG_INFO("Label::setTopArgumentValidator: top = ", value);
    setLayoutProperty(Titanium::LayoutEngine::ValueName::Top, static_cast<std::string>(argument));
    set_top(argument);
    result = true;
    return result;
  }

  bool Label::setLeftArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
    bool result = false;
    std::string value = static_cast<std::string>(argument);
    TITANIUM_LOG_INFO("Label::setLeftArgumentValidator: left = ", value);
    setLayoutProperty(Titanium::LayoutEngine::ValueName::Left, static_cast<std::string>(argument));
    set_left(argument);
    result = true;
    return result;
  }

  bool Label::setWidthArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
    bool result = false;
    std::string value = static_cast<std::string>(argument);
    TITANIUM_LOG_INFO("Label::setWidthArgumentValidator: width = ", value);
    setLayoutProperty(Titanium::LayoutEngine::ValueName::Width, static_cast<std::string>(argument));
    set_width(argument);
    result = true;
    return result;
  }

  bool Label::setHeightArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT {
    TITANIUM_ASSERT(argument.IsString() || argument.IsNumber());
    bool result = false;
    std::string value = static_cast<std::string>(argument);
    TITANIUM_LOG_INFO("Label::setHeightArgumentValidator: height = ", value);
    setLayoutProperty(Titanium::LayoutEngine::ValueName::Height, static_cast<std::string>(argument));
    set_height(argument);
    result = true;
    return result;
  }

  void Label::enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT {
    TITANIUM_LOG_DEBUG("Label::enableEvent: (event name '", event_name, "'");

    const JSContext  ctx = this->get_context();

    using namespace Windows::UI::Xaml::Input;
    using namespace Windows::UI::Xaml;

    if (event_name == "click") {
      if (click_event_count_ == 0) {
        click_event_ = getComponent()->Tapped += ref new TappedEventHandler([this, ctx](Platform::Object ^ sender, TappedRoutedEventArgs ^ e) {
          auto component = safe_cast<FrameworkElement^>(sender);
          auto position = e->GetPosition(component);

          JSObject  eventArgs = ctx.CreateObject();
          eventArgs.SetProperty("x", ctx.CreateNumber(position.X));
          eventArgs.SetProperty("y", ctx.CreateNumber(position.Y));

          this->fireEvent("click", eventArgs);
        });
      }

      ++click_event_count_;

      return;
    }
  }

}}  // namespace TitaniumWindows { namespace UI {
