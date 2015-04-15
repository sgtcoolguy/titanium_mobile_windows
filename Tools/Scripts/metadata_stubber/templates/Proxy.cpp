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

#include "Titanium/<%= full_name %>.hpp"

<% for (var i = 0; i < namespaces.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= namespaces[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>

		<%= base_name %>::<%= base_name %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments)
		{
		}

		void <%= base_name %>::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments)
		{	
			wrapped__ = ref new <%= windows_name %>();
		}

		<%= windows_name %>^ <%= base_name %>::unwrap()
		{
			return wrapped__;
		}

		void <%= base_name %>::wrap(<%= windows_name %>^ object)
		{
			wrapped__ = object;
		}

		void <%= base_name %>::JSExportInitialize()
		{
			JSExport<<%= base_name %>>::SetClassVersion(1);
			JSExport<<%= base_name %>>::SetParent(JSExport<Module>::Class());

<% for (property_name in properties) {
	   if (properties[property_name]['setter']) { -%>
			TITANIUM_ADD_PROPERTY(<%= base_name %>, <%= property_name %>);
	<% } else { -%>
			TITANIUM_ADD_PROPERTY_READONLY(<%= base_name %>, <%= property_name %>);
<%     }
   } -%>
<% for (var i = 0; i < methods.length; i++) {
	var method = methods[i];
	// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
	if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
		method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0) {
			continue;
	} -%>
			TITANIUM_ADD_FUNCTION(<%= base_name %>, <%= method.name %>);
<% } -%>
		}

<% for (property_name in properties) {
	if (properties[property_name]['setter']) { -%>
		TITANIUM_PROPERTY_SETTER(<%= base_name %>, <%= property_name %>)
		{
<%
var type = properties[property_name]['returnType'];
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') { -%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
<% } else if (type == 'int32') { -%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument);
<% } else if (type == 'uint32') { -%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<uint32>(argument);
<% } else if (type == 'double' || type == 'float32') { -%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
<% } else if (type == 'string') { -%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
<% } else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	var other_type = metadata[real_type_name];
	var is_enum = (other_type.extends == '[mscorlib]System.Enum');
	var is_struct = (other_type.extends == '[mscorlib]System.ValueType');
	var windows_type_name = real_type_name.replace(/\./g, '::');

	if (is_struct) { -%>
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new <%= windows_type_name %>(); // FIXME We need to look at the fields to know how many, and order of args to pass in!
<%	} else if (is_enum) { -%>
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32>(argument); // TODO Look up enum in metadata to know what type it's value is? 
<%	}-%>
<% } else {
		//	It's a class. Assume we have a JSObject wrapping a native impl
		var full_type_name = type.trim().replace(/\./g, '::');
		if (full_type_name.indexOf('class ') == 0) {
			full_type_name = full_type_name.substring(6);
		}
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<<%= full_type_name %>>();
			// FIXME What if wrapper is nullptr? We need to figure out how to translate the arg into a native object!
			// TODO Now get the wrapper's underlying native object, it's wrapped__ field...
			auto value = wrapper->unwrap();
<% } -%>
			wrapped__-><%= property_name %> = value;
			return true;
		}
<%  } -%>
		TITANIUM_PROPERTY_GETTER(<%= base_name %>, <%= property_name %>)
		{
			auto value = wrapped__-><%= property_name %>;
			auto context = get_context();
<%
var type = properties[property_name]['returnType'];
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') { -%> 
			return context.CreateBoolean(value); 
<% } else if (type == 'int32' || type == 'uint32' || type == 'double') { -%> 
			return context.CreateNumber(value);
<% } else if (type == 'string') { -%> 
			return context.CreateString(value);
<% } else if (type == 'float32') { -%>
			// TODO Do we need to cast this to a double?
			return context.CreateNumber(value);
<% } else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	var other_type = metadata[real_type_name];
	var is_enum = (other_type.extends == '[mscorlib]System.Enum');
	var is_struct = (other_type.extends == '[mscorlib]System.ValueType');

	if (is_struct) { -%>
			auto result = context.CreateObject();
<%		for (field_name in other_type.fields) {
			var field_type = other_type.fields[field_name].type;
			if (field_type == 'int64' || field_type == 'float32') { -%>
			result.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<double>(value.<%= field_name %>)));
<%			} else { -%>
			// FIXME This assumes every other type used is either double, int32 or uint32!
			result.SetProperty("<%= field_name %>", context.CreateNumber(value.<%= field_name %>));
<%			}
		} -%>
			return result; 
<%	} else if (is_enum) { -%>
			return context.CreateNumber(value);
<%	}
} else {
	//	It's a class. Assume we have a JSObject wrapping a native impl
	var full_type_name = type.trim().replace(/\./g, '::');
	if (full_type_name.indexOf('class ') == 0) {
		full_type_name = full_type_name.substring(6);
	} -%>
			// FIXME How do we wrap a class/type? We already have an instance of the wrapped object, we need to instantiate the native JS wrapper like this one, and then somehow shim
			// the already created wrapped object inside it!
			auto object = context.CreateObject(JSExport<<%= full_type_name %>>::Class());
			object.wrap(value);
			return object;
<% } -%>
		}
<% } -%>

<% for (var i = 0; i < methods.length; i++) {
	var method = methods[i];
	// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
	if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
		method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0) {
			continue;
	} -%>
		TITANIUM_FUNCTION(<%= base_name %>, <%= method.name %>)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
		<% if (method.returnType == 'void') { -%>
			wrapped__-><%= method.name %>();
			return get_context().CreateUndefined(); 
		<% } else { -%>
			// otherwise we need to map return type to equivalent JS type!
			auto result = wrapped__-><%= method.name %>();
			return get_context().CreateBoolean(result); 
		<% } -%>
		}
<% } -%>

<% for (var i = namespaces.length - 2; i>= 0; i--) { -%>
<%= Array(i + 1).join('\t') %>} // namespace <%= namespaces[i] %>
<% } -%>

