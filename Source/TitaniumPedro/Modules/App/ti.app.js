(function(self){
		Object.defineProperties(self.TiApp.prototype, {
		    'EVENT_ACCESSIBILITY_ANNOUNCEMENT' : {get:function(){ return 'accessibilityannouncement'; }, enumerable : true},
		    'EVENT_ACCESSIBILITY_CHANGED' : {get:function(){ return 'accessibilitychanged'; }, enumerable : true},
		    'analytics' : {get:function(){ return this.getAnalytics(); }, enumerable : true},
			'accessibilityEnabled' : {get:function(){ return this.getAccessibilityEnabled(); }, enumerable : true},
		    'disableNetworkActivityIndicator' : {set:function(value){ this.setDisableNetworkActivityIndicator(value); }, get : function(){ return this.getDisableNetworkActivityIndicator(); }, enumerable : true},
		    'forceSplashAsSnapshot' : {set:function(value){ this.setForceSplashAsSnapshot(value); }, get : function(){ return this.getForceSplashAsSnapshot(); }, enumerable : true},
		    'idleTimerDisabled' : {set:function(value){ this.setIdleTimerDisabled(value); }, get : function(){ return this.getIdleTimerDisabled(); }, enumerable : true},
		    'keyboardVisible' : {get:function(){ return this.getKeyboardVisible(); }, enumerable : true},
		    'proximityDetection' : {set:function(value){ this.setProximityDetection(value); }, get : function(){ return this.getProximityDetection(); }, enumerable : true},
		    'proximityState' : {get:function(){ return this.getProximityState(); }, enumerable : true},
		    'sessionId' : {get:function(){ return this.getSessionId(); }, enumerable : true},
		});
		    var exports = new self.TiApp();
		    exports.Properties = new self.TiAppProperties();
			
			// Get/Set Object
		    exports.Properties.setObject = function(property, value) {exports.Properties.setString(property, JSON.stringify(value));};
		    exports.Properties.getObject = function(property) {return JSON.parse(exports.Properties.getString(property));};
		    
			// Get/Set List
			exports.Properties.setList = function(property, value) {exports.Properties.setString(property, JSON.stringify(value));};
		    exports.Properties.getList = function(property) {return JSON.parse(exports.Properties.getString(property));};
		    
			// Deploy type
			exports.deployType = "__DEPLOY_TYPE__";
			exports.getDeployType = function () {
				return exports.deployType;
			}
			
			// Id
			exports.id = "__ID__";
			exports.getId = function () {
				return exports.id;
			}
			
			// InstallId
			exports.installId = "__INSTALL_ID__";
			exports.getInstallId = function () {
				return exports.installId;
			}
			
			// Publisher
			exports.publisher = "__PUBLISHER__";
			exports.getPublisher = function () {
				return exports.publisher;
			}
			
			// Url
			exports.url = "__URL__";
			exports.getUrl = function () {
				return exports.url;
			}
			
			// Name
			exports.name = "__NAME__";
			exports.getName = function () {
				return exports.name;
			}
			
			// Version
			exports.version = "__VERSION__";
			exports.getVersion = function () {
				return exports.version;
			}
			
			// Description
			exports.description = "__DESCRIPTION__";
			exports.getDescription = function () {
				return exports.description;
			}
			
			// Copyright
			exports.copyright = "__COPYRIGHT__";
			exports.getCopyright = function () {
				return exports.copyright;
			}
			
			// GUID
			exports.guid = "__GUID__";
			exports.getGuid = function () {
				return exports.guid;
			}

			// Event hook for fireEvent, to delegate all Ti.App events onto WebView.
			// Do not call fireEvent() here otherwise you'll end up in infinite loop.
			exports.__ti_private__.fireEventHook = function(_string, _object) {
				// shortcut for callback
				exports._fireEventHook(_string, _object);
			};
			
			return exports;
		})(this);
