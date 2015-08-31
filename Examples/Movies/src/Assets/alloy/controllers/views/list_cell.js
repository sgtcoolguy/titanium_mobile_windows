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
    this.__controllerPath = "views/list_cell";
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
        width: Alloy.Globals.layout.lists.cell.width,
        height: Alloy.Globals.layout.lists.cell.height,
        backgroundColor: "#333333",
        clipMode: true,
        id: "cell"
    });
    $.__views.cell && $.addTopLevelView($.__views.cell);
    $.__views.image = Ti.UI.createView({
        top: Alloy.Globals.layout.lists.cell.imageTop,
        left: Alloy.Globals.layout.lists.cell.imageLeft,
        width: Alloy.Globals.layout.lists.cell.imageWidth,
        height: Alloy.Globals.layout.lists.cell.imageHeight,
        touchEnabled: false,
        id: "image"
    });
    $.__views.cell.add($.__views.image);
    $.__views.imageview = Ti.UI.createImageView({
        width: Alloy.Globals.layout.lists.cell.imageWidth,
        height: Alloy.Globals.layout.lists.cell.imageHeight,
        preventDefaultImage: true,
        touchEnabled: false,
        zIndex: 0,
        id: "imageview"
    });
    $.__views.image.add($.__views.imageview);
    $.__views.imageview1 = Ti.UI.createImageView({
        width: Alloy.Globals.layout.lists.cell.imageWidth,
        height: Alloy.Globals.layout.lists.cell.imageHeight,
        preventDefaultImage: true,
        touchEnabled: false,
        zIndex: 1,
        opacity: 0,
        id: "imageview1"
    });
    $.__views.image.add($.__views.imageview1);
    $.__views.__alloyId12 = Ti.UI.createView({
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
                color: "#33000000",
                offset: 0
            }, {
                color: "#aa000000",
                offset: 1
            } ]
        },
        touchEnabled: false,
        id: "__alloyId12"
    });
    $.__views.cell.add($.__views.__alloyId12);
    $.__views.title_label = Ti.UI.createLabel({
        left: 4,
        right: 4,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        font: {
            fontSize: 22,
            fontFamily: "HelveticaNeue-Bold"
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
    var animation = (require("alloy/animation"), require("animation"));
    var _images = [];
    var _currentImageIndex = 0;
    var _currentImageView = "imageview";
    $.populateImages = function(images) {
        _images = images;
        $.imageview.image = _images[0];
    };
    $.animateImages = function() {
        var nextImageIndex = _currentImageIndex >= _images.length - 1 ? 0 : _currentImageIndex + 1;
        var nextImageView = "imageview" == _currentImageView ? "imageview1" : "imageview";
        $[_currentImageView].zIndex = 0;
        $[nextImageView].opacity = 0;
        $[nextImageView].zIndex = 1;
        $[nextImageView].image = _images[nextImageIndex];
        $[nextImageView].animate({
            opacity: 1,
            duration: 1e3
        });
        _currentImageIndex = nextImageIndex;
        _currentImageView = nextImageView;
    };
    $.animateClick = function(callback) {
        animation.flash($.overlay_view, callback);
    };
    $.title_label.addEventListener("postlayout", function() {
        -1 == $.title_label.text.indexOf(" ");
    });
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;