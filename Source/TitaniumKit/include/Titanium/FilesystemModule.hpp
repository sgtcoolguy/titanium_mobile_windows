/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_FILESYSTEM_HPP_
#define _TITANIUM_FILESYSTEM_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Filesystem/Constants.hpp"
#include "Titanium/Filesystem/File.hpp"

namespace Titanium {
  
  using namespace JavaScriptCoreCPP;
  
  class TITANIUMKIT_EXPORT FilesystemModule : public Module, public JSExport <FilesystemModule> {
    
  public:
    
    JSValue getFile(const JSString&) TITANIUM_NOEXCEPT;
    JSValue createTempDirectory() TITANIUM_NOEXCEPT;
    JSValue createTempFile() TITANIUM_NOEXCEPT;
    bool isExternalStoragePresent() TITANIUM_NOEXCEPT;
    JSValue openStream(std::unordered_set<Titanium::Filesystem::MODE> modes, const JSString& path) TITANIUM_NOEXCEPT;

    virtual JSValue MODE_READ()   const TITANIUM_NOEXCEPT final;
    virtual JSValue MODE_WRITE()  const TITANIUM_NOEXCEPT final;
    virtual JSValue MODE_APPEND() const TITANIUM_NOEXCEPT final;
    virtual JSString separator() const TITANIUM_NOEXCEPT;
    virtual JSString applicationCacheDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString applicationDataDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString applicationDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString applicationSupportDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString externalStorageDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString lineEnding() const TITANIUM_NOEXCEPT;
    virtual JSString resourcesDirectory() const TITANIUM_NOEXCEPT;
    virtual JSString tempDirectory() const TITANIUM_NOEXCEPT;

    FilesystemModule(const JSContext& js_context)                      TITANIUM_NOEXCEPT;
    FilesystemModule(const FilesystemModule&, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT;
    
    virtual ~FilesystemModule()                  = default;
    FilesystemModule(const FilesystemModule&)            = default;
    FilesystemModule& operator=(const FilesystemModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
    FilesystemModule(FilesystemModule&&)                 = default;
    FilesystemModule& operator=(FilesystemModule&&)      = default;
#endif
    
    static void JSExportInitialize();
    
    virtual JSValue getFile_ArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue createTempDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue createTempFile_ArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue isExternalStoragePresent_ArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
    virtual JSValue openStream_ArgumentValidator(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

    virtual JSValue getSeparator_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getApplicationCacheDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getApplicationDataDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getApplicationDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getApplicationSupportDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getExternalStorageDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getLineEnding_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getResourcesDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;
    virtual JSValue getTempDirectory_ArgumentValidator(const std::vector<JSValue>&, JSObject&) const TITANIUM_NOEXCEPT final;

    virtual JSValue separator_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue applicationCacheDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue applicationDataDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue applicationDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue applicationSupportDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue externalStorageDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue lineEnding_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue resourcesDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;
    virtual JSValue tempDirectory_ArgumentValidator() const TITANIUM_NOEXCEPT final;

  private:
    JSValue mode_read__;
    JSValue mode_write__;
    JSValue mode_append__;
  };

} // namespace Titanium {

#endif // _TITANIUM_FILESYSTEM_HPP_
