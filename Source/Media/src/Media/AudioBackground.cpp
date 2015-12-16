/**
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#include "TitaniumWindows/Media/AudioBackground.hpp"

// Entry point: TitaniumWindows_Media.AudioBackground

namespace TitaniumWindows_Media
{
	using namespace Windows::ApplicationModel::Background;

	void AudioBackground::Run(IBackgroundTaskInstance^ taskInstance)
	{
		taskInstance->Canceled += ref new BackgroundTaskCanceledEventHandler(
			[=](IBackgroundTaskInstance^ sender, BackgroundTaskCancellationReason reason) {
				taskInstance->GetDeferral()->Complete();
			}
		);
	}
}
