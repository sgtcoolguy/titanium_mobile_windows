
/**
 * The Titanium Analytics module.
 *
 * @module analytics
 *
 * @copyright
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
var ANALYTICS_URL = "https://api.appcelerator.com/p/v3/mobile-track/",
	// Delays for function to post events to server/URL
	MINOR_SEND_ANALYTICS_DELAY = 5000, // default delay for sending events
	DEFAULT_TIME_SEPARATION_ANALYTICS = 30000, // additional delay for sending certain event types (see sendAnalytics(true);)
	// Database names/fields
	DB_NAME = 'appcAnalytics.db', // Name of the internal database we use to store events
	SEQUENCE = 'Seq', // Name of property we use to track event ids
	ENROLLED = "Enrolled",
	APP_VERSION = "AppVersion";
	// Event types
	EVENT_APP_ENROLL = "ti.enroll",
	EVENT_APP_FOREGROUND = "ti.foreground",
	EVENT_APP_BACKGROUND = "ti.background",
	EVENT_ERROR = "ti.crash",
	EVENT_APP_GEO = "ti.geo",
	// Determine how many events to send at once
	BUCKET_SIZE_FAST_NETWORK = 10,
	BUCKET_SIZE_SLOW_NETWORK = 5; // currently unused

/**
 * Creates the Analytics module object.
 * @class
 * @classdesc Analytics module.
 * @constructor
 */
function Analytics() {
	this.sessionId = Ti.Platform.createUUID();
	this.lastEventID = null;
	this.lastevent = null;
	this.sendEnrollEvent = false;
	this.sending = false;
}

/**
 * @param {String} eventType - event type
 * @param {Object} data - payload data
 * @returns {Object} - the event as an Object
 * @private
 */
Analytics.prototype.createAnalyticsEvent = function createAnalyticsEvent(eventType, data) {
	Ti.API.info('createAnalyticsEvent');
	return {
		type: eventType,
		timestamp: Date.now().toISOString(),
		mid: Ti.Platform.id,
		sid: sessionId,
		appGUID: Ti.App.guid,
		payload: JSON.stringify(data),
		expandPayload: true
	};
};

/**
 * Generates a event object to store in the DB or send along to the analytics server.
 * @param {String} deployType - The deployType to use
 * @private
 */
Analytics.prototype.createAppEnrollEvent = function createAppEnrollEvent(deployType) {
	Ti.API.info('createAppEnrollEvent');
	var json = {
		app_name: Ti.App.name,
		oscpu: Ti.Platform.processorCount,
		platform: Ti.Platform.name,
		app_id: Ti.App.id,
		ostype: Ti.Platform.ostype,
		osarch: Ti.Platform.architecture,
		model: Ti.Platform.model,
		deploytype: deployType,
		app_version: Ti.App.version,
		tz: Date.now().getTimezoneOffset(),
		os: Ti.Platform.osname,
		osver: Ti.Platform.version,
		sdkver: Ti.version,
		nettype: Ti.Network.networkTypeName,
		sequence: undefined
		//		buildtype: 
	};
	return createAnalyticsEvent(EVENT_APP_ENROLL, json);
};

/**
 * @param {String} type - event type
 * @param {String} name - event name
 * @param {Object} data - payload data
 * @private
 */
Analytics.prototype.createEvent = function createEvent(type, name, data) {
	Ti.API.info('createEvent');
	var eventData = data || {};
	eventData['eventName'] = name;
	return createAnalyticsEvent(type, eventData);
};

/**
 * Adds an event to the Database and schedules a job to send it along to the server.
 * @param {Object} event - The event to store in the DB and send along to the server
 * @private
 */
