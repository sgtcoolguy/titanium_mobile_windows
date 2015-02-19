/**
 * Titanium.UI.ListView module.
 *
 * @module listview
 *
 * @copyright
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 *
 * @license
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

var LISTVIEW_LIST_ITEM_TEMPLATE_DEFAULT = {
	childTemplates: [
		{
			type: 'Ti.UI.ImageView',
			bindId: 'image',
			properties: {
				left: 0, top: 0
			}
		},
		{
			type: 'Ti.UI.Label', 
			bindId: 'text',
			properties: {
				color: 'black',
				left: 0, top: 0,
			}
		}
	]
}; 

//Recursive function that process childTemplates and append corresponding proxy constructors to
//property 'constructor'. I.e: type: "Titanium.UI.Label" -> constructor: LabelProxy constructor
function processChildTemplates(properties) {
	if (!properties.hasOwnProperty('childTemplates')) return;

	var childProperties = properties.childTemplates;
	if (childProperties === void 0 || childProperties === null) return;

	for (var i = 0; i < childProperties.length; i++) {
		var child = childProperties[i];
		var proxyType = child.type;
		if (proxyType !== void 0 && child.createView === void 0) {
			var creationProperties = child.properties;
			var creationFunction = lookup(proxyType);
			var func = creationFunction;
			func.properties = creationProperties;
			func.events = child.events;
			child.createView = func;
		}

		processChildTemplates(child);
	}
}

//convert name of UI elements into a constructor function.
//I.e: lookup("Titanium.UI.Label") returns Titanium.UI.createLabel function
function lookup(name) {
	var lastDotIndex = name.lastIndexOf('.');
	var proxy = eval(name.substring(0, lastDotIndex));
	if (typeof (proxy) === undefined) return;

	var proxyName = name.slice(lastDotIndex + 1);
	return proxy['create' + proxyName];
}

// Create item views from section
function createSectionView(listview, section) {
	section.items = section.items || [];
	listview.templates = listview.templates || [];
	listview.defaultItemTemplate = listview.defaultItemTemplate || Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT;

	// prepare default template
	if (!this.loaded) {
		listview.templates[Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT] = LISTVIEW_LIST_ITEM_TEMPLATE_DEFAULT;

		for (var binding in listview.templates) {
			processChildTemplates(listview.templates[binding]);
		}
		this.loaded = true;
	}

	section.views = []; // store views to protect from gc
	for (var i = 0; i < section.items.length; i++) {
		section.views.push(createSectionItemAt(listview, section, i));
	}
	return section.views;
}

	// Create list item for custom template
function createSectionItemAt(listview, section, index) {
	var item = section.items[index];
	var template = listview.templates[listview.defaultItemTemplate];

	var view = Ti.UI.createView({top:0, left:0, width:Ti.UI.SIZE, height:Ti.UI.SIZE});
	if (template.childTemplates && Array.isArray(template.childTemplates)) {
		template.childTemplates.forEach(function (ctemplate) {
			try {
				var cview;
				if (item[ctemplate.bindId]) {
					cview = ctemplate.createView(ctemplate.properties);
					cview.applyProperties(item[ctemplate.bindId]);
				} else if (item.properties) {
					// builtin template has different format
					if (ctemplate.type == 'Ti.UI.Label' && item.properties.title) {
						cview = ctemplate.createView(ctemplate.properties);
						cview.applyProperties({text:item.properties.title});
					} else if (ctemplate.type == 'Ti.UI.ImageView' && item.properties.image) {
						cview = ctemplate.createView(ctemplate.properties);
						cview.applyProperties({image:item.properties.image});
					}
				}
				if (cview) {
					view.add(cview);
				}
			} catch (E) {
				Ti.API.warn(E);
			}
		});
	}
	return view;
}

this.exports = {};
this.exports.createSectionView = createSectionView;
this.exports.processChildTemplates = processChildTemplates;
this.exports.loaded = false;
