<%
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') {
-%> 
			auto <%= to_assign %> = context.CreateBoolean(<%= argument_name %>); 
<%
} else if (type == 'int32' || type == 'uint32' || type == 'double') {
-%> 
			auto <%= to_assign %> = context.CreateNumber(<%= argument_name %>);
<%
} else if (type == 'string') {
-%> 
			auto <%= to_assign %> = context.CreateString(TitaniumWindows::Utility::ConvertUTF8String(<%= argument_name %>));
<%
} else if (type == 'float32' || type == 'float64') {
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
			auto <%= to_assign %> = context.CreateObject();
<%		for (field_name in other_type.fields) {
			var field_type = other_type.fields[field_name].type;
			if (field_type == 'int64' || field_type == 'float32' || field_type == 'double') {
-%>
			<%= to_assign %>.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<double>(<%= argument_name %>.<%= field_name %>)));
<%
			} else if (field_type == 'uint32') {
-%>
			<%= to_assign %>.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<uint32_t>(<%= argument_name %>.<%= field_name %>)));
<%
			} else {
-%>
			<%= to_assign %>.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<int32_t>(<%= argument_name %>.<%= field_name %>)));
<%
			}
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
	} -%>
			// FIXME We're assuming the value is the exact type defined in the return type. It may be a subclass and we'll lose that detail here...
			// I'm not sure how we can avoid it, though
			auto <%= to_assign %> = context.CreateObject(JSExport<<%= full_type_name %>>::Class());
			auto <%= to_assign %>_wrapper = <%= to_assign %>.GetPrivate<<%= full_type_name %>>();
			<%= to_assign %>_wrapper->wrap(<%= argument_name %>);
<% } -%>