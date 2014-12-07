/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiFilesystemFile.h"

#include <ppltasks.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <collection.h>

using namespace Windows::Storage;
using namespace Windows::Foundation::Collections;
using namespace concurrency;

namespace Filesystem {

// Called when this js proxy is created
File::File(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
	// TODO throw JS exception
	assert(!arguments.empty());

	// this assumes we already joins the arguments with separater
	name_ = arguments.at(0).toString();

	const auto location = Windows::ApplicationModel::Package::Current->InstalledLocation->Path;
	// if this path is relative path, let's use application installed location path
	if (name_.find(":\\") == std::string::npos) {
		path_ = Ti::Utils::GetPlatformString(location) + "\\" + name_;
	}
	else {
		path_ = name_;
	}

	file_ = getFileFromPathSync(path_);
	if (file_ == nullptr) {
		folder_ = getFolderFromPathSync(path_);
	}
}

// Creates a directory at the path identified by this file object.
bool File::createDirectory(const std::string& path) {
	auto separator = path.find_last_of(Ti::Constants::separator);
	const auto parent = path.substr(0, separator);
	const auto desiredName = path.substr(separator + 1);

	const auto folder = getFolderFromPathSync(parent);

	bool result = false;
	concurrency::event event;
	task<StorageFolder^>(folder->CreateFolderAsync(Ti::Utils::GetPlatformString(desiredName))).then([&result, &event](task<StorageFolder^> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return result;
}

FileProperties::BasicProperties^ File::getStorageProperties(IStorageItem^ file) const {
	try {
		if (file == nullptr) {
			return nullptr;
		}
		FileProperties::BasicProperties^ properties = nullptr;
		concurrency::event event;
		task<FileProperties::BasicProperties^>(file->GetBasicPropertiesAsync()).then([&properties, &event](task<FileProperties::BasicProperties^> task) {
				try {
					properties = task.get();
				} catch (Platform::COMException^ ex) {
					std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
				}
				event.set();
			}, concurrency::task_continuation_context::use_arbitrary());
		event.wait();

		return properties;
	} catch (Platform::COMException^ ex) {
		std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
		return nullptr;
	}
}

Windows::Storage::StorageFolder^ File::getFolderFromPathSync(Platform::String^ filename) const {
	Windows::Storage::StorageFolder^ storageFolder = nullptr;
	concurrency::event event;
	task<StorageFolder ^>(Windows::Storage::StorageFolder::GetFolderFromPathAsync(filename)).then([&storageFolder, &event](task<StorageFolder^> task) {
			try {
				storageFolder = task.get();
			} catch (Platform::COMException^ ex) {
				storageFolder = nullptr;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return storageFolder;
}

Windows::Storage::StorageFile^ File::getFileFromPathSync(Platform::String^ filename) const {
	Windows::Storage::StorageFile^ storageFile = nullptr;
	concurrency::event event;
	task<StorageFile^>(Windows::Storage::StorageFile::GetFileFromPathAsync(filename)).then([&storageFile, &event](task<StorageFile^> task) {
			try {
				storageFile = task.get();
			} catch (Platform::COMException^ ex) {
				storageFile = nullptr;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return storageFile;
}

// Copies the file identified by this file object to a new path.
Ti::Value File::copy(const std::vector<Ti::Value>& arguments) {
	// copy will never work for folder
	if (isFolder()) {
		return Ti::Value(false);
	}

	const std::string destinationPath = arguments.at(0).toString();
	auto fileToReplace = this->getFileFromPathSync(destinationPath);

	// if destination file is not found, create new file and try again
	if (fileToReplace == nullptr) {
		const bool created = createEmptyFile(destinationPath);
		if (created) {
			fileToReplace = getFileFromPathSync(destinationPath);
		} else {
			return Ti::Value(false);
		}
	}

	concurrency::event event;
	bool result = false;
	task<void>(file_->CopyAndReplaceAsync(fileToReplace)).then([&result, &event](task<void> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return Ti::Value(result);
}

// Deletes the file identified by this file object.
Ti::Value File::deleteFile(const std::vector<Ti::Value>& arguments) {
	auto item = getStorageItem();
	if (item == nullptr) {
		return Ti::Value(false);
	}
	bool result = false;
	concurrency::event event;
	task<void>(item->DeleteAsync()).then([&result, &event](task<void> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	// release the file object because file is deleted
	if (result) {
		file_   = nullptr;
		folder_ = nullptr;
	}

	return Ti::Value(result);
}

// Returns a listing of the directory identified by this file object, or null
// if this object doesn't identify a directory.
Ti::Value File::getDirectoryListing(const std::vector<Ti::Value>& arguments) const {
	if (!isFolder()) {
		return Ti::Value::Null();
	}
	std::vector<JSValueRef> filenames;

	// Get folders in folder
	concurrency::event folderEvent;
	task<IVectorView<StorageFolder^>^>(folder_->GetFoldersAsync()).then([&filenames, &folderEvent](task<IVectorView<StorageFolder^>^> task) {
			try {
				auto folders = task.get();
				std::for_each(begin(folders), end(folders), [&filenames](StorageFolder^ folder) {
						filenames.push_back(Ti::Value(Ti::Utils::GetPlatformString(folder->Name)).JSValueRef());
					});
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			folderEvent.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	folderEvent.wait();

	// Get files in folder
	concurrency::event fileEvent;
	task<IVectorView<StorageFile^>^>(folder_->GetFilesAsync()).then([&filenames, &fileEvent](task<IVectorView<StorageFile^>^> task) {
			try {
				auto files = task.get();
				std::for_each(begin(files), end(files), [&filenames](StorageFile^ file) {
						filenames.push_back(Ti::Value(Ti::Utils::GetPlatformString(file->Name)).JSValueRef());
					});
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			fileEvent.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	fileEvent.wait();

	return Ti::Value(JSObjectMakeArray(Ti::Runtime::instance().globalContext(), filenames.size(), (filenames.size() > 0 ? &filenames[0] : nullptr), nullptr));
}

// Moves the file identified by this file object to another path.
Ti::Value File::move(const std::vector<Ti::Value>& arguments) {

	// if this item is folder, call rename
	if (isFolder()) {
		return this->rename(arguments);
	}

	// make sure to create detination file before getting StorageFile
	// otherwise GetFileFromPathSync will return nullptr
	const std::string newpath = arguments.at(0).toString();
	if (!createEmptyFile(newpath)) {
		return Ti::Value(false);
	}

	// retrieve destination file
	StorageFile^ fileToReplace = getFileFromPathSync(Ti::Utils::GetPlatformString(newpath));

	if (fileToReplace == nullptr) {
		return Ti::Value(false);
	}

	bool result = false;
	concurrency::event event;
	task<void>(this->file_->MoveAndReplaceAsync(fileToReplace)).then([&result, &event](task<void> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	// release the file object because file is deleted
	if (result) {
		file_   = nullptr;
		folder_ = nullptr;
	}

	return Ti::Value(result);
}


// Renames the file identified by this file object.
Ti::Value File::rename(const std::vector<Ti::Value>& arguments) {
	auto item = getStorageItem();
	const std::string desiredName = arguments.at(0).toString();
	concurrency::event event;
	bool result = false;
	task<void>(item->RenameAsync(Ti::Utils::GetPlatformString(desiredName))).then([&result, &event](task<void> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return Ti::Value(result);
}

// Returns the amount of free space available on the device where the
// file identified by this file object is stored.
Ti::Value File::spaceAvailable(const std::vector<Ti::Value>& arguments) const {
	const auto prop = getStorageProperties(getStorageItem());

	const auto propertiesName = ref new Platform::Collections::Vector<Platform::String^>();
	propertiesName->Append("System.FreeSpace");

	uint64 freeSpace;

	concurrency::event event;
	task<IMap<Platform::String^, Platform::Object^>^>(prop->RetrievePropertiesAsync(propertiesName)).then([&freeSpace, &event](task<IMap<Platform::String^, Platform::Object^>^> task) {
			try {
				const auto extraProperties = task.get();
				freeSpace = (uint64)extraProperties->Lookup("System.FreeSpace");
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());

	event.wait();

	return Ti::Value(static_cast<double>(freeSpace));
}

// Writes the specified data to the file identified by this file
// object.
Ti::Value File::write(const std::vector<Ti::Value>& arguments) {

	// if this item represents folder, write will never work
	if (isFolder()) {
		return Ti::Value(false);
	}

	if (file_ == nullptr) {
		// create empty file, then retrieve StorageFile object
		if (!createEmptyFile(path_)) {
			return Ti::Value(false);
		}
		file_ = getFileFromPathSync(Ti::Utils::GetPlatformString(path_));
		if (file_ == nullptr) {
			return Ti::Value(false);
		}
	}

	const Ti::Value data = arguments.at(0);
	const bool append = arguments.size() > 1 ? arguments.at(1).toBool() : false;

	Streams::IBuffer^ buffer = nullptr;

	// from String
	if (data.isString()) {
		buffer = getBufferFromString(data.toString(), append, file_);
	} else if (data.isObject()) {
		auto proxy = toProxy(data).get();
		auto file = dynamic_cast<Filesystem::File*>(proxy);
		if (file) {
			auto content = file->getContent();
			buffer = getBufferFromBytes(&content[0], content.size(), append, file_);
		} else {
			auto blob = dynamic_cast<Ti::Blob::Blob*>(proxy);
			if (blob && blob->size() > 0) {
				buffer = getBufferFromBytes(&blob->getData()[0], blob->size(), append, file_);
			}
		}
	}

	if (buffer == nullptr) {
		std::clog << "[WARN] Can't get content from Ti.Filesystem.File.write(content)" << std::endl;
		return Ti::Value(false);
	}

	bool result = false;
	concurrency::event event;
	task<void>(FileIO::WriteBufferAsync(file_, buffer)).then([&result, &event](task<void> task) {
			try {
				task.get();
				result = true;
			} catch (Platform::COMException^ ex) {
				std::clog << "[WARN] " << Ti::Utils::GetPlatformString(ex->Message) << std::endl;
			}
			event.set();
		}, concurrency::task_continuation_context::use_arbitrary());
	event.wait();

	return Ti::Value(result);
}


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction File::ClassMethods[] = {
	{ "getExecutable", _getExecutable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setHidden", _setHidden, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getHidden", _getHidden, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getName", _getName, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getNativePath", _getNativePath, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getParent", _getParent, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getReadonly", _getReadonly, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setRemoteBackup", _setRemoteBackup, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getRemoteBackup", _getRemoteBackup, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getSize", _getSize, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getSymbolicLink", _getSymbolicLink, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getWritable", _getWritable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getWriteable", _getWriteable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "append", _append, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "copy", _copy, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "createDirectory", _createDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "createFile", _createFile, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "createTimestamp", _createTimestamp, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "deleteDirectory", _deleteDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "deleteFile", _deleteFile, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "exists", _exists, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "extension", _extension, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getDirectoryListing", _getDirectoryListing, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "isDirectory", _isDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "isFile", _isFile, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "modificationTimestamp", _modificationTimestamp, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "move", _move, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "open", _open, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "read", _read, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "rename", _rename, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "resolve", _resolve, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "spaceAvailable", _spaceAvailable, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "write", _write, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}  // namespace Filesystem {
