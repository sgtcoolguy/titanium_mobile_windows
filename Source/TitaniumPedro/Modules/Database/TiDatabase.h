/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef __TI_DATABASE_PROXY_H__
#define __TI_DATABASE_PROXY_H__

#include "TiCore/TiProxy.h"
#include <sqlite3.h>

namespace Ti { namespace Database {

class DBModule final : public Ti::Proxy, public virtual_enable_shared_from_this<DBModule> {

public:

	enum class Type {
		Field_Type_Double,
		Field_Type_Float,
		Field_Type_Int,
		Field_Type_String
	};
	
	static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);
	
private:

	TI_CREATE_PROXY(DBModule)

protected:

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	DBModule(const std::string& name, const std::vector<Ti::Value>& args) : Ti::Proxy(name, args) {
	}
};
}}
#endif // defined(__TI_DATABASE_PROXY_H__)
