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
        $.motion_switch.value = Ti.App.Properties.getBool(Alloy.Globals.PROPERTY_ENABLE_MOTION_ANIMATION);
        $.list_animation_switch.value = Ti.App.Properties.getBool(Alloy.Globals.PROPERTY_ENABLE_LIST_ANIMATION);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "settings";
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
    $.__views.settings = Ti.UI.createView({
        backgroundColor: "#66000000",
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        opacity: 0,
        id: "settings"
    });
    $.__views.settings && $.addTopLevelView($.__views.settings);
    $.__views.__alloyId7 = Ti.UI.createView({
        layout: "vertical",
        width: Alloy.Globals.layout.overlay.width,
        height: Ti.UI.SIZE,
        id: "__alloyId7"
    });
    $.__views.settings.add($.__views.__alloyId7);
    $.__views.__alloyId8 = Ti.UI.createView({
        height: 100,
        id: "__alloyId8"
    });
    $.__views.__alloyId7.add($.__views.__alloyId8);
    $.__views.__alloyId9 = Ti.UI.createLabel({
        color: "#ffffff",
        left: 0,
        text: "Device motion animation",
        id: "__alloyId9"
    });
    $.__views.__alloyId8.add($.__views.__alloyId9);
    $.__views.motion_switch = Ti.UI.createSwitch({
        right: 0,
        id: "motion_switch"
    });
    $.__views.__alloyId8.add($.__views.motion_switch);
    $.__views.__alloyId10 = Ti.UI.createView({
        height: 100,
        id: "__alloyId10"
    });
    $.__views.__alloyId7.add($.__views.__alloyId10);
    $.__views.__alloyId11 = Ti.UI.createLabel({
        color: "#ffffff",
        left: 0,
        text: "Parallax animation",
        id: "__alloyId11"
    });
    $.__views.__alloyId10.add($.__views.__alloyId11);
    $.__views.list_animation_switch = Ti.UI.createSwitch({
        right: 0,
        id: "list_animation_switch"
    });
    $.__views.__alloyId10.add($.__views.list_animation_switch);
    exports.destroy = function() {};
    _.extend($, $.__views);
    arguments[0] || {};
    init();
    $.motion_switch.addEventListener("change", function(e) {
        Ti.Analytics.featureEvent("edit:motion." + e.value);
        Ti.App.Properties.setBool(Alloy.Globals.PROPERTY_ENABLE_MOTION_ANIMATION, e.value);
        Ti.App.fireEvent(Alloy.Globals.EVENT_PROPERTY_ENABLE_MOTION_ANIMATION_DID_CHANGE, {
            value: e.value
        });
    });
    $.list_animation_switch.addEventListener("change", function(e) {
        Ti.Analytics.featureEvent("edit:parallax." + e.value);
        Ti.App.Properties.setBool(Alloy.Globals.PROPERTY_ENABLE_LIST_ANIMATION, e.value);
        Ti.App.fireEvent(Alloy.Globals.EVENT_PROPERTY_ENABLE_LIST_ANIMATION_DID_CHANGE, {
            value: e.value
        });
    });
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;