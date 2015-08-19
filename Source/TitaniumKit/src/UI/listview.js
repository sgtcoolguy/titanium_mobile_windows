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
function processTemplates(template) {
	lookupCreateFunction(template);

	if (!template.hasOwnProperty('childTemplates')) return;

	var childTemplates = template.childTemplates;
	if (childTemplates === void 0 || childTemplates === null) return;

	for (var i = 0; i < childTemplates.length; i++) {
		lookupCreateFunction(childTemplates[i]);
		processTemplates(childTemplates[i]);
	}
}

function lookupCreateFunction(template) {
	if (template.createView === void 0) {
		var proxyType = template.type;
		if (proxyType !== void 0) {
			var func = lookup(proxyType);
			template.createView = func;
		} else {
			template.createView = Ti.UI.createView;
		}
	}
}

//convert name of UI elements into a constructor function.
//I.e: lookup("Titanium.UI.Label") returns Titanium.UI.createLabel function
function lookup(name) {
	var lastDotIndex = name.lastIndexOf('.');
	var proxy = global;
	var names = name.substring(0, lastDotIndex).split('.');
	for (var i = 0; i < names.length; i++) {
		var property = names[i];
		if (property in proxy) {
			proxy = proxy[property];
		} else {
			return;
		}
	}
	var proxyName = name.slice(lastDotIndex + 1);
	return proxy['create' + proxyName];
}

function ensureLoadTemplates(listview) {
	// prepare default template
	if (!this.loaded) {
		listview.templates[Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT] = LISTVIEW_LIST_ITEM_TEMPLATE_DEFAULT;

		for (var binding in listview.templates) {
			processTemplates(listview.templates[binding]);
		}
		this.loaded = true;
	}
}

// Create item views from section
function createSectionView(listview, section) {
	section.listview = listview;
	section.items = section.items || [];
	listview.templates = listview.templates || [];
	listview.defaultItemTemplate = listview.defaultItemTemplate || Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT;

	ensureLoadTemplates(listview);

	section.views = []; // store views to protect from gc
	for (var i = 0; i < section.items.length; i++) {
		section.views.push(createSectionItemAt(listview, section, i));
	}
	return section.views;
}

function createSectionItemView(item, template, parent) {
	var options = template.properties;
	if (!options) {
		options = {top:0, left:0, width:Ti.UI.SIZE, height:Ti.UI.SIZE};
	}

	if (!template.createView) {
		processTemplates(template);
	}

	var view = template.createView(options);
	if (template.bindId && item[template.bindId]) {
		view.applyProperties(item[template.bindId]);
	} else if (item.properties) {
		// builtin template has different format
		if (template.type == 'Ti.UI.Label' && item.properties.title) {
			view.applyProperties({text:item.properties.title});
		} else if (template.type == 'Ti.UI.ImageView' && item.properties.image) {
			view.applyProperties({image:item.properties.image});
		}
	}
	if (template.childTemplates && Array.isArray(template.childTemplates)) {
		for (var i = 0; i < template.childTemplates.length; i++) {
			createSectionItemView(item, template.childTemplates[i], view);
		}
	}
	if (parent) {
		parent.add(view);
	}
	return view;
}

// Create list item for custom template
function createSectionItemAt(listview, section, index) {
	var item = section.items[index];
	var template = listview.templates[listview.defaultItemTemplate];

	return createSectionItemView(item, template);
}

this.exports = {};
this.exports.createSectionItemAt = createSectionItemAt;
this.exports.createSectionView = createSectionView;
this.exports.processTemplates  = processTemplates;
this.exports.loaded = false;
