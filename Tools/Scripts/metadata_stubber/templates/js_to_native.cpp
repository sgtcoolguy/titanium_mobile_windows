<%
// TODO uint8, int, uint16, int16, int64, uint64, single, char16
if (type == 'bool') {
-%> 
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsBoolean(), "Expected boolean");
			auto <%= to_assign %> = static_cast<bool>(<%= argument_name %>);
<%
} else if (type == 'int32') {
-%> 
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsNumber(), "Expected Number");
			auto <%= to_assign %> = static_cast<int32_t>(<%= argument_name %>);
<%
} else if (type == 'uint32') {
-%> 
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsNumber(), "Expected Number");
			auto <%= to_assign %> = static_cast<uint32_t>(<%= argument_name %>);
<%
} else if (type == 'double' || type == 'float32' || type == 'float64') {
-%> 
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsNumber(), "Expected Number");
			auto <%= to_assign %> = static_cast<double>(<%= argument_name %>);
<%
} else if (type == 'string') {
-%> 
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsString(), "Expected String");
			auto <%= to_assign %> = static_cast<std::string>(<%= argument_name %>);
<%
} else if (type.indexOf('valuetype ') == 0) {
	var real_type_name = type.substring(10).trim();
	// May ask for reference to a type as an argument to a method, so let's drop the trailing & for now.
	if (real_type_name.lastIndexOf('&') == real_type_name.length - 1) {
		real_type_name = real_type_name.substring(0, real_type_name.length - 1);
	}
	var other_type = metadata[real_type_name];
	if (!other_type) {
		console.log("No metadata found for: " + real_type_name); // useful to know what type we need to pull into our stripped down metadata
	}
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
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsObject(), "Expected Object");
			auto object_<%= to_assign %> = static_cast<JSObject>(<%= argument_name %>);
			auto <%= to_assign %> = ::<%= windows_type_name %>(<%= ctr_args %>);
			// Assign fields explicitly since we cheated on constructor args
<%
		for (field_name in other_type.fields) {
-%>
			auto <%= field_name %> = object_<%= to_assign %>.GetProperty("<%= field_name %>");
<%
			var field_type = other_type.fields[field_name].type;
			if (field_type == 'int64' || field_type == 'float32' || field_type == 'double') {
-%>
			<%= to_assign %>.<%= field_name %> = static_cast<double>(<%= field_name %>);
<%
			} else if (field_type == 'uint32') {
-%>
			<%= to_assign %>.<%= field_name %> = static_cast<uint32_t>(<%= field_name %>);
<%
			} else {
-%>
			<%= to_assign %>.<%= field_name %> = static_cast<int32_t>(<%= field_name %>);
<%
			}
		}
	} else if (is_enum) {
-%>
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsNumber(), "Expected Number");
			auto <%= to_assign %> = static_cast<::<%= real_type_name.replace(/\./g, '::') %>>(static_cast<int32_t>(<%= argument_name %>)); // TODO Look up enum in metadata to know what type it's value is? 
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
			TITANIUM_ASSERT_AND_THROW(<%= argument_name %>.IsObject(), "Expected Object");
			auto object_<%= to_assign %> = static_cast<JSObject>(<%= argument_name %>);
			auto wrapper_<%= to_assign %> = object_<%= to_assign %>.GetPrivate<<%= full_type_name %>>();
			// FIXME What if the type we want here is some parent class of the actual wrapper's class? I think we'll get nullptr here.
			// We need some way to know the underlying type the JSObject maps to, get that, then cast to the type we want...
			auto <%= to_assign %> = wrapper_<%= to_assign %>->unwrap<%= full_type_name.replace(/::/g, '_') %>();
<%
}
-%>