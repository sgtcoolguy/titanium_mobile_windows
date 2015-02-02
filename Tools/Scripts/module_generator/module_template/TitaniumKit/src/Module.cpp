<% function getType(type, parameter) { -%>
<%     var r = 'JSValue' -%>
<%         if (type == 'Number') { -%>
<%             r = 'double' -%>
<%         } else if (type == 'Boolean') { -%>
<%             r = 'bool' -%>
<%         } else if (type == 'void') { -%>
<%             r = 'void' -%>
<%         } else if (type == 'String') {-%>
<%             r = (parameter ? 'const std::string&' : 'std::string') -%>
<%         } -%>
<%     return r -%>
<% } -%>
<% function getParameters(parameters) { -%>
<%     var r = '' -%>
<%     for (i in parameters) { -%>
<%         if (parameters[i].name.length > 0) { -%>
<%             r += getType(parameters[i].type, true)+' '+parameters[i].name -%>
<%             if (i < parameters.length-1) r += ', ' -%>
<%         } -%>
<%     } -%>
<%     return r -%>
<% } -%>
<% Array.prototype.contains=function(v){return this.indexOf(v)>-1;} -%>
/**
 * <%= module %> for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/<%= module_path %>.hpp"

<% for (var i=0;i<module_classes.length-1;i++) { -%>
namespace <%= module_classes[i] %> {
<% } -%>

    <%= namespace %>::<%= namespace %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
        : Module(js_context, arguments)
    {
    }

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.__inherits == module && (property.platforms.contains('android') && property.platforms.contains('iphone'))) {-%>
<% if (property.type == 'Number' && property.permission == 'read-only') { -%>
<% property.type = 'JSValue' -%>
    JSValue <%= namespace %>::<%= property.name %>() const TITANIUM_NOEXCEPT
<% } else { -%>
    <%= getType(property.type) %> <%= namespace %>::<%= property.name %>() const TITANIUM_NOEXCEPT
<% } -%>
    {
<% if (property.type == 'String') { -%>
        return "";
<% } else if (property.type == 'Boolean') { -%>
        return false;
<% } else if (property.type == 'Number') { -%>
        return 0;
<% } else if (property.type == 'JSValue') { -%>
        return get_context().CreateNull();
<% } else { -%>
        const auto script = "";
        return get_context().JSEvaluateScript(script);
<% } -%>
    }

<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__accessor != true && method.__inherits == module && (method.platforms.contains('android') && method.platforms.contains('iphone'))) {-%>
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
<% if (property.__inherits == module && (property.platforms.contains('android') && property.platforms.contains('iphone'))) {-%>
        JSExport<<%= namespace %>>::AddValueProperty("<%= property.name %>", std::mem_fn(&<%= namespace %>::<%= (property.type == 'JSValue') ? '' : 'js_' %><%= property.name %>));
<% } -%>
<% } -%>

<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__inherits == module && (method.platforms.contains('android') && method.platforms.contains('iphone'))) {-%>
        JSExport<<%= namespace %>>::AddFunctionProperty("<%= method.name %>", std::mem_fn(&<%= namespace %>::js_<%= method.name %>));
<% } -%>
<% } -%>
    }

<% for (i in data.properties) { -%>
<% var property = data.properties[i] -%>
<% if (property.type != 'JSValue' && property.__inherits == module && (property.platforms.contains('android') && property.platforms.contains('iphone'))) {-%>
    JSValue <%= namespace %>::js_<%= property.name %>() const TITANIUM_NOEXCEPT
    {
<% if (property.type == 'String') { -%>
        return get_context().CreateString(<%= property.name %>());
<% } else if (property.type == 'Boolean') { -%>
        return get_context().CreateBoolean(<%= property.name %>());
<% } else if (property.type == 'Number') { -%>
        return get_context().CreateNumber(<%= property.name %>());
<% } else { -%>
        return <%= property.name %>()
<% } -%>
    }

<% } -%>
<% } -%>
<% for (i in data.methods) { -%>
<% var method = data.methods[i] -%>
<% if (method.__inherits == module && (method.platforms.contains('android') && method.platforms.contains('iphone'))) {-%>
<% var parameters = ('parameters' in method ? getParameters(method.parameters) : '') -%>
<% var type = ('returns' in method ? method.returns[0].type : 'JSValue') -%>
    JSValue <%= namespace %>::js_<%= method.name %>(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
    {
        TITANIUM_LOG_WARN("<%= name %>.<%= method.name %> is not implemented yet");
<% if ('parameters' in method) { -%>

        if (arguments.size() < <%= method.parameters.length %>) {
            return get_context().CreateUndefined();
        }
<% for (var i=0;i<method.parameters.length;i++) { -%>
        const auto _<%= i %> = arguments.at(<%= i %>);
<% } -%>

<% for (var i=0;i<method.parameters.length;i++) { -%>
        <%= (typeof method.parameters[i].type === 'string' ? '' : '// ') %>TITANIUM_ASSERT(_<%= i %>.Is<%= method.parameters[i].type %>());
<% } -%>

<% var parameters = '' -%>
<% for (var i=0;i<method.parameters.length;i++) { -%>
<% var parameter = method.parameters[i] -%>
<% parameters += parameter.name -%>
<% if (i < method.parameters.length-1) parameters += ', ' -%>
<% if (parameter.type == 'String') { -%>
        const std::string <%= parameter.name %> = static_cast<std::string>(_<%= i %>);
<% } else if (parameter.type == 'Number') { -%>
        const double <%= parameter.name %> = static_cast<double>(_<%= i %>);
<% } else if (parameter.type == 'Boolean') { -%>
        const bool <%= parameter.name %> = static_cast<bool>(_<%= i %>);
<% } else { -%>
        //const auto <%= parameter.name %> = static_cast<>(_<%= i %>);
<% } -%>
<% } -%>
<% } -%>

        return get_context().CreateUndefined(); // <%= method.name %>(<%= parameters %>);
    }

<% } -%>
<% } -%>
<% for (var i=0;i<module_classes.length-1;i++) { -%>
}
<% } -%>
