		TITANIUM_FUNCTION(<%= base_name %>, <%= method.name %>)
		{
			// TODO What about handling args! We need to confirm the number and convert types there too!
			// i.e. TextBox.Select() takes two int32 args
<%	if (method.returnType == 'void') { -%>
			unwrap()-><%= method.name %>();
			return get_context().CreateUndefined(); 
<%	} else { -%>
			// otherwise we need to map return type to equivalent JS type!
			auto result = unwrap()-><%= method.name %>();
			return get_context().CreateBoolean(result); 
<%	} -%>
		}
