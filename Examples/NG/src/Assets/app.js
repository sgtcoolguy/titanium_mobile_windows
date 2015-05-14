var Canvas = require("Windows.UI.Xaml.Controls.Canvas"),
    TextBlock = require("Windows.UI.Xaml.Controls.TextBlock"),
    Window = require("Windows.UI.Xaml.Window");

var win = new Canvas();

// Add stuff to the window!
var label = new TextBlock();
label.FontSize = 60;
label.Text = "Hello World!";
// TODO How do I handle enums? When we require a type that references enums, should we hook them into the global namespace?
//label.TextAlignment = Windows.UI.Xaml.TextAlignment.Center;
//label.VerticalAlignment = Windows.UI.Xaml.VerticalAlignment.Center;
//label.HorizontalAlignment = Windows.UI.Xaml.HorizontalAlignment.Center;

win.Children.Append(label);

Window.Current.Content = win;
Window.Current.Activate();
