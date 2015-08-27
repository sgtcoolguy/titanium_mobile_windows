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
    this.__controllerPath = "views/movies_list_cell";
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
    $.__views.container = Ti.UI.createTableViewRow({
        layout: "Absolute",
        top: 0,
        left: 0,
        height: Alloy.Globals.layout.list.row.height,
        backgroundColor: "#000000",
        id: "container"
    });
    $.__views.container && $.addTopLevelView($.__views.container);
    $.__views.scrollview = Ti.UI.createScrollView({
        contentWidth: "auto",
        contentHeight: "auto",
        scrollingEnabled: false,
        scrollType: "vertical",
        id: "scrollview"
    });
    $.__views.container.add($.__views.scrollview);
    $.__views.thumbnail_imageview = Ti.UI.createImageView({
        top: 0,
        bottom: 0,
        left: 0,
        right: 0,
        width: Alloy.Globals.layout.list.row.width,
        height: Alloy.Globals.layout.list.row.imageHeight,
        preventDefaultImage: true,
        id: "thumbnail_imageview"
    });
    $.__views.scrollview.add($.__views.thumbnail_imageview);
    $.__views.gradient_view = Ti.UI.createView({
        top: 0,
        left: 0,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        backgroundGradient: {
            type: "linear",
            startPoint: {
                x: "0%",
                y: "0%"
            },
            endPoint: {
                x: "0%",
                y: "100%"
            },
            colors: [ {
                color: "#00000000",
                offset: 0
            }, {
                color: "#99000000",
                offset: 1
            } ]
        },
        id: "gradient_view"
    });
    $.__views.container.add($.__views.gradient_view);
    $.__views.title_label = Ti.UI.createLabel({
        bottom: 6,
        left: 6,
        right: 6,
        width: Titanium.UI.SIZE,
        font: {
            fontSize: 22,
            fontFamily: "HelveticaNeue-Bold"
        },
        color: "#ffffff",
        id: "title_label",
        text: "A Title"
    });
    $.__views.container.add($.__views.title_label);
    $.__views.overlay_view = Ti.UI.createView({
        backgroundColor: "#ffffff",
        opacity: 0,
        id: "overlay_view"
    });
    $.__views.container.add($.__views.overlay_view);
    $.__views.separator = Ti.UI.createView({
        bottom: 0,
        left: 0,
        right: 0,
        height: .5,
        backgroundColor: "#ffffff",
        id: "separator"
    });
    $.__views.container.add($.__views.separator);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var animation = require("animation");
    exports.animateClick = function(callback) {
        animation.flash($.overlay_view, callback);
    };
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;