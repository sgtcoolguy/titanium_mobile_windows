/**
 * Copyright (c) 2014-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_BLOB_HPP_
#define _TITANIUMWINDOWS_BLOB_HPP_

#include "TitaniumWindows_EXPORT.h"
#include "Titanium/Blob.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	/*!
	  @class Blob
	  @ingroup Titanium.Blob

	  @discussion This is the Titanium.Blob implementation for Windows.
    */
	class TITANIUMWINDOWS_EXPORT Blob final : public Titanium::Blob, public JSExport<Blob>
	{
	public:
		::Platform::Guid getImageEncoder();

		virtual void construct(const std::vector<std::uint8_t>& data, const std::string& mimetype) TITANIUM_NOEXCEPT;
		virtual void construct(Windows::Storage::StorageFile^ file) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract imageAsCropped
		  @discussion Creates a new blob by cropping the underlying image to the specified dimensions.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageAsCropped(const Titanium::UI::Dimension&) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract imageAsResized
		  @discussion Creates a new blob by resizing and scaling the underlying image to the specified dimensions.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageAsResized(const std::uint32_t&, const std::uint32_t&) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract imageAsThumbnail
		  @discussion Returns a thumbnail version of the underlying image, optionally with a border and rounded corners.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageAsThumbnail(const std::uint32_t&, const std::uint32_t&, const double&) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract imageWithAlpha
		  @discussion Returns a copy of the underlying image with an added alpha channel.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageWithAlpha() TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract imageWithRoundedCorner
		  @discussion Returns a copy of the underlying image with rounded corners added.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageWithRoundedCorner(const std::uint32_t&, const std::uint32_t&) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract imageWithTransparentBorder
		  @discussion Returns a copy of the underlying image with an added transparent border.
		*/
		virtual std::shared_ptr<Titanium::Blob> imageWithTransparentBorder(const std::uint32_t&) TITANIUM_NOEXCEPT override;

		/*!
		  @method
		  @abstract transformImage
		  @param width Width to resize
		  @param height Height to resize
		  @param crop options (width, height, x, y)
		  @discussion Creates a new blob by resizing/scaling/cropping the underlying image to the specified dimensions.
		*/
		std::shared_ptr<Titanium::Blob> transformImage(const std::uint32_t& scaledWidth, const std::uint32_t scaledHeight, const Titanium::UI::Dimension& crop) TITANIUM_NOEXCEPT;

		Blob(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~Blob();
		Blob(const Blob&) = default;
		Blob& operator=(const Blob&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Blob(Blob&&) = default;
		Blob& operator=(Blob&&) = default;
#endif

		static void JSExportInitialize();
	};

}  // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_BLOB_HPP_
