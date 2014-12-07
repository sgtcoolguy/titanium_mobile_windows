#pragma once

#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"

namespace titanium
{
	class View
	{
	public:

		static JSObjectRef create();
		static bool SetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception);
		static JSValueRef GetTop(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception);
		static bool SetLeft(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception);
		static JSValueRef GetLeft(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception);
	    static JSValueRef SetBackground(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
	};
}
