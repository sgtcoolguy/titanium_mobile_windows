var Alloy = require("alloy"), _ = Alloy._, Backbone = Alloy.Backbone;

Alloy.Globals.HQ = {
    latitude: 37.389505,
    longitude: -122.050252,
    name: "Appcelerator"
};

Alloy.Globals.App = {
    Settings: {
        menuWidth: "70%"
    },
    SDK: {
        version: true && Ti.version,
        versionMajor: true && parseInt(Ti.version.split(".")[0], 10),
        versionMinor: true && parseInt(Ti.version.split(".")[1], 10)
    },
    Device: {
        version: Ti.Platform.version,
        versionMajor: true && parseInt(Ti.Platform.version.split(".")[0], 10),
        versionMinor: true && parseInt(Ti.Platform.version.split(".")[1], 10),
        width: null,
        height: null,
        //dpi: Ti.Platform.displayCaps.dpi, // FIXME TIMOB-18458
        orientation: Ti.Gesture.orientation == Ti.UI.LANDSCAPE_LEFT || Ti.Gesture.orientation == Ti.UI.LANDSCAPE_RIGHT ? "landscape" : "portrait"
    },
    Navigator: {
        currentWindow: null,
        navGroup: null,
        open: function(controller, payload) {
            var view = Alloy.createController(controller, payload || {}).getView();
            var win = Alloy.Globals.App.Navigator.currentWindow = Ti.UI.createWindow({
                title: view.title || "",
                titleAttributes: {
                    color: "#C41230"
                },
                fullscreen: null,
                backgroundColor: "#fff",
                navTintColor: "C41230"
            });
            win.add(view);
            this.navGroup.openWindow(win, {
                animated: true
            });
        },
        modal: function(_controller, _options) {
            Ti.API.info("MODAL");
            if (_controller) {
                var modalWin = Ti.UI.createWindow({
                    modal: true,
                    title: "Bookmarks",
                    width: Ti.UI.FILL,
                    height: "60%",
                    bottom: 0,
                    backgroundColor: "transparent"
                });
                var modalController = Alloy.createController(_controller, _options);
                modalWin.add(modalController.getView());
                modalController.getView().addEventListener("close", function() {
                    modalWin.close();
                });
                modalWin.open();
            } else Ti.API.error("Mandatory parameter '_controller' not specified");
        }
    },
    init: function(params) {
        true && params.navGroup && (this.Navigator.navGroup = params.navGroup);
    }
};

Alloy.createController("index");