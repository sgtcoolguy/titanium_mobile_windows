/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/GlobalObject.hpp"
#include "Titanium/XML.hpp"
#include "NativeAPIExample.hpp"
#include "gtest/gtest.h"

#define XCTAssertEqual ASSERT_EQ
#define XCTAssertNotEqual ASSERT_NE
#define XCTAssertTrue ASSERT_TRUE
#define XCTAssertFalse ASSERT_FALSE
#define XCTAssertNoThrow ASSERT_NO_THROW

using namespace Titanium;
using namespace HAL;

class XMLTests : public testing::Test
{
protected:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}

	JSContextGroup js_context_group;
};

TEST_F(XMLTests, BasicFeatures)
{
	JSContext js_context = js_context_group.CreateContext(JSExport<Titanium::GlobalObject>::Class());
	auto global_object = js_context.get_global_object();

	XCTAssertFalse(global_object.HasProperty("Titanium"));
	auto Titanium = js_context.CreateObject();
	global_object.SetProperty("Titanium", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Titanium"));

	// Make the alias "Ti" for the "Titanium" property.
	XCTAssertFalse(global_object.HasProperty("Ti"));
	global_object.SetProperty("Ti", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Ti"));

	XCTAssertFalse(Titanium.HasProperty("XML"));
	auto XML = js_context.CreateObject(JSExport<Titanium::XML>::Class());
	Titanium.SetProperty("XML", XML, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(Titanium.HasProperty("XML"));

	XCTAssertTrue(XML.HasProperty("parseString"));
	XCTAssertTrue(XML.HasProperty("serializeToString"));
}

TEST_F(XMLTests, ParseString)
{
	JSContext js_context = js_context_group.CreateContext(JSExport<Titanium::GlobalObject>::Class());
	auto global_object = js_context.get_global_object();

	XCTAssertFalse(global_object.HasProperty("Titanium"));
	auto Titanium = js_context.CreateObject();
	global_object.SetProperty("Titanium", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Titanium"));

	// Make the alias "Ti" for the "Titanium" property.
	XCTAssertFalse(global_object.HasProperty("Ti"));
	global_object.SetProperty("Ti", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Ti"));

	XCTAssertFalse(Titanium.HasProperty("API"));
	auto API = js_context.CreateObject(JSExport<NativeAPIExample>::Class());
	Titanium.SetProperty("API", API, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(Titanium.HasProperty("API"));

	XCTAssertFalse(Titanium.HasProperty("XML"));
	auto XML = js_context.CreateObject(JSExport<Titanium::XML>::Class());
	Titanium.SetProperty("XML", XML, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(Titanium.HasProperty("XML"));

	auto func_property = XML.GetProperty("parseString");
	XCTAssertTrue(func_property.IsObject());

	auto func = static_cast<JSObject>(func_property);
	XCTAssertTrue(func.IsFunction());

	const std::vector<JSValue> args { js_context.CreateString("<test/>") };
	auto js_dom = func(args, XML);
	XCTAssertTrue(js_dom.IsObject());
	auto dom = static_cast<JSObject>(js_dom);
	XCTAssertTrue(dom.HasProperty("documentElement"));
}

TEST_F(XMLTests, SerializeToString)
{
	JSContext js_context = js_context_group.CreateContext(JSExport<Titanium::GlobalObject>::Class());
	auto global_object = js_context.get_global_object();

	XCTAssertFalse(global_object.HasProperty("Titanium"));
	auto Titanium = js_context.CreateObject();
	global_object.SetProperty("Titanium", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Titanium"));

	// Make the alias "Ti" for the "Titanium" property.
	XCTAssertFalse(global_object.HasProperty("Ti"));
	global_object.SetProperty("Ti", Titanium, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(global_object.HasProperty("Ti"));

	XCTAssertFalse(Titanium.HasProperty("API"));
	auto API = js_context.CreateObject(JSExport<NativeAPIExample>::Class());
	Titanium.SetProperty("API", API, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(Titanium.HasProperty("API"));

	XCTAssertFalse(Titanium.HasProperty("XML"));
	auto XML = js_context.CreateObject(JSExport<Titanium::XML>::Class());
	Titanium.SetProperty("XML", XML, {JSPropertyAttribute::ReadOnly, JSPropertyAttribute::DontDelete});
	XCTAssertTrue(Titanium.HasProperty("XML"));

	auto func_property = XML.GetProperty("serializeToString");
	XCTAssertTrue(func_property.IsObject());

	auto serialize = static_cast<JSObject>(func_property);
	XCTAssertTrue(serialize.IsFunction());

	auto parse_property = XML.GetProperty("parseString");
	XCTAssertTrue(parse_property.IsObject());

	auto parse = static_cast<JSObject>(parse_property);
	XCTAssertTrue(parse.IsFunction());

	const std::vector<JSValue> args { js_context.CreateString("<test/>") };
	auto js_dom = parse(args, XML);
	XCTAssertTrue(js_dom.IsObject());
	auto dom = static_cast<JSObject>(js_dom);
	XCTAssertTrue(dom.HasProperty("documentElement"));

	const std::vector<JSValue> serialize_args { dom };
	auto result = serialize(serialize_args, XML);

	XCTAssertTrue(result.IsString());
	XCTAssertEqual("<test/>", static_cast<std::string>(result));
}
