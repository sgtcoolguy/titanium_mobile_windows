#include "Utils.h"
#include <iostream>
#include <fstream>
#include <vector>

Platform::String^ titanium::Utils::getPlatformString(JSStringRef sValue) {
	size_t sLength = JSStringGetMaximumUTF8CStringSize(sValue);
	char* cValue = new char[sLength];
	JSStringGetUTF8CString(sValue, cValue, sLength);
	std::string s_str = cValue;
	std::wstring w_str(s_str.begin(), s_str.end());
	return ref new Platform::String(w_str.c_str());
}

std::string titanium::Utils::getSTDString(JSStringRef sValue) {
	size_t sLength = JSStringGetMaximumUTF8CStringSize(sValue);
	char* cValue = new char[sLength];
	JSStringGetUTF8CString(sValue, cValue, sLength);
	std::string s_str = cValue;
	return s_str;
}

JSStringRef titanium::Utils::getJSStringRef(Platform::String^ string) {
	std::wstring w_str(string->Begin());
	std::string s_str(w_str.begin(), w_str.end());
	const char* charStr = s_str.c_str();
	return JSStringCreateWithUTF8CString(charStr);
}


 JSContextRef titanium::Utils::getAppContext() {
	return app_context;
}

 void titanium::Utils::setAppContext(JSContextRef context) {
	 app_context = context;
}

 std::string titanium::Utils::ConvertPlatformStringToStdString(Platform::String^ platformString) {
	 const std::wstring wstring(platformString->Data());
	 const std::string string(wstring.begin(), wstring.end());
	 return string;
 }

 Platform::String^ titanium::Utils::ConvertStdStringToPlatformString(const std::string& string) {
	 const std::wstring wstring(string.begin(), string.end());
	 const auto platformString = ref new Platform::String(wstring.c_str());
	 return platformString;
 }

std::string
titanium::Utils::loadFile(const std::string& logicalFilePath) {
	const auto folder   = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
	const auto filePath = folder + ConvertStdStringToPlatformString(logicalFilePath);

	std::ifstream inputFile;
	inputFile.open(filePath->Data());

	std::string fileContents;
	while (!inputFile.eof()) {
		std::string line;
		getline(inputFile, line);
		fileContents += line + "\n";
	}

	return fileContents;
}
