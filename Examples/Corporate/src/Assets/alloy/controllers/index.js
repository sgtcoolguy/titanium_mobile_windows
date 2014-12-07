function __processArg(obj, key) {
    var arg = null;
    if (obj) {
        arg = obj[key] || null;
        delete obj[key];
    }
    return arg;
}

function Controller() {
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "index";
    if (arguments[0]) {
        {
            __processArg(arguments[0], "__parentSymbol");
        }
        {
            __processArg(arguments[0], "$model");
        }
        {
            __processArg(arguments[0], "__itemTemplate");
        }
    }
    var $ = this;
    var exports = {};
    $.__views.__alloyId31 = Ti.UI.createWindow({
        backgroundColor: "#fff",
        titleAttributes: {
            color: "#C41230"
        },
        title: "Directory",
        id: "__alloyId31"
    });
    $.__views.logo = Ti.UI.createLabel({
        text: "",
        color: "#C41230",
        font: {
            fontFamily: "icomoon",
            fontSize: 36
        },
        id: "logo"
    });
    $.__views.__alloyId31.leftNavButton = $.__views.logo;
    $.__views.__alloyId33 = Alloy.createController("directory", {
        id: "__alloyId33",
        __parentSymbol: $.__views.__alloyId31
    });
    $.__views.__alloyId33.setParent($.__views.__alloyId31);
    $.__views.nav = Ti.UI.iOS.createNavigationWindow({
        backgroundColor: "#fff",
        orientationModes: [ Ti.UI.PORTRAIT, Ti.UI.LANDSCAPE_LEFT, Ti.UI.LANDSCAPE_RIGHT, Ti.UI.UPSIDE_PORTRAIT ],
        navBarHidden: true,
        exitOnClose: true,
        navTintColor: "#ae331f",
        window: $.__views.__alloyId31,
        id: "nav"
    });
    $.__views.nav && $.addTopLevelView($.__views.nav);
    exports.destroy = function() {};
    _.extend($, $.__views);
    Alloy.Globals.App.init({
        navGroup: $.nav
    });
    $.nav.open();
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;