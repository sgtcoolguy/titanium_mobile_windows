/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "TiXML.h"
#include <mutex>
#include "TiCore/TiRuntimeFunctions.h"

Ti::Value Ti::XML::XMLModule::Initialize(const std::string& ns, Ti::Value& obj) {
	static Ti::Value result;

	// This API cannot be called more than once!
	static std::once_flag of;
	std::call_once(of, [&ns, &obj] {
			Ti::requireJS("TitaniumPedro/dom");
			Ti::requireJS("TitaniumPedro/sax");
			Ti::requireJS("TitaniumPedro/dom-parser");
			result = Ti::requireJS("TitaniumPedro/ti.xml");
			
			// Attach this object to "obj", which was passed in to us from the function call
			obj.setProperty(ns, result);
			
			// For debug, place a break point to see the result
			// std::string strResult = result.toString();
		});
	
	return result;
}
