/**
 * TitaniumKit CloseWindowParams
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_CLOSEWINDOWPARAMS_HPP_
#define _TITANIUM_UI_CLOSEWINDOWPARAMS_HPP_

#include "Titanium/detail/TiBase.hpp"
#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion This is the CloseWindowParams.
		  Extend this struct to implement platform-specific properties like animation style.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/CloseWindowParams
		*/
		class TITANIUMKIT_EXPORT CloseWindowParams : public Module, public JSExport<CloseWindowParams>
		{
		public:
			virtual bool get_animated() const TITANIUM_NOEXCEPT;
			virtual void set_animated(const bool& animated) TITANIUM_NOEXCEPT;

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments);

			CloseWindowParams(const JSContext&) TITANIUM_NOEXCEPT;
			
			virtual ~CloseWindowParams() = default;
			CloseWindowParams(const CloseWindowParams&) = default;
			CloseWindowParams& operator=(const CloseWindowParams&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			CloseWindowParams(CloseWindowParams&&) = default;
			CloseWindowParams& operator=(CloseWindowParams&&) = default;
#endif
			
			static void JSExportInitialize();
			static JSObject GetConstructor(const JSContext& js_context) TITANIUM_NOEXCEPT;
		protected:
			bool animated__ {true};
		};
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_CLOSEWINDOWPARAMS_HPP_
