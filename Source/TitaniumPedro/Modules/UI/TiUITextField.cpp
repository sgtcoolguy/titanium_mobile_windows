/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUITextField.h"
#include "Modules/UI/UIModule.h"
#include <Windows.h>
#include "TiCore/TiWebColor.h"

namespace Ti { namespace UI {

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction TextField::ClassMethods[] = {
	// appearance: iOS
	// attributedHintText: iOS
	// attributedString: iOS
	// autoLink: Android
	{"setAutocapitalization" ,_setAutocapitalization ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getAutocapitalization" ,_getAutocapitalization ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setAutocorrect" ,_setAutocorrect ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getAutocorrect" ,_getAutocorrect ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setBorderStyle" ,_setBorderStyle ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getBorderStyle" ,_getBorderStyle ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	// clearButtonMode: iOS
	{"setClearOnEdit" ,_setClearOnEdit ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getClearOnEdit" ,_getClearOnEdit ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setColor" ,_setColor ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"getColor" ,_getColor ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setEditable" ,_setEditable ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getEditable" ,_getEditable ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setEllipsize" ,_setEllipsize ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getEllipsize" ,_getEllipsize ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setEnableReturnKey" ,_setEnableReturnKey ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getEnableReturnKey" ,_getEnableReturnKey ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setFont" ,_setFont ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getFont" ,_getFont ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setHintText" ,_setHintText ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getHintText" ,_getHintText ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	// keyboardToolbar: iOS
	// keyboardToolbarColor: iOS
	// keyboardToolbarHeight: iOS
	{"setKeyboardType" ,_setKeyboardType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getKeyboardType" ,_getKeyboardType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	// leftButton: iOS
	// leftButtonMode: iOS
	// leftButtonPadding: iOS
	{"setMaxLength" ,_setMaxLength ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getMaxLength" ,_getMaxLength ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	// minimumFontSize: iOS
	// paddingLeft: iOS
	// paddingRight: iOS
	{"setPasswordMask" ,_setPasswordMask ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getPasswordMask" ,_getPasswordMask ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setReturnKeyType" ,_setReturnKeyType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getReturnKeyType" ,_getReturnKeyType ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"setRightButton" ,_setRightButton ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"getRightButton" ,_getRightButton ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"setRightButtonMode" ,_setRightButtonMode ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"getRightButtonMode" ,_getRightButtonMode ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"setRightButtonPadding" ,_setRightButtonPadding ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	//{"getRightButtonPadding" ,_getRightButtonPadding ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getSelection" ,_getSelection ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setSuppressReturn" ,_setSuppressReturn ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getSuppressReturn" ,_getSuppressReturn ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },	
	{"setTextAlign" ,_setTextAlign ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getTextAlign" ,_getTextAlign ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setValue" ,_setValue ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getValue" ,_getValue ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"setVerticalAlign" ,_setVerticalAlign ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
	{"getVerticalAlign" ,_getVerticalAlign ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
  {"blur", _blur, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
  {"focus", _focus, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
  {"hasText", _hasText, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{0,0,0}
};

// TODO: This was shamelessly copied from TiUiLabel.cpp. Move code to Utils class to re-use.
Ti::Value TextField::setFont(const std::vector<Ti::Value>& arguments) {
  const auto& arg1 = arguments.at(0);
  if (!arg1.isObject()) {
    OutputDebugString(L"[WARN] Label.setFont() must be an object. Returning Undefined");
    return Ti::Value::Undefined();
  }

  const auto font = arg1.getProperty("fontFamily");
  if (font.isString()) {
    const auto str = font.toString();
    const auto pStr = Ti::Utils::GetPlatformString(str);
    text_box_->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(pStr);
  }
  const auto size = arg1.getProperty("fontSize");
  if (size.isString() || size.isNumber()) {
    text_box_->FontSize = size.toDouble();
  }

  const auto weight = arg1.getProperty("fontWeight");
  if (weight.isString()) {
    const auto str = weight.toString();
    if (str == "bold") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::Bold;
    }
    else if (str == "black") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::Black;
    }
    else if (str == "light") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::Light;
    }
    else if (str == "extraBlack") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::ExtraBlack;
    }
    else if (str == "extraBold") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::ExtraBold;
    }
    else if (str == "extraLight") {
      text_box_->FontWeight = Windows::UI::Text::FontWeights::ExtraLight;
    }
  }
  return Ti::Value::Undefined();
}

Ti::Value TextField::getKeyboardType(const std::vector<Ti::Value>& arguments) {
  // FIXME What is the difference between number pad, decimal pad and numbers punctuation pad?
  // FIXME What does ACSII pad correspond to?
  switch (text_box_->InputScope->Names->GetAt(0)->NameValue) {
  case Windows::UI::Xaml::Input::InputScopeNameValue::Default:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_DEFAULT));
  case Windows::UI::Xaml::Input::InputScopeNameValue::Url:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_URL));
  case Windows::UI::Xaml::Input::InputScopeNameValue::Number:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_DECIMAL_PAD));
  case Windows::UI::Xaml::Input::InputScopeNameValue::TelephoneNumber:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_PHONE_PAD));
  case Windows::UI::Xaml::Input::InputScopeNameValue::EmailSmtpAddress:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_EMAIL));
  case Windows::UI::Xaml::Input::InputScopeNameValue::NameOrPhoneNumber:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_NAMEPHONE_PAD));
  case Windows::UI::Xaml::Input::InputScopeNameValue::CurrencyAmountAndSymbol:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_NUMBERS_PUNCTUATION));
  default:
    return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_DEFAULT));
  }
  return Ti::Value(static_cast<double>(::UI::UIModule::KEYBOARD_DEFAULT));
}

