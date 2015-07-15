#include <collection.h>
#include <ppltasks.h>
#include "JS.h"

using namespace JavaScriptCore;
using namespace Platform;

namespace JavaScriptCore
{
	/*
	 * Pointer conversion helper functions
	 */
#define _CAST(name, claz) \
::claz name(claz^ obj) {\
	IntPtr ptr = nullptr;\
	if (obj != nullptr) {\
		ptr = obj->GetNativePointer();\
	}\
	return (::claz)(void*)ptr;\
}

	_CAST(_CTX, JSContextRef);
	_CAST(_CTXG, JSContextGroupRef);
	_CAST(_STR, JSStringRef);
	_CAST(_VAL, JSValueRef);
	_CAST(_OBJ, JSObjectRef);
	_CAST(_CLS, JSClassRef);
	_CAST(_PROP_ACCUM, JSPropertyNameAccumulatorRef);
	_CAST(_PROP_ARRAY, JSPropertyNameArrayRef);

#define BEGIN_JSEXCEPTION(val, name)\
	IntPtr name = 0;\
	if (val != nullptr) {\
		name = val->GetNativePointer();\
	}\

#define COMMIT_JSEXCEPTION(val, name)\
	if (val != nullptr) {\
		val->Update(name);\
	}\

#define BEGIN_JSARGS(arguments, argumentCount, name, T)\
	::T* name = (::T*)malloc(sizeof(::T)*argumentCount);\
	for (auto i = 0; i < argumentCount; i++) {\
		name[i] = (::T)(void*)arguments->GetAt(i)->GetNativePointer(); \
	}\

#define COMMIT_JSARGS(name) free(name)

	JSContextRef^ JS::JSGlobalContextCreate()
	{
		return ref new JSContextRef(::JSGlobalContextCreate(nullptr));
	}

	JSValueRef^ JS::JSValueMakeNull(JSContextRef^ ctx)
	{
		IntPtr ptr = (void*)::JSValueMakeNull(_CTX(ctx));
		return ref new JSValueRef(ptr);
	}

	void JS::JSGarbageCollect(JSContextRef^ ctx)
	{
		::JSGarbageCollect(_CTX(ctx));
	}

	bool JS::JSCheckScriptSyntax(JSContextRef^ ctx, String^ script, String^ sourceURL, int startingLineNumber, JSValueRef^ exception)
	{
		JSStringRef^ scriptRef = JSStringCreateWithUTF8PlatformString(script);
		JSStringRef^ sourceURLRef = JSStringCreateWithUTF8PlatformString(sourceURL);
		auto result = JSCheckScriptSyntax(ctx, scriptRef, sourceURLRef, startingLineNumber, exception);
		JSStringRelease(scriptRef);
		JSStringRelease(sourceURLRef);
		return result;
	}

