/**
 * TitaniumKit Titanium.UI.PickerRow
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_PICKERROW_HPP_
#define _TITANIUM_UI_PICKERROW_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Font.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium PickerRow Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.PickerRow
		*/
		class TITANIUMKIT_EXPORT PickerRow : public View, public JSExport<PickerRow>
		{

		public:

			/*!
			  @property
			  @abstract color
			  @discussion Color of the item text, as a color name or hex triplet.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, color);

			/*!
			  @property
			  @abstract font
			  @discussion Font to use for the item text.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(Font, font);

			/*!
			  @property
			  @abstract title
			  @discussion Item text.
			*/
			TITANIUM_PROPERTY_IMPL_DEF(std::string, title);

			PickerRow(const JSContext&) TITANIUM_NOEXCEPT;
			virtual ~PickerRow()                   = default;
			PickerRow(const PickerRow&)            = default;
			PickerRow& operator=(const PickerRow&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			PickerRow(PickerRow&&)                 = default;
			PickerRow& operator=(PickerRow&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(color);
			TITANIUM_PROPERTY_DEF(font);
			TITANIUM_PROPERTY_DEF(title);

			TITANIUM_FUNCTION_DEF(getColor);
			TITANIUM_FUNCTION_DEF(setColor);
			TITANIUM_FUNCTION_DEF(getFont);
			TITANIUM_FUNCTION_DEF(setFont);
			TITANIUM_FUNCTION_DEF(getTitle);
			TITANIUM_FUNCTION_DEF(setTitle);

		protected:
#pragma warning(push)
#pragma warning(disable : 4251)
			std::string color__;
			Font font__;
			std::string title__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_PICKERROW_HPP_