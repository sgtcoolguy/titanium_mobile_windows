/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Media/Constants.hpp"
#include <unordered_map>
#include <mutex>

namespace Titanium
{
	namespace Media
	{

		std::unordered_set<VideoMediaType> Constants::to_VideoMediaType(std::underlying_type<VideoMediaType>::type videoMediaTypes) TITANIUM_NOEXCEPT
		{
			std::unordered_set<VideoMediaType> videoMediaType_set;
			static_cast<void>((videoMediaTypes & (1 << 0)) && videoMediaType_set.emplace(VideoMediaType::Audio).second);
			static_cast<void>((videoMediaTypes & (1 << 1)) && videoMediaType_set.emplace(VideoMediaType::None).second);
			static_cast<void>((videoMediaTypes & (1 << 2)) && videoMediaType_set.emplace(VideoMediaType::Video).second);
			return videoMediaType_set;
		}

		std::underlying_type<VideoMediaType>::type Constants::to_underlying_type(const std::unordered_set<VideoMediaType>& videoMediaType_set) TITANIUM_NOEXCEPT
		{
			std::underlying_type<VideoMediaType>::type result = 0;
			for (auto videoMediaType : videoMediaType_set) {
				result |= static_cast<std::underlying_type<VideoMediaType>::type>(videoMediaType);
			}

			return result;
		}

		std::underlying_type<VideoMediaType>::type Constants::to_underlying_type(const VideoMediaType& videoMediaType) TITANIUM_NOEXCEPT
		{
			return static_cast<std::underlying_type<VideoMediaType>::type>(videoMediaType);
		}
		
	} // namespace Media
} // namespace Titanium