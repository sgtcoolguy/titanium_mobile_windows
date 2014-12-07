/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */


/**
 * Adds properties to a TiProxy's prototype
 * @param (tiObject)    TiProxy object
 * @param (props)       Object with property keys and arrays of boolean to indicate
 *                      if a propery has a setter and/or a getter
 *
 * Example:
 *      Utils.addPropertiesToTiObject(TiProxy, {
 *          name: [true, true],         // creates a setter for the setName() and a getter getName()
 *          hasListener: [false, true]  // only creates a getter since the first arg is "false"
 *      });
 *
 * There is no need to define getter in the proxy if it only returns the value from the setter
 * Only create a getter at the proxy layer if there is no setter or if the getter needs to return
 * a native value that might be different that the setter value
 */
function addPropertiesToObject(ObjectPrototype, props) {
    try {
        var newProps = {};
        var newProp = {};
        var currentProp;
        for (var key in props) {
            currentProp = props[key];
            newProp = {};
            newProp.enumerable = true;
            var capProp = key.charAt(0).toUpperCase() + key.substring(1);
            // Check if it has a setter
            if (currentProp[0]) {
                (function () {
                    var keyCopy = String(key);
                    var setter = 'set' + capProp;
                    if (!(setter in ObjectPrototype)) {
                        throw new Error('Missing setter ' + setter);
                    }
                    newProp.set = function (value) {
                        this.__ti_private__['_' + keyCopy + '_'] = value;
                        this[setter](value);
                    };
                })();
            }
            // Check if it has a getter
            if (currentProp[1]) {
                (function () {
                    var keyCopy = String(key);
                    var getter = 'get' + capProp;
                    // Check if the getter exists, otherwise create one
                    if (!(getter in ObjectPrototype)) {
                        ObjectPrototype[getter] = function () {
                            return this.__ti_private__['_' + keyCopy + '_'];
                        }
                    }
                    newProp.get = function () {
                        return this[getter]();
                    };
                })();
            }
            newProps[key] = newProp;
        }
        Object.defineProperties(ObjectPrototype, newProps);
    } catch (er) {
        console.log(er);
    }
}
exports.addPropertiesToObject = addPropertiesToObject;
exports.addPropertiesToTiObject = function (tiObject, props) {
    addPropertiesToObject(tiObject.prototype, props);
}

/**
 * Delegates getters and setters to a control hanging off the object's __ti_private__ property. This is intended to be used when we generate
 * a parent view and hang children controls off the view but wish certain properties to be delegated/forwarded to the children.
 * @param (composite)   The parent object (typically something like a View instance)
 * @param (control)     The property name (String) of the child control that we're going to delegate parent property's getter/setters to
 * @param (props)       Object with property keys and arrays of boolean to indicate
 *                      if delegated propery has a setter and/or a getter
 *
 * Example:
 *      Utils.delegate(view, 'label', {
 *          name: [true, true],         // creates a setter for the setName() and a getter getName() on view that delegates to view.__ti_private.label.setName()/getName()
 *          hasListener: [false, true]  // only creates a getter since the first arg is "false"
 *      });
 */
exports.delegate = function(composite, control, props) {
    try {
        var currentProp;
        for (var key in props) {
            currentProp = props[key];
            var capProp = key.charAt(0).toUpperCase() + key.substring(1);
            // setter
            if (currentProp[0]) {
                (function () {
                    var keyCopy = String(key);
                    var setter = 'set' + capProp;
                    composite[setter] = function (value) {
                        this.__ti_private__[control][setter](value);
                    };
                })();
            }
            // getter
            if (currentProp[1]) {
                (function () {
                    var keyCopy = String(key);
                    var getter = 'get' + capProp;
                    // Check if the getter exists, otherwise create one
                    composite.__ti_private__[getter] = function () {
                        return this.__ti_private__[control][getter]();
                    };
                })();
            }
        }
    } catch (er) {
        console.log(er);
    }
}
/**
 * Creates the Red Screen Of Death!
 * @param (e) Error or Exception
 */
exports.showError = function (e) {
    console.log('[ERROR] ' + e);
    try {
        var f = e.filename || "",
            match = f.match(/:\/\/.+(\/.*)/),
            filename = match ? match[1] : e.filename,
            line = e.lineno,
            win = Ti.UI.createWindow({
                backgroundColor: "#f00",
                layout: "vertical"
            }),
            view,
            button;

        function makeLabel(text, height, color, fontSize) {
            win.add(Ti.UI.createLabel({
                color: color,
                font: { fontSize: fontSize, fontWeight: "bold" },
                height: height,
                width: Ti.UI.FILL,
                textAlign: 'center', //UI.TEXT_ALIGNMENT_CENTER,
                text: text
            }));
        }

        win.add(view = Ti.UI.createView({ height: "12%" }));
        makeLabel("Application Error", "15%", "#0f0", "34");
        makeLabel((e.message || "Unknown error").trim() + (filename && filename !== "undefined" ? " at " + filename : "") + (line ? " (line " + line + ")" : ""), "45%", "#fff", "26");
        win.add(view = Ti.UI.createView({ height: "12%" }));
        view.add(button = Ti.UI.createButton({ title: "Dismiss" }));
        button.addEventListener("click", function () {
            win.close();
        });

        makeLabel("Error messages will only be displayed during development. When your app is packaged for final distribution, no error screen will appear. Test your code!", "28%", "#000", "20");

        win.open();
    } catch (er) {
        alert(er);
    }
}
