function getURLArgs(_string) {
    var args = {};
    var pairs = _string.split("&");
    for (var i = 0; i < pairs.length; i++) {
        var pos = pairs[i].indexOf("=");
        if (-1 == pos) continue;
        var argname = pairs[i].substring(0, pos);
        var value = pairs[i].substring(pos + 1);
        args[argname] = unescape(value);
    }
    return args;
}

function h264videosWithYoutubeURL(_youtubeId, _callbackOk, _callbackError) {
    var youtubeInfoUrl = "http://www.youtube.com/get_video_info?video_id=" + _youtubeId;
    var request = Titanium.Network.createHTTPClient({
        timeout: 1e4
    });
    request.open("GET", youtubeInfoUrl);
    request.onerror = function(_event) {
        _callbackError && _callbackError({
            status: this.status,
            error: _event.error
        });
    };
    request.onload = function() {
        var qualities = [];
        var response = this.responseText;
        var args = getURLArgs(response);
        if (args.hasOwnProperty("url_encoded_fmt_stream_map")) {
            var fmtstring = args["url_encoded_fmt_stream_map"];
            var fmtarray = fmtstring.split(",");
            for (var i = 0, j = fmtarray.length; j > i; i++) {
                var args2 = getURLArgs(fmtarray[i]);
                var type = decodeURIComponent(args2["type"]);
                if (type.indexOf("mp4") >= 0) {
                    var url = decodeURIComponent(args2["url"]);
                    {
                        decodeURIComponent(args2["quality"]);
                    }
                    qualities.push(url);
                }
            }
            _callbackOk && _callbackOk(qualities[0]);
        } else _callbackError && _callbackError();
    };
    request.send();
}

function getVideo(id) {
    var client = Ti.Network.createHTTPClient();
    client.onload = function() {
        var json = decodeURIComponent(decodeURIComponent(decodeURIComponent(decodeURIComponent(this.responseText.substring(4, this.responseText.length)))));
        var response = JSON.parse(json);
        var video = response.content.video;
        var isHighQuality = null != video["fmt_stream_map"];
        var streamUrl = isHighQuality ? video["fmt_stream_map"][0].url : video.stream_url;
        isHighQuality || Ti.API.info("using low quality video because fmt_stream_map does not exist in json response, User-Agent probably is not being sent correctly");
        playVideo(streamUrl);
    };
    client.open("GET", "http://m.youtube.com/watch?ajax=1&layout=mobile&tsp=1&utcoffset=330&v=" + id);
    client.send();
}

function playVideo(url) {
    videoPlayer = Ti.Media.createVideoPlayer({
        backgroundColor: "#000",
        url: url,
        fullscreen: true,
        autoplay: true,
        scalingMode: Ti.Media.VIDEO_SCALING_ASPECT_FIT,
        mediaControlMode: Ti.Media.VIDEO_CONTROL_DEFAULT
    });
    videoPlayer.addEventListener("complete", function() {
        Ti.API.info("video player complete");
        exports.close();
    });
    videoPlayer.addEventListener("fullscreen", function(e) {
        if (!e.entering) {
            Ti.API.info("video player fullscreen exit");
            exports.close();
        }
    });
}

var lib = Alloy.Globals;

var win = null, videoPlayer = null;

exports.isPlaying = false;

exports.play = function(id) {
    exports.isPlaying = true;
    h264videosWithYoutubeURL(id, function(e) {
        playVideo(e);
    }, function(e) {
        Ti.API.error("Error: " + e);
    });
};

exports.close = function() {
    Ti.API.info("closing video player");
    if (videoPlayer) {
        videoPlayer.hide();
        videoPlayer.release();
        videoPlayer = null;
    }
    exports.isPlaying = false;
};