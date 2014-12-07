/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiFilesystem.h"
#include "TiFilesystemFile.h"
#include <Windows.h>
#include "TiCore/TiRuntimeFunctions.h"

namespace Filesystem {

static const std::string gCode =
		"(function(self){"
		"   Object.defineProperties(self.TiFilesystemFile.prototype, {"
		"       'executable': {get:function(){return this.getExecutable();}, enumerable:true},"
		"       'hidden': {set:function(value){this.setHidden(value);},get:function(){return this.getHidden();}, enumerable:true},"
		"       'name': {get:function(){return this.getName();}, enumerable:true},"
		"       'nativePath': {get:function(){return this.getNativePath();}, enumerable:true},"
		"       'parent': {get:function(){return this.getParent();}, enumerable:true},"
		"       'readonly': {get:function(){return this.getReadonly();}, enumerable:true},"
		"       'remoteBackup': {set:function(value){this.setRemoteBackup(value);},get:function(){return this.getRemoteBackup();}, enumerable:true},"
		"       'size': {get:function(){return this.getSize();}, enumerable:true},"
		"       'symbolicLink': {get:function(){return this.getSymbolicLink();}, enumerable:true},"
		"       'writable': {get:function(){return this.getWritable();}, enumerable:true},"
		"       'writeable': {get:function(){return this.getWriteable();}, enumerable:true},"
		"   });"
		"   Object.defineProperties(self.TiFilesystem.prototype, {"
		"       'MODE_APPEND': {get:function(){return this.getMODE_APPEND();}, enumerable:true},"
		"       'MODE_READ': {get:function(){return this.getMODE_READ();}, enumerable:true},"
		"       'MODE_WRITE': {get:function(){return this.getMODE_WRITE();}, enumerable:true},"
		"       'applicationCacheDirectory': {get:function(){return this.getApplicationCacheDirectory();}, enumerable:true},"
		"       'applicationDataDirectory': {get:function(){return this.getApplicationDataDirectory();}, enumerable:true},"
		"       'applicationDirectory': {get:function(){return this.getApplicationDirectory();}, enumerable:true},"
		"       'applicationSupportDirectory': {get:function(){return this.getApplicationSupportDirectory();}, enumerable:true},"
		"       'externalStorageDirectory': {get:function(){return this.getExternalStorageDirectory();}, enumerable:true},"
		"       'lineEnding': {get:function(){return this.getLineEnding();}, enumerable:true},"
		"       'resRawDirectory': {get:function(){return this.getResRawDirectory();}, enumerable:true},"
		"       'resourcesDirectory': {get:function(){return this.getResourcesDirectory();}, enumerable:true},"
		"       'separator': {get:function(){return this.getSeparator();}, enumerable:true},"
		"       'tempDirectory': {get:function(){return this.getTempDirectory();}, enumerable:true},"
		"   });"
		""
		"   var exports = new self.TiFilesystem();"
		""
		"   /*"
		"    * Ti.Filesystem.createTempDirectory"
		"    * Creates a temporary directory and returns a File object representing the new directory."
		"    */"
		"   exports.createTempDirectory = function() {"
		"       var path = [Ti.Filesystem.tempDirectory, +new Date()];"
		"       var file = new self.TiFilesystemFile(path.join(Ti.Filesystem.separator));"
		"       file.createDirectory();"
		"       return file;"
		"   };"
		""
		"   /*"
		"    * Ti.Filesystem.createTempFile"
		"    * Creates a temporary file and returns a File object representing the new file."
		"    */"
		"   exports.createTempFile = function() {"
		"       var dir  = this.createTempDirectory();"
		"       var path = [dir.nativePath, 'tifile'+Math.random().toString(36).substring(2)+'.tmp'];"
		"       var file = new self.TiFilesystemFile(path.join(Ti.Filesystem.separator));"
		"       file.createFile();"
		"       return file;"
		"   };"
		""
		"   /*"
		"    * Ti.Filesystem.getFile"
		"    * Returns a File object representing the file identified by the path arguments."
		"    */"
		"   exports.getFile = function(path) {"
		"       var args = Array.prototype.slice.call(arguments);"
		"       return new self.TiFilesystemFile(args.join(Ti.Filesystem.separator));"
		"   };"
		""
		"   return exports;"
		"})(this);"
		;

Ti::Value FSModule::Initialize(const std::string& ns, Ti::Value& obj) {
	Ti::Value fsModule;

	fsModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
	fsModule.setProperty("TiFilesystemFile", Filesystem::File::CreateConstructor());
	fsModule.setProperty("TiFilesystem", Filesystem::FSModule::CreateConstructor());

	Ti::Value result = Ti::evaluateScriptInObject(gCode, fsModule);

	obj.setProperty(ns, result);

	return result;
}


////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction FSModule::ClassMethods[] = {
	{ "getMODE_APPEND", _getMODE_APPEND, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getMODE_READ", _getMODE_READ, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getMODE_WRITE", _getMODE_WRITE, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getApplicationCacheDirectory", _getApplicationCacheDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getApplicationDataDirectory", _getApplicationDataDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getApplicationDirectory", _getApplicationDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getApplicationSupportDirectory", _getApplicationSupportDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getExternalStorageDirectory", _getExternalStorageDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getLineEnding", _getLineEnding, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getResRawDirectory", _getResRawDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getResourcesDirectory", _getResourcesDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getSeparator", _getSeparator, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getTempDirectory", _getTempDirectory, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "isExternalStoragePresent", _isExternalStoragePresent, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "openStream", _openStream, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}  // namespace Filesystem {
