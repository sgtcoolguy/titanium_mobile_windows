var win = Ti.UI.createWindow({
	backgroundColor: 'blue'
});

var btn = Ti.UI.createButton({
	title: 'open'
});

win.add(btn);

btn.addEventListener('click', function () {
	var w = Ti.UI.createWindow({
		backgroundColor: 'red'
	});
	
	w.open();
	
	setTimeout(function () {
		Ti.GC();
		w.close();
		w = null;
	}, 500);
});

win.open();
