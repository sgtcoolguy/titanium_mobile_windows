/**
 * Windows Titanium Module Generator
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

var fs = require('fs.extra');
var path = require('path');
var async = require('async');
var fields = require('fields');

const AUTHOR = 'Gary Mathews';
const API_FILE = 'API.json';

const MODULE_FOLDER = 'module_template';
const SUB_CLASS_FOLDER = 'sub_class_template';
const SOURCE_FOLDER = '../../../Source/';

function generateModule(name, proxy) {
	var name_array = (name+'').split('.');
	name_array.shift();

	var module_name = null, sub_class_name = null, sub_class_name_upper = null, sub_class_name_lower;

	module_name = name_array[0];
	if (name_array.length > 1) {
		sub_class_name = name_array[1];
		sub_class_name_upper = sub_class_name.toUpperCase();
		sub_class_name_lower = sub_class_name.toLowerCase();
	}

	var module_name_upper = module_name.toUpperCase();
	var module_name_lower = module_name.toLowerCase();

	var class_name = (sub_class_name == null ? module_name : sub_class_name);
	var class_name_lower = class_name.toLowerCase();

	var namespace = (sub_class_name == null ? module_name+'Module' : sub_class_name);

	console.log('Generating Titanium.' + module_name + (sub_class_name != null ? '.'+sub_class_name : '') + '...\n');

	var module_properties = '', module_property_definitions = '';
	var module_methods = '', module_method_definitions = '';
	var kit_method_validators = '', kit_method_validator_definitions = '';
	var kit_methods = '', kit_method_definitions = '';
	var kit_property_methods = '', kit_property_definitions = '';
	var kit_property_validators = '', kit_property_validator_definitions = '';
	var kit_add_properties = '', kit_add_functions = '';

	var cmake_set_source = "set(SOURCE_"+module_name+"\n"+
   						   "\tinclude/Titanium/"+module_name+".hpp\n"+
   						   "\tsrc/"+module_name+".cpp\n"+
   						   ")\n\n"+
						   "set(SOURCE_TitaniumKit";
	var cmake_add_library = "add_library(TitaniumKit SHARED\n"+
							"  ${SOURCE_"+module_name+"}";
	var cmake_source_group = "source_group(TitaniumKit                   FILES ${SOURCE_TitaniumKit})\n"+
							 "source_group(TitaniumKit\\\\"+module_name+((18-module_name.length > 0) ? Array(18-module_name.length).join(' ') : '')+" FILES ${SOURCE_"+module_name+"})";
	var cmake_get_filename_component = "get_filename_component(Global_SOURCE_DIR            ${PROJECT_SOURCE_DIR}/../Global            ABSOLUTE)\n"+
				 					   "get_filename_component("+module_name+"_SOURCE_DIR"+((18-module_name.length > 0) ? Array(18-module_name.length).join(' ') : '')+" ${PROJECT_SOURCE_DIR}/../"+module_name+((18-module_name.length > 0) ? Array(18-module_name.length).join(' ') : '')+" ABSOLUTE)";
	var cmake_add_subdirectory = "add_subdirectory(${Global_SOURCE_DIR}        ${CMAKE_CURRENT_BINARY_DIR}/Global        EXCLUDE_FROM_ALL)\n"+
				 				 "add_subdirectory(${"+module_name+"_SOURCE_DIR}"+((14-module_name.length > 0) ? Array(14-module_name.length).join(' ') : '')+" ${CMAKE_CURRENT_BINARY_DIR}/"+module_name+((14-module_name.length > 0) ? Array(14-module_name.length).join(' ') : '')+" EXCLUDE_FROM_ALL)";
	var cmake_target_link_libraries = "target_link_libraries(TitaniumWindows\n"+
				 					  "  TitaniumWindows_"+module_name;
	var cmake_target_include_directories = "target_include_directories(TitaniumWindows PUBLIC\n"+
				 						   "  $<TARGET_PROPERTY:TitaniumWindows_"+module_name+",INTERFACE_INCLUDE_DIRECTORIES>";
	var kit_header_definition = "#include \"Titanium/GlobalObject.hpp\"\n"+
								"#include \"Titanium/"+module_name+".hpp\"";
	var ti_windows_header = "#include \"TitaniumWindows/GlobalObject.hpp\"\n"+
							"#include \"TitaniumWindows/"+class_name+".hpp\"";

	var ti_windows_constructor = "t<TitaniumWindows::API>())\n"+
								 "\t."+class_name+"Object(js_context__.CreateObject<TitaniumWindows::"+(sub_class_name == null ? namespace : (module_name+'::'+namespace))+">())";
	var app_builder_definition = "Application build();\n\n"+
								 "    JSObject        "+class_name+"Object() const                 TITANIUM_NOEXCEPT;\n"+
    							 "    ApplicationBuilder& "+class_name+"Object(const JSObject&)    TITANIUM_NOEXCEPT;";
	var app_builder_variable = "JSObject  api__;\n"+
							   "    JSObject  "+class_name_lower+"__;";
	var app_builder_include = "#include \"Titanium/ApplicationBuilder.hpp\"\n"+
							  "#include \"Titanium/"+module_name+".hpp\"";
	var app_builder_build = "CreateObject<Titanium::API>())\n"+
							"  , "+module_name_lower+"__(js_context__.CreateObject<Titanium::"+(sub_class_name == null ? namespace : (module_name+'::'+namespace))+">())";
	var app_builder_property = "api__          , {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});\n"+
    						   "    titanium.SetProperty(\""+module_name+"\"           , "+module_name_lower+"__             , {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});";
    
    var app_builder_class = "  JSObject ApplicationBuilder::"+class_name+"Object() const TITANIUM_NOEXCEPT {\n"+
							"    return "+class_name_lower+"__;\n"+
							"  }\n\n"+
							"  ApplicationBuilder& ApplicationBuilder::"+class_name+"Object(const JSObject& "+class_name_lower+") TITANIUM_NOEXCEPT {\n"+
							"    "+class_name_lower+"__ = "+class_name_lower+";\n"+
							"    return *this;\n"+
							"  }\n\n"+
    						"  JSObject ApplicationBuilder::APIObject";

	var build_and_test = "Global_DISABLE_TESTS=ON\"\n"+
						 "cmd+=\" -DTitaniumWindows_"+module_name+"_DISABLE_TESTS=ON\"";
	var module_cmake_source = "set(SOURCE_"+module_name+"\n"+
							  "  include/TitaniumWindows/"+sub_class_name+".hpp\n"+
							  "  src/"+sub_class_name+".cpp";
	var kit_cmake_source = "set(SOURCE_"+module_name+"\n"+
						   "  include/Titanium/"+module_name+"/"+sub_class_name+".hpp\n"+
						   "  src/"+module_name+"/"+sub_class_name+".cpp";
	var kit_module_header_definition = "Module.hpp\"\n"+
									   "#include \"Titanium/"+module_name+"/"+sub_class_name+".hpp\"";

	var module_header_definition = module_name_lower+", {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});\n"+
								   "    "+module_name_lower+".SetProperty(\""+sub_class_name+"\", js_context__.CreateObject(*"+class_name_lower+"_class_ptr__));";

	// Generate methods and definitions
	for (var method in proxy.methods) {

		// Generate module method definitions
		module_method_definitions += "\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT override final;\n";

		// Generate module methods
		module_methods += "\t// " + proxy.methods[method].summary.replace(/\n/g, "") + "\n"+
						  "\tJSString "+namespace+"::"+method+"() TITANIUM_NOEXCEPT {\n"+
						  "\t\tTITANIUM_LOG_DEBUG(\""+namespace+"::"+method+" Unimplemented\");\n"+
						  "\t\treturn \""+namespace+"::"+method+" Unimplemented\";\n"+
						  "\t}\n";

		// Generate titanium kit method definitions
		kit_method_definitions += "\t\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit method validator definitions
		kit_method_validator_definitions += "\t\tvirtual JSValue "+method+"ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT final;\n";

		// Generate titanium kit method validators
		kit_method_validators += "\tJSValue "+namespace+"::"+method+"ArgumentValidator(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT {\n";
		kit_method_validators += "\t\treturn get_context().CreateString("+method+"());\n";
		kit_method_validators += "\t}\n";

		// Generate titanium kit function exports
		kit_add_functions += "\t\tJSExport<"+namespace+">::AddFunctionProperty(\""+method+"\", std::mem_fn(&"+namespace+"::"+method+"ArgumentValidator));\n";
	}
	kit_methods = module_methods;

	// Generate properties and definitions
	for (var property in proxy.properties) {

		// Generate module property definitions
		module_property_definitions += "\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT override final;\n"

		// Generate module property methods
		module_properties += "\t// " + proxy.properties[property].summary.replace(/\n/g, "") + "\n"+
							 "\tJSString "+namespace+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
							 "\t\tTITANIUM_LOG_DEBUG(\""+namespace+"::get_"+property+" Unimplemented\");\n"+
							 "\t\treturn \""+namespace+"::get_"+property+": Unimplemented\";\n"+
							 "\t}\n";

		// Generate titanium kit property definitions
		kit_property_definitions += "\t\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit property methods
		kit_property_methods += "\t// " + proxy.properties[property].summary.replace(/\n/g, "") + "\n"+
								"\tJSString "+namespace+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
								"\t\treturn \"\";\n"+
								"\t}\n";

		// Generate titanium kit property validator definitions
		kit_property_validator_definitions += "\t\tvirtual JSValue get_"+property+"Validator() const TITANIUM_NOEXCEPT final;\n"

		// Generate titanium kit property validators
		kit_property_validators += "\tJSValue "+namespace+"::get_"+property+"Validator() const TITANIUM_NOEXCEPT {\n"+
								   "\t\treturn get_context().CreateString(get_"+property+"());\n"+
								   "\t}\n";

		// Generate titanium kit property exports
		kit_add_properties += "\t\tJSExport<"+namespace+">::AddValueProperty(\""+property+"\", std::mem_fn(&"+namespace+"::get_"+property+"Validator));\n";
	}

	// Create module if not sub class
	if (sub_class_name == null) {

		// Create Module files
		fs.walk(MODULE_FOLDER).on("file", function(root, stat, next) {
			
			var file = path.join(root, stat.name);

			fs.readFile(file, 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Process
					data = data.replace(/{#Module#}/g, module_name)
					.replace(/{#MODULE#}/g, module_name_upper)
					.replace(/{#ModuleName#}/g, namespace)
					.replace(/{#Author#}/g, AUTHOR)

					.replace(/{#MODULE_METHODS#}/g, module_methods)
					.replace(/{#MODULE_METHOD_DEFINITIONS#}/g, module_method_definitions)

					.replace(/{#MODULE_PROPERTIES#}/g, module_properties)
					.replace(/{#MODULE_PROPERTY_DEFINITIONS#}/g, module_property_definitions)

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
					var filePath = SOURCE_FOLDER + file.substring(MODULE_FOLDER.length+1).replace(/Module/g, module_name);
					console.log('Creating ' + filePath);
					writeFile(filePath, data);
					next();
				}
			);
		});

	} else {

		// Creates sub class files
		fs.walk(SUB_CLASS_FOLDER).on("file", function(root, stat, next) {
			var file = path.join(root, stat.name);
			fs.readFile(file, 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Process
					data = data.replace(/{#Module#}/g, module_name)
					.replace(/{#MODULE#}/g, module_name_upper)
					.replace(/{#SubClass#}/g, sub_class_name)
					.replace(/{#subclass#}/g, sub_class_name_lower)
					.replace(/{#SUBCLASS#}/g, sub_class_name_upper)
					.replace(/{#Author#}/g, AUTHOR)

					.replace(/{#MODULE_METHODS#}/g, module_methods)
					.replace(/{#MODULE_METHOD_DEFINITIONS#}/g, module_method_definitions)

					.replace(/{#MODULE_PROPERTIES#}/g, module_properties)
					.replace(/{#MODULE_PROPERTY_DEFINITIONS#}/g, module_property_definitions)

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
					var filePath = SOURCE_FOLDER + file.substring(SUB_CLASS_FOLDER.length+1).replace(/Module/g, module_name).replace(/SubClass/g, sub_class_name);
					console.log('Creating ' + filePath);
					writeFile(filePath, data);
					next();
				}
			);
		});
	}

	var kit_cmakelists_file = SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt';
	var ti_cmakelists_file = SOURCE_FOLDER + 'Titanium/CMakeLists.txt';
	var ti_build_test_file = SOURCE_FOLDER + 'Titanium/build_and_test.sh';
	var kit_titanium_header_file = SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp';
	var ti_titanium_windows_cpp_file = SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp';
	var kit_application_builder_header_file = SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp';
	var kit_application_builder_cpp_file = SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp';
	var kit_module_header_file = SOURCE_FOLDER + 'TitaniumKit/include/Titanium/'+module_name+'.hpp';
	var module_cmakelists_file = SOURCE_FOLDER + module_name + '/CMakeLists.txt';

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

	if (sub_class_name == null) {
		asyncTasks.push(asyncRenameFile(kit_cmakelists_file, kit_cmakelists_file + ".bak"));
		asyncTasks.push(asyncRenameFile(ti_cmakelists_file, ti_cmakelists_file + ".bak"));
		asyncTasks.push(asyncRenameFile(ti_build_test_file, ti_build_test_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_titanium_header_file, kit_titanium_header_file + ".bak"));
		asyncTasks.push(asyncRenameFile(ti_titanium_windows_cpp_file, ti_titanium_windows_cpp_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_application_builder_header_file, kit_application_builder_header_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_application_builder_cpp_file, kit_application_builder_cpp_file + ".bak"));
	} else {
		asyncTasks.push(asyncRenameFile(module_cmakelists_file, module_cmakelists_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_cmakelists_file, kit_cmakelists_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_module_header_file, kit_module_header_file + ".bak"));
		asyncTasks.push(asyncRenameFile(ti_titanium_windows_cpp_file, ti_titanium_windows_cpp_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_application_builder_header_file, kit_application_builder_header_file + ".bak"));
		asyncTasks.push(asyncRenameFile(kit_application_builder_cpp_file, kit_application_builder_cpp_file + ".bak"));
	}

	async.parallel(asyncTasks,
		function(error) {
			if (error) throw error;

			// Modify TitaniumWindows ApplicationBuilder.hpp
			fs.readFile(kit_application_builder_header_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update definition
					data = data.replace(/Application build\(\);/g, app_builder_definition)

					// Update variable
					.replace(/JSObject  api__;/g, app_builder_variable);

					console.log('Patching ' + kit_application_builder_header_file);

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
					.replace(/CreateObject<Titanium::API>\(\)\)/g, app_builder_build)

					// Update variable
					.replace(/  JSObject ApplicationBuilder::APIObject/, app_builder_class);

					if (sub_class_name != null) {
						data = data.replace(new RegExp(module_name_lower+", {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete}\\);", "g"), module_header_definition);
					} else {
						data = data.replace(/api__          , {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete}\);/g, app_builder_property);
					}

					console.log('Patching ' + kit_application_builder_cpp_file);

					// Write file
					writeFile(kit_application_builder_cpp_file, data);
				}
			);

			// Modify TitaniumWindows constructor
			fs.readFile(ti_titanium_windows_cpp_file + ".bak", 'utf8',
				function(err, data) {
					if (err) throw err;
					
					// Update header
					data = data.replace(/\#include \"TitaniumWindows\/GlobalObject.hpp\"/g, ti_windows_header)

					// Update TitaniumWindows constructor
					.replace(/t<TitaniumWindows::API>\(\)\)/g, ti_windows_constructor);

					console.log('Patching ' + ti_titanium_windows_cpp_file);

					// Write file
					writeFile(ti_titanium_windows_cpp_file, data);
				}
			);

			// Module
			if (sub_class_name == null) {

				// Modify TitaniumKit Titanium header
				fs.readFile(kit_titanium_header_file + ".bak", 'utf8',
					function(err, data) {
						if (err) throw err;
						
						// Update Titanium Kit header
						data = data.replace(/\#include \"Titanium\/GlobalObject.hpp\"/g, kit_header_definition);

						console.log('Patching ' + kit_titanium_header_file);

						// Write file
						writeFile(kit_titanium_header_file, data);
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

					   console.log('Patching ' + kit_cmakelists_file);

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

						console.log('Patching ' + ti_cmakelists_file);

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

						console.log('Patching ' + ti_build_test_file);
						
						// Write file
						writeFile(ti_build_test_file, data);
					}
				);

			// Sub Class
			} else {

				// Modify Module CMakeLists.txt
				fs.readFile(module_cmakelists_file + ".bak", 'utf8',
					function(err, data) {
						if (err) throw err;

						data = data.replace(new RegExp("set\\(SOURCE_"+module_name,"g"), module_cmake_source);

						console.log('Patching ' + module_cmakelists_file);
						
						// Write file
						writeFile(module_cmakelists_file, data);
					}
				);

				// Modify Titanium Kit CMakeLists.txt
				fs.readFile(kit_cmakelists_file + ".bak", 'utf8',
					function(err, data) {
						if (err) throw err;
						
						// Update Titanium Kit CMake
						data = data.replace(new RegExp("set\\(SOURCE_"+module_name, "g"), kit_cmake_source);

						console.log('Patching ' + kit_cmakelists_file);
						
						// Write file
						writeFile(kit_cmakelists_file, data);
					}
				);

				// Modify Titanium Kit Module header
				fs.readFile(kit_module_header_file + ".bak", 'utf8',
					function(err, data) {
						if (err) throw err;

						// Update Titanium Kit CMake
						data = data.replace(/Module.hpp\"/g, kit_module_header_definition);

						console.log('Patching ' + kit_module_header_file);
						
						// Write file
						writeFile(kit_module_header_file, data);
					}
				);

			}
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
function mkdir(dirname, cb) {
	if (cb) {
		fs.mkdirp(dirname, cb);
	} else {
		try { 
			fs.mkdirpSync(dirname);
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
