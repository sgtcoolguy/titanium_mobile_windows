		TITANIUM_FUNCTION(<%= base_name %>, <%= method.name %>)
		{
<%
var arguments = "",
	arg,
	type,
	as_param;

// Build up our arguments!
for (var x = 0; x < method.args.length; x++) {
	arg = method.args[x];
	type = arg.type;
	as_param = arg.name;
	if (arg.inout == "out") {
		as_param = "&" + as_param;
		type = type.substring(0, type.length - 1); // drop & from type we pass along to conversion
	}
	arguments += as_param + ", ";
-%>
			auto _<%= x %> = arguments.at(<%= x %>);
<%- include('js_to_native.cpp', {type: type, metadata: metadata, to_assign: arg.name, argument_name: '_' + x}) %>

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
			auto method_result = unwrap()-><%= method.name %>(<%- arguments %>);

<%- include('native_to_js.cpp', {type: method.returnType, metadata: metadata, to_assign: 'result', argument_name: 'method_result'}) %>
<%
// If we had "out" parameters, we now need to assign the values back to the JS Objects before returning result!

for (var x = 0; x < method.args.length; x++) {
	if (arg.inout == "out") {
		// FIXME This assumes int32, uint32, double. We need to handle other types!
		// I've seen string, Point struct, float32, IMapView<K,V>, Rect struct, TabAlignment, TabLeader, JsonArray
-%>
			_<%= x %> = _<%= x %>.get_context().CreateNumber(<%= arg.name %>);
<%
	}
}
-%>
			return result;
<%
}
-%>
		}
