(function (self) {

    Object.defineProperties(self.TiPlatform.prototype, {
        'statistics': { get: function () { return this.getStatistics(); }, enumerable: true },
        'BATTERY_STATE_CHARGING': { get: function () { return this.getBATTERY_STATE_CHARGING(); }, enumerable: true },
        'BATTERY_STATE_FULL': { get: function () { return this.getBATTERY_STATE_FULL(); }, enumerable: true },
        'BATTERY_STATE_UNKNOWN': { get: function () { return this.getBATTERY_STATE_UNKNOWN(); }, enumerable: true },
        'BATTERY_STATE_UNPLUGGED': { get: function () { return this.getBATTERY_STATE_UNPLUGGED(); }, enumerable: true },
        'address': { get: function () { return this.getAddress(); }, enumerable: true },
        'architecture': { get: function () { return this.getArchitecture(); }, enumerable: true },
        'availableMemory': { get: function () { return this.getAvailableMemory(); }, enumerable: true },
        'batteryLevel': { get: function () { return this.getBatteryLevel(); }, enumerable: true },
        'batteryMonitoring': { set: function (value) { this.setBatteryMonitoring(value); }, get: function () { return this.getBatteryMonitoring(); }, enumerable: true },
        'batteryState': { get: function () { return this.getBatteryState(); }, enumerable: true },
        'id': { get: function () { return this.getId(); }, enumerable: true },
        'locale': { get: function () { return this.getLocale(); }, enumerable: true },
        'macaddress': { get: function () { return this.getMacaddress(); }, enumerable: true },
        'manufacturer': { get: function () { return this.getManufacturer(); }, enumerable: true },
        'model': { get: function () { return this.getModel(); }, enumerable: true },
        'name': { get: function () { return this.getName(); }, enumerable: true },
        'netmask': { get: function () { return this.getNetmask(); }, enumerable: true },
        'osname': { get: function () { return this.getOsname(); }, enumerable: true },
        'ostype': { get: function () { return this.getOstype(); }, enumerable: true },
        'processorCount': { get: function () { return this.getProcessorCount(); }, enumerable: true },
        'runtime': { get: function () { return this.getRuntime(); }, enumerable: true },
        'username': { get: function () { return this.getUsername(); }, enumerable: true },
        'version': { get: function () { return this.getVersion(); }, enumerable: true },
    });

    Object.defineProperties(self.TiPlatformDisplayCaps.prototype, {
        'density': { set: function (value) { this.setDensity(value); }, get: function () { return this.getDensity(); }, enumerable: true },
        'dpi': { set: function (value) { this.setDpi(value); }, get: function () { return this.getDpi(); }, enumerable: true },
        'logicalDensityFactor': { set: function (value) { this.setLogicalDensityFactor(value); }, get: function () { return this.getLogicalDensityFactor(); }, enumerable: true },
        'platformHeight': { set: function (value) { this.setPlatformHeight(value); }, get: function () { return this.getPlatformHeight(); }, enumerable: true },
        'platformWidth': { set: function (value) { this.setPlatformWidth(value); }, get: function () { return this.getPlatformWidth(); }, enumerable: true },
        'xdpi': { set: function (value) { this.setXdpi(value); }, get: function () { return this.getXdpi(); }, enumerable: true },
        'ydpi': { set: function (value) { this.setYdpi(value); }, get: function () { return this.getYdpi(); }, enumerable: true },
    });

    var exports = new self.TiPlatform();

    exports.displayCaps = new self.TiPlatformDisplayCaps();
    exports.getDisplayCaps = function () {
        return this.displayCaps;
    };

    return exports;

})(this);
