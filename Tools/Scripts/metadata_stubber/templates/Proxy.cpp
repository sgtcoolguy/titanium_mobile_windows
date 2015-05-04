<%
String.prototype.to_windows_name = function() {
	return this.replace(/\./g, '::');
};

var full_name = name;
var namespaces = ['Titanium'];
namespaces = namespaces.concat(full_name.split('.'));
var base_name = namespaces[namespaces.length - 1];
var underscore_name = full_name.replace(/\./g, '_');
var name_upper = underscore_name.toUpperCase();
var windows_name = full_name.to_windows_name();
var has_constructor = false;

var parent_name = "Titanium::Platform::Object";
if (parent && parent.indexOf('[mscorlib]') != 0) {
	parent_name = parent.trim();
}

// gather all the types referenced in this file!
var types_to_include = [full_name],
	prop,
	method,
	type;

// check property types
for (property_name in properties) {
	prop = properties[property_name];
	type = prop['returnType'];
	if (type.indexOf('class ') == 0 || type.indexOf('Windows') == 0) {
		type = type.trim();
		if (type.indexOf('class ') == 0) {
			type = type.substring(6);
		}
		if (types_to_include.indexOf(type) == -1) {
			types_to_include.unshift(type);
		}
	}
}
// Check method args and return types!
if (methods) {
	for (var i = 0; i < methods.length; i++) {
		method = methods[i];
		// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
		if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
			method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0) {
				continue;
		}
		if (method.name == '.ctor') {
			has_constructor = true;
			continue;
		}
		// Skip non-public methods
		if (method.attributes.indexOf("public") == -1) {
			continue;
		}

		// return type
		type = method.returnType;
		if (type.indexOf('class ') == 0 || type.indexOf('Windows.') == 0) {
			// it's a type/class, we need to include it!
			type = type.trim();
			if (type.indexOf('class ') == 0) {
				type = type.substring(6);
			}
			if (types_to_include.indexOf(type) == -1) {
				types_to_include.unshift(type);
			}
		}
		// Check method args!
		for (var j = 0; j < method.args.length; j++) {
			type = method.args[j].type;
			if (type.indexOf('class ') == 0 || type.indexOf('Windows.') == 0) {
				// it's a type/class, we need to include it!
				type = type.trim();
				if (type.indexOf('class ') == 0) {
					type = type.substring(6);
				}
				if (types_to_include.indexOf(type) == -1) {
					types_to_include.unshift(type);
				}
			}
		}
	}
}
-%>
/**
 * Windows Native Wrapper for <%= full_name %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

<%
for (var i = 0; i < types_to_include.length; i++) {
	var type_name = types_to_include[i];
-%>
#include "<%= type_name %>.hpp"
<%
}
-%>

<% for (var i = 0; i < namespaces.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= namespaces[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>

		<%= base_name %>::<%= base_name %>(const JSContext& js_context) TITANIUM_NOEXCEPT
			: <%= parent_name.to_windows_name() %>(js_context)
		{
		}

		void <%= base_name %>::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			// TODO Handle passing along args to the constructor. Not all items have default constructor!
<%
if (has_constructor) {
-%>
			wrapped__ = ref new ::<%= windows_name %>();
<%
}
-%>
		}

		::<%= windows_name %>^ <%= base_name %>::unwrap<%= underscore_name %>() const
		{
			return dynamic_cast<::<%= windows_name %>^>(wrapped__);
		}

		::<%= windows_name %>^ <%= base_name %>::unwrap() const
		{
			return unwrap<%= underscore_name %>();
		}

		void <%= base_name %>::wrap(::<%= windows_name %>^ object)
		{
			wrapped__ = object;
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
		// Skip non-public methods
		if (method.attributes.indexOf("public") == -1) {
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
		// Skip non-public methods
		if (method.attributes.indexOf("public") == -1) {
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
