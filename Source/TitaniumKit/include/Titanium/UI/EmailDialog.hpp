/**
 * TitaniumKit Titanium.UI.EmailDialog
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_EMAILDIALOG_HPP_
#define _TITANIUM_EMAILDIALOG_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Filesystem/File.hpp"
#include "Titanium/Blob.hpp"
#include <vector>

#ifdef FAILED
#pragma push_macro("FAILED")
#undef FAILED
#define _restore_FAILED_
#endif

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class
		  @discussion This is the Titanium EmailDialog Module.
		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.EmailDialog
		*/
		class TITANIUMKIT_EXPORT EmailDialog : public Module, public JSExport<EmailDialog>
		{

		public:

			/*!
			  @property
			  @abstract CANCELLED
			  @discussion Constant for the `CANCELLED` status result.
			*/
			virtual JSValue CANCELLED() const TITANIUM_NOEXCEPT final;

			/*!
			  @property
			  @abstract FAILED
			  @discussion Constant for the `FAILED` status result.
			*/
			virtual JSValue FAILED() const TITANIUM_NOEXCEPT final;

			/*!
			  @property
			  @abstract SAVED
			  @discussion Constant for the `SAVED` status result. On Android, this property exists but is not used.
			*/
			virtual JSValue SAVED() const TITANIUM_NOEXCEPT final;

			/*!
			  @property
			  @abstract SENT
			  @discussion Constant for the `SENT` status result.
			*/
			virtual JSValue SENT() const TITANIUM_NOEXCEPT final;

			/*!
			  @property
			  @abstract bccRecipients
			  @discussion Recipients of the email included via the `BCC` (Blind Carbon Copy) field.
			*/
			virtual std::vector<std::string> get_bccRecipients() const TITANIUM_NOEXCEPT final;
			virtual void set_bccRecipients(const std::vector<std::string>& bcc) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract ccRecipients
			  @discussion Recipients of the email included via the `CC` (Carbon Copy) field.
			*/
			virtual std::vector<std::string> get_ccRecipients() const TITANIUM_NOEXCEPT final;
			virtual void set_ccRecipients(const std::vector<std::string>& cc) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract html
			  @discussion Determines whether the email message, specifically the contents of [messageBody](Titanium.UI.EmailDialog.messageBody), should be sent as HTML content type rather than plain text.
			*/
			virtual bool get_html() const TITANIUM_NOEXCEPT final;
			virtual void set_html(const bool& html) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract messageBody
			  @discussion Email message body.
			*/
			virtual std::string get_messageBody() const TITANIUM_NOEXCEPT final;
			virtual void set_messageBody(const std::string& body) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract subject
			  @discussion Subject line for the email.
			*/
			virtual std::string get_subject() const TITANIUM_NOEXCEPT final;
			virtual void set_subject(const std::string& subject) TITANIUM_NOEXCEPT;

			/*!
			  @property
			  @abstract toRecipients
			  @discussion Recipients of the email included via the main `TO` field.
			*/
			virtual std::vector<std::string> get_toRecipients() const TITANIUM_NOEXCEPT final;
			virtual void set_toRecipients(const std::vector<std::string>& toRecipients) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract addAttachment
			  @discussion Adds an attachment.
			*/
			virtual void addAttachment(const std::shared_ptr<Titanium::Filesystem::File>& attachment) TITANIUM_NOEXCEPT;
			virtual void addAttachment(const std::shared_ptr<Titanium::Blob>& attachment) TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract isSupported
			  @discussion Indicates whether sending email is supported by the system.
			*/
			virtual bool isSupported() TITANIUM_NOEXCEPT;

			/*!
			  @method
			  @abstract open
			  @discussion Opens this email dialog.
			*/
			virtual void open(const bool& animated) TITANIUM_NOEXCEPT;

			EmailDialog(const JSContext&) TITANIUM_NOEXCEPT;
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual ~EmailDialog() = default;
			EmailDialog(const EmailDialog&) = default;
			EmailDialog& operator=(const EmailDialog&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			EmailDialog(EmailDialog&&)                 = default;
			EmailDialog& operator=(EmailDialog&&)      = default;
#endif

			static void JSExportInitialize();

			virtual JSValue js_get_bccRecipients() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_bccRecipients(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_ccRecipients() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_ccRecipients(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_html() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_html(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_messageBody() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_messageBody(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_subject() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_subject(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_get_toRecipients() const TITANIUM_NOEXCEPT final;
			virtual bool js_set_toRecipients(const JSValue& argument) TITANIUM_NOEXCEPT final;
			virtual JSValue js_addAttachment(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_isSupported(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_open(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getBccRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setBccRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getCcRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setCcRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getHtml(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setHtml(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getMessageBody(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setMessageBody(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getSubject(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setSubject(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_getToRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;
			virtual JSValue js_setToRecipients(const std::vector<JSValue>&, JSObject&) TITANIUM_NOEXCEPT final;

		private:
#pragma warning(push)
#pragma warning(disable : 4251)
			JSValue cancelled__;
			JSValue failed__;
			JSValue saved__;
			JSValue sent__;
			std::vector<std::string> bccRecipients__;
			std::vector<std::string> ccRecipients__;
			bool html__;
			std::string messageBody__;
			std::string subject__;
			std::vector<std::string> toRecipients__;
			std::vector<std::shared_ptr<Titanium::Blob>> attachments__;
#pragma warning(pop)
		};

	} // namespace UI
} // namespace Titanium

#ifdef _restore_FAILED_
#pragma pop_macro("FAILED")
#undef _restore_FAILED_
#endif

#endif // _TITANIUM_EMAILDIALOG_HPP_