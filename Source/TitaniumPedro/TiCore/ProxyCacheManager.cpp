/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

// #ifndef DEBUG_PROXYCACHEMANAGER
// #define DEBUG_PROXYCACHEMANAGER
// #endif

#include "TiCore/ProxyCacheManager.hpp"
#include <iostream>
#include <utility>
#include "TiCore/BaseProxy.h"

ProxyCacheManager_shared_ptr_t ProxyCacheManager::Instance() {
	static ProxyCacheManager_shared_ptr_t instance;
	static std::once_flag of;
	std::call_once(of, [] {
			instance = ProxyCacheManager_shared_ptr_t(new ProxyCacheManager(), deleter{});
		});
	
	return instance;
}

ProxyCacheManager_key_type_t ProxyCacheManager::add(const BaseProxy_shared_ptr_t& base_proxy_shared_ptr) {
	static const std::string log_prefix { "MDL: ProxyCacheManager::add:" };
	const auto proxy_identifier = base_proxy_shared_ptr -> get_proxy_identifier();
	// std::clog << log_prefix << " [DEBUG] " << proxy_identifier << std::endl;
	
	const auto key = reinterpret_cast<ProxyMap_t::key_type>(base_proxy_shared_ptr.get());

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix << " [DEBUG] " << proxy_identifier << ": look for key " << key << " in cache." << std::endl;
#endif

	assert(proxy_map_.count(key) == 0);

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix
	          << " [DEBUG] "
	          << proxy_identifier
	          << ": BEFORE: "
	          <<  proxy_map_.count(key)
	          << " cache entries for key "
	          << key
	          << " (use_count = "
	          << base_proxy_shared_ptr.use_count()
	          << ")."
	          << std::endl;
#endif

	{ // Open critical section.
		std::lock_guard<std::mutex> proxy_map_lock(proxy_map_mutex_);
		auto insert_result = proxy_map_.insert(std::make_pair(key, base_proxy_shared_ptr));
		// std::clog << log_prefix << " [DEBUG] " << proxy_identifier << ": AFTER: insert_result == " << std::boolalpha << insert_result.second << "." << std::endl;
	} //Close critical section.

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix
	          << " [DEBUG] "
	          << proxy_identifier
	          << ": AFTER: "
	          <<  proxy_map_.count(key)
	          << " cache entries for key "
	          << key
	          << " (use_count = "
	          << base_proxy_shared_ptr.use_count()
	          << ")."
	          << std::endl;

	const auto position = proxy_map_.find(key);
	std::clog << log_prefix << " [DEBUG] " << proxy_identifier << ": position != proxy_map_.end() = " << std::boolalpha << (position != proxy_map_.end()) << "." << std::endl;
#endif
	
	return key;
}

BaseProxy_shared_ptr_t ProxyCacheManager::remove(ProxyCacheManager_key_type_t key) {
	static const std::string log_prefix { "MDL: ProxyCacheManager::remove:" };
	// std::clog << log_prefix << " [DEBUG] look for key " << key << " in proxy cache." << std::endl;
	const auto position = proxy_map_.find(key);

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix << " [DEBUG] position != proxy_map_.end() = " << std::boolalpha << (position != proxy_map_.end()) << "." << std::endl;
#endif

	assert(position != proxy_map_.end());
	const auto proxy_ptr = position -> second;
	const auto proxy_identifier = proxy_ptr -> get_proxy_identifier();

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix
	          << " [DEBUG] remove proxy "
	          << proxy_identifier
	          << " from cache (use_count = "
	          << proxy_ptr.use_count()
	          << ")."
	          << std::endl;
#endif

	const auto number_of_elements_removed = proxy_map_.erase(key);

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix
	          << " [DEBUG] "
	          << number_of_elements_removed
	          << " elements removed "
	          << proxy_identifier
	          << " (use_count = "
	          << proxy_ptr.use_count()
	          << ")."
	          << std::endl;
#endif

	// postcondition
	assert(number_of_elements_removed == 1);
	return proxy_ptr;
}

BaseProxy_shared_ptr_t ProxyCacheManager::find(ProxyCacheManager_key_type_t key) const {
	static const std::string log_prefix { "MDL: ProxyCacheManager::find:" };

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix << " [DEBUG] look for key " << key << " in proxy cache." << std::endl;
#endif

	const auto position = proxy_map_.find(key);

#ifdef DEBUG_PROXYCACHEMANAGER
	std::clog << log_prefix << " [DEBUG] position != proxy_map_.end() = " << std::boolalpha << (position != proxy_map_.end()) << "." << std::endl;
#endif
	
	assert(position != proxy_map_.end());
	const auto proxy_ptr = position -> second;
	return proxy_ptr;
}

void ProxyCacheManager::sweep() const {
	static const std::string log_prefix { "MDL: ProxyCacheManager::sweep:" };
	for (auto& element : proxy_map_) {
		const auto use_count = element.second.use_count();
		if (use_count > 1) {
			if (!(element.second -> protected_)) {
				JSValueProtect(Ti::Runtime::instance().globalContext(), element.second -> js_object_);
				element.second -> protected_ = true;

#ifdef DEBUG_PROXYCACHEMANAGER
				std::clog << log_prefix
				          << " [DEBUG] protect js_object_ for "
				          << element.second -> get_proxy_identifier()
				          << ", use_count = "
				          << element.second.use_count()
				          << ", protected = "
				          << std::boolalpha
				          << element.second -> protected_
				          << "."
				          << std::endl;
#endif
			}
		} else if (element.second -> protected_) {
			JSValueUnprotect(Ti::Runtime::instance().globalContext(), element.second -> js_object_);
			element.second -> protected_ = false;

#ifdef DEBUG_PROXYCACHEMANAGER
			std::clog << log_prefix
			          << " [DEBUG] unprotect js_object_ for "
			          << element.second -> get_proxy_identifier()
			          << ", use_count = "
			          << element.second.use_count()
			          << ", protected = "
			          << std::boolalpha
			          << element.second -> protected_
			          << "."
			          << std::endl;
#endif
		}
	}
}

void ProxyCacheManager::scan() const {
	static const std::string log_prefix { "MDL: ProxyCacheManager::scan:" };
	for (auto& element : proxy_map_) {
		std::clog << log_prefix
		          << " [DEBUG] "
		          << element.second -> get_proxy_identifier()
		          << ", use_count = "
		          << element.second.use_count()
		          << ", protected = "
		          << std::boolalpha
		          << element.second -> protected_
		          << "."
		          << std::endl;
	}
}
