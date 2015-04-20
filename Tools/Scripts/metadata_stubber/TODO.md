= TODO =
- handle method arguments in function.cpp template.
	- We need to look through the metadata to know how many arguments, their types, map from JSValue arguments to appropriate types, etc and forward on to method call
	- handle overloads of same method with different argument counts/types. We have one bridge method that needs to handle every variation of overload.
- Fix escaping of complex types that use templates. See TITANIUM_PROPERTY_GETTER(UIElement, PointerCaptures) in Windows.UI.Xaml.UIElement.cpp
	- We need to use <%- tag to avoid escaping, but we aso appear to need to clean up the bad metadata which added "class " prefix to templated type inside the IVectorView.
- Better handle polymorphism on getters when unwrapping?
	- We know the defined return type from metadata, but that could be a parent/base type and the actual property value is a subclass. We effectively lose that info and have no means to cast down to subclass. May need some special syntax in JS to do the casting? does the unwrapping even work fromt he JSObject in cases like this?
- Handle mapping primitives better
	- I might not be casting appropriately, and we may need to worry about signed/unsigned mismatches
	- I'm not handling all the primitive types, just some
- Events
	- I'm not exposing events/handlers at all - or maybe I am but haven't really hooked them up properly...
	- We'll likely want to allow users to register a function callback as a handler and do the magic work behind the scenes for them.
- Handle non-default constructors for wrapped types
- Handle constructions of structs
	- We don't look at metadata to see how many args they require in their constructor. We can probably cheat and just populate with 0/"" values and then explicitly assign property/fields
	- See Windows.UI.Xaml.Controls.Control.cpp TITANIUM_PROPERTY_SETTER(Control, Padding) for an example where we need to construct a Thickness struct
- handle some oddball metadata issues
	- See Windows.UI.Xaml.Controls.Control.cpp TITANIUM_PROPERTY_SETTER(Control, DefaultStyleKey) for example where we think "object" is a class and should likely just treat it as some base type like Titanium::Module/JSExport.
- Use JSExport as root, not Titanium::Module.
- Run against entire set of metadata, not my filtered down metadata.json file. (Use hyperloop_windows_metabase.json.gz)

== Improvements to Metadata ==
- Consistently use "class Name.Of.Class" or "Name.Of.Class" for types. Probably the former.
- Add constructor info for structs (so we know arg count, types, maybe even fields they correspond to?)
- Mark API support for each type. There are types documented that work on windows Phone 10 tehcnical preview, but not 8 or 8.1.
- Pare down the amount of data to just what we need? (Doesn't matter much if just used to geenrate stubs and isn't getting embedded in app or shipped in distribution)
- Fix up naming of complex/templated types?