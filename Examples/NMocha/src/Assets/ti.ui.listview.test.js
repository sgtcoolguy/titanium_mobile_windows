/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

var should = require('./should');

describe('Titanium.UI.ListView', function () {
    it('Ti.UI.ListView', function (finish) {
        should(Ti.UI.ListView).not.be.undefined;
        finish();
    });
    it('createListView', function (finish) {
        
        // Validate createListView()
        should(Ti.UI.createListView).not.be.undefined;
        should(Ti.UI.createListView).be.a.Function;

        // Create ListView
        var listView = Ti.UI.createListView();
        should(listView).be.a.Object;
        should(listView.apiName).be.a.String;
        should(listView.apiName).be.eql("Titanium.UI.ListView");

        // Create list section
        var section_0 = Ti.UI.createListSection({ headerTitle: 'Zero'});
        should(section_0).be.a.Object;

        // Set section items
        var section_0_set = [
            {properties: { title: 'Red'}},
            {properties: { title: 'White'}}
        ];
        section_0.setItems(section_0_set);
        should(section_0.items.length).be.eql(2);

        // Append item to section
        section_0.appendItems([{properties: { title: 'Purple'}}]);

        // Validate section items length
        should(section_0.items.length).be.eql(3);

        // Create list section
        var section_1 = Ti.UI.createListSection({ headerTitle: 'One'});
        should(section_1).be.a.Object;

        // Set section items
        var section_1_set = [
            {properties: { title: 'Green'}},
            {properties: { title: 'Yellow'}},
            {properties: { title: 'Blue'}}
        ];
        section_1.setItems(section_1_set);
        should(section_1.items.length).be.eql(3);

        // Set listView sections
        listView.sections = [section_0];

        // Validate listView section count
        should(listView.sectionCount).be.eql(1);

        // Apend section to listView
        listView.appendSection([section_1]);

        // Validate listView section count
        should(listView.sectionCount).be.eql(2);

        finish();
    });
    
});
