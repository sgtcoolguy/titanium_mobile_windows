#include "stdafx.h"
#include "CppUnitTest.h"
#include <JavaScriptCore/JavaScript.h>
#include "TiValue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TiValueWindows
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const auto& context = Ti::Runtime::instance();

			// Create a new object called "testObject" and add some Ti::Values to it.
			std::map<std::string, Ti::Value> testObject;

			testObject["number"] = Ti::Value(123.34);
			Assert::IsTrue(testObject["number"].isNumber());
			Assert::AreEqual(123.34, testObject["number"].toDouble(), std::numeric_limits<double>::epsilon());

			testObject["string"] = Ti::Value("Hello String");
			Assert::IsTrue(testObject["string"].isString());
			Assert::AreEqual("Hello String", testObject["string"].toString().c_str());

			testObject["object"] = Ti::Value();
			Assert::IsTrue(testObject["object"].isObject());

			testObject["bool-true"] = Ti::Value(true);
			Assert::IsTrue(testObject["bool-true"].isBoolean());
			Assert::IsTrue(testObject["bool-true"].toBool());

			testObject["bool-false"] = Ti::Value(false);
			Assert::IsTrue(testObject["bool-false"].isBoolean());
			Assert::IsFalse(testObject["bool-false"].toBool());

			// Create an array
			std::vector<Ti::Value> testArray;
			testArray.push_back(Ti::Value("hello"));
			testArray.push_back(Ti::Value("world"));

			// Add the array to the object
			testObject["array"] = Ti::Value(testArray);
			Assert::IsTrue(testObject["array"].isArray());

			// Create a JavaScript Object from the vector.
			Ti::Value testObject2(testObject);
			Assert::IsTrue(testObject2.isObject());

			// Add another property to it.
			// We should add operator[] to support this.
			testObject2.setProperty("testing_property", Ti::Value("Hello World!!!!"));
			Assert::IsTrue(testObject2.getProperty("testing_property").isString());
			Assert::AreEqual("Hello World!!!!", testObject2.getProperty("testing_property").toString().c_str());

			// Add it to the global object.
			context.addPropertyToGlobalObject("testObject2", testObject2);

			// Convert testObject2 to a JSON string.
			auto result = context.evaluateScript("JSON.stringify(testObject2)");
			Assert::AreEqual("{\"array\":[\"hello\",\"world\"],\"bool-false\":false,\"bool-true\":true,\"number\":123.34,\"object\":{},\"string\":\"Hello String\",\"testing_property\":\"Hello World!!!!\"}", result.toString().c_str());

			auto props = testObject2.toDictionary();
			Assert::AreEqual(7, (int)props.size());

			auto valueList = Ti::Value(testArray).toVector();
			Assert::AreEqual(2, (int)valueList.size());

			Ti::Value testObject3;
			testObject3.setProperty("foo", Ti::Value(true));
			Assert::AreEqual("[object Object]", testObject3.toString().c_str());
			Assert::IsTrue(testObject3.getProperty("foo").isBoolean());
			Assert::IsTrue(testObject3.getProperty("foo").toBool());

			testObject3.setProperty("bar", Ti::Value("hello world"));
			Assert::IsTrue(testObject3.getProperty("bar").isString());
			Assert::AreEqual("hello world", testObject3.getProperty("bar").toString().c_str());

			auto testObject3Props = testObject3.toDictionary();
			Assert::AreEqual(2, (int)testObject3Props.size());
		}

	};
}