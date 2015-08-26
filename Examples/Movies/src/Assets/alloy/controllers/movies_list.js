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
        var diff = Alloy.Globals.layout.list.row.imageHeight - Alloy.Globals.layout.list.row.height;
        tableview_offset_per_px = diff / $.tableview.rect.height;
        tableview_cell_offset = tableview_offset_per_px * Alloy.Globals.layout.list.row.height;
        if ("search" == args.type) {
            Ti.Analytics.featureEvent("view:search_results");
            Ti.Analytics.featureEvent("view:search_results." + args.query);
            search(args.query);
        } else {
            Ti.Analytics.featureEvent("view:" + args.type);
            Ti.Analytics.featureEvent("view:" + args.type + "." + args.id);
            fetchCollection(args.type, args.id);
        }
    }
    function fetchCollection(type) {
        Data["movies_get_" + type](function(error, e) {
            if (error) Ti.API.error("Error: " + JSON.stringify(JSON.parse(e), null, 4)); else {
                $.navbar.title_label.text = e.title.toUpperCase();
                movies = e.movies;
                populateMovies(movies);
            }
        });
    }
    function search(query) {
        $.navbar.title_label.text = "Results for '" + query + "'";
        Data.movies_search(query, function(error, e) {
            if (error) Ti.API.error(error); else {
                movies = e;
                populateMovies(movies);
            }
        });
    }
    function populateMovies(movies) {
        tableView_data = [];
        var tableView_rows = [];
        for (var i = 0; i < movies.length; i++) {
            var movie = movies[i];
            var cell = Alloy.createController("views/movies_list_cell");
            cell.updateViews({
                "#title_label": {
                    text: movie.title
                },
                "#thumbnail_imageview": {
                    top: 0,
                    image: theMovieDb.common.getImage({
                        size: Alloy.Globals.backdropImageSize,
                        file: movie.backdrop_path
                    })
                }
            });
            tableView_data.push(cell);
            tableView_rows.push(cell.getView());
        }
        $.tableview.setData(tableView_rows);
        $.activity_indicator.hide();
        var tableview_animation = Ti.UI.createAnimation({
            opacity: 1,
            duration: 500,
            curve: Titanium.UI.ANIMATION_CURVE_EASE_OUT
        });
        $.tableview.animate(tableview_animation);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "movies_list";
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
        navBarHidden: true,
        orientationModes: [ Ti.UI.PORTRAIT ],
        backgroundColor: "#000000",
        id: "window"
    });
    $.__views.window && $.addTopLevelView($.__views.window);
    $.__views.tableview = Ti.UI.createTableView({
        top: 0,
        left: 0,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        backgroundColor: "transparent",
        pullBackgroundColor: "#b0332a",
        showVerticalScrollIndicator: false,
        opacity: 0,
        id: "tableview"
    });
    $.__views.window.add($.__views.tableview);
    $.__views.activity_indicator = Ti.UI.createActivityIndicator({
        style: Ti.UI.ActivityIndicatorStyle.BIG,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        color: "#ff0000",
        id: "activity_indicator"
    });
    $.__views.window.add($.__views.activity_indicator);
    $.__views.navbar = Alloy.createController("views/navbar", {
        id: "navbar",
        __parentSymbol: $.__views.window
    });
    $.__views.navbar.setParent($.__views.window);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var theMovieDb = require("themoviedb"), Data = require("data");
    var args = arguments[0] || {};
    var movies = [];
    var tableView_data = [];
    var tableview_offset_per_px = 0;
    var tableview_cell_offset = 0;
    $.window.addEventListener("open", init);
    $.tableview.addEventListener("click", function(e) {
        $.tableview.touchEnabled = false;
        tableView_data[e.index].animateClick(function() {
            var movie = movies[e.index];
            Alloy.Globals.Navigator.push("movie", {
                id: movie.id
            });
            setTimeout(function() {
                $.tableview.touchEnabled = true;
            }, 1e3);
        });
    });
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;