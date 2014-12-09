/**
 * Titanium.Utility for Windows
 * Author: Gary Mathews
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Utility.hpp"
#include "Titanium/detail/TiBase.hpp"

namespace TitaniumWindows {

  std::vector<unsigned char> TitaniumWindows::Utility::GetContentFromBuffer(Windows::Storage::Streams::IBuffer^ buffer) {
    const auto reader = Windows::Storage::Streams::DataReader::FromBuffer(buffer);
    std::vector<unsigned char> data(reader->UnconsumedBufferLength);
    if (!data.empty()) {
      reader->ReadBytes(::Platform::ArrayReference<unsigned char>(&data[0], data.size()));
    }
    return data;
  }

  std::vector<unsigned char> TitaniumWindows::Utility::GetContentFromFile(Windows::Storage::StorageFile^ file) {
    std::vector<unsigned char> content;
    concurrency::event event;
    concurrency::task<Windows::Storage::Streams::IBuffer^>(Windows::Storage::FileIO::ReadBufferAsync(file)).then([&content, &event](concurrency::task<Windows::Storage::Streams::IBuffer^> task) {
      try {
        content = std::move(GetContentFromBuffer(task.get()));
      }
      catch (::Platform::COMException^ ex) {
        std::clog << "[WARN] " << ConvertString(ex->Message) << std::endl;
      }
      event.set();
    }, concurrency::task_continuation_context::use_arbitrary());
    event.wait();

    return content;
  }

  const std::string TitaniumWindows::Utility::MimeTypeForExtension(std::string& path) {
    const static std::unordered_map<std::string, const std::string> mimeTypeFromExtensionDict = {
      { "css", "text/css" },
      { "m4v", "video/x-m4v" }
    };

    const auto pos = path.find_last_of(".");
    if (pos != std::string::npos && path.size() > pos) {
      const auto ext = path.substr(pos + 1);
      const auto found = mimeTypeFromExtensionDict.find(ext);
      if (found != mimeTypeFromExtensionDict.end()) {
        return found->second;
      }
    }
    return "application/octet-stream";
  }

  unsigned TitaniumWindows::Utility::GetMSecSinceEpoch(Windows::Foundation::DateTime d) {
    Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
    cal->SetDateTime(d);

    std::tm tm = { cal->Second, cal->Minute, cal->Hour + (cal->Period == 1 ? 0 : 12), cal->Day, cal->Month - 1, cal->Year - 1900, 0, 0, -1 };
    const std::time_t t = std::mktime(&tm);

    return t * 1000;
  }

}  // namespace TitaniumWindows
