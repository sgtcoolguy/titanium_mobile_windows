var win = Ti.UI.createWindow({
    backgroundColor: 'green'
});

var label = Ti.UI.createLabel({
    font: { fontSize: 50 },
    text: 'Titanium',
    textAlign: 'center',
    top: 100,
    color: 'black'
});
win.add(label);

var button = Ti.UI.createButton({
    title: 'Animate',
    width: 200,
    height: 40,
    color: 'black'
});
win.add(button);

button.addEventListener('click', function () {
    var t1 = Ti.UI.create2DMatrix({
        rotate: 45
    });
    Ti.API.info(t1.a);
    Ti.API.info(t1.b);
    Ti.API.info(t1.c);
    Ti.API.info(t1.d);
    var a1 = Ti.UI.createAnimation();
    a1.transform = t1;
    a1.duration = 800;
    label.animate(a1);
});
win.open();