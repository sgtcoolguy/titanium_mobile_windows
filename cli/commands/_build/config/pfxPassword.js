var appc = require('node-appc'),
	fields = require('fields'),
	__ = appc.i18n(__dirname).__;

/**
 * Defines the --pfx-password option.
 *
 * @param {Number} order - The order to apply to this option.
 *
 * @returns {Object}
 */
module.exports = function configOptionPFXPassword(order) {
	function validate(pfxPassword, callback) {
		callback(pfxPassword !== undefined || !this.conf.options['pfx-password'].required ? null : new Error(__('Invalid pfx password')), pfxPassword);
	}

	return {
		abbr: 'P',
		desc: __('the PFX password; only applicable when target is %s or %s', 'ws-local'.cyan, 'dist-winstore'.cyan),
		hint: 'password',
		order: order,
		prompt: function (callback) {
			if (this.cli.argv['ws-cert']) {
				// We don't need a password! Carry on, mate.
				return callback();
			}
			callback(fields.text({
				promptLabel: __('What is (or will be) your PFX password?'),
				password: true,
				validate: validate.bind(this)
			}));
		}.bind(this),
		validate: validate.bind(this)
	};
};