var fs = require('fs'),
	ejs = require('ejs'),
	path = require('path'),
	wrench = require('wrench'),
	metadata = JSON.parse(fs.readFileSync('metadata.json')),
	all_classes = metadata['classes'],
	classDefinition;

wrench.mkdirSyncRecursive(path.join(__dirname, 'generated', 'include'));
wrench.mkdirSyncRecursive(path.join(__dirname, 'generated', 'src'));

for (classname in all_classes) {
	classDefinition = all_classes[classname];
	// skip structs and enums
	if (classDefinition['extends'].indexOf("[mscorlib]System.Enum") == 0 ||
		classDefinition['extends'].indexOf("[mscorlib]System.ValueType") == 0) {
		continue;
	}

	// Stub the header
	var hpp_file = path.join(__dirname, 'templates', 'Proxy.hpp');
	var generated_proxy_header = ejs.render('' + fs.readFileSync(hpp_file), {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends']}, {filename: hpp_file});
	fs.writeFileSync(path.join(__dirname, 'generated', 'include', classname + '.hpp'), generated_proxy_header, {flags : 'w'});

	// Stub the implementation
	var cpp_file = path.join(__dirname, 'templates', 'Proxy.cpp');
	// We need the whole all_classes data so we can look up types such as structs/enums to map to JSObjects/JSNumbers
	var generated_proxy_impl = ejs.render('' + fs.readFileSync(cpp_file), {properties: classDefinition.properties, methods: classDefinition.methods, name: classDefinition.name, metadata: all_classes, parent: classDefinition['extends']}, {filename: cpp_file});
	fs.writeFileSync(path.join(__dirname, 'generated', 'src', classname + '.cpp'), generated_proxy_impl, {flags : 'w'});
}
