var appc = require('node-appc'),
	fields = require('fields'),
	path = require('path'),
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
			});
			if (certs.length === 1) {
				console.log('(Hint: Found a pfx file in working directory: ' + certs[0] + ')');
			}
			else if (certs.length > 1) {
				console.log('(Hint: Found these pfx files in working directory: ' + certs.join(', ') + ')');
			}
			callback(fields.file({
				promptLabel: __('What __pfx file__ should sign the app? (leave blank to generate)'),
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