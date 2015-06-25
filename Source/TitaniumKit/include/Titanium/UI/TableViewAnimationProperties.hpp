/**
 * TitaniumKit TableViewAnimationProperties
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_TABLEVIEWANIMATIONPROPERTIES_HPP_
#define _TITANIUM_UI_TABLEVIEWANIMATIONPROPERTIES_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @struct
		  @discussion This is the TableViewAnimationProperties.
		  Extend this struct to implement platform-specific properties like animation style.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/TableViewAnimationProperties
		*/
		class TITANIUMKIT_EXPORT TableViewAnimationProperties : public Module, public JSExport<TableViewAnimationProperties>
		{
		public:
			virtual bool get_animated() const TITANIUM_NOEXCEPT;
			virtual void set_animated(const bool& animated) TITANIUM_NOEXCEPT;

			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments);

			TableViewAnimationProperties(const JSContext&) TITANIUM_NOEXCEPT;
			
			virtual ~TableViewAnimationProperties() = default;
			TableViewAnimationProperties(const TableViewAnimationProperties&) = default;
			TableViewAnimationProperties& operator=(const TableViewAnimationProperties&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TableViewAnimationProperties(TableViewAnimationProperties&&) = default;
			TableViewAnimationProperties& operator=(TableViewAnimationProperties&&) = default;
#endif
			
			static void JSExportInitialize();
		protected:
			bool animated__ {true};
		};
		
	} // namespace UI
} // namespace Titanium
#endif // _TITANIUM_UI_TABLEVIEWANIMATIONPROPERTIES_HPP_
