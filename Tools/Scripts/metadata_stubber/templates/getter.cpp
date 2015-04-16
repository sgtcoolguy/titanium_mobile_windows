		TITANIUM_PROPERTY_GETTER(<%= base_name %>, <%= property_name %>)
		{
			auto value = wrapped__-><%= property_name %>;
			auto context = get_context();
<%
var type = properties[property_name]['returnType'];
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') {
-%> 
			return context.CreateBoolean(value); 
<%
} else if (type == 'int32' || type == 'uint32' || type == 'double') {
-%> 
			return context.CreateNumber(value);
<%
} else if (type == 'string') {
-%> 
			return context.CreateString(value);
<%
} else if (type == 'float32' || type == 'float64') {
-%>
			return context.CreateNumber(static_cast<double>(value));
<%
} else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	// console.log(real_type_name); // useful to know what type we need to pull into our stripped down metadata
	var other_type = metadata[real_type_name];
	var is_enum = (other_type.extends == '[mscorlib]System.Enum');
	var is_struct = (other_type.extends == '[mscorlib]System.ValueType');

	if (is_struct) {
-%>
			auto result = context.CreateObject();
<%		for (field_name in other_type.fields) {
			var field_type = other_type.fields[field_name].type;
			if (field_type == 'int64' || field_type == 'float32' || field_type == 'double') {
-%>
			result.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<double>(value.<%= field_name %>)));
<%
			} else if (field_type == 'uint32') {
-%>
			result.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<uint32_t>(value.<%= field_name %>)));
<%
			} else {
-%>
			result.SetProperty("<%= field_name %>", context.CreateNumber(static_cast<int32_t>(value.<%= field_name %>)));
<%
			}
		}
-%>
			return result; 
<%
	} else if (is_enum) {
-%>
			return context.CreateNumber(value);
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
			auto object = context.CreateObject(JSExport<<%= full_type_name %>>::Class());
			auto native_wrapper = object.GetPrivate<<%= full_type_name %>>();
			native_wrapper->wrap(value);
			return object;
<% } -%>
		}
