/**
 * TitaniumKit Titanium.Buffer
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Buffer.hpp"
#include "Titanium/Blob.hpp"
#include "Titanium/Codec.hpp"
#include "Titanium/TiModule.hpp"
#include <algorithm>

#define GET_TITANIUM_MODULE(NAME,VARNAME) \
  const auto Titanium_property = get_context().get_global_object().GetProperty("Titanium"); \
  TITANIUM_ASSERT(Titanium_property.IsObject()); \
  const auto Titanium = static_cast<JSObject>(Titanium_property); \
  const auto NAME##_poperty = Titanium.GetProperty(#NAME); \
  TITANIUM_ASSERT(NAME##_poperty.IsObject()); \
  auto VARNAME = static_cast<JSObject>(NAME##_poperty);

namespace Titanium
{

	Buffer::Buffer(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
		, type__(Titanium::Codec::Type::Int)
		, charset__(Titanium::Codec::CharSet::UTF8)
		, value__(js_context.CreateNull())
		, byteOrder__(Titanium::Codec::ByteOrder::Unknown)
	{
		TITANIUM_LOG_DEBUG("Titanium::Buffer ctor ", this);
	}

	TITANIUM_PROPERTY_READWRITE(Buffer, Titanium::Codec::Type, type)
	TITANIUM_PROPERTY_READWRITE(Buffer, Titanium::Codec::ByteOrder, byteOrder)
	TITANIUM_PROPERTY_READWRITE(Buffer, Titanium::Codec::CharSet, charset)
	TITANIUM_PROPERTY_READWRITE(Buffer, JSValue, value)
	TITANIUM_PROPERTY_READWRITE(Buffer, std::vector<std::uint8_t>, data)

	void Buffer::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) 
	{
		Titanium::Module::postCallAsConstructor(js_context, arguments);

		if (byteOrder__ == Titanium::Codec::ByteOrder::Unknown) {
			GET_TITANIUM_MODULE(Codec, CodecObj);
			const auto codec_ptr = CodecObj.GetPrivate<Titanium::Codec::CodecModule>();
			TITANIUM_ASSERT(codec_ptr);
			byteOrder__ = codec_ptr->getNativeByteOrder();
		}
	}

	std::uint32_t Buffer::get_length() const TITANIUM_NOEXCEPT
	{
		return static_cast<std::uint32_t>(data__.size());
	}

	void Buffer::set_length(const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		data__.resize(length, 0);
	}

	std::uint32_t Buffer::append(const std::shared_ptr<Buffer>& sourceBuffer, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT
	{
		const auto source = sourceBuffer->get_data();
		data__.reserve(data__.size() + sourceLength);
		data__.insert(data__.end(), source.begin() + sourceOffset, source.begin() + sourceOffset + sourceLength);
		return sourceLength;
	}

	std::uint32_t Buffer::insert(const std::shared_ptr<Buffer>& sourceBuffer, const std::uint32_t& offset, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT
	{
		const auto source = sourceBuffer->get_data();
		data__.reserve(data__.size() + sourceLength);
		data__.insert(data__.begin() + offset, source.begin() + sourceOffset, source.begin() + sourceOffset + sourceLength);
		return sourceLength;
	}

	std::uint32_t Buffer::copy(const std::shared_ptr<Buffer>& sourceBuffer, const std::uint32_t& offset, const std::uint32_t& sourceOffset, const std::uint32_t& sourceLength) TITANIUM_NOEXCEPT
	{
		const auto source = sourceBuffer->get_data();
		const auto actualLength = offset + sourceLength > data__.size() ? data__.size() - offset : sourceLength;
		std::copy(source.begin() + sourceOffset, source.begin() + sourceOffset + actualLength, data__.begin() + offset);
		return 0;
	}

	std::shared_ptr<Buffer> Buffer::clone(const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		const auto Titanium_property = get_context().get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());
		auto Titanium = static_cast<JSObject>(Titanium_property);
		const auto tiModule = Titanium.GetPrivate<Titanium::TiModule>();
		TITANIUM_ASSERT(tiModule);
		const auto js_buffer = tiModule->js_createBuffer({}, Titanium);
		TITANIUM_ASSERT(js_buffer.IsObject());
		const auto buffer = static_cast<JSObject>(js_buffer).GetPrivate<Buffer>();
		TITANIUM_ASSERT(buffer);
		buffer->append(get_object().GetPrivate<Buffer>(), offset, length);
		return buffer;
	}

	void Buffer::fill(const std::uint8_t& fillByte, const std::uint32_t& offset, const std::uint32_t& length) TITANIUM_NOEXCEPT
	{
		std::fill(data__.begin() + offset, data__.begin() + length, fillByte);
	}

	void Buffer::clear() TITANIUM_NOEXCEPT
	{
		data__.clear();
	}

	void Buffer::release() TITANIUM_NOEXCEPT
	{
		clear();
	}

	std::string Buffer::toString() TITANIUM_NOEXCEPT
	{
		//
		// Just call Ti.Codec.encodeString(buffer);
		//
		GET_TITANIUM_MODULE(Codec, CodecObj);
		const auto codec_ptr = CodecObj.GetPrivate<Titanium::Codec::CodecModule>();
		TITANIUM_ASSERT(codec_ptr);

		Titanium::Codec::DecodeStringDict param;
		param.charset = charset__;
		param.length = static_cast<std::uint32_t>(data__.size());
		param.position = 0;
		param.source = get_object().GetPrivate<Buffer>();

		return codec_ptr->decodeString(param);
	}

	std::shared_ptr<Blob> Buffer::toBlob() TITANIUM_NOEXCEPT
	{
		GET_TITANIUM_MODULE(Blob, BlobObj);
		const auto blob = BlobObj.CallAsConstructor();
		const auto blob_ptr = blob.GetPrivate<Titanium::Blob>();
		TITANIUM_ASSERT(blob_ptr);
		blob_ptr->construct(data__);
		return blob_ptr;
	}

	void Buffer::JSExportInitialize() 
	{
		JSExport<Buffer>::SetClassVersion(1);
		JSExport<Buffer>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY(Buffer, length);
		TITANIUM_ADD_PROPERTY(Buffer, value);
		TITANIUM_ADD_PROPERTY(Buffer, type);
		TITANIUM_ADD_PROPERTY(Buffer, byteOrder);

		TITANIUM_ADD_FUNCTION(Buffer, append);
		TITANIUM_ADD_FUNCTION(Buffer, insert);
		TITANIUM_ADD_FUNCTION(Buffer, copy);
		TITANIUM_ADD_FUNCTION(Buffer, clone);
		TITANIUM_ADD_FUNCTION(Buffer, fill);
		TITANIUM_ADD_FUNCTION(Buffer, clear);
		TITANIUM_ADD_FUNCTION(Buffer, release);
		TITANIUM_ADD_FUNCTION(Buffer, toString);
		TITANIUM_ADD_FUNCTION(Buffer, toBlob);
		TITANIUM_ADD_FUNCTION(Buffer, getLength);
		TITANIUM_ADD_FUNCTION(Buffer, setLength);
		TITANIUM_ADD_FUNCTION(Buffer, getValue);
		TITANIUM_ADD_FUNCTION(Buffer, setValue);
		TITANIUM_ADD_FUNCTION(Buffer, getType);
		TITANIUM_ADD_FUNCTION(Buffer, setType);
		TITANIUM_ADD_FUNCTION(Buffer, getByteOrder);
		TITANIUM_ADD_FUNCTION(Buffer, setByteOrder);
	}

	TITANIUM_PROPERTY_GETTER_UINT(Buffer, length);
	TITANIUM_PROPERTY_SETTER_UINT(Buffer, length)

	TITANIUM_PROPERTY_GETTER(Buffer, value)
	{
		return get_value();
	}

	TITANIUM_PROPERTY_SETTER(Buffer, value)
	{
		set_value(argument);
		return true;
	}

	TITANIUM_PROPERTY_GETTER(Buffer, type)
	{
		return get_context().CreateString(Titanium::Codec::Constants::to_string(get_type()));
	}

	TITANIUM_PROPERTY_SETTER(Buffer, type)
	{
		set_type(Titanium::Codec::Constants::to_Type(static_cast<std::string>(argument)));
		return true;
	}

	TITANIUM_PROPERTY_GETTER(Buffer, byteOrder)
	{
		return get_context().CreateNumber(static_cast<std::uint32_t>(get_byteOrder()));
	}

	TITANIUM_PROPERTY_SETTER(Buffer, byteOrder)
	{
		TITANIUM_ASSERT(argument.IsNumber());
		set_byteOrder(Titanium::Codec::Constants::to_ByteOrder(static_cast<std::uint32_t>(argument)));
		return true;
	}

	TITANIUM_FUNCTION(Buffer, append)
	{
		ENSURE_OBJECT_AT_INDEX(sourceBuffer, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceOffset, 1, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceLength, 2, 0);

		const auto buffer = sourceBuffer.GetPrivate<Buffer>();
		if (buffer) {
			sourceLength = static_cast<std::uint32_t>(buffer->get_data().size());
		} else {
			TITANIUM_LOG_WARN("Buffer::append: Unable to get Buffer");
			return get_context().CreateUndefined();
		}

		return get_context().CreateNumber(append(buffer, sourceOffset, sourceLength));
	}

	TITANIUM_FUNCTION(Buffer, insert)
	{
		ENSURE_OBJECT_AT_INDEX(sourceBuffer, 0);
		ENSURE_UINT_AT_INDEX(offset, 1);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceOffset, 2, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceLength, 3, 0);

		const auto buffer = sourceBuffer.GetPrivate<Buffer>();
		if (buffer) {
			sourceLength = static_cast<std::uint32_t>(buffer->get_data().size());
		} else {
			TITANIUM_LOG_WARN("Buffer::insert: Unable to get Buffer");
			return get_context().CreateUndefined();
		}

		return get_context().CreateNumber(insert(buffer, offset, sourceOffset, sourceLength));
	}

	TITANIUM_FUNCTION(Buffer, copy)
	{
		ENSURE_OBJECT_AT_INDEX(sourceBuffer, 0);
		ENSURE_UINT_AT_INDEX(offset, 1);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceOffset, 2, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(sourceLength, 3, 0);

		const auto buffer = sourceBuffer.GetPrivate<Buffer>();
		if (buffer) {
			sourceLength = static_cast<std::uint32_t>(buffer->get_data().size());
		} else {
			TITANIUM_LOG_WARN("Buffer::copy: Unable to get Buffer");
			return get_context().CreateUndefined();
		}

		return get_context().CreateNumber(copy(buffer, offset, sourceOffset, sourceLength));
	}

	TITANIUM_FUNCTION(Buffer, clone)
	{
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 0, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 1, 0);
		const auto buffer = clone(offset, length);
		
		if (buffer) {
			return buffer->get_object();
		} else {
			return get_context().CreateNull();
		}
	}

	TITANIUM_FUNCTION(Buffer, fill)
	{
		ENSURE_UINT_AT_INDEX(fillByte, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(offset, 1, 0);
		ENSURE_OPTIONAL_UINT_AT_INDEX(length, 2, 0);
		fill(fillByte, offset, length);
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Buffer, clear)
	{
		clear();
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Buffer, release)
	{
		release();
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Buffer, toString)
	{
		return get_context().CreateString(toString());
	}

	TITANIUM_FUNCTION(Buffer, toBlob)
	{
		const auto blob = toBlob();
		if (blob) {
			return blob->get_object();
		} else {
			return get_context().CreateNull();
		}
	}

	TITANIUM_FUNCTION_AS_GETTER(Buffer, getLength, length)
	TITANIUM_FUNCTION_AS_SETTER(Buffer, setLength, length)
	TITANIUM_FUNCTION_AS_GETTER(Buffer, getValue, value)
	TITANIUM_FUNCTION_AS_SETTER(Buffer, setValue, value)
	TITANIUM_FUNCTION_AS_GETTER(Buffer, getType, type)
	TITANIUM_FUNCTION_AS_SETTER(Buffer, setType, type)
	TITANIUM_FUNCTION_AS_GETTER(Buffer, getByteOrder, byteOrder)
	TITANIUM_FUNCTION_AS_SETTER(Buffer, setByteOrder, byteOrder)

} // namespace Titanium