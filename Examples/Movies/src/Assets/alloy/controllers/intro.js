function __processArg(obj, key) {
    var arg = null;
    if (obj) {
        arg = obj[key] || null;
        delete obj[key];
    }
    return arg;
}

function Controller() {
    function init() {
        $.window.removeEventListener("open", init);
        var animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                rotate: -10
            }),
            curve: Ti.UI.ANIMATION_CURVE_EASE_IN,
            duration: 1e3
        });
        animation.addEventListener("complete", function() {
            var animation = Ti.UI.createAnimation({
                transform: Ti.UI.create2DMatrix({
                    rotate: 11.3
                }),
                duration: 200
            });
            animation.addEventListener("complete", function() {
                _animationComplete = true;
                _animateOutOnComplete ? animateOut() : $.activity_indicator.show();
            });
            $.clapper_top_container.animate(animation);
        });
        $.clapper_top_container.animate(animation);
    }
    function animateOut() {
        $.activity_indicator.hide();
        var animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                scale: .7
            }),
            opacity: 0,
            duration: 1e3
        });
        animation.addEventListener("complete", _callback);
        $.window.animate(animation);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "intro";
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
    $.__views.window = Ti.UI.createWindow({
        id: "window"
    });
    $.__views.window && $.addTopLevelView($.__views.window);
    $.__views.clapper_top_container = Ti.UI.createView({
        top: Alloy.Globals.layout.intro.clapperTopContainerTop,
        left: Alloy.Globals.layout.intro.clapperTopContainerLeft,
        height: 62,
        width: 200,
        id: "clapper_top_container"
    });
    $.__views.window.add($.__views.clapper_top_container);
    $.__views.clapper_top = Ti.UI.createImageView({
        top: 0,
        left: 100,
        width: 100,
        height: 31,
        id: "clapper_top",
        image: "/clapper_top.png"
    });
    $.__views.clapper_top_container.add($.__views.clapper_top);
    $.__views.clapper_bottom = Ti.UI.createImageView({
        top: Alloy.Globals.layout.intro.clapperBottomTop,
        left: Alloy.Globals.layout.intro.clapperBottomLeft,
        width: 100,
        height: 55,
        id: "clapper_bottom",
        image: "/clapper_bottom.png"
    });
    $.__views.window.add($.__views.clapper_bottom);
    $.__views.activity_indicator = Ti.UI.createActivityIndicator({
        style: Ti.UI.ActivityIndicatorStyle.BIG,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        color: "#ff0000",
        top: Alloy.Globals.layout.intro.activityViewTop,
        id: "activity_indicator"
    });
    $.__views.window.add($.__views.activity_indicator);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var _animateOutOnComplete = false;
    var _animationComplete = false;
    var _callback;
    $.endIntro = function(callback) {
        _callback = callback;
        _animateOutOnComplete = true;
        _animationComplete && animateOut();
    };
    $.window.addEventListener("open", init);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;