/**
 * TitaniumKit OptionDialogShowParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_OPTIONDIALOGSHOWPARAMS_HPP_
#define _TITANIUM_UI_OPTIONDIALOGSHOWPARAMS_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/UI/Dimension.hpp"

namespace Titanium
{
	namespace UI
	{
		class View;

		using namespace HAL;

		/*!
		  @struct
		  @discussion This is the OptionDialogShowParams.
		  Dictionary of options for the Titanium.UI.OptionDialog.show method.
		  See api/http://docs.appcelerator.com/titanium/3.0/#!/api/showParams
		*/
		struct OptionDialogShowParams
		{
			bool animated {false};
			Dimension rect;
			std::shared_ptr<Titanium::UI::View> view;
		};

		OptionDialogShowParams js_to_OptionDialogShowParams(const JSObject& object);
		JSObject OptionDialogShowParams_to_js(const JSContext& js_context, const OptionDialogShowParams& dict);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_OPTIONDIALOGSHOWPARAMS_HPP_
