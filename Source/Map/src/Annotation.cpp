/**
 * Titanium.Map.Annotation for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Map/Annotation.hpp"
#include "TitaniumWindows/Utility.hpp"

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
using namespace Windows::UI::Xaml::Controls::Maps;
using namespace Windows::Devices::Geolocation;
#endif

namespace TitaniumWindows
{
	namespace Map
	{

		void Annotation::set_latitude(const double& latitude) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_latitude(latitude);
			updateGeoLocation();
		}

		void Annotation::set_longitude(const double& longitude) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_longitude(longitude);
			updateGeoLocation();
		}

		void Annotation::set_pincolor(const Titanium::Map::ANNOTATION_COLOR& pincolor) TITANIUM_NOEXCEPT
		{
			if (pincolor == Titanium::Map::ANNOTATION_COLOR::AZURE) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Azure);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::BLUE) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Blue);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::CYAN) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Cyan);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::GREEN) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Green);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::MAGENTA) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Magenta);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::ORANGE) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Orange);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::PURPLE) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Purple);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::RED) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Red);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::ROSE) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::MistyRose); // FIXME What is a good color to match here?
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::VIOLET) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Violet);
			} else if (pincolor == Titanium::Map::ANNOTATION_COLOR::YELLOW) {
				icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Yellow);
			}
		}

		void Annotation::updateGeoLocation() {
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			BasicGeoposition bgp = { get_latitude(), get_longitude() };
			MapControl::SetLocation(mapicon__, ref new Geopoint(bgp));
			MapControl::SetNormalizedAnchorPoint(mapicon__, Windows::Foundation::Point(0.5, 0.5)); // middle is anchor
#endif
		}

		void Annotation::set_title(const std::string& title) TITANIUM_NOEXCEPT
		{
			Titanium::Map::Annotation::set_title(title);
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			text__->Text = TitaniumWindows::Utility::ConvertString(title);
#endif
		}

		Annotation::Annotation(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Titanium::Map::Annotation(js_context)
		{
			TITANIUM_LOG_DEBUG("Annotation::ctor Initialize");
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapicon__ = ref new Windows::UI::Xaml::Controls::Grid();

			// Draw circle
			icon__ = ref new Windows::UI::Xaml::Shapes::Ellipse();
			icon__->Fill = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Red);
			icon__->Stroke = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Black);
			icon__->StrokeThickness = 2;
			icon__->Width = 24;
			icon__->Height = 24;
			mapicon__->Children->Append(icon__);

			// Draw text
			text__ = ref new Windows::UI::Xaml::Controls::TextBlock();
			text__->Text = Utility::ConvertUTF8String(get_title());
			text__->FontSize = 16;
			text__->FontWeight = Windows::UI::Text::FontWeights::Bold;
			text__->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Black);
			text__->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;
			text__->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
			text__->Height = 62;
			mapicon__->Children->Append(text__);
#endif
		}

		Annotation::~Annotation()
		{
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
			mapicon__ = nullptr;
#endif
		}

		void Annotation::JSExportInitialize() 
		{
			JSExport<Annotation>::SetClassVersion(1);
			JSExport<Annotation>::SetParent(JSExport<Titanium::Map::Annotation>::Class());
		}

	} // namespace Map
}  // namespace Titanium
