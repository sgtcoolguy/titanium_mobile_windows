exports.flash = function(view, callback) {
    var in_animation = Ti.UI.createAnimation({
        opacity: .7,
        curve: Ti.UI.ANIMATION_CURVE_EASE_IN,
        duration: 100
    });
    in_animation.addEventListener("complete", function() {
        var out_animation = Ti.UI.createAnimation({
            opacity: 0,
            curve: Ti.UI.ANIMATION_CURVE_EASE_OUT,
            duration: 300
        });
        out_animation.addEventListener("complete", function() {
            callback();
        });
        view.animate(out_animation);
    });
    view.animate(in_animation);
};