// Sets the value of the keyboardType property.
Ti::Value TextField::setKeyboardType(const std::vector<Ti::Value>& arguments) {
  auto type = static_cast<int>(arguments.at(0).toDouble());
  auto scope_name = ref new Windows::UI::Xaml::Input::InputScopeName();
  if (type == ::UI::UIModule::KEYBOARD_ASCII) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Default;
  }
  else if (type == ::UI::UIModule::KEYBOARD_DECIMAL_PAD) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Number;
  }
  else if (type == ::UI::UIModule::KEYBOARD_DEFAULT) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Default;
  }
  else if (type == ::UI::UIModule::KEYBOARD_EMAIL) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::EmailSmtpAddress;
  }
  else if (type == ::UI::UIModule::KEYBOARD_NAMEPHONE_PAD) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::NameOrPhoneNumber;
  }
  else if (type == ::UI::UIModule::KEYBOARD_NUMBERS_PUNCTUATION) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::CurrencyAmountAndSymbol;
  }
  else if (type == ::UI::UIModule::KEYBOARD_NUMBER_PAD) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Number;
  }
  else if (type == ::UI::UIModule::KEYBOARD_PHONE_PAD) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::TelephoneNumber;
  }
  else if (type == ::UI::UIModule::KEYBOARD_URL) {
    scope_name->NameValue = Windows::UI::Xaml::Input::InputScopeNameValue::Url;
  }
  else {
    return Ti::Value::Undefined();
  }
  text_box_->InputScope->Names->Clear();
  text_box_->InputScope->Names->Append(scope_name);
  return Ti::Value::Undefined();
}

// TODO All the alignment methods here were also copied from TiUILabel, extract common code to Utils class!
Ti::Value TextField::getTextAlign(const std::vector<Ti::Value>& arguments) {
  switch (text_box_->TextAlignment) {
  case Windows::UI::Xaml::TextAlignment::Center:
    return Ti::Value("center");
  case Windows::UI::Xaml::TextAlignment::Justify:
    return Ti::Value("justify");
  case Windows::UI::Xaml::TextAlignment::Left:
    return Ti::Value("left");
  case Windows::UI::Xaml::TextAlignment::Right:
    return Ti::Value("right");
  default:
    return Ti::Value::Undefined();
  }
}

