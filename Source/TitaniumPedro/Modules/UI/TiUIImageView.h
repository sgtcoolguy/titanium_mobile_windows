/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIIMAGEVIEW_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIIMAGEVIEW_H_

#include "TiCore/TiViewProxy.h"
#include "TiCore/TiUtils.h"
#include <algorithm>
#include <boost\algorithm\string\predicate.hpp>

namespace Ti { namespace UI {

class ImageView : public Ti::ViewProxy, public virtual_enable_shared_from_this<ImageView> {

 public:

	// The TIViewProxy defaults for height and width are correct.

 protected:

	ImageView(const std::string& name, const std::vector<Ti::Value>& arguments);

	virtual ~ImageView() {
		image_->ImageOpened -= internal_load_event_;
	}

	virtual void postConstruct();
 private:
	Windows::Foundation::EventRegistrationToken internal_load_event_;
	Windows::UI::Xaml::Controls::Image^ image_{ nullptr };
	std::string path_;

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(ImageView);

	static JSClassRef Parent() {
		return Ti::ViewProxy::ClassDef();
	}

	// Gets the value of the animating property.
	TI_CREATE_METHOD(ImageView, getAnimating);
	Ti::Value getAnimating(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] Window.getAnimating() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the animating property.
	TI_CREATE_METHOD(ImageView, setAnimating);
	Ti::Value setAnimating(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setAnimating() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the autorotate property.
	TI_CREATE_METHOD(ImageView, getAutorotate);
	// Gets the value of the autorotate property.
	Ti::Value getAutorotate(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getAutorotate() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the autorotate property.
	TI_CREATE_METHOD(ImageView, setAutorotate);
	Ti::Value setAutorotate(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setAutorotate() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the decodeRetries property.
	TI_CREATE_METHOD(ImageView, getDecodeRetries);
	Ti::Value getDecodeRetries(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getDecodeRetries() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the decodeRetries property.
	TI_CREATE_METHOD(ImageView, setDecodeRetries);
	Ti::Value setDecodeRetries(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setDecodeRetries() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the defaultImage property.
	TI_CREATE_METHOD(ImageView, getDefaultImage);
	Ti::Value getDefaultImage(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getDefaultImage() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the defaultImage property.
	TI_CREATE_METHOD(ImageView, setDefaultImage);
	Ti::Value setDefaultImage(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setDefaultImage() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the duration property.
	TI_CREATE_METHOD(ImageView, getDuration);
	Ti::Value getDuration(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getDuration() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the duration property.
	TI_CREATE_METHOD(ImageView, setDuration);
	Ti::Value setDuration(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setDuration() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the enableZoomControls property.
	TI_CREATE_METHOD(ImageView, getEnableZoomControls);
	Ti::Value getEnableZoomControls(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getEnableZoomControls() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	TI_CREATE_METHOD(ImageView, setEnableZoomControls);
	Ti::Value setEnableZoomControls(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setEnableZoomControls() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the hires property.
	TI_CREATE_METHOD(ImageView, getHires);
	Ti::Value getHires(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getHires() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the hires property.
	TI_CREATE_METHOD(ImageView, setHires);
	Ti::Value setHires(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setHires() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the image property.
	TI_CREATE_METHOD(ImageView, getImage);
	Ti::Value getImage(const std::vector<Ti::Value>& arguments);

	// Sets the value of the image property.
	TI_CREATE_METHOD(ImageView, setImage);
	Ti::Value setImage(const std::vector<Ti::Value>& arguments);

	// Gets the value of the images property.
	TI_CREATE_METHOD(ImageView, getImages);
	Ti::Value getImages(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getImages() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the images property.
	TI_CREATE_METHOD(ImageView, setImages);
	Ti::Value setImages(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setImages() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the paused property.
	TI_CREATE_METHOD(ImageView, getPaused);
	Ti::Value getPaused(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getPaused() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the paused property.
	TI_CREATE_METHOD(ImageView, setPaused);
	Ti::Value setPaused(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setPaused() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the preventDefaultImage property.
	TI_CREATE_METHOD(ImageView, getPreventDefaultImage);
	Ti::Value getPreventDefaultImage(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getPreventDefaultImage() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the preventDefaultImage property.
	TI_CREATE_METHOD(ImageView, setPreventDefaultImage);
	Ti::Value setPreventDefaultImage(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setPreventDefaultImage() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the repeatCount property.
	TI_CREATE_METHOD(ImageView, getRepeatCount);
	Ti::Value getRepeatCount(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getRepeatCount() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the repeatCount property.
	TI_CREATE_METHOD(ImageView, setRepeatCount);
	Ti::Value setRepeatCount(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setRepeatCount() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Gets the value of the reverse property.
	TI_CREATE_METHOD(ImageView, getReverse);
	Ti::Value getReverse(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.getReverse() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}

	// Sets the value of the reverse property.
	TI_CREATE_METHOD(ImageView, setReverse);
	Ti::Value setReverse(const std::vector<Ti::Value>& arguments) {
		OutputDebugString(L"[WARN] ImageView.setReverse() not implemented yet. Returning Undefined");
		return Ti::Value::Undefined();
	}
};

}} // namespace Ti { namespace UI {

#endif // #define _TITANIUM_MOBILE_WINDOWS_MODULES_UI_TIUIIMAGEVIEW_H_
