var win = Ti.UI.createWindow();

var imageView = Ti.UI.createImageView({
	image: 'images/photo.png'
});

imageView.addEventListener('click', function(){
	alert('ImageView Clicked')
});

win.add(imageButton);
win.open();