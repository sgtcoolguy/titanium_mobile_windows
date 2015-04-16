<%
String.prototype.to_windows_name = function() {
	return this.replace(/\./g, '::');
};

var full_name = name;
var namespaces = full_name.split('.');
var base_name = namespaces[namespaces.length - 1];
var underscore_name = full_name.replace(/\./g, '_');
var name_upper = underscore_name.toUpperCase();
var windows_name = full_name.to_windows_name();

var parent_name = "Titanium::Module";
if (parent.indexOf('[mscorlib]') != 0) {
	parent_name = parent.trim();
}

-%>
/**
 * Windows Native Wrapper for <%= full_name %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "<%= full_name %>.hpp"
 // TODO Include the headers for all the native types we use in here! We'll have to go through type of every method arg, return type, type of every property

<% for (var i = 0; i < namespaces.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= namespaces[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>

		<%= base_name %>::<%= base_name %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: <%= parent_name.to_windows_name() %>(js_context, arguments)
		{
		}

		void <%= base_name %>::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
			wrapped__ = ref new <%= windows_name %>();
		}

		<%= windows_name %>^ <%= base_name %>::unwrap<%= underscore_name %>()
		{
			return dynamic_cast<<%= windows_name %>^>(wrapped__); // downcast/sidecast. I think dynamic_cast is right here...
		}

		void <%= base_name %>::wrap(<%= windows_name %>^ object)
		{
			wrapped__ = object; // upcast/assign, should be ok without casting
		}

		void <%= base_name %>::JSExportInitialize()
		{
			JSExport<<%= base_name %>>::SetClassVersion(1);
			JSExport<<%= base_name %>>::SetParent(JSExport<<%= parent_name.to_windows_name() %>>::Class());

<%
// properties
for (property_name in properties) {
	if (properties[property_name]['setter']) {
-%>
			TITANIUM_ADD_PROPERTY(<%= base_name %>, <%= property_name %>);
<%
	} else {
-%>
			TITANIUM_ADD_PROPERTY_READONLY(<%= base_name %>, <%= property_name %>);
<%	}
}
// Methods
if (methods) {
	for (var i = 0; i < methods.length; i++) {
		var method = methods[i];
		// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
		if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
			method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0 ||
			method.name == ".ctor") {
				continue;
		}
-%>
			TITANIUM_ADD_FUNCTION(<%= base_name %>, <%= method.name %>);
<%
	}
}
-%>
		}

<%
for (property_name in properties) {
	if (properties[property_name]['setter']) { -%>
<%- include('setter.cpp', {base_name: base_name}) %>
<%  
	} -%>
<%- include('getter.cpp', {base_name: base_name}) %>
<% 
} // End Properties
// Methods
if (methods) {
	for (var i = 0; i < methods.length; i++) {
		var method = methods[i];
		// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
		if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
			method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0 ||
			method.name == '.ctor') {
				continue;
		}
		// TODO handle overloads with same method name! We need to group methods by name and then use one bridge function per unique name and have it delegate to right native method based on arg count!
-%>
<%- include('function.cpp', {base_name: base_name, method: method}) %>
<%
	}
}

for (var i = namespaces.length - 2; i>= 0; i--) {
-%>
<%= Array(i + 1).join('\t') %>} // namespace <%= namespaces[i] %>
<% 
}
-%>
