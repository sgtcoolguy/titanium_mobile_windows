// -*- mode: c++ -*-

#ifndef _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_TIPROXY2_H_
#define _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_TIPROXY2_H_

#include "BaseProxy2.h"

namespace Ti {

class Proxy2 : public BaseProxy2<Proxy2> {

 public:
	static constexpr JSClassRef       Parent         { nullptr  };
	static constexpr JSStaticFunction ClassMethods[] { {0, 0, 0} };

	Proxy2(const std::string proxyName = "Proxy2") : BaseProxy2<Proxy2>(proxyName) {
	};

};

}  // namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_TIPROXY2_H_

