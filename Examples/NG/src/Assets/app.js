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

label.text = 'quotes go here';
label.color = '#ff00ff';
label.top = 500;
label.left = 10;
//label.width = 145;
//label.height = 50;

var imageView = Ti.UI.createImageView({
    'top': 420,
    'left': 10
});

imageView.image = 'http://iconizer.net/files/IconSweets/orig/email.png';

imageView.top = 420;
imageView.left = 10;

imageView.addEventListener('click', function (e) {
    Ti.API.warn('Image, Art, Faith, Mystery.');
});

var button = Ti.UI.createButton({
});

var button2 = Ti.UI.createButton({
});

var button3 = Ti.UI.createButton({
});

button.title = 'Neeraj Says...';
button2.title = 'Ingo Says...';
button3.title = 'Chris Barber Says...';

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
    'height': 50
});

view.top = 20;
view.left = 10;
view.width = 145;
view.height = 50;
view.backgroundColor = "Red";
view.add(button);

var view2 = Ti.UI.createView({
    'top': 120,
    'left': 110,
    'width': 130,
    'height': 50
});

view2.top = 120;
view2.left = 110;
view2.width = 130;
view2.height = 50;

view2.backgroundColor = "Pink";
view2.add(button2);

var view3 = Ti.UI.createView({
    'top': 220,
    'left': 210,
    'width': 190,
    'height': 50
});

view3.top = 220;
view3.left = 210;
view3.width = 190;
view3.height = 50;

view3.backgroundColor = "Green";
view3.add(button3);

var window = Ti.UI.createWindow({
    'backgroundColor': "Blue"
});
window.backgroundColor = "Blue";
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