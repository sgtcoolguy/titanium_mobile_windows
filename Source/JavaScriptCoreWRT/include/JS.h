#pragma unmanaged

#include "JavaScriptCore\JSBase.h"
#include "JavaScriptCore\JSStringRef.h"
#include "JavaScriptCore\JSContextRef.h"
#include "JavaScriptCore\JSValueRef.h"
#include "JavaScriptCore\JSObjectRef.h"

using namespace Platform;
using namespace Windows::Foundation::Collections;

namespace JavaScriptCore
{
	public ref class JSContextRef sealed
	{
	public:
		JSContextRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSContextRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSContextGroupRef sealed
	{
	public:
		JSContextGroupRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSContextGroupRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSClassRef sealed
	{
	public:
		JSClassRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSClassRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSClassDefinition sealed
	{
	public:
		JSClassDefinition(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSClassDefinition(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSValueRef sealed
	{
	public:
		JSValueRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSValueRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
		int GetNativePointerAsInt() { return this->ptr;  }
		void Update(IntPtr ptr) {
			this->ptr = ptr.ToInt32();
		}
	private:
		int ptr;
	};
	public ref class JSObjectRef sealed
	{
	public:
		JSObjectRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSObjectRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
		int GetNativePointerAsInt() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSStringRef sealed
	{
	public:
		JSStringRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSStringRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSPropertyNameAccumulatorRef sealed
	{
	public:
		JSPropertyNameAccumulatorRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSPropertyNameAccumulatorRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};
	public ref class JSPropertyNameArrayRef sealed
	{
	public:
		JSPropertyNameArrayRef(IntPtr ptr) : ptr(ptr.ToInt32()) { }
		JSPropertyNameArrayRef(int ptr) : ptr(ptr) { }
		IntPtr GetNativePointer() { return this->ptr; }
	private:
		int ptr;
	};

	public enum class JSType : int {
		kJSTypeUndefined,
		kJSTypeNull,
		kJSTypeBoolean,
		kJSTypeNumber,
		kJSTypeString,
		kJSTypeObject
	};

	public ref class JS sealed
	{
	public:
		static JSObjectRef^ JSObjectMakeArray(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);
		static JSObjectRef^ JSObjectMakeDate(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);
		static JSObjectRef^ JSObjectMakeRegExp(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);
		static JSObjectRef^ JSObjectMakeError(JSContextRef^ ctx, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);
		static JSObjectRef^ JSObjectMakeConstructor(JSContextRef^ ctx, JSClassRef^ jsClass, int callAsConstructor);
		static JSObjectRef^ JSObjectMakeFunction(JSContextRef^ ctx, JSStringRef^ name, int parameterCount, IVector<JSStringRef^>^ parameterNames, JSStringRef^ body, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception);
		static JSObjectRef^ JSObjectMakeFunctionWithCallback(JSContextRef^ ctx, String^ name, int callAsFunction);
		static JSObjectRef^ JSObjectMakeFunctionWithCallback(JSContextRef^ ctx, JSStringRef^ name, int callAsFunction);

		static JSObjectRef^ JSObjectCallAsConstructor(JSContextRef^ ctx, JSObjectRef^ obj, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);
		static JSValueRef^ JSObjectCallAsFunction(JSContextRef^ ctx, JSObjectRef^ obj, JSObjectRef^ thisObject, int argumentCount, IVector<JSValueRef^>^ arguments, JSValueRef^ exception);

		static JSContextRef^ JSGlobalContextCreate(JSClassRef^ globalObjectClass);
		static JSContextRef^ JSGlobalContextCreateInGroup(JSContextGroupRef^ group, JSClassRef^ globalObjectClass);
		static void JSGlobalContextRelease(JSContextRef^ ctx);
		static JSContextRef^ JSGlobalContextRetain(JSContextRef^ ctx);
		static void JSClassRelease(JSClassRef^ jsClass);
		static JSClassRef^ JSClassRetain(JSClassRef^ jsClass);

		static JSClassRef^ JSClassCreate(JSClassDefinition^ definition);
		static JSObjectRef^ JSObjectMake(JSContextRef^ ctx, JSClassRef^ jsClass, int data);
		static JSContextRef^ JSGlobalContextCreate();
		static void JSGarbageCollect(JSContextRef^ ctx);

		static bool JSCheckScriptSyntax(JSContextRef^ ctx, String^ script, String^ sourceURL, int startingLineNumber, JSValueRef^ exception);
		static bool JSCheckScriptSyntax(JSContextRef^ ctx, JSStringRef^ script, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception);

		static JSValueRef^ JSEvaluateScript(JSContextRef^ ctx, String^ script, JSObjectRef^ thisObject, String^ sourceURL, int startingLineNumber, JSValueRef^ exception);
		static JSValueRef^ JSEvaluateScript(JSContextRef^ ctx, JSStringRef^ script, JSObjectRef^ thisObject, JSStringRef^ sourceURL, int startingLineNumber, JSValueRef^ exception);

		static JSValueRef^ JSValueMakeNull(JSContextRef^ ctx);

		static JSStringRef^ JSStringCreateWithUTF8PlatformString(String^ str);
		static int JSStringGetLength(JSStringRef^ string);
		static int JSStringGetMaximumUTF8PlatformStringSize(JSStringRef^ string);
		static String^ JSStringGetUTF8PlatformString(JSStringRef^ string);
		static bool JSStringIsEqual(JSStringRef^ a, JSStringRef^ b);
		static bool JSStringIsEqualToUTF8PlatformString(JSStringRef^ a, String^ b);
		static void JSStringRelease(JSStringRef^ string);
		static JSStringRef^ JSStringRetain(JSStringRef^ string);

		static bool JSValueIsBoolean(JSContextRef^ ctx, JSValueRef^ value);
		static bool JSValueIsEqual(JSContextRef^ ctx, JSValueRef^ a, JSValueRef^ b, JSValueRef^ exception);
		static bool JSValueIsInstanceOfConstructor(JSContextRef^ ctx, JSValueRef^ value, JSObjectRef^ constructor, JSValueRef^ exception);
		static bool JSValueIsNull(JSContextRef^ ctx, JSValueRef^ value);
		static bool JSValueIsNumber(JSContextRef^ ctx, JSValueRef^ value);
		static bool JSValueIsObject(JSContextRef^ ctx, JSValueRef^ value);
		static bool JSValueIsObjectOfClass(JSContextRef^ ctx, JSValueRef^ value, JSClassRef^ jsClass);
		static bool JSValueIsStrictEqual(JSContextRef^ ctx, JSValueRef^ a, JSValueRef^ b);
		static bool JSValueIsUndefined(JSContextRef^ ctx, JSValueRef^ value);

		static JSObjectRef^ JSContextGetGlobalObject(JSContextRef^ ctx);
		static JSContextGroupRef^ JSContextGetGroup(JSContextRef^ ctx);
		static JSContextGroupRef^ JSContextGroupCreate();
		static void JSContextGroupRelease(JSContextGroupRef^ group);

		static JSValueRef^ JSObjectToJSValue(JSObjectRef^ obj);

		static JSValueRef^ JSValueMakeBoolean(JSContextRef^ ctx, bool boolean);
		static JSValueRef^ JSValueMakeFromJSONString(JSContextRef^ ctx, JSStringRef^ string);
		static JSValueRef^ JSValueMakeNumber(JSContextRef^ ctx, double number);
		static JSValueRef^ JSValueMakeString(JSContextRef^ ctx, String^ string);
		static JSValueRef^ JSValueMakeString(JSContextRef^ ctx, JSStringRef^ string);
		static JSValueRef^ JSValueMakeUndefined(JSContextRef^ ctx);
		static void JSValueProtect(JSContextRef^ ctx, JSValueRef^ value);
		static bool JSValueToBoolean(JSContextRef^ ctx, JSValueRef^ value);
		static double JSValueToNumber(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception);
		static JSObjectRef^ JSValueToObject(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception);
		static String^ JSValueToString(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception);
		static JSStringRef^ JSValueToStringCopy(JSContextRef^ ctx, JSValueRef^ value, JSValueRef^ exception);
		static void JSValueUnprotect(JSContextRef^ ctx, JSValueRef^ value);

		static void JSPropertyNameAccumulatorAddName(JSPropertyNameAccumulatorRef^ accumulator, JSStringRef^ propertyName);
		static int JSPropertyNameArrayGetCount(JSPropertyNameArrayRef^ array);
		static JSStringRef^ JSPropertyNameArrayGetNameAtIndex(JSPropertyNameArrayRef^ array, int index);
		static void JSPropertyNameArrayRelease(JSPropertyNameArrayRef^ array);
		static JSPropertyNameArrayRef^ JSPropertyNameArrayRetain(JSPropertyNameArrayRef^ array);
		static JSStringRef^ JSValueCreateJSONString(JSContextRef^ ctx, JSValueRef^ value, int indent, JSValueRef^ exception);
		static JSType JSValueGetType(JSContextRef^ ctx, JSValueRef^ value);

		static JSClassDefinition^ kJSClassDefinitionEmpty();

		static void JSObjectSetProperty(JSContextRef^ ctx, JSObjectRef^ object, String^ propertyName, JSValueRef^ value, int attributes, JSValueRef^ exception);
		static void JSObjectSetProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName, JSValueRef^ value, int attributes, JSValueRef^ exception);
		static void JSObjectSetPropertyAtIndex(JSContextRef^ ctx, JSObjectRef^ object, int propertyIndex, JSValueRef^ value, JSValueRef^ exception);
		static void JSObjectSetPrototype(JSContextRef^ ctx, JSObjectRef^ object, JSValueRef^ value);

		static JSValueRef^ JSObjectGetProperty(JSContextRef^ ctx, JSObjectRef^ obj, String^ propertyName, JSValueRef^ exception);
		static JSValueRef^ JSObjectGetProperty(JSContextRef^ ctx, JSObjectRef^ obj, JSStringRef^ propertyName, JSValueRef^ exception);
		static int JSObjectGetPrivate(JSObjectRef^ obj);
		static JSPropertyNameArrayRef^ JSObjectCopyPropertyNames(JSContextRef^ ctx, JSObjectRef^ object);
		static bool JSObjectDeleteProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName, JSValueRef^ exception);
		static JSValueRef^ JSObjectGetPropertyAtIndex(JSContextRef^ ctx, JSObjectRef^ object, int propertyIndex, JSValueRef^ exception);
		static JSValueRef^ JSObjectGetPrototype(JSContextRef^ ctx, JSObjectRef^ object);
		static bool JSObjectHasProperty(JSContextRef^ ctx, JSObjectRef^ object, JSStringRef^ propertyName);
		static bool JSObjectIsConstructor(JSContextRef^ ctx, JSObjectRef^ object);
		static  bool JSObjectIsFunction(JSContextRef^ ctx, JSObjectRef^ object);

		static int CreateNewObjectKey();
		static void ReleaseObjectKey(int key);

	private:
		JS() { }
	};

}
