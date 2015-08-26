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
    this.__controllerPath = "views/navbar";
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
    $.__views.container = Ti.UI.createView({
        top: 0,
        left: 0,
        width: Ti.UI.FILL,
        height: 64,
        id: "container",
        zIndex: "400"
    });
    $.__views.container && $.addTopLevelView($.__views.container);
    $.__views.background_view = Ti.UI.createView({
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
                color: "#99000000",
                offset: 0
            }, {
                color: "#33000000",
                offset: .5
            }, {
                color: "#00000000",
                offset: 1
            } ]
        },
        id: "background_view"
    });
    $.__views.container.add($.__views.background_view);
    $.__views.content = Ti.UI.createView({
        id: "content"
    });
    $.__views.container.add($.__views.content);
    $.__views.title_label = Ti.UI.createLabel({
        top: 20,
        height: 44,
        font: {
            fontSize: 18,
            fontFamily: "HelveticaNeue-Bold"
        },
        viewShadowRadius: 5,
        color: "#ffffff",
        width: Ti.UI.SIZE,
        id: "title_label"
    });
    $.__views.content.add($.__views.title_label);
    exports.destroy = function() {};
    _.extend($, $.__views);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;