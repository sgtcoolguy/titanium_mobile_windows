= TODO =
- Generate the types inside the user's app, not in TitaniumWindows module?
- Walk the user's app.js to record the types needed and use that to determine what to include and register off global?
	- We'd need a way for the user's app code to be able to register the stuff on the global namespace...
	- We could also enforce use of "require" and hack require to on-demand register the type on global? Or maybe just have it return a reference to the type?
- Casting
	- Add a "cast" method to Platform::Object that takes a String and tries to unwrap/rewrap with the new type
		i.e. something.cast('Windows.UI.Xaml.Controls.Page');
		behind the scenes it uses a big if/else block that we generate with every possible type we know about and does an auto new_wrapper = context.CreateObject(JSExport<Type::Name::Here>::Class());
		new_wrapper->wrap(dynamic_cast<Type::Name::Here^>(unwrapPlatform_Object()));
		- Should it modify the existing object by assigning to it under the hood, or return the new wrapped object?
- Events
	- I'm not exposing events/handlers at all - or maybe I am but haven't really hooked them up properly...
	- We'll likely want to allow users to register a function callback as a handler and do the magic work behind the scenes for them.
- Enums
	- Should we look at the dependencies of a type and when it includes enums, we then register the enum and it's values into the global namespace?

== Improvements to Metadata ==
- Consistently use "class Name.Of.Class" or "Name.Of.Class" for types. Probably the former.
- Mark API support for each type. There are types documented that work on windows Phone 10 tehcnical preview, but not 8 or 8.1.
- Pare down the amount of data to just what we need? (Doesn't matter much if just used to geenrate stubs and isn't getting embedded in app or shipped in distribution)
- Fix up naming of complex/templated types?