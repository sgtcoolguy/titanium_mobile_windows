#pragma once

#include "View.h"
#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"
#include "UIPrototype.h"

using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

JSObjectRef titanium::View::create() {
	JSContextRef ctx = Utils::getAppContext();
	JSClassDefinition classDefinition = kJSClassDefinitionEmpty;

	JSStaticValue StaticValueArray[] = {{ "top", GetTop, SetTop, kJSPropertyAttributeNone }, 
										{ "left", GetLeft, SetLeft, kJSPropertyAttributeNone }, 
		                                { 0, 0, 0, 0 }
		                               };		
	classDefinition.staticValues = StaticValueArray; 

	JSStaticFunction StaticFunctionArray[] = {{ "setBackgroundColor", SetBackground, kJSPropertyAttributeNone },
		                                      { 0, 0, 0 }
		                                     };		
	classDefinition.staticFunctions = StaticFunctionArray;

	classDefinition.parentClass = titanium::UIPrototype::create();

	PrivateObjectContainer* poc = new PrivateObjectContainer();
	Canvas^ nobj = ref new Canvas();
	poc->set(nobj);

	JSClassRef clsRef = JSClassCreate(&classDefinition);
	JSObjectRef classDef = JSObjectMake(ctx, clsRef, poc);

	return classDef;
}

bool titanium::View::SetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	nobj->SetTop((UIElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get(), JSValueToNumber(ctx, value, NULL));
	
	return true;
}

JSValueRef titanium::View::GetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();

	return  JSValueMakeNumber(ctx, Canvas::GetTop(nobj));
}

bool titanium::View::SetLeft(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	nobj->SetLeft((UIElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get(), JSValueToNumber(ctx, value, NULL));
	
	return true;
}

JSValueRef titanium::View::GetLeft(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();

	return  JSValueMakeNumber(ctx, Canvas::GetLeft(nobj));
}

JSValueRef titanium::View::SetBackground(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {	
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	
	double nVal = JSValueToNumber(ctx, arguments[0], NULL);
	std::string color = titanium::Utils::getSTDString(JSValueToStringCopy(ctx, arguments[0], NULL));
	
	SolidColorBrush^ brush = ref new SolidColorBrush();

	// ToDo handle passed in string constants in utils or a helper like getBrushForColor(<color>) 
	if (color.compare("red") == 0)
		brush->Color = Windows::UI::Colors::Red;
	else if (color.compare("yellow") == 0)
		brush->Color = Windows::UI::Colors::Yellow;
	else if (color.compare("blue") == 0)
		brush->Color = Windows::UI::Colors::Blue;
	else
		brush->Color = Windows::UI::Colors::Green;

	nobj->Background = brush;

	return JSValueMakeUndefined(ctx);
}




