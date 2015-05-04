<%
// TODO int64, uint64, single, char16
if (type == 'bool') {
-%> 
			auto <%= to_assign %> = context.CreateBoolean(<%= argument_name %>); 
<%
} else if (type == 'int32' || type == 'uint32' || type == 'double') {
-%> 
			auto <%= to_assign %> = context.CreateNumber(<%= argument_name %>);
<%
} else if (type == 'uint16' || type == 'uint8') {
-%>
			auto <%= to_assign %> = context.CreateNumber(static_cast<uint32_t>(<%= argument_name %>));
<%
} else if (type == 'int16' || type == 'int') {
-%>
			auto <%= to_assign %> = context.CreateNumber(static_cast<int32_t>(<%= argument_name %>));
<%
} else if (type == 'string') {
-%> 
			auto <%= to_assign %> = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(<%= argument_name %>));
<%
} else if (type == 'float32' || type == 'float64' || type == 'int64') {
-%>
			auto <%= to_assign %> = context.CreateNumber(static_cast<double>(<%= argument_name %>));
<%
} else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	var other_type = metadata[real_type_name];
	if (!other_type) {
		console.log("No metadata found for: " + real_type_name); // useful to know what type we need to pull into our stripped down metadata
	}
	var is_enum = (other_type.extends == '[mscorlib]System.Enum');
	var is_struct = (other_type.extends == '[mscorlib]System.ValueType');

	if (is_struct) {
-%>
			auto <%= to_assign %> = context.CreateObject();<%
		for (field_name in other_type.fields) {
-%>
<%- include('native_to_js.cpp', {type: other_type.fields[field_name].type, metadata: metadata, to_assign: field_name + '_', argument_name: argument_name + '.' + field_name }) -%>			<%= to_assign %>.SetProperty("<%= field_name %>", <%= field_name %>_);
<%
		}
	} else if (is_enum) {
-%>
			auto <%= to_assign %> = context.CreateNumber(static_cast<int32_t>(static_cast<int>(<%= argument_name %>))); // FIXME What if the enum isn't an int based one?!
<%
	} else {
		// Has to be struct or enum or we have an issue!
		console.log("Got a valuetype that is neither struct nor enum: " + real_type_name);
	}
} else {
	//	It's a class. Let's wrap the native item in our native wrapper for the defined type
	var full_type_name = type.trim().replace(/\./g, '::');
	if (full_type_name.indexOf('class ') == 0) {
		full_type_name = full_type_name.substring(6);
	}
	if (full_type_name == 'object') {
		full_type_name = 'Platform::Object';
	}

	if (full_type_name.indexOf('[]') == full_type_name.length - 2) {
		// Strip off the [], then proceed knowing it's an array...
		full_type_name = full_type_name.substring(0, full_type_name.length - 2);
-%>
			std::vector<JSValue> <%= to_assign %>_vector;
			for (int i = 0; i < <%= argument_name %>->Length; ++i) {
				auto <%= argument_name %>_tmp = context.CreateObject(JSExport<<%- full_type_name %>>::Class());
				auto <%= argument_name %>_tmp_wrapper = <%= argument_name %>_tmp.GetPrivate<<%- full_type_name %>>();
				<%= argument_name %>_tmp_wrapper->wrap(<%= argument_name %>[i]);
        		<%= to_assign %>_vector.push_back(<%= argument_name %>_tmp);
			}

			<%= to_assign %> = get_context().CreateArray(<%= to_assign %>_vector);
<%
	} else { // normal class
-%>
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto <%= to_assign %> = context.CreateObject(JSExport<<%- full_type_name %>>::Class());
			auto <%= to_assign %>_wrapper = <%= to_assign %>.GetPrivate<<%- full_type_name %>>();
			<%= to_assign %>_wrapper->wrap(<%= argument_name %>);
<% 
	}
}
-%>