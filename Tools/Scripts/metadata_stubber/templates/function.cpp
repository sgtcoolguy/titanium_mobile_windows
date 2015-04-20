		TITANIUM_FUNCTION(<%= base_name %>, <%= method.name %>)
		{
<%
var arguments = "",
	arg,
	type;

// Build up our arguments!
for (var x = 0; x < method.args.length; x++) {
	arg = method.args[x];
	type = arg.type;
	arguments += arg.name + ", ";
	// FIXME Handle "out" arguments where you pass in a reference to a type as an arg and that type gets modified. See TryTransform
-%>
			auto _<%= x %> = arguments.at(<%= x %>);
<%- include('js_to_native.cpp', {type: arg.type, metadata: metadata, to_assign: arg.name, argument_name: '_' + x}) %>

<%
}

// Chop off trailing ", "
if (method.args.length > 0) {
	arguments = arguments.substring(0, arguments.length - 2);
}

// Now invoke the method and return the result!
if (method.returnType == 'void') {
-%>
			unwrap()-><%= method.name %>(<%= arguments %>);
			return get_context().CreateUndefined(); 
<%
} else {
-%>
			auto context = get_context();
			auto method_result = unwrap()-><%= method.name %>(<%= arguments %>);

<%- include('native_to_js.cpp', {type: method.returnType, metadata: metadata, to_assign: 'result', argument_name: 'method_result'}) %>

			return result; 
<%
}
-%>
		}
