/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_FILE_HPP_
#define _TITANIUMWINDOWS_FILE_HPP_

#include "detail/FilesystemBase.hpp"
#include "Titanium/Filesystem/Constants.hpp"
#include <ppltasks.h>
#include <algorithm>
#include <vector>
#include <collection.h>

// FIXME THIS SHOULD BE REMOVED ONCE UTILITY FUNCTIONS ARE MERGED
#define TITANIUM_FILESYSTEM_FILE_PATH_SEPARATOR "\\"
::Platform::String^ GetPlatformString(const std::string& s_str);
std::string GetPlatformString(::Platform::String^ str);
std::string GetPlatformUTF8String(::Platform::String^ str);
std::vector<unsigned char> GetContentFromBuffer(Windows::Storage::Streams::IBuffer^ buffer);
std::vector<unsigned char> GetContentFromFile(Windows::Storage::StorageFile^ file);
const std::string MimeTypeForExtension(std::string& path);
unsigned GetMSecSinceEpoch(Windows::Foundation::DateTime d);
// FIXME END

namespace TitaniumWindows {
  namespace Filesystem {

  using namespace JavaScriptCoreCPP;

  /*!
    @class

    @discussion This is the Titanium.Filesystem.File implementation for Windows.
    */
  class TITANIUMWINDOWS_EXPORT File final : public Titanium::Filesystem::File, public JSExport <File> {

  public:

    virtual bool get_executable() const TITANIUM_NOEXCEPT;
    virtual bool get_hidden() const TITANIUM_NOEXCEPT;
    virtual JSString get_name() const TITANIUM_NOEXCEPT;
    virtual JSString get_nativePath() const TITANIUM_NOEXCEPT;
    virtual JSValue get_parent() const TITANIUM_NOEXCEPT;
    virtual bool get_readonly() const TITANIUM_NOEXCEPT;
    virtual bool get_remoteBackup() const TITANIUM_NOEXCEPT;
    virtual unsigned get_size() const TITANIUM_NOEXCEPT;
    virtual bool get_symbolicLink() const TITANIUM_NOEXCEPT;
    virtual bool get_writable() const TITANIUM_NOEXCEPT;

    virtual bool append(const JSValue& data) TITANIUM_NOEXCEPT;
    virtual bool copy(const JSString& dest) TITANIUM_NOEXCEPT;
    virtual bool createDirectory() TITANIUM_NOEXCEPT;
    virtual bool createFile() TITANIUM_NOEXCEPT;
    virtual unsigned createTimestamp() TITANIUM_NOEXCEPT;
    virtual bool deleteDirectory(bool recursive) TITANIUM_NOEXCEPT;
    virtual bool deleteFile() TITANIUM_NOEXCEPT;
    virtual bool exists() TITANIUM_NOEXCEPT;
    virtual JSString extension() TITANIUM_NOEXCEPT;
    virtual std::vector<JSValue> getDirectoryListing() TITANIUM_NOEXCEPT;
    virtual bool isDirectory() TITANIUM_NOEXCEPT;
    virtual bool isFile() TITANIUM_NOEXCEPT;
    virtual unsigned modificationTimestamp() TITANIUM_NOEXCEPT;
    virtual bool move(const JSString& newpath) TITANIUM_NOEXCEPT;
    virtual JSValue open(const std::unordered_set<Titanium::Filesystem::MODE>&) TITANIUM_NOEXCEPT;
    virtual JSValue read() TITANIUM_NOEXCEPT;
    virtual bool rename(const JSString& newname) TITANIUM_NOEXCEPT;
    virtual JSString resolve() TITANIUM_NOEXCEPT;
    virtual unsigned spaceAvailable() TITANIUM_NOEXCEPT;
    virtual bool write(const JSValue& data, bool append) TITANIUM_NOEXCEPT;

    File(const JSContext& js_context) TITANIUM_NOEXCEPT;
    File(const File&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;

    virtual ~File();
    File(const File&)            = default;
    File& operator=(const File&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    File(File&&)                 = default;
    File& operator=(File&&)      = default;
#endif

    static void JSExportInitialize();

  protected:

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
    Windows::Storage::StorageFolder^ getFolderFromPathSync(::Platform::String^ filename) const;

    Windows::Storage::StorageFolder^ getFolderFromPathSync(const std::string& filename) const {
      return getFolderFromPathSync(GetPlatformString(filename));
    }

    // Get StorageFile from path. Returns nullptr if access denied or
    // there's no such file.
    Windows::Storage::StorageFile^ getFileFromPathSync(::Platform::String^ filename) const;

    Windows::Storage::StorageFile^ getFileFromPathSync(const std::string& filename) const {
      return getFileFromPathSync(GetPlatformString(filename));
    }

    Windows::Storage::Streams::IBuffer^ getBufferFromBytes(unsigned char* data, std::size_t size, bool append, Windows::Storage::StorageFile^ appendingFile) {
      using namespace Windows::Storage;
      const auto writer = ref new Streams::DataWriter(ref new Streams::InMemoryRandomAccessStream());
      if (append) {
        writeContentFromFile(writer, appendingFile);
      }
      writer->WriteBytes(::Platform::ArrayReference<unsigned char>(data, size));
      return writer->DetachBuffer();
    }

    Windows::Storage::Streams::IBuffer^ getBufferFromString(const std::string& string, bool append, Windows::Storage::StorageFile^ appendingFile) {
      using namespace Windows::Storage;
      const auto writer = ref new Streams::DataWriter(ref new Streams::InMemoryRandomAccessStream());
      if (append) {
        writeContentFromFile(writer, appendingFile);
      }
      writer->WriteString(GetPlatformString(string));
      return writer->DetachBuffer();
    }

    std::size_t writeContentFromFile(Windows::Storage::Streams::DataWriter^ writer, Windows::Storage::StorageFile^ file) {
      auto content = GetContentFromFile(file);
      if (content.size() > 0) {
        writer->WriteBytes(::Platform::ArrayReference<unsigned char>(&content[0], content.size()));
      }
      return content.size();
    }

    JSString name_;
    JSString path_;

    // We need both file and folder because Windows Runtime
    // distinguishes it.
    Windows::Storage::StorageFile^ file_;
    Windows::Storage::StorageFolder^ folder_;
  };

} }  // namespace TitaniumWindows { namespace Filesystem {

#endif // _TITANIUMWINDOWS_FILE_HPP_