Ti::Value TextField::setTextAlign(const std::vector<Ti::Value>& arguments) {
   auto textAlign = arguments.at(0).toString();
   // let's make it all lowercase, fool proof

   std::transform(textAlign.begin(), textAlign.end(), textAlign.begin(), ::tolower);
   if (textAlign == "center") {
     text_box_->TextAlignment = Windows::UI::Xaml::TextAlignment::Center;
   }
   else if (textAlign == "justify") {
     text_box_->TextAlignment = Windows::UI::Xaml::TextAlignment::Justify;
   }
   else if (textAlign == "left") {
     text_box_->TextAlignment = Windows::UI::Xaml::TextAlignment::Left;
   }
   else if (textAlign == "right") {
     text_box_->TextAlignment = Windows::UI::Xaml::TextAlignment::Right;
   }

   return Ti::Value::Undefined();
 }

Ti::Value TextField::getVerticalAlign(const std::vector<Ti::Value>& arguments) {
  switch (text_box_->VerticalAlignment) {
  case Windows::UI::Xaml::VerticalAlignment::Bottom:
    return Ti::Value("bottom");
  case Windows::UI::Xaml::VerticalAlignment::Center:
    return Ti::Value("center");
  case Windows::UI::Xaml::VerticalAlignment::Stretch:
    return Ti::Value("stretch");
  case Windows::UI::Xaml::VerticalAlignment::Top:
    return Ti::Value("top");
  default:
    return Ti::Value::Undefined();
  }
}

Ti::Value TextField::setVerticalAlign(const std::vector<Ti::Value>& arguments) {
  auto vertAlign = arguments.at(0).toString();
  // let's make it all lowercase, fool proof
  std::transform(vertAlign.begin(), vertAlign.end(), vertAlign.begin(), ::tolower);
  if (vertAlign == "bottom") {
    text_box_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Bottom;
  }
  else if (vertAlign == "center") {
    text_box_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
  }
  else if (vertAlign == "stretch") {
    text_box_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Stretch;
  }
  else if (vertAlign == "top") {
    text_box_->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
  }

  return Ti::Value::Undefined();
}

