/**
 * TitaniumKit Titanium.Buffer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_BUFFER_HPP_
#define _TITANIUM_BUFFER_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Codec/Constants.hpp"
#include <vector>

namespace Titanium
{
	using namespace HAL;

	class Blob;

	/*!
	  @class
	  @discussion This is the Titanium Buffer Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Buffer
	*/
	class TITANIUMKIT_EXPORT Buffer : public Module, public JSExport<Buffer>
	{

	public:

		/*!
		  @property
		  @abstract length
		  @discussion Length of the buffer in bytes.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::uint32_t, length);

		/*!
		  @property
		  @abstract type
		  @discussion The type of data encoding to use with `value`.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Titanium::Codec::Type, type);

		/*!
		@property
		@abstract charset
		@discussion The charset of data encoding to use with `value`.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Titanium::Codec::CharSet, charset);

		/*!
		  @property
		  @abstract byteOrder
		  @discussion Byte order of this buffer.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Titanium::Codec::ByteOrder, byteOrder);

		/*!
		@property
		@abstract value
		@discussion value of this buffer.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(JSValue, value);

		/*!
		@property
		@abstract data
		@discussion internal data representation of this buffer.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(std::vector<std::uint8_t>, data);

		/*!
		  @method
		  @abstract append
		  @discussion Appends `sourceBuffer` to the this buffer.
		*/
		virtual std::uint32_t append(const std::shared_ptr<Buffer>& sourceBuffer, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract insert
		  @discussion Inserts data from `sourceBuffer` into this buffer at `offset`.
		*/
		virtual std::uint32_t insert(const std::shared_ptr<Buffer>& sourceBuffer, const std::uint32_t& offset, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract copy
		  @discussion Copies data from `sourceBuffer` into the current buffer at `offset`.
		*/
		virtual std::uint32_t copy(const std::shared_ptr<Buffer>&  sourceBuffer, const std::uint32_t& offset, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract clone
		  @discussion Creates a complete or partial copy of this buffer.
		*/
		virtual std::shared_ptr<Buffer> clone(const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract fill
		  @discussion Fills this buffer with the specified byte value.
		*/
		virtual void fill(const std::uint8_t& fillByte, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract clear
		  @discussion Clears this buffer's contents but does not change the size of the buffer.
		*/
		virtual void clear() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract release
		  @discussion Releases the space allocated to the buffer, and sets its length to 0.
		*/
		virtual void release() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract toString
		  @discussion Converts this buffer to a String.
		*/
		virtual std::string toString() TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract toBlob
		  @discussion Converts this buffer to a <Titanium.Blob>.
		*/
		virtual std::shared_ptr<Blob> toBlob() TITANIUM_NOEXCEPT;

		virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

		// Called after all properties are set at Ti.createBuffer
		virtual void afterPropertiesSet() TITANIUM_NOEXCEPT override;

		// Construct internal data
		virtual void construct(const std::vector<std::uint8_t>& data) TITANIUM_NOEXCEPT;

		Buffer(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~Buffer()                      = default;
		Buffer(const Buffer&)            = default;
		Buffer& operator=(const Buffer&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		Buffer(Buffer&&)                 = default;
		Buffer& operator=(Buffer&&)      = default;
#endif

		static void JSExportInitialize();

		TITANIUM_PROPERTY_DEF(length);
		TITANIUM_PROPERTY_DEF(value);
		TITANIUM_PROPERTY_DEF(type);
		TITANIUM_PROPERTY_DEF(byteOrder);

		TITANIUM_FUNCTION_DEF(append);
		TITANIUM_FUNCTION_DEF(insert);
		TITANIUM_FUNCTION_DEF(copy);
		TITANIUM_FUNCTION_DEF(clone);
		TITANIUM_FUNCTION_DEF(fill);
		TITANIUM_FUNCTION_DEF(clear);
		TITANIUM_FUNCTION_DEF(release);
		TITANIUM_FUNCTION_DEF(toString);
		TITANIUM_FUNCTION_DEF(toBlob);
		TITANIUM_FUNCTION_DEF(getLength);
		TITANIUM_FUNCTION_DEF(setLength);
		TITANIUM_FUNCTION_DEF(getValue);
		TITANIUM_FUNCTION_DEF(setValue);
		TITANIUM_FUNCTION_DEF(getType);
		TITANIUM_FUNCTION_DEF(setType);
		TITANIUM_FUNCTION_DEF(getByteOrder);
		TITANIUM_FUNCTION_DEF(setByteOrder);

		bool js_hasProperty(const JSString& property_name) const;
		JSValue js_getProperty(const JSString& property_name) const;
		bool js_setProperty(const JSString& property_name, const JSValue& value);

	protected:
#pragma warning(push)
#pragma warning(disable : 4251)
		bool isDataIndexProperty(const std::string& property_name) const;

		JSValue value__;
		std::vector<std::uint8_t>  data__;
		Titanium::Codec::Type      type__;
		Titanium::Codec::ByteOrder byteOrder__;
		Titanium::Codec::CharSet   charset__;
#pragma warning(pop)
	};

} // namespace Titanium
#endif // _TITANIUM_BUFFER_HPP_