// -*- mode: c++ -*-

#ifndef _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_EXAMPLEPROXY2_H_
#define _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_EXAMPLEPROXY2_H_

#include "TiProxy2.h"

namespace Ti {

class ExampleProxy2 : public Proxy2	{
	//		TI_CREATE_PROXY(ExampleProxy)
	//		
	//		// Sample JavaScript method
	//		TI_CREATE_METHOD(ExampleProxy, saySomething);
		
 public:

	ExampleProxy2() : Proxy2() {
	};

};

}  // namespace Ti {

#endif // _TITANIUM_MOBILE_WINDOWS_TEST_TIVALUE_TIVALUE__TIVALUE_EXAMPLEPROXY2_H_
