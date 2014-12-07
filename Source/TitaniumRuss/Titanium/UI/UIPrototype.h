#pragma once

#include <JavaScriptCore/JavaScript.h>
#include "common/Utils.h"

using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Input;

namespace titanium
{
	class UIPrototype
	{
	public:

		static  JSClassRef create(); 
		static void classDestructor(JSObjectRef object);
		static bool SetWidth(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception);
		static JSValueRef GetWidth(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception);
		static bool SetHeight(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, const JSValueRef value, JSValueRef* exception);
		static JSValueRef GetHeight(JSContextRef ctx, JSObjectRef thisObject,  JSStringRef propertyName, JSValueRef* exception);
		static JSValueRef AddEventListener(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef* exception);
	
	};

	ref class ManipulationHandler sealed
	{
	public:
		ManipulationHandler();
		void ManipulationDelta(Object^ sender, ManipulationDeltaRoutedEventArgs^ e);
		void SetContext(int64 context);
		void SetDeltaCallback(int64 callback);
		void SetSource(int64 source);

	private:
		JSObjectRef createEventArgs(JSContextRef ctx, JSObjectRef source, ManipulationDeltaRoutedEventArgs^ e);

		float angle;
		Point translation;
		JSContextRef context;
		JSObjectRef deltaCallback;
		JSObjectRef source;	
	};
}
