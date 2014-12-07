/**
 * JavaScriptCoreCPP
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _JAVASCRIPTCORECPP_JSFUNCTION_HPP_
#define _JAVASCRIPTCORECPP_JSFUNCTION_HPP_

#include "JavaScriptCoreCPP/JSObject.hpp"

namespace JavaScriptCoreCPP {

/*!
  @class
  
  @discussion A JavaScript object of the Function type whose body is
  given as a string of JavaScript code. Use this class when you want
  to execute a script repeatedly to avoid the cost of re-parsing the
  script before each execution.

  The only way to create a JSFunction is by using the
  JSContext::CreateFunction member function.
*/
class JAVASCRIPTCORECPP_EXPORT JSFunction final : public JSObject JAVASCRIPTCORECPP_PERFORMANCE_COUNTER2(JSFunction) {
	
 private:
	
	// Only a JSContext can create a JSFunction.
	friend JSContext;
	
	JSFunction(const JSContext& js_context, const JSString& body, const std::vector<JSString>& parameter_names, const JSString& function_name, const JSString& source_url, int starting_line_number);

	static JSObjectRef MakeFunction(const JSContext& js_context, const JSString& body, const std::vector<JSString>& parameter_names, const JSString& function_name, const JSString& source_url, int starting_line_number);
};

} // namespace JavaScriptCoreCPP {

#endif // _JAVASCRIPTCORECPP_JSFUNCTION_HPP_