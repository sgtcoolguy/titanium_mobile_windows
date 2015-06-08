		TITANIUM_FUNCTION(<%= base_name %>, <%= methods[0].name %>)
		{
			auto context = get_context();
<%
var event_name = methods[0].name.substring(7), // drop "remove_"
	type = methods[0].args[0].type;
-%>
			auto _0 = arguments.at(0); // Should be a JSObject representing an EventRegistrationToken
			<%- include('js_to_native.cpp', {type: type, metadata: metadata, to_assign: 'token', argument_name: '_0'}) -%>
			unwrap()-><%= event_name %> -= token;
			return context.CreateUndefined(); 
		}
