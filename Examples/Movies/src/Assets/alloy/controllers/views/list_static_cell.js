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
    this.__controllerPath = "views/list_static_cell";
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
    $.__views.cell = Ti.UI.createView({
        top: 10,
        left: 10,
        bottom: 10,
        width: Alloy.Globals.layout.lists.cell.width,
        height: Alloy.Globals.layout.lists.cell.height,
        backgroundColor: "#b0332a",
        clipMode: true,
        id: "cell"
    });
    $.__views.cell && $.addTopLevelView($.__views.cell);
    $.__views.imageview = Ti.UI.createImageView({
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        preventDefaultImage: true,
        touchEnabled: false,
        id: "imageview"
    });
    $.__views.cell.add($.__views.imageview);
    $.__views.title_label = Ti.UI.createLabel({
        left: 4,
        right: 4,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        font: {
            fontSize: 48,
            fontFamily: "FontAwesome"
        },
        textAlign: "center",
        color: "#ffffff",
        touchEnabled: false,
        id: "title_label"
    });
    $.__views.cell.add($.__views.title_label);
    $.__views.overlay_view = Ti.UI.createView({
        backgroundColor: "#ffffff",
        opacity: 0,
        touchEnabled: false,
        id: "overlay_view"
    });
    $.__views.cell.add($.__views.overlay_view);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var animation = require("animation");
    arguments[0] || {};
    $.animateClick = function(callback) {
        animation.flash($.overlay_view, callback);
    };
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;