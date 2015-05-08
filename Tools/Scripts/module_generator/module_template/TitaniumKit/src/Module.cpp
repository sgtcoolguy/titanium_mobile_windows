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
<%
var valid_properties = 0;
for (i in data.properties) {
	var property = data.properties[i];
	if (property.__inherits == module) {
		valid_properties++;
	}
}
-%>

<%= Array(module_classes.length).join('\t') %><%= namespace %>::<%= namespace %>(const JSContext& js_context, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
<%= Array(module_classes.length).join('\t') %>	: <%= module_classes.contains('UI') ? 'View(js_context)' : 'Module(js_context, arguments)' %><%= (valid_properties > 0 ? ',' : '') %>
<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.__inherits != module) {
		continue;
	}
	
	if (property.type == 'String') { -%>
<%= Array(module_classes.length).join('\t') %>	<%= property.name %>__(<%= ('default' in property ? property.default : "\"\"") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } else if (property.type == 'Boolean') { -%>
<%= Array(module_classes.length).join('\t') %>	<%= property.name %>__(<%= ('default' in property ? property.default : "false") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } else if (property.type == 'Number') { -%>
<%= Array(module_classes.length).join('\t') %>	<%= property.name %>__(<%= ('default' in property && !isNaN(property.default) ? property.default : "0") %>)<%= (valid_properties > 1 ? ',' : '') %>
<% } else { -%>
<%= Array(module_classes.length).join('\t') %>	<%= property.name %>__(get_context().CreateUndefined())<%= (valid_properties > 1 ? ',' : '') %>
<%
 	}
	valid_properties--;
}
-%>
		{
		}

<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.__inherits != module) {
		continue;
	}
	
	if (property.type == 'Number' && property.permission && property.permission == 'read-only') {
		property.type = 'JSValue';
-%>
		JSValue <%= namespace %>::<%= property.name %>() const TITANIUM_NOEXCEPT
		{
			return <%= property.name %>__;
		}
<%
	} else if (property.permission && property.permission == 'read-only') {
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_PROPERTY_READ(<%= namespace %>, <%= getType(property.type) %>, <%= property.name %>)
<%
	} else {
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_PROPERTY_READWRITE(<%= namespace %>, <%= getType(property.type) %>, <%= property.name %>)
<% } -%>
<% } -%>

<%

for (i in data.methods) {
	var method = data.methods[i];
	if (method.__accessor == true || method.__inherits != module) {
		continue;
	}
	
	var parameters = ('parameters' in method ? getParameters(method.parameters) : '');
	var type = ('returns' in method ? method.returns[0].type : 'void');
-%>
<%= Array(module_classes.length).join('\t') %><%= getType(type) %> <%= namespace %>::<%= method.name %>(<%= parameters %>) TITANIUM_NOEXCEPT
<%= Array(module_classes.length).join('\t') %>{
<%= Array(module_classes.length).join('\t') %>	TITANIUM_LOG_WARN("<%= namespace %>::<%= method.name %>: Unimplemented");
<% 	if (type == 'String') { -%>
<%= Array(module_classes.length).join('\t') %>	return "";
<% 	} else if (type == 'Boolean') { -%>
<%= Array(module_classes.length).join('\t') %>	return false;
<% 	} else if (type == 'Number') { -%>
<%= Array(module_classes.length).join('\t') %>	return 0;
<% 	} else if (type == 'void') { -%>
<% 	} else { -%>
<%= Array(module_classes.length).join('\t') %>	return get_context().CreateUndefined();
<% 	} -%>
		}

<%
}
-%>
<%= Array(module_classes.length).join('\t') %>void <%= namespace %>::JSExportInitialize() {
<%= Array(module_classes.length).join('\t') %>	JSExport<<%= namespace %>>::SetClassVersion(1);
<%= Array(module_classes.length).join('\t') %>	JSExport<<%= namespace %>>::SetParent(JSExport<Module>::Class());

<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.__inherits != module) {
		continue;
	}
	
	if (property.permission && property.permission == 'read-only') {
-%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ADD_PROPERTY_READONLY(<%= namespace %>, <%= property.name %>);
<%	} else { -%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ADD_PROPERTY(<%= namespace %>, <%= property.name %>);
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
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ADD_FUNCTION(<%= namespace %>, <%= method.name %>);
<%
}
-%>
		}

