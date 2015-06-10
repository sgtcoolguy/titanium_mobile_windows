<%
// This expects:
// to_assign: the name of the native variable to assign the resulting object to
// type: the _definition_ of the struct type from the metadata! Note that this differs from other partials that expect a type name for this variable!
// metadata: pointer to the full metadata
// argument_name: the name of the JS variable we're converting from


// here we generate constructor args.
// FIXME the matadata gives no indication if the struct has a constructor or not, or the arg order. So I don't think this will work properly!
// Looks like we'll need to improve the metadata generator. But it also appears that for those not having constructors they can only be accessed
// through read-only getters. So let's just hope this works well enough for now...
var ctr_args = "";
for (field_name in type.fields) {
	var field_type = type.fields[field_name].type;
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
			::<%= type.name.to_windows_name() %> <%= to_assign %>;
			// Assign fields explicitly since we didn't use a constructor
<%
for (field_name in type.fields) {
-%>
			auto object_<%= to_assign %>_<%= field_name %> = object_<%= to_assign %>.GetProperty("<%= field_name %>");<%- include('js_to_native.cpp', {type:  type.fields[field_name].type, metadata: metadata, to_assign: 'object_' + to_assign + '_' + field_name + '_', argument_name: 'object_' + to_assign + '_' + field_name}) -%>
			<%= to_assign %>.<%= field_name %> = object_<%= to_assign %>_<%= field_name %>_;
<%
}
-%>