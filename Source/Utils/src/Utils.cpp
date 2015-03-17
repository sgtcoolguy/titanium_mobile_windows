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

namespace TitaniumWindows
{

	Utils::Utils(const JSContext& js_context) TITANIUM_NOEXCEPT
		: Titanium::Utils(js_context)
	{
		TITANIUM_LOG_DEBUG("Utils::ctor Initialize");
	}

	void Utils::JSExportInitialize() {
		JSExport<Utils>::SetClassVersion(1);
		JSExport<Utils>::SetParent(JSExport<Titanium::Utils>::Class());
	}

	std::string Utils::generateHash(Platform::String^ hashName, std::vector<unsigned char> data) {
		Platform::ArrayReference<unsigned char> parray(data.data(), data.size());
		IBuffer^ buffer = CryptographicBuffer::CreateFromByteArray(parray);

		HashAlgorithmProvider^ hashProvider = HashAlgorithmProvider::OpenAlgorithm(hashName);
		auto hash = hashProvider->HashData(buffer);
		
		Platform::Array<unsigned char,1U>^ hashArray = ref new Platform::Array<unsigned char,1U>(hash->Length);
		CryptographicBuffer::CopyToByteArray(hash, &hashArray);

		std::string result = Utility::HexString(hashArray->Data, hashArray->Length);
		return result;
	}

	std::string Utils::md5HexDigest(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		return generateHash(HashAlgorithmNames::Md5, obj->getData());
	}

	std::string Utils::md5HexDigest(std::string& obj) TITANIUM_NOEXCEPT
	{
		std::vector<unsigned char> data(obj.begin(), obj.end());
		return generateHash(HashAlgorithmNames::Md5, data);
	}

	std::string Utils::sha1(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		return generateHash(HashAlgorithmNames::Sha1, obj->getData());
	}

	std::string Utils::sha1(std::string& obj) TITANIUM_NOEXCEPT
	{
		std::vector<unsigned char> data(obj.begin(), obj.end());
		return generateHash(HashAlgorithmNames::Sha1, data);
	}

	std::string Utils::sha256(Blob_shared_ptr_t obj) TITANIUM_NOEXCEPT
	{
		return generateHash(HashAlgorithmNames::Sha256, obj->getData());
	}

	std::string Utils::sha256(std::string& obj) TITANIUM_NOEXCEPT
	{
		std::vector<unsigned char> data(obj.begin(), obj.end());
		return generateHash(HashAlgorithmNames::Sha256, data);
	}
}  // namespace TitaniumWindows