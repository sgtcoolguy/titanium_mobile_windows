function __processArg(obj, key) {
    var arg = null;
    if (obj) {
        arg = obj[key] || null;
        delete obj[key];
    }
    return arg;
}

function Controller() {
    function __alloyId17(e) {
        if (e && e.fromAdapter) return;
        var opts = __alloyId17.opts || {};
        var models = __alloyId16.models;
        var len = models.length;
        var __alloyId12 = [];
        for (var i = 0; len > i; i++) {
            var __alloyId13 = models[i];
            __alloyId13.__transform = transform(__alloyId13);
            var __alloyId15 = {
                properties: {
                    itemId: "undefined" != typeof __alloyId13.__transform["guid"] ? __alloyId13.__transform["guid"] : __alloyId13.get("guid")
                },
                image: {
                    image: "undefined" != typeof __alloyId13.__transform["image"] ? __alloyId13.__transform["image"] : __alloyId13.get("image")
                },
                title: {
                    text: "undefined" != typeof __alloyId13.__transform["title"] ? __alloyId13.__transform["title"] : __alloyId13.get("title")
                },
                subtitle: {
                    text: "undefined" != typeof __alloyId13.__transform["pubDate"] ? __alloyId13.__transform["pubDate"] : __alloyId13.get("pubDate")
                }
            };
            __alloyId12.push(__alloyId15);
        }
        opts.animation ? $.__views.__alloyId11.setItems(__alloyId12, opts.animation) : $.__views.__alloyId11.setItems(__alloyId12);
    }
    function refresh(e) {
        "use strict";
        function afterFetch() {}
        var url = Alloy.CFG.url;
        Alloy.Collections.feed.fetch({
            url: url,
            success: afterFetch,
            error: afterFetch
        });
    }
    function transform(model) {
        "use strict";
        return {
            pubDate: moment(model.get("pubDate"), "DD MMM YYYY HH:mm:ss ZZ").format("LLL")
        };
    }
    function select(e) {
        "use strict";
        var guid = e.itemId;
        var model = Alloy.Collections.feed.get(guid);
        $.trigger("select", {
            model: model
        });
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "master";
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
    var __defers = {};
    Alloy.Collections.instance("feed");
    $.__views.master = Ti.UI.createWindow({
        backgroundColor: "#FFF",
        title: "RSS Reader",
        id: "master"
    });
    $.__views.master && $.addTopLevelView($.__views.master);
    var __alloyId3 = {};
    var __alloyId6 = [];
    var __alloyId8 = {
        type: "Ti.UI.Label",
        bindId: "title",
        properties: {
            color: "#000",
            left: 10,
            height: 25,
            wordWrap: false,
            ellipsize: true,
            top: 5,
            font: {
                fontSize: 18
            },
            bindId: "title"
        }
    };
    __alloyId6.push(__alloyId8);
    var __alloyId10 = {
        type: "Ti.UI.Label",
        bindId: "subtitle",
        properties: {
            color: "#999",
            left: 10,
            height: 25,
            wordWrap: false,
            ellipsize: true,
            top: 30,
            font: {
                fontSize: 18
            },
            bindId: "subtitle"
        }
    };
    __alloyId6.push(__alloyId10);
    var __alloyId5 = {
        properties: {
            height: 60,
            name: "template"
        },
        childTemplates: __alloyId6
    };
    __alloyId3["template"] = __alloyId5;
    $.__views.__alloyId11 = Ti.UI.createListSection({
        id: "__alloyId11"
    });
    var __alloyId16 = Alloy.Collections["feed"] || feed;
    __alloyId16.on("fetch destroy change add remove reset", __alloyId17);
    var __alloyId18 = [];
    __alloyId18.push($.__views.__alloyId11);
    $.__views.__alloyId2 = Ti.UI.createListView({
        sections: __alloyId18,
        templates: __alloyId3,
        defaultItemTemplate: "template",
        id: "__alloyId2"
    });
    $.__views.master.add($.__views.__alloyId2);
    select ? $.addListener($.__views.__alloyId2, "itemclick", select) : __defers["$.__views.__alloyId2!itemclick!select"] = true;
    exports.destroy = function() {
        __alloyId16.off("fetch destroy change add remove reset", __alloyId17);
    };
    _.extend($, $.__views);
    var moment = require("alloy/moment");
    !function() {
        "use strict";
        refresh();
    }(arguments[0] || {});
    __defers["$.__views.__alloyId2!itemclick!select"] && $.addListener($.__views.__alloyId2, "itemclick", select);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;