Ti::Value TextField::eventAdded(const std::vector<Ti::Value>& arguments) {
  const auto event = arguments.at(0).toString();
  using namespace std::placeholders;
  const auto current = Windows::UI::Xaml::Window::Current;

  if (Ti::Constants::EventBlur == event) {
    ++blur_event_handler_count_;
    if (blur_event_handler_count_ == 1) {
      const auto changedCallback = std::bind([current](const std::weak_ptr<TextField>& weakThis, Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e) {
        const auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          const auto dispatchedCallback = std::bind([](const std::weak_ptr<TextField>& weakThis) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
              Ti::Value eventArgs;
              eventArgs.setProperty("value", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->text_box_->Text)));
              strong_ptr->fireEvent(Ti::Constants::EventBlur, eventArgs);
            }
          }, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

          if (current) {
            current->Dispatcher->RunAsync(
              Windows::UI::Core::CoreDispatcherPriority::Normal,
              ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
          }
        }
      }, std::move(get_weak_ptr_for_proxy()), _1, _2);
      blur_event_ = text_box_->LostFocus += ref new Windows::UI::Xaml::RoutedEventHandler(changedCallback);
    }
  }
  else if (Ti::Constants::EventChange == event) {
    ++change_event_handler_count_;
    if (change_event_handler_count_ == 1) {
      const auto changedCallback = std::bind([current](const std::weak_ptr<TextField>& weakThis, Platform::Object ^sender, Windows::UI::Xaml::Controls::TextChangedEventArgs ^e) {
        const auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          const auto dispatchedCallback = std::bind([](const std::weak_ptr<TextField>& weakThis) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
              Ti::Value eventArgs;
              eventArgs.setProperty("value", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->text_box_->Text)));
              strong_ptr->fireEvent(Ti::Constants::EventChange, eventArgs);
            }
          }, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

          if (current) {
            current->Dispatcher->RunAsync(
              Windows::UI::Core::CoreDispatcherPriority::Normal,
              ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
          }
        }
      }, std::move(get_weak_ptr_for_proxy()), _1, _2);
      change_event_ = text_box_->TextChanged += ref new Windows::UI::Xaml::Controls::TextChangedEventHandler(changedCallback);
    }
  }
  else if (Ti::Constants::EventFocus == event) {
    ++focus_event_handler_count_;
    if (focus_event_handler_count_ == 1) {
      const auto changedCallback = std::bind([current](const std::weak_ptr<TextField>& weakThis, Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e) {
        const auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          const auto dispatchedCallback = std::bind([](const std::weak_ptr<TextField>& weakThis) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
              Ti::Value eventArgs;
              eventArgs.setProperty("value", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->text_box_->Text)));
              strong_ptr->fireEvent(Ti::Constants::EventFocus, eventArgs);
            }
          }, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

          if (current) {
            current->Dispatcher->RunAsync(
              Windows::UI::Core::CoreDispatcherPriority::Normal,
              ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
          }
        }
      }, std::move(get_weak_ptr_for_proxy()), _1, _2);
      focus_event_ = text_box_->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler(changedCallback);
    }
  }
  else if (Ti::Constants::EventReturn == event) {
    ++return_event_handler_count_;
    if (return_event_handler_count_ == 1) {
      const auto changedCallback = std::bind([current](const std::weak_ptr<TextField>& weakThis, Platform::Object ^sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs ^e) {
        const auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          // Only fire if the key is the "Return" key!
          if (e->Key == Windows::System::VirtualKey::Enter) {
            const auto dispatchedCallback = std::bind([](const std::weak_ptr<TextField>& weakThis) {
              const auto strong_ptr = weakThis.lock();
              if (strong_ptr) {
                Ti::Value eventArgs;
                eventArgs.setProperty("value", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->text_box_->Text)));
                strong_ptr->fireEvent(Ti::Constants::EventReturn, eventArgs);
              }
            }, /* std::move(strong_ptr->get_weak_ptr_for_proxy()) causes crash */ weakThis);

            if (current) {
              current->Dispatcher->RunAsync(
                Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler(dispatchedCallback));
            }
          }
        }
      }, std::move(get_weak_ptr_for_proxy()), _1, _2);
      return_event_ = text_box_->KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler(changedCallback);
    }
  }
  return Ti::Proxy::eventAdded(arguments);
}

Ti::Value TextField::eventRemoved(const std::vector<Ti::Value>& arguments) {
  const auto event = arguments.at(0).toString();
  if (Ti::Constants::EventBlur == event) {
    --blur_event_handler_count_;
    if (blur_event_handler_count_ == 0) {
      text_box_->LostFocus -= blur_event_;
    }
  }
  else if (Ti::Constants::EventChange == event) {
    --change_event_handler_count_;
    if (change_event_handler_count_ == 0) {
      text_box_->TextChanged -= change_event_;
    }
  }
  else if (Ti::Constants::EventFocus == event) {
    --focus_event_handler_count_;
    if (focus_event_handler_count_ == 0) {
      text_box_->GotFocus -= focus_event_;
    }
  }
  else if (Ti::Constants::EventReturn == event) {
    --return_event_handler_count_;
    if (return_event_handler_count_ == 0) {
      text_box_->KeyDown -= return_event_;
    }
  }
  return Ti::Proxy::eventRemoved(arguments);
}
}} // namespace Ti { namespace UI {
