/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIImageButton.h"
#include "TiCore/TiUtils.h"

namespace Ti{
	namespace UI {

		JSStaticFunction const ImageButton::ClassMethods[] = {
				{ "setTitle", _setTitle, 0 },
				{ "setImage", _setImage, 0 },
				{ "setFont", _setFont, 0 },
				{ 0, 0, 0 }
		};
		ImageButton::ImageButton(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments)
		{
			using namespace Windows::UI::Xaml::Controls;
			using namespace Windows::UI::Xaml::Media;
			using namespace Windows::UI::Xaml;
			auto layout = ref new StackPanel();
			layout->Orientation = Orientation::Vertical;

			button_ = ref new Button();
			image_view_ = ref new Image();
			image_view_->Stretch = Stretch::None;
			label_ = ref new TextBlock();
			label_->TextAlignment = TextAlignment::Center;

			layout->Children->Append(image_view_);
			layout->Children->Append(label_);
			button_->Content = layout;

			setComponent(button_);
		}

		Ti::Value ImageButton::setTitle(const std::vector<Ti::Value>& args)
		{
			label_->Text = Ti::Utils::GetPlatformString(args[0].toString());
			return Ti::Value::Undefined();
		}
		Ti::Value ImageButton::setImage(const std::vector<Ti::Value>& args)
		{
			const auto winpath = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
			const auto path = Ti::Utils::GetPlatformString(std::string(winpath->Begin(), winpath->End()) + "/" + args[0].toString());
			const auto uri = ref new Windows::Foundation::Uri(path);
			const auto src = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
			image_view_->Source = src;
			return Ti::Value::Undefined();
		}
		Ti::Value ImageButton::setFont(const std::vector<Ti::Value>& arguments) {
			const auto& arg1 = arguments.at(0);
			if (!arg1.isObject()) {
				OutputDebugString(L"[WARN] Label.setFont() must be an object. Returning Undefined");
				return Ti::Value::Undefined();
			}

			const auto font = arg1.getProperty("fontFamily");
			if (font.isString()){
				const auto str = font.toString();
				const auto pStr = ref new Platform::String(std::wstring(str.begin(), str.end()).c_str());
				label_->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily(pStr);
			}
			const auto size = arg1.getProperty("fontSize");
			if (size.isString() || size.isNumber()) {
				label_->FontSize = std::stod(size.toString());
			}

			const auto weight = arg1.getProperty("fontWeight");
			if (weight.isString()) {
				const auto str = weight.toString();
				if (str == "bold") {
					label_->FontWeight = Windows::UI::Text::FontWeights::Bold;
				}
				else if (str == "black") {
					label_->FontWeight = Windows::UI::Text::FontWeights::Black;
				}
				else if (str == "light") {
					label_->FontWeight = Windows::UI::Text::FontWeights::Light;
				}
				else if (str == "extraBlack") {
					label_->FontWeight = Windows::UI::Text::FontWeights::ExtraBlack;
				}
				else if (str == "extraBold") {
					label_->FontWeight = Windows::UI::Text::FontWeights::ExtraBold;
				}
				else if (str == "extraLight") {
					label_->FontWeight = Windows::UI::Text::FontWeights::ExtraLight;
				}
			}
			return Ti::Value::Undefined();
		}
	}	// namespace UI {

}