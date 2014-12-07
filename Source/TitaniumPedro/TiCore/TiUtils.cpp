#include "TiCore/TiUtils.h"
#include <unordered_map>
#include <ppltasks.h>
#include <iostream>

std::vector<unsigned char> Ti::Utils::GetContentFromBuffer(Windows::Storage::Streams::IBuffer^ buffer) {
	const auto reader = Windows::Storage::Streams::DataReader::FromBuffer(buffer);
	std::vector<unsigned char> data(reader->UnconsumedBufferLength);
	if (!data.empty()) {
		reader->ReadBytes(::Platform::ArrayReference<unsigned char>(&data[0], data.size()));
	}
	return data;
}

std::vector<unsigned char> Ti::Utils::GetContentFromFile(Windows::Storage::StorageFile^ file) {
	std::vector<unsigned char> content;
	concurrency::event event;
	concurrency::task<Windows::Storage::Streams::IBuffer^>(Windows::Storage::FileIO::ReadBufferAsync(file)).then([&content, &event](concurrency::task<Windows::Storage::Streams::IBuffer^> task) {
		try {
			content = std::move(Ti::Utils::GetContentFromBuffer(task.get()));
		} catch (::Platform::COMException^ ex) {
			std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
		}
		event.set();
	}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return content;
}

const std::string Ti::Utils::MimeTypeForExtension(std::string& path) {
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
