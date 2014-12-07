/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiDatabaseResultSet.h"
#include <Windows.h>

namespace Ti { namespace Database {

	const JSStaticFunction ResultSet::ClassMethods[] = {
		{"getRowCount" ,_getRowCount ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"getFieldCount", _getFieldCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete},
		{"close" ,_close ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"field" ,_field ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"fieldByName" ,_fieldByName ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"fieldName" ,_fieldName ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"isValidRow" ,_isValidRow ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{"next" ,_next ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete},
		{0,0,0}
	};
	
	ResultSet::~ResultSet() {
	}

	ResultSet::ResultSet(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args) {
	}

	Ti::Value ResultSet::getValue() {
		return Ti::Value(this->get_js_object());
	}

	// Public API
	// Gets the value of the fieldCount property.
	Ti::Value ResultSet::getFieldCount(const std::vector<Ti::Value>& args) {
		return Ti::Value(static_cast<double>(column_names_.size()));
	}

	// Gets the value of the rowCount property.
	Ti::Value ResultSet::getRowCount(const std::vector<Ti::Value>& args) {
		return Ti::Value(static_cast<double>(effected_rows_));
	}

	// Closes this result set and release resources. Once closed, the result set must no longer 
	// be used.
	Ti::Value ResultSet::close(const std::vector<Ti::Value>& args) {
		if (column_names_.size()) {
			sqlite3_finalize(statement_);
		}
		return Ti::Value::Undefined();
	}

	// Retrieves the value for the specified field in the current row, 
	// and casts it to the specified type (String, Integer, Float or Double.)
	Ti::Value ResultSet::field(const std::vector<Ti::Value>& args) {
		if (args.size() >= 1) {
			auto i = static_cast<int>(args.at(0).toDouble());
			int columnType = sqlite3_column_type(statement_, i);
			switch (columnType) {
				case SQLITE_TEXT:{
					std::string text(reinterpret_cast<const char*>(sqlite3_column_text(statement_, i)));
					return Ti::Value(text);
				}
				case SQLITE_INTEGER:{
					return Ti::Value(static_cast<double>(sqlite3_column_int(statement_, i)));
				}
				case SQLITE_FLOAT:{
					return Ti::Value(static_cast<double>(sqlite3_column_double(statement_, i)));
				}
				case SQLITE_BLOB:{
					// TODO: create a Ti Blob from this
					return Ti::Value::Null(); //sqlite3_column_blob(statement, i)
				}
				case SQLITE_NULL:{
					return Ti::Value::Null();
				}
			}
			return Ti::Value::Null();
		}
		return Ti::Value::Undefined();
	}

	// Retrieves the value for the specified field in the current row, 
	// and casts it to the specified type (String, Integer, Float or Double.)
	Ti::Value ResultSet::fieldByName(const std::vector<Ti::Value>& args) {
		if (args.size() >= 1) {
			for (int i = 0, len = column_names_.size(); i < len; i++) {
				if (column_names_[i] == args.at(0).toString()) {
					int columnType = sqlite3_column_type(statement_, i);
					switch (columnType) {
						case SQLITE_TEXT:{
							std::string text(reinterpret_cast<const char*>(sqlite3_column_text(statement_, i)));
							return Ti::Value(text);
						}
						case SQLITE_INTEGER:
							return Ti::Value(static_cast<double>(sqlite3_column_int(statement_, i)));
						case SQLITE_FLOAT:
							return Ti::Value(static_cast<double>(sqlite3_column_double(statement_, i)));
						case SQLITE_BLOB:
							// TODO: create a Ti Blob from this
							return Ti::Value::Null(); //sqlite3_column_blob(statement, i)
						case SQLITE_NULL:
							return Ti::Value::Null();
					}
				}
			}
			return Ti::Value::Null();
		}
		return Ti::Value::Undefined();
	}

	// Returns the field name for the specified field index.
	Ti::Value ResultSet::fieldName(const std::vector<Ti::Value>& args) {
		if (args.size() >= 1) {
			auto index = static_cast<int>(args.at(0).toDouble());
			if (index <= sqlite3_column_count(statement_) && strlen(reinterpret_cast<const char*>(sqlite3_column_text(statement_, index))) > 0) {
				return Ti::Value(reinterpret_cast<const char*>(sqlite3_column_name(statement_, index)));
			}
			return Ti::Value::Null();
		}
		return Ti::Value::Undefined();
	}

	// Returns whether the current row is valid.
	Ti::Value ResultSet::isValidRow(const std::vector<Ti::Value>& args) {
		return Ti::Value(step_result_ == SQLITE_ROW);
	}

	// Advances to the next row in the result set and returns true if one exists, 
	// or false otherwise.
	Ti::Value ResultSet::next(const std::vector<Ti::Value>& args) {
		step_result_ = sqlite3_step(statement_);
		if (step_result_ == SQLITE_ROW) {
			return Ti::Value(true);
		}
		return Ti::Value(false);
	}
}}
