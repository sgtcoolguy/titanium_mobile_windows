/**
 * TitaniumKit Titanium.UI.Clipboard
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_CLIPBOARD_HPP_
#define _TITANIUM_CLIPBOARD_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium Clipboard Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Clipboard
		*/
		class TITANIUMKIT_EXPORT Clipboard : public View, public JSExport<Clipboard>
		{

		public:

			/*!
			  @method
			  @abstract clearData
			  @discussion Deletes data of the specified MIME type stored in the clipboard. If MIME type omitted, all data is deleted.
			*/
			virtual void clearData(const std::string& type) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract clearText
			  @discussion Deletes all text data stored in the clipboard.
			*/
			virtual void clearText() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract getData
			  @discussion Gets data of the specified MIME type stored in the clipboard.
			*/
			virtual JSObject getData(const std::string& type) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract getText
			  @discussion Gets text data stored in the clipboard.
			*/
			virtual std::string getText() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract hasData
			  @discussion Indicates whether any data of the specified MIME type is stored in the clipboard.
			*/
			virtual bool hasData(const std::string& type) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract hasText
			  @discussion Indicates whether any text data is stored in the clipboard.
			*/
			virtual bool hasText() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setData
			  @discussion Stores data of the specified MIME type in the clipboard.
			*/
			virtual void setData(const std::string& type, JSObject data) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract setText
			  @discussion Stores text data in the clipboard.
			*/
			virtual void setText(const std::string& text) TITANIUM_NOEXCEPT;

			Clipboard(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
			virtual ~Clipboard()                   = default;
			Clipboard(const Clipboard&)            = default;
			Clipboard& operator=(const Clipboard&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Clipboard(Clipboard&&)                 = default;
			Clipboard& operator=(Clipboard&&)      = default;
#endif

			static void JSExportInitialize();

			TITANIUM_FUNCTION_DEF(clearData);
			TITANIUM_FUNCTION_DEF(clearText);
			TITANIUM_FUNCTION_DEF(getData);
			TITANIUM_FUNCTION_DEF(getText);
			TITANIUM_FUNCTION_DEF(hasData);
			TITANIUM_FUNCTION_DEF(hasText);
			TITANIUM_FUNCTION_DEF(setData);
			TITANIUM_FUNCTION_DEF(setText);
		};

	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_CLIPBOARD_HPP_