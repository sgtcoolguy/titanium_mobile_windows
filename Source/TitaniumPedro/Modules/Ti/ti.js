/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

(function (self) {
    const DEBUG_TIMODULE = false;
    var Utils = self.internal_require('ti.jsutils');
    var exports = {};
    exports.GC = self.gc;
    self.global.require = self.require;
    /*
    function (args) {
        console.log("-----REQUIRE----");
        var obj = {};
        try {
            obj = self.require(args);
        } catch (er) {
            console.log("-----ERROR----");
            Utils.showError(er);
        }
        return obj;
    };
    */
    // Every TiProxy will have these methods:
    self.TiProxy.prototype.applyProperties = function (_object) {
        _object = _object || {};
        var keys = Object.keys(_object);
        for (var i = 0, len = keys.length; i < len; i++) {
            this[keys[i]] = _object[keys[i]];
        }
    };

    self.TiProxy.prototype.addEventListener = function (_string, _callback) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = this.ProxyIdentifier();
        }
        this.__ti_private__.events = this.__ti_private__.events || {};
        this.__ti_private__.events[_string] = this.__ti_private__.events[_string] || [];
        var i = this.__ti_private__.events[_string].indexOf(_callback);
        if (i == -1) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiProxy.prototype.addEventListener(' + _string + ', _callback): add ' + _string + ' event listener to ' + proxy_identifier + '.');
            }
            this.__ti_private__.events[_string].push(_callback);
            this.eventAdded(_string, _callback);
        } else {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiProxy.prototype.addEventListener(' + _string + ', _callback): ignore request to add identical ' + _string + ' event listener to ' + proxy_identifier + '.');
            }
        }
    };

    self.TiProxy.prototype.removeEventListener = function (_string, _callback) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = this.ProxyIdentifier();
        }
        if (!this.__ti_private__.events) {
            var proxy_identifier = this.ProxyIdentifier();
            self.log('[WARN] TiProxy.prototype.removeEventListener(' + _string + ', _callback): this.__ti_private__.events array does not exist for ' + proxy_identifier + '.');
            return;
        }
        if (!this.__ti_private__.events[_string]) {
            var proxy_identifier = this.ProxyIdentifier();
            self.log('[WARN] TiProxy.prototype.removeEventListener(' + _string + ', _callback): this.__ti_private__.events array does not contain ' + _string + ' event listeners for ' + proxy_identifier + '.');
            return;
        }
        var i = this.__ti_private__.events[_string].indexOf(_callback);
        if (i != -1) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiProxy.prototype.removeEventListener(' + _string + ', _callback): remove ' + _string + ' event listener for ' + proxy_identifier + '.');
            }
            this.__ti_private__.events[_string].splice(i, 1);
            if (this.__ti_private__.events[_string].length == 0) {
                delete this.__ti_private__.events[_string];
            }
            this.eventRemoved(_string, _callback);
        } else {
            var proxy_identifier = this.ProxyIdentifier();
            self.log('[WARN] TiProxy.prototype.removeEventListener(' + _string + ', _callback): ignore request to remove nonexistent ' + _string + ' event listener for ' + proxy_identifier + '.');
        }
    };

    self.TiProxy.prototype.fireEvent = function (_string, _object) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = this.ProxyIdentifier();
        } if (!this.__ti_private__.events) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiProxy.prototype.fireEvent(' + _string + ', _object): this.__ti_private__.events array does not exist for ' + proxy_identifier + '.');
            }
            return;
        }
        if (!this.__ti_private__.events[_string]) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiProxy.prototype.fireEvent(' + _string + ', _object): this.__ti_private__.events array does not contain a ' + _string + ' event listener for ' + proxy_identifier + '.');
            }
            return;
        }
        _object = _object || {};
        _object.source = this;
        this.__ti_private__.events[_string].forEach(function (callback, index) {
            try {
                if (DEBUG_TIMODULE) {
                    Ti.API.debug('TiProxy.prototype.fireEvent(' + _string + ', _object): fire event ' + _string + ' at index ' + index + ' for ' + proxy_identifier + '.');
                }
                callback(_object);
            } catch (error) {
                Ti.API.error('TiProxy.prototype.fireEvent(' + _string + ', _object): caught exception calling callback at index ' + index + ' for ' + proxy_identifier + ': ' + error);
                Utils.showError(error);
            }
        });
        // Event hook for fireEvent
        // Currently only Ti.App is using this, to delegate all Ti.App events onto WebView.
        // Do not call fireEvent() in fireEventCallback otherwise you'll end up in infinite loop.
        if (this.__ti_private__.fireEventHook) {
            this.__ti_private__.fireEventHook(_string, _object);
        }
    };

    // Every TiViewProxy will have these methods:
    self.TiViewProxy.prototype.add = function (_view) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = this.ProxyIdentifier();
            var view_proxy_identifier = _view.ProxyIdentifier();
        } this.children = this.children || [];
        var i = this.children.indexOf(_view);
        // TODO: What would be the use case of adding the same view a seconds time?
        if (i != -1) {
            var proxy_identifier = this.ProxyIdentifier();
            var view_proxy_identifier = _view.ProxyIdentifier();
            Ti.API.error('TiViewProxy.prototype.add(' + view_proxy_identifier + '): view ' + view_proxy_identifier + ' already exists in our list of child views for ' + proxy_identifier + '.');
            return;
        }
        if (DEBUG_TIMODULE) {
            Ti.API.debug('TiViewProxy.prototype.add(' + view_proxy_identifier + '): add view ' + view_proxy_identifier + ' to ' + proxy_identifier + '.');
        } this._addView(_view);
        // Protect the child view from GC
        this.children.push(_view);
    };

    self.TiViewProxy.prototype.remove = function (_view) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = this.ProxyIdentifier();
            var view_proxy_identifier = _view.ProxyIdentifier();
        }
        if (!this.children) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('TiViewProxy.prototype.remove(' + view_proxy_identifier + '): this.children array does not exist for ' + proxy_identifier + '.');
            } return;
        }
        var i = this.children.indexOf(_view);
        if (i == -1) {
            var proxy_identifier = this.ProxyIdentifier();
            var view_proxy_identifier = _view.ProxyIdentifier();
            Ti.API.error('TiViewProxy.prototype.remove(' + view_proxy_identifier + '): could not find view ' + view_proxy_identifier + ' in our list of child views for ' + proxy_identifier + '.');
            return;
        }
        if (DEBUG_TIMODULE) {
            Ti.API.debug('TiViewProxy.prototype.remove(' + view_proxy_identifier + '): remove view ' + view_proxy_identifier + ' from ' + proxy_identifier + '.');
        } this._removeView(_view);
        this.children.splice(i, 1);
        _view = null;
    };

    // setTimeout and setInterval
    // clearTimeout and clearInterval
    //
    // The timerList array is used to prevent the native TimerProxy
    // from garbage collection, and also enables clearTimeout and
    // clearInterval.
    var timerList = [];
    function timerOn(_callback, _milliseconds, _repeat) {
        var timer = new self.Timer(_milliseconds);
        timer._callback = _callback;
        if (DEBUG_TIMODULE) {
            var proxy_identifier = timer.ProxyIdentifier();
            Ti.API.debug('timerOn: add timer ' + proxy_identifier + ' to timerList.');
        }
        timerList.push(timer);
        timer.callback = function () {
            if (_repeat == false) {
                timerOff(timer);
            }
            try {
               _callback();
            } catch (error) {
                Utils.showError(error);
            }
        };
        timer.start();
        return timer;
    };

    function timerOff(_timer) {
        if (DEBUG_TIMODULE) {
            var proxy_identifier = _timer.ProxyIdentifier();
            Ti.API.debug('timerOff: try to remove timer ' + proxy_identifier + ' from timerList.');
        }
        var i = timerList.indexOf(_timer);
        if (i == -1) {
            if (DEBUG_TIMODULE) {
                Ti.API.debug('timerOff: Ignore request to remove timer ' + proxy_identifier + ' since it is not in our list of timers.');
                Ti.API.debug('timerOff: We have these timers in our list:');
                timerList.forEach(function (timer, index, array) {
                    var existing_proxy_identifier = timer.ProxyIdentifier();
                    Ti.API.debug('timerOff: index = ' + index + ', timer = ' + existing_proxy_identifier);
                });
            }
            return;
        }
        _timer.stop();
        timerList.splice(i, 1);
        if (DEBUG_TIMODULE) {
            Ti.API.debug('timerOff: successfully removed timer ' + proxy_identifier + ' from timerList.');
        }
        _timer = null;
    };

    // Using `self.global` adds it to the global object
    // becuase `self.global` is the global object.
    self.global.setTimeout = function (_callback, _milliseconds) {
        return timerOn(_callback, _milliseconds, false);
    };

    self.global.setInterval = function (_callback, _milliseconds) {
        return timerOn(_callback, _milliseconds, true);
    };

    self.global.clearTimeout = function (_timer) {
        timerOff(_timer);
    };

    self.global.clearInterval = function (_timer) {
        timerOff(_timer);
    };

    self.global.console = {
        log: function (args) {
            self.log(args);
        },
        warn: function (args) {
            self.log(args);
        },
        error: function (args) {
            self.log(args);
        }
    };

    // Create the API module, simple!
    // TODO: http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.API
    exports.API = {
        info: function (_str) {
            console.log('[INFO] ' + _str);
        },
        debug: function (_str) {
            console.log('[DEBUG] ' + _str);
        },
        log: function (_level, _str) {
            console.log('['+_level.toUpperCase()+'] ' + _str);
        },
        trace: function (_str) {
            console.log('[TRACE] ' + _str);
        },
        warn: function (_str) {
            console.log('[WARN] ' + _str);
        },
        error: function (_str) {
            console.log('[ERROR] ' + _str);
        }
    };

    // Adds the specified callback as an event listener for the named event.
    exports.addEventListener = function (name, callback) {
        return Ti.App.addEventListener(name, callback);
    };
    // Removes the specified callback as an event listener for the named event.
    exports.removeEventListener = function (name, callback) {
        return Ti.App.removeEventListener(name, callback);
    };
    // Fires a synthesized event to any registered listeners.
    exports.fireEvent = function (name, event) {
        return Ti.App.fireEvent(name, event);
    };
    // Applies the properties to the Ti object
    exports.applyProperties = function (_object) {
        _object = _object || {};
        var keys = Object.keys(_object);
        for (var i = 0, len = keys.length; i < len; i++) {
            exports[keys[i]] = _object[keys[i]];
        }
    };

    //
    // TODO: Titanium build system should update these build properties
    //

    // Date of the Titanium build
    exports.buildDate = "__TITANIUM_BUILD_DATE__";
    exports.getBuildDate = function () {
        return exports.buildDate;
    };

    // Git hash of the Titanium build
    exports.buildHash = "__TITANIUM_BUILD_HASH__";
    exports.getBuildHash = function () {
        return exports.buildHash;
    };

    // Version of Titanium that is executing
    exports.version = "__TITANIUM_VERSION__";
    exports.getVersion = function () {
        return exports.version;
    }

    // User-agent string used by Titanium
    exports.userAgent = "__TITANIUM_USER_AGENT__";
    exports.getUserAgent = function () {
        return exports.userAgent;
    }
    exports.setUserAgent = function (value) {
        exports.userAgent = value;
    }

    // TiViewProxy's properties
    // Main ViewProxy
    Utils.addPropertiesToTiObject(self.TiViewProxy, {
        top: [true, true],
        bottom: [true, true],
        right: [true, true],
        left: [true, true],
        width: [true, true],
        height: [true, true],
        layout: [true, true],
        center: [true, true],
        backgroundColor: [true, true],
        color: [true, true],
        borderColor: [true, true],
        borderWidth: [true, true],
        size: [false, true],
        rect: [false, true]
    });

    return exports;
})(this);
