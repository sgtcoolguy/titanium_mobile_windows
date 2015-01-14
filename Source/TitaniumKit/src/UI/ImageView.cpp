/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/ImageView.hpp"

namespace Titanium
{
	namespace UI
	{
		ImageView::ImageView(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      image__(js_context.CreateString())
		{
		}

		ImageView::ImageView(const ImageView& rhs, const std::vector<JSValue>& arguments) TITANIUM_NOEXCEPT
		    : View(rhs, arguments),
		      image__(rhs.image__)
		{
		}

		std::string ImageView::get_image() const TITANIUM_NOEXCEPT
		{
			return image__;
		}

		void ImageView::set_image(const std::string& image) TITANIUM_NOEXCEPT
		{
			image__ = image;
		}

		// TODO: The following functions can automatically be generated from
		// the YAML API docs.

		void ImageView::JSExportInitialize()
		{
			JSExport<ImageView>::SetClassVersion(1);
			JSExport<ImageView>::SetParent(JSExport<View>::Class());
			JSExport<ImageView>::AddValueProperty("image", std::mem_fn(&ImageView::getImageArgumentValidator), std::mem_fn(&ImageView::setImageArgumentValidator));
		}

		JSValue ImageView::getImageArgumentValidator() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(image__);
		}

		bool ImageView::setImageArgumentValidator(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			std::string path = static_cast<std::string>(argument);
			TITANIUM_LOG_DEBUG("ImageView::setImageArgumentValidator: image = ", path);
			set_image(path);
			return true;
		}
	} // namespace UI
}  // namespace Titanium
