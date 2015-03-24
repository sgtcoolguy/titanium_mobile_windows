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

Ti.API.info('animating opacity...');
imageView.animate({
    opacity: 1,
    autoreverse: true,
    repeat: 2,
    duration: 5000,
    delay: 2000
}, function () {
    Ti.API.info('Done with opacity animation.');
    view.animate({
        backgroundColor: 'blue',
        autoreverse: true,
        duration: 5000
    }, function () {
        Ti.API.info('Done with backgroundColor animation.');
        view.animate({
            top: 100,
            duration: 5000
        }, function () {
            Ti.API.info('Done with top animation.');
            view.animate({
                left: 100,
                duration: 5000
            }, function () {
                Ti.API.info('Done with left animation.');
            });
        });
    });
});

