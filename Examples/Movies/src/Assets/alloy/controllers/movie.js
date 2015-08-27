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
        $.activity_indicator.show();
        if (args.id) {
            Ti.Analytics.featureEvent("view:movie");
            fetchMovie(args.id);
        } else args.movie && (movie = args.movie);
    }
    function fetchMovie() {
        Data.movies_get_movie(function(error, e) {
            if (error) Ti.API.error("Error: " + JSON.stringify(JSON.parse(e), null, 4)); else {
                movie = e;
                Ti.Analytics.featureEvent("view:movie." + movie.title);
                populateMovie(e);
            }
        });
    }
    function populateMovie(movie) {
        $.background_imageview.image = theMovieDb.common.getImage({
            size: Alloy.Globals.backdropImageSize,
            file: movie.backdrop_path
        });
        $.poster_imageview.image = theMovieDb.common.getImage({
            size: Alloy.Globals.posterImageSize,
            file: movie.poster_path
        });
        $.title_label.text = movie.title;
        $.info_label.text = durationString(movie.runtime);
        movie.release_date && ($.info_label.text += "  |  " + movie.release_date.substr(0, 4));
        var info_label_max_y = $.info_label.rect.y + $.info_label.rect.height;
        if (movie.homepage || movie.imdb_id) {
            movie.homepage ? $.website_button.top = info_label_max_y + 15 : $.details_view.remove($.website_button);
            if (movie.imdb_id) {
                movie.homepage || ($.imdb_button.left = $.website_button.left);
                $.imdb_button.top = info_label_max_y + 15;
            } else $.details_view.remove($.imdb_button);
        }
        $.synopsis_label.text = movie.overview;
        var synopsis_height = 0;
        $.synopsis_label.addEventListener("postlayout", function() {
            if ($.synopsis_label.rect.height == synopsis_height) return;
            synopsis_height = $.synopsis_label.rect.height;
            $.details_scrollview.contentHeight = $.synopsis_label.rect.y + $.synopsis_label.rect.height + 20;
            $.details_scrollview.contentHeight = Math.max($.details_scrollview.contentHeight, Alloy.Globals.Device.height + 1);
        });
        movie.trailer ? can_play_trailer = true : $.poster.remove($.play_button);
    }
    function durationString(minutes) {
        var hours = Math.floor(minutes / 60);
        minutes -= 60 * hours;
        var duration = hours > 0 ? hours + "h " : "";
        duration += minutes > 9 ? minutes + "m" : "0" + minutes + "m";
        return duration;
    }
    function animateIn() {
        images_loaded++;
        if (2 > images_loaded) return;
        $.activity_indicator.hide();
        var background_animation = Ti.UI.createAnimation({
            opacity: 1,
            duration: 1e3,
            curve: Titanium.UI.ANIMATION_CURVE_EASE_OUT
        });
        $.background_imageview.animate(background_animation);
        var details_animation = Ti.UI.createAnimation({
            opacity: 1,
            duration: 500,
            delay: 800,
            curve: Titanium.UI.ANIMATION_CURVE_EASE_OUT
        });
        $.details_scrollview.animate(details_animation);
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "movie";
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
        backgroundColor: "black",
        orientationModes: [ Ti.UI.PORTRAIT ],
        clipMode: true,
        id: "window"
    });
    $.__views.window && $.addTopLevelView($.__views.window);
    $.__views.background_imageview = Ti.UI.createImageView({
        top: 0,
        left: Alloy.Globals.layout.movie.backdropImageLeft,
        width: Alloy.Globals.layout.movie.backdropImageWidth,
        height: Alloy.Globals.layout.movie.backdropImageHeight,
        preventDefaultImage: true,
        opacity: 0,
        id: "background_imageview"
    });
    $.__views.window.add($.__views.background_imageview);
    $.__views.background_gradient_view = Ti.UI.createView({
        top: 0,
        left: Alloy.Globals.layout.movie.backdropImageLeft,
        width: Alloy.Globals.layout.movie.backdropImageWidth,
        height: Alloy.Globals.layout.movie.backdropImageHeight,
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
                color: "#77000000",
                offset: 0
            }, {
                color: "#77000000",
                offset: .5
            }, {
                color: "#ff000000",
                offset: .9
            } ]
        },
        id: "background_gradient_view"
    });
    $.__views.window.add($.__views.background_gradient_view);
    $.__views.details_scrollview = Ti.UI.createScrollView({
        top: 0,
        left: 0,
        width: Alloy.Globals.Device.width,
        height: Ti.UI.FILL,
        contentWidth: "auto",
        contentHeight: "auto",
        layout: "vertical",
        opacity: 0,
        id: "details_scrollview"
    });
    $.__views.window.add($.__views.details_scrollview);
    $.__views.title_label = Ti.UI.createLabel({
        top: Alloy.Globals.layout.movie.titleTop,
        left: 10,
        right: 10,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 28,
            fontFamily: "HelveticaNeue-Bold"
        },
        color: "#ffffff",
        id: "title_label"
    });
    $.__views.details_scrollview.add($.__views.title_label);
    $.__views.details_view = Ti.UI.createView({
        top: Alloy.Globals.layout.movie.detailsTop,
        left: 10,
        right: 10,
        height: Ti.UI.SIZE,
        id: "details_view"
    });
    $.__views.details_scrollview.add($.__views.details_view);
    $.__views.poster = Ti.UI.createView({
        top: 0,
        left: 0,
        width: Alloy.Globals.layout.movie.posterWidth,
        height: Alloy.Globals.layout.movie.posterHeight,
        id: "poster"
    });
    $.__views.details_view.add($.__views.poster);
    $.__views.poster_imageview = Ti.UI.createImageView({
        borderColor: "#66ffffff",
        borderWidth: .5,
        width: Alloy.Globals.layout.movie.posterWidth,
        height: Alloy.Globals.layout.movie.posterHeight,
        preventDefaultImage: true,
        id: "poster_imageview"
    });
    $.__views.poster.add($.__views.poster_imageview);
    $.__views.poster_overlay_view = Ti.UI.createView({
        backgroundColor: "#ffffff",
        opacity: 0,
        id: "poster_overlay_view"
    });
    $.__views.poster.add($.__views.poster_overlay_view);
    $.__views.play_button = Ti.UI.createButton({
        width: Alloy.Globals.layout.movie.posterWidth,
        height: Alloy.Globals.layout.movie.posterHeight,
        backgroundImage: "/play_button.png",
        backgroundSelectedImage: "/play_button_down.png",
        id: "play_button"
    });
    $.__views.poster.add($.__views.play_button);
    $.__views.info_label = Ti.UI.createLabel({
        top: 0,
        left: Alloy.Globals.layout.movie.infoLeft,
        width: 170,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue-Light"
        },
        color: "#c0c0c0",
        id: "info_label"
    });
    $.__views.details_view.add($.__views.info_label);
    $.__views.website_button = Ti.UI.createButton({
        top: Alloy.Globals.layout.movie.linkButtonTop,
        width: Alloy.Globals.layout.movie.linkButtonWidth,
        height: 30,
        backgroundColor: "#260205",
        borderColor: "#b0332a",
        borderWidth: .5,
        color: "#b0332a",
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue-Light"
        },
        left: Alloy.Globals.layout.movie.infoLeft,
        title: "Website",
        id: "website_button"
    });
    $.__views.details_view.add($.__views.website_button);
    $.__views.imdb_button = Ti.UI.createButton({
        top: Alloy.Globals.layout.movie.linkButtonTop,
        width: Alloy.Globals.layout.movie.linkButtonWidth,
        height: 30,
        backgroundColor: "#260205",
        borderColor: "#b0332a",
        borderWidth: .5,
        color: "#b0332a",
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue-Light"
        },
        left: Alloy.Globals.layout.movie.imdbButtonLeft,
        title: "IMDB",
        id: "imdb_button"
    });
    $.__views.details_view.add($.__views.imdb_button);
    $.__views.synopsis_label = Ti.UI.createLabel({
        top: Alloy.Globals.layout.movie.synopsisTop,
        left: 10,
        right: 10,
        height: Ti.UI.SIZE,
        font: {
            fontSize: 14,
            fontFamily: "HelveticaNeue"
        },
        backgroundColor: "transparent",
        color: "#d0d0d0",
        id: "synopsis_label"
    });
    $.__views.details_scrollview.add($.__views.synopsis_label);
    $.__views.activity_indicator = Ti.UI.createActivityIndicator({
        style: Ti.UI.ActivityIndicatorStyle.BIG,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        color: "#ff0000",
        id: "activity_indicator"
    });
    $.__views.window.add($.__views.activity_indicator);
    $.__views.__alloyId6 = Alloy.createController("views/navbar", {
        id: "__alloyId6",
        __parentSymbol: $.__views.window
    });
    $.__views.__alloyId6.setParent($.__views.window);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var Data = require("data"), theMovieDb = require("themoviedb"), yt = require("youtube"), animation = require("animation");
    var IMDB_BASE_URL = "http://www.imdb.com/title/";
    var args = arguments[0] || {};
    var movie;
    var images_loaded = 0;
    var can_play_trailer = false;
    $.window.addEventListener("open", init);
    $.background_imageview.addEventListener("load", function(e) {
        $.background_gradient_view.height = e.source.rect.height + 2;
        animateIn();
    });
    $.poster_imageview.addEventListener("load", animateIn);
    $.details_scrollview.addEventListener("scroll", function(e) {
        var opacity = 1;
        var offset = e.y;
        if (0 >= offset) {
            var height = Alloy.Globals.layout.movie.backdropImageHeight - offset;
            var scale = height / Alloy.Globals.layout.movie.backdropImageHeight;
            var transform = Ti.UI.create2DMatrix({
                scale: scale
            });
            transform = transform.translate(0, -offset / (2 * scale));
            $.background_imageview.transform = $.background_gradient_view.transform = transform;
            $.background_imageview.opacity = 1;
        } else if (offset > 0) {
            opacity = Math.max(1 - offset / 200, .5);
            $.background_imageview.opacity = opacity;
        }
    });
    $.play_button.addEventListener("click", function() {
        if (can_play_trailer) {
            Ti.Analytics.featureEvent("view:trailer");
            $.play_button.touchEnabled = false;
            animation.flash($.poster_overlay_view, function() {
                yt.play(movie.trailer.source);
                setTimeout(function() {
                    $.play_button.touchEnabled = true;
                }, 2e3);
            });
        }
    });
    $.website_button.addEventListener("click", function() {
        if (movie.homepage) {
            Ti.Analytics.featureEvent("open:movie.website");
            Ti.Platform.openURL(movie.homepage);
        }
    });
    $.imdb_button.addEventListener("click", function() {
        if (movie.imdb_id) {
            Ti.Analytics.featureEvent("open:movie.imdb");
            Ti.Platform.openURL(IMDB_BASE_URL + movie.imdb_id);
        }
    });
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;