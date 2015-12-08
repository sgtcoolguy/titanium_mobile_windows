/**
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Blob.hpp"
#include "TitaniumWindows/Utility.hpp"
#include "TitaniumWindows/GlobalObject.hpp"
#include <ppltasks.h>
#include <concrt.h>
#include <collection.h>
#include <boost/algorithm/string/predicate.hpp>

using Windows::Security::Cryptography::CryptographicBuffer;
using Windows::Security::Cryptography::BinaryStringEncoding;
using Windows::Storage::Streams::IRandomAccessStreamWithContentType;
using Windows::Foundation::IAsyncOperation;
using Windows::Graphics::Imaging::BitmapDecoder;
using concurrency::task_continuation_context;

namespace TitaniumWindows
{
	Blob::Blob(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::Blob(js_context)
	{
	}

	Blob::~Blob()
	{
	}

	void Blob::JSExportInitialize()
	{
		JSExport<Blob>::SetClassVersion(1);
		JSExport<Blob>::SetParent(JSExport<Titanium::Blob>::Class());
	}

	void Blob::construct(Windows::Storage::StorageFile^ file)
	{
		width_ = 0;
		height_ = 0;

		path_ = TitaniumWindows::Utility::ConvertString(file->Path);
		if (boost::ends_with(path_, ".js") || boost::ends_with(path_, ".json")){
			// TODO: We should refactor to get the IBuffer back directly, rather than converting the contents multiple times.

			auto js_global = get_context().get_global_object();
			auto global = js_global.GetPrivate<TitaniumWindows::GlobalObject>();
			TITANIUM_ASSERT(global != nullptr);
			std::string contents = global->readRequiredModule(get_object(), path_);
			auto buffer = CryptographicBuffer::ConvertStringToBinary(TitaniumWindows::Utility::ConvertString(contents), BinaryStringEncoding::Utf8);
			data_ = TitaniumWindows::Utility::GetContentFromBuffer(buffer);
		}
		else {
			data_ = TitaniumWindows::Utility::GetContentFromFile(file);
		}

		mimetype_ = TitaniumWindows::Utility::ConvertString(file->ContentType);
		if (mimetype_ == "application/x-javascript" || mimetype_ == "application/javascript") { // handle special cases to match other platforms
			mimetype_ = "text/javascript";
		}
		if (boost::starts_with(mimetype_, "image/")) {
			concurrency::event event;
			concurrency::task<IRandomAccessStreamWithContentType^>(file->OpenReadAsync())
				.then([](IRandomAccessStreamWithContentType^ stream) {
					return Windows::Graphics::Imaging::BitmapDecoder::CreateAsync(stream);
				}, task_continuation_context::use_arbitrary())
				.then([=, &event](concurrency::task<BitmapDecoder^> task) {
					try {
						auto decoder = task.get();
						width_ = static_cast<uint32_t>(decoder->PixelWidth);
						height_ = static_cast<uint32_t>(decoder->PixelHeight);
					} catch (...) {
						TITANIUM_LOG_ERROR("Blob: Could not decode image file");
					}
					event.set();
				}, task_continuation_context::use_arbitrary()
			);
			event.wait();
		}

		this->type_ = Titanium::BlobModule::TYPE::FILE;
	}

	::Platform::Guid Blob::getImageEncoder()
	{
		if (mimetype_ == "image/png") {
			return Windows::Graphics::Imaging::BitmapEncoder::PngEncoderId;
		} else if (mimetype_ == "image/jpg" || mimetype_ == "image/jpeg" || mimetype_ == "image/pjpeg") {
			return Windows::Graphics::Imaging::BitmapEncoder::JpegEncoderId;
		} else if (mimetype_ == "image/tiff") {
			return Windows::Graphics::Imaging::BitmapEncoder::TiffEncoderId;
		} else if (mimetype_ == "image/gif") {
			return Windows::Graphics::Imaging::BitmapEncoder::GifEncoderId;
		} else { // image/bmp?
			return Windows::Graphics::Imaging::BitmapEncoder::BmpEncoderId;
		}
	}
}  // namespace TitaniumWindows
