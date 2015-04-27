<% 
function getType(type, parameter) {
	var r = 'JSValue';
	if (type == 'Number') {
		r = (parameter ? 'const double&' : 'double');
	} else if (type == 'Boolean') {
		r = (parameter ? 'const bool&' : 'bool');
	} else if (type == 'void') {
		r = 'void';
	} else if (type == 'String') {
		r = (parameter ? 'const std::string&' : 'std::string');
	}
	return r;
}
function getParameters(parameters) {
	var r = '';
	for (i in parameters) {
		if (parameters[i].name.length > 0) {
			r += getType(parameters[i].type, true) + ' ' + parameters[i].name;
			if (i < parameters.length-1) {
				r += ', ';
			}
		}
	}
	return r;
}
Array.prototype.contains = function(v){ return this.indexOf(v)>-1; };
-%>
/**
 * TitaniumKit <%= module %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/<%= module_path %>.hpp"

<% for (var i=0;i<module_classes.length-1;i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= module_classes[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>

<% var valid_properties = 0 -%>
<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module) {-%>
<% valid_properties++ -%>
<% } -%>
<% } -%>

		<%= namespace %>::<%= namespace %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
			: Module(js_context, arguments)<%= (valid_properties > 0 ? ',' : '') %>
<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module) {-%>
<% if (property.type == 'String') { -%>
			<%= property.name %>__(<%= ('default' in property ? property.default : "\"\"") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } else if (property.type == 'Boolean') { -%>
			<%= property.name %>__(<%= ('default' in property ? property.default : "false") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } else if (property.type == 'Number') { -%>
			<%= property.name %>__(<%= ('default' in property ? property.default : "0") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } -%>
<% valid_properties-- -%>
<% } -%>
<% } -%>
		{
		}

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module) {-%>
<% if (property.type == 'Number' && property.permission == 'read-only') { -%>
<% property.type = 'JSValue' -%>
		JSValue <%= namespace %>::<%= property.name %>() const TITANIUM_NOEXCEPT
<% } else { -%>
		<%= getType(property.type) %> <%= namespace %>::get_<%= property.name %>() const TITANIUM_NOEXCEPT
<% } -%>
		{
<% if (property.type == 'String') { -%>
			return <%= property.name %>__;
<% } else if (property.type == 'Boolean') { -%>
			return <%= property.name %>__;
<% } else if (property.type == 'Number') { -%>
			return <%= property.name %>__;
<% } else if (property.type == 'JSValue') { -%>
			return get_context().CreateNull();
<% } else { -%>
			const auto script = "";
			return get_context().JSEvaluateScript(script);
<% } -%>
		}

<% if (!property.__permission || property.__permission != "read-only") {-%>
		void <%= namespace %>::set_<%= property.name %>(<%= getType(property.type, true) %> <%= property.name %>) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("<%= namespace %>::set_<%= property.name %>: Unimplemented");
			<%= property.name %>__ = <%= property.name %>;
		}

<% } -%>
<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__accessor != true && method.__inherits == module) {-%>
<% var parameters = ('parameters' in method ? getParameters(method.parameters) : '') -%>
<% var type = ('returns' in method ? method.returns[0].type : 'JSValue') -%>
		<%= getType(type) %> <%= namespace %>::<%= method.name %>(<%= parameters %>) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("<%= namespace %>::<%= method.name %>: Unimplemented");
<% if (type == 'String') { -%>
			return "";
<% } else if (type == 'Boolean') { -%>
			return false;
<% } else if (type == 'Number') { -%>
			return 0;
<% } else { -%>
			return get_context().CreateUndefined();
<% } -%>
		}

<% } -%>
<% } -%>
		void <%= namespace %>::JSExportInitialize() {
			JSExport<<%= namespace %>>::SetClassVersion(1);
			JSExport<<%= namespace %>>::SetParent(JSExport<Module>::Class());

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module) {-%>
			JSExport<<%= namespace %>>::AddValueProperty("<%= property.name %>", std::mem_fn(&<%= namespace %>::<%= (property.type == 'JSValue') ? '' : 'js_' %>get_<%= property.name %>, std::mem_fn(&<%= namespace %>::js_set_<%= property.name %>));
<% } -%>
<% } -%>

<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__inherits == module) {-%>
			JSExport<<%= namespace %>>::AddFunctionProperty("<%= method.name %>", std::mem_fn(&<%= namespace %>::js_<%= method.name %>));
<% } -%>
<% } -%>
		}

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.type != 'JSValue' && property.__inherits == module) {-%>
		JSValue <%= namespace %>::js_get_<%= property.name %>() const TITANIUM_NOEXCEPT
		{
<% if (property.type == 'String') { -%>
			return get_context().CreateString(<%= property.name %>());
<% } else if (property.type == 'Boolean') { -%>
			return get_context().CreateBoolean(<%= property.name %>());
<% } else if (property.type == 'Number') { -%>
			return get_context().CreateNumber(<%= property.name %>());
<% } else { -%>
			return <%= property.name %>();
<% } -%>
		}

<% if (!property.__permission || property.__permission != "read-only") {-%>
		bool <%= namespace %>::js_set_<%= property.name %>(const JSValue& argument) const TITANIUM_NOEXCEPT
		{
<% if (property.type == 'String') { -%>
			TITANIUM_ASSERT(argument.IsString());
			set_<%= property.name %>(static_cast<std::string>(argument));
<% } else if (property.type == 'Number') { -%>
			TITANIUM_ASSERT(argument.IsNumber());
			set_<%= property.name %>(static_cast<double>(argument));
<% } else if (property.type == 'Boolean') { -%>
			TITANIUM_ASSERT(argument.IsBoolean());
			set_<%= property.name %>(static_cast<bool>(argument));
<% } else { -%>
			TITANIUM_ASSERT(argument.IsObject());
			set_<%= property.name %>(static_cast<JSObject>(argument));
<% } -%>
			return true;
		}

<% } -%>
<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__inherits == module) {-%>
<% var parameters = ('parameters' in method ? getParameters(method.parameters) : '') -%>
<% var type = ('returns' in method ? method.returns[0].type : 'JSValue') -%>
<% if (method.__accessor == true) {-%>
		JSValue <%= namespace %>::js_<%= method.name %>(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
<% var propName = method.name.charAt(3).toLowerCase() + method.name.slice(4); -%>
<% if (method.name.slice(0, 3) == "set") {-%>
			TITANIUM_ASSERT(arguments.size() >= 1);
			js_set_<%= propName %>(arguments.at(0));
			return get_context().CreateUndefined();
<% } else { -%>
			return js_get_<%= propName %>();
<% } -%>
		}

<% } else { -%>
		JSValue <%= namespace %>::js_<%= method.name %>(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("<%= name %>.<%= method.name %> is not implemented yet");
<% if ('parameters' in method) { -%>
<% if (method.parameters.length == 1) { -%>
			if (arguments.empty()) {
<% } else { -%>
			if (arguments.size() < <%= method.parameters.length %>) {
<% } -%>
				return get_context().CreateUndefined();
			}
<% for (var p=method.parameters.length;p>0;p--) { var z = p -%>
			else if (arguments.size() >= <%= z %>) {
<% for (var i=0;i<z;i++) { -%>
				const auto _<%= i %> = arguments.at(<%= i %>);
				TITANIUM_ASSERT(_<%= i %>.Is<%= (typeof method.parameters[i].type === 'string' && !method.parameters[i].type.contains('<') ? method.parameters[i].type : 'Object') %>());
<% } -%>
<% var parameters = '' -%>
<% for (var i=0;i<z;i++) { -%>
<% var parameter = method.parameters[i] -%>
<% parameters += parameter.name -%>
<% if (i < z-1) parameters += ', ' -%>
<% if (parameter.type == 'String') { -%>
				const std::string <%= parameter.name %> = static_cast<std::string>(_<%= i %>);
<% } else if (parameter.type == 'Number') { -%>
				const double <%= parameter.name %> = static_cast<double>(_<%= i %>);
<% } else if (parameter.type == 'Boolean') { -%>
				const bool <%= parameter.name %> = static_cast<bool>(_<%= i %>);
<% } else { -%>
				const auto <%= parameter.name %> = static_cast<JSObject>(_<%= i %>);
<% } -%>
<% } -%>
<% if (type == 'String') { -%>
				// return get_context().CreateString(<%= method.name %>(<%= parameters %>));
<% } else if (type == 'Number') { -%>
				// return get_context().CreateNumber(<%= method.name %>(<%= parameters %>));
<% } else if (type == 'Boolean') { -%>
				// return get_context().CreateBoolean(<%= method.name %>(<%= parameters %>));
<% } else if (type == 'JSValue') { -%>
				// <%= method.name %>(<%= parameters %>);
<% } else { -%>
				// return <%= method.name %>(<%= parameters %>);
<% } -%>
			}
<% } -%>
<% } -%>
			return get_context().CreateUndefined();
		}

<% } -%>
<% } -%>
<% } -%>
<% for (var i = module_classes.length - 2; i >= 0; i--) { -%>
<%= Array(i + 1).join('\t') %>} // namespace <%= module_classes[i] %>
<% } -%>
