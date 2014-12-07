// Touches Application Sample

console.log("MDL: Hello, world.");

var win = Ti.UI.createWindow();

var view1 = Ti.UI.createView();
view1.setBackgroundColor('yellow');
view1.top = 50;
view1.left = 50;
view1.width = 200;
view1.height = 300;

var view2 = Ti.UI.createView();
view2.setBackgroundColor('green');
view2.top = 50;
view2.left = 350;
view2.width = 200;
view2.height = 300;

var view3 = Ti.UI.createView();
view3.setBackgroundColor('red');
view3.top = 50;
view3.left = 650;
view3.width = 200;
view3.height = 300;

win.add(view1);
win.add(view2);
win.add(view3);

view1.addEventListener('touchmove', function (e) {

    this.top += e.y;
    this.left += e.x;

});

win.open();
