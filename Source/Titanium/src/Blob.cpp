/**
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Blob.hpp"
#include "Titanium/detail/TiBase.hpp"
#include <iostream>
#include <objbase.h>
#include "File.hpp"

namespace TitaniumWindows
{
	Blob::Blob(const JSContext& js_context) TITANIUM_NOEXCEPT
	    : Titanium::Blob(js_context)
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::Blob::ctor");
	}

	Blob::~Blob()
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::Blob::dtor");
	}

	void Blob::JSExportInitialize()
	{
		JSExport<Blob>::SetClassVersion(1);
		JSExport<Blob>::SetParent(JSExport<Titanium::Blob>::Class());
	}

	void Blob::construct(Windows::Storage::StorageFile^ file)
	{
		TITANIUM_LOG_DEBUG("TitaniumWindows::Blob::construct");
		data_ = TitaniumWindows::Utility::GetContentFromFile(file);
		path_ = TitaniumWindows::Utility::ConvertString(file->Path);

		std::string path = path_;
		mimetype_ = TitaniumWindows::Utility::MimeTypeForExtension(path);

		this->type_ = Titanium::BlobModule::TYPE::FILE;
	}

	::Platform::Guid Blob::getImageEncoder()
	{
		if (mimetype_ == "image/png") {
			return Windows::Graphics::Imaging::BitmapEncoder::PngEncoderId;
		} else if (mimetype_ == "image/jpg") {
			return Windows::Graphics::Imaging::BitmapEncoder::JpegEncoderId;
		} else {
			return Windows::Graphics::Imaging::BitmapEncoder::BmpEncoderId;
		}
	}

	File_shared_ptr_t Blob::get_file() const TITANIUM_NOEXCEPT
	{
		if (path_.size() > 0) {
			auto File = get_context().CreateObject(JSExport<TitaniumWindows::Filesystem::File>::Class());
			return File.CallAsConstructor(path_).GetPrivate<TitaniumWindows::Filesystem::File>();
		} else {
			return nullptr;
		}
	}
}  // namespace TitaniumWindows
