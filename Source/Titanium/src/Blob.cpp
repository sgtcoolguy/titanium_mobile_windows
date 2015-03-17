/**
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
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
		data_ = TitaniumWindows::Utility::GetContentFromFile(file);
		path_ = TitaniumWindows::Utility::ConvertString(file->Path);

		std::string path = path_;
		mimetype_ = TitaniumWindows::Utility::MimeTypeForExtension(path);
		// TODO Determine width and height!

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
}  // namespace TitaniumWindows
