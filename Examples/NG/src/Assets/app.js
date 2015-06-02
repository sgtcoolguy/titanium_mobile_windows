var Window = require('Windows.UI.Xaml.Window'),
    TextBlock = require('Windows.UI.Xaml.Controls.TextBlock'),
    window = Window.Current,
	text = new TextBlock();

text.Text = "Hello, world!";
//text.TextAlignment = TextAlignment.Center;
//text.VerticalAlignment = VerticalAlignment.Center;
//text.HorizontalAlignment = HorizontalAlignment.Center;
text.FontSize = 60;

window.Content = text;
window.Activate();