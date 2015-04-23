/**
 * Windows Native Wrapper for Windows.Foundation.IAsyncAction
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _WINDOWS_FOUNDATION_IASYNCACTION_HPP_
#define _WINDOWS_FOUNDATION_IASYNCACTION_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace Foundation
		{


		using namespace HAL;

		class TITANIUMWINDOWS_UI_EXPORT IAsyncAction : public Titanium::Module, public JSExport<IAsyncAction>
		{

		public:
			TITANIUM_PROPERTY_DEF(Completed);

			TITANIUM_FUNCTION_DEF(GetResults);

			IAsyncAction(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~IAsyncAction() = default;
			IAsyncAction(const IAsyncAction&) = default;
			IAsyncAction& operator=(const IAsyncAction&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			IAsyncAction(IAsyncAction&&)                 = default;
			IAsyncAction& operator=(IAsyncAction&&)      = default;
#endif

			static void JSExportInitialize();

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			::Windows::Foundation::IAsyncAction^ unwrapWindows_Foundation_IAsyncAction() const;
			void wrap(::Windows::Foundation::IAsyncAction^ object);

		protected:
			::Windows::Foundation::IAsyncAction^ wrapped__;

		private:
			::Windows::Foundation::IAsyncAction^ unwrap() const;

		};

		} // namespace Foundation
	} // namespace Windows
} // namespace Titanium
#endif // _WINDOWS_FOUNDATION_IASYNCACTION_HPP_
