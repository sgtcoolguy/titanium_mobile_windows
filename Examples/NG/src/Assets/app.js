var win = new Windows.UI.Xaml.Controls.Canvas();

// Add stuff to the window!
var label = new Windows.UI.Xaml.Controls.TextBlock();
label.FontSize = 60;
label.Text = "Hello World!";
//label.TextAlignment = Windows.UI.Xaml.TextAlignment.Center;
//label.VerticalAlignment = Windows.UI.Xaml.VerticalAlignment.Center;
//label.HorizontalAlignment = Windows.UI.Xaml.HorizontalAlignment.Center;

win.Children.Append(label);

Windows.UI.Xaml.Window.Current.Content = win;
Windows.UI.Xaml.Window.Current.Activate();
