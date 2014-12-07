var win = Ti.UI.createWindow();

var btn = Ti.UI.createButton({
	title: 'here'
});

win.add(btn);

btn.addEventListener('click', function () {
	var a = Ti.UI.createAlertDialog({title: 'title', message: 'message', buttonNames: ['ok', 'cancel']});
	a.addEventListener('click', function () {
		Ti.API.info('Alert clicked!!!');
	});
	
	a.show();
	setTimeout(function () {
		Ti.GC();
		Ti.API.info('Garbage collection called');
	}, 1000);
});

var statisticsButton = Ti.UI.createButton({
	title: 'Statistics',
	top: 20,
	bottom: 20,
	width: 200,
	height: Ti.UI.SIZE
});

statisticsButton.addEventListener('click', function (e) {
	var statistics = Ti.Platform.statistics;
	Ti.API.info('TiValue: ' + statistics.TiValue_ctor_count + ' created, ' + statistics.TiValue_dtor_count + ' destroyed');
	Ti.API.info('BaseProxy: ' + statistics.BaseProxy_ctor_count + ' created, ' + statistics.BaseProxy_dtor_count + ' destroyed');
});

win.add(statisticsButton);

win.open();
