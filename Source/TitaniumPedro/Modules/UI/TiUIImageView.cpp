/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "Modules/UI/TiUIImageView.h"
#include <Windows.h>
#include "TiCore/TiWebColor.h"

namespace Ti { namespace UI {


ImageView::ImageView(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::ViewProxy(name, arguments) {
	image_ = ref new Windows::UI::Xaml::Controls::Image();
	setComponent(image_);
}

void ImageView::postConstruct()
{
	using namespace Windows::UI::Xaml;
	using namespace Windows::UI::Xaml::Controls;

	auto weak = get_weak_ptr_for_proxy();
	internal_load_event_ = image_->ImageOpened += ref new RoutedEventHandler([weak](Platform::Object ^sender, RoutedEventArgs ^e)
	{
		auto proxy = weak.lock();
		assert(proxy);

		auto rect = Layout::RectMake(
			Canvas::GetLeft(proxy->image_),
			Canvas::GetTop(proxy->image_),
			proxy->image_->ActualWidth,
			proxy->image_->ActualHeight
			);
		proxy->onComponentSizeChange(rect);
	});

}

Ti::Value ImageView::getImage(const std::vector<Ti::Value>& arguments) {
	return Ti::Value(path_);
}

Ti::Value ImageView::setImage(const std::vector<Ti::Value>& arguments) {
	auto path = arguments.at(0).toString();
	path_ = path;
	// if the path isn't an http/s URI already, fix URI to point to local files in app
	if (!boost::starts_with(path, "http://") && !boost::starts_with(path, "https://")) {
		// URIs must be absolute
		if (!boost::starts_with(path, "/")) {
			path = "/" + path;
		}
		// use MS's in-app URL scheme
		path = "ms-appx://" + path;
	}
	auto uri = ref new Windows::Foundation::Uri(Ti::Utils::GetPlatformString(path));
	auto image = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
	image_->Source = image;
	return Ti::Value::Undefined();
}

////////////////////////////////////////////////////////////////////////
//
// Proxy macro infrastructure goes below here.
//
////////////////////////////////////////////////////////////////////////

const JSStaticFunction ImageView::ClassMethods[] = {
	{ "setAnimating", _setAnimating, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getAnimating", _getAnimating, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setAutorotate", _setAutorotate, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getAutorotate", _getAutorotate, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setDecodeRetries", _setDecodeRetries, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getDecodeRetries", _getDecodeRetries, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setDefaultImage", _setDefaultImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getDefaultImage", _getDefaultImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setDuration", _setDuration, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getDuration", _getDuration, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setEnableZoomControls", _setEnableZoomControls, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getEnableZoomControls", _getEnableZoomControls, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setHires", _setHires, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getHires", _getHires, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setImage", _setImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getImage", _getImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setImages", _setImages, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getImages", _getImages, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setPaused", _setPaused, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getPaused", _getPaused, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setPreventDefaultImage", _setPreventDefaultImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getPreventDefaultImage", _getPreventDefaultImage, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setRepeatCount", _setRepeatCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getRepeatCount", _getRepeatCount, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "setReverse", _setReverse, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ "getReverse", _getReverse, kJSPropertyAttributeReadOnly | kJSPropertyAttributeDontDelete },
	{ 0, 0, 0 }
};

}} // namespace Ti { namespace UI {
