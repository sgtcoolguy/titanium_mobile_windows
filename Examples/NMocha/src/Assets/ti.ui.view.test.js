/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

require('ti-mocha');
var should = require('should');

describe("Titanium.UI.View", function () {

    it("hide() and show() change visible property value", function (finish) {
        this.timeout(5000);
        var w = Ti.UI.createWindow({
            backgroundColor: 'blue',
            width: 100,
            height: 100
        });
       
        w.addEventListener('focus', function () {
            Ti.API.info("Got focus event");
            should(w.visible).be.true;
            Ti.API.info("Was visible");
            w.hide();
            should(w.visible).be.false;
            Ti.API.info("Was not visible after hide()");
            w.show();
            should(w.visible).be.true;
            Ti.API.info("Was visible after show()");
            setTimeout(function () {
                w.close();
                finish();
            }, 1000);
        });
        w.open();
    });
});
