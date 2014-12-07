// -*- mode: c++ -*-
/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * This code and related technologies are covered by patents
 * or patents pending by Appcelerator, Inc.
 */
#ifndef _TITANIUM_MOBILE_WINDOWS_HYPERLOOP_COMMON_H_
#define _TITANIUM_MOBILE_WINDOWS_HYPERLOOP_COMMON_H_

#ifndef _WIN32
// C99 type
#ifndef _Bool
#define _Bool bool
#endif
#endif

#include <string> //TODO: refactor to remove c++ from API
#include <cmath>
#include <stdlib.h> 
#include <JavaScriptCore/JavaScript.h>

#define EXPORTAPI extern "C"

// macro for checking to see if exception has been thrown
#define CHECK_EXCEPTION(e)                              \
    if (*e!=nullptr && !JSValueIsNull(ctx,*e)) {        \
        return JSValueMakeUndefined(ctx);               \
    }

/**
 * Initialize the Hyperloop library.  This is a singleton so calling
 * this method more than once will return the same JSGlobalContextRef.
 * If you want to create a new context call DestroyHyperloop() before
 * calling this method again.
 *
 * @returns JSGlobalContextRef
 */
EXPORTAPI JSGlobalContextRef InitializeHyperloop();

/**
 * Destory the Hyperloop library.
 */
EXPORTAPI void DestroyHyperloop();

/**
 * Return the global context for hyperloop.
 */
EXPORTAPI JSGlobalContextRef HyperloopGlobalContext();

/**
 * Return a new global context in the same context group.
 */
EXPORTAPI JSGlobalContextRef HyperloopNewGlobalContext();

/**
 * Create an Error object using message.
 */
EXPORTAPI JSValueRef HyperloopMakeException(JSContextRef ctx, const char *error);

/**
 * Return a char* from a JSValueRef as string which must be delete
 * when finished.
 */
EXPORTAPI char* HyperloopJSValueToStringCopy(JSContextRef ctx, JSValueRef value, JSValueRef *exception);

/**
 * Return a char* from a JSStringRef as string which must be delete
 * when finished.
 */
EXPORTAPI char* HyperloopJSStringToStringCopy(JSContextRef ctx, JSStringRef str, JSValueRef *exception);

/**
 * Return a JS string from a const char *.
 */
EXPORTAPI JSValueRef HyperloopMakeString(JSContextRef ctx, const char *string, JSValueRef *exception);

/**
 * Return a void pointer as a JSValueRef.
 */
EXPORTAPI JSObjectRef HyperloopVoidPointerToJSValue(JSContextRef ctx, void *pointer, JSValueRef *exception);

/**
 * Return a void pointer from a JSValueRef.
 */
EXPORTAPI void* HyperloopJSValueToVoidPointer(JSContextRef ctx, JSValueRef value, JSValueRef *exception);

/**
 * Invoke a function callback.
 */
EXPORTAPI JSValueRef HyperloopInvokeFunctionCallback (JSContextRef ctx, void * callbackPointer, size_t argumentCount, const JSValueRef arguments[], JSValueRef *exception);

/**
 * Create a module instance.
 */
EXPORTAPI JSObjectRef HyperloopCreateModule(JSGlobalContextRef ctx, JSObjectRef parent, const char *filename, const char *dirname, JSValueRef *exception);

/**
 * Called when the module has completed loading.
 */
EXPORTAPI JSObjectRef HyperloopModuleLoaded(JSGlobalContextRef ctx, JSObjectRef module);

/*
 * Tests whether a JavaScript value is an array object.
 */
EXPORTAPI bool HyperloopJSValueIsArray(JSContextRef ctx, JSValueRef value);

/*
 * Tests whether two JavaScript values are equals, as compared by the
 * JS '==' operator.
 */
