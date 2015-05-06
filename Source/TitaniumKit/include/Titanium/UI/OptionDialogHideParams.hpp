/**
 * TitaniumKit OptionDialogHideParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_OPTIONDIALOGHIDEPARAMS_HPP_
#define _TITANIUM_UI_OPTIONDIALOGHIDEPARAMS_HPP_

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
		  @discussion This is the OptionDialogHideParams.
		  Dictionary of options for the Titanium.UI.OptionDialog.show method.
		  See api/http://docs.appcelerator.com/titanium/3.0/#!/api/showParams
		*/
		struct OptionDialogHideParams
		{
			bool animated {false};
			Dimension rect;
			std::shared_ptr<Titanium::UI::View> view;
		};

		OptionDialogHideParams js_to_OptionDialogHideParams(const JSObject& object);
		JSObject OptionDialogHideParams_to_js(const JSContext& js_context, const OptionDialogHideParams& dict);
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_OPTIONDIALOGHIDEPARAMS_HPP_
