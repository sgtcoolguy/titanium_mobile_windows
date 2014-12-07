#pragma once

#include <JavaScriptCore/JavaScript.h>

namespace titanium
{
	class UI
	{
	public:

		static JSObjectRef create(JSObjectRef container);
		static JSValueRef createWindow(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
		static JSValueRef createView(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
	};
}