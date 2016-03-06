/**
 * TitaniumKit Titanium.UI.SearchBar
 *
 * Copyright (c) 2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_SEARCHBAR_HPP_
#define _TITANIUM_SEARCHBAR_HPP_

#include "Titanium/UI/View.hpp"
#include <vector>

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		class TableViewRow;

		/*!
		  @class
		  @discussion This is the Titanium SearchBar Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.SearchBar
		*/
		class TITANIUMKIT_EXPORT SearchBar : public View, public JSExport<SearchBar>
		{

		public:

			/*!
			  @property
			  @abstract autocapitalization
			  @discussion Determines how text is capitalized during typing.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(TEXT_AUTOCAPITALIZATION, autocapitalization);

			/*!
			  @property
			  @abstract autocorrect
			  @discussion Determines whether the text in the search bar is autocorrected during typing.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, autocorrect);

			/*!
			  @property
			  @abstract barColor
			  @discussion Bar color of the search bar view, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, barColor);

			/*!
			  @property
			  @abstract hintText
			  @discussion Text to show when the search bar field is not focused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, hintText);

			/*!
			  @property
			  @abstract hinttextid
			  @discussion Key identifying a string from the locale file to use for the[hintText](Titanium.UI.SearchBar.hintText) property.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, hinttextid);

			/*!
			  @property
			  @abstract keyboardType
			  @discussion Keyboard type constant to use when the field is focused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(KEYBOARD, keyboardType);

			/*!
			  @property
			  @abstract keyboardAppearance
			  @discussion Determines the appearance of the keyboard to be displayed the field is focused.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(KEYBOARD_APPEARANCE, keyboardAppearance);

			/*!
			  @property
			  @abstract prompt
			  @discussion Single line of text displayed at the top of the search bar.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, prompt);

			/*!
			  @property
			  @abstract promptid
			  @discussion Key identifying a string from the locale file to use for the[prompt](Titanium.UI.SearchBar.prompt) property.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, promptid);

			/*!
			  @property
			  @abstract showBookmark
			  @discussion Determines whether the bookmark button is displayed.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showBookmark);

			/*!
			  @property
			  @abstract showCancel
			  @discussion Determines whether the cancel button is displayed.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(bool, showCancel);

			/*!
			  @property
			  @abstract value
			  @discussion Value of the search bar.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, value);

			TITANIUM_PROPERTY_IMPL_DEF(std::function<void(const std::string&)>, querySubmitted);
			TITANIUM_PROPERTY_IMPL_DEF(std::function<std::vector<std::string>(const std::string&)>, suggestionRequested);

			SearchBar(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~SearchBar()                   = default;
			SearchBar(const SearchBar&)            = default;
			SearchBar& operator=(const SearchBar&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			SearchBar(SearchBar&&)                 = default;
			SearchBar& operator=(SearchBar&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(autocapitalization);
			TITANIUM_PROPERTY_DEF(autocorrect);
			TITANIUM_PROPERTY_DEF(barColor);
			TITANIUM_PROPERTY_DEF(hintText);
			TITANIUM_PROPERTY_DEF(hinttextid);
			TITANIUM_PROPERTY_DEF(keyboardType);
			TITANIUM_PROPERTY_DEF(keyboardAppearance);
			TITANIUM_PROPERTY_DEF(prompt);
			TITANIUM_PROPERTY_DEF(promptid);
			TITANIUM_PROPERTY_DEF(showBookmark);
			TITANIUM_PROPERTY_DEF(showCancel);
			TITANIUM_PROPERTY_DEF(value);

			TITANIUM_FUNCTION_DEF(getAutocapitalization);
			TITANIUM_FUNCTION_DEF(setAutocapitalization);
			TITANIUM_FUNCTION_DEF(getAutocorrect);
			TITANIUM_FUNCTION_DEF(setAutocorrect);
			TITANIUM_FUNCTION_DEF(getBarColor);
			TITANIUM_FUNCTION_DEF(setBarColor);
			TITANIUM_FUNCTION_DEF(getHintText);
			TITANIUM_FUNCTION_DEF(setHintText);
			TITANIUM_FUNCTION_DEF(getHinttextid);
			TITANIUM_FUNCTION_DEF(setHinttextid);
			TITANIUM_FUNCTION_DEF(getKeyboardType);
			TITANIUM_FUNCTION_DEF(setKeyboardType);
			TITANIUM_FUNCTION_DEF(getKeyboardAppearance);
			TITANIUM_FUNCTION_DEF(setKeyboardAppearance);
			TITANIUM_FUNCTION_DEF(getPrompt);
			TITANIUM_FUNCTION_DEF(setPrompt);
			TITANIUM_FUNCTION_DEF(getPromptid);
			TITANIUM_FUNCTION_DEF(setPromptid);
			TITANIUM_FUNCTION_DEF(getShowBookmark);
			TITANIUM_FUNCTION_DEF(setShowBookmark);
			TITANIUM_FUNCTION_DEF(getShowCancel);
			TITANIUM_FUNCTION_DEF(setShowCancel);
			TITANIUM_FUNCTION_DEF(getValue);
			TITANIUM_FUNCTION_DEF(setValue);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			TEXT_AUTOCAPITALIZATION autocapitalization__;
			bool autocorrect__;
			std::string barColor__;
			std::string hintText__;
			std::string hinttextid__;
			KEYBOARD keyboardType__;
			KEYBOARD_APPEARANCE keyboardAppearance__;
			std::string prompt__;
			std::string promptid__;
			bool showBookmark__;
			bool showCancel__;
			std::string value__;
			std::function<void(const std::string&)> querySubmitted__;
			std::function<std::vector<std::string>(const std::string&)> suggestionRequested__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_SEARCHBAR_HPP_