/*
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var should = require('./should');

describe('Ti.App.Windows.BackgroundService', function () {

    it('API', function (finish) {
        should(Ti.App.Windows).be.an.Object;
        should(Ti.App.Windows.BackgroundService).be.an.Object;
        should(Ti.App.Windows.BackgroundService.registerTimerTask).be.a.Function;
        should(Ti.App.Windows.BackgroundService.unregisterAllTasks).be.a.Function;
        finish();
    });

    it('locationServiceEnabled', function (finish) {
        should(Ti.App.Windows.BackgroundService.locationServiceEnabled).be.Boolean;
        Ti.App.Windows.BackgroundService.locationServiceEnabled = true;
        should(Ti.App.Windows.BackgroundService.locationServiceEnabled).be.true;
        Ti.App.Windows.BackgroundService.locationServiceEnabled = false;
        should(Ti.App.Windows.BackgroundService.locationServiceEnabled).be.false;
        finish();
    });

    it('registerTimerTask', function (finish) {
        var task = Ti.App.Windows.BackgroundService.registerTimerTask(function() {
            Ti.API.info('registerTimerTask');
        }, 15, true);
        task.unregister();
        finish();
    });

    it('unregisterAllTasks', function (finish) {
        var task = Ti.App.Windows.BackgroundService.registerTimerTask(function() {
            Ti.API.info('unregisterAllTasks');
        }, 15, true);
        Ti.App.Windows.BackgroundService.unregisterAllTasks();
        finish();
    });

});
