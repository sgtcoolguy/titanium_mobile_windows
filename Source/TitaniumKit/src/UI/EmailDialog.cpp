/**
 * TitaniumKit Titanium.UI.EmailDialog
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/EmailDialog.hpp"

#ifdef FAILED
#pragma push_macro("FAILED")
#undef FAILED
#define _restore_FAILED_
#endif

namespace Titanium
{
	namespace UI
	{

		EmailDialog::EmailDialog(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Module(js_context),
			cancelled__(js_context.CreateNumber(0)),
			failed__(js_context.CreateNumber(3)),
			saved__(js_context.CreateNumber(1)),
			sent__(js_context.CreateNumber(2)),
			html__(false),
			messageBody__(""),
			subject__("")
		{
			TITANIUM_LOG_DEBUG("EmailDialog:: ctor ", this);
		}

		void EmailDialog::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
			HAL_LOG_DEBUG("EmailDialog:: postCallAsConstructor ", this);
		}

		JSValue EmailDialog::CANCELLED() const TITANIUM_NOEXCEPT
		{
			return cancelled__;
		}

		JSValue EmailDialog::FAILED() const TITANIUM_NOEXCEPT
		{
			return failed__;
		}

		JSValue EmailDialog::SAVED() const TITANIUM_NOEXCEPT
		{
			return saved__;
		}

		JSValue EmailDialog::SENT() const TITANIUM_NOEXCEPT
		{
			return sent__;
		}

		std::vector<std::string> EmailDialog::get_bccRecipients() const TITANIUM_NOEXCEPT
		{
			return bccRecipients__;
		}

		void EmailDialog::set_bccRecipients(const std::vector<std::string>& bcc) TITANIUM_NOEXCEPT
		{
			bccRecipients__ = bcc;
		}

		std::vector<std::string> EmailDialog::get_ccRecipients() const TITANIUM_NOEXCEPT
		{
			return ccRecipients__;
		}

		void EmailDialog::set_ccRecipients(const std::vector<std::string>& cc) TITANIUM_NOEXCEPT
		{
			ccRecipients__ = cc;
		}

		bool EmailDialog::get_html() const TITANIUM_NOEXCEPT
		{
			return html__;
		}

		void EmailDialog::set_html(const bool& html) TITANIUM_NOEXCEPT
		{
			html__ = html;
		}

		std::string EmailDialog::get_messageBody() const TITANIUM_NOEXCEPT
		{
			return messageBody__;
		}

		void EmailDialog::set_messageBody(const std::string& body) TITANIUM_NOEXCEPT
		{
			messageBody__ = body;
		}

		std::string EmailDialog::get_subject() const TITANIUM_NOEXCEPT
		{
			return subject__;
		}

		void EmailDialog::set_subject(const std::string& subject) TITANIUM_NOEXCEPT
		{
			subject__ = subject;
		}

		std::vector<std::string> EmailDialog::get_toRecipients() const TITANIUM_NOEXCEPT
		{
			return toRecipients__;
		}

		void EmailDialog::set_toRecipients(const std::vector<std::string>& toRecipients) TITANIUM_NOEXCEPT
		{
			toRecipients__ = toRecipients;
		}

		void EmailDialog::addAttachment(const std::shared_ptr<Titanium::Filesystem::File>& attachment) TITANIUM_NOEXCEPT
		{
			addAttachment(attachment->read());
		}

		void EmailDialog::addAttachment(const std::shared_ptr<Titanium::Blob>& attachment) TITANIUM_NOEXCEPT
		{
			attachments__.push_back(attachment);
		}

		bool EmailDialog::isSupported() TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("EmailDialog::isSupported: Unimplemented");
			return false;
		}

		void EmailDialog::open(const bool& animated) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("EmailDialog::open: Unimplemented");
		}

		void EmailDialog::JSExportInitialize() {
			JSExport<EmailDialog>::SetClassVersion(1);
			JSExport<EmailDialog>::SetParent(JSExport<Module>::Class());

			JSExport<EmailDialog>::AddValueProperty("CANCELLED", std::mem_fn(&EmailDialog::CANCELLED));
			JSExport<EmailDialog>::AddValueProperty("FAILED", std::mem_fn(&EmailDialog::FAILED));
			JSExport<EmailDialog>::AddValueProperty("SAVED", std::mem_fn(&EmailDialog::SAVED));
			JSExport<EmailDialog>::AddValueProperty("SENT", std::mem_fn(&EmailDialog::SENT));
			JSExport<EmailDialog>::AddValueProperty("bccRecipients", std::mem_fn(&EmailDialog::js_get_bccRecipients), std::mem_fn(&EmailDialog::js_set_bccRecipients));
			JSExport<EmailDialog>::AddValueProperty("ccRecipients", std::mem_fn(&EmailDialog::js_get_ccRecipients), std::mem_fn(&EmailDialog::js_set_ccRecipients));
			JSExport<EmailDialog>::AddValueProperty("html", std::mem_fn(&EmailDialog::js_get_html), std::mem_fn(&EmailDialog::js_set_html));
			JSExport<EmailDialog>::AddValueProperty("messageBody", std::mem_fn(&EmailDialog::js_get_messageBody), std::mem_fn(&EmailDialog::js_set_messageBody));
			JSExport<EmailDialog>::AddValueProperty("subject", std::mem_fn(&EmailDialog::js_get_subject), std::mem_fn(&EmailDialog::js_set_subject));
			JSExport<EmailDialog>::AddValueProperty("toRecipients", std::mem_fn(&EmailDialog::js_get_toRecipients), std::mem_fn(&EmailDialog::js_set_toRecipients));

			JSExport<EmailDialog>::AddFunctionProperty("addAttachment", std::mem_fn(&EmailDialog::js_addAttachment));
			JSExport<EmailDialog>::AddFunctionProperty("isSupported", std::mem_fn(&EmailDialog::js_isSupported));
			JSExport<EmailDialog>::AddFunctionProperty("open", std::mem_fn(&EmailDialog::js_open));
			JSExport<EmailDialog>::AddFunctionProperty("getBccRecipients", std::mem_fn(&EmailDialog::js_getBccRecipients));
			JSExport<EmailDialog>::AddFunctionProperty("setBccRecipients", std::mem_fn(&EmailDialog::js_setBccRecipients));
			JSExport<EmailDialog>::AddFunctionProperty("getCcRecipients", std::mem_fn(&EmailDialog::js_getCcRecipients));
			JSExport<EmailDialog>::AddFunctionProperty("setCcRecipients", std::mem_fn(&EmailDialog::js_setCcRecipients));
			JSExport<EmailDialog>::AddFunctionProperty("getHtml", std::mem_fn(&EmailDialog::js_getHtml));
			JSExport<EmailDialog>::AddFunctionProperty("setHtml", std::mem_fn(&EmailDialog::js_setHtml));
			JSExport<EmailDialog>::AddFunctionProperty("getMessageBody", std::mem_fn(&EmailDialog::js_getMessageBody));
			JSExport<EmailDialog>::AddFunctionProperty("setMessageBody", std::mem_fn(&EmailDialog::js_setMessageBody));
			JSExport<EmailDialog>::AddFunctionProperty("getSubject", std::mem_fn(&EmailDialog::js_getSubject));
			JSExport<EmailDialog>::AddFunctionProperty("setSubject", std::mem_fn(&EmailDialog::js_setSubject));
			JSExport<EmailDialog>::AddFunctionProperty("getToRecipients", std::mem_fn(&EmailDialog::js_getToRecipients));
			JSExport<EmailDialog>::AddFunctionProperty("setToRecipients", std::mem_fn(&EmailDialog::js_setToRecipients));
		}

		JSValue EmailDialog::js_get_bccRecipients() const TITANIUM_NOEXCEPT
		{
			const auto js_context = get_context();
			const auto recipients = get_bccRecipients();
			std::vector<JSValue> args;
			for (auto r : recipients) {
				args.push_back(js_context.CreateString(r));
			}
			return js_context.CreateArray(args);
		}

		bool EmailDialog::js_set_bccRecipients(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			const auto _0 = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(_0.IsArray());

			std::vector<std::string> recipients;
			const auto item_count = static_cast<JSArray>(_0).GetLength();
			for (uint32_t i = 0; i < item_count; ++i) {
				JSValue item = _0.GetProperty(i);
				TITANIUM_ASSERT(item.IsString());
				recipients.push_back(static_cast<std::string>(item));
			}

			set_bccRecipients(recipients);

			return true;
		}

		JSValue EmailDialog::js_get_ccRecipients() const TITANIUM_NOEXCEPT
		{
			const auto js_context = get_context();
			const auto recipients = get_ccRecipients();
			std::vector<JSValue> args;
			for (auto r : recipients) {
				args.push_back(js_context.CreateString(r));
			}
			return js_context.CreateArray(args);
		}

		bool EmailDialog::js_set_ccRecipients(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			const auto _0 = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(_0.IsArray());

			std::vector<std::string> recipients;
			const auto item_count = static_cast<JSArray>(_0).GetLength();
			for (uint32_t i = 0; i < item_count; ++i) {
				JSValue item = _0.GetProperty(i);
				TITANIUM_ASSERT(item.IsString());
				recipients.push_back(static_cast<std::string>(item));
			}

			set_ccRecipients(recipients);
			return true;
		}

		JSValue EmailDialog::js_get_html() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(get_html());
		}

		bool EmailDialog::js_set_html(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsBoolean());
			set_html(static_cast<bool>(argument));
			return true;
		}

		JSValue EmailDialog::js_get_messageBody() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_messageBody());
		}

		bool EmailDialog::js_set_messageBody(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_messageBody(static_cast<std::string>(argument));
			return true;
		}

		JSValue EmailDialog::js_get_subject() const TITANIUM_NOEXCEPT
		{
			return get_context().CreateString(get_subject());
		}

		bool EmailDialog::js_set_subject(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsString());
			set_subject(static_cast<std::string>(argument));
			return true;
		}

		JSValue EmailDialog::js_get_toRecipients() const TITANIUM_NOEXCEPT
		{
			const auto js_context = get_context();
			const auto recipients = get_toRecipients();
			std::vector<JSValue> args;
			for (auto r : recipients) {
				args.push_back(js_context.CreateString(r));
			}
			return js_context.CreateArray(args);
		}

		bool EmailDialog::js_set_toRecipients(const JSValue& argument) TITANIUM_NOEXCEPT
		{
			TITANIUM_ASSERT(argument.IsObject());
			const auto _0 = static_cast<JSObject>(argument);
			TITANIUM_ASSERT(_0.IsArray());

			std::vector<std::string> recipients;
			const auto item_count = static_cast<JSArray>(_0).GetLength();
			for (uint32_t i = 0; i < item_count; ++i) {
				JSValue item = _0.GetProperty(i);
				TITANIUM_ASSERT(item.IsString());
				recipients.push_back(static_cast<std::string>(item));
			}

			set_toRecipients(recipients);

			return true;
		}

		JSValue EmailDialog::js_addAttachment(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.empty()) {
				return get_context().CreateUndefined();
			} else if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto attachment = static_cast<JSObject>(_0);

				const auto file_ptr = attachment.GetPrivate<Titanium::Filesystem::File>();
				const auto blob_ptr = attachment.GetPrivate<Titanium::Blob>();

				if (file_ptr != nullptr) {
					addAttachment(file_ptr);
				} else if (blob_ptr != nullptr) {
					addAttachment(blob_ptr);
				} else {
					TITANIUM_LOG_WARN("EmailDialog::addAttachment: Can not attach unknown object");
				}
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_isSupported(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return get_context().CreateBoolean(isSupported());
		}

		JSValue EmailDialog::js_open(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			bool animated = true;
			if (arguments.size() >= 1) {
				const auto _0 = arguments.at(0);
				TITANIUM_ASSERT(_0.IsObject());
				const auto properties = static_cast<JSObject>(_0);

				if (properties.HasProperty("animated")) {
					animated = static_cast<bool>(properties.GetProperty("animated"));
				}
			}
			open(animated);
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getBccRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_bccRecipients();
		}

		JSValue EmailDialog::js_setBccRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_bccRecipients(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getCcRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_ccRecipients();
		}

		JSValue EmailDialog::js_setCcRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_ccRecipients(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getHtml(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_html();
		}

		JSValue EmailDialog::js_setHtml(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_html(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getMessageBody(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_messageBody();
		}

		JSValue EmailDialog::js_setMessageBody(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_messageBody(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getSubject(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_subject();
		}

		JSValue EmailDialog::js_setSubject(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			 if (arguments.size() >= 1) {
				js_set_subject(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

		JSValue EmailDialog::js_getToRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			return js_get_toRecipients();
		}

		JSValue EmailDialog::js_setToRecipients(const std::vector<JSValue>& arguments, JSObject& this_object) TITANIUM_NOEXCEPT
		{
			if (arguments.size() >= 1) {
				js_set_toRecipients(arguments.at(0));
			}
			return get_context().CreateUndefined();
		}

	} // namespace UI
} // namespace Titanium

#ifdef _restore_FAILED_
#pragma pop_macro("FAILED")
#undef _restore_FAILED_
#endif
