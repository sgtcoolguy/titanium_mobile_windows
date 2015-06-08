		TITANIUM_FUNCTION(<%= base_name %>, <%= methods[0].name %>)
		{
			auto context = this_object.get_context();
			// TODO Handle no args, just return undefined?
			ENSURE_OBJECT_AT_INDEX(callback, 0);
<%
// TODO We need to assert that there is one argument, that it's an object and a function. It's our callback
// TODO We then need to hook an event handler like so:

var event_name = methods[0].name.substring(4), // drop "add_"
	handler_type_name = methods[0].args[0].type,
	handler_type,
	invoke_method,
	parameters = ""; // Build up the list of paremeters that the handler needs!
if (handler_type_name.indexOf('class ') == 0) {
	handler_type_name = handler_type_name.substring(6); // strip off leading 'class '
}
// handle special common handler types:
if (handler_type_name.indexOf("Windows.Foundation.EventHandler`1") == 0) {
	var inner = handler_type_name.substring(34, handler_type_name.length - 1); // grab inner type
	if (inner == 'object') {
		inner = 'Platform.Object';
	}
	if (inner.indexOf("class ") == 0) {
		inner = inner.substring(6); // drop off "class "
	}
	handler_type_name = "Windows.Foundation.EventHandler<::";
	handler_type_name += inner;
	handler_type_name += "^>";

	parameters = "::Platform::Object^ sender, ::" + inner.replace(/\./g, '::') + "^ args";
} else if (handler_type_name.indexOf("Windows.Foundation.TypedEventHandler`2") == 0) {
	var inner = handler_type_name.substring(handler_type_name.indexOf('`2<') + 3, handler_type_name.length - 1),
		sender = inner.substring(0, inner.indexOf(',')),
		result = inner.substring(inner.indexOf(',') + 1);
	if (sender.indexOf("class ") == 0) {
		sender = sender.substring(6); // drop off "class "
	}
	if (result.indexOf("class ") == 0) {
		result = result.substring(6); // drop off "class "
	}
	handler_type_name = "Windows.Foundation.TypedEventHandler<::";
	handler_type_name += sender;
	handler_type_name += "^, ::";
	handler_type_name += result;
	handler_type_name += "^>";

	parameters = "::" + sender.replace(/\./g, '::') + "^ sender, ::" + result.replace(/\./g, '::') + "^ result";
} else {
	// Dedicated event handler delegate type
	handler_type = metadata[handler_type_name]; // grab handler type from metadata

	// Find the Invoke method in handler_type.methods!
	// FIXME Use nicer JS to find it!
	for (var i = 0; i < handler_type.methods.length; i++) {
		var method = handler_type.methods[i];
		if (method.name == "Invoke") {
			invoke_method = method;
			break;
		}
	}

	// loop through the arguments and turn them into parameters
	for (var x = 0; x < invoke_method.args.length; x++) {
		var arg = invoke_method.args[x],
			arg_type = arg.type;
		// Normalize type name FIXME We have code like this all over the place!
		if (arg_type == 'object') {
			arg_type = "Platform.Object";
		}
		if (arg_type.indexOf("class ") == 0) {
			arg_type = arg_type.substring(6); // drop off "class "
		}
		// FIXME What if arg_type starts with 'valuetype '?
		parameters += "::" + arg_type.replace(/\./g, '::') + "^ " + arg.name + ", ";
	}
	if (parameters.length > 0) {
		parameters = parameters.substring(0, parameters.length - 2); // Drop trailing ", "
	}

}
-%>
			auto method_result = unwrap()-><%= event_name %> += ref new ::<%- handler_type_name.replace(/\./g, '::') %>([context, &callback](<%- parameters %>) {
				// TODO Convert the args and pass them to callback!
				// Takes a const std::vector<JSValue>&  arguments
				callback(context.get_global_object());
			});
			<%- include('native_to_js.cpp', {type: methods[0].returnType, metadata: metadata, to_assign: 'result', argument_name: 'method_result'}) -%>
			return result; 
		}
