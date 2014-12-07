/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

// -*- mode: c++ -*-
#ifndef _TITANIUM_MOBILE_WINDOWS_APP_H_
#define _TITANIUM_MOBILE_WINDOWS_APP_H_

using namespace Windows::UI::Xaml;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;

namespace TitaniumPedro {

public ref class App sealed : public ::Application {

public:

	App();
	virtual ~App();
	
	virtual void OnLaunched(LaunchActivatedEventArgs^ args) override;

private:

	void OnSuspending(Object^ sender, SuspendingEventArgs^ e);
	
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
	Windows::UI::Xaml::Media::Animation::TransitionCollection^ _transitions;
	Windows::Foundation::EventRegistrationToken _firstNavigatedToken;
	void RootFrame_FirstNavigated(Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationEventArgs^ e);
#endif
};

}	// namespace TitaniumPedro {

#endif	// _TITANIUM_MOBILE_WINDOWS_APP_H_
