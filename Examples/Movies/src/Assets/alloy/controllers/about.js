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
    this.__controllerPath = "about";
    this.args = arguments[0] || {};
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
    $.__views.about = Ti.UI.createView({
        backgroundColor: "#66000000",
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        opacity: 0,
        id: "about"
    });
    $.__views.about && $.addTopLevelView($.__views.about);
    $.__views.__alloyId0 = Ti.UI.createView({
        layout: "vertical",
        width: Alloy.Globals.layout.overlay.width,
        height: Ti.UI.SIZE,
        id: "__alloyId0"
    });
    $.__views.about.add($.__views.__alloyId0);
    $.__views.__alloyId1 = Ti.UI.createImageView({
        width: 100,
        height: 100,
        image: "/logo.png",
        id: "__alloyId1"
    });
    $.__views.__alloyId0.add($.__views.__alloyId1);
    $.__views.__alloyId2 = Ti.UI.createLabel({
        top: 20,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 20,
            fontFamily: "HelveticaNeue-Light"
        },
        color: "#ffffff",
        text: "Movies",
        id: "__alloyId2"
    });
    $.__views.__alloyId0.add($.__views.__alloyId2);
    $.__views.__alloyId3 = Ti.UI.createLabel({
        top: 10,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue-Light"
        },
        color: "#bbffffff",
        text: "Appcelerator",
        id: "__alloyId3"
    });
    $.__views.__alloyId0.add($.__views.__alloyId3);
    $.__views.__alloyId4 = Ti.UI.createLabel({
        top: 40,
        left: 20,
        right: 20,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue-Light"
        },
        color: "#99ffffff",
        textAlign: Titanium.UI.TEXT_ALIGNMENT_CENTER,
        text: "Data from The Movie Database\n\nClapperboard by Fabio Grande from The Noun Project",
        id: "__alloyId4"
    });
    $.__views.__alloyId0.add($.__views.__alloyId4);
    $.__views.__alloyId5 = Ti.UI.createImageView({
        top: 40,
        width: 50,
        height: 38,
        image: "/appcelerator_logo.png",
        id: "__alloyId5"
    });
    $.__views.__alloyId0.add($.__views.__alloyId5);
    exports.destroy = function() {};
    _.extend($, $.__views);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;