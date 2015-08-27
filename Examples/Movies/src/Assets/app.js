function orientationChange(_event) {
    if (_event.orientation === Titanium.UI.FACE_UP || _event.orientation === Titanium.UI.FACE_DOWN || _event.orientation === Titanium.UI.UNKNOWN) return;
    Alloy.Globals.Device.orientation = _event.source.isLandscape() ? "landscape" : "portrait";
    Ti.App.fireEvent("orientationChange", {
        orientation: Alloy.Globals.Device.orientation
    });
}

function setViewsForOrientation(_controller) {
    if (!Alloy.Globals.Device.orientation) return;
    if ("portrait" == Alloy.Globals.Device.orientation || "landscape" == Alloy.Globals.Device.orientation) for (var view in _controller.__views) _controller.__views[view][Alloy.Globals.Device.orientation] && "function" == typeof _controller.__views[view].applyProperties ? _controller.__views[view].applyProperties(_controller.__views[view][Alloy.Globals.Device.orientation]) : _controller.__views[view].wrapper && _controller.__views[view].wrapper[Alloy.Globals.Device.orientation] && "function" == typeof _controller.__views[view].applyProperties && _controller.__views[view].applyProperties(_controller.__views[view].wrapper[Alloy.Globals.Device.orientation]);
}

function getBestImageSize(sizes, target) {
    var bestSizeValue = 999999;
    var bestSize = "original";
    for (var i = 0; i < sizes.length; i++) {
        var size = sizes[i];
        if ("original" != size) {
            var sizeValue = parseInt(size.substr(1, size.length));
            if (bestSizeValue > sizeValue && sizeValue > target) {
                bestSizeValue = sizeValue;
                bestSize = size;
            }
        }
    }
    return bestSize;
}

var Alloy = require("alloy"), _ = Alloy._, Backbone = Alloy.Backbone;

Alloy.Globals.PROPERTY_ENABLE_MOTION_ANIMATION = "PROPERTY_ENABLE_MOTION_ANIMATION";

Alloy.Globals.PROPERTY_ENABLE_LIST_ANIMATION = "PROPERTY_ENABLE_LIST_ANIMATION";

Ti.App.Properties.hasProperty(Alloy.Globals.PROPERTY_ENABLE_MOTION_ANIMATION) || Ti.App.Properties.setBool(Alloy.Globals.PROPERTY_ENABLE_MOTION_ANIMATION, true);

Ti.App.Properties.hasProperty(Alloy.Globals.PROPERTY_ENABLE_LIST_ANIMATION) || Ti.App.Properties.setBool(Alloy.Globals.PROPERTY_ENABLE_LIST_ANIMATION, true);

Alloy.Globals.EVENT_PROPERTY_ENABLE_MOTION_ANIMATION_DID_CHANGE = "EVENT_PROPERTY_ENABLE_MOTION_ANIMATION_DID_CHANGE";

Alloy.Globals.EVENT_PROPERTY_ENABLE_LIST_ANIMATION_DID_CHANGE = "EVENT_PROPERTY_ENABLE_LIST_ANIMATION_DID_CHANGE";

Alloy.Globals.Navigator = {};

Alloy.Globals.initNavigation = function() {
    Alloy.Globals.Navigator = require("navigation")({
        parent: Alloy.Globals.navigationWindow || null
    });
};

Alloy.Globals.Device = {
    version: Ti.Platform.version,
    versionMajor: parseInt(Ti.Platform.version.split(".")[0], 10),
    versionMinor: parseInt(Ti.Platform.version.split(".")[1], 10),
    width: Ti.Platform.displayCaps.platformWidth > Ti.Platform.displayCaps.platformHeight ? Ti.Platform.displayCaps.platformHeight : Ti.Platform.displayCaps.platformWidth,
    height: Ti.Platform.displayCaps.platformWidth > Ti.Platform.displayCaps.platformHeight ? Ti.Platform.displayCaps.platformWidth : Ti.Platform.displayCaps.platformHeight,
    dpi: Ti.Platform.displayCaps.dpi,
    orientation: Ti.Gesture.orientation == Ti.UI.LANDSCAPE_LEFT || Ti.Gesture.orientation == Ti.UI.LANDSCAPE_RIGHT ? "landscape" : "portrait"
};

Alloy.Globals.dpToPx = function(dp) {
    return dp * (Ti.Platform.displayCaps.platformHeight / Alloy.Globals.Device.height);
};

Alloy.Globals.pxToDp = function(px) {
    return px * (Alloy.Globals.Device.height / Ti.Platform.displayCaps.platformHeight);
};

