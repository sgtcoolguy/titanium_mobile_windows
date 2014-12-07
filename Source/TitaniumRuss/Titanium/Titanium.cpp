#pragma once

#include "Titanium.h"
#include "common/Utils.h"

JSObjectRef titanium::Titanium::create() {
	JSContextRef ctx = Utils::getAppContext();
	JSObjectRef global = JSContextGetGlobalObject(ctx);

	JSClassDefinition classDefinition = kJSClassDefinitionEmpty;

	JSClassRef clsRef = JSClassCreate(&classDefinition);
	JSObjectRef objRef = JSObjectMake(ctx, clsRef, NULL);
	JSStringRef className = JSStringCreateWithUTF8CString("Titanium");
	JSObjectSetProperty(ctx, global, className, objRef, kJSPropertyAttributeNone, NULL);
	JSStringRelease(className);

	return objRef;
}	

