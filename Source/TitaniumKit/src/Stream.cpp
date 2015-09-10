/**
 * TitaniumKit Titanium.Stream
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/Stream.hpp"
#include "Titanium/IOStream.hpp"
#include "Titanium/Buffer.hpp"
#include "Titanium/Blob.hpp"
#include "Titanium/BufferStream.hpp"
#include "Titanium/BlobStream.hpp"

#define CREATE_TITANIUM_BUFFER(NAME) \
  const auto NAME##_ctor = get_context().JSEvaluateScript("Ti.Buffer"); \
  TITANIUM_ASSERT(NAME##_ctor.IsObject()); \
  const auto NAME = static_cast<JSObject>(NAME##_ctor).CallAsConstructor();

namespace Titanium
{
	CreateStreamArgs js_to_CreateStreamArgs(const JSObject& object)
	{
		CreateStreamArgs args;

		if (object.GetProperty("mode")) {
			const auto mode = object.GetProperty("mode");
			if (mode.IsNumber()) {
				args.mode = static_cast<STREAM_MODE>(static_cast<std::uint32_t>(mode));
			}
		}
		if (object.GetProperty("source")) {
			const auto source_property = object.GetProperty("source");
			if (source_property.IsObject()) {
				const auto source = static_cast<JSObject>(source_property);
				const auto blob_ptr  =  source.GetPrivate<Blob>();
				const auto buffer_ptr = source.GetPrivate<Buffer>();
				if (blob_ptr) {
					args.blob_source = blob_ptr;
					// Blob should be read-only
					if (args.mode != STREAM_MODE::READ) {
						HAL::detail::ThrowRuntimeError("Titanium::Stream::createStream", "Invalid argument for Stream.createStream, mode should be READ when source is Blob.");
					}
				} else if (buffer_ptr) {
					args.buffer_source = buffer_ptr;
				}
			}
		}

		return args;
	}

	JSObject CreateStreamArgs_to_js(const JSContext& js_context, const CreateStreamArgs& params)
	{
		auto object = js_context.CreateObject();
		object.SetProperty("mode", js_context.CreateNumber(static_cast<std::uint32_t>(params.mode)));
		if (params.blob_source) {
			object.SetProperty("source", params.blob_source->get_object());
		} else if (params.buffer_source) {
			object.SetProperty("source", params.buffer_source->get_object());
		}
		return object;
	}

	Stream::Stream(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Module(js_context)
		, MODE_APPEND__(js_context.CreateNumber(static_cast<std::uint32_t>(STREAM_MODE::APPEND)))
		, MODE_READ__(js_context.CreateNumber(static_cast<std::uint32_t>(STREAM_MODE::READ)))
		, MODE_WRITE__(js_context.CreateNumber(static_cast<std::uint32_t>(STREAM_MODE::WRITE)))
	{

	}

	/*
	 * Returns Titanium.BufferStream or Titanium.BlobStream depending on whether a Buffer or Blob is provided as the source property in params. 
	*/
	std::shared_ptr<IOStream> Stream::createStream(const CreateStreamArgs& params) TITANIUM_NOEXCEPT
	{
		if (params.blob_source) {
			const auto blobStream_property = get_context().JSEvaluateScript("Ti.BlobStream");
			TITANIUM_ASSERT(blobStream_property.IsObject());
			const auto blobStream = static_cast<JSObject>(blobStream_property);
			const auto blobStream_ptr = blobStream.GetPrivate<BlobStream>();
			blobStream_ptr->construct(params.blob_source);
			return std::dynamic_pointer_cast<IOStream>(blobStream_ptr);
		} else if (params.buffer_source) {
			const auto bufferStream_property = get_context().JSEvaluateScript("Ti.BufferStream");
			TITANIUM_ASSERT(bufferStream_property.IsObject());
			const auto bufferStream = static_cast<JSObject>(bufferStream_property);
			const auto bufferStream_ptr = bufferStream.GetPrivate<BufferStream>();
			bufferStream_ptr->construct(params.buffer_source);
			return std::dynamic_pointer_cast<IOStream>(bufferStream_ptr);
		}
		return nullptr;
	}

	void Stream::read(const std::shared_ptr<IOStream>& sourceStream, const std::shared_ptr<Buffer>& buffer, const std::uint32_t& offset, const std::uint32_t& length, JSObject resultsCallback) TITANIUM_NOEXCEPT
	{
		sourceStream->readAsync(buffer, offset, length, [this, resultsCallback](const std::int32_t& bytesRead) {
			JSObject e = get_context().CreateObject();
			e.SetProperty("bytesProcessed", get_context().CreateNumber(bytesRead));
			e.SetProperty("success", get_context().CreateBoolean(true));
			e.SetProperty("code", get_context().CreateNumber(0));

			const std::vector<JSValue> args { e };
			static_cast<JSObject>(resultsCallback)(args, get_object());
		});
	}

	std::shared_ptr<Buffer> Stream::readAll(const std::shared_ptr<IOStream>& sourceStream, const std::shared_ptr<Buffer>& write_buffer, JSObject resultsCallback) TITANIUM_NOEXCEPT
	{
		if (write_buffer != nullptr && resultsCallback.IsFunction()) {
			// TODO:
			// read operation takes place asynchronously, and results are passed to callback.
			//
			return nullptr;
		} else {
			CREATE_TITANIUM_BUFFER(write_buffer_obj);
			CREATE_TITANIUM_BUFFER(read_buffer_obj);
			const auto read_buffer = read_buffer_obj.GetPrivate<Buffer>();
			read_buffer->set_length(1024);
			const auto write_buffer = read_buffer_obj.GetPrivate<Buffer>();

			while (auto bytesRead = sourceStream->read(read_buffer, 0, read_buffer->get_length()) != -1) {
				write_buffer->append(read_buffer, 0, bytesRead);
				read_buffer->clear();
			}

			return write_buffer;
		}
	}

	void Stream::write(const std::shared_ptr<IOStream>& outputStream, const std::shared_ptr<Buffer>& buffer, const uint32_t& offset, const uint32_t& length, JSObject resultsCallback) TITANIUM_NOEXCEPT
	{
		outputStream->writeAsync(buffer, offset, length, [this, resultsCallback](const std::int32_t& bytesWritten) {
			JSObject e = get_context().CreateObject();
			e.SetProperty("bytesProcessed", get_context().CreateNumber(bytesWritten));
			e.SetProperty("success", get_context().CreateBoolean(true));
			e.SetProperty("code", get_context().CreateNumber(0));

			const std::vector<JSValue> args { e };
			static_cast<JSObject>(resultsCallback)(args, get_object());
		});
	}

	void Stream::writeStream(const std::shared_ptr<IOStream>& inputStream, const std::shared_ptr<IOStream>& outputStream, const uint32_t& maxChunkSize, JSObject resultsCallback) TITANIUM_NOEXCEPT
	{
		CREATE_TITANIUM_BUFFER(buffer);
		const auto buffer_ptr = buffer.GetPrivate<Buffer>();
		buffer_ptr->set_length(maxChunkSize);

		std::function<void(const std::int32_t&)> callback = [this, &callback, inputStream, outputStream, buffer_ptr, maxChunkSize, resultsCallback](const std::int32_t& bytesRead) {
			if (bytesRead < 0) {
				JSObject e = get_context().CreateObject();
				e.SetProperty("fromStream", inputStream->get_object());
				e.SetProperty("toStream",   outputStream->get_object());
				e.SetProperty("bytesProcessed", get_context().CreateNumber(totalBytesProcessed__));
				e.SetProperty("success", get_context().CreateBoolean(true));
				e.SetProperty("code", get_context().CreateNumber(0));

				const std::vector<JSValue> args { e };
				static_cast<JSObject>(resultsCallback)(args, get_object());
			} else {
				totalBytesProcessed__ += bytesRead;
				outputStream->write(buffer_ptr, 0, bytesRead);
				buffer_ptr->clear();
				inputStream->readAsync(buffer_ptr, 0, maxChunkSize, callback);
			}
		};

		inputStream->readAsync(buffer_ptr, 0, maxChunkSize, callback);
	}

	void Stream::pump(const std::shared_ptr<IOStream>& inputStream, JSObject handler, const uint32_t& maxChunkSize, const bool& isAsync) TITANIUM_NOEXCEPT
	{
		CREATE_TITANIUM_BUFFER(buffer);
		const auto buffer_ptr = buffer.GetPrivate<Buffer>();
		buffer_ptr->set_length(maxChunkSize);

		const auto callback = [this, buffer, handler, inputStream](const std::int32_t& bytesRead) {
			if (bytesRead > 0) {
				totalBytesProcessed__ += bytesRead;

				// callback
				JSObject e = get_context().CreateObject();
				e.SetProperty("buffer", buffer);
				e.SetProperty("source", inputStream->get_object());
				e.SetProperty("bytesProcessed", get_context().CreateNumber(bytesRead));
				e.SetProperty("totalBytesProcessed", get_context().CreateNumber(totalBytesProcessed__));
				e.SetProperty("success", get_context().CreateBoolean(true));
				e.SetProperty("code", get_context().CreateNumber(0));

				const std::vector<JSValue> args { e };
				static_cast<JSObject>(handler)(args, get_object());
			}
		};

		if (isAsync) {
			inputStream->readAsync(buffer_ptr, 0, maxChunkSize, callback);
		} else {
			callback(inputStream->read(buffer_ptr, 0, maxChunkSize));
		}
	}

	void Stream::JSExportInitialize() 
	{
		JSExport<Stream>::SetClassVersion(1);
		JSExport<Stream>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY_READONLY(Stream, MODE_APPEND);
		TITANIUM_ADD_PROPERTY_READONLY(Stream, MODE_READ);
		TITANIUM_ADD_PROPERTY_READONLY(Stream, MODE_WRITE);
		TITANIUM_ADD_FUNCTION(Stream, createStream);
		TITANIUM_ADD_FUNCTION(Stream, read);
		TITANIUM_ADD_FUNCTION(Stream, readAll);
		TITANIUM_ADD_FUNCTION(Stream, write);
		TITANIUM_ADD_FUNCTION(Stream, writeStream);
		TITANIUM_ADD_FUNCTION(Stream, pump);
	}

	TITANIUM_FUNCTION(Stream, read)
	{
		if (arguments.size() < 3) {
			HAL::detail::ThrowRuntimeError("Titanium::Stream::read", "Titanium::Stream::read: Invalid arguments");
		}
		ENSURE_OBJECT_AT_INDEX(sourceStream, 0);
		ENSURE_OBJECT_AT_INDEX(buffer, 1);

		//
		// read(sourceStream, buffer, [offset], [length], resultsCallback)
		//
		if (arguments.at(2).IsObject()) {
			ENSURE_OBJECT_AT_INDEX(resultsCallback, 3);
			const auto buffer_ptr = buffer.GetPrivate<Buffer>();
			read(sourceStream.GetPrivate<IOStream>(), buffer_ptr, 0, buffer_ptr->get_length(), resultsCallback);
		} else {
			ENSURE_UINT_AT_INDEX(offset, 2);
			ENSURE_UINT_AT_INDEX(length, 3);
			ENSURE_OBJECT_AT_INDEX(resultsCallback, 4);
			read(sourceStream.GetPrivate<IOStream>(), buffer.GetPrivate<Buffer>(), offset, length, resultsCallback);
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Stream, readAll)
	{
		ENSURE_OBJECT_AT_INDEX(sourceStream, 0);
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(buffer, 1);
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(resultsCallback, 2);
		const auto result = readAll(sourceStream.GetPrivate<IOStream>(), buffer.GetPrivate<Buffer>(), resultsCallback);
		if (result) {
			return result->get_object();
		}
		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Stream, write)
	{
		if (arguments.size() < 3) {
			HAL::detail::ThrowRuntimeError("Titanium::Stream::write", "Titanium::Stream::write: Invalid arguments");
		}

		ENSURE_OBJECT_AT_INDEX(outputStream, 0);
		ENSURE_OBJECT_AT_INDEX(buffer, 1);

		//
		// write(outputStream, buffer, [offset], [length], resultsCallback)
		//
		if (arguments.at(2).IsObject()) {
			ENSURE_OBJECT_AT_INDEX(resultsCallback, 2);
			const auto buffer_ptr = buffer.GetPrivate<Buffer>();
			write(outputStream.GetPrivate<IOStream>(), buffer_ptr, 0, buffer_ptr->get_length(), resultsCallback);
		} else {
			ENSURE_UINT_AT_INDEX(offset, 2);
			ENSURE_UINT_AT_INDEX(length, 3);
			ENSURE_OBJECT_AT_INDEX(resultsCallback, 4);
			write(outputStream.GetPrivate<IOStream>(), buffer.GetPrivate<Buffer>(), offset, length, resultsCallback);
		}

		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Stream, writeStream)
	{
		ENSURE_OBJECT_AT_INDEX(inputStream, 0);
		ENSURE_OBJECT_AT_INDEX(outputStream, 1);
		ENSURE_UINT_AT_INDEX(maxChunkSize, 2);
		ENSURE_OPTIONAL_OBJECT_AT_INDEX(resultsCallback, 3);

		const auto inputStream_ptr  = inputStream.GetPrivate<IOStream>();
		const auto outputStream_ptr = outputStream.GetPrivate<IOStream>();
		if (inputStream_ptr && outputStream_ptr) {
			writeStream(inputStream_ptr, outputStream_ptr, maxChunkSize, resultsCallback);
		} else {
			HAL::detail::ThrowRuntimeError("Titanium::Stream:writeStream", "Stream::writeStream: Invalid argument"); 
		}

		return get_context().CreateUndefined();
	}

	TITANIUM_FUNCTION(Stream, pump)
	{
		ENSURE_OBJECT_AT_INDEX(inputStream, 0);
		ENSURE_OBJECT_AT_INDEX(handler, 1);
		ENSURE_UINT_AT_INDEX(maxChunkSize, 2);
		ENSURE_OPTIONAL_BOOL_AT_INDEX(isAsync, 3, true);

		const auto inputStream_ptr = inputStream.GetPrivate<IOStream>();
		if (inputStream_ptr && handler.IsFunction()) {
			pump(inputStream_ptr, handler, maxChunkSize, isAsync);
		} else {
			HAL::detail::ThrowRuntimeError("Titanium::Stream:pump", "Stream::pump: Invalid argument"); 
		}

		return get_context().CreateUndefined();
	}

	TITANIUM_PROPERTY_GETTER(Stream, MODE_APPEND)
	{
		return MODE_APPEND__;
	}

	TITANIUM_PROPERTY_GETTER(Stream, MODE_READ)
	{
		return MODE_READ__;
	}

	TITANIUM_PROPERTY_GETTER(Stream, MODE_WRITE)
	{
		return MODE_WRITE__;
	}

	TITANIUM_FUNCTION(Stream, createStream)
	{
		ENSURE_OBJECT_AT_INDEX(params, 0);
		const auto stream = createStream(js_to_CreateStreamArgs(params));
		if (stream) {
			return stream->get_object();
		} else {
			return get_context().CreateNull();
		}
	}
} // namespace Titanium