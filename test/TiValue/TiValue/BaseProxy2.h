// -*- mode: c++ -*-

#ifndef _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_BASEPROXY2_H_
#define _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_BASEPROXY2_H_

#include "TiCore/TiValue.h"
#include <JavaScriptCore/JavaScript.h>
#include <memory>
#include <functional>

template<typename Derived>
class BaseProxy2 : public std::enable_shared_from_this<BaseProxy2<Derived>> {
  
 protected:
  
	BaseProxy2(const std::string& name) : proxyName_(name) {
    
		using JSObjectCallAsConstructorCallback_t = std::function<JSObjectRef(JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception)>;
		JSObjectCallAsConstructorCallback_t callAsConstructor = [](JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) -> JSObjectRef {
			return nullptr;
		};
		
		classDefinition_                   = kJSClassDefinitionEmpty;
		classDefinition_.className         = proxyName_.c_str();
		classDefinition_.parentClass       = Derived::Parent;
		classDefinition_.staticFunctions   = Derived::ClassMethods;
		classDefinition_.callAsConstructor = &BaseProxy2::ConstructorCallback;
		classDefinition_.finalize          = &BaseProxy2::Finalizer;
		class_                             = JSClassCreate(&classDefinition_);
	}
  
	virtual ~BaseProxy2() {
	}
  
	virtual void onFinalizer() {
	}
  
	virtual void onInitializer() {
	}
  
	Ti::Value CreateConstructor() 	{
		return Ti::Value(JSObjectMakeConstructor(Ti::Runtime::instance().globalContext(), class_, &BaseProxy2::ConstructorCallback));
	}
  
  
private:
  
	static JSObjectRef ConstructorCallback (JSContextRef ctx, JSObjectRef constructor, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception) {
		auto proxy = new Derived();
		Ti::Value jsObject(JSObjectMake(Ti::Runtime::instance().globalContext(), class_, proxy));
		proxy->setJSObject(jsObject.JSObjectRef());
		proxy->onInitializer();
		return jsObject.JSObjectRef();
	}
  
	void Finalizer(JSObjectRef obj) {
		auto proxy = static_cast<Derived*>(JSObjectGetPrivate(obj));
		if(proxy == nullptr) {
			return;
		}
		proxy->onFinalizer();
		delete proxy;
		proxy = nullptr;
		JSObjectSetPrivate(obj, nullptr);
	}
  
	void setJSObject(JSObjectRef obj) {
		object_ = obj;
	}

	JSClassDefinition classDefinition_ = kJSClassDefinitionEmpty;
	JSClassRef        class_;
	std::string       proxyName_;
	JSObjectRef       object_;
};


#endif // _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_BASEPROXY2_H_
