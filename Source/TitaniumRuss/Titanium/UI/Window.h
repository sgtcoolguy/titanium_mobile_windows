#pragma once

#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"

namespace titanium
{
	class Window
	{
	public:

		static JSObjectRef create();
		static JSValueRef Activate(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
		static JSValueRef Add(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
	};
}
