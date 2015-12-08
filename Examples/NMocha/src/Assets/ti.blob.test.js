/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should');

describe("Titanium.Blob", function () {

    it.skip("constructed from File.read()", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob).be.an.Object;
        should(blob).be.an.instanceof(Ti.Blob);
        should(blob.apiName).be.eql("Titanium.Blob");
        finish();
    });
    it.skip("constructed from image", function (finish) {
        var window = Ti.UI.createWindow();
        var label = Ti.UI.createLabel({ text: 'test' });
        window.add(label);
        window.addEventListener('focus', function () {
            var blob = label.toImage(function (blob) {
                should(blob).be.an.Object;
                should(blob).be.an.instanceof(Ti.Blob);
                should(blob.getText() === null).be.eql(true);
                should(blob.width).be.a.Number;
                should(blob.width > 0).be.true;
                should(blob.height).be.a.Number;
                should(blob.height > 0).be.true;
                should(blob.length).be.a.Number;
                should(blob.size).be.a.Number;
                should(blob.size == (blob.width * blob.height));
                window.close();
                finish();
            });
        });
        window.open();
    });
    it("text", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.text).be.a.String;
        should(blob.text.length > 0).be.true;
        should(blob.text == blob.toString());
        finish();
    });
    it("append", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        if (Ti.Platform.osname == 'iphone' || Ti.Platform.osname == 'ipad') {
            should(blob.append).be.undefined;
        } else {
            should(blob.append).be.a.Function;
        }
        finish();
    });
    it("nativePath", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.nativePath).be.a.String;
        should(blob.nativePath.length > 0).be.true;
        finish();
    });
    it("mimeType", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.mimeType).be.a.String;
        should(blob.mimeType.length > 0).be.true;
        should(blob.mimeType).be.eql("text/javascript");
        finish();
    });
    it("length", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.length).be.a.Number;
        should(blob.length > 0).be.true;
        finish();
    });
    it("size", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.size).be.a.Number;
        should(blob.size > 0).be.true;
        finish();
    });
    it("width", function (finish) {
        var blob = Ti.Filesystem.getFile('Logo.png').read();
        should(blob.width).be.a.Number;
        should(blob.width).be.eql(150);
        finish();
    });
    it("height", function (finish) {
        var blob = Ti.Filesystem.getFile('Logo.png').read();
        should(blob.height).be.a.Number;
        should(blob.height).be.eql(150);
        finish();
    });
    it("file", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        var file = blob.file;
        should(file.toString()).be.a.String;
        should(file.nativePath).be.eql(blob.nativePath);
        finish();
    });
    it.skip("imageAsCropped", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageAsCropped).be.a.Function;
        finish();
    });
    it.skip("imageAsResized", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageAsResized).be.a.Function;
        finish();
    });
    it.skip("imageAsThumbnail", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageAsThumbnail).be.a.Function;
        finish();
    });
    it.skip("imageWithAlpha", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageWithAlpha).be.a.Function;
        finish();
    });
    it.skip("imageWithRoundedCorner", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageWithRoundedCorner).be.a.Function;
        finish();
    });
    it.skip("imageWithTransparentBorder", function (finish) {
        var blob = Ti.Filesystem.getFile('app.js').read();
        should(blob.imageWithTransparentBorder).be.a.Function;
        finish();
    });
});
