/**
 * Titanium.Utility for Windows
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UTILITY_HPP_
#define _TITANIUMWINDOWS_UTILITY_HPP_

#include <string>
#include <locale>
#include <codecvt>
#include <ppltasks.h>

namespace TitaniumWindows {
	namespace Utility {

		static ::Platform::String^ ConvertString(const std::string& str) {
			return ref new ::Platform::String(std::wstring(str.begin(), str.end()).c_str());
		}

		static std::string ConvertString(::Platform::String^ str) {
			std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
			return std::string(converter.to_bytes(str->Data()));
		}

    std::vector<unsigned char> GetContentFromBuffer(Windows::Storage::Streams::IBuffer^ buffer);
    std::vector<unsigned char> GetContentFromFile(Windows::Storage::StorageFile^ file);
    const std::string MimeTypeForExtension(std::string& path);
    unsigned GetMSecSinceEpoch(Windows::Foundation::DateTime d);

	} // namespace Utility
} // namespace TitaniumWindows

#endif // _TITANIUMWINDOWS_UTILITY_HPP_
