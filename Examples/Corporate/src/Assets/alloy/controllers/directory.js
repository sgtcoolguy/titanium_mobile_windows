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
        var file = Ti.Filesystem.getFile(Ti.Filesystem.resourcesDirectory + "userData/data.json");
        users = JSON.parse(file.read().text).users;
        users = _.sortBy(users, function(user) {
            return user.lastName;
        });
        if (users) {
            indexes = [];
            var sections = [];
            var userGroups = _.groupBy(users, function(item) {
                return item.lastName.charAt(0);
            });
            _.each(userGroups, function(group) {
                var dataToAdd = preprocessForListView(group);
                if (dataToAdd.length < 1) return;
                indexes.push({
                    index: indexes.length,
                    title: group[0].lastName.charAt(0)
                });
                var sectionHeader = Ti.UI.createView({
                    backgroundColor: "#ececec",
                    width: Ti.UI.FILL,
                    height: 30
                });
                var sectionLabel = Ti.UI.createLabel({
                    text: group[0].lastName.charAt(0),
                    left: 20,
                    font: {
                        fontSize: 20
                    },
                    color: "#666"
                });
                sectionHeader.add(sectionLabel);
                var section = Ti.UI.createListSection({
                    headerView: sectionHeader
                });
                section.items = dataToAdd;
                sections.push(section);
            });
            $.listView.sections = sections;
        }
        _args.title && ($.wrapper.title = _args.title);
        _args.restrictBookmarks && false;
    }
    function onItemClick(e) {
        Ti.Analytics.featureEvent("windows." + title + ".contact.clicked");
        var item = $.listView.sections[e.sectionIndex].items[e.itemIndex];
        Alloy.Globals.Navigator.open("profile", item.properties.user);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "directory";
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
    $.__views.wrapper = Ti.UI.createWindow({
        backgroundColor: "#fff",
        titleAttributes: {
            color: "#C41230"
        },
        layout: "vertical",
        id: "wrapper",
        title: "Directory"
    });
    $.__views.wrapper && $.addTopLevelView($.__views.wrapper);
    $.__views.__alloyId1 = Ti.UI.createView({
        layout: "horizontal",
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId1"
    });
    $.__views.wrapper.add($.__views.__alloyId1);
    $.__views.__alloyId2 = Ti.UI.createLabel({
        left: 10,
        font: {
            fontFamily: "icomoon",
            fontSize: 24
        },
        text: "",
        color: "#999",
        width: "7%",
        id: "__alloyId2"
    });
    $.__views.__alloyId1.add($.__views.__alloyId2);
    $.__views.searchBar = Ti.UI.createTextField({
        borderStyle: Ti.UI.INPUT_BORDERSTYLE_ROUNDED,
        backgroundColor: "#fff",
        borderWidth: 0,
        borderColor: "#fff",
        tintColor: "#C41230",
        hintText: "Search",
        barColor: "#fff",
        showBookmark: true,
        height: 40,
        left: 10,
        width: "76%",
        id: "searchBar"
    });
    $.__views.__alloyId1.add($.__views.searchBar);
    onSearchChange ? $.__views.searchBar.addEventListener("change", onSearchChange) : __defers["$.__views.searchBar!change!onSearchChange"] = true;
    $.__views.closeBtn = Ti.UI.createLabel({
        right: 10,
        font: {
            fontFamily: "icomoon",
            fontSize: 24
        },
        text: "",
        color: "#999",
        height: 40,
        width: "7%",
        visible: false,
        id: "closeBtn"
    });
    $.__views.__alloyId1.add($.__views.closeBtn);
    onSearchCancel ? $.__views.closeBtn.addEventListener("click", onSearchCancel) : __defers["$.__views.closeBtn!click!onSearchCancel"] = true;
    var __alloyId3 = {};
    var __alloyId5 = [];
    var __alloyId7 = {
        type: "Ti.UI.View",
        childTemplates: function() {
            var __alloyId8 = [];
            var __alloyId9 = {
                type: "Ti.UI.ImageView",
                bindId: "userPhoto",
                properties: {
                    preventDefaultImage: true,
                    border: 1,
                    borderColor: "#acacac",
                    height: 75,
                    width: 75,
                    top: 12,
                    left: 0,
                    borderRadius: 35,
                    bindId: "userPhoto"
                }
            };
            __alloyId8.push(__alloyId9);
            var __alloyId11 = {
                type: "Ti.UI.View",
                childTemplates: function() {
                    var __alloyId12 = [];
                    var __alloyId13 = {
                        type: "Ti.UI.Label",
                        bindId: "userName",
                        properties: {
                            font: {
                                fontSize: 14
                            },
                            left: 85,
                            color: "#444",
                            bindId: "userName"
                        }
                    };
                    __alloyId12.push(__alloyId13);
                    var __alloyId14 = {
                        type: "Ti.UI.Label",
                        bindId: "userEmail",
                        properties: {
                            font: {
                                fontSize: 10
                            },
                            left: 85,
                            height: 20,
                            color: "#666",
                            bindId: "userEmail"
                        }
                    };
                    __alloyId12.push(__alloyId14);
                    var __alloyId15 = {
                        type: "Ti.UI.Label",
                        bindId: "userCompany",
                        properties: {
                            font: {
                                fontSize: 10
                            },
                            left: 85,
                            height: 20,
                            color: "#666",
                            bindId: "userCompany"
                        }
                    };
                    __alloyId12.push(__alloyId15);
                    return __alloyId12;
                }(),
                properties: {
                    layout: "vertical",
                    height: Ti.UI.SIZE,
                    width: Ti.UI.SIZE,
                    left: 0
                }
            };
            __alloyId8.push(__alloyId11);
            var __alloyId17 = {
                type: "Ti.UI.View",
                properties: {
                    bottom: 0,
                    backgroundColor: "#ececec",
                    width: Ti.UI.FILL,
                    height: 1
                }
            };
            __alloyId8.push(__alloyId17);
            return __alloyId8;
        }(),
        properties: {
            left: 10
        }
    };
    __alloyId5.push(__alloyId7);
    var __alloyId4 = {
        properties: {
            height: 100,
            width: Ti.UI.FILL,
            name: "userTemplate"
        },
        childTemplates: __alloyId5
    };
    __alloyId3["userTemplate"] = __alloyId4;
    var __alloyId19 = [];
    var __alloyId21 = {
        type: "Ti.UI.View",
        childTemplates: function() {
            var __alloyId22 = [];
            var __alloyId23 = {
                type: "Ti.UI.ImageView",
                bindId: "userPhoto",
                properties: {
                    preventDefaultImage: true,
                    border: 1,
                    borderColor: "#acacac",
                    height: 75,
                    width: 75,
                    top: 12,
                    left: 0,
                    borderRadius: 35,
                    bindId: "userPhoto"
                }
            };
            __alloyId22.push(__alloyId23);
            var __alloyId25 = {
                type: "Ti.UI.View",
                childTemplates: function() {
                    var __alloyId26 = [];
                    var __alloyId27 = {
                        type: "Ti.UI.Label",
                        bindId: "userName",
                        properties: {
                            font: {
                                fontSize: 14
                            },
                            left: 85,
                            color: "#444",
                            bindId: "userName"
                        }
                    };
                    __alloyId26.push(__alloyId27);
                    var __alloyId28 = {
                        type: "Ti.UI.Label",
                        bindId: "userEmail",
                        properties: {
                            font: {
                                fontSize: 10
                            },
                            left: 85,
                            height: 20,
                            color: "#666",
                            bindId: "userEmail"
                        }
                    };
                    __alloyId26.push(__alloyId28);
                    var __alloyId29 = {
                        type: "Ti.UI.Label",
                        bindId: "userCompany",
                        properties: {
                            font: {
                                fontSize: 10
                            },
                            left: 85,
                            height: 20,
                            color: "#666",
                            bindId: "userCompany"
                        }
                    };
                    __alloyId26.push(__alloyId29);
                    return __alloyId26;
                }(),
                properties: {
                    layout: "vertical",
                    height: Ti.UI.SIZE,
                    width: Ti.UI.SIZE,
                    left: 0
                }
            };
            __alloyId22.push(__alloyId25);
            var __alloyId31 = {
                type: "Ti.UI.Label",
                properties: {
                    font: {
                        fontSize: 20,
                        fontFamily: "icomoon"
                    },
                    text: "",
                    color: "#038BC8",
                    right: 10,
                    top: -2
                }
            };
            __alloyId22.push(__alloyId31);
            var __alloyId33 = {
                type: "Ti.UI.View",
                properties: {
                    bottom: 0,
                    backgroundColor: "#ececec",
                    width: Ti.UI.FILL,
                    height: 1
                }
            };
            __alloyId22.push(__alloyId33);
            return __alloyId22;
        }(),
        properties: {
            left: 10
        }
    };
    __alloyId19.push(__alloyId21);
    var __alloyId18 = {
        properties: {
            height: 100,
            width: Ti.UI.FILL,
            name: "favoriteTemplate"
        },
        childTemplates: __alloyId19
    };
    __alloyId3["favoriteTemplate"] = __alloyId18;
    $.__views.listView = Ti.UI.createListView({
        tintColor: "#666",
        templates: __alloyId3,
        id: "listView",
        defaultItemTemplate: "userTemplate"
    });
    $.__views.wrapper.add($.__views.listView);
    onItemClick ? $.__views.listView.addEventListener("itemclick", onItemClick) : __defers["$.__views.listView!itemclick!onItemClick"] = true;
    exports.destroy = function() {};
    _.extend($, $.__views);
    var _args = arguments[0] || {}, users = (Alloy.Globals.App, null), indexes = [];
    var title = _args.title ? _args.title.toLowerCase() : "directory";
    Ti.Analytics.featureEvent("windows." + title + ".viewed");
    var preprocessForListView = function(rawData) {
        var bookmarks = Ti.App.Properties.getList("bookmarks", []);
        _args.restrictBookmarks && (rawData = _.filter(rawData, function(item) {
            return _.find(bookmarks, function(bookmark) {
                return item.id === bookmark;
            });
        }));
        return _.map(rawData, function(item) {
            var isBookmark = _.find(bookmarks, function(bookmark) {
                return item.id === bookmark;
            });
            return {
                template: isBookmark ? "favoriteTemplate" : "userTemplate",
                properties: {
                    searchableText: item.name + " " + item.company + " " + item.email,
                    user: item
                },
                userName: {
                    text: item.firstName + " " + item.lastName
                },
                userCompany: {
                    text: item.company
                },
                userPhoto: {
                    image: item.photo
                },
                userEmail: {
                    text: item.email
                }
            };
        });
    };
    var onSearchChange, onSearchCancel;
    onSearchChange = function() {
        $.closeBtn.visible = "" !== $.searchBar.value ? true : false;
        $.listView.searchText = $.searchBar.value;
    };
    onSearchCancel = function() {
        $.closeBtn.visible = false;
        $.searchBar.value = "";
        $.searchBar.blur();
    };
    $.wrapper.addEventListener("open", function() {
        if (false && _args.restrictBookmarks) {
            var activity = $.wrapper.getActivity();
            activity.onCreateOptionsMenu = function(e) {
                e.menu.clear();
            };
            activity.invalidateOptionsMenu();
        }
    });
    Ti.App.addEventListener("refresh-data", function() {
        init();
    });
    init();
    __defers["$.__views.searchBar!change!onSearchChange"] && $.__views.searchBar.addEventListener("change", onSearchChange);
    __defers["$.__views.closeBtn!click!onSearchCancel"] && $.__views.closeBtn.addEventListener("click", onSearchCancel);
    __defers["$.__views.listView!itemclick!onItemClick"] && $.__views.listView.addEventListener("itemclick", onItemClick);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;