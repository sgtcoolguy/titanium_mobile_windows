/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_BLOB_TIBLOB_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_BLOB_TIBLOB_H_

//#ifndef DEBUG_TIBLOBPROXY
//#define DEBUG_TIBLOBPROXY
//#endif

#include "TiCore/TiRuntimeFunctions.h"
#include "TiCore/TiValue.h"
#include "TiCore/TiProxy.h"
#include "TiCore/TiUtils.h"

namespace Ti { namespace Blob {

	enum class TiBlobType {
		Image = 0,
		File  = 1,
		Data  = 2
	};

	class Blob : public Ti::Proxy, public virtual_enable_shared_from_this < Blob > {

	public:

		Ti::Value toValue();

		std::vector<unsigned char> getData();

		std::size_t size();

		::Platform::Guid getImageEncoder();

		// Construct image data
		// This is needed because constructor prevents from using weak_ptr to "this"
		void toImage(Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap^ image,
			const std::function<void(const std::shared_ptr<Ti::Blob::Blob>& blob)> callback);

	protected:

		Blob(const std::string& name, const std::vector<Ti::Value>& arguments);

		// Initialize the blob with a data
		Blob(std::vector<unsigned char> data, std::string mimetype);

		//  Initialize the blob with contents of a file.
		explicit Blob(Windows::Storage::StorageFile^ file);

		// Initialize the blob with given mimetype.
		// Blob content should be constructed by subsequent toImage() call.
		explicit Blob(std::string mimetype);

		virtual void postConstruct() override;

		TI_CREATE_PROXY(Blob);

		static JSClassRef Parent();

		// Gets the value of the file property.
		TI_CREATE_METHOD(Blob, getFile);
		Ti::Value Blob::getFile(const std::vector<Ti::Value>& arguments);

		// Gets the value of the height property.
		TI_CREATE_METHOD(Blob, getHeight);
		Ti::Value Blob::getHeight(const std::vector<Ti::Value>& arguments);

		// Gets the value of the width property.
		TI_CREATE_METHOD(Blob, getWidth);
		Ti::Value Blob::getWidth(const std::vector<Ti::Value>& arguments);

		// Gets the value of the length property.
		TI_CREATE_METHOD(Blob, getLength);
		Ti::Value Blob::getLength(const std::vector<Ti::Value>& arguments);

		// Gets the value of the mimeType property.
		TI_CREATE_METHOD(Blob, getMimeType);
		Ti::Value Blob::getMimeType(const std::vector<Ti::Value>& arguments);

		// Gets the value of the nativePath property.
		TI_CREATE_METHOD(Blob, getNativePath);
		Ti::Value Blob::getNativePath(const std::vector<Ti::Value>& arguments);

		// Gets the value of the size property.
		TI_CREATE_METHOD(Blob, getSize);
		Ti::Value Blob::getSize(const std::vector<Ti::Value>& arguments);

		// Gets the value of the text property.
		TI_CREATE_METHOD(Blob, getText);
		Ti::Value Blob::getText(const std::vector<Ti::Value>& arguments);

		// Appends the data from another blob to this blob.
		TI_CREATE_METHOD(Blob, append);
		Ti::Value Blob::append(const std::vector<Ti::Value>& arguments);

		// Returns a string representation of this blob.
		TI_CREATE_METHOD(Blob, toString);
		Ti::Value Blob::toString(const std::vector<Ti::Value>& arguments);
	private:
		std::string path_;
		std::string mimetype_;
		int width_;
		int height_;
		TiBlobType type_;
		std::vector<unsigned char> data_;
	};
} } // namespace Ti { namespace Blob {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_BLOB_TIBLOB_H_
