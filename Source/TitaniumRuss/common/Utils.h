#pragma once

using namespace Platform;
#include <string>
#include <JavaScriptCore/JavaScript.h>

using namespace Windows::UI::Xaml;

static JSContextRef app_context;

#include "Titanium/UI/UIPrototype.h"

namespace titanium
{
	class Utils
	{
	public:
		static Platform::String^ getPlatformString(JSStringRef sValue);
		static std::string getSTDString(JSStringRef sValue);
		static JSStringRef getJSStringRef(Platform::String^ string);
		static JSContextRef getAppContext();
		static void setAppContext(JSContextRef context);

		static std::string       ConvertPlatformStringToStdString(Platform::String^ platformString);
		static Platform::String^ ConvertStdStringToPlatformString(const std::string& string);
		static std::string       loadFile(const std::string& logicalFilePath);
	private:
		Utils();
	};

	class PrivateObjectContainer
	{
	private:
		Object^ obj;		
	public:
		void set(Object^ obj) {
			this->obj = obj;
		}
		Object^ get() {
			return obj;
		}
		void clean() {
			// native object should now be ready for release 
			obj = nullptr;
		}
		
		// ToDo add handlers here
		ManipulationHandler^ manipulationHandler;
		
	};
}
