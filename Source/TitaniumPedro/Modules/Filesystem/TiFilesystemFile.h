/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILE_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILE_H_

#include "TiCore/TiProxy.h"
#include <string>
#include <iostream>
#include <fstream>
#include "TiCore/TiConstants.h"
#include "TiCore/TiUtils.h"
#include "Modules/Blob/TiBlob.h"

namespace Filesystem {

class File final : public Ti::Proxy, public virtual_enable_shared_from_this<File> {

 protected:

	File(const std::string& name, const std::vector<Ti::Value>& arguments);

	virtual ~File() {
	}

	const std::vector<unsigned char> getContent() {
		return Ti::Utils::GetContentFromFile(file_);
	}

 private:

	bool createDirectory(const std::string& desiredName);

	// Creates a file at the path identified by this file object.
	bool File::createEmptyFile(const std::string& path) {
		std::ofstream outfile(path, std::ofstream::out);
		bool fail = outfile.fail();
		outfile.close();
		return !fail;
	}

	bool isFolder() const {
		return folder_ != nullptr;
	}

	Windows::Storage::IStorageItem^ getStorageItem() const {
		if (file_ == nullptr && folder_ == nullptr) {
			return nullptr;
		}
		if (isFolder()) {
			return folder_;
		}
		return file_;
	}

	Windows::Storage::FileProperties::BasicProperties^ getStorageProperties(Windows::Storage::IStorageItem^ file) const;

	// Get StorageFolder from path. Returns nullptr if access denied or
	// there's no such file.
	Windows::Storage::StorageFolder^ getFolderFromPathSync(Platform::String^ filename) const;

	Windows::Storage::StorageFolder^ getFolderFromPathSync(const std::string& filename) const {
		return getFolderFromPathSync(Ti::Utils::GetPlatformString(filename));
	}

	// Get StorageFile from path. Returns nullptr if access denied or
	// there's no such file.
	Windows::Storage::StorageFile^ getFileFromPathSync(Platform::String^ filename) const;

	Windows::Storage::StorageFile^ getFileFromPathSync(const std::string& filename) const {
		return getFileFromPathSync(Ti::Utils::GetPlatformString(filename));
	}

	Windows::Storage::Streams::IBuffer^ getBufferFromBytes(unsigned char* data, std::size_t size, bool append, Windows::Storage::StorageFile^ appendingFile) {
		using namespace Windows::Storage;
		const auto writer = ref new Streams::DataWriter(ref new Streams::InMemoryRandomAccessStream());
		if (append) {
			writeContentFromFile(writer, appendingFile);
		}
		writer->WriteBytes(Platform::ArrayReference<unsigned char>(data, size));
		return writer->DetachBuffer();
	}

	Windows::Storage::Streams::IBuffer^ getBufferFromString(const std::string& string, bool append, Windows::Storage::StorageFile^ appendingFile) {
		using namespace Windows::Storage;
		const auto writer = ref new Streams::DataWriter(ref new Streams::InMemoryRandomAccessStream());
		if (append) {
			writeContentFromFile(writer, appendingFile);
		}
		writer->WriteString(Ti::Utils::GetPlatformString(string));
		return writer->DetachBuffer();
	}

	std::size_t writeContentFromFile(Windows::Storage::Streams::DataWriter^ writer, Windows::Storage::StorageFile^ file) {
		auto content = Ti::Utils::GetContentFromFile(file);
		if (content.size() > 0) {
			writer->WriteBytes(Platform::ArrayReference<unsigned char>(&content[0], content.size()));
		}
		return content.size();
	}

	std::string name_;
	std::string path_;

	// We need both file and folder because Windows Runtime
	// distinguishes it.
	Windows::Storage::StorageFile^ file_;
	Windows::Storage::StorageFolder^ folder_;


	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(File);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	// Gets the value of the executable property.
	TI_CREATE_METHOD(File, getExecutable);
	Ti::Value getExecutable(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		// Just return false here because Windows Runtime API doesn't
		// privide a way to get executable attribute
		return Ti::Value(false);
	}

	// Gets the value of the hidden property.
	TI_CREATE_METHOD(File, getHidden);
	Ti::Value getHidden(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		using namespace Windows::Storage;
		return Ti::Value((item->Attributes & FileAttributes::Normal) != FileAttributes::Normal);
	}