Alloy.Globals.bindOrientationEvents = function(_controller) {
    _controller.window.addEventListener("close", function() {
        _controller.handleOrientation && Ti.App.removeEventListener("orientationChange", _controller.handleOrientation);
    });
    _controller.window.addEventListener("open", function() {
        Ti.App.addEventListener("orientationChange", function(_event) {
            _controller.handleOrientation && _controller.handleOrientation(_event);
            setViewsForOrientation(_controller);
        });
    });
};

Ti.Gesture.addEventListener("orientationchange", orientationChange);

Alloy.Globals.calculateElementDimensions = function(size) {
    var layout = {};
    layout.intro = {};
    layout.intro.clapperTopContainerTop = size.height / 2 - 43;
    layout.intro.clapperTopContainerLeft = size.width / 2 - 150;
    layout.intro.clapperBottomTop = layout.intro.clapperTopContainerTop + 31;
    layout.intro.clapperBottomLeft = size.width / 2 - 50;
    layout.intro.activityViewTop = layout.intro.clapperTopContainerTop + 130;
    layout.optionButtons = {};
    layout.optionButtons.width = size.width / 3;
    layout.optionButtons.height = .3 * layout.optionButtons.width;
    layout.overlay = {};
    layout.overlay.width = size.width > 400 ? 360 : size.width - 40;
    layout.lists = {};
    layout.lists.userCell = {};
    layout.lists.userCell.width = size.width - 20;
    layout.lists.userCell.imageLeft = -layout.lists.userCell.width / 6;
    layout.lists.userCell.imageWidth = Math.abs(2 * layout.lists.userCell.imageLeft) + layout.lists.userCell.width;
    layout.lists.userCell.imageHeight = Math.ceil(9 * layout.lists.userCell.imageWidth) / 16;
    layout.lists.cell = {};
    layout.lists.cell.width = (size.width - 30) / 2;
    layout.lists.cell.height = layout.lists.cell.width;
    layout.lists.cell.imageTop = -20;
    layout.lists.cell.imageLeft = -layout.lists.cell.width;
    layout.lists.cell.imageWidth = Math.abs(2 * layout.lists.cell.imageLeft) + layout.lists.cell.width;
    layout.lists.cell.imageHeight = Math.ceil(9 * layout.lists.cell.imageWidth) / 16;
    layout.list = {};
    layout.list.row = {};
    layout.list.row.width = size.width;
    layout.list.row.height = Math.ceil(size.width / 2.5);
    layout.list.row.imageHeight = Math.ceil(9 * size.width / 16);
    layout.movie = {};
    layout.movie.backdropImageLeft = .15 * -size.width;
    layout.movie.backdropImageWidth = 1.3 * size.width;
    layout.movie.backdropImageHeight = Math.ceil(9 * layout.movie.backdropImageWidth / 16);
    layout.movie.titleTop = .5 * layout.movie.backdropImageHeight;
    layout.movie.detailsTop = 15;
    layout.movie.posterWidth = Math.ceil(size.width / 3);
    layout.movie.posterHeight = 1.5 * layout.movie.posterWidth;
    layout.movie.infoLeft = layout.movie.posterWidth + 15;
    layout.movie.infoWidth = size.width - layout.movie.infoLeft - 20;
    layout.movie.linkButtonTop = 40;
    layout.movie.linkButtonWidth = (layout.movie.infoWidth - 10) / 2;
    layout.movie.imdbButtonLeft = layout.movie.infoLeft + layout.movie.linkButtonWidth + 10;
    layout.movie.synopsisTop = 20;
    return layout;
};

Alloy.Globals.layout = Alloy.Globals.calculateElementDimensions(Alloy.Globals.Device);

Alloy.Globals.backdropImageSize = "original";

Alloy.Globals.setBackdropImageSize = function(sizes) {
    Alloy.Globals.backdropImageSize = getBestImageSize(sizes, Alloy.Globals.Device.width);
    Ti.API.info("Backdrop size for " + Alloy.Globals.Device.width + ": " + Alloy.Globals.backdropImageSize);
};

Alloy.Globals.posterImageSize = "original";

Alloy.Globals.setPosterImageSize = function(sizes) {
    Alloy.Globals.posterImageSize = getBestImageSize(sizes, Alloy.Globals.layout.movie.posterWidth);
    Ti.API.info("Poster size for " + Alloy.Globals.layout.movie.posterWidth + ": " + Alloy.Globals.posterImageSize);
};

Alloy.CFG.run_logic_tests && require("tests/tests_runner");

Alloy.createController("index");