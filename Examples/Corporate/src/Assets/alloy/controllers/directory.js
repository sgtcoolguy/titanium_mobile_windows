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
                    width: Ti.UI.FIll,
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
            $.wrapper.addEventListener("swipe", function(e) {
                "left" === e.direction && ($.listView.sectionIndexTitles = indexes);
                "right" === e.direction && ($.listView.sectionIndexTitles = null);
            });
        }
        _args.title && ($.wrapper.title = _args.title);
        _args.restrictBookmarks && ($.searchBar.showBookmark = false);
    }
    function onItemClick(e) {
        Ti.Analytics.featureEvent(Ti.Platform.osname + "." + title + ".contact.clicked");
        var item = $.listView.sections[e.sectionIndex].items[e.itemIndex];
        Alloy.Globals.App.Navigator.open("profile", item.properties.user);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "directory";
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
    $.__views.wrapper = Ti.UI.createView({
        layout: "vertical",
        id: "wrapper",
        title: "Directory"
    });
    $.__views.wrapper && $.addTopLevelView($.__views.wrapper);
    $.__views.searchBar = Ti.UI.createSearchBar({
        backgroundColor: "#fff",
        borderWidth: 0,
        tintColor: "#C41230",
        hintText: "Search",
        barColor: "#fff",
        showBookmark: true,
        id: "searchBar"
    });
    $.__views.wrapper.add($.__views.searchBar);
    onBookmarkClick ? $.__views.searchBar.addEventListener("bookmark", onBookmarkClick) : __defers["$.__views.searchBar!bookmark!onBookmarkClick"] = true;
    onSearchFocus ? $.__views.searchBar.addEventListener("focus", onSearchFocus) : __defers["$.__views.searchBar!focus!onSearchFocus"] = true;
    onSearchCancel ? $.__views.searchBar.addEventListener("cancel", onSearchCancel) : __defers["$.__views.searchBar!cancel!onSearchCancel"] = true;
    onSearchChange ? $.__views.searchBar.addEventListener("change", onSearchChange) : __defers["$.__views.searchBar!change!onSearchChange"] = true;
    var __alloyId0 = {};
    var __alloyId2 = [];
    var __alloyId4 = {
        type: "Ti.UI.View",
        childTemplates: function() {
            var __alloyId5 = [];
            var __alloyId6 = {
                type: "Ti.UI.ImageView",
                bindId: "userPhoto",
                properties: {
                    preventDefaultImage: true,
                    border: 1,
                    borderColor: "#acacac",
                    height: 75,
                    width: Ti.UI.SIZE,
                    top: 12,
                    left: 0,
                    borderRadius: 35,
                    bindId: "userPhoto"
                }
            };
            __alloyId5.push(__alloyId6);
            var __alloyId8 = {
                type: "Ti.UI.View",
                childTemplates: function() {
                    var __alloyId9 = [];
                    var __alloyId10 = {
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
                    __alloyId9.push(__alloyId10);
                    var __alloyId11 = {
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
                    __alloyId9.push(__alloyId11);
                    var __alloyId12 = {
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
                    __alloyId9.push(__alloyId12);
                    return __alloyId9;
                }(),
                properties: {
                    layout: "vertical",
                    height: Ti.UI.SIZE,
                    width: Ti.UI.SIZE,
                    left: 10
                }
            };
            __alloyId5.push(__alloyId8);
            var __alloyId14 = {
                type: "Ti.UI.View",
                properties: {
                    bottom: 0,
                    backgroundColor: "#ececec",
                    width: Ti.UI.FILL,
                    height: 1
                }
            };
            __alloyId5.push(__alloyId14);
            return __alloyId5;
        }(),
        properties: {
            left: 10
        }
    };
    __alloyId2.push(__alloyId4);
    var __alloyId1 = {
        properties: {
            height: 100,
            width: Ti.UI.FILL,
            name: "userTemplate"
        },
        childTemplates: __alloyId2
    };
    __alloyId0["userTemplate"] = __alloyId1;
    var __alloyId16 = [];
    var __alloyId18 = {
        type: "Ti.UI.View",
        childTemplates: function() {
            var __alloyId19 = [];
            var __alloyId20 = {
                type: "Ti.UI.ImageView",
                bindId: "userPhoto",
                properties: {
                    preventDefaultImage: true,
                    border: 1,
                    borderColor: "#acacac",
                    height: 75,
                    width: Ti.UI.SIZE,
                    top: 12,
                    left: 0,
                    borderRadius: 35,
                    bindId: "userPhoto"
                }
            };
            __alloyId19.push(__alloyId20);
            var __alloyId22 = {
                type: "Ti.UI.View",
                childTemplates: function() {
                    var __alloyId23 = [];
                    var __alloyId24 = {
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
                    __alloyId23.push(__alloyId24);
                    var __alloyId25 = {
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
                    __alloyId23.push(__alloyId25);
                    var __alloyId26 = {
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
                    __alloyId23.push(__alloyId26);
                    return __alloyId23;
                }(),
                properties: {
                    layout: "vertical",
                    height: Ti.UI.SIZE,
                    width: Ti.UI.SIZE,
                    left: 10
                }
            };
            __alloyId19.push(__alloyId22);
            var __alloyId28 = {
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
            __alloyId19.push(__alloyId28);
            var __alloyId30 = {
                type: "Ti.UI.View",
                properties: {
                    bottom: 0,
                    backgroundColor: "#ececec",
                    width: Ti.UI.FILL,
                    height: 1
                }
            };
            __alloyId19.push(__alloyId30);
            return __alloyId19;
        }(),
        properties: {
            left: 10
        }
    };
    __alloyId16.push(__alloyId18);
    var __alloyId15 = {
        properties: {
            height: 100,
            width: Ti.UI.FILL,
            name: "favoriteTemplate"
        },
        childTemplates: __alloyId16
    };
    __alloyId0["favoriteTemplate"] = __alloyId15;
    $.__views.listView = Ti.UI.createListView({
        tintColor: "#666",
        templates: __alloyId0,
        id: "listView",
        defaultItemTemplate: "userTemplate"
    });
    $.__views.wrapper.add($.__views.listView);
    onItemClick ? $.__views.listView.addEventListener("itemclick", onItemClick) : __defers["$.__views.listView!itemclick!onItemClick"] = true;
    exports.destroy = function() {};
    _.extend($, $.__views);
    var _args = arguments[0] || {}, App = Alloy.Globals.App, users = null, indexes = [];
    var title = _args.title ? _args.title.toLowerCase() : "directory";
    Ti.Analytics.featureEvent(Ti.Platform.osname + "." + title + ".viewed");
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
    var onSearchChange, onSearchFocus, onSearchCancel, onBookmarkClick;
    onSearchChange = function() {
        $.listView.searchText = $.searchBar.value;
    };
    onSearchFocus = function() {
        $.searchBar.showBookmark = false;
        $.searchBar.showCancel = true;
    };
    onSearchCancel = function() {
        if (!_args.restrictBookmarks) {
            $.searchBar.showBookmark = true;
            $.searchBar.showCancel = false;
        }
        $.searchBar.blur();
    };
    onBookmarkClick = function() {
        Ti.Analytics.featureEvent(Ti.Platform.osname + "." + title + ".bookmarks.clicked");
        $.searchBar.blur();
        App.Navigator.open("directory", {
            restrictBookmarks: true,
            title: "Bookmarks"
        });
    };
    init();
    Ti.App.addEventListener("refresh-data", function() {
        $.listView.sections[0].items = null;
        init();
    });
    __defers["$.__views.searchBar!bookmark!onBookmarkClick"] && $.__views.searchBar.addEventListener("bookmark", onBookmarkClick);
    __defers["$.__views.searchBar!focus!onSearchFocus"] && $.__views.searchBar.addEventListener("focus", onSearchFocus);
    __defers["$.__views.searchBar!cancel!onSearchCancel"] && $.__views.searchBar.addEventListener("cancel", onSearchCancel);
    __defers["$.__views.searchBar!change!onSearchChange"] && $.__views.searchBar.addEventListener("change", onSearchChange);
    __defers["$.__views.listView!itemclick!onItemClick"] && $.__views.listView.addEventListener("itemclick", onItemClick);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;