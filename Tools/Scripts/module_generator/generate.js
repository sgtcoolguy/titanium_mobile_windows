/**
 * Windows Titanium Module Generator
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

var fs = require('fs');
var fields;
try {
	fields = require('fields');
} catch(error) {
	console.log('Installing fields...');
	var child = require('child_process').exec('npm install fields');
}
var filendir;
try {
	filendir = require('filendir')
} catch(error) {
	console.log('Installing filendir...');
	var child = require('child_process').exec('npm install filendir');
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
	var NAME = Name.toUpperCase();
	var name_lower = Name.toLowerCase();

	var module_properties = '', module_property_definitions = '';
	var module_methods = '', module_method_definitions = '';
	var kit_method_validators = '', kit_method_validator_definitions = '';
	var kit_methods = '', kit_method_definitions = '';
	var kit_property_methods = '', kit_property_definitions = '';
	var kit_property_validators = '', kit_property_validator_definitions = '';
	var kit_add_properties = '', kit_add_functions = '';

	// TitaniumKit CMake modifications
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

	// Build and test script modifications
	var build_and_test = "Global_DISABLE_TESTS=ON\"\n"+
						 "cmd+=\" -DTitaniumWindows_"+Name+"_DISABLE_TESTS=ON\"";

	// Generate methods and definitions
	for (var method in proxy.methods) {

		// Generate module method definitions
		module_method_definitions += "\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT override final;\n";

		// Generate module methods
		module_methods += "\t// " + proxy.methods[method].summary.replace(/\n/g, "") + "\n"+
						  "\tJSString "+Name+"::"+method+"() TITANIUM_NOEXCEPT {\n"+
						  "\t\tTITANIUM_LOG_DEBUG(\""+Name+"::"+method+"\");\n"+
						  "\t\treturn \"\";\n"+
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

	for (var property in proxy.properties) {

		// Generate module property definitions
		module_property_definitions += "\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT override final;\n"

		// Generate module property methods
		module_properties +=  "\t// " + proxy.properties[property].summary.replace(/\n/g, "") + "\n"+
										"\tJSString "+Name+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
										"\t\tTITANIUM_LOG_DEBUG(\""+Name+"::get_"+property+"\");\n"+
										"\t\treturn \"\";\n"+
										"\t}\n";

		// Generate titanium kit property definitions
		kit_property_definitions += "\t\tvirtual JSString get_"+property+"() const TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit property methods
		kit_property_methods += "\tJSString "+Name+"::get_"+property+"() const TITANIUM_NOEXCEPT {\n"+
								"\t\treturn \""+Name + "::get_"+property+": Unimplemented\";\n"+
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
						data = data.replace(/{#NAME#}/g, NAME);
						data = data.replace(/{#Author#}/g, AUTHOR);
					
						data = data.replace(/{#MODULE_METHODS#}/g, module_methods);
						data = data.replace(/{#MODULE_METHOD_DEFINITIONS#}/g, module_method_definitions);

						data = data.replace(/{#MODULE_PROPERTIES#}/g, module_properties);
						data = data.replace(/{#MODULE_PROPERTY_DEFINITIONS#}/g, module_property_definitions);

						// Write file
						var filePath = SOURCE_FOLDER + Name + '/' + file.substring(TEMPLATE_FOLDER.length+1).replace(/Module/g, Name);
						filendir.ws(filePath, data);
					}
				);
			}
		);
	});

	// Create TitaniumKit
	walk(KIT_FOLDER, function(error, files) {
		if (error) throw err;

		files.forEach(
			function(file) {
				fs.readFile(file, 'utf8',
					function(err, data) {
						if (err) throw err;
						
						// Process
						data = data.replace(/{#Name#}/g, Name);
						data = data.replace(/{#NAME#}/g, NAME);
						data = data.replace(/{#Author#}/g, AUTHOR);

						data = data.replace(/{#KIT_PROPERTIES#}/g, kit_property_methods);
						data = data.replace(/{#KIT_METHODS#}/g, kit_methods);
						data = data.replace(/{#KIT_VALIDATORS#}/g, kit_method_validators);
						data = data.replace(/{#KIT_PROPERTY_VALIDATORS#}/g, kit_property_validators);
						   
						data = data.replace(/{#ADD_PROPERTIES#}/g, kit_add_properties);
						data = data.replace(/{#ADD_FUNCTIONS#}/g, kit_add_functions);
						   
						data = data.replace(/{#KIT_PROPERTY_DEFINITIONS#}/g, kit_property_definitions);
						data = data.replace(/{#KIT_METHOD_DEFINITIONS#}/g, kit_method_definitions);
						data = data.replace(/{#KIT_PROPERTY_VALIDATOR_DEFINITIONS#}/g, kit_property_validator_definitions);
						data = data.replace(/{#KIT_METHOD_VALIDATOR_DEFINITIONS#}/g, kit_method_validator_definitions);
								   
						// Write file
						var filePath = SOURCE_FOLDER + 'TitaniumKit' + '/' + file.substring(KIT_FOLDER.length+1).replace(/Module/g, Name);
						filendir.ws(filePath, data);
					}
				);
			}
		);
	});

	fs.rename(SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt', SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt.bak',
		function(error) {
			if (error) throw error;

			fs.rename(SOURCE_FOLDER + 'Titanium/CMakeLists.txt', SOURCE_FOLDER + 'Titanium/CMakeLists.txt.bak',
				function(error) {
					if (error) throw error;

								fs.rename(SOURCE_FOLDER + 'Titanium/build_and_test.sh', SOURCE_FOLDER + 'Titanium/build_and_test.sh.bak',
									function(error) {
										if (error) throw error;

										fs.rename(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp', SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp.bak',
											function(error) {
												if (error) throw error;

												fs.rename(SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp', SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp.bak',
													function(error) {
														if (error) throw error;

														fs.rename(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp', SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp.bak',
															function(error) {
																if (error) throw error;

																fs.rename(SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp', SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp.bak',
																	function(error) {
																		if (error) throw error;

																		// Modify TitaniumKit Titanium header
																		fs.readFile(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																			   // Update Titanium Kit header
																			   data = data.replace(/\#include \"Titanium\/GlobalObject.hpp\"/g, kit_header_definition);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/Titanium.hpp', data);
																			}
																		);

																		// Modify TitaniumWindows constructor
																		fs.readFile(SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																				// Update header
																				data = data.replace(/\#include \"TitaniumWindows\/GlobalObject.hpp\"/g, ti_windows_header);

																				// Update TitaniumWindows constructor
																				data = data.replace(/\(JSExport<TitaniumWindows::GlobalObject>::Class\(\)\)\)/g, ti_windows_constructor);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'Titanium/src/TitaniumWindows.cpp', data);
																			}
																		);

																		// Modify TitaniumWindows ApplicationBuilder.hpp
																		fs.readFile(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																				// Update definition
																				data = data.replace(/Application build\(\);/g, app_builder_definition);

																				// Update variable
																				data = data.replace(/global_object_class_ptr__ { nullptr };/g, app_builder_variable);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'TitaniumKit/include/Titanium/ApplicationBuilder.hpp', data);
																			}
																		);

																		// Modify TitaniumWindows ApplicationBuilder.cpp
																		fs.readFile(SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;

																				data = data.replace(/#include \"Titanium\/ApplicationBuilder.hpp\"/g, app_builder_include);
																				
																				// Update definition
																				data = data.replace(/ApplicationBuilder::build\(\) {/g, app_builder_build);

																				// Update variable
																				data = data.replace(/JSObject api/g, app_builder_property);

																				// Update variable
																				data = data.replace(/JSClassPtr_t A/, app_builder_class);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'TitaniumKit/src/ApplicationBuilder.cpp', data);
																			}
																		);

																		// Modify TitaniumKit CMakeList
																		fs.readFile(SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																			   // Update Titanium Kit CMake
																			   data = data.replace(/set\(SOURCE_TitaniumKit/g, cmake_set_source);
																			   data = data.replace(/add_library\(TitaniumKit SHARED/g, cmake_add_library);
																			   data = data.replace(/source_group\(TitaniumKit                   FILES \${SOURCE_TitaniumKit}\)/g, cmake_source_group);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt', data);
																			}
																		);

																		// Modify Titanium CMakeList
																		fs.readFile(SOURCE_FOLDER + 'Titanium/CMakeLists.txt.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																				// Update Titanium Kit CMake
																				data = data.replace(/get_filename_component\(Global_SOURCE_DIR            \${PROJECT_SOURCE_DIR}\/\.\.\/Global            ABSOLUTE\)/g, cmake_get_filename_component);
																				data = data.replace(/add_subdirectory\(\${Global_SOURCE_DIR}        \${CMAKE_CURRENT_BINARY_DIR}\/Global        EXCLUDE_FROM_ALL\)/g, cmake_add_subdirectory);
																				data = data.replace(/target_link_libraries\(TitaniumWindows/g, cmake_target_link_libraries);
																				data = data.replace(/target_include_directories\(TitaniumWindows PUBLIC/g, cmake_target_include_directories);

																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'Titanium/CMakeLists.txt', data);
																			}
																		);

																		// Modify Titanium Build and Test
																		fs.readFile(SOURCE_FOLDER + 'Titanium/build_and_test.sh.bak', 'utf8',
																			function(err, data) {
																				if (err) throw err;
																				
																				// Update Titanium Kit CMake
																				data = data.replace(/Global_DISABLE_TESTS=ON\"/g, build_and_test);
																				
																				// Write file
																				filendir.ws(SOURCE_FOLDER + 'Titanium/build_and_test.sh', data);
																			}
																		);
																	}
																);
															}
														);
													}
												);
											}
										);
									}
								);
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
				return num + opt.value.cyan;
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
				return num + opt.value.cyan;
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
