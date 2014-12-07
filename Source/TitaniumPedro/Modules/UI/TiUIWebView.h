/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWEBVIEW_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWEBVIEW_H_

#include "TiCore/TiViewProxy.h"
#include <unordered_map>

namespace UI {

    class TiUIWebView : public Ti::ViewProxy, public virtual_enable_shared_from_this < TiUIWebView > {

    public:
        std::string defaultHeight() const override;
        std::string defaultWidth() const override;
        virtual Ti::Value eventAdded(const std::vector<Ti::Value>& args) override;
        virtual Ti::Value eventRemoved(const std::vector<Ti::Value>& args) override;
        
        static std::unordered_map<std::intptr_t, std::weak_ptr<TiUIWebView>> getWebViewProxies();
        void executeListener(const Ti::Value& name, const Ti::Value& obj);

    protected:
        TiUIWebView(const std::string& name, const std::vector<Ti::Value>& args);
        virtual void postConstruct() override;
        virtual ~TiUIWebView();

    private:
        Platform::String^ loadTitaniumInjectionJavaScript();
        void releaseWebViewListeners();
        int getWebViewError(const Windows::Web::WebErrorStatus status);
        void initWebViewListeners();

        static std::unordered_map <std::intptr_t, std::weak_ptr<TiUIWebView>> webviews_;
        std::intptr_t self { 0 };

        Windows::Foundation::EventRegistrationToken load_event_;
        Windows::Foundation::EventRegistrationToken beforeload_event_;
        Windows::Foundation::EventRegistrationToken script_event_;

        bool navigating { false };
        unsigned int load_listener_count_ { 0 };
        unsigned int beforeload_listener_count_ { 0 };
        unsigned int error_listener_count_ { 0 };

        std::string titaniumInjectionJavaScript;

        Windows::UI::Xaml::Controls::WebView^ webview_ { nullptr };

        TI_CREATE_PROXY(TiUIWebView);

        static JSClassRef Parent();

        // Sets the value of the url property.
        TI_CREATE_METHOD(TiUIWebView, setUrl);
        Ti::Value setUrl(const std::vector<Ti::Value>& args);

        // Gets the value of the url property.
        TI_CREATE_METHOD(TiUIWebView, getUrl);
        Ti::Value getUrl(const std::vector<Ti::Value>& args);

        // Sets the value of the opacity property.
        TI_CREATE_METHOD(TiUIWebView, setOpacity);
        Ti::Value setOpacity(const std::vector<Ti::Value>& args);

        // Gets the value of the opacity property.
        TI_CREATE_METHOD(TiUIWebView, getOpacity);
        Ti::Value getOpacity(const std::vector<Ti::Value>& args);

        // Sets the value of the html property.
        TI_CREATE_METHOD(TiUIWebView, setHtml);
        Ti::Value setHtml(const std::vector<Ti::Value>& args);

        // Gets the value of the html property.
        TI_CREATE_METHOD(TiUIWebView, getHtml);
        Ti::Value getHtml(const std::vector<Ti::Value>& args);

        // Evaluates a JavaScript expression inside the context of the web view and
        // optionally, returns a result.
        TI_CREATE_METHOD(TiUIWebView, evalJS);
        Ti::Value evalJS(const std::vector<Ti::Value>& args);

        // Gets the value of the loading property.
        TI_CREATE_METHOD(TiUIWebView, getLoading);
        Ti::Value getLoading(const std::vector<Ti::Value>& args);

        // Goes back one entry in the web view's history list, to the previous page.
        TI_CREATE_METHOD(TiUIWebView, goBack);
        Ti::Value goBack(const std::vector<Ti::Value>& args);

        // Goes forward one entry in this web view's history list, if possible.
        TI_CREATE_METHOD(TiUIWebView, goForward);
        Ti::Value goForward(const std::vector<Ti::Value>& args);

        // Stops loading a currently loading page.
        TI_CREATE_METHOD(TiUIWebView, stopLoading);
        Ti::Value stopLoading(const std::vector<Ti::Value>& args);

