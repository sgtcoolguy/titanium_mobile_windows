/**
 * Titanium.UI.TableViewRow for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TABLEVIEWROW_HPP_
#define _TITANIUM_TABLEVIEWROW_HPP_

#include "Titanium/Module.hpp"
#include "Font.hpp"

namespace Titanium
{
	namespace UI
	{

		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium TableViewRow Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TableViewRow
		*/
		class TITANIUMKIT_EXPORT TableViewRow : public Module, public JSExport<TableViewRow>
		{

		public:

			/*!
			  @property
			  @abstract color
			  @discussion Default text color of the row when not selected, as a color name or hex triplet.
			*/
			virtual std::string color() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract font
			  @discussion Font to use for the row title.
			*/
			virtual JSValue font() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract hasCheck
			  @discussion Determines whether a system-provided checkmark is displayed on the right-hand side of the row.
			*/
			virtual bool hasCheck() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract hasChild
			  @discussion Determines whether a system-provided arrow is displayed on the right-hand side of the row.
			*/
			virtual bool hasChild() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract leftImage
			  @discussion Image to render in the left image area of the row, specified as a local path or URL.
			*/
			virtual std::string leftImage() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract rightImage
			  @discussion Image to render in the right image area of the row, specified as a local path or URL.
			*/
			virtual std::string rightImage() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract selectedBackgroundColor
			  @discussion Background color to render when the row is selected, as a color name or hex triplet.
			*/
			virtual std::string selectedBackgroundColor() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract selectedBackgroundImage
			  @discussion Background image to render when the row is selected.
			*/
			virtual std::string selectedBackgroundImage() const TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract title
			  @discussion Text to display on the row.
			*/
			virtual std::string title() const TITANIUM_NOEXCEPT;

			TableViewRow(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~TableViewRow() = default;
			TableViewRow(const TableViewRow&) = default;
			TableViewRow& operator=(const TableViewRow&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewRow(TableViewRow&&)                 = default;
			TableViewRow& operator=(TableViewRow&&)      = default;
#endif

			static void JSExportInitialize();

			virtual JSValue js_color() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_font() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_hasCheck() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_hasChild() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_leftImage() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_rightImage() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_selectedBackgroundColor() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_selectedBackgroundImage() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_title() const TITANIUM_NOEXCEPT final;
			virtual JSValue js_getColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getFont(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setFont(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHasCheck(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHasCheck(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHasChild(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHasChild(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getLeftImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setLeftImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getRightImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setRightImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSelectedBackgroundColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSelectedBackgroundColor(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSelectedBackgroundImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSelectedBackgroundImage(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setTitle(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

			protected:
#pragma warning(push)
#pragma warning(disable : 4251)
				std::string color__;
				Font font__;
				bool hasCheck__;
				bool hasChild__;
				std::string leftImage__;
				std::string rightImage__;
				std::string selectedBackgroundColor__;
				std::string selectedBackgroundImage__;
				std::string title__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_TABLEVIEWROW_HPP_