	// Sets the value of the hidden property.
	TI_CREATE_METHOD(File, setHidden);
	Ti::Value setHidden(const std::vector<Ti::Value>& arguments) {
		// Just return false here because Windows Runtime API doesn't
		// privide a way to set hidden attribute
		return Ti::Value(false);
	}

	// Gets the value of the name property.
	TI_CREATE_METHOD(File, getName);
	Ti::Value getName(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(name_);
	}

	// Gets the value of the nativePath property.
	TI_CREATE_METHOD(File, getNativePath);
	Ti::Value getNativePath(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(path_);
	}

	// Returns the path of the parent directory holding the file
	// identified by this file object, as a String or as a File object.
	TI_CREATE_METHOD(File, getParent);
	Ti::Value getParent(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(path_.substr(0, path_.find_last_of(Ti::Constants::separator)));
	}

	// Gets the value of the readonly property.
	TI_CREATE_METHOD(File, getReadonly);
	Ti::Value getReadonly(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		using namespace Windows::Storage;
		return Ti::Value((item->Attributes & FileAttributes::ReadOnly) == FileAttributes::ReadOnly);
	}

	// Gets the value of the remoteBackup property.
	TI_CREATE_METHOD(File, getRemoteBackup);
	Ti::Value getRemoteBackup(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value::Undefined();
	}

	// Sets the value of the remoteBackup property.
	TI_CREATE_METHOD(File, setRemoteBackup);
	Ti::Value setRemoteBackup(const std::vector<Ti::Value>& arguments) {
		return Ti::Value::Undefined();
	}

	// Gets the value of the size property.
	TI_CREATE_METHOD(File, getSize);
	// Gets the value of the size property.
	Ti::Value getSize(const std::vector<Ti::Value>& arguments) const {
		const auto prop = getStorageProperties(getStorageItem());
		if (prop == nullptr) {
			return Ti::Value(0.0);
		}
		else {
			return Ti::Value(static_cast<double>(prop->Size));
		}
	}

	// Gets the value of the symbolicLink property.
	TI_CREATE_METHOD(File, getSymbolicLink);
	Ti::Value getSymbolicLink(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(false);
	}

	// Gets the value of the writable property.
	TI_CREATE_METHOD(File, getWritable);
	Ti::Value getWritable(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		using namespace Windows::Storage;
		return Ti::Value((item->Attributes & FileAttributes::ReadOnly) != FileAttributes::ReadOnly);
	}

	// Gets the value of the writeable property.
	TI_CREATE_METHOD(File, getWriteable);
	Ti::Value getWriteable(const std::vector<Ti::Value>& arguments) const {
		return getWritable(arguments);
	}

	// Appends data to the file identified by this file object.
	TI_CREATE_METHOD(File, append);
	Ti::Value append(const std::vector<Ti::Value>& arguments) {
		std::clog << "[WARN] File.append() not implemented yet. Returning Undefined" << std::endl;
		return Ti::Value::Undefined();
	}

	// Copies the file identified by this file object to a new path.
	TI_CREATE_METHOD(File, copy);
	Ti::Value copy(const std::vector<Ti::Value>& arguments);

	// Creates a directory at the path identified by this file object.
	TI_CREATE_METHOD(File, createDirectory);
	Ti::Value createDirectory(const std::vector<Ti::Value>& arguments) {
		const bool result = createDirectory(path_);
		if (result) {
			// because this creates new directory which didn't exit, update the folder_ member
			folder_ = getFolderFromPathSync(path_);
			file_ = nullptr;
		}
		return Ti::Value(result);
	}

	// Creates a file at the path identified by this file object.
	TI_CREATE_METHOD(File, createFile);
	Ti::Value createFile(const std::vector<Ti::Value>& arguments) {
		const bool result = createEmptyFile(path_);
		if (result) {
			// because this creates new file which didn't exit, update the
			// file_ member
			file_ = getFileFromPathSync(Ti::Utils::GetPlatformString(path_));
			folder_ = nullptr;
		}
		return Ti::Value(result);
	}

