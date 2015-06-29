/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_HPP_
#define _TITANIUM_UI_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{
		class View;
		class Window;
	}

	using namespace HAL;

	/*!
	  @class

	  @discussion This is the Titanium UI Module.

	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI
   */
	class TITANIUMKIT_EXPORT UIModule : public Module, public JSExport<UIModule>
	{
	public:

		/*!
		@property
		@abstract currentTab
		@discussion Value of the `currentTab` property
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<Titanium::UI::View>, currentTab);

		/*!
		@property
		@abstract currentWindow
		@discussion Value of the `currentWindow` property
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::shared_ptr<Titanium::UI::Window>, currentWindow);

		/*!
		  @property
		  @abstract backgroundColor
		  @discussion Value of the `backgroundColor` property
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::string, backgroundColor);

		/*!
		@property
		@abstract backgroundImage
		@discussion Value of the `backgroundImage` property
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::string, backgroundImage);

		TITANIUM_PROPERTY_DEF(backgroundImage);
		TITANIUM_PROPERTY_DEF(backgroundColor);
		TITANIUM_PROPERTY_DEF(currentTab);
		TITANIUM_PROPERTY_READONLY_DEF(currentWindow);

		TITANIUM_PROPERTY_READONLY_DEF(ANIMATION_CURVE_EASE_IN);
		TITANIUM_PROPERTY_READONLY_DEF(ANIMATION_CURVE_EASE_IN_OUT);
		TITANIUM_PROPERTY_READONLY_DEF(ANIMATION_CURVE_EASE_OUT);
		TITANIUM_PROPERTY_READONLY_DEF(ANIMATION_CURVE_LINEAR);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_ALL);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_CALENDAR);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_EMAIL_ADDRESSES);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_MAP_ADDRESSES);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_PHONE_NUMBERS);
		TITANIUM_PROPERTY_READONLY_DEF(AUTOLINK_URLS);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_ALL);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_BOTTOM);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_LEFT);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_RIGHT);
		TITANIUM_PROPERTY_READONLY_DEF(EXTEND_EDGE_TOP);
		TITANIUM_PROPERTY_READONLY_DEF(FACE_DOWN);
		TITANIUM_PROPERTY_READONLY_DEF(FACE_UP);
		TITANIUM_PROPERTY_READONLY_DEF(FILL);
		TITANIUM_PROPERTY_READONLY_DEF(INHERIT);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BORDERSTYLE_BEZEL);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BORDERSTYLE_LINE);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BORDERSTYLE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BORDERSTYLE_ROUNDED);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BUTTONMODE_ALWAYS);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BUTTONMODE_NEVER);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BUTTONMODE_ONBLUR);
		TITANIUM_PROPERTY_READONLY_DEF(INPUT_BUTTONMODE_ONFOCUS);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_APPEARANCE_ALERT);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_APPEARANCE_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_ASCII);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_DECIMAL_PAD);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_EMAIL);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_NAMEPHONE_PAD);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_NUMBERS_PUNCTUATION);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_NUMBER_PAD);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_PHONE_PAD);
		TITANIUM_PROPERTY_READONLY_DEF(KEYBOARD_URL);
		TITANIUM_PROPERTY_READONLY_DEF(LANDSCAPE_LEFT);
		TITANIUM_PROPERTY_READONLY_DEF(LANDSCAPE_RIGHT);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ACCESSORY_TYPE_CHECKMARK);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ACCESSORY_TYPE_DETAIL);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ACCESSORY_TYPE_DISCLOSURE);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ACCESSORY_TYPE_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ITEM_TEMPLATE_CONTACTS);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ITEM_TEMPLATE_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ITEM_TEMPLATE_SETTINGS);
		TITANIUM_PROPERTY_READONLY_DEF(LIST_ITEM_TEMPLATE_SUBTITLE);
		TITANIUM_PROPERTY_READONLY_DEF(NOTIFICATION_DURATION_LONG);
		TITANIUM_PROPERTY_READONLY_DEF(NOTIFICATION_DURATION_SHORT);
		TITANIUM_PROPERTY_READONLY_DEF(PICKER_TYPE_COUNT_DOWN_TIMER);
		TITANIUM_PROPERTY_READONLY_DEF(PICKER_TYPE_DATE);
		TITANIUM_PROPERTY_READONLY_DEF(PICKER_TYPE_DATE_AND_TIME);
		TITANIUM_PROPERTY_READONLY_DEF(PICKER_TYPE_PLAIN);
		TITANIUM_PROPERTY_READONLY_DEF(PICKER_TYPE_TIME);
		TITANIUM_PROPERTY_READONLY_DEF(PORTRAIT);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_DEFAULT);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_DONE);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_EMERGENCY_CALL);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_GO);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_GOOGLE);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_JOIN);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_NEXT);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_ROUTE);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_SEARCH);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_SEND);
		TITANIUM_PROPERTY_READONLY_DEF(RETURNKEY_YAHOO);
		TITANIUM_PROPERTY_READONLY_DEF(SIZE);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_ALIGNMENT_CENTER);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_ALIGNMENT_LEFT);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_ALIGNMENT_RIGHT);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_AUTOCAPITALIZATION_ALL);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_AUTOCAPITALIZATION_NONE);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_AUTOCAPITALIZATION_SENTENCES);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_AUTOCAPITALIZATION_WORDS);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_BODY);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_CAPTION1);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_CAPTION2);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_FOOTNOTE);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_HEADLINE);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_STYLE_SUBHEADLINE);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_VERTICAL_ALIGNMENT_BOTTOM);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_VERTICAL_ALIGNMENT_CENTER);
		TITANIUM_PROPERTY_READONLY_DEF(TEXT_VERTICAL_ALIGNMENT_TOP);
		TITANIUM_PROPERTY_READONLY_DEF(UNIT_CM);
		TITANIUM_PROPERTY_READONLY_DEF(UNIT_DIP);
		TITANIUM_PROPERTY_READONLY_DEF(UNIT_IN);
		TITANIUM_PROPERTY_READONLY_DEF(UNIT_MM);
		TITANIUM_PROPERTY_READONLY_DEF(UNIT_PX);
		TITANIUM_PROPERTY_READONLY_DEF(UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(UPSIDE_PORTRAIT);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_AUTHENTICATION);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_BAD_URL);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_CONNECT);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_FILE);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_FILE_NOT_FOUND);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_HOST_LOOKUP);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_REDIRECT_LOOP);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_SSL_FAILED);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_TIMEOUT);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(URL_ERROR_UNSUPPORTED_SCHEME);

		UIModule(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~UIModule() TITANIUM_NOEXCEPT;  //= default;
		UIModule(const UIModule&) = default;
		UIModule& operator=(const UIModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		UIModule(UIModule&&) = default;
		UIModule& operator=(UIModule&&) = default;
#endif

		static void JSExportInitialize();

		TITANIUM_FUNCTION_DEF(create2DMatrix);
		TITANIUM_FUNCTION_DEF(createActivityIndicator);
		TITANIUM_FUNCTION_DEF(createAlertDialog);
		TITANIUM_FUNCTION_DEF(createAnimation);
		TITANIUM_FUNCTION_DEF(createButton);
		TITANIUM_FUNCTION_DEF(createEmailDialog);
		TITANIUM_FUNCTION_DEF(createImageView);
		TITANIUM_FUNCTION_DEF(createLabel);
		TITANIUM_FUNCTION_DEF(createListItem);
		TITANIUM_FUNCTION_DEF(createListSection);
		TITANIUM_FUNCTION_DEF(createListView);
		TITANIUM_FUNCTION_DEF(createNotification);
		TITANIUM_FUNCTION_DEF(createOptionDialog);
		TITANIUM_FUNCTION_DEF(createProgressBar);
		TITANIUM_FUNCTION_DEF(createScrollableView);
		TITANIUM_FUNCTION_DEF(createScrollView);
		TITANIUM_FUNCTION_DEF(createSlider);
		TITANIUM_FUNCTION_DEF(createSwitch);
		TITANIUM_FUNCTION_DEF(createTab);
		TITANIUM_FUNCTION_DEF(createTabGroup);
		TITANIUM_FUNCTION_DEF(createTableView);
		TITANIUM_FUNCTION_DEF(createTableViewRow);
		TITANIUM_FUNCTION_DEF(createTableViewSection);
		TITANIUM_FUNCTION_DEF(createTextArea);
		TITANIUM_FUNCTION_DEF(createTextField);
		TITANIUM_FUNCTION_DEF(createView);
		TITANIUM_FUNCTION_DEF(createWebView);
		TITANIUM_FUNCTION_DEF(createWindow);

		TITANIUM_FUNCTION_DEF(getBackgroundColor);
		TITANIUM_FUNCTION_DEF(setBackgroundColor);
		TITANIUM_FUNCTION_DEF(getBackgroundImage);
		TITANIUM_FUNCTION_DEF(setBackgroundImage);
		TITANIUM_FUNCTION_DEF(getCurrentTab);
		TITANIUM_FUNCTION_DEF(setCurrentTab);
		TITANIUM_FUNCTION_DEF(getCurrentWindow);
		

	private:
		JSValue animation_curve_ease_in__;
		JSValue animation_curve_ease_in_out__;
		JSValue animation_curve_ease_out__;
		JSValue animation_curve_linear__;
		JSValue autolink_all__;
		JSValue autolink_calendar__;
		JSValue autolink_email_addresses__;
		JSValue autolink_map_addresses__;
		JSValue autolink_none__;
		JSValue autolink_phone_numbers__;
		JSValue autolink_urls__;
		JSValue extend_edge_all__;
		JSValue extend_edge_bottom__;
		JSValue extend_edge_left__;
		JSValue extend_edge_none__;
		JSValue extend_edge_right__;
		JSValue extend_edge_top__;
		JSValue face_down__;
		JSValue face_up__;
		JSValue fill__;
		JSValue inherit__;
		JSValue input_borderstyle_bezel__;
		JSValue input_borderstyle_line__;
		JSValue input_borderstyle_none__;
		JSValue input_borderstyle_rounded__;
		JSValue input_buttonmode_always__;
		JSValue input_buttonmode_never__;
		JSValue input_buttonmode_onblur__;
		JSValue input_buttonmode_onfocus__;
		JSValue keyboard_appearance_alert__;
		JSValue keyboard_appearance_default__;
		JSValue keyboard_ascii__;
		JSValue keyboard_decimal_pad__;
		JSValue keyboard_default__;
		JSValue keyboard_email__;
		JSValue keyboard_namephone_pad__;
		JSValue keyboard_numbers_punctuation__;
		JSValue keyboard_number_pad__;
		JSValue keyboard_phone_pad__;
		JSValue keyboard_url__;
		JSValue landscape_left__;
		JSValue landscape_right__;
		JSValue list_accessory_type_checkmark__;
		JSValue list_accessory_type_detail__;
		JSValue list_accessory_type_disclosure__;
		JSValue list_accessory_type_none__;
		JSValue list_item_template_contacts__;
		JSValue list_item_template_default__;
		JSValue list_item_template_settings__;
		JSValue list_item_template_subtitle__;
		JSValue notification_duration_long__;
		JSValue notification_duration_short__;
		JSValue picker_type_count_down_timer__;
		JSValue picker_type_date__;
		JSValue picker_type_date_and_time__;
		JSValue picker_type_plain__;
		JSValue picker_type_time__;
		JSValue portrait__;
		JSValue returnkey_default__;
		JSValue returnkey_done__;
		JSValue returnkey_emergency_call__;
		JSValue returnkey_go__;
		JSValue returnkey_google__;
		JSValue returnkey_join__;
		JSValue returnkey_next__;
		JSValue returnkey_route__;
		JSValue returnkey_search__;
		JSValue returnkey_send__;
		JSValue returnkey_yahoo__;
		JSValue size__;
		JSValue text_alignment_center__;
		JSValue text_alignment_left__;
		JSValue text_alignment_right__;
		JSValue text_autocapitalization_all__;
		JSValue text_autocapitalization_none__;
		JSValue text_autocapitalization_sentences__;
		JSValue text_autocapitalization_words__;
		JSValue text_style_body__;
		JSValue text_style_caption1__;
		JSValue text_style_caption2__;
		JSValue text_style_footnote__;
		JSValue text_style_headline__;
		JSValue text_style_subheadline__;
		JSValue text_vertical_alignment_bottom__;
		JSValue text_vertical_alignment_center__;
		JSValue text_vertical_alignment_top__;
		JSValue unit_cm__;
		JSValue unit_dip__;
		JSValue unit_in__;
		JSValue unit_mm__;
		JSValue unit_px__;
		JSValue unknown__;
		JSValue upside_portrait__;
		JSValue url_error_authentication__;
		JSValue url_error_bad_url__;
		JSValue url_error_connect__;
		JSValue url_error_file__;
		JSValue url_error_file_not_found__;
		JSValue url_error_host_lookup__;
		JSValue url_error_redirect_loop__;
		JSValue url_error_ssl_failed__;
		JSValue url_error_timeout__;
		JSValue url_error_unknown__;
		JSValue url_error_unsupported_scheme__;
		JSFunction createViewFunction(const JSContext& js_context, const std::string& viewClass) const TITANIUM_NOEXCEPT;

#pragma warning(push)
#pragma warning(disable: 4251)
		std::shared_ptr<Titanium::UI::View> currentTab__;
		std::shared_ptr<Titanium::UI::Window> currentWindow__;

		std::string backgroundColor__;
		std::string backgroundImage__;
#pragma warning(pop)

	};

}  // namespace Titanium

#endif  // _TITANIUM_UI_HPP_
