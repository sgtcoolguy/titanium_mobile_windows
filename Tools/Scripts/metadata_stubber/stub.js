var fs = require('fs'),
	ejs = require('ejs'),
	path = require('path'),
	wrench = require('wrench'),
	async = require('async'),
	metadata = JSON.parse(fs.readFileSync(path.join(__dirname, 'hyperloop_windows_metabase.json.gz'))),
	all_classes = metadata['classes'],
	// where do we stick our wrappers?
	dest = path.join(__dirname, '..', '..', '..', 'Source', 'Titanium'),
	require_hook = path.join(__dirname, '..', '..', '..', 'Source', 'Titanium', 'src', 'WindowsNativeModuleLoader.cpp'),
	// Start with seeds from my simple hello world app
	seeds = [
		'Windows.UI.Xaml.Controls.Canvas',
		'Windows.UI.Xaml.Controls.TextBlock',
		'Windows.UI.Xaml.Controls.Page',
		'Windows.UI.Xaml.Window'
	],
	// TODO Let's assume everything for now
	//seeds = [],
	// We need to skip/map a number of collections to JSArray and JSObject
	// We handle these types specially
	blacklist = [
		"object",
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
	if (type == 'object') {
		type = 'Platform.Object';
	}
	return type;
}

function expandTypes(typeName) {
	var types = [],
		type = typeName.trim(),
		collectionName;
	if (type.indexOf('`1<') != -1) {
		collectionName = normalizeType(type.substring(0, type.indexOf('`1<')));
		types.unshift(collectionName + '`1<T>');
		types = types.concat(expandTypes(type.substring(type.indexOf('`1<') + 3, type.length - 1)));
	} else if (type.indexOf('`2<') != -1) {
		collectionName = normalizeType(type.substring(0, type.indexOf('`2<')));
		types.unshift(collectionName + '`2<K,V>');
		type = type.substring(type.indexOf('`2<') + 3, type.length - 1);
		// split on ,!
		types = types.concat(expandTypes(type.substring(0, type.indexOf(','))));
		types = types.concat(expandTypes(type.substring(type.indexOf(',') + 1)));
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
				method.name == '.ctor') {
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
	// TODO Can we inject the set of types to include into the metadata for this type?!
	classDefinition.dependencies = types;
	classDefinition.dependencies.unshift(classname);
	return types;
}

// If we have no seeds, assume we want everything!
if (seeds.length == 0) {
	for (classname in all_classes) {
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

// Using the seeds, generate the list of types we need to stub!
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

// Generate a base class that everything can extend where we can hang a single unwrap method to get back an Object!
all_classes['Platform.Object'] = {
	"name": 'Platform.Object',
	properties: {},
	methods: [],
	attributes: [
		"public",
		"auto",
		"ansi",
		"windowsruntime"
	],
	'extends': 'Module'
}
seeds.unshift('Platform.Object');
// TODO Add a cast method that takes one String, and generate a huuuuge block of conversions inside it for every type we know of below!

// Now that we have the full list of types, let's stub them
async.each(seeds, function(classname, callback) {
	var classDefinition = all_classes[classname];
	console.log('Processing class ' + classname);

	// Skip blacklisted types
	if (blacklist.indexOf(classname) != -1) {
		callback();
		return;
	}
	
	if (!classDefinition) {
		callback("Something went wrong. No metadata for type: " + classname);
		return;
	}

	// skip structs and enums
	if (classDefinition['extends'] && 
		(classDefinition['extends'].indexOf("[mscorlib]System.Enum") == 0 ||
		classDefinition['extends'].indexOf("[mscorlib]System.ValueType") == 0)) {
		callback();
		return;
	}

	// Stub the header
	console.log("Stubbing header for " + classname);
	var hpp_file = path.join(__dirname, 'templates', 'Proxy.hpp');
	fs.readFile(hpp_file, 'utf8', function (err, data) {
		if (err) callback(err);

		var generated_proxy_header = ejs.render(data, {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends']}, {filename: hpp_file});
		fs.writeFile(path.join(dest, 'include', classname + '.hpp'), generated_proxy_header, {flags : 'w'}, function(err) {
			if (err) callback(err);
		});
	});

	// Stub the implementation
	console.log("Stubbing implementation for " + classname);
	var cpp_file = path.join(__dirname, 'templates', 'Proxy.cpp');
	fs.readFile(cpp_file, 'utf8', function (err, data) {
		if (err) callback(err);

		var generated_proxy_impl = ejs.render(data, {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends'], dependencies: classDefinition.dependencies}, {filename: cpp_file});
		fs.writeFile(path.join(dest, 'src', classname + '.cpp'), generated_proxy_impl, {flags : 'w'}, function(err) {
			if (err) {
				callback(err);
			}
			else {
				callback();
			}
		});
	});
}, function(err){
	// if any of the file processing produced an error, err would equal that error
	if( err ) {
	  // One of the iterations produced an error.
	  // All processing will now stop.
	  console.log(err.toString());
	} else {
	  console.log('All files have been processed successfully');
	}
});

// Now we'll add all the types we know about as includes into our require hook class
// This let's us load these types by name using require!
console.log("Adding types to require hook implementation...");
fs.readFile(require_hook, 'utf8', function (err, data) {
	if (err) throw err;

	var classes = "";
	var loader_switch = "";

	// Add our includes
	for (var i = 0; i < seeds.length; i++) {

		// Skip blacklisted types
		if (blacklist.indexOf(seeds[i]) != -1) {
			continue;
		}

		classes += "#include \"" + seeds[i] + ".hpp\"\r\n";
		loader_switch += "\t\telse if (path == \"" + seeds[i] + "\") {\r\n\t\t\tinstantiated = context.CreateObject(JSExport<::Titanium::" + seeds[i].replace(/\./g, '::') + ">::Class());\r\n\t\t}\r\n";
	}
	loader_switch += "\t\telse {\r\n			return false;\r\n		}";
	loader_switch = loader_switch.substring(7); // drop first "\t\telse "
	data = data.replace('// INSERT_INCLUDES', classes);
	data = data.replace('// INSERT_SWITCH', loader_switch);

	fs.writeFile (require_hook, data, function(err) {
		if (err) throw err;
	});
});

