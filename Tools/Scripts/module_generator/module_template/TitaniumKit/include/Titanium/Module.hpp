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
 * TitaniumKit <%= module %>
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_<%= name_upper %>_HPP_
#define _TITANIUM_<%= name_upper %>_HPP_

#include "Titanium/<%= module_classes.contains('UI') ? 'UI/View' : 'Module' %>.hpp"

<% for (var i = 0; i < module_classes.length - 1; i++) { -%>
<%= Array(i + 1).join('\t') %>namespace <%= module_classes[i] %>
<%= Array(i + 1).join('\t') %>{
<% } -%>
<%= indent %>using namespace HAL;

<%= indent %>/*!
<%= indent %>  @class
<%= indent %>  @discussion This is the Titanium <%= name %> Module.
<%= indent %>  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.<%= full_namespace.replace(/::/g,'.') %>
<%= indent %>*/
<%= indent %>class TITANIUMKIT_EXPORT <%= namespace %> : public <%= module_classes.contains('UI') ? 'View' : 'Module' %>, public JSExport<<%= namespace %>>
<%= indent %>{

<%= indent %>public:
<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.__inherits != module) {
		continue;
	}
-%>

<%= Array(module_classes.length+1).join('\t') %>/*!
<%= Array(module_classes.length+1).join('\t') %>  @property
<%= Array(module_classes.length+1).join('\t') %>  @abstract <%= property.name %>
<%= Array(module_classes.length+1).join('\t') %>  @discussion <%= property.summary.replace(/\n/g,'') %>
<%= Array(module_classes.length+1).join('\t') %>*/
<%
	if (property.type == 'Number' && property.permission && property.permission == 'read-only') {
		property.isJS = true;
-%>
			virtual JSValue <%= property.name %>() const TITANIUM_NOEXCEPT final;
<% 	} else if (property.permission && property.permission == 'read-only') { -%>
<%= Array(module_classes.length+1).join('\t') %>TITANIUM_PROPERTY_IMPL_READONLY_DEF(<%= getType(property.type) %>, <%= property.name %>);
<% 	} else { -%>
<%= Array(module_classes.length+1).join('\t') %>TITANIUM_PROPERTY_IMPL_DEF(<%= getType(property.type) %>, <%= property.name %>);
<%
	}
}

for (i in data.methods) {
	var method = data.methods[i];
	if (method.__accessor == true || method.__inherits != module) {
		continue;
	}

	var parameters = ('parameters' in method ? getParameters(method.parameters) : '');
	var type = ('returns' in method ? method.returns[0].type : 'void');
-%>

<%= Array(module_classes.length+1).join('\t') %>/*!
<%= Array(module_classes.length+1).join('\t') %>  @method
<%= Array(module_classes.length+1).join('\t') %>  @abstract <%= method.name %>
<%= Array(module_classes.length+1).join('\t') %>  @discussion <%= method.summary.replace(/\n/g,'') %>
<%= Array(module_classes.length+1).join('\t') %>*/
<%= Array(module_classes.length+1).join('\t') %>virtual <%= getType(type) %> <%= method.name -%>(<%= parameters %>) TITANIUM_NOEXCEPT;
<%
}
-%>

			<%= namespace %>(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;
			virtual ~<%= namespace %>()<%= Array(namespace.length).join(' ') %>           = default;
			<%= namespace %>(const <%= namespace %>&)            = default;
			<%= namespace %>& operator=(const <%= namespace %>&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			<%= namespace %>(<%= namespace %>&&)                 = default;
			<%= namespace %>& operator=(<%= namespace %>&&)      = default;
#endif

			static void JSExportInitialize();

<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.isJS || property.__inherits != module) {
		continue;
	}

	if (property.permission && property.permission == 'read-only') {
-%>
<%= Array(module_classes.length+1).join('\t') %>TITANIUM_PROPERTY_READONLY_DEF(<%= property.name %>);
<%	} else { -%>
<%= Array(module_classes.length+1).join('\t') %>TITANIUM_PROPERTY_DEF(<%= property.name %>);
<%
	}
}
-%>

<%
for (i in data.methods) {
	var method = data.methods[i];
	if (method.__inherits != module) {
		continue;
	}
-%>
<%= Array(module_classes.length+1).join('\t') %>TITANIUM_FUNCTION_DEF(<%= method.name %>);
<%
}
-%>

<% if (data.properties.length > 0) { -%>
<%= indent %>protected:
#pragma warning(push)
#pragma warning(disable : 4251)
<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.isJS || property.__inherits != module) {
		continue;
	}
-%>
<%= indent %>	<%= getType(property.type) %> <%= property.name %>__;
<%
}
-%>
#pragma warning(pop)
<% } -%>
		};

<% for (var i = module_classes.length - 2; i>= 0; i--) { -%>
<%= Array(i + 1).join('\t') %>} // namespace <%= module_classes[i] %>
<% } -%>
#endif // _TITANIUM_<%= name_upper %>_HPP_
