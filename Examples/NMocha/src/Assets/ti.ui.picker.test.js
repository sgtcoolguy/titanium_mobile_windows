/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

var should = require('./should');

describe("Ti.UI.Picker", function() {
	it("DatePicker", function(finish) {
	    this.timeout(5000);
		var date = new Date();
		var win = Ti.UI.createWindow({
			backgroundColor: "#000"
		});
		var picker = Ti.UI.createPicker({
			type: Ti.UI.PICKER_TYPE_DATE,
			value: date
		});
		win.add(picker);
		win.addEventListener('focus', function() {
			should(function() {
				should(picker.getValue()).be.eql(date);
			}).not.throw();
			setTimeout(function() {
				win.close();
				finish();
			}, 1000);
		});
		win.open();
	});
	it("TimePicker", function(finish) {
	    this.timeout(5000);
		var date = new Date();
		var win = Ti.UI.createWindow({
			backgroundColor: "#000"
		});
		var picker = Ti.UI.createPicker({
			type: Ti.UI.PICKER_TYPE_TIME,
			value: date
		});
		win.add(picker);
		win.addEventListener('focus', function() {
			should(function() {
				should(picker.getValue()).be.eql(date);
			}).not.throw();
			setTimeout(function() {
				win.close();
				finish();
			}, 1000);
		});
		win.open();
	});
	it("PlainPicker", function(finish) {
	    this.timeout(5000);
		var win = Ti.UI.createWindow({
			backgroundColor: "#000"
		});
		var picker = Ti.UI.createPicker({
			type: Ti.UI.PICKER_TYPE_PLAIN
		});
		win.add(picker);
		win.addEventListener('focus', function() {
			should(function() {
				should(picker).be.an.Object;
				picker.getValue();
			}).not.throw();
			setTimeout(function() {
				win.close();
				finish();
			}, 1000);
		});
		win.open();
	});
	
});