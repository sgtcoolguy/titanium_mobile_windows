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
        _introController = Alloy.createController("intro");
        _introController.window.open();
        _homeController = Alloy.createController("home", {
            loaded_callback: function() {
                _introController.endIntro(displayHome);
            }
        });
    }
    function displayHome() {
        Alloy.Globals.initNavigation();
        Alloy.Globals.Navigator.push(_homeController);
        _homeController.animateIn();
        _introController.window.close();
        _introController = null;
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "index";
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
    exports.destroy = function() {};
    _.extend($, $.__views);
    var _introController;
    var _homeController;
    var launch = true;
    if (Alloy.CFG.run_logic_tests) {
        launch = false;
        Ti.App.addEventListener("logic_tests_complete", function logicTestsComplete() {
            Ti.App.removeEventListener("logic_tests_complete", logicTestsComplete);
            init();
        });
    }
    launch && init();
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;