/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */


#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_PROXYCACHEMANAGER_HPP_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_PROXYCACHEMANAGER_HPP_

#include <memory>
#include <unordered_map>
#include <cstdint>
#include <mutex>

class BaseProxy;
using ProxyCacheManager_key_type_t = std::intptr_t;
using BaseProxy_shared_ptr_t = std::shared_ptr<BaseProxy>;
using ProxyMap_t = std::unordered_map<ProxyCacheManager_key_type_t, BaseProxy_shared_ptr_t>;

class ProxyCacheManager;
using ProxyCacheManager_shared_ptr_t = std::shared_ptr<ProxyCacheManager>;
using ProxyCacheManager_weak_ptr_t	 = std::weak_ptr<ProxyCacheManager>;

class ProxyCacheManager final : public std::enable_shared_from_this<ProxyCacheManager> {

 public:

	// Create an instance of the proxy cache manager.
	static ProxyCacheManager_shared_ptr_t Instance();
	
	ProxyCacheManager_key_type_t add(const BaseProxy_shared_ptr_t& base_proxy_shared_ptr);
	
	BaseProxy_shared_ptr_t remove(ProxyCacheManager_key_type_t key);

	BaseProxy_shared_ptr_t find(ProxyCacheManager_key_type_t key) const;

	void sweep() const;
	
	void scan() const;
	
private:

	// Private to enforce singleton pattern.
	ProxyCacheManager() {
	};

	// Private to enforce singleton pattern.
	~ProxyCacheManager() {
	};

	ProxyCacheManager(const ProxyCacheManager& rhs) = delete;
	ProxyCacheManager& operator=( const ProxyCacheManager& rhs ) = delete;

	// This struct only exists so that a custom deleter can be passed to
	// std::shared_ptr<ProxyCacheManager> while keeping the
	// ProxyCacheManager destructor private.
	struct deleter {
		void operator()(ProxyCacheManager* ptr) {
			delete ptr;
		}
	};

	ProxyMap_t proxy_map_;
	std::mutex proxy_map_mutex_;
};

#endif // _TITANIUM_MOBILE_WINDOWS_TICORE_PROXYCACHEMANAGER_HPP_