        // Reloads the current webpage.
        TI_CREATE_METHOD(TiUIWebView, reload);
        Ti::Value reload(const std::vector<Ti::Value>& args);

        // Sets the value of the data property.
        TI_CREATE_METHOD(TiUIWebView, setData);
        Ti::Value setData(const std::vector<Ti::Value>& args);

        // Gets the value of the data property.
        TI_CREATE_METHOD(TiUIWebView, getData);
        Ti::Value getData(const std::vector<Ti::Value>& args);

        // Sets the value of the cacheMode property.
        TI_CREATE_METHOD(TiUIWebView, setCacheMode);
        Ti::Value setCacheMode(const std::vector<Ti::Value>& args);

        // Gets the value of the cacheMode property.
        TI_CREATE_METHOD(TiUIWebView, getCacheMode);
        Ti::Value getCacheMode(const std::vector<Ti::Value>& args);

        // Sets the value of the disableBounce property.
        TI_CREATE_METHOD(TiUIWebView, setDisableBounce);
        Ti::Value setDisableBounce(const std::vector<Ti::Value>& args);

        // Gets the value of the disableBounce property.
        TI_CREATE_METHOD(TiUIWebView, getDisableBounce);
        Ti::Value getDisableBounce(const std::vector<Ti::Value>& args);

        // Sets the value of the enableZoomControls property.
        TI_CREATE_METHOD(TiUIWebView, setEnableZoomControls);
        Ti::Value setEnableZoomControls(const std::vector<Ti::Value>& args);

        // Gets the value of the enableZoomControls property.
        TI_CREATE_METHOD(TiUIWebView, getEnableZoomControls);
        Ti::Value getEnableZoomControls(const std::vector<Ti::Value>& args);

        // Sets the value of the handlePlatformUrl property.
        TI_CREATE_METHOD(TiUIWebView, setHandlePlatformUrl);
        Ti::Value setHandlePlatformUrl(const std::vector<Ti::Value>& args);

        // Gets the value of the handlePlatformUrl property.
        TI_CREATE_METHOD(TiUIWebView, getHandlePlatformUrl);
        Ti::Value getHandlePlatformUrl(const std::vector<Ti::Value>& args);

        // Sets the value of the hideLoadIndicator property.
        TI_CREATE_METHOD(TiUIWebView, setHideLoadIndicator);
        Ti::Value setHideLoadIndicator(const std::vector<Ti::Value>& args);

        // Gets the value of the hideLoadIndicator property.
        TI_CREATE_METHOD(TiUIWebView, getHideLoadIndicator);
        Ti::Value getHideLoadIndicator(const std::vector<Ti::Value>& args);

        // Sets the value of the ignoreSslError property.
        TI_CREATE_METHOD(TiUIWebView, setIgnoreSslError);
        Ti::Value setIgnoreSslError(const std::vector<Ti::Value>& args);

        // Gets the value of the ignoreSslError property.
        TI_CREATE_METHOD(TiUIWebView, getIgnoreSslError);
        Ti::Value getIgnoreSslError(const std::vector<Ti::Value>& args);

        // Sets the value of the lightTouchEnabled property.
        TI_CREATE_METHOD(TiUIWebView, setLightTouchEnabled);
        Ti::Value setLightTouchEnabled(const std::vector<Ti::Value>& args);

        // Gets the value of the lightTouchEnabled property.
        TI_CREATE_METHOD(TiUIWebView, getLightTouchEnabled);
        Ti::Value getLightTouchEnabled(const std::vector<Ti::Value>& args);

        // Sets the value of the onCreateWindow property.
        TI_CREATE_METHOD(TiUIWebView, setOnCreateWindow);
        Ti::Value setOnCreateWindow(const std::vector<Ti::Value>& args);

        // Gets the value of the onCreateWindow property.
        TI_CREATE_METHOD(TiUIWebView, getOnCreateWindow);
        Ti::Value getOnCreateWindow(const std::vector<Ti::Value>& args);

        // Sets the value of the overScrollMode property.
        TI_CREATE_METHOD(TiUIWebView, setOverScrollMode);
        Ti::Value setOverScrollMode(const std::vector<Ti::Value>& args);

