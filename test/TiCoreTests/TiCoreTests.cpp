#include "TiCore/TiRuntime.h"
#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiValue.h"

#include "TiCore/TiProxy.h"
#include "ExampleProxy.h"

//#include "TiProxy2.h"
//#include "ExampleProxy.h"

#include <JavaScriptCore/JavaScript.h>

#include <string>
#include <iostream>
#include <regex>

#include "gtest/gtest.h"

TEST(TiCoreTests, TiValue) {
	Ti::Value hello_world("Hello, world");
	ASSERT_EQ("Hello, world", hello_world.toString());
}

TEST(TiCoreTests, Proxies) {
	const auto& context = Ti::Runtime::instance();
	
	// Add two proxies to the global object
	// Proxy is the base and ExampleProxy is a subclass
	context.addPropertyToGlobalObject("Proxy", Ti::Proxy::CreateConstructor());
	context.addPropertyToGlobalObject("ExampleProxy", Ti::ExampleProxy::CreateConstructor());
	
	// Create a new object by calling "new" on it, it should return [object ObjectName]
	ASSERT_EQ("[object Proxy]", Ti::evaluateScript("new Proxy()").toString());
	ASSERT_EQ("[object ExampleProxy]", Ti::evaluateScript("new ExampleProxy()").toString());

	// Call a method "testMethod", which returns the argument passed in
	ASSERT_EQ("something", Ti::evaluateScript("new Proxy().testMethod('something')").toString());

	// Call the same method "testMethod" on the subclass, should act the same way
	ASSERT_EQ("something", Ti::evaluateScript("new ExampleProxy().testMethod('something')").toString());
	
	// Call another method, only defined in the sublclass
	ASSERT_TRUE(Ti::evaluateScript("new ExampleProxy().saySomething('something')").toBool());
	

	std::string testString = Ti::evaluateScript("new Proxy().saySomething('something')").toString();
	std::regex regex { "^TypeError:.*" };
	ASSERT_TRUE(std::regex_match(testString, regex));
}

TEST(TiCoreTests, EvaluateScript) {
	auto callback = [] (JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) -> JSValueRef {
		return Ti::Value(arguments, argumentCount).JSValueRef();
	};
	
	const auto& context = Ti::Runtime::instance();
	JSContextRef globalContext = context.globalContext();
	Ti::Value testMethod(JSObjectMakeFunctionWithCallback(globalContext, nullptr, callback));
	context.addPropertyToGlobalObject("testMethod", testMethod);
	
	// Should only return a string
	ASSERT_EQ("[\"hello world\"]"        , Ti::evaluateScript("JSON.stringify(testMethod('hello world'));").toString());
	ASSERT_EQ("[\"hello\",\"world\"]"    , Ti::evaluateScript("JSON.stringify(testMethod('hello','world'));").toString());
	ASSERT_EQ("[[\"hello world\"]]"      , Ti::evaluateScript("JSON.stringify(testMethod(['hello world']));").toString());
	ASSERT_EQ("[[\"hello\"],[\"world\"]]", Ti::evaluateScript("JSON.stringify(testMethod(['hello'], ['world']));").toString());
	ASSERT_EQ("[1,2,3,4,5,6]"            , Ti::evaluateScript("JSON.stringify(testMethod(1,2,3,4,5,6));").toString());
}

TEST(TiCoreTests, Example) {
	const auto& context = Ti::Runtime::instance();
	
	// Create a new object called "testObject" and add some Ti::Values to it.
	std::map<std::string, Ti::Value> testObject;
	
	testObject["number"] = Ti::Value(123.34);
	ASSERT_TRUE(testObject["number"].isNumber());
	ASSERT_DOUBLE_EQ(123.34, testObject["number"].toDouble());
	ASSERT_FALSE(testObject["number"].isArray());
	
	testObject["string"] = Ti::Value("Hello String");
	ASSERT_TRUE(testObject["string"].isString());
	ASSERT_EQ("Hello String", testObject["string"].toString());
	ASSERT_FALSE(testObject["string"].isArray());
	
	testObject["object"] = Ti::Value();
	ASSERT_TRUE(testObject["object"].isObject());
	ASSERT_FALSE(testObject["object"].isArray());
	
	testObject["bool-true"] = Ti::Value(true);
	ASSERT_TRUE(testObject["bool-true"].isBoolean());
	ASSERT_TRUE(testObject["bool-true"].toBool());
	ASSERT_FALSE(testObject["bool-true"].isArray());
	
	testObject["bool-false"] = Ti::Value(false);
	ASSERT_TRUE(testObject["bool-false"].isBoolean());
	ASSERT_FALSE(testObject["bool-false"].toBool());
	ASSERT_FALSE(testObject["bool-false"].isArray());
	
	// Create an array
	std::vector<Ti::Value> testArray;
	testArray.push_back(Ti::Value("hello"));
	testArray.push_back(Ti::Value("world"));
	
	// Add the array to the object
	testObject["array"] = Ti::Value(testArray);
	ASSERT_TRUE(testObject["array"].isArray());
	
	// Create a JavaScript Object from the vector.
	Ti::Value testObject2(testObject);
	ASSERT_TRUE(testObject2.isObject());
	ASSERT_FALSE(testObject2.isArray());
	
	// Add another property to it.
	// We should add operator[] to support this.
	testObject2.setProperty("testing_property", Ti::Value("Hello World!!!!"));
	ASSERT_TRUE(testObject2.getProperty("testing_property").isString());
	ASSERT_EQ("Hello World!!!!", testObject2.getProperty("testing_property").toString());
	
	// Add it to the global object.
	context.addPropertyToGlobalObject("testObject2", testObject2);
	
	// Convert testObject2 to a JSON string.
	auto result = Ti::evaluateScript("JSON.stringify(testObject2)");
	ASSERT_EQ("{\"array\":[\"hello\",\"world\"],\"bool-false\":false,\"bool-true\":true,\"number\":123.34,\"object\":{},\"string\":\"Hello String\",\"testing_property\":\"Hello World!!!!\"}", result.toString());
	
	auto props = testObject2.toDictionary();
	ASSERT_EQ(7, props.size());
	
	auto valueList = Ti::Value(testArray).toVector();
	ASSERT_EQ(2, valueList.size());
	
	Ti::Value testObject3;
	testObject3.setProperty("foo", Ti::Value(true));
	ASSERT_EQ("[object Object]", testObject3.toString());
	ASSERT_TRUE(testObject3.getProperty("foo").isBoolean());
	ASSERT_TRUE(testObject3.getProperty("foo").toBool());
	
	testObject3.setProperty("bar", Ti::Value("hello world"));
	ASSERT_TRUE(testObject3.getProperty("bar").isString());
	ASSERT_EQ("hello world", testObject3.getProperty("bar").toString());
	
	auto testObject3Props = testObject3.toDictionary();
	ASSERT_EQ(2, testObject3Props.size());
}

