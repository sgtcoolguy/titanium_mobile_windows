= TODO =
- Async methods
	- We skip them entirely. We need to convert to a Promise like object like WInJS does
- Avoid recompiling everything on every rebuild
	- Shouldn't need to recompile anything if no new native types are added
	- Only compile new types and RequireHook/WindowsNativeModuleLoader if new types/modules added!
	
== Improvements to Metadata ==
- Consistently use "class Name.Of.Class" or "Name.Of.Class" for types. Probably the former.
- Mark API support for each type. There are types documented that work on windows Phone 10 tehcnical preview, but not 8 or 8.1.
- Pare down the amount of data to just what we need? (Doesn't matter much if just used to geenrate stubs and isn't getting embedded in app or shipped in distribution)
- Fix up naming of complex/templated types?