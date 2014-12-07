// 'foo' module test
var Foo = require('foo');
Foo.saySomething('really cool!');

// 'require' cache test
var Foo_cached = require('foo');
Ti.API.info('require cache test...should be true => ' + (Foo == Foo_cached));

var win = Ti.UI.createWindow();
win.setBackgroundColor('#aaa');

var view = Ti.UI.createView({
    top: 500,
    left: 50,
    width: 300,
    height: Ti.UI.SIZE
});
var btn = Ti.UI.createButton({
    title: 'pedro',
    color: 'black',
    top: 20,
    bottom: 20,
    width: 200,
    height: Ti.UI.SIZE,
    backgroundColor: 'yellow'
});
view.setBackgroundColor('blue');
view.add(btn);

win.add(view);
view.addEventListener('touchstart', function (e) {
    Ti.API.info('TouchStart');
});
view.addEventListener('touchmove', function (e) {
    view.left = Number(view.left) + e.delta.x;
    view.top = Number(view.top) + e.delta.y;
});
view.addEventListener('touchend', function (e) {
    Ti.API.info('TouchEnd');
});
view.addEventListener('click', function (e) {
    Ti.API.info('Click');
});
var self = this;
btn.addEventListener('click', function (e) {
    alert('Button Clicked!');
});
var num = 0;
var myInterval = setInterval(function () {
    btn.title = 'title ' + (num++);
    if (num > 20) {
        clearInterval(myInterval);
    }
}, 500 /* ms */);

var statisticsButton = Ti.UI.createButton({
    title: 'Statistics',
    color: 'black',
    top: 20,
    bottom: 20,
    width: 200,
    height: Ti.UI.SIZE
    //backgroundColor: 'yellow'
});
statisticsButton.addEventListener('click', function (e) {
    var statistics = Ti.Platform.statistics;
    Ti.API.info('TiValue: ' + statistics.TiValue_ctor_count + ' created, ' + statistics.TiValue_dtor_count + ' destroyed');
    Ti.API.info('BaseProxy: ' + statistics.BaseProxy_ctor_count + ' created, ' + statistics.BaseProxy_dtor_count + ' destroyed');
});
win.add(statisticsButton);

var textField = Ti.UI.createTextField({
    top: 70,
    width: 200
});
textField.addEventListener('change', function (e) {
    Ti.API.info('The text field changed: ' + e.value);
});
textField.addEventListener('blur', function (e) {
    Ti.API.info('The text field lost focus!');
});
textField.addEventListener('focus', function (e) {
    Ti.API.info('The text field gained focus!');
});
textField.addEventListener('return', function (e) {
    Ti.API.info('The text field return key was hit!');
});
win.add(textField);

var indicatorButton = Ti.UI.createButton({
    title: 'Indicator',
    color: 'black',
    top: 120,
    width: 200,
    height: Ti.UI.SIZE
});
indicatorButton.addEventListener('click', function (e) {
    Ti.API.info('Creating activity indicator');
    var indicator = Ti.UI.createActivityIndicator({
        color: 'black',
        message: 'Loading...',
        top: 210,
        indicatorColor: 'red'
    });
    win.add(indicator);
    indicator.show();
    setTimeout(function(){ indicator.hide(); }, 2500);
});
win.add(indicatorButton);

var progressBar = Ti.UI.createProgressBar({
    message: 'Testing...',
    color: 'black',
    max: 100,
    min: 0,
    value: 0,
    width: 200,
    height: Ti.UI.SIZE,
    top: 170
});
setInterval(function () { progressBar.value += 1; if (progressBar.value == progressBar.max) { clearInterval(this); progressBar.hide(); } }, 500);
setTimeout(function () { progressBar.show(); }, 1500);
win.add(progressBar);

var imagesView = Ti.UI.createView({
    top: 190,
    layout: 'horizontal',
    width: 200,
    left: 100
});
// image view that opens email dialog on click
var emailButton = Ti.UI.createImageView({
    image: 'http://iconizer.net/files/IconSweets/orig/email.png',
});
emailButton.addEventListener('click', function (e) {
    var emailDialog = Ti.UI.createEmailDialog({
        toRecipients: ['me@example.com'],
        subject: 'My Subject',
        messageBody: "This is an example email"
    });
    emailDialog.addEventListener('complete', function (e) {
        Ti.API.info("Email sent!");   
    })
    emailDialog.open();
});
imagesView.add(emailButton);

var notifyButton = Ti.UI.createImageView({
    image: 'http://pkp.sfu.ca/support/forum/images/smilies/icon_exclaim.gif',
});
notifyButton.addEventListener('click', function (e) {
    Ti.API.info("showing notification...");
    var toast = Ti.UI.createNotification({
        message: "Please Stand By",
        duration: Ti.UI.NOTIFICATION_DURATION_LONG
    });
    toast.show();
});
imagesView.add(notifyButton);
win.add(imagesView);

var slider = Ti.UI.createSlider({ left: '20px', right: 20, backgroundColor: 'green' });
slider.addEventListener('change', function (e) {
    btn.title = 'Slider value: ' + e.value;
});
win.add(slider);

win.open();
Ti.API.info('DONE LOADING!');
