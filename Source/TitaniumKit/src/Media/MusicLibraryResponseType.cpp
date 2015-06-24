/**
 * TitaniumKit MusicLibraryResponseType
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/MusicLibraryResponseType.hpp"
#include "Titanium/Media/Item.hpp"
#include "Titanium/detail/TiImpl.hpp"

namespace Titanium
{
	namespace Media
	{
		using namespace HAL;

		MusicLibraryResponseType js_to_MusicLibraryResponseType(const JSObject& object)
		{
			MusicLibraryResponseType config;

			const auto items_property = object.GetProperty("items");
			ENSURE_OBJECT_ARRAY(items_property, items, Item);
			config.items = items;
			
			const auto representative_property = object.GetProperty("representative");
			ENSURE_OBJECT_ARRAY(representative_property, representative, Item);
			config.representative = representative;
			
			config.types = Constants::to_MusicMediaType(static_cast<std::uint32_t>(object.GetProperty("types")));
			
			return config;
		};

		JSObject MusicLibraryResponseType_to_js(const JSContext& js_context, const MusicLibraryResponseType& config)
		{
			auto object = js_context.CreateObject();

			std::vector<JSValue> items;
			for (const auto v : config.items) {
				items.push_back(v->get_object());
			}
			object.SetProperty("items", js_context.CreateArray(items));

			std::vector<JSValue> representative;
			for (const auto v : config.representative) {
				representative.push_back(v->get_object());
			}
			object.SetProperty("representative", js_context.CreateArray(representative));
			object.SetProperty("types", js_context.CreateNumber(Constants::to_underlying_type(config.types)));

			return object;
		}
	} // namespace Media
} // namespace Titanium
