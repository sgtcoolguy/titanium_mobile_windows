var fs = require('fs'),
	ejs = require('ejs'),
	path = require('path'),
	wrench = require('wrench'),
	metadata = JSON.parse(fs.readFileSync(path.join(__dirname, 'hyperloop_windows_metabase.json.gz'))),
	all_classes = metadata['classes'],
	classDefinition,
	dest = path.join(__dirname, '..', '..', '..', 'Source', 'UI'),
	// Start with seeds from my simple hellow world app
	seeds = [
		'Windows.UI.Xaml.Controls.Canvas',
		'Windows.UI.Xaml.Controls.TextBlock',
		'Windows.UI.Xaml.Controls.Page',
		'Windows.UI.Xaml.Window'
	],
	// TODO We need to skip/map a number of collections to JSArray and JSObject
	blacklist = [
		"Windows.Foundation.Collections.IIterable`1<T>",
	    "Windows.Foundation.Collections.IIterator`1<T>",
	    "Windows.Foundation.Collections.IVectorView`1<T>",
	    "Windows.Foundation.Collections.IVector`1<T>",
	    "Windows.Foundation.Collections.IKeyValuePair`2<K,V>",
	    "Windows.Foundation.Collections.IMap`2<K,V>",
	    "Windows.Foundation.Collections.IMapView`2<K,V>",
	    "Windows.Foundation.Collections.VectorChangedEventHandler`1<T>",
	    "Windows.Foundation.Collections.IObservableVector`1<T>",
	    "Windows.Foundation.Collections.IMapChangedEventArgs`1<K>",
	    "Windows.Foundation.Collections.MapChangedEventHandler`2<K,V>",
	    "Windows.Foundation.Collections.IObservableMap`2<K,V>",
	    "Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2<TResult,TProgress>",
	    "Windows.Foundation.IAsyncOperationWithProgress`2<TResult,TProgress>",
	    "Windows.Foundation.AsyncOperationCompletedHandler`1<TResult>",
	    "Windows.Foundation.IAsyncOperation`1<TResult>",
	    "Windows.Foundation.AsyncActionWithProgressCompletedHandler`1<TProgress>",
	    "Windows.Foundation.IAsyncActionWithProgress`1<TProgress>",
	    "Windows.Foundation.AsyncOperationProgressHandler`2<TResult,TProgress>",
	    "Windows.Foundation.AsyncActionProgressHandler`1<TProgress>",
	    "Windows.Foundation.IReference`1<T>",
	    "Windows.Foundation.IReferenceArray`1<T>",
	    "Windows.Foundation.TypedEventHandler`2<TSender,TResult>",
	    "Windows.Foundation.EventHandler`1<T>"
	];

// For when we dump files into a "generated" sub-folder
//wrench.mkdirSyncRecursive(path.join(__dirname, 'generated', 'include'));
//wrench.mkdirSyncRecursive(path.join(__dirname, 'generated', 'src'));

function normalizeType(typeName) {
	var type = typeName.trim();
	if (type.indexOf('class ') == 0) {
		type = type.substring(6);
	}
	if (type.indexOf('>') == (type.length - 1)) {
		type = type.substring(0, type.length - 1);
	}
	if (type.indexOf('[]') == (type.length - 2)) {
		type = type.substring(0, type.length - 2);
	}
	return type;
}

// TODO Handle multiple nesting!
function expandTypes(typeName) {
	var types = [],
		type = typeName.trim(),
		collectionName;
	if (type.indexOf('`1<') != -1) {
		collectionName = normalizeType(type.substring(0, type.indexOf('`1<')));
		types.unshift(collectionName + '`1<T>');
		type = normalizeType(type.substring(type.indexOf('`1<') + 3));
		types.unshift(type);
	} else {
		types.unshift(normalizeType(typeName));
	}
	return types;
}

function addNewTypes(rawTypeName, existingTypes) {
	var types = [];
	if (rawTypeName.indexOf('class ') == 0 || rawTypeName.indexOf('Windows.') == 0) {
		types = expandTypes(rawTypeName);
		for (var i = 0; i < types.length; i++) {
			// skip template names
			if (types[i].indexOf("!") == 0) {
				continue;
			}
			if (existingTypes.indexOf(types[i]) == -1) {
				existingTypes.unshift(types[i]);
			}
		}
	}
}

/**
 * Given a type name, look up all the types it references. Returns an array of strings (type names)
 */
