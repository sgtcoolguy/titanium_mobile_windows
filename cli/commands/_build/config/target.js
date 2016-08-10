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
				this.conf.options['wp-sdk'].required = true;
			}

			if (value === 'dist-phonestore' || value === 'dist-winstore') {
				this.conf.options['output-dir'].required = true;
			}

			// targeting ws-local without SDK specified, select most appropriate for platform
			if (value === 'ws-local' && this.cli.argv.$_.indexOf('--wp-sdk') === -1 && this.cli.argv.$_.indexOf('-S') === -1) {
				var sdk = '10.0',
					os = require('os').release();

				// not on Windows 10, default to 8.1 sdk
				if (!os.startsWith('10.0')) {
					sdk = '8.1';
				}
				this.cli.argv['wp-sdk'] = sdk;
			}
		}.bind(this),
		default: this.defaultTarget,
		desc: __('the target to build for'),
		order: order,
		required: true,
		values: this.targets
	};
};