	bool JS::JSCheckScriptSyntax(JSContextRef^ ctx, JSStringRef^ script, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSCheckScriptSyntax(_CTX(ctx), _STR(script), _STR(sourceURL), startingLineNumber, (::JSValueRef*) &exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return result;
	}

	JSValueRef^ JS::JSEvaluateScript(JSContextRef^ ctx, String^ script, JSObjectRef^ thisObject, String^ sourceURL, int startingLineNumber, JSValueRef^ exception)
	{
		JSStringRef^ scriptRef = JSStringCreateWithUTF8PlatformString(script);
		JSStringRef^ sourceURLRef = JSStringCreateWithUTF8PlatformString(sourceURL);
		auto result = JSEvaluateScript(ctx, scriptRef, thisObject, sourceURLRef, startingLineNumber, exception);
		JSStringRelease(scriptRef);
		JSStringRelease(sourceURLRef);
		return result;
	}

	JSValueRef^ JS::JSEvaluateScript(JSContextRef^ ctx, JSStringRef^ script, JSObjectRef^ thisObject, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSEvaluateScript(_CTX(ctx), _STR(script), _OBJ(thisObject), _STR(sourceURL), startingLineNumber, (::JSValueRef*) &exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return ref new JSValueRef((void*)result);
	}

	JSClassRef^ JS::JSClassCreate(JSClassDefinition^ definition) {
		::JSClassDefinition* jsClassDef = (::JSClassDefinition*)(void*)definition->GetNativePointer();
		IntPtr ptr = (void*)::JSClassCreate(jsClassDef);
		return ref new JSClassRef(ptr);
	}

	JSValueRef^ JS::JSObjectToJSValue(JSObjectRef^ obj)
	{
		return ref new JSValueRef(obj->GetNativePointer());
	}

	JSObjectRef^ JS::JSObjectMake(JSContextRef^ ctx, JSClassRef^ jsClass, int data)
	{
		::JSClassRef jsClassRef = nullptr;
		if (jsClass != nullptr)
		{
			jsClassRef = (::JSClassRef)(void*)jsClass->GetNativePointer();
		}
		IntPtr ptr = (void*)::JSObjectMake(_CTX(ctx), jsClassRef, (void*)(IntPtr)data);
		return ref new JSObjectRef(ptr);
	}

	JSStringRef^ JS::JSStringCreateWithUTF8PlatformString(String^ string)
	{
		if (string == nullptr) return nullptr;

		std::wstring wstr(string->Begin());
		std::string str(wstr.begin(), wstr.end());
		const char* c_str = str.c_str();

		IntPtr ptr = (void*)::JSStringCreateWithUTF8CString(c_str);
		return ref new JSStringRef(ptr);
	}
	int JS::JSStringGetLength(JSStringRef^ str)
	{
		return ::JSStringGetLength(_STR(str));
	}
	int JS::JSStringGetMaximumUTF8PlatformStringSize(JSStringRef^ str)
	{
		return ::JSStringGetMaximumUTF8CStringSize(_STR(str));
	}
	String^ JS::JSStringGetUTF8PlatformString(JSStringRef^ str)
	{
		size_t bufferSize = JS::JSStringGetMaximumUTF8PlatformStringSize(str);
		char* source = new char[bufferSize];
		size_t size = ::JSStringGetUTF8CString(_STR(str), source, bufferSize);
		wchar_t* wbuffer = new wchar_t[bufferSize];
		mbstowcs_s(&size, wbuffer, bufferSize, source, bufferSize);
		delete[] source;
		String^ result = ref new String(wbuffer);
		delete[] wbuffer;
		return result;
	}
	bool JS::JSStringIsEqual(JSStringRef^ a, JSStringRef^ b)
	{
		return ::JSStringIsEqual(_STR(a), _STR(b));
	}
	bool JS::JSStringIsEqualToUTF8PlatformString(JSStringRef^ a, String^ b)
	{
		std::wstring wstr(b->Begin());
		std::string bstr(wstr.begin(), wstr.end());
		const char* b_str = bstr.c_str();

		return ::JSStringIsEqualToUTF8CString(_STR(a), b_str);
	}
	void JS::JSStringRelease(JSStringRef^ str)
	{
		if (str != nullptr) 
		{
			::JSStringRelease(_STR(str));
		}
	}
	JSStringRef^ JS::JSStringRetain(JSStringRef^ str)
	{
		IntPtr ptr = (void*)::JSStringRetain(_STR(str));
		return ref new JSStringRef(ptr);
	}

	JSClassDefinition^ JS::kJSClassDefinitionEmpty() {
		return ref new JSClassDefinition((void*)&::kJSClassDefinitionEmpty);
	}

	JSContextRef^ JS::JSGlobalContextCreate(JSClassRef^ globalObjectClass)
	{
		return ref new JSContextRef(::JSGlobalContextCreate(_CLS(globalObjectClass)));
	}
	JSContextRef^ JS::JSGlobalContextCreateInGroup(JSContextGroupRef^ group, JSClassRef^ globalObjectClass) 
	{
		return ref new JSContextRef(::JSGlobalContextCreateInGroup(_CTXG(group), _CLS(globalObjectClass)));
	}
	void JS::JSGlobalContextRelease(JSContextRef^ ctx)
	{
		::JSGlobalContextRelease((::JSGlobalContextRef)_CTX(ctx));
	}
	JSContextRef^ JS::JSGlobalContextRetain(JSContextRef^ ctx)
	{
		return ref new JSContextRef(::JSGlobalContextRetain((::JSGlobalContextRef)_CTX(ctx)));
	}
	void JS::JSClassRelease(JSClassRef^ jsClass)
	{
		::JSClassRelease(_CLS(jsClass));
	}
	JSClassRef^ JS::JSClassRetain(JSClassRef^ jsClass)
	{
		return ref new JSClassRef(::JSClassRetain(_CLS(jsClass)));
	}

	bool JS::JSValueIsBoolean(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsBoolean(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueIsEqual(JSContextRef^ ctx, JSValueRef^ a, JSValueRef^ b, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueIsEqual(_CTX(ctx), _VAL(a), _VAL(b), (::JSValueRef*) &exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return result;
	}
	bool JS::JSValueIsInstanceOfConstructor(JSContextRef^ ctx, JSValueRef^ value, JSObjectRef^ constructor, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueIsInstanceOfConstructor(_CTX(ctx), _VAL(value), _OBJ(constructor), (::JSValueRef*) &exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return result;
	}
	bool JS::JSValueIsNull(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsNull(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueIsNumber(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsNumber(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueIsObject(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsObject(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueIsObjectOfClass(JSContextRef^ ctx, JSValueRef^ value, JSClassRef^ jsClass)
	{
		return ::JSValueIsObjectOfClass(_CTX(ctx), _VAL(value), _CLS(jsClass));
	}
	bool JS::JSValueIsString(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsString(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueIsStrictEqual(JSContextRef^ ctx, JSValueRef^ a, JSValueRef^ b)
	{
		return ::JSValueIsStrictEqual(_CTX(ctx), _VAL(a), _VAL(b));
	}
	bool JS::JSValueIsUndefined(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueIsUndefined(_CTX(ctx), _VAL(value));
	}

	JSObjectRef^ JS::JSContextGetGlobalObject(JSContextRef^ ctx)
	{
		return ref new JSObjectRef(::JSContextGetGlobalObject(_CTX(ctx)));
	}
	JSContextGroupRef^ JS::JSContextGetGroup(JSContextRef^ ctx)
	{
		return ref new JSContextGroupRef((void*)::JSContextGetGroup(_CTX(ctx)));
	}
	JSContextGroupRef^ JS::JSContextGroupCreate()
	{
		return ref new JSContextGroupRef((void*)::JSContextGroupCreate());
	}
	void JS::JSContextGroupRelease(JSContextGroupRef^ group)
	{
		::JSContextGroupRelease(_CTXG(group));
	}

	JSValueRef^ JS::JSValueMakeBoolean(JSContextRef^ ctx, bool value)
	{
		return ref new JSValueRef((void*)::JSValueMakeBoolean(_CTX(ctx), value));
	}
	JSValueRef^ JS::JSValueMakeFromJSONString(JSContextRef^ ctx, JSStringRef^ str)
	{
		return ref new JSValueRef((void*)::JSValueMakeFromJSONString(_CTX(ctx), _STR(str)));
	}
	JSValueRef^ JS::JSValueMakeNumber(JSContextRef^ ctx, double number)
	{
		return ref new JSValueRef((void*)::JSValueMakeNumber(_CTX(ctx),number));
	}
	JSValueRef^ JS::JSValueMakeString(JSContextRef^ ctx, String^ str)
	{
		JSStringRef^ strRef = JSStringCreateWithUTF8PlatformString(str);
		auto result = JSValueMakeString(ctx, strRef);
		JSStringRelease(strRef);
		return result;
	}
	JSValueRef^ JS::JSValueMakeString(JSContextRef^ ctx, JSStringRef^ str)
	{
		return ref new JSValueRef((void*)::JSValueMakeString(_CTX(ctx), _STR(str)));
	}
	JSValueRef^ JS::JSValueMakeUndefined(JSContextRef^ ctx)
	{
		return ref new JSValueRef((void*)::JSValueMakeUndefined(_CTX(ctx)));
	}
	void JS::JSValueProtect(JSContextRef^ ctx, JSValueRef^ value)
	{
		::JSValueProtect(_CTX(ctx), _VAL(value));
	}
	bool JS::JSValueToBoolean(JSContextRef^ ctx, JSValueRef^ value)
	{
		return ::JSValueToBoolean(_CTX(ctx), _VAL(value));
	}
	double JS::JSValueToNumber(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueToNumber(_CTX(ctx), _VAL(value), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return result;
	}
	JSObjectRef^ JS::JSValueToObject(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueToObject(_CTX(ctx), _VAL(value), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return ref new JSObjectRef(result);
	}
	String^ JS::JSValueToString(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception)
	{
		JSStringRef^ str = JSValueToStringCopy(ctx, value, exception);
		auto result = JSStringGetUTF8PlatformString(str);
		JSStringRelease(str);
		return result;
	}
	JSStringRef^ JS::JSValueToStringCopy(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueToStringCopy(_CTX(ctx), _VAL(value), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return ref new JSStringRef(result);
	}
	void JS::JSValueUnprotect(JSContextRef^ ctx, JSValueRef^ value)
	{
		::JSValueUnprotect(_CTX(ctx), _VAL(value));
	}

	void JS::JSPropertyNameAccumulatorAddName(JSPropertyNameAccumulatorRef^ accumulator, JSStringRef^ propertyName)
	{
		::JSPropertyNameAccumulatorAddName(_PROP_ACCUM(accumulator), _STR(propertyName));
	}
	int JS::JSPropertyNameArrayGetCount(JSPropertyNameArrayRef^ array)
	{
		return ::JSPropertyNameArrayGetCount(_PROP_ARRAY(array));
	}
	JSStringRef^ JS::JSPropertyNameArrayGetNameAtIndex(JSPropertyNameArrayRef^ array, int index)
	{
		return ref new JSStringRef(::JSPropertyNameArrayGetNameAtIndex(_PROP_ARRAY(array), index));
	}
	void JS::JSPropertyNameArrayRelease(JSPropertyNameArrayRef^ array)
	{
		::JSPropertyNameArrayRelease(_PROP_ARRAY(array));
	}
	JSPropertyNameArrayRef^ JS::JSPropertyNameArrayRetain(JSPropertyNameArrayRef^ array)
	{
		return ref new JSPropertyNameArrayRef(::JSPropertyNameArrayRetain(_PROP_ARRAY(array)));
	}
	JSStringRef^ JS::JSValueCreateJSONString(JSContextRef^ ctx, JSValueRef^ value, int indent, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSValueCreateJSONString(_CTX(ctx), _VAL(value), indent, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);

		return ref new JSStringRef(result);
	}
	JSType JS::JSValueGetType(JSContextRef^ ctx, JSValueRef^ value)
	{
		return (JSType)::JSValueGetType(_CTX(ctx), _VAL(value));
	}

	void JS::JSObjectSetProperty(JSContextRef^ ctx, JSObjectRef^ object, String^ propertyName, JSValueRef^ value, int attributes, JSValueRef^ exception)
	{
		JSStringRef^ propertyNameRef = JSStringCreateWithUTF8PlatformString(propertyName);
		JSObjectSetProperty(ctx, object, propertyNameRef, value, attributes, exception);
		JSStringRelease(propertyNameRef);
	}

	void JS::JSObjectSetProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName, JSValueRef^ value, int attributes, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		::JSObjectSetProperty(_CTX(ctx), _OBJ(object), _STR(propertyName), _VAL(value), attributes, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
	}
	void JS::JSObjectSetPropertyAtIndex(JSContextRef^ ctx, JSObjectRef^ object, int propertyIndex, JSValueRef^ value, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		::JSObjectSetPropertyAtIndex(_CTX(ctx), _OBJ(object), propertyIndex, _VAL(value), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
	}
	void JS::JSObjectSetPrototype(JSContextRef^ ctx, JSObjectRef^ object, JSValueRef^ value)
	{
		::JSObjectSetPrototype(_CTX(ctx), _OBJ(object), _VAL(value));
	}

	JSValueRef^ JS::JSObjectGetProperty(JSContextRef^ ctx, JSObjectRef^ obj, String^ propertyName, JSValueRef^ exception)
	{
		JSStringRef^ propertyNameRef = JSStringCreateWithUTF8PlatformString(propertyName);
		auto result = JSObjectGetProperty(ctx, obj, propertyNameRef, exception);
		JSStringRelease(propertyNameRef);
		return result;
	}

	JSValueRef^ JS::JSObjectGetProperty(JSContextRef^ ctx, JSObjectRef^ obj, JSStringRef^ propertyName, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectGetProperty(_CTX(ctx), _OBJ(obj), _STR(propertyName), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return ref new JSValueRef((void*)result);
	}
	int JS::JSObjectGetPrivate(JSObjectRef^ obj)
	{
		return ((IntPtr)(void*)::JSObjectGetPrivate(_OBJ(obj))).ToInt32();
	}
	JSPropertyNameArrayRef^ JS::JSObjectCopyPropertyNames(JSContextRef^ ctx, JSObjectRef^ object)
	{
		return ref new JSPropertyNameArrayRef(::JSObjectCopyPropertyNames(_CTX(ctx), _OBJ(object)));
	}
	bool JS::JSObjectDeleteProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectDeleteProperty(_CTX(ctx), _OBJ(object), _STR(propertyName), (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return result;
	}
	JSValueRef^ JS::JSObjectGetPropertyAtIndex(JSContextRef^ ctx, JSObjectRef^ object, int propertyIndex, JSValueRef^ exception)
	{
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectGetPropertyAtIndex(_CTX(ctx), _OBJ(object), propertyIndex, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		return ref new JSValueRef((void*)result);
	}
	JSValueRef^ JS::JSObjectGetPrototype(JSContextRef^ ctx, JSObjectRef^ object)
	{
		return ref new JSValueRef((void*)::JSObjectGetPrototype(_CTX(ctx), _OBJ(object)));
	}
	bool JS::JSObjectHasProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName)
	{
		return ::JSObjectHasProperty(_CTX(ctx), _OBJ(object), _STR(propertyName));
	}
	bool JS::JSObjectIsConstructor(JSContextRef^ ctx, JSObjectRef^ object)
	{
		return ::JSObjectIsConstructor(_CTX(ctx), _OBJ(object));
	}
	bool JS::JSObjectIsFunction(JSContextRef^ ctx, JSObjectRef^ object)
	{
		return ::JSObjectIsFunction(_CTX(ctx), _OBJ(object));
	}

	JSObjectRef^ JS::JSObjectCallAsConstructor(JSContextRef^ ctx, JSObjectRef^ obj, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectCallAsConstructor(_CTX(ctx), _OBJ(obj), argumentCount, jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSObjectRef(result);
	}

	JSValueRef^ JS::JSObjectCallAsFunction(JSContextRef^ ctx, JSObjectRef^ obj, JSObjectRef^ thisObject, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectCallAsFunction(_CTX(ctx), _OBJ(obj), _OBJ(thisObject), argumentCount, jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSValueRef((void*)result);
	}

	JSObjectRef^ JS::JSObjectMakeArray(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectMakeArray(_CTX(ctx), argumentCount,jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSObjectRef(result);
	}
	JSObjectRef^ JS::JSObjectMakeDate(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectMakeDate(_CTX(ctx), argumentCount, jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSObjectRef(result);
	}
	JSObjectRef^ JS::JSObjectMakeRegExp(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectMakeRegExp(_CTX(ctx), argumentCount, jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSObjectRef(result);
	}
	JSObjectRef^ JS::JSObjectMakeError(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception)
	{
		BEGIN_JSARGS(arguments, argumentCount, jsArgs, JSValueRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectMakeError(_CTX(ctx), argumentCount, jsArgs, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsArgs);

		return ref new JSObjectRef(result);
	}
	JSObjectRef^ JS::JSObjectMakeConstructor(JSContextRef^ ctx, JSClassRef^ jsClass, int callAsConstructor)
	{
		return ref new JSObjectRef(::JSObjectMakeConstructor(_CTX(ctx), _CLS(jsClass), (JSObjectCallAsConstructorCallback)callAsConstructor));
	}
	JSObjectRef^ JS::JSObjectMakeFunction(JSContextRef^ ctx, JSStringRef^ name, int parameterCount, IVector<JSStringRef^>^ parameterNames, JSStringRef^ body, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception)
	{
		BEGIN_JSARGS(parameterNames, parameterCount, jsParams, JSStringRef);
		BEGIN_JSEXCEPTION(exception, exceptionPtr);
		auto result = ::JSObjectMakeFunction(_CTX(ctx), _STR(name), parameterCount, jsParams, _STR(body), _STR(sourceURL), startingLineNumber, (::JSValueRef*)&exceptionPtr);
		COMMIT_JSEXCEPTION(exception, exceptionPtr);
		COMMIT_JSARGS(jsParams);

		return ref new JSObjectRef(result);
	}
	JSObjectRef^ JS::JSObjectMakeFunctionWithCallback(JSContextRef^ ctx, String^ name, int callAsFunction)
	{
		JSStringRef^ nameRef = JSStringCreateWithUTF8PlatformString(name);
		auto result = JSObjectMakeFunctionWithCallback(ctx, nameRef, callAsFunction);
		JSStringRelease(nameRef);
		return result;
	}
	JSObjectRef^ JS::JSObjectMakeFunctionWithCallback(JSContextRef^ ctx, JSStringRef^ name, int callAsFunction)
	{
		return ref new JSObjectRef(::JSObjectMakeFunctionWithCallback(_CTX(ctx), _STR(name), (JSObjectCallAsFunctionCallback)callAsFunction));
	}

	int JS::CreateNewObjectKey() 
	{
		return ((IntPtr)malloc(1)).ToInt32();
	}

	void JS::ReleaseObjectKey(int key) {
		free((void*)(IntPtr)key);
	}
}
