(function (self) {
	Object.defineProperties(self.TiGeolocation.prototype, {
		   'accuracy': {set:function(value){this.setAccuracy(value);},get:function(){return this.getAccuracy();},enumerable: true},
		   'distanceFilter': {set:function(value){this.setDistanceFilter(value);},get:function(){return this.getDistanceFilter();},enumerable: true},
		   'headingFilter': {set:function(value){this.setHeadingFilter(value);},get:function(){return this.getHeadingFilter();},enumerable: true},
		   'lastGeolocation': {get:function(){return this.getLastGeolocation();},enumerable: true},
		   'locationServicesEnabled': {get:function(){return this.getLocationServicesEnabled();},enumerable: true},
	});
	
	var exports = new self.TiGeolocation();
	return exports;

})(this);