	// Returns the creation timestamp for the file identified by this
	// file object.
	TI_CREATE_METHOD(File, createTimestamp);
	Ti::Value createTimestamp(const std::vector<Ti::Value>& arguments) {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(0.0);
		} else {
			return Ti::Value(Ti::Utils::GetMSecSinceEpoch(item->DateCreated));
		}
	}

	// Deletes the directory identified by this file object.
	TI_CREATE_METHOD(File, deleteDirectory);
	Ti::Value deleteDirectory(const std::vector<Ti::Value>& arguments) {
		return deleteFile(arguments);
	}

	// Deletes the file identified by this file object.
	TI_CREATE_METHOD(File, deleteFile);
	Ti::Value deleteFile(const std::vector<Ti::Value>& arguments);

	// Returns true if the file or directory identified by this file
	// object exists on the device.
	TI_CREATE_METHOD(File, exists);
	Ti::Value exists(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value((getStorageItem() != nullptr));
	}

	// Returns the extension for the file identified by this file object.
	TI_CREATE_METHOD(File, extension);
	Ti::Value extension(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(path_.substr(path_.find_last_of(".") + 1));
	}

	// Returns a listing of the directory identified by this file
	// object, or null if this object doesn't identify a directory.
	TI_CREATE_METHOD(File, getDirectoryListing);
	Ti::Value getDirectoryListing(const std::vector<Ti::Value>& arguments) const;

	// Returns true if this file object represents a directory.
	TI_CREATE_METHOD(File, isDirectory);
	Ti::Value isDirectory(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		using namespace Windows::Storage;
		return Ti::Value((item->Attributes & FileAttributes::Directory) == FileAttributes::Directory);
	}

	// Returns true if this file object represents an ordinary file.
	TI_CREATE_METHOD(File, isFile);
	Ti::Value isFile(const std::vector<Ti::Value>& arguments) const {
		auto item = getStorageItem();
		if (item == nullptr) {
			return Ti::Value(false);
		}
		using namespace Windows::Storage;
		return Ti::Value((item->Attributes & FileAttributes::Directory) != FileAttributes::Directory);
	}

	// Returns the last modification time for this file.
	TI_CREATE_METHOD(File, modificationTimestamp);
	Ti::Value modificationTimestamp(const std::vector<Ti::Value>& arguments) const {
		const auto prop = getStorageProperties(getStorageItem());
		if (prop == nullptr) {
			return Ti::Value(0.0);
		}
		else {
			return Ti::Value(Ti::Utils::GetMSecSinceEpoch(prop->DateModified));
		}
	}

	// Moves the file identified by this file object to another path.
	TI_CREATE_METHOD(File, move);
	Ti::Value move(const std::vector<Ti::Value>& arguments);

	// Opens the file identified by this file object for random access.
	TI_CREATE_METHOD(File, open);
	Ti::Value open(const std::vector<Ti::Value>& arguments) {
		std::clog << "[WARN] File.open() not implemented yet. Returning Undefined" << std::endl;
		return Ti::Value::Undefined();
	}

	// Returns the contents of the file identified by this file object
	// as a Blob.
	TI_CREATE_METHOD(File, read);
	Ti::Value read(const std::vector<Ti::Value>& arguments) const {
		if (file_ == nullptr) {
			return Ti::Value::Null();
		}
		return Ti::Blob::Blob::create(file_)->toValue();
	}

	// Renames the file identified by this file object.
	TI_CREATE_METHOD(File, rename);
	Ti::Value rename(const std::vector<Ti::Value>& arguments);

	// Returns the fully-resolved native path associated with this file
	// object.
	TI_CREATE_METHOD(File, resolve);
	Ti::Value resolve(const std::vector<Ti::Value>& arguments) const {
		return Ti::Value(path_);
	}

	// Returns the amount of free space available on the device where
	// the file identified by this file object is stored.
	TI_CREATE_METHOD(File, spaceAvailable);
	Ti::Value spaceAvailable(const std::vector<Ti::Value>& arguments) const;

	// Writes the specified data to the file identified by this file
	// object.
	TI_CREATE_METHOD(File, write);
	Ti::Value File::write(const std::vector<Ti::Value>& arguments);
};

}  // namespace Filesystem {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_FILESYSTEM_TIFILE_H_
