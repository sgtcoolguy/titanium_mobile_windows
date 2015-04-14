var win = Titanium.UI.createWindow({});

var view = Ti.UI.createView({
    top: 20,
    left: 10,
    width: 345,
    height: 600,
    backgroundColor: "red"
});

var imageView = Ti.UI.createImageView({
    opacity: 0.0,
    image: 'http://iconizer.net/files/IconSweets/orig/email.png'
});
view.add(imageView);
win.add(view);
win.open();

Ti.API.info('app.js running...');

var point = Windows.Foundation.Point();
Ti.API.info('point');