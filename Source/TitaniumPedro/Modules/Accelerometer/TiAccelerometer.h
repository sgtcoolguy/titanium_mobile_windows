/** -*- mode: c++ -*-
* Appcelerator Titanium Mobile
* Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
* Licensed under the terms of the Apache Public License
* Please see the LICENSE included with this distribution for details.
*/

#ifndef _TITANIUM_MOBILE_WINDOWS_MODULES_ACCELEROMETER_H_
#define _TITANIUM_MOBILE_WINDOWS_MODULES_ACCELEROMETER_H_

#include "TiCore/TiProxy.h"

namespace Ti { namespace Accelerometer {
	class AccelerometerModule : public Ti::Proxy, public virtual_enable_shared_from_this<AccelerometerModule> {

	public:
		static Ti::Value Initialize(const std::string& ns, Ti::Value& obj);
		virtual Ti::Value eventAdded(const std::vector<Ti::Value>&args) override;
		virtual Ti::Value eventRemoved(const std::vector<Ti::Value>&args) override;

	protected:
		AccelerometerModule(const std::string& name, const std::vector<Ti::Value>& arguments);
		virtual void postConstruct() override;

	private:
		Windows::Foundation::DateTime previous_acceleromter_time_;
		Windows::Devices::Sensors::Accelerometer^ accelerometer_;

		Windows::Foundation::EventRegistrationToken update_event_;
		unsigned int update_listener_count_ { 0 };

		TI_CREATE_PROXY(AccelerometerModule);

		static JSClassRef Parent();
	};
}} // namespace Ti { namespace Accelerometer {

#endif // _TITANIUM_MOBILE_WINDOWS_MODULES_ACCELEROMETER_H_
