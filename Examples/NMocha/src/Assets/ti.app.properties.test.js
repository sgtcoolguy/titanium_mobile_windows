/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should');

Array.prototype.contains = function (obj) {
    var i = this.length;
    while (i--) if (this[i] === obj) return true;
    return false;
}

describe('Titanium.App.Properties', function () {

    it('getBool default', function (finish) {
        Ti.App.Properties.removeProperty('test_bool');
        should(Ti.App.Properties.getBool('test_bool')).be.eql(false); // iOS returns null, Android returns false
        should(Ti.App.Properties.getBool('test_bool', true)).be.eql(true);
        finish();
    });

    it('set and getBool', function (finish) {
        Ti.App.Properties.setBool('test_bool', true);
        should(Ti.App.Properties.getBool('test_bool')).be.eql(true);
        finish();
    });

    it('setBool on property from tiapp doesnt change value', function (finish) {
    	should(Ti.App.Properties.getBool('presetBool')).be.eql(true);
        Ti.App.Properties.setBool('presetBool', false); // should log warning
        should(Ti.App.Properties.getBool('presetBool')).be.eql(true);
        finish();
    });

    it('getDouble default', function (finish) {
        Ti.App.Properties.removeProperty('test_double');
        should(Ti.App.Properties.getDouble('test_double')).be.eql(0); // iOS returns null, Android returns 0D
        should(Ti.App.Properties.getDouble('test_double', 3.14)).be.eql(3.14);
        finish();
    });

    it('set and getDouble', function (finish) {
        Ti.App.Properties.setDouble('test_double', 1.321);
        should(Ti.App.Properties.getDouble('test_double')).be.eql(1.321);
        finish();
    });

    it('setDouble on property from tiapp doesnt change value', function (finish) {
    	should(Ti.App.Properties.getDouble('presetDouble')).be.eql(1.23456);
        Ti.App.Properties.setDouble('presetDouble', 6.54321); // should log warning
        should(Ti.App.Properties.getDouble('presetDouble')).be.eql(1.23456);
        finish();
    });

    it('getInt default', function (finish) {
        Ti.App.Properties.removeProperty('test_int');
        should(Ti.App.Properties.getInt('test_int')).be.eql(0); // iOS returns null, Android returns 0
        should(Ti.App.Properties.getInt('test_int', 3)).be.eql(3);
        finish();
    });

    it('set and getInt', function (finish) {
        Ti.App.Properties.setInt('test_int', 1);
        should(Ti.App.Properties.getInt('test_int')).be.eql(1);
        finish();
    });

    it('setInt on property from tiapp doesnt change value', function (finish) {
        should(Ti.App.Properties.getInt('presetInt')).be.eql(1337);
        Ti.App.Properties.setInt('presetInt', 666); // should log warning
        should(Ti.App.Properties.getInt('presetInt')).be.eql(1337);
        finish();
    });

    it('List', function (finish) {
        var test_list = ['item1', 'item2', 'item3'];
        Ti.App.Properties.setList('test_list', test_list);
        should(Ti.App.Properties.getList('test_list')).be.eql(test_list);
        finish();
    });

    it('Object', function (finish) {
        var test_object = {item : 'item1'};
        Ti.App.Properties.setObject('test_object', test_object);
        should(Ti.App.Properties.getObject('test_object')).be.eql(test_object);
        finish();
    });

    it('getString default', function (finish) {
        Ti.App.Properties.removeProperty('test_string');
        should(Ti.App.Properties.getString('test_string')).be.eql(null);
        should(Ti.App.Properties.getString('test_string', "defaultString")).be.eql("defaultString");
        finish();
    });

    it('set and getString', function (finish) {
        Ti.App.Properties.setString('test_string', "some test string");
        should(Ti.App.Properties.getString('test_string')).be.eql("some test string");
        finish();
    });

    it('setString on property from tiapp doesnt change value', function (finish) {
    	should(Ti.App.Properties.getString('presetString')).be.eql("Hello!");
        Ti.App.Properties.setString('presetString', "a new value"); // should log warning
        should(Ti.App.Properties.getString('presetString')).be.eql("Hello!");
        finish();
    });

    it('listProperties', function (finish) {
        Ti.App.Properties.setBool('test_property', true);
        var properties = Ti.App.Properties.listProperties();
        should(properties).be.a.Object;
        should(properties.contains('test_property')).be.eql(true);
        finish();
    });

    it('listProperties contains tiapp properties', function (finish) {
        var properties = Ti.App.Properties.listProperties();
        should(properties).be.a.Object;
        should(properties.contains('ti.ui.defaultunit')).be.eql(true);
        should(properties.contains('ti.deploytype')).be.eql(true);
        should(properties.contains('presetBool')).be.eql(true);
        finish();
    });

    it('removeProperty', function (finish) {
        Ti.App.Properties.setBool('test_property', true);
        var properties = Ti.App.Properties.listProperties();
        should(properties).be.a.Object;
        should(properties.contains('test_property')).be.eql(true);
        Ti.App.Properties.removeProperty('test_property');
        properties = Ti.App.Properties.listProperties();
        should(properties.contains('test_property')).be.eql(false);
        finish();
    });

    it('removeProperty doesnt remove properties from tiapp', function (finish) {
        var properties = Ti.App.Properties.listProperties();
        should(properties).be.a.Object;
        should(properties.contains('presetString')).be.eql(true);
        Ti.App.Properties.removeProperty('presetString');
        properties = Ti.App.Properties.listProperties();
        should(properties.contains('presetString')).be.eql(true);
        finish();
    });

    it('hasProperty', function (finish) {
        Ti.App.Properties.removeProperty('test_has_property');
        should(Ti.App.Properties.hasProperty('test_has_property')).be.eql(false);
        Ti.App.Properties.setBool('test_has_property', true);
        should(Ti.App.Properties.hasProperty('test_has_property')).be.eql(true);
        finish();
    });

    it('hasProperty returns true for tiapp properties', function (finish) {
        should(Ti.App.Properties.hasProperty('presetString')).be.eql(true);
        finish();
    });
});