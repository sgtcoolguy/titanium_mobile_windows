/** -*- mode: c++ -*-
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_MOBILE_WINDOWS_TICORE_TIMERPROXY_H_
#define _TITANIUM_MOBILE_WINDOWS_TICORE_TIMERPROXY_H_

#include "TiCore/TiProxy.h"
#include <chrono>
#include <ratio>
#include <mutex>
#include <cassert>

// This is the timer proxy, used to create setTimeout, clearTimeout,
// setInterval, and clearInterval
class TimerProxy : public Ti::Proxy, public virtual_enable_shared_from_this<TimerProxy> {

 protected:

	TimerProxy(const std::string& name, const std::vector<Ti::Value>& arguments) : Ti::Proxy(name, arguments) {
		const double arg1 = arguments.at(0).toDouble();
		// std::clog << "MDL: TimerProxy: arg1 = " << arg1 << std::endl;
		auto timer_interval_ms = std::chrono::milliseconds(static_cast<std::chrono::milliseconds::rep>(arg1));
		// std::clog << "MDL: TimerProxy: timer_interval_ms = " << timer_interval_ms.count() << std::endl;

		// A Windows::Foundation::TimeSpan is a time period expressed in
		// 100-nanosecond units.
		//
		// Reference:
		// http://msdn.microsoft.com/en-us/library/windows/apps/windows.foundation.timespan
		std::chrono::duration<std::chrono::nanoseconds::rep, std::ratio_multiply<std::ratio<100>, std::nano> > timer_interval_ticks = timer_interval_ms;
		// std::clog << "MDL: TimerProxy: timer_interval_ticks = " << timer_interval_ticks.count() << std::endl;

		Windows::Foundation::TimeSpan time_span;
		time_span.Duration = timer_interval_ticks.count();
		dispatcher_timer_ = ref new Windows::UI::Xaml::DispatcherTimer();
		dispatcher_timer_ -> Interval = time_span;
	}

	virtual ~TimerProxy() {
		if (dispatcher_timer_ -> IsEnabled) {
			dispatcher_timer_ -> Stop();
		}

		// TODO: what happens if start was never called? Is this an error?
		dispatcher_timer_ -> Tick -= event_registration_token_;
		dispatcher_timer_ = nullptr;
	}

 private:

	Windows::UI::Xaml::DispatcherTimer^         dispatcher_timer_;
	std::once_flag                              dispatcher_timer_once_flag_;
	//std::atomic<long>                           repeat_count_ { 0 };
	Windows::Foundation::EventRegistrationToken event_registration_token_;

	////////////////////////////////////////////////////////////////////////
	//
	// Proxy macro infrastructure goes below here.
	//
	////////////////////////////////////////////////////////////////////////

	TI_CREATE_PROXY(TimerProxy);

	static JSClassRef Parent() {
		return Ti::Proxy::ClassDef();
	}

	TI_CREATE_METHOD(TimerProxy, start);
	Ti::Value start(const std::vector<Ti::Value>& arguments) {
		std::call_once(dispatcher_timer_once_flag_, [this] {
				// Bring in the placeholders _1, _2, etc. for std::bind.
				using namespace std::placeholders;
				auto callback = std::bind([](const TimerProxy_weak_ptr_t& weakThis, Platform::Object^ sender, Platform::Object^ event) {
						auto strong_ptr = weakThis.lock();
						if (strong_ptr) {
							strong_ptr -> fireCallback("callback", Ti::Value::Undefined());
						}
					},
					std::move(get_weak_ptr_for_proxy()), _1, _2);
				
				this -> event_registration_token_ = this -> dispatcher_timer_ -> Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>(callback);
			});
		
		if (!(dispatcher_timer_ -> IsEnabled)) {
			// std::clog << "MDL: TimerProxy: start timer " << this << std::endl;
			dispatcher_timer_ -> Start();
		} else {
			std::clog << "MDL: [WARN] TimerProxy: start called while timer is already running for " << this << std::endl;
		}
		
		return Ti::Value::Undefined();
	}
	
	TI_CREATE_METHOD(TimerProxy, stop);
	Ti::Value stop(const std::vector<Ti::Value>& arguments) {
		if (dispatcher_timer_ -> IsEnabled) {
			// std::clog << "MDL: TimerProxy: stop timer " << this << std::endl;
			dispatcher_timer_ -> Stop();
		} else {
			std::clog << "MDL: [WARN] TimerProxy: stop called while timer is not running for " << this << std::endl;
		}
		
		return Ti::Value::Undefined();
	}
};

#endif	// _TITANIUM_MOBILE_WINDOWS_TICORE_TIMERPROXY_H_
