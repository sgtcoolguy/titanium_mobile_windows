// -*- mode: c++ -*-
#ifndef _TITANIUM_MOBILE_WINDOWS_TIAPP_H_
#define _TITANIUM_MOBILE_WINDOWS_TIAPP_H_

#include "hyperloop/hyperloop_common.h"

using namespace Windows::UI::Xaml;
using namespace Windows::ApplicationModel::Activation;

namespace TitaniumRuss {
public ref class TiApp sealed : public ::Application {
 public:
    TiApp();
    virtual void OnLaunched(LaunchActivatedEventArgs^ args) override;
    
 private:
    void Boot();
    JSGlobalContextRef context;
    bool booted;
};
}

#endif  // _TITANIUM_MOBILE_WINDOWS_TIAPP_H_
