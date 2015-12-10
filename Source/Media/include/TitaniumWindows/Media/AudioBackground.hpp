/**
* Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License.
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUMWINDOWS_MEDIA_AUDIOBACKGROUND_HPP_
#define _TITANIUMWINDOWS_MEDIA_AUDIOBACKGROUND_HPP_

namespace TitaniumWindows_Media
{
	using namespace Windows::ApplicationModel::Background;

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AudioBackground sealed : IBackgroundTask
	{
	public:
		virtual void Run(IBackgroundTaskInstance^ taskInstance);
	};
}
#endif
