/**
 * Titanium.Utils for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "TitaniumWindows/Utils.hpp"
#include "Titanium/detail/TiBase.hpp"

#include "TitaniumWindows/Utility.hpp"

using namespace Windows::Security::Cryptography;
using namespace Windows::Security::Cryptography::Core;
using namespace Windows::Storage::Streams;

namespace TitaniumWindows
{

	UtilsModule::UtilsModule(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::UtilsModule(js_context)
	{
		TITANIUM_LOG_DEBUG("Utils::ctor Initialize");
	}

	void UtilsModule::JSExportInitialize() {
		JSExport<UtilsModule>::SetClassVersion(1);
		JSExport<UtilsModule>::SetParent(JSExport<Titanium::UtilsModule>::Class());
	}

	std::string UtilsModule::md5HexDigest(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		auto data = obj->getData();
		Platform::ArrayReference<unsigned char> parray(data.data(), data.size());
		IBuffer^ buffer = CryptographicBuffer::CreateFromByteArray(parray);

		HashAlgorithmProvider^ hashProvider = HashAlgorithmProvider::OpenAlgorithm(HashAlgorithmNames::Md5);
		auto hash = hashProvider->HashData(buffer);
		
		Platform::Array<unsigned char,1U>^ hashArray = ref new Platform::Array<unsigned char,1U>(hash->Length);
		CryptographicBuffer::CopyToByteArray(hash, &hashArray);

		std::string result = Utility::HexString(hashArray->Data, hashArray->Length);
		return result;
	}

	std::string UtilsModule::sha1(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		auto data = obj->getData();
		Platform::ArrayReference<unsigned char> parray(data.data(), data.size());
		IBuffer^ buffer = CryptographicBuffer::CreateFromByteArray(parray);

		HashAlgorithmProvider^ hashProvider = HashAlgorithmProvider::OpenAlgorithm(HashAlgorithmNames::Sha1);
		auto hash = hashProvider->HashData(buffer);
		
		Platform::Array<unsigned char,1U>^ hashArray = ref new Platform::Array<unsigned char,1U>(hash->Length);
		CryptographicBuffer::CopyToByteArray(hash, &hashArray);

		std::string result = Utility::HexString(hashArray->Data, hashArray->Length);
		return result;
	}

	std::string UtilsModule::sha256(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		auto data = obj->getData();
		Platform::ArrayReference<unsigned char> parray(data.data(), data.size());
		IBuffer^ buffer = CryptographicBuffer::CreateFromByteArray(parray);

		HashAlgorithmProvider^ hashProvider = HashAlgorithmProvider::OpenAlgorithm(HashAlgorithmNames::Sha256);
		auto hash = hashProvider->HashData(buffer);
		
		Platform::Array<unsigned char,1U>^ hashArray = ref new Platform::Array<unsigned char,1U>(hash->Length);
		CryptographicBuffer::CopyToByteArray(hash, &hashArray);

		std::string result = Utility::HexString(hashArray->Data, hashArray->Length);
		return result;
	}
}  // namespace TitaniumWindows