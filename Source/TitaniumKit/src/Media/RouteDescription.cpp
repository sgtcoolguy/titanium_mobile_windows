/**
 * TitaniumKit RouteDescription
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/RouteDescription.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		RouteDescription js_to_RouteDescription(const JSObject& object)
		{
			RouteDescription config;
			
			const auto inputs_property = object.GetProperty("inputs");
			ENSURE_ARRAY(inputs_property, js_inputs);
			const auto inputs = static_cast<std::vector<JSValue>>(js_inputs);
			for (const auto v : inputs) {
				config.inputs.push_back(static_cast<AudioSessionPort>(static_cast<std::uint32_t>(v)));
			}
			const auto outputs_property = object.GetProperty("outputs");
			ENSURE_ARRAY(outputs_property, js_outputs);
			const auto outputs = static_cast<std::vector<JSValue>>(js_outputs);
			for (const auto v : outputs) {
				config.outputs.push_back(static_cast<AudioSessionPort>(static_cast<std::uint32_t>(v)));
			}

			return config;
		};

		JSObject RouteDescription_to_js(const JSContext& js_context, const RouteDescription& config)
		{
			auto object = js_context.CreateObject();

			std::vector<JSValue> js_inputs;
			for (const auto v : config.inputs) {
				js_inputs.push_back(js_context.CreateNumber(static_cast<std::uint32_t>(v)));
			}
			std::vector<JSValue> js_outputs;
			for (const auto v : config.outputs) {
				js_outputs.push_back(js_context.CreateNumber(static_cast<std::uint32_t>(v)));
			}
			object.SetProperty("inputs",  js_context.CreateArray(js_inputs));
			object.SetProperty("outputs", js_context.CreateArray(js_outputs));

			return object;
		}
	} // namespace Media
} // namespace Titanium
