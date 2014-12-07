/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_DATABASE_DB_PROXY_H__
#define __TI_DATABASE_DB_PROXY_H__

#include "TiCore/TiProxy.h"
#include "TiDatabaseResultSet.h"

#include <sqlite3.h>

namespace Ti { namespace Database {
class DB : public Ti::Proxy, public virtual_enable_shared_from_this<DB> {

	TI_CREATE_PROXY(DB);

public:

private:

	std::string db_name_;
	std::string db_file_path_;
	sqlite3* db_ = nullptr;

	int last_insert_row_id_ = 0;
	int rows_affected_ = 0;

	Ti::Value _initDatabase(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, _initDatabase);

protected:

	static JSClassRef Parent() { return Ti::Proxy::ClassDef(); }
	DB(const std::string&, const std::vector<Ti::Value>&);
	virtual ~DB();

	// JavaScript's public API
	
	// Sets the value of the lastInsertRowId property.
	Ti::Value setLastInsertRowId(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, setLastInsertRowId);
	
	// Gets the value of the lastInsertRowId property.
	Ti::Value getLastInsertRowId(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, getLastInsertRowId);
	
	// Sets the value of the name property.
	Ti::Value setName(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, setName);
	
	// Gets the value of the name property.
	Ti::Value getName(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, getName);
	
	// Sets the value of the rowsAffected property.
	Ti::Value setRowsAffected(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, setRowsAffected);
	
	// Gets the value of the rowsAffected property.
	Ti::Value getRowsAffected(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, getRowsAffected);
	
	// Closes the database and releases resources from memory. Once closed, this instance is no 
	// longer valid and should not be used. On iOS, also closes all Ti.Database.ResultSet 
	// instances that exist.
	Ti::Value close(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, close);
	
	// Executes an SQL statement against the database and returns a ResultSet.
	Ti::Value execute(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(DB, execute);
};
}}
#endif // defined(__TI_DATABASE_DB_PROXY_H__)
