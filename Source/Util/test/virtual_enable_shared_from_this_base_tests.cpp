#include "Util/virtual_enable_shared_from_this_base.hpp"

#include <functional>
#include <string>
#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

using Appcelerator::Util::virtual_enable_shared_from_this;

struct A: virtual_enable_shared_from_this<A> {
};

struct B: virtual_enable_shared_from_this<B> {
};

using helloCallback_t = std::function<std::string()>;

struct C: A, B, virtual_enable_shared_from_this<C> {
  static const int arraySize { 10 };
  int* intArray { new int[arraySize] };
  
  std::string hello() {
    std::ostringstream os;
    os << "MDL: intArray = [";
    for (int i = 0; i < arraySize; ++i) {
      if (i > 0) {
        os << ", ";
      }
      os << intArray[i];
    }
    os << "]";
    return os.str();
  }
  
  C() {
    for (int i = 0; i < arraySize; ++i) {
      intArray[i] = i;
    }
  }
  
  ~C() {
    delete[] intArray;
  }
  
  using virtual_enable_shared_from_this<C>::shared_from_this;

  helloCallback_t helloCallbackCorrect() {
//#define GENERALIZED_LAMBDA_CAPTURE_SUPPORTED
#ifdef GENERALIZED_LAMBDA_CAPTURE_SUPPORTED
    auto lambda = [weakThis = std::weak_ptr<C>(shared_from_this())]() -> std::string {
      auto strong_ptr = weakThis.lock();
      if (strong_ptr) {
        return strong_ptr  -> hello();
      } else {
        return "weak pointer is invalid";
      }
    };
#else
    auto weakThis = std::weak_ptr<C>(shared_from_this());
    auto lambda = std::bind([](const std::weak_ptr<C>& weakThis) -> std::string {
        auto strong_ptr = weakThis.lock();
        if (strong_ptr) {
          return strong_ptr  -> hello();
        } else {
          return "weak pointer is invalid";
        }
      },
      std::move(weakThis)
      );
#endif

    return lambda;
  }

  helloCallback_t helloCallbackIncorrect() {
    auto lambda = [this]() -> std::string {
      // This will crash is this is a dangling pointer.
     return this -> hello();
    };
    
    return lambda;
  }
};

static const std::string expectedHelloResult("MDL: intArray = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]");

TEST(virtual_enable_shared_from_this, helloCallbackCorrect) {
  // Create a scope so that the destructors run.
  {
    auto c_ptr = std::make_shared<C>();
    auto helloCallback = c_ptr -> helloCallbackCorrect();
    std::cout << "helloCallback() = " << helloCallback() << std::endl;
    ASSERT_EQ(expectedHelloResult, helloCallback());
  }
  
  // This is initialized in the following scope in order to test that the weak
  // pointer works correctly.
  helloCallback_t helloCallback { nullptr };
  
  // Create a scope so that the destructors run.
  {
    auto c_ptr = std::make_shared<C>();
    helloCallback = c_ptr -> helloCallbackCorrect();
  }
  
  // The weak pointer logic in helloCallbackCorrect will detect that the weak
  // pointer is no longer valid.
  std::cout << "helloCallback() = " << helloCallback() << std::endl;
  ASSERT_EQ("weak pointer is invalid", helloCallback());
}

TEST(virtual_enable_shared_from_this, helloCallbackIncorrect) {
  // Create a scope so that the destructors run.
  {
    auto c_ptr = std::make_shared<C>();
    auto helloCallback = c_ptr -> helloCallbackIncorrect();
    ASSERT_EQ(expectedHelloResult, helloCallback());
  }
  
  // This is initialized in the following scope in order to test that the weak
  // pointer works correctly.
  helloCallback_t helloCallback { nullptr };
  
  // Create a scope so that the destructors run.
  {
    auto c_ptr = std::make_shared<C>();
    helloCallback = c_ptr -> helloCallbackIncorrect();
  }

  // The "this" pointer in the lambda is no longer valid, so using this lambda
  // will result undefined behaviour, probably crashing the app.
  // This causes EXC_BAD_ACCESS
  //std::cout << "helloCallback() = " << helloCallback() << std::endl;
#ifndef TRAVIS
  ASSERT_DEATH(helloCallback(); exit(1), ".*");
#else
  ASSERT_DEATH(helloCallback(), ".*");
#endif
}
