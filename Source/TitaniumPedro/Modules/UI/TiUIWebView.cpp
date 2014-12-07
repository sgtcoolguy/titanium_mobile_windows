/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#include "Modules/UI/TiUIWebView.h"
#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiUtils.h"
#include "UIModule.h"
#include "TiCore/TiRuntime.h"
#include <collection.h>
#include <ppltasks.h>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

namespace UI {

    std::unordered_map <std::intptr_t, std::weak_ptr<TiUIWebView>> TiUIWebView::webviews_;

    std::string TiUIWebView::defaultHeight() const {
        return Ti::Constants::SizeFILL;
    }

    std::string TiUIWebView::defaultWidth() const {
        return Ti::Constants::SizeFILL;
    }

    Ti::Value TiUIWebView::eventAdded(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }
        const auto arg = args.at(0).toString();

        if (arg == Ti::Constants::EventLoad) {
            ++load_listener_count_;
        }
        else if (arg == Ti::Constants::EventBeforeLoad) {
            ++beforeload_listener_count_;
        }
        else if (arg == Ti::Constants::EventError) {
            ++error_listener_count_;
        }

        return Ti::ViewProxy::eventAdded(args);
    }

    Ti::Value TiUIWebView::eventRemoved(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }
        const auto arg = args.at(0).toString();
        if (arg == Ti::Constants::EventLoad) {
            --load_listener_count_;
        } else if (arg == Ti::Constants::EventBeforeLoad) {
            --beforeload_listener_count_;
        } else if (arg == Ti::Constants::EventError) {
            --error_listener_count_;
        }
        return Ti::ViewProxy::eventRemoved(args);
    }

    TiUIWebView::TiUIWebView(const std::string& name, const std::vector<Ti::Value>& args) : Ti::ViewProxy(name, args) {
        this->webview_ = ref new Windows::UI::Xaml::Controls::WebView();
        this->titaniumInjectionJavaScript = Ti::Utils::GetPlatformString(loadTitaniumInjectionJavaScript());
        setComponent(webview_);
    }

    void TiUIWebView::postConstruct() {
        ViewProxy::postConstruct();
        initWebViewListeners();

        self = reinterpret_cast<intptr_t>(this);
        webviews_.insert(std::make_pair(self, get_weak_ptr_for_proxy()));
    }

    TiUIWebView::~TiUIWebView() {
        webview_->NavigationCompleted -= load_event_;
        webview_->NavigationStarting -= beforeload_event_;
        webview_->ScriptNotify -= script_event_;
        webview_ = nullptr;

        webviews_.erase(self);
    }

    std::unordered_map<std::intptr_t, std::weak_ptr<TiUIWebView>> TiUIWebView::getWebViewProxies() {
        return webviews_;
    }

    void TiUIWebView::executeListener(const Ti::Value& name, const Ti::Value& obj) {
        const auto script = (boost::format("Ti.executeListener(%1%, JSON.parse('%2%'));\r\n") % name.toJSONString() % obj.toJSONString()).str();
        std::vector<Ti::Value> args;
        args.push_back(Ti::Value(script));
        args.push_back(Ti::Value());
        this->evalJS(args);
    }


    Platform::String^ TiUIWebView::loadTitaniumInjectionJavaScript() {
        Platform::String^ content;
        concurrency::event event;
        concurrency::task<Windows::Storage::StorageFile^>(Windows::Storage::StorageFile::GetFileFromPathAsync(
            Windows::ApplicationModel::Package::Current->InstalledLocation->Path + L"\\TitaniumPedro\\TiUIWebViewBinding.js")).then([&content, &event](concurrency::task<Windows::Storage::StorageFile^> task) {
            concurrency::task<Platform::String^>(Windows::Storage::FileIO::ReadTextAsync(task.get(), Windows::Storage::Streams::UnicodeEncoding::Utf8)).then([&content, &event](concurrency::task<Platform::String^> task) {
                content = task.get();
                event.set();
            }, concurrency::task_continuation_context::use_arbitrary());
        }, concurrency::task_continuation_context::use_arbitrary());
        event.wait();
        return content;
    }

    int TiUIWebView::getWebViewError(const Windows::Web::WebErrorStatus status) {
        using namespace Windows::Web;
        int code = UIModule::URL_ERROR_UNKNOWN;
        if (status == WebErrorStatus::Unauthorized) {
            code = UIModule::URL_ERROR_AUTHENTICATION;
        }
        else if (status == WebErrorStatus::Timeout || status == WebErrorStatus::RequestTimeout || status == WebErrorStatus::GatewayTimeout) {
            code = UIModule::URL_ERROR_TIMEOUT;
        }
        else if (status == WebErrorStatus::CertificateCommonNameIsIncorrect || status == WebErrorStatus::CertificateContainsErrors || status == WebErrorStatus::CertificateExpired || status == WebErrorStatus::CertificateIsInvalid || status == WebErrorStatus::CertificateRevoked) {
            code = UIModule::URL_ERROR_SSL_FAILED;
        }
        else if (status == WebErrorStatus::RequestUriTooLong) {
            code = UIModule::URL_ERROR_BAD_URL;
        }
        else if (status == WebErrorStatus::CannotConnect || status == WebErrorStatus::ConnectionAborted || status == WebErrorStatus::ConnectionReset || status == WebErrorStatus::ConnectionReset) {
            code = UIModule::URL_ERROR_CONNECT;
        }
        else if (status == WebErrorStatus::NotFound) {
            code = UIModule::URL_ERROR_FILE_NOT_FOUND;
        }
        else if (status == WebErrorStatus::HostNameNotResolved) {
            code = UIModule::URL_ERROR_HOST_LOOKUP;
        }
        return code;
    }

    void TiUIWebView::initWebViewListeners() {
        using namespace std::placeholders;

        const auto loadCallback = std::bind([](const TiUIWebView_weak_ptr_t& weakThis, Platform::Object^ sender, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs^ e) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
                strong_ptr->navigating = false;
                if (e->IsSuccess && strong_ptr->load_listener_count_ > 0) {
                    Ti::Value obj;
                    obj.setProperty("type", Ti::Value("load"));
                    if (strong_ptr->webview_->Source != nullptr) {
                        obj.setProperty("url", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->webview_->Source->ToString())));
                    }
                    strong_ptr->fireEvent(Ti::Constants::EventLoad, obj);
                }
                else if (!e->IsSuccess && strong_ptr->error_listener_count_ > 0) {
                    Ti::Value obj;
                    obj.setProperty("type", Ti::Value("error"));
                    obj.setProperty("success", Ti::Value(false));
                    if (strong_ptr->webview_->Source != nullptr) {
                        obj.setProperty("url", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->webview_->Source->ToString())));
                    }
                    obj.setProperty("code", Ti::Value(static_cast<double>(strong_ptr->getWebViewError(e->WebErrorStatus))));
                    strong_ptr->fireEvent(Ti::Constants::EventError, obj);
                }
            }
        }, std::move(get_weak_ptr_for_proxy()), _1, _2);
        load_event_ = webview_->NavigationCompleted +=
            ref new Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView^, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs^>(loadCallback);

        const auto beforeloadCallback = std::bind([](const TiUIWebView_weak_ptr_t& weakThis, Platform::Object^ sender, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs^ e) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
                strong_ptr->navigating = true;
                if (strong_ptr->beforeload_listener_count_ > 0) {
                    Ti::Value obj;
                    obj.setProperty("type", Ti::Value("beforeload"));
                    if (strong_ptr->webview_->Source != nullptr) {
                        obj.setProperty("url", Ti::Value(Ti::Utils::GetPlatformString(strong_ptr->webview_->Source->ToString())));
                    }
                    strong_ptr->fireEvent(Ti::Constants::EventBeforeLoad, obj);
                }
            }
        }, std::move(get_weak_ptr_for_proxy()), _1, _2);
        beforeload_event_ = webview_->NavigationStarting +=
            ref new Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView^, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs^>(beforeloadCallback);

        const auto scriptCallback = std::bind([](const TiUIWebView_weak_ptr_t& weakThis, Platform::Object^ sender, Windows::UI::Xaml::Controls::NotifyEventArgs^ e) {
            const auto strong_ptr = weakThis.lock();
            if (strong_ptr) {
                const auto value = Ti::Utils::GetPlatformString(e->Value);
                std::vector<std::string> args;
                boost::split(args, value, boost::is_any_of(","));

                // we need at least 3 arguments
                if (args.size() < 3) {
                    return;
                }

                // notify command
                const auto command = args.at(0);
                // first argument
                const auto arg1 = args.at(1);
                // rest of arguments
                const auto arg2 = value.substr(command.length() + arg1.length() + 2);

                if (command == "log") {
                    std::clog << "[" << arg1 << "] " << arg2 << std::endl;
                }
                else if (command == "event") {
                    // Event execution shortcut: let's do just like the way Ti Blackberry does for now
                    const auto script = (boost::format("Ti.App.fireEvent('%1%', %2%);\r\n") % arg1 % arg2).str();
                    Ti::evaluateScript(script);
                }
            }
        }, std::move(get_weak_ptr_for_proxy()), _1, _2);

        script_event_ = webview_->ScriptNotify +=
            ref new Windows::UI::Xaml::Controls::NotifyEventHandler(scriptCallback);
    }


    ////////////////////////////////////////////////////////////////////////
    //
    // Proxy macro infrastructure goes below here.
    //
    ////////////////////////////////////////////////////////////////////////

    JSStaticFunction const TiUIWebView::ClassMethods[] = {
    { "setUrl", _setUrl, 0 },
    { "getUrl", _getUrl, 0 },
    { "setOpacity", _setOpacity, 0 },
    { "getOpacity", _getOpacity, 0 },
    { "setHtml", _setHtml, 0 },
    { "getHtml", _getHtml, 0 },
    { "getLoading", _getLoading, 0 },
    { "goBack", _goBack, 0 },
    { "goForward", _goForward, 0 },
    { "stopLoading", _stopLoading, 0 },
    { "reload", _reload, 0 },
    { "setData", _setData, 0 },
    { "getData", _getData, 0 },
    { "evalJS", _evalJS, 0 },
    { "canGoBack", _canGoBack, 0 },
    { "canGoForward", _canGoForward, 0 },
    { "setCacheMode", _setCacheMode, 0 },
    { "getCacheMode", _getCacheMode, 0 },
    { "setDisableBounce", _setDisableBounce, 0 },
    { "getDisableBounce", _getDisableBounce, 0 },
    { "setEnableZoomControls", _setEnableZoomControls, 0 },
    { "getEnableZoomControls", _getEnableZoomControls, 0 },
    { "setHandlePlatformUrl", _setHandlePlatformUrl, 0 },
    { "getHandlePlatformUrl", _getHandlePlatformUrl, 0 },
    { "setHideLoadIndicator", _setHideLoadIndicator, 0 },
    { "getHideLoadIndicator", _getHideLoadIndicator, 0 },
    { "setIgnoreSslError", _setIgnoreSslError, 0 },
    { "getIgnoreSslError", _getIgnoreSslError, 0 },
    { "setLightTouchEnabled", _setLightTouchEnabled, 0 },
    { "getLightTouchEnabled", _getLightTouchEnabled, 0 },
    { "setOnCreateWindow", _setOnCreateWindow, 0 },
    { "getOnCreateWindow", _getOnCreateWindow, 0 },
    { "setOverScrollMode", _setOverScrollMode, 0 },
    { "getOverScrollMode", _getOverScrollMode, 0 },
    { "setPluginState", _setPluginState, 0 },
    { "getPluginState", _getPluginState, 0 },
    { "setScalesPageToFit", _setScalesPageToFit, 0 },
    { "getScalesPageToFit", _getScalesPageToFit, 0 },
    { "setScrollsToTop", _setScrollsToTop, 0 },
    { "getScrollsToTop", _getScrollsToTop, 0 },
    { "setShowScrollbars", _setShowScrollbars, 0 },
    { "getShowScrollbars", _getShowScrollbars, 0 },
    { "setUserAgent", _setUserAgent, 0 },
    { "getUserAgent", _getUserAgent, 0 },
    { "setWillHandleTouches", _setWillHandleTouches, 0 },
    { "getWillHandleTouches", _getWillHandleTouches, 0 },
    { "pause", _pause, 0 },
    { "release", _release, 0 },
    { "repaint", _repaint, 0 },
    { "resume", _resume, 0 },
    { "setBasicAuthentication", _setBasicAuthentication, 0 },
    { 0, 0, 0 }
    };

    JSClassRef TiUIWebView::Parent() {
        return Ti::ViewProxy::ClassDef();
    }

    // Sets the value of the url property.
    Ti::Value TiUIWebView::setUrl(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }
        this->webview_->Navigate(ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(args.at(0).toString())));
        return Ti::Value::Undefined();
    }

    // Gets the value of the url property.
    Ti::Value TiUIWebView::getUrl(const std::vector<Ti::Value>& args) {
        if (this->webview_->Source != nullptr) {
            return Ti::Value(Ti::Utils::GetPlatformString(this->webview_->Source->ToString()));
        }
        else {
            return Ti::Value::Undefined();
        }
    }

    // Sets the value of the opacity property.
    Ti::Value TiUIWebView::setOpacity(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }
        this->webview_->Opacity = args.at(0).toDouble();
        return Ti::Value::Undefined();
    }

    // Gets the value of the opacity property.
    Ti::Value TiUIWebView::getOpacity(const std::vector<Ti::Value>& args) {
        return Ti::Value(this->webview_->Opacity);
    }

    // Sets the value of the html property.
    Ti::Value TiUIWebView::setHtml(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }
        std::string content = args.at(0).toString();

        if (titaniumInjectionJavaScript.length() > 0) {
            // attempt to inject in our Titanium bridge code (mostly copied from iOS WebView)
            // However, we only do this if the content looks like HTML 
            const auto found = content.find_first_of("<html");
            if (found != std::string::npos) {
                const auto start = content.find_first_of(">", found);
                if (start != std::string::npos) {
                    content.insert(start + 1, "<script id='__ti_injection'>" + titaniumInjectionJavaScript + "</script>");
                }
            }
        }

        webview_->NavigateToString(Ti::Utils::GetPlatformString(content));
        return Ti::Value::Undefined();
    }

    // Evaluates a JavaScript expression inside the context of the web view and
    // optionally, returns a result.
    // Note: On Windows Store/Phone, evalJS is an async function. Use with WebView.evalJS(script, callback_function(result){});
    Ti::Value TiUIWebView::evalJS(const std::vector<Ti::Value>& args) {
        if (args.size() < 2) {
            std::clog << "[ERROR] WebView.evalJS works with callback. Use evalJS(script, callback)." << std::endl;
            return Ti::Value::Undefined();
        }
        const auto arguments = ref new Platform::Collections::Vector<Platform::String^>();
        arguments->Append(Ti::Utils::GetPlatformString(args.at(0).toString()));

        const auto func = args.at(1).JSObjectRef();
        JSValueProtect(Ti::Runtime::instance().globalContext(), func);

        concurrency::create_task(webview_->InvokeScriptAsync("eval", arguments)).then([func](Platform::String ^result) {
            const auto ctx = Ti::Runtime::instance().globalContext();
            const JSValueRef jsargs[] = { Ti::Value(Ti::Utils::GetPlatformUTF8String(result)).JSValueRef() };
            if (JSObjectIsFunction(ctx, func)) {
                JSObjectCallAsFunction(ctx, func, Ti::Runtime::instance().globalObject(), 1, jsargs, nullptr);
            }
            JSValueUnprotect(ctx, func);
        });

        return Ti::Value::Undefined();
    }

    // Gets the value of the loading property.
    Ti::Value TiUIWebView::getLoading(const std::vector<Ti::Value>& args) {
        return Ti::Value(navigating);
    }

    // Goes back one entry in the web view's history list, to the previous page.
    Ti::Value TiUIWebView::goBack(const std::vector<Ti::Value>& args) {
        if (webview_->CanGoBack) {
            webview_->GoBack();
        }
        return Ti::Value::Undefined();
    }

    // Goes forward one entry in this web view's history list, if possible.
    Ti::Value TiUIWebView::goForward(const std::vector<Ti::Value>& args) {
        if (webview_->CanGoForward) {
            webview_->GoForward();
        }
        return Ti::Value::Undefined();
    }

    // Stops loading a currently loading page.
    Ti::Value TiUIWebView::stopLoading(const std::vector<Ti::Value>& args) {
        webview_->Stop();
        return Ti::Value::Undefined();
    }

    // Reloads the current webpage.
    Ti::Value TiUIWebView::reload(const std::vector<Ti::Value>& args) {
        webview_->Refresh();
        return Ti::Value::Undefined();
    }

    // Sets the value of the data property.
    Ti::Value TiUIWebView::setData(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            return Ti::Value::Undefined();
        }

        if (args.at(0).isString()) {
            return setHtml(args);
        }
        else {
            std::clog << "[WARN] Ti.UI.WebView.setData() is not implented yet" << std::endl;
        }
        return Ti::Value::Undefined();
    }

    // Gets the value of the data property.
    Ti::Value TiUIWebView::getData(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getData() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }

    // Gets the value of the html property.
    // Note: On Windows Store/Phone, getHtml is an async function. Use with WebView.getHtml(callback_function(result){});
    Ti::Value TiUIWebView::getHtml(const std::vector<Ti::Value>& args) {
        if (args.size() < 1) {
            std::clog << "[ERROR] WebView.getHtml works with callback. Use WebView.getHtml(callback)" << std::endl;
            return Ti::Value::Undefined();
        }

        const auto arguments = ref new Platform::Collections::Vector<Platform::String^>();
        arguments->Append("document.documentElement.outerHTML;");

        const auto func = args.at(0).JSObjectRef();
        JSValueProtect(Ti::Runtime::instance().globalContext(), func);

        concurrency::create_task(webview_->InvokeScriptAsync("eval", arguments)).then([func](Platform::String ^result) {
            const auto ctx = Ti::Runtime::instance().globalContext();
            const JSValueRef jsargs[] = { Ti::Value(Ti::Utils::GetPlatformUTF8String(result)).JSValueRef() };
            const auto isFunc = JSObjectIsFunction(ctx, func);
            JSObjectCallAsFunction(ctx, func, Ti::Runtime::instance().globalObject(), 1, jsargs, nullptr);
            JSValueUnprotect(ctx, func);
        });

        return Ti::Value::Undefined();
    }

    // Sets the value of the cacheMode property.
    Ti::Value TiUIWebView::setCacheMode(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setCacheMode() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the cacheMode property.
    Ti::Value TiUIWebView::getCacheMode(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getCacheMode() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the disableBounce property.
    Ti::Value TiUIWebView::setDisableBounce(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setDisableBounce() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the disableBounce property.
    Ti::Value TiUIWebView::getDisableBounce(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getDisableBounce() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the enableZoomControls property.
    Ti::Value TiUIWebView::setEnableZoomControls(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setEnableZoomControls() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the enableZoomControls property.
    Ti::Value TiUIWebView::getEnableZoomControls(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getEnableZoomControls() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the handlePlatformUrl property.
    Ti::Value TiUIWebView::setHandlePlatformUrl(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setHandlePlatformUrl() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the handlePlatformUrl property.
    Ti::Value TiUIWebView::getHandlePlatformUrl(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getHandlePlatformUrl() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the hideLoadIndicator property.
    Ti::Value TiUIWebView::setHideLoadIndicator(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setHideLoadIndicator() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the hideLoadIndicator property.
    Ti::Value TiUIWebView::getHideLoadIndicator(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getHideLoadIndicator() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the ignoreSslError property.
    Ti::Value TiUIWebView::setIgnoreSslError(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setIgnoreSslError() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the ignoreSslError property.
    Ti::Value TiUIWebView::getIgnoreSslError(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getIgnoreSslError() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the lightTouchEnabled property.
    Ti::Value TiUIWebView::setLightTouchEnabled(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setLightTouchEnabled() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the lightTouchEnabled property.
    Ti::Value TiUIWebView::getLightTouchEnabled(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getLightTouchEnabled() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the onCreateWindow property.
    Ti::Value TiUIWebView::setOnCreateWindow(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setOnCreateWindow() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the onCreateWindow property.
    Ti::Value TiUIWebView::getOnCreateWindow(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getOnCreateWindow() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the overScrollMode property.
    Ti::Value TiUIWebView::setOverScrollMode(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setOverScrollMode() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the overScrollMode property.
    Ti::Value TiUIWebView::getOverScrollMode(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getOverScrollMode() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the pluginState property.
    Ti::Value TiUIWebView::setPluginState(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setPluginState() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the pluginState property.
    Ti::Value TiUIWebView::getPluginState(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getPluginState() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the scalesPageToFit property.
    Ti::Value TiUIWebView::setScalesPageToFit(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setScalesPageToFit() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the scalesPageToFit property.
    Ti::Value TiUIWebView::getScalesPageToFit(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getScalesPageToFit() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the scrollsToTop property.
    Ti::Value TiUIWebView::setScrollsToTop(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setScrollsToTop() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the scrollsToTop property.
    Ti::Value TiUIWebView::getScrollsToTop(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getScrollsToTop() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the showScrollbars property.
    Ti::Value TiUIWebView::setShowScrollbars(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setShowScrollbars() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the showScrollbars property.
    Ti::Value TiUIWebView::getShowScrollbars(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getShowScrollbars() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the userAgent property.
    Ti::Value TiUIWebView::setUserAgent(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setUserAgent() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the userAgent property.
    Ti::Value TiUIWebView::getUserAgent(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getUserAgent() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the value of the willHandleTouches property.
    Ti::Value TiUIWebView::setWillHandleTouches(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setWillHandleTouches() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Gets the value of the willHandleTouches property.
    Ti::Value TiUIWebView::getWillHandleTouches(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.getWillHandleTouches() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Returns true if the web view can go back in its history list.
    Ti::Value TiUIWebView::canGoBack(const std::vector<Ti::Value>& args) {
        return Ti::Value(webview_->CanGoBack);
    }
    // Returns true if the web view can go forward in its history list.
    Ti::Value TiUIWebView::canGoForward(const std::vector<Ti::Value>& args) {
        return Ti::Value(webview_->CanGoForward);
    }
    // Pauses native webview plugins.
    Ti::Value TiUIWebView::pause(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.pause() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Releases memory when the web view is no longer needed.
    Ti::Value TiUIWebView::release(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.release() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Forces the web view to repaint its contents.
    Ti::Value TiUIWebView::repaint(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.repaint() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Resume native webview plugins.
    Ti::Value TiUIWebView::resume(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.resume() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }
    // Sets the basic authentication for this web view to use on subsequent URl requests.
    Ti::Value TiUIWebView::setBasicAuthentication(const std::vector<Ti::Value>& args) {
        std::clog << "[WARN] WebView.setBasicAuthentication() not implemented yet. Returning Undefined" << std::endl;
        return Ti::Value::Undefined();
    }

}   // namespace UI {
