/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiDatabaseDB.h"
#include <Windows.h>

// Taken from iOS SDK
#define SQLITE_BUSY_TIMEOUT 5000

namespace Ti { namespace Database {

	const JSStaticFunction DB::ClassMethods[] = {
		{"setLastInsertRowId" ,_setLastInsertRowId ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getLastInsertRowId" ,_getLastInsertRowId ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setName" ,_setName ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getName" ,_getName ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"setRowsAffected" ,_setRowsAffected ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"getRowsAffected" ,_getRowsAffected ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"close" ,_close ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"execute" ,_execute ,kJSPropertyAttributeReadOnly|kJSPropertyAttributeDontDelete },
		{"_initDatabase", __initDatabase, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete | kJSPropertyAttributeDontEnum },
		{0,0,0}
	};
	
	DB::~DB() {
	}

	DB::DB(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args) {
	}

	Ti::Value DB::_initDatabase(const std::vector<Ti::Value>& args) {

		if (args.size() < 2) {
			return Ti::Value::Undefined();
		}
		db_name_ = args.at(0).toString();
		db_file_path_ = args.at(1).toString();
		if (db_ == nullptr) {
			if (db_name_.size() == 0) {
				OutputDebugString(L"[ERROR] Invalid database name!\n");
				return Ti::Value::Undefined();
			}
			if (db_file_path_.size() == 0) {
				OutputDebugString(L"[ERROR] Invalid database file path!\n");
				return Ti::Value::Undefined();
			}
			int error = sqlite3_open_v2(db_file_path_.c_str(), &db_, SQLITE_OPEN_SHAREDCACHE | SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, NULL);
			if (error != SQLITE_OK) {
				//sqlite3_errmsg(db_); // Error message
				OutputDebugString(L"[ERROR] Could not open database!\n");
				sqlite3_close(db_);
				db_ = nullptr;
				return Ti::Value::Undefined();
			}
			error = sqlite3_busy_timeout(db_, SQLITE_BUSY_TIMEOUT);
			if (error != SQLITE_OK) {
				//sqlite3_errmsg(db_); // Error message
				OutputDebugString(L"[ERROR] Timeout error!\n");
				sqlite3_close(db_);
				db_ = nullptr;
			}
		}
		return Ti::Value::Undefined();
	}

	// Public API
	// Sets the value of the lastInsertRowId property.
	Ti::Value DB::setLastInsertRowId(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			last_insert_row_id_ = static_cast<int>(args.at(0).toDouble());
		}
		return Ti::Value::Undefined();
	}
	// Gets the value of the lastInsertRowId property.
	Ti::Value DB::getLastInsertRowId(const std::vector<Ti::Value>& args)
	{
		if (db_ != nullptr) {
			last_insert_row_id_ = sqlite3_last_insert_rowid(db_);
		}
		return Ti::Value(static_cast<double>(last_insert_row_id_));
	}
	// Sets the value of the name property.
	Ti::Value DB::setName(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			db_name_ = args.at(0).toString();
		}
		return Ti::Value::Undefined();
	}
	// Gets the value of the name property.
	Ti::Value DB::getName(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(db_name_);
	}
	// Sets the value of the rowsAffected property.
	Ti::Value DB::setRowsAffected(const std::vector<Ti::Value>& args)
	{
		if (args.size() >= 1) {
			rows_affected_ = static_cast<int>(args.at(0).toDouble());
		}
		return Ti::Value::Undefined();
	}
	// Gets the value of the rowsAffected property.
	Ti::Value DB::getRowsAffected(const std::vector<Ti::Value>& args)
	{
		return Ti::Value(static_cast<double>(rows_affected_));
	}
	// Closes the database and releases resources from memory. Once closed, this instance is no 
	// longer valid and should not be used. On iOS, also closes all Ti.Database.ResultSet 
	// instances that exist.
	Ti::Value DB::close(const std::vector<Ti::Value>& args)
	{
		if (db_ != nullptr) {
			sqlite3_close(db_);
			db_ = nullptr;
		}
		return Ti::Value::Undefined();
	}