Analytics.prototype.postAnalyticsEvent = function postAnalyticsEvent(event) {
	Ti.API.info('postAnalyticsEvent');
	lastEvent = event;

	if (event.type == EVENT_APP_ENROLL) {
		sendEnrollEvent = needsEnrollEvent();
		if (sendEnrollEvent) {
			lastEventID = addEvent(event);
			sendAnalytics(false);
			markEnrolled();
		}
	} else if (event.type == EVENT_APP_FOREGROUND) {
		var lastEvent = getLastEventForType(EVENT_APP_BACKGROUND);
		if (lastEvent && lastEvent.ts) {
			var lastEnd = Date.parse(lastEvent.ts).getTime();
			var start = Date.parse(event.timestamp).getTime();
			// If the new activity starts immediately after the previous activity pauses, we consider
			// the app is still in foreground so will not send any analytics events
			if (start - lastEnd < DEFAULT_TIME_SEPARATION_ANALYTICS) {
				deleteEvents([ lastEvent['_id'] ]);
				return;
			}
		}

		// We don't want to reset the sid on the first foreground after an enroll event.
		if (sendEnrollEvent) {
			sendEnrollEvent = false;
		} else {
			this.sessionId = Ti.Platform.createUUID();
			event.sid = this.sessionId;
		}

		lastEventID = addEvent(event);
		sendAnalytics(false);
	} else if (event.type == EVENT_APP_BACKGROUND) {
		lastEventID = addEvent(event);
		sendAnalytics(true);
	} else {
		lastEventID = addEvent(event);
		sendAnalytics(false);
	}
}

/**
 * Schedules the run method to trigger after a delay to send along events.
 * @param {Boolean} useSessionTimeout - Whether we should add some additional delay in scheduling the event loop to send the event(s)
 * @private
 */
Analytics.prototype.sendAnalytics = function sendAnalytics(useSessionTimeout) {
	Ti.API.info('sendAnalytics');
	var delay = MINOR_SEND_ANALYTICS_DELAY;
	if (useSessionTimeout) {
		delay += DEFAULT_TIME_SEPARATION_ANALYTICS;
	}
	setTimeout(run, delay); // send the events after a delay
}

/**
 * Returns a boolean indicating if we are online/in a network state where we shoudl send along events to the server.
 * @returns {Boolean}
 * @private
 */
Analytics.prototype.canSend = function canSend() {
	Ti.API.info('canSend');
	if (!Ti.Network.online) {
		return false;
	}

	var type = Ti.Network.networkType;
	if (type == Titanium.Network.NETWORK_MOBILE) {
		// FIXME How do we tell if we're roaming or not? We don't want to send if roaming, but otherwise we're OK!
		return true;
	}
	// TODO What about UNKNOWN or NONE?

	return true;
}

/**
 * The heart of the service, this is meant to run as a scheduled task to send along events to the analytics server via POSTs.
 * @private
 */
Analytics.prototype.run = function run() {
	Ti.API.info("Analytics Service Started");

	if (sending) {
		Ti.API.info("Send already in progress, skipping");
		return;
	}
	sending = true;

	// do we even have events to send?
	if (!hasEvents()) {
		Ti.API.debug("No events to send.");
		Ti.API.info("Stopping Analytics Service");
		sending = false;
		return;
	}
	// are we online?
	if (!canSend()) {
		Ti.API.warn("Network unavailable, can't send analytics");
		Ti.API.info("Stopping Analytics Service");
		sending = false;
		return;
	}

	// keep track of how many times we've tried this set of records
	var retryCount = 0;

	var events = getEventsAsJSON(BUCKET_SIZE_FAST_NETWORK); // map from event id to actual event
	var eventIds = events.keys(); // event ids
	var records = []; // the events to send
	// build up data to send and records to delete on success
	for (var i = 0; i < eventIds.length; i++) {
		var id = eventIds[i];
		var event = events[id];
		// ids are kept even on error JSON to prevent unrestrained growth
		// and a queue blocked by bad records.
		records.unshift(event);
		
		Ti.API.debug("Sending event: type = " + event.event + ", timestamp = " + event.ts);
	}
	events = null; // we don't need this map now. We;ve split them into ids (eventIds) and actual events (records)

	if (records.length > 0) {		
		Ti.API.debug("Sending " + records.length + " analytics events.");
		
		var jsonData = records.toString() + "\n";
		var postUrl = (Ti.App.guid == null) ? ANALYTICS_URL : (ANALYTICS_URL + Ti.App.guid);

		function postRecords() {
			var client = Ti.Network.createHTTPClient({
			    onload : function(e) {
			    	// we posted the events, let's delete them from the DB and reschedule run loop to send next batch of events
			        deleteEvents(eventIds);
					sending = false;
			        setTimeout(run, 1); // try to send the next set of records
			    },

			    onerror : function(e) {
			    	// We failed to send
			        Ti.API.debug("Error posting events: " + e.error);
			        retryCount++;

			        // Stop retrying after 5 attempts, leave the events in the DB.
					if (retryCount >= 5) {
						Ti.API.error("Failed to send analytics events after 5 attempts");
						Ti.API.info("Stopping Analytics Service");
						sending = false;
					} else {
						// if count is 1-4, retry to send this set after 15 seconds
						Ti.API.debug("Failed to send analytics events. Retrying in 15 seconds");
						setTimeout(postRecords, 15000);
					}
			    },
			    timeout : 5000  // in milliseconds
			});
			// Prepare the connection.
			client.open("POST", postUrl);
			client.setRequestHeader("Content-Type", "text/json");
			// Send the request.
			client.send(jsonData);

			//client.params["http.protocol.expect-continue"] = false; // FIXME Do we need this? How would we do it in Titanium?
		};
		postRecords();
	} else {
		Ti.API.info("Stopping Analytics Service");
		sending = false;
	}
	
}

