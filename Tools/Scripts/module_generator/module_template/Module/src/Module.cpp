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
 * <%= module %> for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/<%= module_path %>.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows
{
<% for (var i=1;i<module_classes.length-1;i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= module_classes[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>
<%= Array(module_classes.length).join('\t') %><%= namespace %>::<%= namespace %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
<%= Array(module_classes.length).join('\t') %>	: Titanium::<%= full_namespace %>(js_context, arguments)
<%= Array(module_classes.length).join('\t') %>{
<%= Array(module_classes.length).join('\t') %>	TITANIUM_LOG_DEBUG("<%= name %>::ctor Initialize");
<%= Array(module_classes.length).join('\t') %>}

<%= Array(module_classes.length).join('\t') %>void <%= namespace %>::JSExportInitialize() {
<%= Array(module_classes.length).join('\t') %>	JSExport<<%= namespace %>>::SetClassVersion(1);
<%= Array(module_classes.length).join('\t') %>	JSExport<<%= namespace %>>::SetParent(JSExport<Titanium::<%= full_namespace %>>::Class());
<%= Array(module_classes.length).join('\t') %>}

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module && (property.platforms.contains('android') && property.platforms.contains('iphone'))) {-%>
<% if (!property.__permission || property.__permission != "read-only") {-%>
<%= Array(module_classes.length).join('\t') %>void <%= namespace %>::set_<%= property.name %>(<%= getType(property.type, true) %> <%= property.name %>) TITANIUM_NOEXCEPT
<%= Array(module_classes.length).join('\t') %>{
<%= Array(module_classes.length).join('\t') %>	TITANIUM_LOG_WARN("<%= namespace %>::set_<%= property.name %>: Unimplemented");
<%= Array(module_classes.length).join('\t') %>}

<% } -%>
<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__accessor != true && method.__inherits == module && (method.platforms.contains('android') && method.platforms.contains('iphone'))) {-%>
<% var parameters = ('parameters' in method ? getParameters(method.parameters) : '') -%>
<% var type = ('returns' in method ? method.returns[0].type : 'void') -%>
<%= Array(module_classes.length).join('\t') %><%= getType(type) %> <%= namespace %>::<%= method.name %>(<%= parameters %>) TITANIUM_NOEXCEPT
<%= Array(module_classes.length).join('\t') %>{
<%= Array(module_classes.length).join('\t') %>	TITANIUM_LOG_WARN("<%= name %>.<%= method.name %> is not implemented yet");
<% if (type == 'String') { -%>
<%= Array(module_classes.length).join('\t') %>	return "";
<% } else if (type == 'Boolean') { -%>
<%= Array(module_classes.length).join('\t') %>	return false;
<% } else if (type == 'Number') { -%>
<%= Array(module_classes.length).join('\t') %>	return 0;
<% } else if (type == 'void') { -%>
<% } else { -%>
<%= Array(module_classes.length).join('\t') %>	return get_context().CreateUndefined();
<% } -%>
<%= Array(module_classes.length).join('\t') %>}

<% } -%>
<% } -%>
<% for (var i = module_classes.length - 2; i >= 1; i--) { -%>
<%= Array(i + 1).join('\t') %>}  // namespace <%= module_classes[i] %>
<% } -%>
}  // namespace TitaniumWindows
