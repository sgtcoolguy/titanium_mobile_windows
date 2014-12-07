#include "TiApp.h"
#include <fstream>
#include <iostream>
#include "common/Utils.h"
#include "Titanium/Titanium.h"
#include "Titanium/UI/UI.h"
#include "hyperloop/hyperloop_windows.h"
#include "hyperloop/hyperloop_Logger.h"

EXPORTAPI void HyperloopAppRequire(JSValueRef *);

/**
 * load up embedded source code from the app
 */
EXPORTAPI JSValueRef HyperloopLoadEmbedSource(JSGlobalContextRef ctx, const JSObjectRef& parent, const char *path, JSValueRef *exception) {
    std::string filePath(path);
    if (filePath.find("/app.js")==0) {
        static JSValueRef result = nullptr;
        if (result==nullptr) {
            // get the global object
            auto object = JSContextGetGlobalObject(ctx);
            
            // module
            auto var0 = JSStringCreateWithUTF8CString("module");
            auto var1 = JSObjectGetProperty(ctx,object,var0,exception);
            // exports
            auto var2 = JSStringCreateWithUTF8CString("exports");
            auto var3 = JSObjectGetProperty(ctx,object,var2,exception);
            // __filename
            auto var4 = JSStringCreateWithUTF8CString("__filename");
            auto var5 = JSObjectGetProperty(ctx,object,var4,exception);
            // __dirname
            auto var6 = JSStringCreateWithUTF8CString("__dirname");
            auto var7 = JSObjectGetProperty(ctx,object,var6,exception);
            // require
            auto var8 = JSStringCreateWithUTF8CString("require");
            auto var9 = JSObjectGetProperty(ctx,object,var8,exception);
            // create the module object
            auto module = HyperloopCreateModule(ctx,parent,filePath.c_str(),"/",exception);
            
            // set properties into our global scope from the module
            JSObjectSetProperty(ctx,object,var0,module,0,exception);
            JSObjectSetProperty(ctx,object,var2,JSObjectGetProperty(ctx,module,var2,exception),0,exception);
            JSObjectSetProperty(ctx,object,var4,JSObjectGetProperty(ctx,module,var4,exception),0,exception);
            JSObjectSetProperty(ctx,object,var6,JSObjectGetProperty(ctx,module,var6,exception),0,exception);
            JSObjectSetProperty(ctx,object,var8,JSObjectGetProperty(ctx,module,var8,exception),0,exception);
            
            // process builtin symbols
            auto Hyperloop_Binary_IsEqualProperty = JSStringCreateWithUTF8CString("Hyperloop_Binary_IsEqual");
            auto Hyperloop_Binary_IsEqualFn = JSObjectMakeFunctionWithCallback(ctx,
                                                                               Hyperloop_Binary_IsEqualProperty,
                                                                               Hyperloop_Binary_IsEqual);
            JSObjectSetProperty(ctx,
                                object,
                                Hyperloop_Binary_IsEqualProperty,
                                Hyperloop_Binary_IsEqualFn,
                                kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontEnum|kJSPropertyAttributeDontDelete,
                                nullptr);
            JSStringRelease(Hyperloop_Binary_IsEqualProperty);
            
            // Load script into this string.
	    //std::string fileContents = titanium::Utils::loadFile("/Assets/resources" + filePath);
	    std::string fileContents = titanium::Utils::loadFile(filePath);
	    const char* var10 = fileContents.c_str();
	    auto var11 = JSStringCreateWithUTF8CString(var10);
	    auto var12 = JSStringCreateWithUTF8CString("app.js");
	    JSEvaluateScript(ctx,var11,object,var12,1,exception);
	    JSStringRelease(var11);
	    JSStringRelease(var12);
	    CHECK_EXCEPTION(exception);
	    
	    // tell the module we're loaded
	    result = HyperloopModuleLoaded(ctx,module);
	    
	    // restore previous module values back into global
	    JSObjectSetProperty(ctx,object,var0,var1,0,exception);
	    JSStringRelease(var0);
	    JSObjectSetProperty(ctx,object,var2,var3,0,exception);
	    JSStringRelease(var2);
	    JSObjectSetProperty(ctx,object,var4,var5,0,exception);
	    JSStringRelease(var4);
	    JSObjectSetProperty(ctx,object,var6,var7,0,exception);
	    JSStringRelease(var6);
	    JSObjectSetProperty(ctx,object,var8,var9,0,exception);
	    JSStringRelease(var8);
        }
        return result;
    }
    auto msg = std::string("Cannot find module '");
    msg+=filePath;
    msg+=std::string("'");
    auto result = HyperloopMakeException(ctx,msg.c_str());
    auto msgStr = HyperloopMakeString(ctx,"MODULE_NOT_FOUND",0);
    auto code = JSStringCreateWithUTF8CString("code");
    auto obj = JSValueToObject(ctx,result,0);
    JSObjectSetProperty(ctx, obj, code, msgStr, 0, 0);
    JSStringRelease(code);
    *exception = result;
    return JSValueMakeUndefined(ctx);
}

EXPORTAPI void HyperloopInitialize_Source()
{
	HyperloopRegisterTranslationUnit(&HyperloopLoadEmbedSource, { "/app.js" });
}

TitaniumRuss::TiApp::TiApp() {
}

void TitaniumRuss::TiApp::OnLaunched(LaunchActivatedEventArgs^ args) {
    JSGlobalContextRef ctx = InitializeHyperloop();
    
    titanium::Utils::setAppContext(ctx);
    JSObjectRef global = JSContextGetGlobalObject(ctx);
    
    // Initialize the runtime with the global Titanium object
	JSObjectRef ti = titanium::Titanium::create();
	titanium::UI::create(ti);
    
    JSStringRef bootScript = JSStringCreateWithUTF8CString("Ti = Titanium;\n");
    JSValueRef result      = JSEvaluateScript(ctx, bootScript, global, NULL, 0, NULL);
    JSStringRelease(bootScript);
    
    // Load and evaluate the Titanium appclication by default the JavaScript is in the app.js file
    JSValueRef exception = NULL;
    HyperloopAppRequire(&exception);
}

void TitaniumRuss::TiApp::Boot()
{
    if (booted) {
        return;
    }
    
    booted = true;

    JSValueRef exception = NULL;
    this->context = InitializeHyperloop();
    
    HyperloopAppRequire(&exception);
    
    if (exception != nullptr) {
        JSStringRef str = JSValueToStringCopy(HyperloopGlobalContext(), exception, NULL);
        const size_t len = JSStringGetMaximumUTF8CStringSize(str);
        char* buf = new char[len];
        JSStringGetUTF8CString(str, (char *)buf, len);
        JSStringRelease(str);
        
        Logger::log(HyperloopWindowsGetPlatformString(buf));
        
        delete[] buf;
    }
    else {
        Logger::log("Hyperloop App started");
    }
}