TEST(TiCoreTests, LoopOfProxiesMethod) {
	const auto& context = Ti::Runtime::instance();

	context.addPropertyToGlobalObject("Proxy", Ti::Proxy::CreateConstructor());
	context.addPropertyToGlobalObject("ExampleProxy", Ti::ExampleProxy::CreateConstructor());
	const char* code =
			"(function(){"
			"   for(var i = 0; i < 10000; i++) {"
			"   	new ExampleProxy();"
			"   }"
			"})();";
	auto result = Ti::evaluateScript(code);
	ASSERT_EQ("undefined", result.toString());

	// clean up
	Ti::Runtime::instance().forceGarbageCollection();
	// Commenting this out for now to remove dependency against WinRT component
	//Ti::Platform::Platform::logStatistics();
}

struct Foo : public Ti::ExampleProxy {
	Foo(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ExampleProxy(name, arguments) {
	}
};
	
TEST(TiCoreTests, postConstruct) {
	std::vector<Ti::Value> empty_arguments_vector;
	Foo foo("Foo", empty_arguments_vector);
	ASSERT_FALSE(foo.get_post_construct_called());
	
	auto example_proxy = Ti::ExampleProxy::create("ExampleProxy", empty_arguments_vector);
	ASSERT_TRUE(example_proxy -> get_post_construct_called());
}

TEST(TiCoreTests, TestCrash) {
	auto& context = Ti::Runtime::instance();
	auto ctx = context.globalContext();
	
	auto globalObject = Ti::Value(context.globalObject());

	// This produces SEGFAULT
	//JSGlobalContextRelease(ctx);

	// Unfortunately, it looks like we can't use Death Tests on OS X
	//due to JavaScriptCore's multithreaded nature. Uncomment this
	//line to see the following output.
	//ASSERT_DEATH(JSGlobalContextRelease(ctx), ".*");

	// 1: Test command: /Users/matt/Documents/Appcelerator/src/Appcelerator/titanium_mobile_windows/test/TiCoreTests/build.debug/TiCoreTests
	// 1: Test timeout computed to be: 9.99988e+06
	// 1: Running main() from gtest_main.cc
	// 1: [==========] Running 1 test from 1 test case.
	// 1: [----------] Global test environment set-up.
	// 1: [----------] 1 test from TiCoreTests
	// 1: [ RUN      ] TiCoreTests.TestCrash
	// 1: TiValue: ctor called (JSValueRef)
	// 1: 
	// 1: [WARNING] /Users/matt/Documents/Appcelerator/src/download/gtest-1.7.0/src/gtest-death-test.cc:825:: Death tests use fork(), which is unsafe particularly in a threaded context. For this test, Google Test detected 11 threads.
	// 1: /Users/matt/Documents/Appcelerator/src/Appcelerator/titanium_mobile_windows/test/TiCoreTests/TiCoreTests.cpp:20: Failure
	// 1: Death test: JSGlobalContextRelease(ctx)
	// 1:     Result: failed to die.
	// 1:  Error msg:
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: TiValue: dtor called
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] The process has forked and you cannot use this CoreFoundation functionality safely. You MUST exec().
	// 1: [  DEATH   ] Break on __THE_PROCESS_HAS_FORKED_AND_YOU_CANNOT_USE_THIS_COREFOUNDATION_FUNCTIONALITY___YOU_MUST_EXEC__() to debug.
	// 1: [  DEATH   ] 
	// 1: [  FAILED  ] TiCoreTests.TestCrash (9 ms)
	// 1: [----------] 1 test from TiCoreTests (9 ms total)
	// 1: 
	// 1: [----------] Global test environment tear-down
	// 1: [==========] 1 test from 1 test case ran. (9 ms total)
	// 1: [  PASSED  ] 0 tests.
	// 1: [  FAILED  ] 1 test, listed below:
	// 1: [  FAILED  ] TiCoreTests.TestCrash
	// 1: 
	// 1:  1 FAILED TEST
	// 1/1 Test #1: TiCoreTests ......................***Failed    0.01 sec
	// 
}
