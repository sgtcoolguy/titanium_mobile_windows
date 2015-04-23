= TODO =
- handle overloads of same method with different argument counts/types. We have one bridge method that needs to handle every variation of overload.

- Handle mapping primitives better
	- I might not be casting appropriately, and we may need to worry about signed/unsigned mismatches
	- I'm not handling all the primitive types, just some
- Events
	- I'm not exposing events/handlers at all - or maybe I am but haven't really hooked them up properly...
	- We'll likely want to allow users to register a function callback as a handler and do the magic work behind the scenes for them.
- Handle non-default constructors for wrapped types
- Use JSExport as root, not Titanium::Module.
- Allow unwrapping to base "Object" for methods where we get/set plain Object
- Map collection types to JSArray/JSObject properly
	- We need to be able to convert from IMap/IMapView <-> JSObject, and IVector/IVectorView <-> JSArray. Not sure about iterable/iterator, key-value pair, etc. See blacklist in stub.js
	- We also need to handle "primitive" arrays as well, such as in WwwFormUrlDecoder.GetMany()
- Fix up includes of used types. We don't clean up the types to handle primitive arrays, collections with templates, etc.

== Improvements to Metadata ==
- Consistently use "class Name.Of.Class" or "Name.Of.Class" for types. Probably the former.
- Add constructor info for structs (so we know arg count, types, maybe even fields they correspond to?)
- Mark API support for each type. There are types documented that work on windows Phone 10 tehcnical preview, but not 8 or 8.1.
- Pare down the amount of data to just what we need? (Doesn't matter much if just used to geenrate stubs and isn't getting embedded in app or shipped in distribution)
- Fix up naming of complex/templated types?