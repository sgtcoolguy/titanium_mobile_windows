/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiDatabase.h"
#include <Windows.h>
#include "TiCore/TiRuntimeFunctions.h"

#include "TiDatabaseResultSet.h"
#include "TiDatabaseDB.h"

namespace Ti { namespace Database {
	 
	const JSStaticFunction DBModule::ClassMethods[] = {
		{0,0,0}
	};

	static const std::string gCode =
		"(function(self){"
		"   Object.defineProperties(self.TiDatabaseDB.prototype, {"
		"       'lastInsertRowId': {set:function(value){this.setLastInsertRowId(value);},get:function(){return this.getLastInsertRowId();}, enumerable:true},"
		"       'rowsAffected': {set:function(value){this.setRowsAffected(value);},get:function(){return this.getRowsAffected();}, enumerable:true},"
		"       'name': {set:function(value){this.setName(value);},get:function(){return this.getName();}, enumerable:true}"
		"   });"
		"   Object.defineProperties(self.TiDatabaseResultSet.prototype, {"
		"       'rowCount': {get:function(){return this.getRowCount();}, enumerable:true},"
		"       'fieldCount': {get:function(){return this.getFieldCount();}, enumerable:true},"
		"       'validRow': {get:function(){return this.getValidRow();}, enumerable:true}"
		"   });"
		"   var exports = {};"
		"   exports.install = function(path,dbName){"
		"       var dbResourceFilePath = Ti.Filesystem.applicationDirectory + \"\\\\\" + path;"
		" 		var dbResourceFile = Ti.Filesystem.getFile(dbResourceFilePath);"
		"       var dbDirPath = Ti.Filesystem.applicationDataDirectory + \"\\\\databases\";"
		"       var dbDir = Ti.Filesystem.getFile(dbDirPath);"
		"       if (!dbDir.exists()) dbDir.createDirectory();"
		"       var dbFilePath = dbDirPath+\"\\\\\"+dbName;"
		"       var dbFile = Ti.Filesystem.getFile(dbFilePath);"
		"       if ((!dbFile.exists() || dbFile.size == 0) && dbResourceFile.exists()) dbResourceFile.copy(dbFilePath);"
		"       var db = exports.open(dbName);"
		"		return db;"
		"   };"
		"   exports.open = function(dbName){"
		"       var dbDirPath = Ti.Filesystem.applicationDataDirectory + \"\\\\databases\";"
		"       var dbDir = Ti.Filesystem.getFile(dbDirPath);"
		"       if (!dbDir.exists()) dbDir.createDirectory();"
		" 		var db = new self.TiDatabaseDB();"
		"       var dbFilePath = dbDirPath + \"\\\\\" + dbName;"
		"       db._initDatabase(dbName,dbFilePath);"
		"       Object.defineProperty(db, \"file\", {value: Ti.Filesystem.getFile(dbFilePath), writable : false});"
		"       db.getFile = function(){return this.file;};"
		"       db.remove = function(){this.close(); this.file.deleteFile();};"
		"		return db;"
		"   };"
		"   return exports;"
		"})(this);"
		;

	Ti::Value DBModule::Initialize(const std::string& ns, Ti::Value& obj) {
		Ti::Value dbModule;

		dbModule.setProperty("global", Ti::Value(Ti::Runtime::instance().globalObject()));
		dbModule.setProperty("TiDatabase", Database::DBModule::CreateConstructor());
		dbModule.setProperty("TiDatabaseDB", Database::DB::CreateConstructor());
		dbModule.setProperty("TiDatabaseResultSet", Database::ResultSet::CreateConstructor());

		Ti::Value result = Ti::evaluateScriptInObject(gCode, dbModule);
		//std::string r = result.toString();

		result.setProperty("FIELD_TYPE_DOUBLE", Ti::Value(static_cast<double>(Type::Field_Type_Double)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("FIELD_TYPE_FLOAT", Ti::Value(static_cast<double>(Type::Field_Type_Float)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("FIELD_TYPE_INT", Ti::Value(static_cast<double>(Type::Field_Type_Int)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);
		result.setProperty("FIELD_TYPE_STRING", Ti::Value(static_cast<double>(Type::Field_Type_String)), kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete);

		obj.setProperty(ns, result);

		return result;
	}
}}
