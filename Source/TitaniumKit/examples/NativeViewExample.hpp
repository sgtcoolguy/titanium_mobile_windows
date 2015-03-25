/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_EXAMPLES_NATIVEVIEW_HPP_
#define _TITANIUM_EXAMPLES_NATIVEVIEW_HPP_

#include "Titanium/Titanium.hpp"
#include "Titanium/UI/ViewLayoutDelegate.hpp"

using namespace HAL;

class NativeViewLayoutDelegate : public Titanium::UI::ViewLayoutDelegate
{
public:
	NativeViewLayoutDelegate(JSObject& this_object);
	virtual ~NativeViewLayoutDelegate() = default;
	
	virtual void set_backgroundColor(const std::string&) TITANIUM_NOEXCEPT override;
};

/*!
 @class
 
 @discussion This is an example of how to implement Titanium::UI::View
 for a native platform.
 */
class NativeViewExample : public Titanium::UI::View, public JSExport<NativeViewExample>
{
public:
	NativeViewExample(const JSContext&) TITANIUM_NOEXCEPT;

	virtual ~NativeViewExample() TITANIUM_NOEXCEPT;  //= default;
	NativeViewExample(const NativeViewExample&) = default;
	NativeViewExample& operator=(const NativeViewExample&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
	NativeViewExample(NativeViewExample&&) = default;
	NativeViewExample& operator=(NativeViewExample&&) = default;
#endif
	
	static void JSExportInitialize();
	
	virtual void postInitialize(JSObject& js_object) override;
};

#endif  // _TITANIUM_EXAMPLES_NATIVEVIEW_HPP_
