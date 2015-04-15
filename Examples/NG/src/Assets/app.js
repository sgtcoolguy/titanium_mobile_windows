var win = new Windows.UI.Xaml.Controls.Canvas();

// Add stuff to the window!
var label = new Windows.UI.Xaml.Controls.TextBlock();
//label.TextWrapping = Windows.UI.Xaml.TextWrapping.Wrap;
//label.TextTrimming = Windows.UI.Xaml.TextTrimming.Clip;
//label.VerticalAlignment = Windows.UI.Xaml.VerticalAlignment.Center;
label.FontSize = 20;
label.Text = "Hello World!";

win.Children.Append(label);

var rootFrame = Windows.UI.Xaml.Window.Current.Content;
rootFrame.Navigate(Windows.UI.Xaml.Controls.Page.typeid);

var page = rootFrame.Content;
page.Content = win;
