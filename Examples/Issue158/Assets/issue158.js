/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

require('ti-mocha');
var should = require('should');

describe("cache", function () {
	
	// Make sure to clear garbage on each test
	beforeEach(function () {
		Ti.GC();
	});
	
	it("test1", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test2", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test3", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test4", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test5", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test6", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test7", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test8", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test9", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test10", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
	it("test11", function (finish) {
		var label = Ti.UI.createLabel({
			text: "this is some text"
		});
		should(label).be.an.Object;
		finish();
	});
});
