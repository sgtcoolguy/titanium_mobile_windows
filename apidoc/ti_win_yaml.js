/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
var lbl = require('line-by-line'),
    path = require('path'),
	fs = require('fs.extra'),
	TI_KIT_SRC_DIRECTORY = '../Source/TitaniumKit/src',
	TI_WIN_DOC_DIRECTORY = '../apidoc/Titanium',
	TI_WIN_SRC_DIRECTORY = '../Source/';

// Add 'contains' prototype to String
if (typeof String.prototype.contains === 'undefined') {
	String.prototype.contains = function(str) {
		return this.indexOf(str) != -1;
	}
}

// Define signatures
var property_ro_signature = 'TITANIUM_ADD_PROPERTY_READONLY(';
var property_signature = 'TITANIUM_ADD_PROPERTY('
var method_signature = 'TITANIUM_ADD_FUNCTION(';
var namespace_signature = 'namespace ';

var properties_found = 0;
var methods_found = 0;
var events_found = 0;

var docs = {};

// Walk through the TitaniumKit source directory
var walker = fs.walk(TI_KIT_SRC_DIRECTORY)
walker.on("file",
	function (root, stat, next) {
		if (stat.name.contains('.cpp')) {
		    processClass(root, stat.name, next);
		} else {
			next();
		}
	}
);
walker.on("end", processEvents);

function processEvents () {
	var recurse = fs.walk(TI_WIN_SRC_DIRECTORY);
	recurse.on("file", function (root, stat, next) {
		if (stat.name.contains('.cpp')) {
		    processEvent(root, stat.name, next);
		} else {
			next();
		}
	});
	recurse.on('end', function() {
		var className, cls;
		for (className in docs) {
			cls = docs[className];
			generateYAML(cls.root, cls.module_name, cls.module, cls.properties, cls.methods, cls.events);
		}
		console.log('\nProcessing whitelist.txt...');
		processWhitelist('whitelist.txt', function() {
			console.log('\nFound '+methods_found+' methods');
			console.log('Found '+properties_found+' propeties');
			console.log('Found '+events_found+' events');
			console.log('Total APIs : '+(methods_found+properties_found+events_found));
			
			var docPath = process.argv[1].replace(/\\/g, '/')
			docPath = docPath.substring(0, docPath.lastIndexOf('/'))+'/Titanium';
			console.log('\nTo append the documentation run the following command from titanium_mobile/apidoc :\n\nnode docgen.js -f parity -a '+docPath);
		});
	});
}

function processEvent(root, file, next) {
	var l = new lbl(path.join(root, file)),
		name = null,
		events = [],
		namespace = [],
		module = file.replace('.cpp', '').replace('Module', '');
		if (module === 'TitaniumWindow') {
			module = 'App';
		}
	l.on('line', function(line) {
		if (~line.indexOf('fireEvent') && !~line.indexOf('//') && !~line.indexOf('%') && !~line.indexOf('TITANIUM_LOG')) {
			if ((name = line.split('"')[1]) && !~events.indexOf(name)) {
				events.push(name);
			}
		} else if (~line.indexOf(namespace_signature) && !~line.indexOf('//') && !~line.indexOf('using')) {
			var ns = line.trim().split(' ')[1].replace('Module','');
			switch (ns) {
				case 'TitaniumWindows':
					ns = 'Titanium';
					break;
				case 'GlobalObject':
					ns = 'Global';
					namespace = [];
					break;
				case 'WindowsXaml':
					ns = 'Windows';
					break;
			}
			namespace.push(ns);
		}
	});
	l.on('error', function (err) {
		console.log('Error : ' + err);
	});
	l.on('end', function () {
		var ns,
			black_list = ['WindowsViewLayoutDelegate', 'TitaniumWindows'];
		namespace.push(module);
		ns = namespace.join('.');
		if (namespace[0] === 'Titanium' && !~namespace.indexOf('Windows') && !~black_list.indexOf(module) && events.length > 0) {
			events_found += events.length;
			if (ns in docs) {
				docs[ns].events = docs[ns].events.concat(events);
			} else {
				docs[ns] = {
					root: root,
					module_name: ns,
					module: module,
					properties: [],
					methods: [],
					events: events
				}
			}
		}
		next();
	});
}