<%
for (i in data.properties) {
	var property = data.properties[i];
	if (property.type == 'JSValue' || property.__inherits != module) {
		continue;
	}
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_PROPERTY_GETTER(<%= namespace %>, <%= property.name %>)
<%= Array(module_classes.length).join('\t') %>{
<% 	if (property.type == 'String' || property.type == 'Boolean' || property.type == 'Number') { -%>
<%= Array(module_classes.length).join('\t') %>	return get_context().Create<%= property.type %>(get_<%= property.name %>());
<% 	} else { -%>
<%= Array(module_classes.length).join('\t') %>	return <%= property.name %>__;
<% 	} -%>
<%= Array(module_classes.length).join('\t') %>}

<%
	// if read-only, no setter so skip to next property.
	if (property.__permission && property.__permission == "read-only") {
		continue;
	}
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_PROPERTY_SETTER(<%= namespace %>, <%= property.name %>)
<%= Array(module_classes.length).join('\t') %>{
<% 	if (property.type == 'String') { -%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ASSERT(argument.IsString());
<%= Array(module_classes.length).join('\t') %>	set_<%= property.name %>(static_cast<std::string>(argument));
<% 	} else if (property.type == 'Number') { -%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ASSERT(argument.IsNumber());
<%= Array(module_classes.length).join('\t') %>	set_<%= property.name %>(static_cast<double>(argument));
<% 	} else if (property.type == 'Boolean') { -%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ASSERT(argument.IsBoolean());
<%= Array(module_classes.length).join('\t') %>	set_<%= property.name %>(static_cast<bool>(argument));
<% 	} else { -%>
<%= Array(module_classes.length).join('\t') %>	TITANIUM_ASSERT(argument.IsObject());
<%= Array(module_classes.length).join('\t') %>	set_<%= property.name %>(static_cast<JSObject>(argument));
<% 	} -%>
<%= Array(module_classes.length).join('\t') %>	return true;
<%= Array(module_classes.length).join('\t') %>}

<%
}

for (i in data.methods) {
	var method = data.methods[i] ;
	if (method.__inherits != module) { // skip inherited methods
		continue;
	}

	var parameters = ('parameters' in method ? getParameters(method.parameters) : '');
	var type = ('returns' in method ? method.returns[0].type : 'JSValue');
	if (method.__accessor == true) {
		var propName = method.name.charAt(3).toLowerCase() + method.name.slice(4);
		if (method.name.slice(0, 3) == "set") {
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_FUNCTION_AS_SETTER(<%= namespace %>, <%= method.name %>, <%= propName %>)
<%
		} else {
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_FUNCTION_AS_GETTER(<%= namespace %>, <%= method.name %>, <%= propName %>)
<%
		}
	} else {
		// Non-accessor functions
-%>
<%= Array(module_classes.length).join('\t') %>TITANIUM_FUNCTION(<%= namespace %>, <%= method.name %>)
<%= Array(module_classes.length).join('\t') %>{
<%= Array(module_classes.length).join('\t') %>	TITANIUM_LOG_WARN("<%= name %>.<%= method.name %> is not implemented yet");

<%
		if (!method.parameters) {
			// No args, just invoke method
-%>
			// FIXME handle return value!
<%= Array(module_classes.length).join('\t') %>	<%= method.name %>();
<%= Array(module_classes.length).join('\t') %>	return get_context().CreateUndefined();
		}
<%
			continue;
		}

		// Determine how many parameters are required!
		var requiredParameterCount = method.parameters.length;
		for (var x = 0; x < method.parameters.length; x++) {
			if (method.parameters[x].optional) {
				requiredParameterCount--;
			}
		}
			
		if (requiredParameterCount == 1) {
-%>
<%= Array(module_classes.length).join('\t') %>	if (arguments.empty()) {
<% 		} else { -%>
<%= Array(module_classes.length).join('\t') %>	if (arguments.size() < <%= requiredParameterCount %>) {
<% 		} -%>
<%= Array(module_classes.length).join('\t') %>		return get_context().CreateUndefined();
<%= Array(module_classes.length).join('\t') %>	}

<%
		// FIXME In most cases, the params at each index are always the same and it's just a metter of having optional 2nd, 3rd, 4th, etc params.
		// We should assume that and avoid duplicating logic in each arg count varition below!
		var parameters = '';
		for (var x = 0; x < method.parameters.length; x++) {
			var parameter = method.parameters[x];
			parameters += parameter.name;
			if (x < method.parameters.length - 1) {
				parameters += ', ';
			}

			var optional = '';
			if (parameter.optional) {
				optional = 'OPTIONAL_';
			}
			
			if (parameter.type == 'String') {
-%>
			ENSURE_<%= optional %>STRING_AT_INDEX(<%= parameter.name %>, <%= x %>, "");
<% 			} else if (parameter.type == 'Number') { -%>
			ENSURE_<%= optional %>DOUBLE_AT_INDEX(<%= parameter.name %>, <%= x %>, 0);
<% 			} else if (parameter.type == 'Boolean') { -%>
			ENSURE_<%= optional %>BOOL_AT_INDEX(<%= parameter.name %>, <%= x %>, false);
<% 			} else { -%>
			ENSURE_<%= optional %>OBJECT_AT_INDEX(<%= parameter.name %>, <%= x %>,);
<%
			}
		}
-%>
			// TODO handle return value!
<%= Array(module_classes.length).join('\t') %>	<%= method.name %>(<%= parameters %>);
<%= Array(module_classes.length).join('\t') %>	return get_context().CreateUndefined();
<%= Array(module_classes.length).join('\t') %>}
<%
	}
-%>

<%
}

for (var i = module_classes.length - 2; i >= 0; i--) {
-%>
<%= Array(i + 1).join('\t') %>} // namespace <%= module_classes[i] %>
<%
}
-%>
