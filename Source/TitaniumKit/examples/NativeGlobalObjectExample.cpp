/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "NativeGlobalObjectExample.hpp"
#include "Titanium/detail/TiBase.hpp"

void NativeGlobalObjectExample::add_require(const std::string& name, const std::string& body) TITANIUM_NOEXCEPT
{
	require_resource__.insert({name, body});
}

bool NativeGlobalObjectExample::requiredModuleExists(const std::string& path) const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("GlobalObjectDelegateExample::requiredModuleExists for ", path);
	return (require_resource__.find(path) != require_resource__.end());
}

std::string NativeGlobalObjectExample::readRequiredModule(const std::string& path) const
{
	TITANIUM_LOG_DEBUG("GlobalObjectDelegateExample::loadRequiredModule for ", path);
	if (require_resource__.find(path) == require_resource__.end()) {
		return "";
	}
	return require_resource__.at(path);
}

class NativeGlobalObjectTimerExample final : public Titanium::GlobalObject::Timer
{
public:
	NativeGlobalObjectTimerExample(Titanium::GlobalObject::Callback_t callback, const std::chrono::milliseconds& interval)
	    : Timer(callback, interval), callback__(callback)
	{
		TITANIUM_LOG_DEBUG("NativeGlobalObjectTimerExample: ctor");
	}

	virtual ~NativeGlobalObjectTimerExample()
	{
		TITANIUM_LOG_DEBUG("NativeGlobalObjectTimerExample: dtor");
	}

	virtual void Start() TITANIUM_NOEXCEPT override final
	{
		TITANIUM_LOG_DEBUG("NativeGlobalObjectTimerExample::Start");
	}

	virtual void Stop() TITANIUM_NOEXCEPT override final
	{
		TITANIUM_LOG_DEBUG("NativeGlobalObjectTimerExample::Stop");
	}

private:
	Titanium::GlobalObject::Callback_t callback__;
};

std::shared_ptr<Titanium::GlobalObject::Timer> NativeGlobalObjectExample::CreateTimer(Titanium::GlobalObject::Callback_t callback, const std::chrono::milliseconds& interval) const TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeGlobalObjectExample::CreateTimer");
	return std::make_shared<NativeGlobalObjectTimerExample>(callback, interval);
}

NativeGlobalObjectExample::NativeGlobalObjectExample(const JSContext& js_context) TITANIUM_NOEXCEPT
    : Titanium::GlobalObject(js_context)
{
	TITANIUM_LOG_DEBUG("NativeGlobalObjectExample:: ctor ", this);
}

NativeGlobalObjectExample::~NativeGlobalObjectExample() TITANIUM_NOEXCEPT
{
	TITANIUM_LOG_DEBUG("NativeGlobalObjectExample:: dtor ", this);
}

void NativeGlobalObjectExample::JSExportInitialize()
{
	JSExport<NativeGlobalObjectExample>::SetClassVersion(1);
	JSExport<NativeGlobalObjectExample>::SetParent(JSExport<Titanium::GlobalObject>::Class());
}