// Extract titanium properties and methods from the class file
function processClass(root, file, next) {

	var module_name = null;
	var namespaces = [];
	var module = null;
	var properties = [];
	var methods = [];

    var l = new lbl(path.join(root, file));
	l.on('line',
		function (line) {
			
			var isProperty = line.contains(property_signature);
			var isPropertyRo = line.contains(property_ro_signature);
			var isMethod = line.contains(method_signature);

			if (isProperty || isPropertyRo || isMethod) {
				if (module == null) {
					if (isProperty) {
						module = line.substr(line.indexOf(property_signature)+property_signature.length).split(',')[0].replace('Module','');
					} else if (isPropertyRo) {
						module = line.substr(line.indexOf(property_ro_signature)+property_ro_signature.length).split(',')[0].replace('Module','');
					} else if (isMethod) {
						module = line.substr(line.indexOf(method_signature)+method_signature.length).split(',')[0].replace('Module','');
					}
				}

				var name = line.split(',')[1].split(')')[0].substring(1);

				if (module_name == null) module_name = namespaces.join('.')+(module != '' ? '.'+module : '');
				if (module_name == 'Titanium.GlobalObject') module_name = 'Global';
				if (module_name == 'Titanium' && module == '') module_name = 'Titanium.Proxy';
				if (module_name == 'Titanium.Ti') module_name = 'Titanium';
				if (module_name == 'Titanium.UI.TwoDMatrix') module_name = 'Titanium.UI.2DMatrix';

				if (isProperty || isPropertyRo) properties.push(name);
				if (isMethod && name[0] != '_') methods.push(name);

			} else if (line.contains(namespace_signature)) {
				var namespace = line.substr(line.indexOf(namespace_signature)+namespace_signature.length).replace('Module','');
				if (namespace.contains(' ')) namespace = namespace.split(' ')[0];
				if (namespace.contains('{')) namespace = namespace.split('{')[0];
				if (!namespace.contains('.') && !namespace.contains(':') && !namespace.contains(';'))
					namespaces.push(namespace);
			}
		}
	);
	l.on('error',
		function (err) {
			console.log('Error : ' + err);
		}
	);
	l.on('end',
		function () {
			properties_found += properties.length;
			methods_found += methods.length;
			if (module != null) {
				if (module == '') module = 'Titanium';
				docs[module_name] = {
					root: root,
					module_name: module_name,
					module: module,
					properties: properties || [],
					methods: methods || [],
					events: []
				}
			}
			next();
		}
	);
}

// Generate a YAML file from the extracted information
function generateYAML(root, module_name, module, properties, methods, events, next) {
	var folder = root.split('/').pop();

	var yaml = 'name: '+module_name+'\n'+
	           'platforms: [windowsphone]\n\n';
	if (properties.length > 0) yaml += 'properties:\n';
	for(i in properties) {
		var property = properties[i];
	    yaml += '  - name: '+property+'\n'+
	            '    platforms: [windowsphone]\n';
	}
	if (methods.length > 0) yaml += 'methods:\n';
	for (i in methods) {
		var method = methods[i];
		yaml += '  - name: '+method+'\n'+
	            '    platforms: [windowsphone]\n';
	}
	if (events.length > 0) yaml += 'events:\n';
	for (i in events) {
		var event = events[i];
		yaml += '  - name: '+event+'\n'+
	            '    platforms: [windowsphone]\n';
	}

	var target = TI_WIN_DOC_DIRECTORY+(folder != 'src' ? '/'+folder+'/' : '/');

	fs.mkdirp(target,
		function (err) {
			if (err) {
				console.log(err);
			} else {
				fs.writeFile(target+module+'.yml', yaml,
					function(err) {
					    if(err) {
					        console.log(err);
					    } else {
					        console.log('Generated '+module+'.yml');
					    	if (next) next();
					    }
					}
				);
			}
		}
	);
}

// Generate whitelist YAML files
function processWhitelist(file, next) {
	var module_name = null;
	var namespaces = [];
	var module = null;
	var properties = [];
	var methods = [];
	var events = [];

    var l = new lbl(file);
	l.on('line',
		function (line) {

			var element = line.split(' '),
				type = element[0];

			// Class
			if (type === 'C') {
				if (module != null) {
					var folder = module_name.substring(module_name.split('.')[0].length+1, module_name.length-module.length-1).replace(/\./g, '/');
					generateYAML(folder, module_name, module+'_white', properties, methods, events);
					module_name = null;
					namespaces = [];
					module = null;
					properties = [];
					methods = [];
					events = [];
				}
				module_name = element[1];
				var split_module = module_name.split('.');
				module = split_module[split_module.length-1];
			
			// Property
			} else if (type === 'P') {
				var name = element[1];
				properties.push(name);

			// Method
			} else if (type === 'M') {
				var name = element[1];
				methods.push(name);

			// Event
			} else if (type === 'E') {
				events.push(element[1]);
			}
		}
	);
	l.on('error',
		function (err) {
			console.log('Error : ' + err);
		}
	);
	l.on('end',
		function () {
			var folder = module_name.substring(module_name.split('.')[0].length+1, module_name.length-module.length-1).replace(/\./g, '/');
			generateYAML(folder, module_name, module+'_white', properties, methods, events, function() {next();});
		}
	);
}
