var Alloy = require("alloy"), _ = require("alloy/underscore")._, model, collection;

exports.definition = {
    config: {
        adapter: {
            type: "rss",
            idAttribute: "guid"
        }
    }
};

model = Alloy.M("feed", exports.definition, []);

collection = Alloy.C("feed", exports.definition, model);

exports.Model = model;

exports.Collection = collection;