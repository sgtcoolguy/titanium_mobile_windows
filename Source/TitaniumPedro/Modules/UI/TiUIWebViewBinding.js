(function () {
    function log(level, str) {
        if (typeof str == 'object') {
            str = JSON.stringify(str);
        }
        str = 'log' + ',' + level + ',' + str;
        window.external.notify(str);
    }
    Ti = {
        _event_listeners: [],
        createEventListener: function (eventName, listener) {
            var newListener = { eventName: eventName, listener: listener, systemId: -1, index: this._event_listeners.length };
            this._event_listeners.push(newListener);
            return newListener;
        },

        getEventListenerByKey: function (key, arg) {
            for (var i = 0; i < this._event_listeners.length; i++) {
                if (this._event_listeners[i][key] == arg) {
                    return this._event_listeners[i];
                }
            }
            return null;
        },
        getEventListenerByName: function (name) {
            for (var i = 0; i < this._event_listeners.length; i++) {
                if (this._event_listeners[i]['eventName'] == name) {
                    return this._event_listeners[i];
                }
            }
            return null;
        },
        API: {
            info: function (str) {
                log('INFO', str);
            },
            debug: function (str) {
                log('DEBUG', str);
            },
            error: function (str) {
                log('ERROR', str);
            }
        },
        App: {
            addEventListener: function (eventName, listener) {
                var newListener = Ti.createEventListener(eventName, listener);
                return newListener.systemId;
            },

            removeEventListener: function (eventName, listener) {
                if (typeof listener == 'number') {
                    var l = Ti.getEventListenerByKey('systemId', listener);
                    if (l !== null) {
                        Ti._event_listeners.splice(l.index, 1);
                    }
                } else {
                    l = Ti.getEventListenerByKey('listener', listener);
                    if (l !== null) {
                        Ti._event_listeners.splice(l.index, 1);
                    }
                }
            },

            fireEvent: function (eventName, data) {
                var str = 'event,' + eventName + ',' + JSON.stringify(data || {});
                window.external.notify(str);
            }
        },

        // Gets called by Ti.App.fireEvent
        executeListener: function (id, data) {
            var listener = this.getEventListenerByName(id);
            if (listener !== null) {
                listener.listener.call(listener.listener, data);
            }
        }
    };
    Titanium = Ti;
})();