        // Gets the value of the overScrollMode property.
        TI_CREATE_METHOD(TiUIWebView, getOverScrollMode);
        Ti::Value getOverScrollMode(const std::vector<Ti::Value>& args);

        // Sets the value of the pluginState property.
        TI_CREATE_METHOD(TiUIWebView, setPluginState);
        Ti::Value setPluginState(const std::vector<Ti::Value>& args);

        // Gets the value of the pluginState property.
        TI_CREATE_METHOD(TiUIWebView, getPluginState);
        Ti::Value getPluginState(const std::vector<Ti::Value>& args);

        // Sets the value of the scalesPageToFit property.
        TI_CREATE_METHOD(TiUIWebView, setScalesPageToFit);
        Ti::Value setScalesPageToFit(const std::vector<Ti::Value>& args);

        // Gets the value of the scalesPageToFit property.
        TI_CREATE_METHOD(TiUIWebView, getScalesPageToFit);
        Ti::Value getScalesPageToFit(const std::vector<Ti::Value>& args);

        // Sets the value of the scrollsToTop property.
        TI_CREATE_METHOD(TiUIWebView, setScrollsToTop);
        Ti::Value setScrollsToTop(const std::vector<Ti::Value>& args);

        // Gets the value of the scrollsToTop property.
        TI_CREATE_METHOD(TiUIWebView, getScrollsToTop);
        Ti::Value getScrollsToTop(const std::vector<Ti::Value>& args);

        // Sets the value of the showScrollbars property.
        TI_CREATE_METHOD(TiUIWebView, setShowScrollbars);
        Ti::Value setShowScrollbars(const std::vector<Ti::Value>& args);

        // Gets the value of the showScrollbars property.
        TI_CREATE_METHOD(TiUIWebView, getShowScrollbars);
        Ti::Value getShowScrollbars(const std::vector<Ti::Value>& args);

        // Sets the value of the userAgent property.
        TI_CREATE_METHOD(TiUIWebView, setUserAgent);
        Ti::Value setUserAgent(const std::vector<Ti::Value>& args);

        // Gets the value of the userAgent property.
        TI_CREATE_METHOD(TiUIWebView, getUserAgent);
        Ti::Value getUserAgent(const std::vector<Ti::Value>& args);

        // Sets the value of the willHandleTouches property.
        TI_CREATE_METHOD(TiUIWebView, setWillHandleTouches);
        Ti::Value setWillHandleTouches(const std::vector<Ti::Value>& args);

        // Gets the value of the willHandleTouches property.
        TI_CREATE_METHOD(TiUIWebView, getWillHandleTouches);
        Ti::Value getWillHandleTouches(const std::vector<Ti::Value>& args);

        // Returns true if the web view can go back in its history list.
        TI_CREATE_METHOD(TiUIWebView, canGoBack);
        Ti::Value canGoBack(const std::vector<Ti::Value>& args);

        // Returns true if the web view can go forward in its history list.
        TI_CREATE_METHOD(TiUIWebView, canGoForward);
        Ti::Value canGoForward(const std::vector<Ti::Value>& args);

        // Pauses native webview plugins.
        TI_CREATE_METHOD(TiUIWebView, pause);
        Ti::Value pause(const std::vector<Ti::Value>& args);

        // Releases memory when the web view is no longer needed.
        TI_CREATE_METHOD(TiUIWebView, release);
        Ti::Value release(const std::vector<Ti::Value>& args);

        // Forces the web view to repaint its contents.
        TI_CREATE_METHOD(TiUIWebView, repaint);
        Ti::Value repaint(const std::vector<Ti::Value>& args);

        // Resume native webview plugins.
        TI_CREATE_METHOD(TiUIWebView, resume);
        Ti::Value resume(const std::vector<Ti::Value>& args);

        // Sets the basic authentication for this web view to use on subsequent URl requests.
        TI_CREATE_METHOD(TiUIWebView, setBasicAuthentication);
        Ti::Value setBasicAuthentication(const std::vector<Ti::Value>& args);
    };

}   // namespace UI {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIWEBVIEW_H_
