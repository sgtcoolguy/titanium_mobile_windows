//
//  TiValueTests.m
//  TiValueTests
//
//  Created by Matt Langston on 9/6/14.
//  Copyright (c) 2014 Pedro Enrique. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <regex>

#include "TiCore/TiRuntime.h"
#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiValue.h"

#include "TiProxy.h"
//#include "TiProxy2.h"
#include "ExampleProxy.h"

@interface TiValueTests : XCTestCase
@end

@implementation TiValueTests

- (void)setUp {
  [super setUp];
  // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
  // Put teardown code here. This method is called after the invocation of each test method in the class.
  [super tearDown];
    
  std::cout << "MDL: Ti::Value::ctorCounter = " << Ti::Value::get_ctor_counter() << std::endl;
  std::cout << "MDL: Ti::Value::dtorCounter = " << Ti::Value::get_dtor_counter() << std::endl;
}

-(void)testProxies {
	const auto& context = Ti::Runtime::instance();
	
	// Add two proxies to the global object
	// Proxy is the base and ExampleProxy is a subclass
	context.addPropertyToGlobalObject("Proxy", Ti::Proxy::CreateConstructor());
	context.addPropertyToGlobalObject("ExampleProxy", Ti::ExampleProxy::CreateConstructor());
	
	// Create a new object by calling "new" on it, it should return [object ObjectName]
  XCTAssertEqual("[object Proxy]", Ti::evaluateScript("new Proxy()").toString());
  XCTAssertEqual("[object ExampleProxy]", Ti::evaluateScript("new ExampleProxy()").toString());

	// Call a method "testMethod", which returns the argument passed in
	XCTAssertEqual("something", Ti::evaluateScript("new Proxy().testMethod('something')").toString());

	// Call the same method "testMethod" on the subclass, should act the same way
	XCTAssertEqual("something", Ti::evaluateScript("new ExampleProxy().testMethod('something')").toString());
	
	// Call another method, only defined in the sublclass
	XCTAssertTrue( Ti::evaluateScript("new ExampleProxy().saySomething('something')").toBool());
	

  std::string testString = Ti::evaluateScript("new Proxy().saySomething('something')").toString();
  std::regex regex { "^TypeError:.*" };
  XCTAssertTrue(std::regex_match(testString, regex));
}

- (void)testExample {
  const auto& context = Ti::Runtime::instance();

	// Create a new object called "testObject" and add some Ti::Values to it.
	std::map<std::string, Ti::Value> testObject;
    
	testObject["number"] = Ti::Value(123.34);
  XCTAssertTrue(testObject["number"].isNumber());
  XCTAssertEqualWithAccuracy(123.34, testObject["number"].toDouble(), std::numeric_limits<double>::epsilon());

	testObject["string"] = Ti::Value("Hello String");
  XCTAssertTrue(testObject["string"].isString());
  XCTAssertEqual("Hello String", testObject["string"].toString());

	testObject["object"] = Ti::Value();
  XCTAssertTrue(testObject["object"].isObject());

	testObject["bool-true"] = Ti::Value(true);
  XCTAssertTrue(testObject["bool-true"].isBoolean());
  XCTAssertTrue(testObject["bool-true"].toBool());

	testObject["bool-false"] = Ti::Value(false);
  XCTAssertTrue(testObject["bool-false"].isBoolean());
  XCTAssertFalse(testObject["bool-false"].toBool());
	
	// Create an array
	std::vector<Ti::Value> testArray;
	testArray.push_back(Ti::Value("hello"));
	testArray.push_back(Ti::Value("world"));
	
	// Add the array to the object
	testObject["array"] = Ti::Value(testArray);
  XCTAssertTrue(testObject["array"].isArray());
	
	// Create a JavaScript Object from the vector.
	Ti::Value testObject2(testObject);
  XCTAssertTrue(testObject2.isObject());
	
	// Add another property to it.
  // We should add operator[] to support this.
	testObject2.setProperty("testing_property", Ti::Value("Hello World!!!!"));
  XCTAssertTrue(testObject2.getProperty("testing_property").isString());
  XCTAssertEqual("Hello World!!!!", testObject2.getProperty("testing_property").toString());
	
	// Add it to the global object.
	context.addPropertyToGlobalObject("testObject2", testObject2);
	
	// Convert testObject2 to a JSON string.
	auto result = Ti::evaluateScript("JSON.stringify(testObject2)");
  XCTAssertEqual("{\"array\":[\"hello\",\"world\"],\"bool-false\":false,\"bool-true\":true,\"number\":123.34,\"object\":{},\"string\":\"Hello String\",\"testing_property\":\"Hello World!!!!\"}", result.toString());
	
	auto props = testObject2.toDictionary();
  XCTAssertEqual(7, props.size());
	
	auto valueList = Ti::Value(testArray).toVector();
  XCTAssertEqual(2, valueList.size());

	Ti::Value testObject3;
	testObject3.setProperty("foo", Ti::Value(true));
	XCTAssertEqual("[object Object]", testObject3.toString());
  XCTAssertTrue(testObject3.getProperty("foo").isBoolean());
  XCTAssertTrue(testObject3.getProperty("foo").toBool());

	testObject3.setProperty("bar", Ti::Value("hello world"));
  XCTAssertTrue(testObject3.getProperty("bar").isString());
  XCTAssertEqual("hello world", testObject3.getProperty("bar").toString());

	auto testObject3Props = testObject3.toDictionary();
  XCTAssertEqual(2, testObject3Props.size());
}

@end
