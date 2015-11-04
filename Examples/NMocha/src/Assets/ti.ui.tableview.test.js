/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

var should = require('./should');

describe('Titanium.UI.TableView', function () {
    it('Ti.UI.TableView', function (finish) {
        should(Ti.UI.TableView).not.be.undefined;
        finish();
    });
    it('createTableView', function (finish) {

        // Validate createTableView()
        should(Ti.UI.createTableView).not.be.undefined;
        should(Ti.UI.createTableView).be.a.Function;

        // Validate createTableViewSection()
        should(Ti.UI.createTableViewSection).not.be.undefined;
        should(Ti.UI.createTableViewSection).be.a.Function;

        // Validate createTableViewRow()
        should(Ti.UI.createTableViewRow).not.be.undefined;
        should(Ti.UI.createTableViewRow).be.a.Function;

        // Create TableView section
        var section_0 = Ti.UI.createTableViewSection({ headerTitle: 'Zero' });
        should(section_0).be.a.Object;
        should(section_0.apiName).be.a.String;
        should(section_0.apiName).be.eql("Titanium.UI.TableViewSection");

        // Create and add two rows to the section
        section_0.add(Ti.UI.createTableViewRow({ title: 'Red' }));
        section_0.add(Ti.UI.createTableViewRow({ title: 'White' }));
        section_0.add(Ti.UI.createTableViewRow({ title: 'Purple' }));

        // Validate section rowCount
        should(section_0.rowCount).be.eql(3);

        // Validate a section row title
        should(section_0.rows[0].title).be.eql('Red');

        // Create another TableView section
        var section_1 = Ti.UI.createTableViewSection({ headerTitle: 'One' });
        should(section_1).be.a.Object;

        // Create and add three rows to the section
        section_1.add(Ti.UI.createTableViewRow({ title: 'Green' }));
        section_1.add(Ti.UI.createTableViewRow({ title: 'Yellow' }));
        section_1.add(Ti.UI.createTableViewRow({ title: 'Blue' }));

        // Validate section row count
        should(section_1.rowCount).be.eql(3);

        // Validate a section row title
        should(section_1.rows[2].title).be.eql('Blue');
        should(section_1.rows[2].apiName).be.a.String;
        should(section_1.rows[2].apiName).be.eql("Titanium.UI.TableViewRow");

        // Create TableView, set data property
        var tableView = Ti.UI.createTableView({
          data: [section_0]
        });
        should(tableView).be.a.Object;
        should(tableView.apiName).be.a.String;
        should(tableView.apiName).be.eql("Titanium.UI.TableView");

        // Validate tableView section count
        should(tableView.sectionCount).be.eql(1);

        // Append another section
        tableView.appendSection(section_1);

        // Validate tableView section count
        should(tableView.sectionCount).be.eql(2);

        finish();
    });
    
});
