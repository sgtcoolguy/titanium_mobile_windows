var Map = require('ti.map');
var win = Titanium.UI.createWindow({
    backgroundColor: 'red'
});

var mountainView = Map.createAnnotation({
    latitude:37.390749,
    longitude:-122.081651,
    title:"Appcelerator Headquarters",
    subtitle:'Mountain View, CA',
    pincolor:Map.ANNOTATION_RED,
    myid:1 // Custom property to uniquely identify this annotation.
});

var mapview = Map.createView({
    mapType: Map.NORMAL_TYPE,
    region: {
        latitude: 37.390749, longitude: -122.081651,
            latitudeDelta:0.01, longitudeDelta:0.01},
    animate:true,
    regionFit:true,
    userLocation:true,
    annotations:[mountainView]
});

win.add(mapview);
// Handle click events on any annotations on this map.
mapview.addEventListener('click', function(evt) {
    Ti.API.info("Annotation " + evt.title + " clicked, id: " + evt.annotation.myid);
});
win.open();