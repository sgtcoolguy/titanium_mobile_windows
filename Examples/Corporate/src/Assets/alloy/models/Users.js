var Alloy = require("alloy"), _ = require("alloy/underscore")._, model, collection;

exports.definition = {
    config: {
        columns: {
            guid: "text",
            picture: "text",
            name: "text",
            company: "text",
            email: "text",
            phone: "text",
            address: "text",
            about: "text",
            favorite: "int"
        },
        adapter: {
            type: "sql",
            collection_name: "users"
        }
    },
    extendModel: function(Model) {
        _.extend(Model.prototype, {
            save: function(model) {
                Ti.API.info(model);
                return model;
            }
        });
        return Model;
    },
    extendCollection: function(Collection) {
        _.extend(Collection.prototype, {});
        return Collection;
    }
};

model = Alloy.M("users", exports.definition, []);

collection = Alloy.C("users", exports.definition, model);

exports.Model = model;

exports.Collection = collection;