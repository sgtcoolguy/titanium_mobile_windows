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
    
    JSObject getFile(const JSString&) TITANIUM_NOEXCEPT;
    virtual JSValue MODE_READ()   const TITANIUM_NOEXCEPT final;
    virtual JSValue MODE_WRITE()  const TITANIUM_NOEXCEPT final;
    virtual JSValue MODE_APPEND() const TITANIUM_NOEXCEPT final;
    virtual JSValue separator()   const TITANIUM_NOEXCEPT;

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
    
    JSValue getFile_ArgumentValidator(const std::vector<JSValue>&, JSObject&);

  private:
    JSValue mode_read__;
    JSValue mode_write__;
    JSValue mode_append__;
  };

} // namespace Titanium {

#endif // _TITANIUM_FILESYSTEM_HPP_
