function __processArg(obj, key) {
    var arg = null;
    if (obj) {
        arg = obj[key] || null;
        delete obj[key];
    }
    return arg;
}

function Controller() {
    function isBookmark(id) {
        return _.find(bookmarks, function(mark) {
            return id === mark;
        });
    }
    function emailContact() {
        Ti.Analytics.featureEvent(Ti.Platform.osname + ".profile.emailButton.clicked");
        var emailDialog = Ti.UI.createEmailDialog();
        emailDialog.toRecipients = [ _args.email ];
        emailDialog.open();
    }
    function callContact() {
        Ti.Analytics.featureEvent(Ti.Platform.osname + ".profile.callContactButton.clicked");
        var dialog = Ti.UI.createAlertDialog({
            cancel: 0,
            buttonNames: [ "Cancel", "Ok" ],
            message: "Are you sure you want to call " + _args.firstName + " at " + _args.phone
        });
        dialog.addEventListener("click", function(e) {
            e.index !== e.source.cancel && Ti.Platform.openURL("tel:+15125551212");
        });
        dialog.show();
    }
    function toggleBookmark() {
        if (isBookmark(_args.id)) {
            Ti.Analytics.featureEvent(Ti.Platform.osname + ".profile.removeBookmark.clicked");
            bookmarks = _.difference(bookmarks, [ _args.id ]);
            $.addBookmarkBtn.setTitle("+ Add To Bookmarks");
        } else {
            Ti.Analytics.featureEvent(Ti.Platform.osname + ".profile.addBookmark.clicked");
            bookmarks.push(_args.id);
            $.addBookmarkBtn.setTitle("- Remove From Bookmarks");
        }
        Ti.App.Properties.setList("bookmarks", bookmarks);
        Ti.App.fireEvent("refresh-data");
    }
    require("alloy/controllers/BaseController").apply(this, Array.prototype.slice.call(arguments));
    this.__controllerPath = "profile";
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
    $.__views.profile = Ti.UI.createView({
        height: Ti.UI.FILL,
        width: Ti.UI.FILL,
        backgroundColor: "#fff",
        title: "Profile",
        id: "profile"
    });
    $.__views.profile && $.addTopLevelView($.__views.profile);
    $.__views.__alloyId34 = Ti.UI.createView({
        layout: "vertical",
        top: 10,
        left: 10,
        right: 10,
        bottom: 10,
        id: "__alloyId34"
    });
    $.__views.profile.add($.__views.__alloyId34);
    $.__views.__alloyId35 = Ti.UI.createView({
        layout: "vertical",
        bottom: 10,
        width: "100%",
        height: Ti.UI.SIZE,
        id: "__alloyId35"
    });
    $.__views.__alloyId34.add($.__views.__alloyId35);
    $.__views.__alloyId36 = Ti.UI.createView({
        width: "100%",
        height: Ti.UI.SIZE,
        id: "__alloyId36"
    });
    $.__views.__alloyId35.add($.__views.__alloyId36);
    $.__views.emailBtn = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        left: 10,
        height: 60,
        width: 60,
        color: "#C41230",
        borderRadius: 30,
        borderWidth: 1,
        borderColor: "#C41230",
        textAlign: "center",
        font: {
            fontSize: 24
        },
        backgroundColor: "#22C41230",
        id: "emailBtn",
        icon: "icon-envelope",
        __parentSymbol: $.__views.__alloyId36
    });
    $.__views.emailBtn.setParent($.__views.__alloyId36);
    $.__views.profilePicture = Ti.UI.createImageView({
        preventDefaultImage: true,
        top: 10,
        touchEnabled: false,
        height: 125,
        width: 125,
        borderRadius: 63,
        borderWidth: 1,
        borderColor: "#22C41230",
        id: "profilePicture"
    });
    $.__views.__alloyId36.add($.__views.profilePicture);
    $.__views.callBtn = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        right: 10,
        height: 60,
        width: 60,
        color: "#C41230",
        borderRadius: 30,
        borderWidth: 1,
        borderColor: "#C41230",
        textAlign: "center",
        font: {
            fontSize: 24
        },
        backgroundColor: "#22C41230",
        id: "callBtn",
        icon: "icon-phone",
        __parentSymbol: $.__views.__alloyId36
    });
    $.__views.callBtn.setParent($.__views.__alloyId36);
    $.__views.__alloyId37 = Ti.UI.createView({
        layout: "vertical",
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId37"
    });
    $.__views.__alloyId35.add($.__views.__alloyId37);
    $.__views.name = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        top: 10,
        font: {
            fontSize: 24
        },
        color: "#C41230",
        touchEnabled: false,
        text: "Kelly Smith",
        id: "name"
    });
    $.__views.__alloyId37.add($.__views.name);
    $.__views.job = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        font: {
            fontSize: 14
        },
        color: "#666",
        touchEnabled: false,
        text: "Account Rep",
        id: "job"
    });
    $.__views.__alloyId37.add($.__views.job);
    $.__views.company = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        font: {
            fontSize: 14
        },
        color: "#666",
        touchEnabled: false,
        text: "Appcelerator, Inc",
        id: "company"
    });
    $.__views.__alloyId37.add($.__views.company);
    $.__views.addBookmarkBtn = Ti.UI.createButton({
        width: "100%",
        height: Ti.UI.SIZE,
        font: {
            fontSize: 18
        },
        title: "+ Add to Bookmarks",
        id: "addBookmarkBtn"
    });
    $.__views.__alloyId34.add($.__views.addBookmarkBtn);
    toggleBookmark ? $.__views.addBookmarkBtn.addEventListener("click", toggleBookmark) : __defers["$.__views.addBookmarkBtn!click!toggleBookmark"] = true;
    var __alloyId39 = [];
    $.__views.__alloyId40 = Ti.UI.createView({
        layout: "vertical",
        top: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId40"
    });
    __alloyId39.push($.__views.__alloyId40);
    $.__views.__alloyId41 = Ti.UI.createView({
        layout: "horizontal",
        width: "100%",
        height: Ti.UI.SIZE,
        id: "__alloyId41"
    });
    $.__views.__alloyId40.add($.__views.__alloyId41);
    $.__views.__alloyId42 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        left: 10,
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-qrcode",
        id: "__alloyId42",
        __parentSymbol: $.__views.__alloyId41
    });
    $.__views.__alloyId42.setParent($.__views.__alloyId41);
    $.__views.__alloyId43 = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        right: 10,
        font: {
            fontSize: 24
        },
        color: "#C41230",
        text: "Contact Info",
        id: "__alloyId43"
    });
    $.__views.__alloyId41.add($.__views.__alloyId43);
    $.__views.__alloyId44 = Ti.UI.createView({
        layout: "horizontal",
        top: 10,
        left: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId44"
    });
    $.__views.__alloyId40.add($.__views.__alloyId44);
    $.__views.__alloyId45 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-phone",
        id: "__alloyId45",
        __parentSymbol: $.__views.__alloyId44
    });
    $.__views.__alloyId45.setParent($.__views.__alloyId44);
    $.__views.phone = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        right: 10,
        font: {
            fontSize: 14
        },
        color: "#666",
        text: "512-555-1212",
        id: "phone"
    });
    $.__views.__alloyId44.add($.__views.phone);
    $.__views.__alloyId46 = Ti.UI.createView({
        layout: "horizontal",
        top: 10,
        left: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId46"
    });
    $.__views.__alloyId40.add($.__views.__alloyId46);
    $.__views.__alloyId47 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-envelope-alt",
        id: "__alloyId47",
        __parentSymbol: $.__views.__alloyId46
    });
    $.__views.__alloyId47.setParent($.__views.__alloyId46);
    $.__views.email = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        right: 10,
        font: {
            fontSize: 14
        },
        color: "#666",
        text: "kelly.smith@appcelerator.com",
        id: "email"
    });
    $.__views.__alloyId46.add($.__views.email);
    $.__views.__alloyId48 = Ti.UI.createView({
        layout: "horizontal",
        top: 10,
        left: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId48"
    });
    $.__views.__alloyId40.add($.__views.__alloyId48);
    $.__views.__alloyId49 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-comment",
        id: "__alloyId49",
        __parentSymbol: $.__views.__alloyId48
    });
    $.__views.__alloyId49.setParent($.__views.__alloyId48);
    $.__views.im = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        right: 10,
        font: {
            fontSize: 14
        },
        color: "#666",
        text: "kelly.smith",
        id: "im"
    });
    $.__views.__alloyId48.add($.__views.im);
    $.__views.__alloyId50 = Ti.UI.createView({
        layout: "vertical",
        top: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId50"
    });
    __alloyId39.push($.__views.__alloyId50);
    $.__views.__alloyId51 = Ti.UI.createView({
        layout: "horizontal",
        width: "100%",
        height: Ti.UI.SIZE,
        id: "__alloyId51"
    });
    $.__views.__alloyId50.add($.__views.__alloyId51);
    $.__views.__alloyId52 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        left: 10,
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-info-sign",
        id: "__alloyId52",
        __parentSymbol: $.__views.__alloyId51
    });
    $.__views.__alloyId52.setParent($.__views.__alloyId51);
    $.__views.__alloyId53 = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        right: 10,
        font: {
            fontSize: 24
        },
        color: "#C41230",
        text: "About",
        id: "__alloyId53"
    });
    $.__views.__alloyId51.add($.__views.__alloyId53);
    $.__views.__alloyId54 = Ti.UI.createScrollView({
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId54"
    });
    $.__views.__alloyId50.add($.__views.__alloyId54);
    $.__views.about = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        font: {
            fontSize: 14
        },
        color: "#666",
        width: Ti.UI.SIZE,
        text: "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.",
        id: "about"
    });
    $.__views.__alloyId54.add($.__views.about);
    $.__views.__alloyId55 = Ti.UI.createView({
        layout: "vertical",
        top: 10,
        height: Ti.UI.SIZE,
        width: Ti.UI.SIZE,
        id: "__alloyId55"
    });
    __alloyId39.push($.__views.__alloyId55);
    $.__views.__alloyId56 = Ti.UI.createView({
        layout: "horizontal",
        width: "100%",
        height: Ti.UI.SIZE,
        id: "__alloyId56"
    });
    $.__views.__alloyId55.add($.__views.__alloyId56);
    $.__views.__alloyId57 = Alloy.createWidget("net.hoyohoyo.iconiclabel", "widget", {
        left: 10,
        color: "#C41230",
        font: {
            fontFamily: "FontAwesome",
            fontSize: 20
        },
        icon: "icon-map-marker",
        id: "__alloyId57",
        __parentSymbol: $.__views.__alloyId56
    });
    $.__views.__alloyId57.setParent($.__views.__alloyId56);
    $.__views.__alloyId58 = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        left: 10,
        font: {
            fontSize: 24
        },
        color: "#C41230",
        text: "Location",
        id: "__alloyId58"
    });
    $.__views.__alloyId56.add($.__views.__alloyId58);
    $.__views.fromHQ = Ti.UI.createLabel({
        autoLink: Ti.UI.AUTOLINK_ALL,
        right: 10,
        bottom: 0,
        font: {
            fontSize: 12
        },
        color: "#666",
        width: Ti.UI.FILL,
        height: Ti.UI.SIZE,
        textAlign: "right",
        id: "fromHQ"
    });
    $.__views.__alloyId56.add($.__views.fromHQ);
    var __alloyId59 = [];
    $.__views.mapview = require("ti.map").createView({
        top: 10,
        left: 10,
        right: 10,
        bottom: 10,
        border: 10,
        borderColor: "#666",
        touchEnabled: false,
        enableZoomControls: false,
        compassEnabled: false,
        annotations: __alloyId59,
        id: "mapview"
    });
    $.__views.__alloyId55.add($.__views.mapview);
    $.__views.__alloyId38 = Ti.UI.createScrollableView({
        height: "45%",
        pagingControlColor: "#C41230",
        showPagingControl: true,
        top: 10,
        views: __alloyId39,
        pagingControlHeight: "20",
        id: "__alloyId38"
    });
    $.__views.__alloyId34.add($.__views.__alloyId38);
    exports.destroy = function() {};
    _.extend($, $.__views);
    var _args = arguments[0] || {}, Map = (Alloy.Globals.App, require("ti.map")), $U = require("utilities"), bookmarks = null;
    $.profilePicture.image = _args.photo;
    $.name.text = _args.firstName + " " + _args.lastName;
    $.company.text = _args.company;
    $.phone.text = _args.phone;
    $.email.text = _args.email;
    $.im.text = _args.im || _args.firstName + "." + _args.lastName;
    $.about.text = _args.about;
    var distanceFromAppcelerator = Math.floor($U.getDistanceFromLatLonInMiles(_args.latitude, _args.longitude, 37.389505, -122.050252));
    $.fromHQ.text = distanceFromAppcelerator + " miles from HQ";
    $.emailBtn.icon.addEventListener("click", emailContact);
    $.callBtn.icon.addEventListener("click", callContact);
    $.mapview.setRegion({
        latitude: _args.latitude || 30.631256,
        longitude: _args.longitude || -97.675422,
        latitudeDelta: 2,
        longitudeDelta: 2
    });
    var mapAnnotation = Map.createAnnotation({
        latitude: _args.latitude || 30.631256,
        longitude: _args.longitude || -97.675422,
        pincolor: Map.ANNOTATION_RED
    });
    $.mapview.addAnnotation(mapAnnotation);
    bookmarks = Ti.App.Properties.getList("bookmarks", []);
    isBookmark(_args.id) && $.addBookmarkBtn.setTitle("- Remove From Bookmarks");
    Ti.Analytics.featureEvent(Ti.Platform.osname + ".profile.viewed");
    __defers["$.__views.addBookmarkBtn!click!toggleBookmark"] && $.__views.addBookmarkBtn.addEventListener("click", toggleBookmark);
    _.extend($, exports);
}

var Alloy = require("alloy"), Backbone = Alloy.Backbone, _ = Alloy._;

module.exports = Controller;