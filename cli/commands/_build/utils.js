var appc = require('node-appc');


/*
 Public API.
 */
exports.mixin = mixin;

/*
 Implementation.
 */
function mixin(WindowsBuilder) {
	WindowsBuilder.prototype.getTargetDevices = getTargetDevices;
	WindowsBuilder.prototype.sanitizeProjectName = sanitizeProjectName;
	WindowsBuilder.prototype.computeHashes = computeHashes;
}

/**
 * Returns the available target Windows Phone devices and emulators. It will
 * cache the results so subsequent calls don't have to requery.
 *
 * This function must be called after the CLI has called config() and after
 * the --ws-sdk option has been processed.
 *
 * @returns {Array}
 */
function getTargetDevices() {
	if (this.deviceCache) {
		return this.deviceCache;
	}

	var target = this.cli.argv.target,
		wpsdk = this.cli.argv['wp-sdk'];

	if (target === 'wp-emulator' && this.windowsInfo.emulators && Array.isArray(this.windowsInfo.emulators[wpsdk])) {
		return this.deviceCache = this.windowsInfo.emulators[wpsdk];
	} else if (target === 'wp-device' && Array.isArray(this.windowsInfo.devices)) {
		return this.deviceCache = this.windowsInfo.devices;
	}

	return [];
}

/**
 * Removes characters from the project name that aren't supported.
 * @param str
 * @returns {string}
 */
function sanitizeProjectName(str) {
	return str
		.replace(/[^a-zA-Z0-9_]/g, '_')
		.replace(/_+/g, '_')
		.split(/[\W_]/)
		.map(function (s) { return appc.string.capitalize(s); })
		.join('');
}


/**
 * Generate hashes of modules and properties from the tiapp.xml so we can detect
 * changes and force a rebuild.
 *
 * @param {Function} next - A function to call when once the hashes have been computed
 */
function computeHashes(next) {
	// modules
	this.modulesHash = !Array.isArray(this.tiapp.modules) ? '' : this.hash(this.tiapp.modules.filter(function (m) {
		return !m.platform || /^windows|commonjs$/.test(m.platform);
	}).map(function (m) {
		return m.id + ',' + m.platform + ',' + m.version;
	}).join('|'));

	// properties
	this.propertiesHash = this.hash(this.tiapp.properties ? JSON.stringify(this.tiapp.properties) : '');

	next();
}
