		TITANIUM_PROPERTY_SETTER(<%= base_name %>, <%= property_name %>)
		{
<%
var type = properties[property_name]['returnType'];
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') {
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsBoolean(), "Expected boolean");
			auto value = static_cast<bool>(argument);
<%
} else if (type == 'int32') {
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument);
<%
} else if (type == 'uint32') {
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<uint32_t>(argument);
<%
} else if (type == 'double' || type == 'float32' || type == 'float64') {
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<double>(argument);
<%
} else if (type == 'string') {
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsString(), "Expected String");
			auto value = static_cast<std::string>(argument);
<%
} else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	// console.log(real_type_name); // useful to know what type we need to pull into our stripped down metadata
	var other_type = metadata[real_type_name];
	var is_enum = (other_type.extends == '[mscorlib]System.Enum');
	var is_struct = (other_type.extends == '[mscorlib]System.ValueType');
	var windows_type_name = real_type_name.to_windows_name();

	if (is_struct) {
-%>
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new <%= windows_type_name %>(); // FIXME We need to look at the fields to know how many, and order of args to pass in!
<%
	} else if (is_enum) {
-%>
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<int32_t>(argument); // TODO Look up enum in metadata to know what type it's value is? 
<%
	} else {
		// Has to be struct or enum or we have an issue!
		console.log("Got a valuetype that is neither struct nor enum: " + real_type_name);
	}
} else {
	//	It's a class. Assume we have a JSObject wrapping a native impl
	var full_type_name = type.trim().replace(/\./g, '::');
	if (full_type_name.indexOf('class ') == 0) {
		full_type_name = full_type_name.substring(6);
	}
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<<%= full_type_name %>>();
			// FIXME What if the type we want here is some parent class of the actual wrapper class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap<%= full_type_name.replace(/::/g, '_') %>();
<%
}
-%>
			wrapped__-><%= property_name %> = value;
			return true;
		}
