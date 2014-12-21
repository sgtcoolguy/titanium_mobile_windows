/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_LABEL_HPP_
#define _TITANIUM_UI_LABEL_HPP_

#include "Titanium/UI/View.hpp"

namespace Titanium { namespace UI {
  
  using namespace HAL;
  
  /*!
   @class
   
   @discussion This is the Titanium UI Button.
   
   See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.Label
   */
  class TITANIUMKIT_EXPORT Label : public View, public JSExport<Label> {
	  
  public:
    
    virtual JSValue get_text() const               TITANIUM_NOEXCEPT final;
    virtual void    set_text(const JSValue& title) TITANIUM_NOEXCEPT final;
    
	Label(const JSContext& js_context)                          TITANIUM_NOEXCEPT;
	Label(const Label&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;
    
	virtual ~Label() = default;
	Label(const Label&) = default;
	Label& operator=(const Label&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
	Label(Label&&)                    = default;
	Label& operator=(Label&&)         = default;
#endif
	
    // TODO: The following functions can automatically be generated
    // from the YAML API docs.
    static void JSExportInitialize();
    
    // Base classes must implement this method. This is the minimum
    // functionality that you should perform:
    //
    // assert(argument.IsString());
    // set_text(argument);
    // return true;
    virtual bool setTextArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT;
    
  private:
    
    JSValue text__;
	
  };
}} // namespace Titanium { namespace UI {

#endif // _TITANIUM_UI_LABEL_HPP_
