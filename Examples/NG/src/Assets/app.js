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


var label = Ti.UI.createLabel({
    'text': 'quotes go here',
    'color': '#ff00ff',
    'top': 500,
    'left': 10,
    width: Ti.UI.FILL
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

var ring = Ti.UI.createActivityIndicator({
    top:  200,
    left: 20,
    message: 'Loading...will be closed in 5 seconds'
});
ring.show();

setTimeout(function () {
    ring.hide();
}, 5000);

var button1 = Ti.UI.createButton({
    top:  20,
    left: 10,
    title: 'Show Alert',
    backgroundColor: 'Green'
});

button1.addEventListener('click', function (e) {
    alert('Lorem ipsum dolor sit amet');
    label.text = 'Lorem ipsum dolor sit amet';
});

win1.add(label);
win1.add(imageView);
win1.add(button1);
win1.add(ring);

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

var slider = Ti.UI.createSlider({ left: 20, right: 20, backgroundColor: 'green' });
slider.addEventListener('change', function (e) {
    Ti.API.info('Slider value: ' + e.value);
});
win2.add(slider);

//
//  add tabs
//
tabGroup.addTab(tab1);
tabGroup.addTab(tab2);

// open tab group
tabGroup.open();
