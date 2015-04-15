
/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.TextBox
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TEXTBOX_HPP_
#define _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TEXTBOX_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Xaml
		{
			namespace Controls
			{

		using namespace HAL;

		class TITANIUMKIT_EXPORT TextBox : public Module, public JSExport<TextBox>
		{

		public:
			TITANIUM_PROPERTY_DEF(PreventKeyboardDisplayOnProgrammaticFocus);
				TITANIUM_PROPERTY_DEF(PlaceholderText);
				TITANIUM_PROPERTY_DEF(IsColorFontEnabled);
				TITANIUM_PROPERTY_DEF(HeaderTemplate);
				TITANIUM_PROPERTY_DEF(Header);
				TITANIUM_PROPERTY_DEF(SelectionHighlightColor);
				TITANIUM_PROPERTY_DEF(SelectionStart);
				TITANIUM_PROPERTY_DEF(SelectionLength);
				TITANIUM_PROPERTY_DEF(SelectedText);
				TITANIUM_PROPERTY_DEF(MaxLength);
				TITANIUM_PROPERTY_DEF(IsTextPredictionEnabled);
				TITANIUM_PROPERTY_DEF(IsSpellCheckEnabled);
				TITANIUM_PROPERTY_DEF(IsReadOnly);
				TITANIUM_PROPERTY_DEF(InputScope);
				TITANIUM_PROPERTY_DEF(AcceptsReturn);
				TITANIUM_PROPERTY_DEF(Text);
				TITANIUM_PROPERTY_DEF(TextWrapping);
				TITANIUM_PROPERTY_DEF(TextAlignment);
				TITANIUM_PROPERTY_READONLY_DEF(AcceptsReturnProperty);
			TITANIUM_PROPERTY_READONLY_DEF(InputScopeProperty);
			TITANIUM_PROPERTY_READONLY_DEF(IsReadOnlyProperty);
			TITANIUM_PROPERTY_READONLY_DEF(IsSpellCheckEnabledProperty);
			TITANIUM_PROPERTY_READONLY_DEF(IsTextPredictionEnabledProperty);
			TITANIUM_PROPERTY_READONLY_DEF(MaxLengthProperty);
			TITANIUM_PROPERTY_READONLY_DEF(TextAlignmentProperty);
			TITANIUM_PROPERTY_READONLY_DEF(TextProperty);
			TITANIUM_PROPERTY_READONLY_DEF(TextWrappingProperty);
			TITANIUM_PROPERTY_READONLY_DEF(HeaderProperty);
			TITANIUM_PROPERTY_READONLY_DEF(HeaderTemplateProperty);
			TITANIUM_PROPERTY_READONLY_DEF(IsColorFontEnabledProperty);
			TITANIUM_PROPERTY_READONLY_DEF(PlaceholderTextProperty);
			TITANIUM_PROPERTY_READONLY_DEF(PreventKeyboardDisplayOnProgrammaticFocusProperty);
			TITANIUM_PROPERTY_READONLY_DEF(SelectionHighlightColorProperty);

			TITANIUM_FUNCTION_DEF(Select);
			TITANIUM_FUNCTION_DEF(SelectAll);
			TITANIUM_FUNCTION_DEF(GetRectFromCharacterIndex);

			TextBox(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~TextBox() = default;
			TextBox(const TextBox&) = default;
			TextBox& operator=(const TextBox&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TextBox(TextBox&&)                 = default;
			TextBox& operator=(TextBox&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Xaml::Controls::TextBox^ unwrap();
			void wrap(Windows::UI::Xaml::Controls::TextBox^ object);

		private:
			Windows::UI::Xaml::Controls::TextBox^ wrapped__;
		};

			} // namespace Controls
		} // namespace Xaml
	} // namespace UI
} // namespace Windows
#endif // _TITANIUM_WINDOWS_UI_XAML_CONTROLS_TEXTBOX_HPP_
