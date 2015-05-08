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

var indent = Array(module_classes.length).join('\t');
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
#include "TitaniumWindows/Utility.hpp"

namespace TitaniumWindows
{
<% for (var i=1;i<module_classes.length-1;i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= module_classes[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>
<%= indent %><%= namespace %>::<%= namespace %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
<%= indent %>	: Titanium::<%= full_namespace %>(js_context, arguments)
<%= indent %>{
<%= indent %>	TITANIUM_LOG_DEBUG("<%= name %>::ctor Initialize");
<%= indent %>}

<%= indent %>void <%= namespace %>::JSExportInitialize() {
<%= indent %>	JSExport<<%= namespace %>>::SetClassVersion(1);
<%= indent %>	JSExport<<%= namespace %>>::SetParent(JSExport<Titanium::<%= full_namespace %>>::Class());
<%= indent %>}

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module && (property.platforms.contains('android') && property.platforms.contains('iphone'))) {-%>
<% if (!property.__permission || property.__permission != "read-only") {-%>
<%= indent %>void <%= namespace %>::set_<%= property.name %>(<%= getType(property.type, true) %> <%= property.name %>) TITANIUM_NOEXCEPT
<%= indent %>{
<%= indent %>	TITANIUM_LOG_WARN("<%= namespace %>::set_<%= property.name %>: Unimplemented");
<%= indent %>}

<% } -%>
<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__accessor != true && method.__inherits == module && (method.platforms.contains('android') && method.platforms.contains('iphone'))) {-%>
<% var parameters = ('parameters' in method ? getParameters(method.parameters) : '') -%>
<% var type = ('returns' in method ? method.returns[0].type : 'void') -%>
<%= indent %><%= getType(type) %> <%= namespace %>::<%= method.name %>(<%= parameters %>) TITANIUM_NOEXCEPT
<%= indent %>{
<%= indent %>	TITANIUM_LOG_WARN("<%= name %>.<%= method.name %> is not implemented yet");
<% if (type == 'String') { -%>
<%= indent %>	return "";
<% } else if (type == 'Boolean') { -%>
<%= indent %>	return false;
<% } else if (type == 'Number') { -%>
<%= indent %>	return 0;
<% } else if (type == 'void') { -%>
<% } else { -%>
<%= indent %>	return get_context().CreateUndefined();
<% } -%>
<%= indent %>}

<% } -%>
<% } -%>
<% for (var i = module_classes.length - 2; i >= 1; i--) { -%>
<%= Array(i + 1).join('\t') %>}  // namespace <%= module_classes[i] %>
<% } -%>
}  // namespace TitaniumWindows
