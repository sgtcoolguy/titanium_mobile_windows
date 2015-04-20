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
		// here we generate constructor args.
		// FIXME the matadata gives no indication if the struct has a constructor or not, or the arg order. So I don't think this will work properly!
		// Looks like we'll need to improve the metadata generator. But it also appears that for those not having constructors they can only be accessed
		// through read-only getters. So let's just hope this works well enough for now...
		var ctr_args = "";
		for (field_name in other_type.fields) {
			var field_type = other_type.fields[field_name].type;
			if (field_type == 'string') {
				ctr_args =+ "\"\", ";
			} else if (field_type == 'bool') {
				ctr_args += "false, ";
			} else {
				// assume number for any other type.
				ctr_args += "0, ";
			}
		}
		ctr_args = ctr_args.substring(0, ctr_args.length - 2); 
-%>
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto value = ref new ::<%= windows_type_name %>(<%= ctr_args %>);
			// TODO Need to explicitly assign fields!
<%
	} else if (is_enum) {
-%>
			TITANIUM_ASSERT_AND_THROW(argument.IsNumber(), "Expected Number");
			auto value = static_cast<::<%= real_type_name.replace(/\./g, '::') %>>(static_cast<int32_t>(argument)); // TODO Look up enum in metadata to know what type it's value is? 
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
	// object == Platform::Object. We treat it as our root type, which is currently Titanium::Module
	if (full_type_name == 'object') {
		full_type_name = 'Titanium::Module';
	}
-%> 
			TITANIUM_ASSERT_AND_THROW(argument.IsObject(), "Expected Object");
			auto object = static_cast<JSObject>(argument);
			auto wrapper = object.GetPrivate<<%= full_type_name %>>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto value = wrapper->unwrap<%= full_type_name.replace(/::/g, '_') %>();
<%
}
-%>
			unwrap()-><%= property_name %> = value;
			return true;
		}
