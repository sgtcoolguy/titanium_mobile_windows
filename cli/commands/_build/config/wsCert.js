var appc = require('node-appc'),
	fields = require('fields'),
	fs = require('fs'),
	__ = appc.i18n(__dirname).__;

/**
 * Defines the --ws-cert option.
 *
 * @param {Number} order - The order to apply to this option.
 *
 * @returns {Object}
 */
module.exports = function configOptionWSCert(order) {
	function validate(certFile, callback) {
		if (certFile === '') {
			return callback();
		}

		certFile = appc.fs.resolvePath(certFile);

		if (!fs.existsSync(certFile) || !fs.statSync(certFile).isFile()) {
			return callback(new Error(__('Invalid cert file')));
		}

		callback(null, certFile);
	}

	return {
		abbr: 'R',
		desc: __('the location of the cert file; only applicable when target is %s or %s', 'ws-local'.cyan, 'dist-winstore'.cyan), // or ws-simulator or ws-remote
		hint: 'path',
		order: order,
		prompt: function (callback) {
			var certs = fs.readdirSync('./').filter(function (file) {
					return file.slice(-4).toLowerCase() === '.pfx';
				}),
				existingCert = certs.length && appc.fs.resolvePath(certs[0]);
			callback(fields.file({
				promptLabel: __('Where is the __pfx file__ used to sign the app? (leave blank to generate)'),
				default: fs.existsSync(existingCert) ? certs[0] : undefined,
				complete: true,
				showHidden: true,
				ignoreDirs: this.ignoreDirs,
				ignoreFiles: this.ignoreFiles,
				validate: validate
			}));
		},
		validate: validate
	};
};