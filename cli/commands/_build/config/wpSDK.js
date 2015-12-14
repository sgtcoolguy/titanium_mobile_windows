var appc = require('node-appc'),
	__ = appc.i18n(__dirname).__;


/**
 * Defines the --wp-sdk option.
 *
 * @param {Number} order - The order to apply to this option.
 *
 * @returns {Object}
 */
module.exports = function configOptionWPSDK(order) {
	var defaultTarget = '8.1';

	var sdkTargets = [];
	for (var version in this.windowsInfo.windowsphone) {
		sdkTargets.push(version);
		if (this.windowsInfo.windowsphone[version].selected) {
			defaultTarget = version;
		}
	}

	return {
		abbr: 'S',
		callback: function (value) {
			if (value === '10.0') {
				this.conf.options['ws-cert'].required = true;
				this.conf.options['pfx-password'].required = true;
			}
		}.bind(this),
		default: defaultTarget,
		desc: __('the Windows Phone SDK version; only used when target is %s, %s, or %s', 'wp-emulator'.cyan, 'wp-device'.cyan, 'dist-phonestore'.cyan),
		hint: __('version'),
		order: order,
		values: sdkTargets
	};
};
