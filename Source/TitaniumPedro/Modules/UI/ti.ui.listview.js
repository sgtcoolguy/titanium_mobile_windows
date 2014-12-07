/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
exports = function (self) {
    var ListView = self.TiUIListView;
    var ListItem = self.TiUIListItem;
    var ListSection = self.TiUIListSection;

    // Ti.UI.ListView functions
    ListView.prototype.getTemplates = function () {
        return this.templates;
    };
    ListView.prototype.setTemplates = function (value) {
        this.templates = value;
    };
    ListView.prototype.getDefaultItemTemplate = function () {
        return this.defaultItemTemplate;
    };
    ListView.prototype.setDefaultItemTemplate = function (value) {
        this.defaultItemTemplate = value;
    };
    ListView.prototype.getSectionCount = function () {
        return this.sections ? this.sections.length : 0;
    };
    ListView.prototype._createSectionItemAt = function (section, index) {
        var item = section.items[index];
        var template = this.templates[this.defaultItemTemplate];

        // Create list item for custom template
        var listItem = Ti.UI.createListItem();
        addEventListeners(template.events, listItem);

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
                            cview.text = item.properties.title;
                        } else if (ctemplate.type == 'Ti.UI.ImageView' && item.properties.image) {
                            cview = ctemplate.createView(ctemplate.properties);
                            cview.image = item.properties.image;
                        }
                    }
                    if (cview) {
                        addEventListeners(ctemplate.events, cview);
                        listItem.add(cview);
                    }
                } catch (E) {
                    // dump template format error
                    Ti.API.warn(E);
                }
            });
        }

        return listItem;
    };

    var createListView = function (options) {
        options = options || {};
        options.templates = options.templates || {};
        options.templates[Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT] = {
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
                }]
        };
        for (var binding in options.templates) {
            processChildTemplates(options.templates[binding]);
        }
        var listview = new ListView();
        listview.defaultItemTemplate = Ti.UI.LIST_ITEM_TEMPLATE_DEFAULT;
        listview.applyProperties(options);

        if (!options.templates[listview.defaultItemTemplate]) {
            Ti.API.error('Ti.UI.ListView: template \''+listview.defaultItemTemplate+'\' not found');
        }

        return listview;
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
            if (proxyType !== void 0) {
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

    //add event listeners
    function addEventListeners(events, proxy) {
        if (events !== void 0) {
            for (var eventName in events) {
                proxy.addEventListener(eventName, events[eventName]);
            }
        }
    }

    var exports = {};

    exports.ListView = ListView;
    exports.ListItem = ListItem;
    exports.ListSection = ListSection;
    exports.createListView = createListView;

    return exports;
};
