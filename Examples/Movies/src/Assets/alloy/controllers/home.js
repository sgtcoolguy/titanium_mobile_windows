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
        configureStaticCells();
        getConfig();
        getLists();
    }
    function getConfig() {
        Data.get_config(function(error, e) {
            if (!error) {
                Alloy.Globals.setBackdropImageSize(e.images.backdrop_sizes);
                Alloy.Globals.setPosterImageSize(e.images.poster_sizes);
            }
        });
    }
    function getLists() {
        Data.movies_get_lists(function(error, e) {
            if (error) Ti.API.error("Error: " + JSON.stringify(JSON.parse(e), null, 4)); else {
                lists = e;
                populateLists(lists, "list", 0, cellOffset + Alloy.Globals.layout.lists.cell.height + 20);
                getGenres();
            }
        });
    }
    function getGenres() {
        Data.movies_get_genres(function(error, e) {
            if (error) Ti.API.error("Error: " + JSON.stringify(JSON.parse(e), null, 4)); else {
                genres = e;
                populateLists(genres, "genre", lists.length, cellOffset + 40 + Alloy.Globals.layout.lists.cell.height);
                loaded_callback();
            }
        });
    }
    function configureStaticCells() {
        $.searchCell.updateViews({
            "#cell": {
                top: cellOffset,
                left: 10
            },
            "#title_label": {
                text: ""
            }
        });
        $.aboutCell.updateViews({
            "#cell": {
                top: cellOffset,
                left: 10 + (Alloy.Globals.layout.lists.cell.width + 10),
                height: Alloy.Globals.layout.lists.cell.height
            },
            "#title_label": {
                text: ""
            }
        });
    }
    function populateLists(lists, type, cellOffset, yOffset) {
        for (var i = 0, num_lists = lists.length; num_lists > i; i++) {
            var list = lists[i];
            var idx = i + cellOffset;
            var cell_x = 10 + (Alloy.Globals.layout.lists.cell.width + 10) * (idx % 2);
            var cell_y = yOffset + (Alloy.Globals.layout.lists.cell.height + 10) * Math.floor(idx / 2);
            var cell = Alloy.createController("views/list_cell");
            cell.updateViews({
                "#cell": {
                    top: cell_y,
                    left: cell_x
                },
                "#title_label": {
                    text: list.title.toUpperCase()
                }
            });
            var images = [];
            _.each(list.backdrop_paths, function(path) {
                null != path && images.push(theMovieDb.common.getImage({
                    size: Alloy.Globals.backdropImageSize,
                    file: path
                }));
            });
            images = _.chain(images).shuffle().first(5).value();
            cell.populateImages(images);
            !function(cell, index) {
                cell.getView().addEventListener("click", function() {
                    $.lists_container.touchEnabled = false;
                    cell.animateClick(function() {
                        "list" == type ? openList(lists[index]) : "genre" == type && openGenre(genres[index]);
                        setTimeout(function() {
                            $.lists_container.touchEnabled = true;
                        }, 1e3);
                    });
                });
            }(cell, i);
            cells.push(cell);
            $.lists_container.add(cell.getView());
            var contentHeight = cell_y + Alloy.Globals.layout.lists.cell.height + 10;
            $.lists_container.contentHeight = contentHeight;
        }
    }
    function startAnimatingImages() {
        cells.length > 0 && !image_animation_interval && (image_animation_interval = setInterval(animateImages, 5e3));
    }
    function animateImages() {
        _.each(cells, function(cell, index) {
            setTimeout(function() {
                animateCellImages(cell);
            }, 100 * index);
        });
    }
    function animateCellImages(cell) {
        var cellTop = cell.getView().rect.y;
        var cellBottom = cell.getView().rect.y + cell.getView().rect.height;
        var visibleTop = $.lists_container.contentOffset.y;
        var visibleBottom = visibleTop + $.lists_container.rect.height;
        var isVisible = visibleBottom > cellTop && cellBottom > visibleTop;
        isVisible && cell.animateImages();
    }
    function openList(list) {
        Alloy.Globals.Navigator.push("movies_list", {
            type: "list",
            id: list.id
        });
    }
    function openGenre(genre) {
        Alloy.Globals.Navigator.push("movies_list", {
            type: "genre",
            id: genre.id
        });
    }
    function showOverlay(controller, options) {
        overlay_controller = Alloy.createController(controller, options);
        var view = overlay_controller.getView();
        $.window.add(view);
        var cells_animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                scale: .7
            }),
            opacity: .5,
            curve: Ti.UI.ANIMATION_CURVE_EASE_OUT,
            duration: 500
        });
        $.lists_container.animate(cells_animation);
        var view_animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                scale: 1
            }),
            opacity: 1,
            curve: Ti.UI.ANIMATION_CURVE_EASE_OUT,
            duration: 500,
            delay: 100
        });
        view.animate(view_animation);
        overlay_controller.getView().addEventListener("click", hideOverlay);
        displaying_overlay = true;
    }
    function hideOverlay() {
        var view = overlay_controller.getView();
        view.removeEventListener("click", hideOverlay);
        var view_animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                scale: 2
            }),
            opacity: 0,
            curve: Ti.UI.ANIMATION_CURVE_EASE_OUT,
            duration: 500
        });
        view.animate(view_animation);
        view_animation.addEventListener("complete", function() {
            $.window.remove(view);
            overlay_controller.destroy();
            overlay_controller = null;
        });
        var animation = Ti.UI.createAnimation({
            transform: Ti.UI.create2DMatrix({
                scale: 1
            }),
            opacity: 1,
            curve: Ti.UI.ANIMATION_CURVE_EASE_OUT,
            duration: 500,
            delay: 100
        });
        $.lists_container.animate(animation);
        displaying_overlay = false;
    }
    function displaySearch() {
        displaying_search = true;
        $.lists_container.scrollEnabled = false;
        $.lists_container.contentOffset = {
            x: 0,
            y: 0
        };
        $.search_overlay.zIndex = 101;
        $.search_textfield.focus();
        $.container.animate({
            top: 0,
            duration: 250
        });
    }
    function hideSearch() {
        displaying_search = false;
        $.search_overlay.zIndex = 0;
        $.lists_container.scrollEnabled = true;
        $.search_textfield.blur();
        $.search_textfield.value = "";
        var animation = Ti.UI.createAnimation({
            top: -70,
            duration: 250
        });
        $.container.animate(animation);
    }
    function handleStaticCellClick(cell, overlay) {
        $.lists_container.touchEnabled = false;
        cell.animateClick(function() {
            Ti.Analytics.featureEvent("display:" + overlay);
            showOverlay(overlay);
            setTimeout(function() {
                $.lists_container.touchEnabled = true;
            }, 1e3);
        });
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "home";
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
        backgroundColor: "black",
        extendEdges: Titanium.UI.EXTEND_EDGE_TOP,
        navBarHidden: true,
        orientationModes: [ Ti.UI.PORTRAIT ],
        id: "window",
        title: "Movies"
    });
    $.__views.window && $.addTopLevelView($.__views.window);
    $.__views.container = Ti.UI.createView({
        top: -70,
        left: 0,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        id: "container"
    });
    $.__views.window.add($.__views.container);
    $.__views.search_textfield = Ti.UI.createTextField({
        top: 10,
        left: 10,
        right: 10,
        height: 40,
        paddingLeft: 40,
        paddingRight: 10,
        color: "#ffffff",
        autocapitalization: true,
        autocorrect: false,
        returnKeyType: Titanium.UI.RETURNKEY_SEARCH,
        enableReturnKey: true,
        hintText: "Search",
        borderColor: "#b0332a",
        borderWidth: 1,
        backgroundColor: "#260205",
        id: "search_textfield"
    });
    $.__views.container.add($.__views.search_textfield);
    $.__views.search_icon = Ti.UI.createImageView({
        top: 40,
        left: 20,
        width: 20,
        height: 20,
        image: "/search_icon.png",
        id: "search_icon"
    });
    $.__views.container.add($.__views.search_icon);
    $.__views.lists_container = Ti.UI.createScrollView({
        top: 70,
        left: 0,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        contentWidth: "auto",
        contentHeight: "auto",
        scrollType: "vertical",
        opacity: 0,
        id: "lists_container",
        zIndex: "100"
    });
    $.__views.container.add($.__views.lists_container);
    $.__views.searchCell = Alloy.createController("views/list_static_cell", {
        id: "searchCell",
        __parentSymbol: $.__views.lists_container
    });
    $.__views.searchCell.setParent($.__views.lists_container);
    $.__views.aboutCell = Alloy.createController("views/list_static_cell", {
        id: "aboutCell",
        __parentSymbol: $.__views.lists_container
    });
    $.__views.aboutCell.setParent($.__views.lists_container);
    $.__views.search_overlay = Ti.UI.createView({
        top: 70,
        left: 0,
        width: Ti.UI.FILL,
        height: Ti.UI.FILL,
        backgroundColor: "#99000000",
        id: "search_overlay",
        zIndex: "0"
    });
    $.__views.container.add($.__views.search_overlay);
    $.__views.activity_indicator = Ti.UI.createActivityIndicator({
        style: Ti.UI.ActivityIndicatorStyle.BIG,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        color: "#ff0000",
        id: "activity_indicator"
    });
    $.__views.container.add($.__views.activity_indicator);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var Data = require("data"), theMovieDb = require("themoviedb");
    var args = arguments[0] || {};
    var loaded_callback = args.loaded_callback;
    var lists = [];
    var genres = [];
    var cells = [];
    var image_animation_interval = null;
    var displaying_overlay = false;
    var overlay_controller;
    var displaying_search = false;
    var cellOffset = 0;
    init();
    $.animateIn = function() {
        $.activity_indicator.hide();
        var offset = cellOffset + Alloy.Globals.layout.lists.cell.height;
        $.lists_container.setContentOffset({
            x: 0,
            y: offset
        }, false);
        $.lists_container.animate(Ti.UI.createAnimation({
            opacity: 1,
            duration: 1e3
        }));
        startAnimatingImages();
        Ti.Analytics.featureEvent("view:home");
    };
    $.search_overlay.addEventListener("click", function() {
        hideSearch();
    });
    $.search_textfield.addEventListener("return", function(e) {
        Alloy.Globals.Navigator.push("movies_list", {
            type: "search",
            query: e.value
        });
        setTimeout(function() {
            hideSearch();
        }, 1e3);
    });
    $.searchCell.getView().addEventListener("click", function() {
        $.lists_container.touchEnabled = false;
        $.searchCell.animateClick(function() {
            Ti.Analytics.featureEvent("display:search");
            displaySearch();
            setTimeout(function() {
                $.lists_container.touchEnabled = true;
            }, 1e3);
        });
    });
    $.aboutCell.getView().addEventListener("click", function() {
        handleStaticCellClick($.aboutCell, "about");
    });
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;