function getDependencies(classname) {
	var classDefinition = all_classes[classname],
		types = [];
	if (!classDefinition) {
		console.log("Something went wrong. No metadata for type: " + classname);
		return types;
	}

	// skip system types
	if (classname.indexOf("[mscorlib]") == 0) {
		return types;
	}

	// skip structs and enums
	if (classDefinition['extends'] && 
		(classDefinition['extends'].indexOf("[mscorlib]System.Enum") == 0 ||
		classDefinition['extends'].indexOf("[mscorlib]System.ValueType") == 0)) {
		return types;
	}

	// Add parent
	if (classDefinition['extends']) {
		addNewTypes(classDefinition['extends'], types);
	}

	// gather all the types referenced in this file!
	var prop,
		method;
	// check property types
	for (property_name in classDefinition.properties) {
		prop = classDefinition.properties[property_name];
		addNewTypes(prop.returnType, types);
	}
	// Check method args and return types!
	if (classDefinition.methods) {
		for (var i = 0; i < classDefinition.methods.length; i++) {
			method = classDefinition.methods[i];
			// Skip if method starts with get_, put_ (properties), add_ or remove_ (events)
			if (method.name.indexOf('get_') == 0 || method.name.indexOf('put_') == 0 ||
				method.name.indexOf('add_') == 0 || method.name.indexOf('remove_') == 0 ||
				method.returnType == 'void' || method.name == '.ctor') {
					continue;
			}
			// Skip non-public methods
			if (method.attributes.indexOf("public") == -1) {
				continue;
			}

			// return type
			addNewTypes(method.returnType, types);
			// Check method args!
			for (var j = 0; j < method.args.length; j++) {
				addNewTypes(method.args[j].type, types);
			}
		}
	}
	return types;
}

// Using the seeds, generate the list of types we need to stub!
// If we have no seeds, assume we want everything!
if (seeds.length == 0) {
	for (var i = 0; i < seeds.length; i++) {
		var classname = seeds[i];
		classDefinition = all_classes[classname];
		// skip structs and enums
		if (classDefinition['extends'] && 
			(classDefinition['extends'].indexOf("[mscorlib]System.Enum") == 0 ||
			classDefinition['extends'].indexOf("[mscorlib]System.ValueType") == 0)) {
			continue;
		}

		seeds.unshift(classname);
	}
}
else {
	// We've specified seed types, use those to gather the full list of types we'll need to generate
	var todo = [];
	for (var i = 0; i < seeds.length; i++) {
		todo.unshift(seeds[i]);
	}
	while (todo.length > 0) {
		var classname = todo.shift();
		console.log("Gathering dependencies of: " + classname);
		var dependencies = getDependencies(classname);
		// are there any new types here?
		for (var j = 0; j < dependencies.length; j++) {
			var the_dependency = dependencies[j];
			if (seeds.indexOf(the_dependency) == -1) {
				// new type. Add it to our seed listing and our queue to gather it's dependencies
				console.log("Adding type to list: " + the_dependency);
				seeds.unshift(the_dependency);
				todo.unshift(the_dependency);
			}
		}
	}
}

// Now that we have the full list of types, let's stub them
for (var i = 0; i < seeds.length; i++) {
	var classname = seeds[i];
	// Skip blacklisted types
	if (blacklist.indexOf(classname) != -1) {
		continue;
	}
	classDefinition = all_classes[classname];
	
	if (!classDefinition) {
		console.log("Something went wrong. No metadata for type: " + classname);
		continue;
	}

	// skip structs and enums
	if (classDefinition['extends'] && 
		(classDefinition['extends'].indexOf("[mscorlib]System.Enum") == 0 ||
		classDefinition['extends'].indexOf("[mscorlib]System.ValueType") == 0)) {
		continue;
	}

	// Stub the header
	console.log("Stubbing header for " + classname);
	var hpp_file = path.join(__dirname, 'templates', 'Proxy.hpp');
	var generated_proxy_header = ejs.render('' + fs.readFileSync(hpp_file), {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends']}, {filename: hpp_file});
	fs.writeFileSync(path.join(dest, 'include', classname + '.hpp'), generated_proxy_header, {flags : 'w'});

	// Stub the implementation
	console.log("Stubbing implementation for " + classname);
	var cpp_file = path.join(__dirname, 'templates', 'Proxy.cpp');
	// We need the whole all_classes data so we can look up types such as structs/enums to map to JSObjects/JSNumbers
	var generated_proxy_impl = ejs.render('' + fs.readFileSync(cpp_file), {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends']}, {filename: cpp_file});
	fs.writeFileSync(path.join(dest, 'src', classname + '.cpp'), generated_proxy_impl, {flags : 'w'});
}