EXPORTAPI JSValueRef Hyperloop_Binary_IsEqual(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

/*
 * Tests whether two JavaScript values are equals, as compared by the
 * JS '===' operator.
 */
EXPORTAPI JSValueRef Hyperloop_Binary_IsStrictEqual(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

/*
 * Tests whether a JavaScript value is an object constructed by given
 * object, as compared by JS 'instanceof' operator.
 */
EXPORTAPI JSValueRef Hyperloop_Binary_InstanceOf(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);

typedef JSValueRef (*HyperloopTranslationUnitCallback)(JSGlobalContextRef ctx, const JSObjectRef & parent, const char *path, JSValueRef *exception);

/**
 * Called by a translation unit to register its compiled code.
 */
EXPORTAPI bool HyperloopRegisterTranslationUnit(HyperloopTranslationUnitCallback callback, std::initializer_list<std::string> filePathList);

///////////////////////////////////////////////////////////////////////////////
// Platforms implement
///////////////////////////////////////////////////////////////////////////////

EXPORTAPI void HyperloopNativeLogger(const char *str);


///////////////////////////////////////////////////////////////////////////////
// C++ native object wrapper
///////////////////////////////////////////////////////////////////////////////

namespace Hyperloop
{
    class AbstractObject {
    public:
        AbstractObject(void* data) 
            : data(data) {
        }
        
        ~AbstractObject() {
        }
        
        void* getData() const {
            return data;
        }
        
        void setData(void* data) {
            this->data = data;
        }
        
        void* getObject() const {
            return nullptr;
        }
        
    private:
        void* data;
    };
    
    template <typename T>
    class NativeObject : public AbstractObject {
    public:
        NativeObject(T &t)
            : object(t),
              AbstractObject(nullptr),
              owning{false} {
        }
        
        NativeObject(T &t, bool own)
            : object(t),
              AbstractObject(nullptr),
              owning(own) {
        }
        
        ~NativeObject<T>() {
        }
        
        T& getObject() {
            return object;
        }
        
        void release();
        void retain();
        
        std::string toString(JSContextRef, JSValueRef*);
        double toNumber(JSContextRef, JSValueRef*);
        bool toBoolean(JSContextRef, JSValueRef*);
        
        bool hasInstance(JSContextRef, JSValueRef, JSValueRef*);
        
    private:
        T object;
        bool owning;
    };
    
    /// JSObjectRef (as function callback) specialization
    
    template<>
    class NativeObject<JSObjectRef> : public AbstractObject 
    {
    public:
        
        NativeObject(JSObjectRef object, void* data)
            : object(object),
              AbstractObject(data) {
            JSValueProtect(HyperloopGlobalContext(), object);
        }
        
        ~NativeObject() {
            JSValueUnprotect(HyperloopGlobalContext(), object);
        }
        
        JSObjectRef getObject() {
            return object;
        }
        
    private:
        JSObjectRef object;
    };
    
    // int specialization
    template<>
    class NativeObject<int> : public AbstractObject 
    {
    public:
        
        NativeObject(int object)
            : object(object),
              AbstractObject(nullptr) {
        }
        
        ~NativeObject() {
        }
        
        int getObject() {
            return object;
        }
        
        void release() {
            delete this;
        }
        
        void retain() {
        }
        
        std::string toString(JSContextRef ctx, JSValueRef* exception) {
            char buf[sizeof(void*)];
#ifdef _WIN32
            sprintf_s(buf,"%d",this->object);
#else
            sprintf(buf,"%d",this->object);
#endif
            return std::string(buf);
        }
        
        double toNumber(JSContextRef ctx, JSValueRef* exception) {
            return this->object;
        }
        
        bool toBoolean(JSContextRef ctx, JSValueRef* exception) {
            return false;
        }
        
        bool hasInstance(JSContextRef ctx, JSValueRef other, JSValueRef* exception) {
            return this->object == (int)JSValueToNumber(ctx, other, exception);
        }
        
    private:
        int object;
    };
    
    /// void * specialization
    
    template<>
    inline void Hyperloop::NativeObject<void *>::release() {
        if (this->owning && this->object != nullptr) {
            free(this->object);
        }
        delete this;
    }
    
    template<>
    inline void Hyperloop::NativeObject<void *>::retain() {
    }
    
    template<>
    inline bool Hyperloop::NativeObject<void *>::hasInstance(JSContextRef ctx, JSValueRef other, JSValueRef* exception) {
        return false;
    }
    
    template<>
    inline std::string Hyperloop::NativeObject<void *>::toString(JSContextRef ctx, JSValueRef* exception) {
        char buf[sizeof(void*)];
#ifdef _WIN32
        sprintf_s(buf,"%p",this->object);
#else
        sprintf(buf,"%p",this->object);
#endif
        return std::string(buf);
    }
    
    template<>
    inline double Hyperloop::NativeObject<void *>::toNumber(JSContextRef ctx, JSValueRef* exception) {
        return NAN;
    }
    
    template<>
    inline bool Hyperloop::NativeObject<void *>::toBoolean(JSContextRef ctx, JSValueRef* exception) {
        return false;
    }
    
} // namespace

#endif  // _TITANIUM_MOBILE_WINDOWS_HYPERLOOP_COMMON_H_
