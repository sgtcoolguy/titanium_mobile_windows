#pragma once

#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"
#include "UIPrototype.h"

using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

JSClassRef  titanium::UIPrototype::create() {
	JSContextRef ctx = Utils::getAppContext();
	JSClassDefinition classDefinition = kJSClassDefinitionEmpty;
	classDefinition.finalize = classDestructor;
	
	// List Javascript object properties and methods
	JSStaticValue StaticValueArray[] = {{ "width", GetWidth, SetWidth, kJSPropertyAttributeNone }, 
										{ "height", GetHeight, SetHeight, kJSPropertyAttributeNone }, 
		                                { 0, 0, 0, 0 }
		                               };		
	classDefinition.staticValues = StaticValueArray; 

	JSStaticFunction StaticFunctionArray[] = {{ "addEventListener", AddEventListener, kJSPropertyAttributeNone },
		                                      { 0, 0, 0 }
		                                     };		
	classDefinition.staticFunctions = StaticFunctionArray;

	JSClassRef clsRef = JSClassCreate(&classDefinition);
	return clsRef;
}

void titanium::UIPrototype::classDestructor(JSObjectRef object) {
	void* raw = JSObjectGetPrivate(object);
	reinterpret_cast<PrivateObjectContainer*>(raw)->clean();
	delete reinterpret_cast<PrivateObjectContainer*>(raw);
}

bool titanium::UIPrototype::SetWidth(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	FrameworkElement^ nobj = (FrameworkElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	double nVal = JSValueToNumber(ctx, value, NULL);
	nobj->Width = nVal;
	return true;
}

JSValueRef titanium::UIPrototype::GetWidth(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	FrameworkElement^ nobj = (FrameworkElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();

	return  JSValueMakeNumber(ctx, nobj->Width);
}

bool titanium::UIPrototype::SetHeight(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	FrameworkElement^ nobj = (FrameworkElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	double nVal = JSValueToNumber(ctx, value, NULL);
	nobj->Height = nVal;
	
	return true;
}

JSValueRef titanium::UIPrototype::GetHeight(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	FrameworkElement^ nobj = (FrameworkElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
		
	return  JSValueMakeNumber(ctx, nobj->Height); 
}

JSValueRef titanium::UIPrototype::AddEventListener(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {	
	void* raw = JSObjectGetPrivate(thisObject);
	FrameworkElement^ nobj = (FrameworkElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();

	JSValueRef val = arguments[0]; // hook type as string ie 'click'
	JSValueRef val2 = arguments[1];
	JSObjectRef objRef = JSValueToObject(ctx, val2, NULL);

	// Setup event handlers
	// ToDo wrap and abstract this. This could get messy
	std::string eventType = titanium::Utils::getSTDString(JSValueToStringCopy(ctx, arguments[0], NULL));

	if (eventType.compare("touchmove") == 0) {
		ManipulationHandler^ manipulationHandler = ref new ManipulationHandler();
		ManipulationDeltaEventHandler^ manipulationDelta =
			ref new ManipulationDeltaEventHandler(manipulationHandler, &ManipulationHandler::ManipulationDelta);
		nobj->ManipulationMode = ManipulationModes::All;
		nobj->ManipulationDelta::add(manipulationDelta);
		((PrivateObjectContainer*)raw)->manipulationHandler = manipulationHandler;
		manipulationHandler->SetDeltaCallback((int64)JSValueToObject(ctx, val2, NULL));
		manipulationHandler->SetContext((int64)Utils::getAppContext());
		manipulationHandler->SetSource((int64)thisObject);
	}

	return JSValueMakeUndefined(ctx);
}

titanium::ManipulationHandler::ManipulationHandler() {}

void titanium::ManipulationHandler::ManipulationDelta(Object^ sender, ManipulationDeltaRoutedEventArgs^ e) {
	if (context != NULL) {
		JSObjectRef evtArg = createEventArgs(context, source, e);

		JSValueRef args[] = {evtArg};
		JSValueRef result = JSObjectCallAsFunction(context, deltaCallback, source, 1, args, NULL);
	}

	e->Handled = true;
}

void titanium::ManipulationHandler::SetContext(int64 context) {
	this->context = (JSContextRef)context;
}

void titanium::ManipulationHandler::SetDeltaCallback(int64 callback) {
	deltaCallback = (JSObjectRef)callback;
}

void titanium::ManipulationHandler::SetSource(int64 source) {
	this->source = (JSObjectRef)source;
}

JSObjectRef titanium::ManipulationHandler::createEventArgs(JSContextRef ctx, JSObjectRef source, ManipulationDeltaRoutedEventArgs^ e) {
	JSObjectRef global = JSContextGetGlobalObject(ctx);
	JSClassDefinition myClassDefinition = kJSClassDefinitionEmpty;
	JSClassRef myClass = JSClassCreate(&myClassDefinition);
	JSObjectRef myObject = JSObjectMake(ctx, myClass, NULL);

	JSStringRef originalSourceProperty = JSStringCreateWithUTF8CString("source");
	JSValueRef valueRef = source;
	JSObjectSetProperty(ctx, myObject, originalSourceProperty, valueRef, kJSPropertyAttributeDontEnum, NULL);
	JSStringRelease(originalSourceProperty);

	JSStringRef xProperty = JSStringCreateWithUTF8CString("x");
	valueRef = JSValueMakeNumber(ctx, e->Delta.Translation.X);
	JSObjectSetProperty(ctx, myObject, xProperty, valueRef, kJSPropertyAttributeDontEnum, NULL);
	JSStringRelease(xProperty);

	JSStringRef yProperty = JSStringCreateWithUTF8CString("y");
	valueRef = JSValueMakeNumber(ctx, e->Delta.Translation.Y);
	JSObjectSetProperty(ctx, myObject, yProperty, valueRef, kJSPropertyAttributeDontEnum, NULL);
	JSStringRelease(yProperty);

	return myObject;
}

