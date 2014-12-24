/**
 * Titanium for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */
'use strict';

var label = Ti.UI.createLabel({
    'text': 'quotes go here',
    'color': '#ff00ff',
    'top': 500,
    'left': 10
});

//label.width = 145;
//label.height = 50;

var imageView = Ti.UI.createImageView({
    'top': 420,
    'left': 10,
    image: 'http://iconizer.net/files/IconSweets/orig/email.png'
});

imageView.addEventListener('click', function (e) {
    Ti.API.warn('Image, Art, Faith, Mystery.');
});

var button = Ti.UI.createButton({
    title: 'Neeraj Says...'
});

var button2 = Ti.UI.createButton({
    title: 'Ingo Says...'
});

var button3 = Ti.UI.createButton({
    title: 'Chris Barber Says...'
});

button.addEventListener('click', function (e) {
    Ti.API.warn('Goals without a timeline are just a dream.');
    label.text = 'Goals without a timeline are just a dream.';
});

button2.addEventListener('click', function (e) {
    Ti.API.info('Your estimation factor is 4X.');
    label.text = 'Your estimation factor is 4X.';
});

button3.addEventListener('click', function (e) {
    Ti.API.info("I am from Santa Clara.");
    label.text = "I am from Santa Clara.";
});

var view = Ti.UI.createView({
    'top': 20,
    'left': 10,
    'width': 145,
    'height': 50,
    backgroundColor: "Red"
});
view.add(button);

var view2 = Ti.UI.createView({
    'top': 120,
    'left': 110,
    'width': 130,
    'height': 50,
    backgroundColor: "Pink"
});
view2.add(button2);

var view3 = Ti.UI.createView({
    'top': 220,
    'left': 210,
    'width': 190,
    'height': 50,
    backgroundColor: 'Green'
});
view3.add(button3);

var window = Ti.UI.createWindow({
    'backgroundColor': "Blue"
});
window.add(label);
window.add(imageView);
window.add(view);
window.add(view2);
window.add(view3);
window.open();

Ti.API.info('app.js running...');

var count = 0;
var timerId = setInterval(function () {
    Ti.API.info('setInterval: timerId = ' + timerId + ', count = ' + count);
    if (++count > 10) {
        clearInterval(timerId);
    }
}, 1000 /* ms */);

Ti.API.info('setInterval: timerId = ' + timerId);