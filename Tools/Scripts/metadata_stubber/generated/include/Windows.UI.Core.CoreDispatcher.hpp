/**
 * Windows Native Wrapper for Windows.UI.Core.CoreDispatcher
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_UI_CORE_COREDISPATCHER_HPP_
#define _WINDOWS_UI_CORE_COREDISPATCHER_HPP_

#include "Titanium/Module.hpp"

namespace Windows
{
	namespace UI
	{
		namespace Core
		{


		using namespace HAL;

		class TITANIUMKIT_EXPORT CoreDispatcher : public Titanium::Module, public JSExport<CoreDispatcher>
		{

		public:
			TITANIUM_PROPERTY_DEF(CurrentPriority);
			TITANIUM_PROPERTY_READONLY_DEF(HasThreadAccess);

			TITANIUM_FUNCTION_DEF(ProcessEvents);
			TITANIUM_FUNCTION_DEF(RunAsync);
			TITANIUM_FUNCTION_DEF(RunIdleAsync);
			TITANIUM_FUNCTION_DEF(ShouldYield);
			TITANIUM_FUNCTION_DEF(StopProcessEvents);

			CoreDispatcher(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~CoreDispatcher() = default;
			CoreDispatcher(const CoreDispatcher&) = default;
			CoreDispatcher& operator=(const CoreDispatcher&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			CoreDispatcher(CoreDispatcher&&)                 = default;
			CoreDispatcher& operator=(CoreDispatcher&&)      = default;
#endif

			static void JSExportInitialize();

			Windows::UI::Core::CoreDispatcher^ unwrapWindows_UI_Core_CoreDispatcher();
			void wrap(Windows::UI::Core::CoreDispatcher^ object);

		protected:
			Windows::UI::Core::CoreDispatcher^ wrapped__;
		};

		} // namespace Core
	} // namespace UI
} // namespace Windows
#endif // _WINDOWS_UI_CORE_COREDISPATCHER_HPP_
