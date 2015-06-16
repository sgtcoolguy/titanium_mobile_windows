var appc = require('node-appc'),
	__ = appc.i18n(__dirname).__;


/**
 * Defines the --target option.
 *
 * @param {Number} order - The order to apply to this option.
 *
 * @returns {Object}
 */
module.exports = function configOptionTarget(order) {
	return {
		abbr: 'T',
		callback: function (value) {
			// as soon as we know the target, toggle required options for validation

			if (value === 'wp-emulator' || value === 'wp-device') {
				this.conf.options['device-id'].required = true;
			}

			if (value === 'wp-emulator' || value === 'wp-device' || value === 'dist-phonestore') {
				this.conf.options['wp-publisher-guid'].required = true;
				this.conf.options['wp-sdk'].required = true;
			}

			if (value === 'dist-phonestore' || value === 'dist-winstore') {
				this.conf.options['output-dir'].required = true;
			}

			if (value === 'dist-winstore' || value == 'ws-local') {
				this.conf.options['ws-cert'].required = true;
				this.conf.options['pfx-password'].required = true;
			}
		}.bind(this),
		default: this.defaultTarget,
		desc: __('the target to build for'),
		order: order,
		required: true,
		values: this.targets
	};
};