<%
var full_name = name;
var namespaces = full_name.split('.');
var base_name = namespaces[namespaces.length - 1];
var name_upper = full_name.toUpperCase().replace(/\./g, '_');
var windows_name = full_name.replace(/\./g, '::');

%>
/**
 * Windows Native Wrapper for <%= full_name %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_<%= name_upper %>_HPP_
#define _TITANIUM_<%= name_upper %>_HPP_

#include "Titanium/Module.hpp"

<% for (var i = 0; i < namespaces.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= namespaces[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>

		using namespace HAL;

		class TITANIUMKIT_EXPORT <%= base_name %> : public Module, public JSExport<<%= base_name %>>
		{

		public:
<% for (property_name in properties) {
	   if (properties[property_name]['setter']) { -%>
			TITANIUM_PROPERTY_DEF(<%= property_name %>);
	<% } else { -%>
			TITANIUM_PROPERTY_READONLY_DEF(<%= property_name %>);
<%     }
   } -%>

<% for (var i = 0; i < methods.length; i++) {
	var method = methods[i];
	// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
	if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
		method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0 || method.name == '.ctor') {
			continue;
	} -%>
			TITANIUM_FUNCTION_DEF(<%= method.name %>);
<% } -%>

			<%= base_name %>(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~<%= base_name %>() = default;
			<%= base_name %>(const <%= base_name %>&) = default;
			<%= base_name %>& operator=(const <%= base_name %>&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			<%= base_name %>(<%= base_name %>&&)                 = default;
			<%= base_name %>& operator=(<%= base_name %>&&)      = default;
#endif

			static void JSExportInitialize();

			<%= windows_name %>^ unwrap();
			void wrap(<%= windows_name %>^ object);

		private:
			<%= windows_name %>^ wrapped__;
		};

<% for (var i = namespaces.length - 2; i>= 0; i--) { -%>
<%= Array(i + 1).join('\t') %>} // namespace <%= namespaces[i] %>
<% } -%>
#endif // _TITANIUM_<%= name_upper %>_HPP_
