/**
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#include "TiBlob.h"
#include "TiCore/TiRuntimeFunctions.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <ppltasks.h>

namespace Ti { namespace Blob {

	static std::string gCode =
		"(function(self){"
		""
		"Object.defineProperties(self, {"
		"		'file': {get:function(){return this.getFile();},enumerable: true},"
		"		'height': {get:function(){return this.getHeight();},enumerable: true},"
		"		'length': {get:function(){return this.getLength();},enumerable: true},"
		"		'mimeType': {get:function(){return this.getMimeType();},enumerable: true},"
		"		'nativePath': {get:function(){return this.getNativePath();},enumerable: true},"
		"		'size': {get:function(){return this.getSize();},enumerable: true},"
		"		'text': {get:function(){return this.getText();},enumerable: true},"
		"		'width': {get:function(){return this.getWidth();},enumerable: true},"
		"});"
		" return self;"
		""
		"})(this);"
		;

	// postConstruct
	// Setup additional properties 
	void Blob::postConstruct() {
		Ti::evaluateScriptInObject(gCode, Ti::Value(get_js_object())).toString();
	}

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	// These are JavaScript methods they will call class methods
	const JSStaticFunction Blob::ClassMethods[] = {
			{ "getFile", _getFile, 0 },
			{ "getHeight", _getHeight, 0 },
			{ "getLength", _getLength, 0 },
			{ "getMimeType", _getMimeType, 0 },
			{ "getNativePath", _getNativePath, 0 },
			{ "getSize", _getSize, 0 },
			{ "getText", _getText, 0 },
			{ "getWidth", _getWidth, 0 },
			{ "append", _append, 0 },
			{ "toString", _toString, 0 },
			{ 0, 0, 0 }
	};

	Blob::Blob(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
		std::clog << "[ERROR] This should never be happening" << std::endl;
		assert(false);
	}

	// Initialize the blob with a data
	Blob::Blob(std::vector<unsigned char> data, std::string mimetype) : Ti::Proxy("Ti.Blob", std::vector<Ti::Value>()), data_(data), mimetype_(mimetype), type_(TiBlobType::Data) {

	}

	//  Initialize the blob with contents of a file.
	Blob::Blob(Windows::Storage::StorageFile^ file) : Ti::Proxy("Ti.Blob", std::vector<Ti::Value>()), type_(TiBlobType::File) {
		data_ = Ti::Utils::GetContentFromFile(file);
		path_ = Ti::Utils::GetPlatformString(file->Path);
		mimetype_ = Ti::Utils::MimeTypeForExtension(path_);
	}

	// Initialize the blob with given mimetype.
	// Blob content should be constructed by subsequent toImage() call.
	Blob::Blob(std::string mimetype) : Ti::Proxy("Ti.Blob", std::vector<Ti::Value>()), mimetype_(mimetype), type_(TiBlobType::Image) {

	}

	Ti::Value Blob::toValue() {
		return Ti::Value(this->get_js_object());
	}

	std::vector<unsigned char> Blob::getData() {
		return data_;
	}

	std::size_t Blob::size() {
		return data_.size();
	}

	::Platform::Guid Blob::getImageEncoder() {
		if (mimetype_ == "image/png") {
			return Windows::Graphics::Imaging::BitmapEncoder::PngEncoderId;
		}
		else if (mimetype_ == "image/jpg") {
			return Windows::Graphics::Imaging::BitmapEncoder::PngEncoderId;
		}
		else {
			return Windows::Graphics::Imaging::BitmapEncoder::BmpEncoderId;
		}
	}

	// Construct image data
	// This is needed because constructor prevents from using weak_ptr to "this"
	void Blob::toImage(Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap^ image,
		const std::function<void(const std::shared_ptr<Ti::Blob::Blob>& blob)> callback) {

		if (type_ != TiBlobType::Image) {
			std::clog << "[ERROR] Blob.toImage is only used for Image type" << std::endl;
			return;
		}

		width_ = image->PixelWidth;
		height_ = image->PixelHeight;

		const ::Platform::Guid encoder = getImageEncoder();

		const auto func = std::bind([image, encoder, callback](const Blob_weak_ptr_t& weakThis, concurrency::task<Windows::Storage::Streams::IBuffer^> task) {
			using namespace Windows::Storage;
			using namespace Windows::Graphics::Imaging;
			using namespace Windows::Graphics::Display;
			using namespace concurrency;

			const auto pixelBuffer = task.get();
			const auto stream = ref new Streams::InMemoryRandomAccessStream();
			const auto reader = ref new Streams::DataReader(stream->GetInputStreamAt(0));
			create_task(BitmapEncoder::CreateAsync(encoder, stream)).then([pixelBuffer, image](BitmapEncoder^ encoder) {
				auto data = Ti::Utils::GetContentFromBuffer(pixelBuffer);
				if (data.size() > 0) {
					encoder->SetPixelData(
						BitmapPixelFormat::Bgra8,
						BitmapAlphaMode::Straight,
						static_cast<unsigned int>(image->PixelWidth),
						static_cast<unsigned int>(image->PixelHeight),
						static_cast<double>(DisplayInformation::GetForCurrentView()->LogicalDpi),
						static_cast<double>(DisplayInformation::GetForCurrentView()->LogicalDpi),
						Platform::ArrayReference<unsigned char>(&data[0], data.size())
						);
				}
				return encoder->FlushAsync();
			}).then([stream, reader]() {
				reader->LoadAsync(stream->Size);
			}).then([stream, reader, weakThis, callback]() {
				const auto strong_ptr = weakThis.lock();
				if (strong_ptr) {
					std::vector<unsigned char> data(stream->Size);
					if (!data.empty()) {
						reader->ReadBytes(::Platform::ArrayReference<unsigned char>(&data[0], data.size()));
					}
					strong_ptr->data_ = data;
					callback(strong_ptr);
				}
			});

		}, std::move(get_weak_ptr_for_proxy()), std::placeholders::_1);

		concurrency::create_task(image->GetPixelsAsync()).then(func);
	}


	JSClassRef Blob::Parent() {
		return Ti::Proxy::ClassDef();
	}

	// Gets the value of the file property.
	Ti::Value Blob::getFile(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::File && path_.size() > 0) {
			const auto path = boost::algorithm::replace_all_copy(path_, "\\", "\\\\");
			return Ti::evaluateScript((boost::format("Ti.Filesystem.getFile('%1%');") % path).str());
		}
		else {
			return Ti::Value::Null();
		}
	}

	// Gets the value of the height property.
	Ti::Value Blob::getHeight(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::Image) {
			return Ti::Value(static_cast<double>(height_));
		}
		else {
			return Ti::Value(0.0);
		}
	}
	// Gets the value of the width property.
	Ti::Value Blob::getWidth(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::Image) {
			return Ti::Value(static_cast<double>(width_));
		}
		else {
			return Ti::Value(0.0);
		}
	}
	// Gets the value of the length property.
	Ti::Value Blob::getLength(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(static_cast<double>(data_.size()));
	}
	// Gets the value of the mimeType property.
	Ti::Value Blob::getMimeType(const std::vector<Ti::Value>& arguments) {
		return Ti::Value(mimetype_);
	}
	// Gets the value of the nativePath property.
	Ti::Value Blob::getNativePath(const std::vector<Ti::Value>& arguments) {
		if (path_.size() > 0) {
			return Ti::Value(path_);
		}
		else {
			return Ti::Value::Null();
		}
	}
	// Gets the value of the size property.
	Ti::Value Blob::getSize(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::Image) {
			return Ti::Value(static_cast<double>(width_ * height_));
		}
		else {
			return Ti::Value(static_cast<double>(data_.size()));
		}
	}
	// Gets the value of the text property.
	Ti::Value Blob::getText(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::Image) {
			return Ti::Value::Null();
		} else {
			return Ti::Value(std::string(data_.begin(), data_.end()));
		}
	}
	// Appends the data from another blob to this blob.
	Ti::Value Blob::append(const std::vector<Ti::Value>& arguments) {
		if (arguments.size() < 1) {
			std::clog << "[ERROR] Invalid argument for Ti.Blob.append()" << std::endl;
			return Ti::Value::Undefined();
		}
		const auto obj = arguments.at(0);
		if (!obj.isObject()) {
			std::clog << "[ERROR] Invalid argument for Ti.Blob.append()" << std::endl;
			return Ti::Value::Undefined();
		}
		const auto proxy = dynamic_cast<Ti::Blob::Blob*>(toProxy(obj).get());

		if (proxy != nullptr) {
			const auto b = proxy->getData();
			data_.reserve(data_.size() + b.size());
			data_.insert(data_.end(), b.begin(), b.end());
		}

		return Ti::Value::Undefined();
	}

	// Returns a string representation of this blob.
	Ti::Value Blob::toString(const std::vector<Ti::Value>& arguments) {
		if (type_ == TiBlobType::Image) {
			return Ti::Value("[object Blob]");
		}
		else {
			return this->getText(arguments);
		}
	}

} } // namespace Ti { namespace Blob {