/**
 * Determine if the tables we need are in the database.
 * @private
 */
Analytics.prototype.databaseExists = function databaseExists() {
	Ti.API.info("databaseExists");
	var db = Ti.Database.open(DB_NAME);
	try {
		var resultSet = db.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='Events';");
		try {
			return resultSet.isValidRow() && ('Events' == resultSet.field(0));
		} finally {
			resultSet.close();
		}
	}
	finally {
		db.close();
	}
	return false;
}


/**
 * Create the database we use to store analytics events to send along, and other properties we care about.
 * @private
 */
Analytics.prototype.createDatabase = function createDatabase() {
	Ti.API.info("createDatabase");
	var db = Ti.Database.open(DB_NAME);
	try {
		db.execute("CREATE TABLE Events (_id INTEGER PRIMARY KEY AUTOINCREMENT, EventId TEXT, Event TEXT, Timestamp TEXT, MID TEXT, SID TEXT, AppGUID TEXT, isJSON INTEGER, Payload TEXT, Seq INTEGER);");
		db.execute("CREATE TABLE Props (_id INTEGER PRIMARY KEY, Name TEXT, Value TEXT);");
		db.execute("INSERT INTO Props(Name, Value) VALUES ('Enrolled', '0')");
		db.execute("INSERT INTO Props(Name, Value) VALUES ('AppVersion', ?)", Ti.App.version);
		db.execute("INSERT INTO Props(Name, Value) VALUES (?, '0')", SEQUENCE);
	}
	finally {
		db.close();
	}
}

/**
 * Creates the event id to uniquely identify the event.
 * @returns {String} - the generated event id
 * @private
 */
Analytics.prototype.createEventId = function createEventId() {
	return Ti.Platform.createUUID() + ":" + Ti.Platform.id;
}

/**
 * Looks up a property value by name in the database.
 * @param {String} name - the property name/key to look up.
 * @returns {String} - the value stored for the given property key/name
 * @private
 */
Analytics.prototype.getProps = function getProps(name) {
	Ti.API.info('getProps');
	var db = Ti.Database.open(DB_NAME);
	try {
		var resultSet = db.execute("SELECT Value FROM Props WHERE Name = ?", name.toString());
		try {
			if (!resultSet.isValidRow()) {
				return null;
			}
			return resultSet.field(0, Ti.Database.FIELD_TYPE_STRING);
		} finally {
			resultSet.close();
		}
	}
	finally {
		db.close();
	}
}

/**
 * Stores a value under a name in the database.
 * @param {String} name - the property name/key
 * @param {String} value - the property value
 * @private
 */
Analytics.prototype.updateProps = function updateProps(name, value) {
	Ti.API.info('updateProps');
	var db = Ti.Database.open(DB_NAME);
	try {
		db.execute("UPDATE Props SET Value = ? WHERE Name = ?", value.toString(), name.toString());
	} finally {
		db.close();
	}
}