	// Executes an SQL statement against the database and returns a ResultSet.
	Ti::Value DB::execute(const std::vector<Ti::Value>& args)
	{
		if (db_ != nullptr && args.size() >= 1) {

			int error;
			sqlite3_stmt* statement;
			int stepResult;
			std::string command;
			
			if (args.at(0).isString()) {
				command = args.at(0).toString();
			} else {
				OutputDebugString(L"[ERROR] Unknown argument!\n");
				return Ti::Value::Undefined();
			}

			std::vector<Ti::Value> undefinedValue;
			undefinedValue.push_back(Ti::Value::Undefined());
			auto resultSet = ResultSet::create(command, undefinedValue);

			error = sqlite3_prepare_v2(db_, command.c_str(), command.size(), &statement, NULL);
			if (error != SQLITE_OK) {
				OutputDebugString(L"[ERROR] SQLite prepare error!\n");
				sqlite3_finalize(statement);
				return Ti::Value::Undefined();
			}

			// Create vector to store memory buffers
			std::vector<char*> buffers;

			if (args.size() > 1) {
				for (int i = 1, len = args.size(); i < len; i++) {
					auto arg = args.at(i);
					auto parameter = arg;
					auto parameters = (arg.isArray() ? parameter.getLength() : 1);

					for (int j = 0; j < parameters; j++) {
						int bind_index = i;
						if (arg.isArray()) {
							parameter = arg.getValueAtIndex(j);
							bind_index = j + 1;
						}
						if (parameter.isString()) {
							const auto str = parameter.toString();
							const int length = str.size() + 1;
							char* buffer = static_cast<char*>(std::malloc(length));
							buffers.push_back(buffer);
							strcpy_s(buffer, length, str.c_str());
							error = sqlite3_bind_text(statement, bind_index, buffer, length, 0);
						} else if (parameter.isBoolean()) {
							// SQLite cant bind booleans so the next best is an integer
							error = sqlite3_bind_int(statement, bind_index, static_cast<int>(parameter.toBool()));
						} else if (parameter.isNumber()) {
							error = sqlite3_bind_double(statement, bind_index, parameter.toDouble());
						}
						if (error) {
							OutputDebugString(L"[ERROR] SQLite bind error!\n");
							sqlite3_finalize(statement);
							return Ti::Value::Undefined();
						}
					}
				}
			}

			// Execute query statement
			stepResult = sqlite3_step(statement);

			// Free all memory buffers
			for (int i = 0; i < buffers.size(); i++) {
				std::free(buffers[i]);
				buffers[i] = nullptr;
			}

			int effectedRows = 0;
			if (stepResult == SQLITE_DONE) {
				sqlite3_finalize(statement);
				resultSet->effected_rows_ = effectedRows;
				rows_affected_ = resultSet->effected_rows_ + 1;
				resultSet->statement_ = statement;
				return Ti::Value(resultSet->getValue());
			}

			while (stepResult != SQLITE_DONE) {
				if (stepResult == SQLITE_ROW) {
					effectedRows++;
				} else {
					sqlite3_finalize(statement);
					OutputDebugString(L"[ERROR] While stepping through statement, an error has occurred!\n");
					return Ti::Value::Undefined();
				}
				stepResult = sqlite3_step(statement);
			}

			resultSet->effected_rows_ = effectedRows;
			rows_affected_ = resultSet->effected_rows_;
			sqlite3_reset(statement);
			resultSet->step_result_ = sqlite3_step(statement);
			resultSet->statement_ = statement;

			for (int i = 0, len = sqlite3_column_count(statement); i < len; i++) {
				resultSet->column_names_.push_back(sqlite3_column_name(statement,i));
			}

			return Ti::Value(resultSet->getValue());
		}
		return Ti::Value::Null();
	}
}}