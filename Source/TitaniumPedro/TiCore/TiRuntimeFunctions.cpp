/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiCore/TiRuntimeFunctions.h"
#include <unordered_map>
#include <fstream>
#include <ostream>
#include <sstream>
#include <memory>
#include "TiCore/TiRuntime.h"

static std::unordered_map <std::string, JSValueRef> js_module_cache;
static std::unordered_map <std::string, JSValueRef> js_internal_module_cache;

namespace Ti {

	std::string readTextFile(const std::string path, bool *success) {
		// if file doesn't exist, return undefined
		std::ifstream ifs(path);
		if (!ifs.is_open()) {
			*success = false;
			return "";
		}
		// load script file
		std::string content;
		std::string line;
		while (!ifs.eof()) {
			std::getline(ifs, line);
			content += line + '\n';
		}
		*success = true;
		return content;
	}
	Value evaluateScript(const std::string& script) {
		return evaluateScriptInObject(script, Ti::Value(Ti::Runtime::instance().globalObject()));
	}

	Value evaluateScriptInObject(const std::string& script, const Value& object) {
		::JSValueRef exceptionValue{ nullptr };
		auto scriptStr = JSStringCreateWithUTF8CString(script.c_str());
		auto result = JSEvaluateScript(Ti::Runtime::instance().globalContext(), scriptStr, object.JSObjectRef(), nullptr, 0, &exceptionValue);
		JSStringRelease(scriptStr);
		if (exceptionValue) {
			auto error = Ti::Value(exceptionValue);
			std::clog << "[ERROR] " << error.toString() << std::endl;
			return error;
		}
		return Ti::Value(result);
	}

	Value evaluateScriptFileInObject(const std::string& path, const Ti::Value& object)
	{
#if defined(__cplusplus_winrt)
		const auto winpath = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
		const auto scriptPath = std::string(winpath->Begin(), winpath->End()) + "/" + path;
		bool success;
		std::string scriptContent = readTextFile(scriptPath, &success);
		if (!success) {
			return Ti::Value::Undefined();
		}
		return Ti::Value(evaluateScriptInObject(scriptContent, object));
#else
		return Ti::Value();
#endif
	}
	//
	// Implementation for 'require'.
	// Loads file from relative path to 'Assets' directory and returns evaluated JS value.
	//
	Value requireJS(const std::string& file)	{
		if (js_module_cache.find(file) != js_module_cache.end()) {
			return Ti::Value(js_module_cache[file]);
		}
#if defined(__cplusplus_winrt)
		// Lookup directly under app installed location. eventually we'll
		// store assets under "Assets"
		const auto winpath = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
		const auto path = std::string(winpath->Begin(), winpath->End()) + "/" + file + ".js";
		bool success;
		std::string scriptContent = readTextFile(path, &success);
		if (!success) {
			return Ti::Value::Undefined();
		}
		const std::string code = "(function(exports){"
			"var __OXP=exports;var module={'exports':exports};"
			"var __filename=\"" + file + "\";\n"
			+ scriptContent + ";\n"
			"if(module.exports !== __OXP){return module.exports;}"
			"return exports;})({})";

		// now evaluate the code
		const Ti::Value result = evaluateScript(code);
		const JSValueRef jsResult = result.JSValueRef();
		// protect evaluated JS value so that we can cache it
		JSValueProtect(Ti::Runtime::instance().globalContext(), jsResult);
		// cache the JS value, to make sure not to evaluate the code again next time
		js_module_cache[file] = jsResult;
		return result;
#else
		return Ti::Value();
#endif
	}

	Value internalRequireJS(const std::string& file)	{
		if (js_internal_module_cache.find(file) != js_internal_module_cache.end()) {
			return Ti::Value(js_internal_module_cache[file]);
		}
#if defined(__cplusplus_winrt)
		// Lookup directly under app installed location. eventually we'll
		// store assets under "Assets"
		const auto winpath = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
		const auto path = std::string(winpath->Begin(), winpath->End()) + "/TitaniumPedro/" + file + ".js";
		bool success;
		std::string scriptContent = readTextFile(path, &success);
		if (!success) {
			return Ti::Value::Undefined();
		}
		const std::string code = "(function(exports){"
			"var __OXP=exports;var module={'exports':exports};"
			"var __filename=\"" + file + "\";\n"
			+ scriptContent + ";\n"
			"if(module.exports !== __OXP){return module.exports;}"
			"return exports;})({})";

		// now evaluate the code
		const Ti::Value result = evaluateScript(code);
		const JSValueRef jsResult = result.JSValueRef();
		// protect evaluated JS value so that we can cache it
		JSValueProtect(Ti::Runtime::instance().globalContext(), jsResult);
		// cache the JS value, to make sure not to evaluate the code again next time
		js_internal_module_cache[file] = jsResult;
		return result;
#else
		return Ti::Value();
#endif
	}

	// Titanium's "require"
	JSValueRef JSModuleRequire(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
		// Get the Ti::Value of the require callback. There should only be one thing in there
		Ti::Value file = Ti::Value(arguments, argumentCount);
		// TODO: Remove or warn?
		if (file.isArray()) {
			// If there happens to be more than one, get the first
			return Ti::requireJS(file.getValueAtIndex(0).toString()).JSValueRef();
		}
		// require this file and return the result
		return Ti::requireJS(file.toString()).JSValueRef();
	}

	JSValueRef JSInternalModuleRequire(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
		// Get the Ti::Value of the require callback. There should only be one thing in there
		auto file = Ti::Value(arguments, argumentCount).toVector();
		return Ti::internalRequireJS(file[0].toString()).JSValueRef();
	}


}	// namespace Ti {