/**
 * Determines if we've enrolled this app before. If we are enrolled this will also check if the app version has
 * changed and if so will update the app version and reset the sequence counter.
 * @returns {Boolean}
 * @private
 */
Analytics.prototype.needsEnrollEvent = function needsEnrollEvent() {
	Ti.API.info('needsEnrollEvent');
	var appVersion = null,
		isEnrolled = ("1" == getProps(ENROLLED));

	if (isEnrolled) {
		appVersion = getProps(APP_VERSION);
		if (appVersion) {
			if (appVersion != Ti.App.version) { // if new version of app, record version in DB and reset the sequence number
				updateProps(APP_VERSION, Ti.App.version);
				updateProps(SEQUENCE, "0");
			}
		}
	}

	return !isEnrolled;
};

/**
 * Records in the database that we've enrolled.
 * @private
 */
Analytics.prototype.markEnrolled = function markEnrolled() {
	updateProps(ENROLLED, "1");
};

/**
 * Adds an analytics event to our database.
 * @param {Object} event - an Object containing the event data that we want to store in the database
 * @returns {String} - the unique event id of the event we just stored.
 * @private
 */
Analytics.prototype.addEvent = function addEvent(event) {
	Ti.API.info('addEvent');
	var sequence,
		eventID,
		db;
	sequence = Integer.parseInt(getProps(SEQUENCE));
	eventID = createEventId();

	db = Ti.Database.open(DB_NAME);
	try {
		db.execute("INSERT INTO Events(EventId, Event, Timestamp, MID, SID, AppGUID, isJSON, Payload, Seq) VALUES(?,?,?,?,?,?,?,?,?)", 
				eventID, event.type, event.timestamp, event.mid, event.sid, event.appGUID, event.expandPayload ? 1 : 0, event.payload, sequence);
	} finally {
		db.close();
	}
	event.sequence = sequence;
	// Update sequence number after each event
	updateProps(SEQUENCE, String.valueOf(sequence + 1));

	return eventID;
}
/**
 * Deletes a set of events from the database.
 * @param {Array} records - an Array of integer ids to delete
 * @private
 */
Analytics.prototype.deleteEvents = function deleteEvents(records) {
	Ti.API.info('deleteEvents');
	if (!records || records.length == 0) {
		return;
	}

	var db = Ti.Database.open(DB_NAME),
		sql = "DELETE FROM Events WHERE _id IN (";
	
	for (var i = 0; i < records.length; i++) {
		if (i > 0) {
			sql += ", ";
		}
		sql += '?';
	}
	sql += ")";
	try {
		db.execute(sql, records);
	} finally {
		db.close();
	}
};

/**
 * Determines if we have any events stored in our database.
 * @returns {Boolean} indicating if any events are stored in our database.
 * @private
 */
Analytics.prototype.hasEvents = function hasEvents() {
	Ti.API.info('hasEvents');
	var db = Ti.Database.open(DB_NAME);
	try {
		var resultSet = db.execute("SELECT exists(SELECT _id FROM Events)");
		try {
			return (resultSet.field(0, Ti.Database.FIELD_TYPE_INT) != 0);
		} finally {
			resultSet.close();
		}
	} finally {
		db.close();
	}
	return false;
};

/*
 * Composes an event Object from the Database query results. The results use the key names expected by the analytics server, so aren't very long and readable.
 * It makes for a nasty mis-match with createAnalyticsEvent (the objects we use to populate the database).
 * @param {Titanium.Database.ResultSet} resultSet - resultSet pointing at a row of results from the Events table.
 * @private
 */
