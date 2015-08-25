var win,
    TextBlock = require('Windows.UI.Xaml.Controls.TextBlock'),
	text = new TextBlock();

text.Text = "Hello, world!";
//text.TextAlignment = TextAlignment.Center;
//text.VerticalAlignment = VerticalAlignment.Center;
//text.HorizontalAlignment = HorizontalAlignment.Center;
text.FontSize = 60;

win = Ti.UI.createWindow({});
win.add(text);
win.open();