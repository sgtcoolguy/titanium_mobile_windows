#include "UI.h"
//#include "Utils.h"
#include "Window.h"
#include "View.h"
#include "hyperloop/hyperloop_common.h"

JSObjectRef titanium::UI::create(JSObjectRef container) {
    JSContextRef ctx = Utils::getAppContext();
    JSObjectRef global = JSContextGetGlobalObject(ctx);
    
    JSClassDefinition classDefinition = kJSClassDefinitionEmpty;
    JSStaticFunction StaticFunctionArray[] = {{ "createWindow", createWindow, kJSPropertyAttributeNone },
					      { "createView", createView, kJSPropertyAttributeNone },
					      {0, 0, 0 }
    };             
    classDefinition.staticFunctions = StaticFunctionArray; 
    
    JSClassRef clsRef = JSClassCreate(&classDefinition);
    JSObjectRef objRef = JSObjectMake(ctx, clsRef, NULL);
    
    JSStringRef className = JSStringCreateWithUTF8CString("UI");
    JSObjectSetProperty(ctx, container, className, objRef, kJSPropertyAttributeNone, NULL);
    JSStringRelease(className);     
    
    return objRef;
}

JSValueRef titanium::UI::createWindow(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
    return titanium::Window::create(); 
}

JSValueRef titanium::UI::createView(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {        
    return titanium::View::create();
}