Analytics.prototype.deserializeEvent = function deserializeEvent(resultSet) {
	Ti.API.info('deserializeEvent');
	var result = {};

	if (resultSet.isValidRow()) {
		result['ver'] = '3';
		result['id'] = resultSet.fieldByName('EventId');
		result['event'] = resultSet.fieldByName('Event');
		result['ts'] = resultSet.fieldByName('Timestamp');
		result['mid'] = resultSet.fieldByName('MID');
		result['sid'] = resultSet.fieldByName('SID');
		result['aguid'] = resultSet.fieldByName('AppGUID');

		var isJSON = (resultSet.fieldByName('isJSON', FIELD_TYPE_INT) == 1) ? true : false;
		if (isJSON) {
			result['data'] = JSON.parse(resultSet.fieldByName('Payload'));
		} else {
			result['data'] = resultSet.fieldByName('Payload');
		}
		result['seq'] = resultSet.fieldByName(SEQUENCE, FIELD_TYPE_INT);

		result['_id'] = resultSet.fieldByName('_id'); // cheat and store the db id in here too
	}

	return result;
}

/*
 * Get the most recent event given the type.
 * @param {String} eventType - type of event we're looking up
 * @private
 */
Analytics.prototype.getLastEventForType = function getLastEventForType(eventType) {
	Ti.API.info('getLastEventForType');
	var db = Ti.Database.open(DB_NAME);	
	try {
		var resultSet = db.execute("SELECT _id, EventId, Event, Timestamp, MID, SID, AppGUID, isJSON, Payload, Seq FROM Events WHERE Event=? ORDER BY Timestamp DESC LIMIT 1;", eventType);
		try {
			if (resultSet.isValidRow()) {
				return deserializeEvent(resultSet);
			}
		} finally {
			resultSet.close();
		}
	} finally {
		db.close();
	}
	return {}; // return empty object if we fail?
}

/*
 * Grab events out of the database
 * @param {Number} limit - max number of records to pull
 * @returns {Array} array of events
 * @private
 */
Analytics.prototype.getEventsAsJSON = function getEventsAsJSON(limit) {
	Ti.API.info('getEventsAsJSON');
	var db = Ti.Database.open(DB_NAME),
		result = {};

	try {
		var resultSet = db.execute("SELECT _id, EventId, Event, Timestamp, MID, SID, AppGUID, isJSON, Payload, Seq FROM Events ORDER BY Timestamp ASC LIMIT ?;", limit);
		try {
			while (resultSet.isValidRow()) {
				var event = deserializeEvent(resultSet);
				result[event['_id']] = event;
				resultSet.next();
			}
		} finally {
			resultSet.close();
		}
	} finally {
		db.close();
	}
	return result;
};

/**
 * Sends a feature event for this application session.
 * @param {String} name - Event name, displayed in Analytics UI.
 * @param {Object} [data] - Extra data related to the event, not displayed in Analytics UI. The object must be serializable as JSON.
 */
Analytics.prototype.featureEvent = function featureEvent(name, data) {
	Ti.API.info('navEvent');
	postAnalyticsEvent(createAppEnrollEvent('development'));
};

/**
 * Sends a navigation event for this application session. Not displayed in Analytics UI.
 * @param {String} from - String describing the location the user navigated from.
 * @param {String} to - String describing the location the user navigated to.
 * @param {String} [name] - Event name.
 * @param {Object} [data] - Extra data related to the event. The object must be serializable as JSON.
 */
Analytics.prototype.navEvent = function navEvent(from, to, name, data) {
	Ti.API.info('navEvent');
	var eventData = data || {};
	eventData['from'] = from;
	eventData['to'] = to;
	postAnalyticsEvent(createEvent("app.nav", name, eventData)); // FIXME We need to fix the createEvent method to handle both invocation types!
};

// TODO Remove once Ti.App module exists!
var app = {
	version: '1.2.3',
	guid: 'a00c4252-eac5-44ac-a9f2-b007391ab119',
	name: 'my_app_name',
	id: 'com.example.app.id',
};
Ti.App = app;

// Create an instance of the module and expose just the methods we want
Ti.API.info('creating instance of Analytics class');
var analytics = new Analytics();
Ti.API.info('checking if database exists');
if (!analytics.databaseExists()) {
	Ti.API.info('creating database');
	analytics.createDatabase();
}
this.exports = {};
this.exports.featureEvent = function(name, data) {
	analytics.featureEvent(name, data);
};
this.exports.navEvent = function(from, to, name, data) {
	analytics.navEvent(from, to, name, data);
};
Object.defineProperty(this.exports, "lastEvent", { value: analytics.lastEvent, writable : false });