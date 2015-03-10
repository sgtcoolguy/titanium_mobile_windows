// this sets the background color of the master UIView (when there are no windows/tab groups on it)
Titanium.UI.setBackgroundColor('#000');

// create tab group
var tabGroup = Titanium.UI.createTabGroup();


//
// create base UI tab and root window
//
var win1 = Titanium.UI.createWindow({
    title: 'Tab 1',
    backgroundColor: 'Blue'
});
var tab1 = Titanium.UI.createTab({
    icon: 'KS_nav_views.png',
    title: 'Tab 1',
    window: win1
});

var textField = Ti.UI.createTextField({
    top: 290,
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
win1.add(textField);

var label = Ti.UI.createLabel({
    'text': 'quotes go here',
    'color': '#ff00ff',
    'top': 500,
    'left': 10
});

var imageView = Ti.UI.createImageView({
    'top': 420,
    'left': 10,
    image: 'http://iconizer.net/files/IconSweets/orig/email.png'
});

imageView.addEventListener('click', function (e) {
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
    alert('Goals without a timeline are just a dream.');
    label.text = 'Goals without a timeline are just a dream.';
});

button2.addEventListener('click', function (e) {
    alert('Your estimation factor is 4X.');
    label.text = 'Your estimation factor is 4X.';
});

button3.addEventListener('click', function (e) {
    alert("I am from Santa Clara.");
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

win1.add(label);
win1.add(imageView);
win1.add(view);
win1.add(view2);
win1.add(view3);


//
// create controls tab and root window
//
var win2 = Titanium.UI.createWindow({
    title: 'Tab 2',
    backgroundColor: '#fff'
});
var tab2 = Titanium.UI.createTab({
    icon: 'KS_nav_ui.png',
    title: 'Tab 2',
    window: win2
});

var slider = Ti.UI.createSlider({ left: '20px', right: 20, backgroundColor: 'green' });
slider.addEventListener('change', function (e) {
    btn.title = 'Slider value: ' + e.value;
});
win2.add(slider);


//
//  add tabs
//
tabGroup.addTab(tab1);
tabGroup.addTab(tab2);

// open tab group
tabGroup.open();

Ti.API.info('app.js running...');

Ti.API.info("Sending Basic HTTP Get Request...");

var url = "http://www.appcelerator.com";
var client = Ti.Network.createHTTPClient({
    // function called when the response data is available
    onload: function (e) {
        Ti.API.info("Response code: " + this.statusText);
        Ti.API.info("Received text: " + this.responseText);
        //alert('success');
    },
    onerror: function (e) {
        Ti.API.info("Response code: " + this.statusText);
        Ti.API.debug(e.error);
        //alert('error');
    },
    timeout: 10000
});

// Prepare the connection.
client.open("GET", url);
// Send the request.
client.send();



var count = 0;
var timerId = setInterval(function () {
    Ti.API.info('setInterval: timerId = ' + timerId + ', count = ' + count);
    if (++count > 10) {
        clearInterval(timerId);

        Ti.Analytics.featureEvent("my.event");
    }
}, 1000 /* ms */);

Ti.API.info('setInterval: timerId = ' + timerId);
