/**
 * Windows Titanium Module Generator
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

var fs = require('fs');
var path = require('path');
var async;
try {
	async = require('async');
} catch(error) {
	console.log('Node module \'async\' not found, npm install async');
	process.exit();
}
var fields;
try {
	fields = require('fields');
} catch(error) {
	console.log('Node module \'fields\' not found, npm install fields');
	process.exit();
}
var mkdirp;
try {
	mkdirp = require('mkdirp');
} catch(error) {
	console.log('Node module \'mkdirp\' not found, npm install mkdirp');
	process.exit();
}
const AUTHOR = 'Gary Mathews';
const API_FILE = 'API.json';

const TEMPLATE_FOLDER = 'module_template';
const KIT_FOLDER = 'kit_template';
const SOURCE_FOLDER = '../../../Source/';

function generateModule(name, proxy) {
	var name_array = (name+'').split('.');
	name_array.shift();

	var Name = '';
	for (var name in name_array) Name += name_array[name];
	console.log('Generating ' + Name + '...');

	var name_upper = Name.toUpperCase();
	var name_lower = Name.toLowerCase();

	var module_properties = '', module_property_definitions = '';
	var module_methods = '', module_method_definitions = '';
	var kit_method_validators = '', kit_method_validator_definitions = '';
	var kit_methods = '', kit_method_definitions = '';
	var kit_property_methods = '', kit_property_definitions = '';
	var kit_property_validators = '', kit_property_validator_definitions = '';
	var kit_add_properties = '', kit_add_functions = '';

	var cmake_set_source = "set(SOURCE_"+Name+"\n"+
   						   "\tinclude/Titanium/"+Name+".hpp\n"+
   						   "\tsrc/"+Name+".cpp\n"+
   						   ")\n\n"+
						   "set(SOURCE_TitaniumKit";
	var cmake_add_library = "add_library(TitaniumKit SHARED\n"+
							"  ${SOURCE_"+Name+"}";
	var cmake_source_group = "source_group(TitaniumKit                   FILES ${SOURCE_TitaniumKit})\n"+
							 "source_group(TitaniumKit\\\\"+Name+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" FILES ${SOURCE_"+Name+"})";
	var cmake_get_filename_component = "get_filename_component(Global_SOURCE_DIR            ${PROJECT_SOURCE_DIR}/../Global            ABSOLUTE)\n"+
				 					   "get_filename_component("+Name+"_SOURCE_DIR"+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" ${PROJECT_SOURCE_DIR}/../"+Name+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" ABSOLUTE)";
	var cmake_add_subdirectory = "add_subdirectory(${Global_SOURCE_DIR}        ${CMAKE_CURRENT_BINARY_DIR}/Global        EXCLUDE_FROM_ALL)\n"+
				 				 "add_subdirectory(${"+Name+"_SOURCE_DIR}"+((14-Name.length > 0) ? Array(14-Name.length).join(' ') : '')+" ${CMAKE_CURRENT_BINARY_DIR}/"+Name+((14-Name.length > 0) ? Array(14-Name.length).join(' ') : '')+" EXCLUDE_FROM_ALL)";
	var cmake_target_link_libraries = "target_link_libraries(TitaniumWindows\n"+
				 					  "  TitaniumWindows_"+Name;
	var cmake_target_include_directories = "target_include_directories(TitaniumWindows PUBLIC\n"+
				 						   "  $<TARGET_PROPERTY:TitaniumWindows_"+Name+",INTERFACE_INCLUDE_DIRECTORIES>";
	var kit_header_definition = "#include \"Titanium/GlobalObject.hpp\"\n"+
								"#include \"Titanium/"+Name+".hpp\"";
	var ti_windows_header = "#include \"TitaniumWindows/GlobalObject.hpp\"\n"+
							"#include \"TitaniumWindows/"+Name+".hpp\"";
	var ti_windows_constructor = "(JSExport<TitaniumWindows::GlobalObject>::Class()))\n"+
								 "\t."+Name+"Class(std::make_shared<JSClass>(JSExport<TitaniumWindows::"+Name+">::Class()))";
	var app_builder_definition = "Application build();\n\n"+
								 "    JSClassPtr_t        "+Name+"Class() const                 TITANIUM_NOEXCEPT;\n"+
    							 "    ApplicationBuilder& "+Name+"Class(const JSClassPtr_t&)    TITANIUM_NOEXCEPT;";
	var app_builder_variable = "global_object_class_ptr__ { nullptr };\n"+
							   "    JSClassPtr_t   "+name_lower+"_class_ptr__           { nullptr };";
	var app_builder_include = "#include \"Titanium/ApplicationBuilder.hpp\"\n"+
							  "#include \"Titanium/"+Name+".hpp\"";
	var app_builder_build = "ApplicationBuilder::build() {\n\n"+
							"    if (!"+name_lower+"_class_ptr__) {\n"+
							"      "+name_lower+"_class_ptr__ = std::make_shared<JSClass>(JSExport<Titanium::"+Name+">::Class());\n"+
    						"    }";
	var app_builder_property = "JSObject "+name_lower+" = js_context__.CreateObject(*"+name_lower+"_class_ptr__);\n"+
    						   "    titanium.SetProperty(\""+Name+"\", "+name_lower+", {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});\n\n"+
    						   "    JSObject api";
    var app_builder_class = "JSClassPtr_t ApplicationBuilder::"+Name+"Class() const TITANIUM_NOEXCEPT {\n"+
							"    return "+name_lower+"_class_ptr__;\n"+
							"  }\n"+
							"  ApplicationBuilder& ApplicationBuilder::"+Name+"Class(const JSClassPtr_t& "+name_lower+"_class_ptr) TITANIUM_NOEXCEPT {\n"+
							"    "+name_lower+"_class_ptr__ = "+name_lower+"_class_ptr;\n"+
							"    return *this;\n"+
							"  }\n\n"+
    						"  JSClassPtr_t A";
	var build_and_test = "Global_DISABLE_TESTS=ON\"\n"+
						 "cmd+=\" -DTitaniumWindows_"+Name+"_DISABLE_TESTS=ON\"";

	// Generate methods and definitions
	for (var method in proxy.methods) {

		// Generate module method definitions
		module_method_definitions += "\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT override final;\n";

		// Generate module methods
		module_methods += "\t// " + proxy.methods[method].summary.replace(/\n/g, "") + "\n"+
						  "\tJSString "+Name+"::"+method+"() TITANIUM_NOEXCEPT {\n"+
						  "\t\tTITANIUM_LOG_DEBUG(\""+Name+"::"+method+" Unimplemented\");\n"+
						  "\t\treturn \""+Name+"::"+method+" Unimplemented\";\n"+
						  "\t}\n";

		// Generate titanium kit method definitions
		kit_method_definitions += "\t\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit method validator definitions
		kit_method_validator_definitions += "\t\tvirtual JSValue "+method+"ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;\n";

		// Generate titanium kit method validators
		kit_method_validators += "\tJSValue "+Name+"::"+method+"ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {\n";
		kit_method_validators += "\t\treturn get_context().CreateString("+method+"());\n";
		kit_method_validators += "\t}\n";

		// Generate titanium kit function exports
		kit_add_functions += "\t\tJSExport<"+Name+">::AddFunctionProperty(\""+method+"\", std::mem_fn(&"+Name+"::"+method+"ArgumentValidator));\n";
	}
	kit_methods = module_methods;

	// Generate properties and definitions
	for (var property in proxy.properties) {

		// Generate module property definitions
		module_property_definitions += "\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT override final;\n"

		// Generate module property methods
		module_properties += "\t// " + proxy.properties[property].summary.replace(/\n/g, "") + "\n"+
							 "\tJSString "+Name+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
							 "\t\tTITANIUM_LOG_DEBUG(\""+Name+"::get_"+property+" Unimplemented\");\n"+
							 "\t\treturn \""+Name + "::get_"+property+": Unimplemented\";\n"+
							 "\t}\n";

		// Generate titanium kit property definitions
		kit_property_definitions += "\t\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit property methods
		kit_property_methods += "\t// " + proxy.properties[property].summary.replace(/\n/g, "") + "\n"+
								"\tJSString "+Name+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
								"\t\treturn \"\";\n"+
								"\t}\n";

		// Generate titanium kit property validator definitions
		kit_property_validator_definitions += "\t\tvirtual JSValue get_"+property+"Validator() const TITANIUM_NOEXCEPT final;\n"

		// Generate titanium kit property validators
		kit_property_validators += "\tJSValue "+Name+"::get_"+property+"Validator() const TITANIUM_NOEXCEPT {\n"+
								   "\t\treturn get_context().CreateString(get_"+property+"());\n"+
								   "\t}\n";

		// Generate titanium kit property exports
		kit_add_properties += "\t\tJSExport<"+Name+">::AddValueProperty(\""+property+"\", std::mem_fn(&"+Name+"::get_"+property+"Validator));\n";
	}

	// Create Module
	walk(TEMPLATE_FOLDER, function(error, files) {
		if (error) throw err;

		files.forEach(
			function(file) {
				fs.readFile(file, 'utf8',
					function(err, data) {
						if (err) throw err;
						
						// Process
						data = data.replace(/{#Name#}/g, Name)
						.replace(/{#NAME#}/g, name_upper)
						.replace(/{#Author#}/g, AUTHOR)
					
						.replace(/{#MODULE_METHODS#}/g, module_methods)
						.replace(/{#MODULE_METHOD_DEFINITIONS#}/g, module_method_definitions)

						.replace(/{#MODULE_PROPERTIES#}/g, module_properties)
						.replace(/{#MODULE_PROPERTY_DEFINITIONS#}/g, module_property_definitions);

						// Write file
						var filePath = SOURCE_FOLDER + Name + '/' + file.substring(TEMPLATE_FOLDER.length+1).replace(/Module/g, Name);
						writeFile(filePath, data);
					}
				);
			}
		);
	});

	// Create TitaniumKit files
	walk(KIT_FOLDER, function(error, files) {
		if (error) throw err;

		files.forEach(
			function(file) {
				fs.readFile(file, 'utf8',
					function(err, data) {
						if (err) throw err;
						
						// Process
						data = data.replace(/{#Name#}/g, Name)
						.replace(/{#NAME#}/g, name_upper)
						.replace(/{#Author#}/g, AUTHOR)

						.replace(/{#KIT_PROPERTIES#}/g, kit_property_methods)
						.replace(/{#KIT_METHODS#}/g, kit_methods)
						.replace(/{#KIT_VALIDATORS#}/g, kit_method_validators)
						.replace(/{#KIT_PROPERTY_VALIDATORS#}/g, kit_property_validators)
						   
						.replace(/{#ADD_PROPERTIES#}/g, kit_add_properties)
						.replace(/{#ADD_FUNCTIONS#}/g, kit_add_functions)
						   
						.replace(/{#KIT_PROPERTY_DEFINITIONS#}/g, kit_property_definitions)
						.replace(/{#KIT_METHOD_DEFINITIONS#}/g, kit_method_definitions)
						.replace(/{#KIT_PROPERTY_VALIDATOR_DEFINITIONS#}/g, kit_property_validator_definitions)
						.replace(/{#KIT_METHOD_VALIDATOR_DEFINITIONS#}/g, kit_method_validator_definitions);
								   
						// Write file
						var filePath = SOURCE_FOLDER + 'TitaniumKit' + '/' + file.substring(KIT_FOLDER.length+1).replace(/Module/g, Name);
						writeFile(filePath, data);
					}
				);
			}
		);
	});

	var kit_cmakelists_file = SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt';
	var ti_cmakelists_file = SOURCE_FOLDER + 'Titanium/CMakeLists.txt';
	var ti_build_test_file = SOURCE_FOLDER + 'Titanium/build_and_test.sh';
	var kit_titanium_header_file = SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp';
	var ti_titanium_windows_cpp_file = SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp';
	var kit_application_builder_header_file = SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp';
	var kit_application_builder_cpp_file = SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp';

	function asyncRenameFile(source, destination) {
		return function(next) {
			fs.rename(source, destination,
				function(error) {
					if (error) throw error;
					next();
				}
			);
		}
	}

	var asyncTasks = [];
	asyncTasks.push(asyncRenameFile(kit_cmakelists_file, kit_cmakelists_file + ".bak"));
	asyncTasks.push(asyncRenameFile(ti_cmakelists_file, ti_cmakelists_file + ".bak"));
	asyncTasks.push(asyncRenameFile(ti_build_test_file, ti_build_test_file + ".bak"));
	asyncTasks.push(asyncRenameFile(kit_titanium_header_file, kit_titanium_header_file + ".bak"));
	asyncTasks.push(asyncRenameFile(ti_titanium_windows_cpp_file, ti_titanium_windows_cpp_file + ".bak"));
	asyncTasks.push(asyncRenameFile(kit_application_builder_header_file, kit_application_builder_header_file + ".bak"));
	asyncTasks.push(asyncRenameFile(kit_application_builder_cpp_file, kit_application_builder_cpp_file + ".bak"));
	async.parallel(asyncTasks,
		function(error) {
			if (error) throw error;

			// Modify TitaniumKit Titanium header
			fs.readFile(kit_titanium_header_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
				   // Update Titanium Kit header
				   data = data.replace(/\#include \"Titanium\/GlobalObject.hpp\"/g, kit_header_definition);

					// Write file
					writeFile(kit_titanium_header_file, data);
				}
			);

			// Modify TitaniumWindows constructor
			fs.readFile(ti_titanium_windows_cpp_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update header
					data = data.replace(/\#include \"TitaniumWindows\/GlobalObject.hpp\"/g, ti_windows_header)

					// Update TitaniumWindows constructor
					.replace(/\(JSExport<TitaniumWindows::GlobalObject>::Class\(\)\)\)/g, ti_windows_constructor);

					// Write file
					writeFile(ti_titanium_windows_cpp_file, data);
				}
			);

			// Modify TitaniumWindows ApplicationBuilder.hpp
			fs.readFile(kit_application_builder_header_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update definition
					data = data.replace(/Application build\(\);/g, app_builder_definition)

					// Update variable
					.replace(/global_object_class_ptr__ { nullptr };/g, app_builder_variable);

					// Write file
					writeFile(kit_application_builder_header_file, data);
				}
			);

			// Modify TitaniumWindows ApplicationBuilder.cpp
			fs.readFile(kit_application_builder_cpp_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;

					data = data.replace(/#include \"Titanium\/ApplicationBuilder.hpp\"/g, app_builder_include)
					
					// Update definition
					.replace(/ApplicationBuilder::build\(\) {/g, app_builder_build)

					// Update variable
					.replace(/JSObject api/g, app_builder_property)

					// Update variable
					.replace(/JSClassPtr_t A/, app_builder_class);

					// Write file
					writeFile(kit_application_builder_cpp_file, data);
				}
			);

			// Modify TitaniumKit CMakeList
			fs.readFile(kit_cmakelists_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
				   // Update Titanium Kit CMake
				   data = data.replace(/set\(SOURCE_TitaniumKit/g, cmake_set_source)
				   .replace(/add_library\(TitaniumKit SHARED/g, cmake_add_library)
				   .replace(/source_group\(TitaniumKit                   FILES \${SOURCE_TitaniumKit}\)/g, cmake_source_group);

					// Write file
					writeFile(kit_cmakelists_file, data);
				}
			);

			// Modify Titanium CMakeList
			fs.readFile(ti_cmakelists_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update Titanium Kit CMake
					data = data.replace(/get_filename_component\(Global_SOURCE_DIR            \${PROJECT_SOURCE_DIR}\/\.\.\/Global            ABSOLUTE\)/g, cmake_get_filename_component)
					.replace(/add_subdirectory\(\${Global_SOURCE_DIR}        \${CMAKE_CURRENT_BINARY_DIR}\/Global        EXCLUDE_FROM_ALL\)/g, cmake_add_subdirectory)
					.replace(/target_link_libraries\(TitaniumWindows/g, cmake_target_link_libraries)
					.replace(/target_include_directories\(TitaniumWindows PUBLIC/g, cmake_target_include_directories);

					// Write file
					writeFile(ti_cmakelists_file, data);
				}
			);

			// Modify Titanium Build and Test
			fs.readFile(ti_build_test_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update Titanium Kit CMake
					data = data.replace(/Global_DISABLE_TESTS=ON\"/g, build_and_test);
					
					// Write file
					writeFile(ti_build_test_file, data);
				}
			);
		}
	);
}
function sortByKey(array, key) {
    return array.sort(
    	function(a, b) {
        	var x = a[key]; var y = b[key];
        	return ((x < y) ? -1 : ((x > y) ? 1 : 0));
    	}
    );
}

var api = JSON.parse(fs.readFileSync(API_FILE));
selectModule();
function selectModule() {
	var moduleSelector = fields.select({
		title: 'Select Module',
		formatters: {
			option: function (opt, idx, num) {
				return num + opt.value.white;
			}
		},
		numbered: true,
		complete: true,
		suggest: true,
		options: {
			'Modules : ': (function(){
				var options = [];
				for(var key in api) {
					options.push({value: key})
				}
				return sortByKey(options, 'value');
			})()
		}
	});
	fields.set([
		moduleSelector
	]).prompt(function (err, value) {
		if (err) {
			process.stdout.write('\n');
			process.exit(0);
		} else {
			selectProxy(value);
		}
	});
}
function selectProxy(_proxy) {
	var moduleSelector = fields.select({
		title: 'Select Proxy',
		formatters: {
			option: function (opt, idx, num) {
				return num + opt.value.white;
			}
		},
		numbered: true,
		complete: true,
		suggest: true,
		options: {
			'Proxies : ': (function(){
				var options = [];
				for(var key in api[_proxy]) {
					options.push({value: key})
				}
				return sortByKey(options, 'value');
			})()
		}
	});
	fields.set([moduleSelector]).prompt(
		function (err, value) {
			if (err) {
				process.stdout.write('\n');
				process.exit(0);
			} else {
				generateModule(value, api[_proxy][value]);
			}
		}
	);
}
var walk = function(dir, callback) {
	var results = [];
	fs.readdir(dir, function(err, list) {
		if (err) return callback(err);
		var pending = list.length;
		if (!pending) return callback(null, results);
		list.forEach(function(file) {
			file = dir + '/' + file;
			fs.stat(file, function(err, stat) {
				if (stat && stat.isDirectory()) {
					walk(file, function(err, res) {
						results = results.concat(res);
						if (!--pending) callback(null, results);
					});
				} else {
					results.push(file);
					if (!--pending) callback(null, results);
				}
			});
		});
	});
};
function mkdir(dirname, cb) {
	if (cb) {
		mkdirp(dirname, cb);
	} else {
		try { 
			mkdirp.sync(dirname);
			return true;
		} catch(e) { 
			console.error(e.message);
			return false;
		}
	}
}
function writeFile(filename, content) {
	mkdir(path.dirname(filename));
	try {
		fs.writeFileSync(filename, content, {flags : 'w'});
		return true;
	} catch(e) {
		console.error(e.message);
		return false;
	}
}
