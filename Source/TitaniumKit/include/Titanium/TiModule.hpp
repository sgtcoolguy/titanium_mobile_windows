/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_TIMODULE_HPP_
#define _TITANIUM_TIMODULE_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
	  @class
	  @discussion This is the top-level Titanium Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium
	*/
	class TITANIUMKIT_EXPORT TiModule : public Module, public JSExport<TiModule>
	{
	public:
		virtual std::string version() const TITANIUM_NOEXCEPT;
		virtual std::string buildDate() const TITANIUM_NOEXCEPT;
		virtual std::string buildHash() const TITANIUM_NOEXCEPT;

		virtual void setUserAgent(const std::string&) TITANIUM_NOEXCEPT final;

		TiModule(const JSContext&) TITANIUM_NOEXCEPT;
		virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

		virtual ~TiModule() = default;
		TiModule(const TiModule&) = default;
		TiModule& operator=(const TiModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		TiModule(TiModule&&) = default;
		TiModule& operator=(TiModule&&) = default;
#endif

		static void JSExportInitialize();
		static JSObject GetStaticObject(const JSContext& js_context) TITANIUM_NOEXCEPT;

		TITANIUM_PROPERTY_READONLY_DEF(version);
		TITANIUM_PROPERTY_READONLY_DEF(buildDate);
		TITANIUM_PROPERTY_READONLY_DEF(buildHash);
		TITANIUM_PROPERTY_DEF(userAgent);
		TITANIUM_FUNCTION_DEF(getVersion);
		TITANIUM_FUNCTION_DEF(getBuildDate);
		TITANIUM_FUNCTION_DEF(getBuildHash);
		TITANIUM_FUNCTION_DEF(getUserAgent);
		TITANIUM_FUNCTION_DEF(setUserAgent);
		TITANIUM_FUNCTION_DEF(createBuffer);

	private:
#pragma warning(push)
#pragma warning(disable : 4251)
		std::string userAgent__;
#pragma warning(pop)

	};

}  // namespace Titanium

#endif  // _TITANIUM_TIMODULE_HPP_
