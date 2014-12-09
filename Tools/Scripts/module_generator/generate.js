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
						   "set(SOURCE_TitaniumKit\n";
	var cmake_add_library = "add_library(TitaniumKit SHARED\n"+
							"  ${SOURCE_"+Name+"}\n";
	var cmake_source_group = "source_group(TitaniumKit                   FILES ${SOURCE_TitaniumKit})\n"+
							 "source_group(TitaniumKit\\"+Name+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" FILES ${SOURCE_"+Name+"})\n";
	var cmake_get_filename_component = "get_filename_component(Global_SOURCE_DIR            ${PROJECT_SOURCE_DIR}/../Global            ABSOLUTE)\n"+
				 					   "get_filename_component("+Name+"_SOURCE_DIR"+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" ${PROJECT_SOURCE_DIR}/../"+Name+((18-Name.length > 0) ? Array(18-Name.length).join(' ') : '')+" ABSOLUTE)\n";
	var cmake_add_subdirectory = "add_subdirectory(${Global_SOURCE_DIR}        ${CMAKE_CURRENT_BINARY_DIR}/Global        EXCLUDE_FROM_ALL)\n"+
				 				 "add_subdirectory(${"+Name+"_SOURCE_DIR}"+((14-Name.length > 0) ? Array(14-Name.length).join(' ') : '')+" ${CMAKE_CURRENT_BINARY_DIR}/"+Name+((14-Name.length > 0) ? Array(14-Name.length).join(' ') : '')+" EXCLUDE_FROM_ALL)\n";
	var cmake_target_link_libraries = "target_link_libraries(TitaniumWindows\n"+
				 					  "  TitaniumWindows_"+Name+"\n";
	var cmake_target_include_directories = "target_include_directories(TitaniumWindows PUBLIC\n"+
				 						   "  $<TARGET_PROPERTY:TitaniumWindows_"+Name+",INTERFACE_INCLUDE_DIRECTORIES>\n";

	// Build and test script modifications
	var build_and_test = "Global_DISABLE_TESTS=ON\"\n"+
						 "cmd+=\" -DTitaniumWindows_"+Name+"_DISABLE_TESTS=ON\"\n";

	// Generate methods and definitions
	for (var method in proxy.methods) {

		// Generate module method definitions
		module_method_definitions += "\tvirtual JSString "+method+"() TITANIUM_NOEXCEPT override final;\n";

		// Generate module methods
		module_methods += "\t// " + proxy.methods[method].summary + "\n"+
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
		module_property_definitions += "virtual JSString "+property+"() const TITANIUM_NOEXCEPT override final;\n"

		// Generate module property methods
		module_property_definitions +=  "\t// " + proxy.properties[property].summary + "\n"+
										"\tJSString "+Name+"::"+property+"() const TITANIUM_NOEXCEPT {\n"+
										"\t\tTITANIUM_LOG_DEBUG(\""+Name+"::"+property+"\");\n"+
										"\t\treturn \"\";\n"+
										"\t}\n";

		// Generate titanium kit property definitions
		kit_property_definitions += "\t\tvirtual JSString "+property+"() const TITANIUM_NOEXCEPT;\n";

		// Generate titanium kit property methods
		kit_property_methods += "\tJSString "+Name+"::"+property+"() const TITANIUM_NOEXCEPT {\n"+
								"\t\treturn \""+Name + "::"+property+": Unimplemented\";\n"+
								"\t}\n";

		// Generate titanium kit property validator definitions
		kit_property_validator_definitions += "\t\tvirtual JSValue "+property+"Validator() const TITANIUM_NOEXCEPT final;\n"

		// Generate titanium kit property validators
		kit_property_validators += "\tJSValue "+Name+"::get"+property+"Validator() const TITANIUM_NOEXCEPT {\n"+
								   "\t\treturn get_context().CreateString("+property+"());\n"+
								   "\t}\n";

		// Generate titanium kit property exports
		kit_add_properties += "\t\tJSExport<"+Name+">::AddValueProperty(\""+property+"\", std::mem_fn(&"+Name+"::"+property+"Validator));\n";
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
								   .replace(/{#NAME#}/g, NAME)
								   .replace(/{#Author#}/g, AUTHOR)
								
								   .replace(/{#MODULE_METHODS#}/g, module_methods)
								   .replace(/{#MODULE_METHOD_DEFINITIONS#}/g, module_method_definitions)

								   .replace(/{#MODULE_PROPERIES#}/g, module_properties)
								   .replace(/{#MODULE_PROPERTY_DEFINITIONS#}/g, module_property_definitions);

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
						data = data.replace(/{#Name#}/g, Name)
								   .replace(/{#NAME#}/g, NAME)
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
								   .replace(/{#KIT_METHOD_VALIDATOR_DEFINITIONS#}/g, kit_method_validator_definitions)
								   
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

										// Modify TitaniumKit CMakeList
										fs.readFile(SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt.bak', 'ascii',
											function(err, data) {
												if (err) throw err;
												
											   // Update Titanium Kit CMake
											   data = data.replace(new RegExp('set\\(SOURCE_TitaniumKit\n','g'), cmake_set_source)
											   .replace(new RegExp('add_library\\(TitaniumKit SHARED\n','g'), cmake_add_library)
											   .replace(new RegExp('source_group\\(TitaniumKit                   FILES \\${SOURCE_TitaniumKit}\\)\n','g'), cmake_source_group);

												// Write file
												filendir.ws(SOURCE_FOLDER + 'TitaniumKit/CMakeLists.txt', data);
											}
										);

										// Modify Titanium CMakeList
										fs.readFile(SOURCE_FOLDER + 'Titanium/CMakeLists.txt.bak', 'ascii',
											function(err, data) {
												if (err) throw err;
												
												// Update Titanium Kit CMake
												data = data.replace(new RegExp('get_filename_component\\(Global_SOURCE_DIR            \\${PROJECT_SOURCE_DIR}/../Global            ABSOLUTE\\)\n','g'), cmake_get_filename_component)
														   .replace(new RegExp('add_subdirectory\\(\\${Global_SOURCE_DIR}        \\${CMAKE_CURRENT_BINARY_DIR}/Global        EXCLUDE_FROM_ALL\\)\n','g'), cmake_add_subdirectory)
														   .replace(new RegExp('target_link_libraries\\(TitaniumWindows\n','g'), cmake_target_link_libraries)
														   .replace(new RegExp('target_include_directories\\(TitaniumWindows PUBLIC\n','g'), cmake_target_include_directories);

												// Write file
												filendir.ws(SOURCE_FOLDER + 'Titanium/CMakeLists.txt', data);
											}
										);

										// Modify Titanium Build and Test
										fs.readFile(SOURCE_FOLDER + 'Titanium/build_and_test.sh.bak', 'ascii',
											function(err, data) {
												if (err) throw err;
												
												// Update Titanium Kit CMake
												data = data.replace(new RegExp('Global_DISABLE_TESTS=ON\"\n','g'), build_and_test);
												
												console.log(data);
												
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
function copyFile(source, target, cb) {
  var cbCalled = false;

  var rd = fs.createReadStream(source);
  rd.on("error", function(err) {
    done(err);
  });
  var wr = fs.createWriteStream(target);
  wr.on("error", function(err) {
    done(err);
  });
  wr.on("close", function(ex) {
    done();
  });
  rd.pipe(wr);

  function done(err) {
    if (!cbCalled) {
      cb(err);
      cbCalled = true;
    }
  }
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
