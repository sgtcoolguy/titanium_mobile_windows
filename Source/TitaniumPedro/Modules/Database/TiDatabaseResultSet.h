/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_DATABASE_RESULTSET_PROXY_H__
#define __TI_DATABASE_RESULTSET_PROXY_H__

#include "TiCore/TiProxy.h"
#include <sqlite3.h>

namespace Ti { namespace Database {
class ResultSet : public Ti::Proxy, public virtual_enable_shared_from_this<ResultSet> {

	TI_CREATE_PROXY(ResultSet)

public:

	int effected_rows_ = 0;
	int step_result_ = 0;
	bool valid_row_ = 0;

	sqlite3_stmt* statement_ = nullptr;
	std::vector<std::string> column_names_;

	ResultSet(const std::string&, const std::vector<Ti::Value>&);

	Ti::Value getValue();

private:

protected:

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}
	
	virtual ~ResultSet();

	
	// Gets the value of the rowCount property.
	Ti::Value getRowCount(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, getRowCount);

	// Gets the value of the fieldCount property.
	Ti::Value getFieldCount(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, getFieldCount);

	// Closes this result set and release resources. Once closed, the result set must no longer 
	// be used.
	Ti::Value close(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, close);

	// Retrieves the value for the specified field in the current row, 
	// and casts it to the specified type (String, Integer, Float or Double.)
	Ti::Value field(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, field);

	// Retrieves the value for the specified field in the current row, 
	// and casts it to the specified type (String, Integer, Float or Double.)
	Ti::Value fieldByName(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, fieldByName);

	// Returns the field name for the specified field index.
	Ti::Value fieldName(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, fieldName);

	// Returns whether the current row is valid.
	Ti::Value isValidRow(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, isValidRow);

	// Advances to the next row in the result set and returns true if one exists, 
	// or false otherwise.
	Ti::Value next(const std::vector<Ti::Value>& args);
	TI_CREATE_METHOD(ResultSet, next);
};
}}
#endif // defined(__TI_DATABASE_RESULTSET_PROXY_H__)
