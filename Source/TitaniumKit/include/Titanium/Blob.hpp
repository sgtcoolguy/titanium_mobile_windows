/**
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_BLOB_HPP_
#define _TITANIUM_BLOB_HPP_

#include "Titanium/Module.hpp"

namespace Titanium
{
	using namespace HAL;

	namespace Filesystem
	{
		class File;
	}

	using File_shared_ptr_t = std::shared_ptr<Filesystem::File>;

	namespace BlobModule
	{
		enum class TYPE {
			IMAGE = 0,
			FILE = 1,
			DATA = 2
		};
	}

	/*!
	  @class
	  @discussion This is the Titanium.Blob module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Blob
	*/
	class TITANIUMKIT_EXPORT Blob : public Module, public JSExport<Blob>
	{
	public:
		/*!
		  @method
		  @abstract get_length
		  @discussion Length of this blob in bytes.
		*/
		virtual uint32_t get_length() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_file
		  @discussion File object represented by this blob, or null if this blob is not
		  associated with a file.
		*/
		virtual File_shared_ptr_t get_file() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_height
		  @discussion If this blob represents an image, this is the height of the image in pixels.
		*/
		virtual uint32_t get_height() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_mimeType
		  @discussion Mime type of the data in this blob.
		*/
		virtual std::string get_mimeType() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_nativePath
		  @discussion If this blob represents a File, this is the file URL that represents it.
		*/
		virtual std::string get_nativePath() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_size
		  @discussion Size of the blob in pixels (for image blobs) or bytes (for all other blobs).
		*/
		virtual uint32_t get_size() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_text
		  @discussion UTF-8 string representation of the data in this blob.
		*/
		virtual std::string get_text() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract get_width
		  @discussion If this blob represents an image, this is the width of the image in pixels.
		*/
		virtual uint32_t get_width() const TITANIUM_NOEXCEPT;
		/*!
		  @method
		  @abstract append
		  @discussion Appends the data from another blob to this blob.
		*/
		virtual void append(const std::shared_ptr<Blob>&) TITANIUM_NOEXCEPT;

		virtual void construct(const std::vector<std::uint8_t>& data) TITANIUM_NOEXCEPT;
		virtual std::vector<std::uint8_t> getData() TITANIUM_NOEXCEPT;

		virtual void release() TITANIUM_NOEXCEPT;

		Blob(const JSContext&) TITANIUM_NOEXCEPT;

		virtual ~Blob() = default;
		Blob(const Blob&) = default;
		Blob& operator=(const Blob&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Blob(Blob&&) = default;
		Blob& operator=(Blob&&) = default;
#endif

		static void JSExportInitialize();

		TITANIUM_PROPERTY_READONLY_DEF(length);
		TITANIUM_PROPERTY_READONLY_DEF(file);
		TITANIUM_PROPERTY_READONLY_DEF(height);
		TITANIUM_PROPERTY_READONLY_DEF(mimeType);
		TITANIUM_PROPERTY_READONLY_DEF(nativePath);
		TITANIUM_PROPERTY_READONLY_DEF(size);
		TITANIUM_PROPERTY_READONLY_DEF(text);
		TITANIUM_PROPERTY_READONLY_DEF(width);

		TITANIUM_FUNCTION_DEF(append);
		TITANIUM_FUNCTION_DEF(getFile);
		TITANIUM_FUNCTION_DEF(getHeight);
		TITANIUM_FUNCTION_DEF(getLength);
		TITANIUM_FUNCTION_DEF(getMimeType);
		TITANIUM_FUNCTION_DEF(getNativePath);
		TITANIUM_FUNCTION_DEF(getSize);
		TITANIUM_FUNCTION_DEF(getText);
		TITANIUM_FUNCTION_DEF(getWidth);
		TITANIUM_FUNCTION_DEF(toString);

	protected:
#pragma warning(push)
#pragma warning(disable : 4251)
		std::string path_;
		std::string mimetype_;
		uint32_t width_;
		uint32_t height_;
		BlobModule::TYPE type_;
		std::vector<std::uint8_t> data_;
#pragma warning(pop)
	};
}  // namespace Titanium

#endif  // _TITANIUM_BLOB_HPP_
