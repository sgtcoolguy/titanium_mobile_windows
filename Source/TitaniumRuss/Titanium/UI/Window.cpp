#pragma once

#include "Window.h"
#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"
#include "UIPrototype.h"

using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
 
JSObjectRef titanium::Window::create() {
	JSContextRef ctx = Utils::getAppContext();
	JSClassDefinition classDefinition = kJSClassDefinitionEmpty;

	JSStaticFunction StaticFunctionArray[] = {{ "open", Activate, kJSPropertyAttributeNone },
											  { "add", Add, kJSPropertyAttributeNone },
		                                      { 0, 0, 0 }
		                                     };		
	classDefinition.staticFunctions = StaticFunctionArray; 

	classDefinition.parentClass = titanium::UIPrototype::create();

	PrivateObjectContainer* poc = new PrivateObjectContainer();
	Canvas^ nobj = ref new Canvas();

	// ToDo handle device rotation 
	// ToDo default color should be black
	nobj->Width =  Windows::UI::Xaml::Window::Current->Bounds.Width;
	nobj->Height =  Windows::UI::Xaml::Window::Current->Bounds.Height;
	SolidColorBrush^ blue = ref new SolidColorBrush();
	blue->Color = Windows::UI::Colors::Blue;
	nobj->Background = blue;

	poc->set(nobj);

	JSClassRef clsRef = JSClassCreate(&classDefinition);
	JSObjectRef classDef = JSObjectMake(ctx, clsRef, poc);

	return classDef;
}

JSValueRef titanium::Window::Activate(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
	void* raw = JSObjectGetPrivate(thisObject);
	UIElement^ nobj = (UIElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	
	// Add the view hierarchy to the display
	Windows::UI::Xaml::Window::Current->Content = nobj;
	Windows::UI::Xaml::Window::Current->Activate();
		
	return JSValueMakeUndefined(ctx);
}

JSValueRef titanium::Window::Add(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {	
	void* raw = JSObjectGetPrivate(thisObject);
	Canvas^ nobj = (Canvas^)reinterpret_cast<PrivateObjectContainer*>(raw)->get();
	JSValueRef val = arguments[0];
	JSObjectRef objRef = JSValueToObject(ctx, val, NULL);
	raw = JSObjectGetPrivate(objRef);
	nobj->Children->Append((UIElement^)reinterpret_cast<PrivateObjectContainer*>(raw)->get());

	return val;
}

