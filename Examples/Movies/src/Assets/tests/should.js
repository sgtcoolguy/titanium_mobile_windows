!function(e) {
    if ("object" == typeof exports && "undefined" != typeof module) module.exports = e(); else if ("function" == typeof define && define.amd) define([], e); else {
        var f;
        "undefined" != typeof window ? f = window : "undefined" != typeof global ? f = global : "undefined" != typeof self && (f = self), 
        f.Should = e();
    }
}(function() {
    return function e(t, n, r) {
        function s(o, u) {
            if (!n[o]) {
                if (!t[o]) {
                    var a = "function" == typeof require && require;
                    if (!u && a) return a(o, !0);
                    if (i) return i(o, !0);
                    throw new Error("Cannot find module '" + o + "'");
                }
                var f = n[o] = {
                    exports: {}
                };
                t[o][0].call(f.exports, function(e) {
                    var n = t[o][1][e];
                    return s(n ? n : e);
                }, f, f.exports, e, t, n, r);
            }
            return n[o].exports;
        }
        var i = "function" == typeof require && require;
        for (var o = 0; o < r.length; o++) s(r[o]);
        return s;
    }({
        1: [ function(_dereq_, module) {
            function _deepEqual(actual, expected) {
                if (actual === expected) return true;
                if (util.isBuffer(actual) && util.isBuffer(expected)) {
                    if (actual.length != expected.length) return false;
                    for (var i = 0; i < actual.length; i++) if (actual[i] !== expected[i]) return false;
                    return true;
                }
                return util.isDate(actual) && util.isDate(expected) ? actual.getTime() === expected.getTime() : util.isRegExp(actual) && util.isRegExp(expected) ? actual.source === expected.source && actual.global === expected.global && actual.multiline === expected.multiline && actual.lastIndex === expected.lastIndex && actual.ignoreCase === expected.ignoreCase : util.isObject(actual) || util.isObject(expected) ? objEquiv(actual, expected) : actual == expected;
            }
            function objEquiv(a, b) {
                if (util.isNullOrUndefined(a) || util.isNullOrUndefined(b)) return false;
                if (a.prototype !== b.prototype) return false;
                if (util.isArguments(a)) {
                    if (!util.isArguments(b)) return false;
                    a = pSlice.call(a);
                    b = pSlice.call(b);
                    return _deepEqual(a, b);
                }
                try {
                    var key, i, ka = Object.keys(a), kb = Object.keys(b);
                } catch (e) {
                    return false;
                }
                if (ka.length != kb.length) return false;
                ka.sort();
                kb.sort();
                for (i = ka.length - 1; i >= 0; i--) if (ka[i] != kb[i]) return false;
                for (i = ka.length - 1; i >= 0; i--) {
                    key = ka[i];
                    if (!_deepEqual(a[key], b[key])) return false;
                }
                return true;
            }
            var util = _dereq_("./util");
            module.exports = _deepEqual;
            var pSlice = Array.prototype.slice;
        }, {
            "./util": 15
        } ],
        2: [ function(_dereq_, module) {
            var util = _dereq_("../util"), assert = _dereq_("assert"), AssertionError = assert.AssertionError;
            module.exports = function(should) {
                var i = should.format;
                util.merge(should, assert);
                should.exist = should.exists = function(obj, msg) {
                    if (null == obj) throw new AssertionError({
                        message: msg || "expected " + i(obj) + " to exist",
                        stackStartFunction: should.exist
                    });
                };
                should.not = {};
                should.not.exist = should.not.exists = function(obj, msg) {
                    if (null != obj) throw new AssertionError({
                        message: msg || "expected " + i(obj) + " to not exist",
                        stackStartFunction: should.not.exist
                    });
                };
            };
        }, {
            "../util": 15,
            assert: 16
        } ],
        3: [ function(_dereq_, module) {
            module.exports = function(should, Assertion) {
                Assertion.add("true", function() {
                    this.is.exactly(true);
                }, true);
                Assertion.alias("true", "True");
                Assertion.add("false", function() {
                    this.is.exactly(false);
                }, true);
                Assertion.alias("false", "False");
                Assertion.add("ok", function() {
                    this.params = {
                        operator: "to be truthy"
                    };
                    this.assert(this.obj);
                }, true);
            };
        }, {} ],
        4: [ function(_dereq_, module) {
            module.exports = function(should, Assertion) {
                function addLink(name) {
                    Object.defineProperty(Assertion.prototype, name, {
                        get: function() {
                            return this;
                        },
                        enumerable: true
                    });
                }
                [ "an", "of", "a", "and", "be", "have", "with", "is", "which", "the" ].forEach(addLink);
            };
        }, {} ],
        5: [ function(_dereq_, module) {
            var util = _dereq_("../util"), eql = _dereq_("../eql");
            module.exports = function(should, Assertion) {
                var i = should.format;
                Assertion.add("containEql", function(other) {
                    this.params = {
                        operator: "to contain " + i(other)
                    };
                    var obj = this.obj;
                    util.isArray(obj) ? this.assert(obj.some(function(item) {
                        return eql(item, other);
                    })) : util.isString(obj) ? this.assert(obj.indexOf(String(other)) >= 0) : util.isObject(obj) ? util.forOwn(other, function(value, key) {
                        obj.should.have.property(key, value);
                    }) : this.assert(false);
                });
                Assertion.add("containDeepOrdered", function(other) {
                    this.params = {
                        operator: "to contain " + i(other)
                    };
                    var obj = this.obj;
                    if (util.isArray(obj)) if (util.isArray(other)) {
                        var otherIdx = 0;
                        obj.forEach(function(item) {
                            try {
                                should(item).not.be.Null.and.containDeep(other[otherIdx]);
                                otherIdx++;
                            } catch (e) {
                                if (e instanceof should.AssertionError) return;
                                throw e;
                            }
                        }, this);
                        this.assert(otherIdx == other.length);
                    } else this.assert(false); else util.isString(obj) ? this.assert(obj.indexOf(String(other)) >= 0) : util.isObject(obj) ? util.isObject(other) ? util.forOwn(other, function(value, key) {
                        should(obj[key]).not.be.Null.and.containDeep(value);
                    }) : this.assert(false) : this.eql(other);
                });
                Assertion.add("containDeep", function(other) {
                    this.params = {
                        operator: "to contain " + i(other)
                    };
                    var obj = this.obj;
                    if (util.isArray(obj)) if (util.isArray(other)) {
                        var usedKeys = {};
                        other.forEach(function(otherItem) {
                            this.assert(obj.some(function(item, index) {
                                if (index in usedKeys) return false;
                                try {
                                    should(item).not.be.Null.and.containDeep(otherItem);
                                    usedKeys[index] = true;
                                    return true;
                                } catch (e) {
                                    if (e instanceof should.AssertionError) return false;
                                    throw e;
                                }
                            }));
                        }, this);
                    } else this.assert(false); else util.isString(obj) ? this.assert(obj.indexOf(String(other)) >= 0) : util.isObject(obj) ? util.isObject(other) ? util.forOwn(other, function(value, key) {
                        should(obj[key]).not.be.Null.and.containDeep(value);
                    }) : this.assert(false) : this.eql(other);
                });
            };
        }, {
            "../eql": 1,
            "../util": 15
        } ],
        6: [ function(_dereq_, module) {
            var eql = _dereq_("../eql");
            module.exports = function(should, Assertion) {
                Assertion.add("eql", function(val, description) {
                    this.params = {
                        operator: "to equal",
                        expected: val,
                        showDiff: true,
                        message: description
                    };
                    this.assert(eql(val, this.obj));
                });
                Assertion.add("equal", function(val, description) {
                    this.params = {
                        operator: "to be",
                        expected: val,
                        showDiff: true,
                        message: description
                    };
                    this.assert(val === this.obj);
                });
                Assertion.alias("equal", "exactly");
            };
        }, {
            "../eql": 1
        } ],
        7: [ function(_dereq_, module) {
            var util = _dereq_("../util");
            module.exports = function(should, Assertion) {
                var i = should.format;
                Assertion.add("throw", function(message, properties) {
                    var fn = this.obj, err = {}, errorInfo = "", thrown = false;
                    var errorMatched = true;
                    try {
                        fn();
                    } catch (e) {
                        thrown = true;
                        err = e;
                    }
                    if (thrown) if (message) {
                        if ("string" == typeof message) errorMatched = message == err.message; else if (message instanceof RegExp) errorMatched = message.test(err.message); else if ("function" == typeof message) errorMatched = err instanceof message; else if (util.isObject(message)) try {
                            err.should.match(message);
                        } catch (e) {
                            if (!(e instanceof should.AssertionError)) throw e;
                            errorInfo = ": " + e.message;
                            errorMatched = false;
                        }
                        if (errorMatched) {
                            if ("function" == typeof message && properties) try {
                                err.should.match(properties);
                            } catch (e) {
                                if (!(e instanceof should.AssertionError)) throw e;
                                errorInfo = ": " + e.message;
                                errorMatched = false;
                            }
                        } else "string" == typeof message || message instanceof RegExp ? errorInfo = " with a message matching " + i(message) + ", but got '" + err.message + "'" : "function" == typeof message && (errorInfo = " of type " + util.functionName(message) + ", but got " + util.functionName(err.constructor));
                    } else errorInfo = " (got " + i(err) + ")";
                    this.params = {
                        operator: "to throw exception" + errorInfo
                    };
                    this.assert(thrown);
                    this.assert(errorMatched);
                });
                Assertion.alias("throw", "throwError");
            };
        }, {
            "../util": 15
        } ],
        8: [ function(_dereq_, module) {
            var util = _dereq_("../util"), eql = _dereq_("../eql");
            module.exports = function(should, Assertion) {
                var i = should.format;
                Assertion.add("match", function(other, description) {
                    this.params = {
                        operator: "to match " + i(other),
                        message: description
                    };
                    if (!eql(this.obj, other)) if (util.isRegExp(other)) {
                        if (util.isString(this.obj)) this.assert(other.exec(this.obj)); else if (util.isArray(this.obj)) this.obj.forEach(function(item) {
                            this.assert(other.exec(item));
                        }, this); else if (util.isObject(this.obj)) {
                            var notMatchedProps = [], matchedProps = [];
                            util.forOwn(this.obj, function(value, name) {
                                other.exec(value) ? matchedProps.push(util.formatProp(name)) : notMatchedProps.push(util.formatProp(name) + " (" + i(value) + ")");
                            }, this);
                            notMatchedProps.length && (this.params.operator += "\n	not matched properties: " + notMatchedProps.join(", "));
                            matchedProps.length && (this.params.operator += "\n	matched properties: " + matchedProps.join(", "));
                            this.assert(0 == notMatchedProps.length);
                        }
                    } else if (util.isFunction(other)) {
                        var res;
                        try {
                            res = other(this.obj);
                        } catch (e) {
                            e instanceof should.AssertionError && (this.params.operator += "\n	" + e.message);
                            throw e;
                        }
                        res instanceof Assertion && (this.params.operator += "\n	" + res.getMessage());
                        util.isBoolean(res) && this.assert(res);
                    } else if (util.isObject(other)) {
                        notMatchedProps = [];
                        matchedProps = [];
                        util.forOwn(other, function(value, key) {
                            try {
                                should(this.obj[key]).match(value);
                                matchedProps.push(util.formatProp(key));
                            } catch (e) {
                                if (!(e instanceof should.AssertionError)) throw e;
                                notMatchedProps.push(util.formatProp(key) + " (" + i(this.obj[key]) + ")");
                            }
                        }, this);
                        notMatchedProps.length && (this.params.operator += "\n	not matched properties: " + notMatchedProps.join(", "));
                        matchedProps.length && (this.params.operator += "\n	matched properties: " + matchedProps.join(", "));
                        this.assert(0 == notMatchedProps.length);
                    } else this.assert(false);
                });
                Assertion.add("matchEach", function(other, description) {
                    this.params = {
                        operator: "to match each " + i(other),
                        message: description
                    };
                    var f = other;
                    util.isRegExp(other) ? f = function(it) {
                        return !!other.exec(it);
                    } : util.isFunction(other) || (f = function(it) {
                        return eql(it, other);
                    });
                    util.forOwn(this.obj, function(value, key) {
                        var res = f(value, key);
                        util.isBoolean(res) && this.assert(res);
                    }, this);
                });
            };
        }, {
            "../eql": 1,
            "../util": 15
        } ],
        9: [ function(_dereq_, module) {
            module.exports = function(should, Assertion) {
                Assertion.add("NaN", function() {
                    this.params = {
                        operator: "to be NaN"
                    };
                    this.assert(this.obj !== this.obj);
                }, true);
                Assertion.add("Infinity", function() {
                    this.params = {
                        operator: "to be Infinity"
                    };
                    this.is.a.Number.and.not.a.NaN.and.assert(!isFinite(this.obj));
                }, true);
                Assertion.add("within", function(start, finish, description) {
                    this.params = {
                        operator: "to be within " + start + ".." + finish,
                        message: description
                    };
                    this.assert(this.obj >= start && this.obj <= finish);
                });
                Assertion.add("approximately", function(value, delta, description) {
                    this.params = {
                        operator: "to be approximately " + value + " ±" + delta,
                        message: description
                    };
                    this.assert(Math.abs(this.obj - value) <= delta);
                });
                Assertion.add("above", function(n, description) {
                    this.params = {
                        operator: "to be above " + n,
                        message: description
                    };
                    this.assert(this.obj > n);
                });
                Assertion.add("below", function(n, description) {
                    this.params = {
                        operator: "to be below " + n,
                        message: description
                    };
                    this.assert(this.obj < n);
                });
                Assertion.alias("above", "greaterThan");
                Assertion.alias("below", "lessThan");
            };
        }, {} ],
        10: [ function(_dereq_, module) {
            var util = _dereq_("../util"), eql = _dereq_("../eql");
            var aSlice = Array.prototype.slice;
            module.exports = function(should, Assertion) {
                var i = should.format;
                Assertion.add("enumerable", function(name, val) {
                    name = String(name);
                    this.params = {
                        operator: "to have enumerable property " + util.formatProp(name)
                    };
                    this.assert(this.obj.propertyIsEnumerable(name));
                    if (arguments.length > 1) {
                        this.params.operator += " equal to " + i(val);
                        this.assert(eql(val, this.obj[name]));
                    }
                });
                Assertion.add("property", function(name, val) {
                    name = String(name);
                    if (arguments.length > 1) {
                        var p = {};
                        p[name] = val;
                        this.have.properties(p);
                    } else this.have.properties(name);
                    this.obj = this.obj[name];
                });
                Assertion.add("properties", function(names) {
                    var values = {};
                    if (arguments.length > 1) names = aSlice.call(arguments); else if (!util.isArray(names)) if (util.isString(names)) names = [ names ]; else {
                        values = names;
                        names = Object.keys(names);
                    }
                    var obj = Object(this.obj), missingProperties = [];
                    names.forEach(function(name) {
                        name in obj || missingProperties.push(util.formatProp(name));
                    });
                    var props = missingProperties;
                    0 === props.length ? props = names.map(util.formatProp) : this.anyOne && (props = names.filter(function(name) {
                        return missingProperties.indexOf(util.formatProp(name)) < 0;
                    }).map(util.formatProp));
                    var operator = (1 === props.length ? "to have property " : "to have " + (this.anyOne ? "any of " : "") + "properties ") + props.join(", ");
                    this.params = {
                        operator: operator
                    };
                    this.assert(0 === missingProperties.length || this.anyOne && missingProperties.length != names.length);
                    var valueCheckNames = Object.keys(values);
                    if (valueCheckNames.length) {
                        var wrongValues = [];
                        props = [];
                        valueCheckNames.forEach(function(name) {
                            var value = values[name];
                            eql(obj[name], value) ? props.push(util.formatProp(name) + " of " + i(value)) : wrongValues.push(util.formatProp(name) + " of " + i(value) + " (got " + i(obj[name]) + ")");
                        });
                        (0 !== wrongValues.length && !this.anyOne || this.anyOne && 0 === props.length) && (props = wrongValues);
                        operator = (1 === props.length ? "to have property " : "to have " + (this.anyOne ? "any of " : "") + "properties ") + props.join(", ");
                        this.params = {
                            operator: operator
                        };
                        this.assert(0 === wrongValues.length || this.anyOne && wrongValues.length != valueCheckNames.length);
                    }
                });
                Assertion.add("length", function(n, description) {
                    this.have.property("length", n, description);
                });
                Assertion.alias("length", "lengthOf");
                var hasOwnProperty = Object.prototype.hasOwnProperty;
                Assertion.add("ownProperty", function(name, description) {
                    name = String(name);
                    this.params = {
                        operator: "to have own property " + util.formatProp(name),
                        message: description
                    };
                    this.assert(hasOwnProperty.call(this.obj, name));
                    this.obj = this.obj[name];
                });
                Assertion.alias("ownProperty", "hasOwnProperty");
                Assertion.add("empty", function() {
                    this.params = {
                        operator: "to be empty"
                    };
                    if (util.isString(this.obj) || util.isArray(this.obj) || util.isArguments(this.obj)) this.have.property("length", 0); else {
                        var obj = Object(this.obj);
                        for (var prop in obj) this.have.not.ownProperty(prop);
                    }
                }, true);
                Assertion.add("keys", function(keys) {
                    arguments.length > 1 ? keys = aSlice.call(arguments) : 1 === arguments.length && util.isString(keys) ? keys = [ keys ] : 0 === arguments.length && (keys = []);
                    keys = keys.map(String);
                    var obj = Object(this.obj);
                    var missingKeys = [];
                    keys.forEach(function(key) {
                        hasOwnProperty.call(this.obj, key) || missingKeys.push(util.formatProp(key));
                    }, this);
                    var extraKeys = [];
                    Object.keys(obj).forEach(function(key) {
                        keys.indexOf(key) < 0 && extraKeys.push(util.formatProp(key));
                    });
                    var verb = 0 === keys.length ? "to be empty" : "to have " + (1 === keys.length ? "key " : "keys ");
                    this.params = {
                        operator: verb + keys.map(util.formatProp).join(", ")
                    };
                    missingKeys.length > 0 && (this.params.operator += "\n	missing keys: " + missingKeys.join(", "));
                    extraKeys.length > 0 && (this.params.operator += "\n	extra keys: " + extraKeys.join(", "));
                    this.assert(0 === missingKeys.length && 0 === extraKeys.length);
                });
                Assertion.alias("keys", "key");
                Assertion.add("propertyByPath", function(properties) {
                    arguments.length > 1 ? properties = aSlice.call(arguments) : 1 === arguments.length && util.isString(properties) ? properties = [ properties ] : 0 === arguments.length && (properties = []);
                    var allProps = properties.map(util.formatProp);
                    properties = properties.map(String);
                    var obj = should(Object(this.obj));
                    var foundProperties = [];
                    var currentProperty;
                    while (currentProperty = properties.shift()) {
                        this.params = {
                            operator: "to have property by path " + allProps.join(", ") + " - failed on " + util.formatProp(currentProperty)
                        };
                        obj = obj.have.property(currentProperty);
                        foundProperties.push(currentProperty);
                    }
                    this.params = {
                        operator: "to have property by path " + allProps.join(", ")
                    };
                    this.obj = obj.obj;
                });
            };
        }, {
            "../eql": 1,
            "../util": 15
        } ],
        11: [ function(_dereq_, module) {
            module.exports = function(should, Assertion) {
                Assertion.add("startWith", function(str, description) {
                    this.params = {
                        operator: "to start with " + should.format(str),
                        message: description
                    };
                    this.assert(0 === this.obj.indexOf(str));
                });
                Assertion.add("endWith", function(str, description) {
                    this.params = {
                        operator: "to end with " + should.format(str),
                        message: description
                    };
                    this.assert(this.obj.indexOf(str, this.obj.length - str.length) >= 0);
                });
            };
        }, {} ],
        12: [ function(_dereq_, module) {
            var util = _dereq_("../util");
            module.exports = function(should, Assertion) {
                Assertion.add("Number", function() {
                    this.params = {
                        operator: "to be a number"
                    };
                    this.assert(util.isNumber(this.obj));
                }, true);
                Assertion.add("arguments", function() {
                    this.params = {
                        operator: "to be arguments"
                    };
                    this.assert(util.isArguments(this.obj));
                }, true);
                Assertion.add("type", function(type, description) {
                    this.params = {
                        operator: "to have type " + type,
                        message: description
                    };
                    (typeof this.obj).should.be.exactly(type, description);
                });
                Assertion.add("instanceof", function(constructor, description) {
                    this.params = {
                        operator: "to be an instance of " + util.functionName(constructor),
                        message: description
                    };
                    this.assert(Object(this.obj) instanceof constructor);
                });
                Assertion.add("Function", function() {
                    this.params = {
                        operator: "to be a function"
                    };
                    this.assert(util.isFunction(this.obj));
                }, true);
                Assertion.add("Object", function() {
                    this.params = {
                        operator: "to be an object"
                    };
                    this.assert(util.isObject(this.obj));
                }, true);
                Assertion.add("String", function() {
                    this.params = {
                        operator: "to be a string"
                    };
                    this.assert(util.isString(this.obj));
                }, true);
                Assertion.add("Array", function() {
                    this.params = {
                        operator: "to be an array"
                    };
                    this.assert(util.isArray(this.obj));
                }, true);
                Assertion.add("Boolean", function() {
                    this.params = {
                        operator: "to be a boolean"
                    };
                    this.assert(util.isBoolean(this.obj));
                }, true);
                Assertion.add("Error", function() {
                    this.params = {
                        operator: "to be an error"
                    };
                    this.assert(util.isError(this.obj));
                }, true);
                Assertion.add("null", function() {
                    this.params = {
                        operator: "to be null"
                    };
                    this.assert(null === this.obj);
                }, true);
                Assertion.alias("null", "Null");
                Assertion.alias("instanceof", "instanceOf");
            };
        }, {
            "../util": 15
        } ],
        13: [ function(_dereq_, module, exports) {
            function inspect(obj, opts) {
                var ctx = {
                    seen: [],
                    stylize: stylizeNoColor
                };
                arguments.length >= 3 && (ctx.depth = arguments[2]);
                arguments.length >= 4 && (ctx.colors = arguments[3]);
                isBoolean(opts) ? ctx.showHidden = opts : opts && exports._extend(ctx, opts);
                isUndefined(ctx.showHidden) && (ctx.showHidden = false);
                isUndefined(ctx.depth) && (ctx.depth = 2);
                isUndefined(ctx.colors) && (ctx.colors = false);
                isUndefined(ctx.customInspect) && (ctx.customInspect = true);
                ctx.colors && (ctx.stylize = stylizeWithColor);
                return formatValue(ctx, obj, ctx.depth);
            }
            function stylizeWithColor(str, styleType) {
                var style = inspect.styles[styleType];
                return style ? "[" + inspect.colors[style][0] + "m" + str + "[" + inspect.colors[style][1] + "m" : str;
            }
            function stylizeNoColor(str) {
                return str;
            }
            function arrayToHash(array) {
                var hash = {};
                array.forEach(function(val) {
                    hash[val] = true;
                });
                return hash;
            }
            function formatValue(ctx, value, recurseTimes) {
                if (ctx.customInspect && value && isFunction(value.inspect) && value.inspect !== exports.inspect && !(value.constructor && value.constructor.prototype === value)) {
                    var ret = value.inspect(recurseTimes, ctx);
                    isString(ret) || (ret = formatValue(ctx, ret, recurseTimes));
                    return ret;
                }
                var primitive = formatPrimitive(ctx, value);
                if (primitive) return primitive;
                var keys = Object.keys(value);
                var visibleKeys = arrayToHash(keys);
                ctx.showHidden && (keys = Object.getOwnPropertyNames(value));
                var formatted;
                var raw = value;
                try {
                    isDate(value) || (raw = value.valueOf());
                } catch (e) {}
                isString(raw) && (keys = keys.filter(function(key) {
                    return !(key >= 0 && key < raw.length);
                }));
                if (isError(value)) return formatError(value);
                if (0 === keys.length) {
                    if (isFunction(value)) {
                        var name = value.name ? ": " + value.name : "";
                        return ctx.stylize("[Function" + name + "]", "special");
                    }
                    if (isRegExp(value)) return ctx.stylize(RegExp.prototype.toString.call(value), "regexp");
                    if (isDate(value)) return ctx.stylize(Date.prototype.toString.call(value), "date");
                    if (isString(raw)) {
                        formatted = formatPrimitiveNoColor(ctx, raw);
                        return ctx.stylize("[String: " + formatted + "]", "string");
                    }
                    if (isNumber(raw)) {
                        formatted = formatPrimitiveNoColor(ctx, raw);
                        return ctx.stylize("[Number: " + formatted + "]", "number");
                    }
                    if (isBoolean(raw)) {
                        formatted = formatPrimitiveNoColor(ctx, raw);
                        return ctx.stylize("[Boolean: " + formatted + "]", "boolean");
                    }
                }
                var base = "", array = false, braces = [ "{", "}" ];
                if (isArray(value)) {
                    array = true;
                    braces = [ "[", "]" ];
                }
                if (isFunction(value)) {
                    var n = value.name ? ": " + value.name : "";
                    base = " [Function" + n + "]";
                }
                isRegExp(value) && (base = " " + RegExp.prototype.toString.call(value));
                isDate(value) && (base = " " + Date.prototype.toUTCString.call(value));
                isError(value) && (base = " " + formatError(value));
                if (isString(raw)) {
                    formatted = formatPrimitiveNoColor(ctx, raw);
                    base = " [String: " + formatted + "]";
                }
                if (isNumber(raw)) {
                    formatted = formatPrimitiveNoColor(ctx, raw);
                    base = " [Number: " + formatted + "]";
                }
                if (isBoolean(raw)) {
                    formatted = formatPrimitiveNoColor(ctx, raw);
                    base = " [Boolean: " + formatted + "]";
                }
                if (0 === keys.length && (!array || 0 === value.length)) return braces[0] + base + braces[1];
                if (0 > recurseTimes) return isRegExp(value) ? ctx.stylize(RegExp.prototype.toString.call(value), "regexp") : ctx.stylize("[Object]", "special");
                ctx.seen.push(value);
                var output;
                output = array ? formatArray(ctx, value, recurseTimes, visibleKeys, keys) : keys.map(function(key) {
                    return formatProperty(ctx, value, recurseTimes, visibleKeys, key, array);
                });
                ctx.seen.pop();
                return reduceToSingleString(output, base, braces);
            }
            function formatPrimitive(ctx, value) {
                if (isUndefined(value)) return ctx.stylize("undefined", "undefined");
                if (isString(value)) {
                    var simple = "'" + JSON.stringify(value).replace(/^"|"$/g, "").replace(/'/g, "\\'").replace(/\\"/g, '"') + "'";
                    return ctx.stylize(simple, "string");
                }
                if (isNumber(value)) {
                    if (0 === value && 0 > 1 / value) return ctx.stylize("-0", "number");
                    return ctx.stylize("" + value, "number");
                }
                if (isBoolean(value)) return ctx.stylize("" + value, "boolean");
                if (isNull(value)) return ctx.stylize("null", "null");
            }
            function formatPrimitiveNoColor(ctx, value) {
                var stylize = ctx.stylize;
                ctx.stylize = stylizeNoColor;
                var str = formatPrimitive(ctx, value);
                ctx.stylize = stylize;
                return str;
            }
            function formatError(value) {
                return "[" + Error.prototype.toString.call(value) + "]";
            }
            function formatArray(ctx, value, recurseTimes, visibleKeys, keys) {
                var output = [];
                for (var i = 0, l = value.length; l > i; ++i) output.push(hasOwnProperty(value, String(i)) ? formatProperty(ctx, value, recurseTimes, visibleKeys, String(i), true) : "");
                keys.forEach(function(key) {
                    key.match(/^\d+$/) || output.push(formatProperty(ctx, value, recurseTimes, visibleKeys, key, true));
                });
                return output;
            }
            function formatProperty(ctx, value, recurseTimes, visibleKeys, key, array) {
                var name, str, desc;
                desc = Object.getOwnPropertyDescriptor(value, key) || {
                    value: value[key]
                };
                desc.get ? str = desc.set ? ctx.stylize("[Getter/Setter]", "special") : ctx.stylize("[Getter]", "special") : desc.set && (str = ctx.stylize("[Setter]", "special"));
                hasOwnProperty(visibleKeys, key) || (name = "[" + key + "]");
                if (!str) if (ctx.seen.indexOf(desc.value) < 0) {
                    str = isNull(recurseTimes) ? formatValue(ctx, desc.value, null) : formatValue(ctx, desc.value, recurseTimes - 1);
                    str.indexOf("\n") > -1 && (str = array ? str.split("\n").map(function(line) {
                        return " " + line;
                    }).join("\n").substr(2) : "\n" + str.split("\n").map(function(line) {
                        return " " + line;
                    }).join("\n"));
                } else str = ctx.stylize("[Circular]", "special");
                if (isUndefined(name)) {
                    if (array && key.match(/^\d+$/)) return str;
                    name = JSON.stringify("" + key);
                    if (name.match(/^"([a-zA-Z_][a-zA-Z_0-9]*)"$/)) {
                        name = name.substr(1, name.length - 2);
                        name = ctx.stylize(name, "name");
                    } else {
                        name = name.replace(/'/g, "\\'").replace(/\\"/g, '"').replace(/(^"|"$)/g, "'").replace(/\\\\/g, "\\");
                        name = ctx.stylize(name, "string");
                    }
                }
                return name + ": " + str;
            }
            function reduceToSingleString(output, base, braces) {
                var length = output.reduce(function(prev, cur) {
                    return prev + cur.replace(/\u001b\[\d\d?m/g, "").length + 1;
                }, 0);
                if (length > 60) return braces[0] + ("" === base ? "" : base + "\n ") + " " + output.join(",\n ") + " " + braces[1];
                return braces[0] + base + " " + output.join(", ") + " " + braces[1];
            }
            function hasOwnProperty(obj, prop) {
                return Object.prototype.hasOwnProperty.call(obj, prop);
            }
            var util = _dereq_("./util");
            var isBoolean = util.isBoolean;
            var isObject = util.isObject;
            var isUndefined = util.isUndefined;
            var isFunction = util.isFunction;
            var isString = util.isString;
            var isNumber = util.isNumber;
            var isNull = util.isNull;
            var isRegExp = util.isRegExp;
            var isDate = util.isDate;
            var isError = util.isError;
            var isArray = util.isArray;
            exports.inspect = inspect;
            inspect.colors = {
                bold: [ 1, 22 ],
                italic: [ 3, 23 ],
                underline: [ 4, 24 ],
                inverse: [ 7, 27 ],
                white: [ 37, 39 ],
                grey: [ 90, 39 ],
                black: [ 30, 39 ],
                blue: [ 34, 39 ],
                cyan: [ 36, 39 ],
                green: [ 32, 39 ],
                magenta: [ 35, 39 ],
                red: [ 31, 39 ],
                yellow: [ 33, 39 ]
            };
            inspect.styles = {
                special: "cyan",
                number: "yellow",
                "boolean": "yellow",
                undefined: "grey",
                "null": "bold",
                string: "green",
                date: "magenta",
                regexp: "red"
            };
            exports._extend = function(origin, add) {
                if (!add || !isObject(add)) return origin;
                var keys = Object.keys(add);
                var i = keys.length;
                while (i--) origin[keys[i]] = add[keys[i]];
                return origin;
            };
        }, {
            "./util": 15
        } ],
        14: [ function(_dereq_, module, exports) {
            var util = _dereq_("./util"), AssertionError = util.AssertionError, inspect = util.inspect;
            var should = function(obj) {
                return new Assertion(util.isWrapperType(obj) ? obj.valueOf() : obj);
            };
            var Assertion = should.Assertion = function(obj) {
                this.obj = obj;
            };
            Assertion.add = function(name, f, isGetter) {
                var prop = {
                    enumerable: true
                };
                prop[isGetter ? "get" : "value"] = function() {
                    var context = new Assertion(this.obj);
                    context.copy = context.copyIfMissing;
                    context.anyOne = this.anyOne;
                    try {
                        f.apply(context, arguments);
                    } catch (e) {
                        this.copy(context);
                        if (e instanceof should.AssertionError) {
                            if (this.negate) {
                                this.obj = context.obj;
                                this.negate = false;
                                return this;
                            }
                            this.assert(false);
                        }
                        throw e;
                    }
                    this.copy(context);
                    this.negate && this.assert(false);
                    this.obj = context.obj;
                    this.negate = false;
                    return this;
                };
                Object.defineProperty(Assertion.prototype, name, prop);
            };
            Assertion.alias = function(from, to) {
                var desc = Object.getOwnPropertyDescriptor(Assertion.prototype, from);
                if (!desc) throw new Error("Alias " + from + " -> " + to + " could not be created as " + from + " not defined");
                Object.defineProperty(Assertion.prototype, to, desc);
            };
            should.AssertionError = AssertionError;
            should.format = function(value) {
                if (util.isDate(value) && "function" != typeof value.inspect) return value.toISOString();
                return inspect(value, {
                    depth: null
                });
            };
            should.use = function(f) {
                f(this, Assertion);
                return this;
            };
            exports = module.exports = should;
            Object.defineProperty(Object.prototype, "should", {
                set: function() {},
                get: function() {
                    return should(this);
                },
                configurable: true
            });
            Assertion.prototype = {
                constructor: Assertion,
                assert: function(expr) {
                    if (expr) return this;
                    var params = this.params;
                    var msg = params.message, generatedMessage = false;
                    if (!msg) {
                        msg = this.getMessage();
                        generatedMessage = true;
                    }
                    var err = new AssertionError({
                        message: msg,
                        actual: this.obj,
                        expected: params.expected,
                        stackStartFunction: this.assert
                    });
                    err.showDiff = params.showDiff;
                    err.operator = params.operator;
                    err.generatedMessage = generatedMessage;
                    throw err;
                },
                getMessage: function() {
                    return "expected " + ("obj" in this.params ? this.params.obj : should.format(this.obj)) + (this.negate ? " not " : " ") + this.params.operator + ("expected" in this.params ? " " + should.format(this.params.expected) : "");
                },
                copy: function(other) {
                    this.params = other.params;
                },
                copyIfMissing: function(other) {
                    this.params || (this.params = other.params);
                },
                get not() {
                    this.negate = !this.negate;
                    return this;
                },
                get any() {
                    this.anyOne = true;
                    return this;
                }
            };
            should.use(_dereq_("./ext/assert")).use(_dereq_("./ext/chain")).use(_dereq_("./ext/bool")).use(_dereq_("./ext/number")).use(_dereq_("./ext/eql")).use(_dereq_("./ext/type")).use(_dereq_("./ext/string")).use(_dereq_("./ext/property")).use(_dereq_("./ext/error")).use(_dereq_("./ext/match")).use(_dereq_("./ext/contain"));
        }, {
            "./ext/assert": 2,
            "./ext/bool": 3,
            "./ext/chain": 4,
            "./ext/contain": 5,
            "./ext/eql": 6,
            "./ext/error": 7,
            "./ext/match": 8,
            "./ext/number": 9,
            "./ext/property": 10,
            "./ext/string": 11,
            "./ext/type": 12,
            "./util": 15
        } ],
        15: [ function(_dereq_, module, exports) {
            function isArray(arr) {
                return isObject(arr) && (arr.__ArrayLike || Array.isArray(arr));
            }
            function isNumber(arg) {
                return "number" == typeof arg || arg instanceof Number;
            }
            function isString(arg) {
                return "string" == typeof arg || arg instanceof String;
            }
            function isBoolean(arg) {
                return "boolean" == typeof arg || arg instanceof Boolean;
            }
            function isBuffer(arg) {
                return "undefined" != typeof Buffer && arg instanceof Buffer;
            }
            function isDate(d) {
                return isObject(d) && "[object Date]" === objectToString(d);
            }
            function objectToString(o) {
                return Object.prototype.toString.call(o);
            }
            function isObject(arg) {
                return "object" == typeof arg && null !== arg;
            }
            function isRegExp(re) {
                return isObject(re) && "[object RegExp]" === objectToString(re);
            }
            function isNullOrUndefined(arg) {
                return null == arg;
            }
            function isNull(arg) {
                return null === arg;
            }
            function isArguments(object) {
                return "[object Arguments]" === objectToString(object);
            }
            function isError(e) {
                return isObject(e) && "[object Error]" === objectToString(e) || e instanceof Error;
            }
            function isUndefined(arg) {
                return void 0 === arg;
            }
            exports.isWrapperType = function(obj) {
                return isNumber(obj) || isString(obj) || isBoolean(obj);
            };
            exports.merge = function(a, b) {
                if (a && b) for (var key in b) a[key] = b[key];
                return a;
            };
            exports.isArray = isArray;
            exports.isNumber = isNumber;
            exports.isBoolean = isBoolean;
            exports.isString = isString;
            exports.isBuffer = isBuffer;
            exports.isDate = isDate;
            exports.isObject = isObject;
            exports.isRegExp = isRegExp;
            exports.isNullOrUndefined = isNullOrUndefined;
            exports.isNull = isNull;
            exports.isArguments = isArguments;
            exports.isFunction = function(arg) {
                return "function" == typeof arg || arg instanceof Function;
            };
            exports.isError = isError;
            exports.isUndefined = isUndefined;
            exports.inspect = _dereq_("./inspect").inspect;
            exports.AssertionError = _dereq_("assert").AssertionError;
            var hasOwnProperty = Object.prototype.hasOwnProperty;
            exports.forOwn = function(obj, f, context) {
                for (var prop in obj) hasOwnProperty.call(obj, prop) && f.call(context, obj[prop], prop);
            };
            var functionNameRE = /^\s*function\s*(\S*)\s*\(/;
            exports.functionName = function(f) {
                if (f.name) return f.name;
                var name = f.toString().match(functionNameRE)[1];
                return name;
            };
            exports.formatProp = function(name) {
                name = JSON.stringify("" + name);
                name = name.match(/^"([a-zA-Z_][a-zA-Z_0-9]*)"$/) ? name.substr(1, name.length - 2) : name.replace(/'/g, "\\'").replace(/\\"/g, '"').replace(/(^"|"$)/g, "'").replace(/\\\\/g, "\\");
                return name;
            };
        }, {
            "./inspect": 13,
            assert: 16
        } ],
        16: [ function(_dereq_, module) {
            function replacer(key, value) {
                if (util.isUndefined(value)) return "" + value;
                if (util.isNumber(value) && (isNaN(value) || !isFinite(value))) return value.toString();
                if (util.isFunction(value) || util.isRegExp(value)) return value.toString();
                return value;
            }
            function truncate(s, n) {
                return util.isString(s) ? s.length < n ? s : s.slice(0, n) : s;
            }
            function getMessage(self) {
                return truncate(JSON.stringify(self.actual, replacer), 128) + " " + self.operator + " " + truncate(JSON.stringify(self.expected, replacer), 128);
            }
            function fail(actual, expected, message, operator, stackStartFunction) {
                throw new assert.AssertionError({
                    message: message,
                    actual: actual,
                    expected: expected,
                    operator: operator,
                    stackStartFunction: stackStartFunction
                });
            }
            function ok(value, message) {
                value || fail(value, true, message, "==", assert.ok);
            }
            function _deepEqual(actual, expected) {
                if (actual === expected) return true;
                if (util.isBuffer(actual) && util.isBuffer(expected)) {
                    if (actual.length != expected.length) return false;
                    for (var i = 0; i < actual.length; i++) if (actual[i] !== expected[i]) return false;
                    return true;
                }
                return util.isDate(actual) && util.isDate(expected) ? actual.getTime() === expected.getTime() : util.isRegExp(actual) && util.isRegExp(expected) ? actual.source === expected.source && actual.global === expected.global && actual.multiline === expected.multiline && actual.lastIndex === expected.lastIndex && actual.ignoreCase === expected.ignoreCase : util.isObject(actual) || util.isObject(expected) ? objEquiv(actual, expected) : actual == expected;
            }
            function isArguments(object) {
                return "[object Arguments]" == Object.prototype.toString.call(object);
            }
            function objEquiv(a, b) {
                if (util.isNullOrUndefined(a) || util.isNullOrUndefined(b)) return false;
                if (a.prototype !== b.prototype) return false;
                if (isArguments(a)) {
                    if (!isArguments(b)) return false;
                    a = pSlice.call(a);
                    b = pSlice.call(b);
                    return _deepEqual(a, b);
                }
                try {
                    var key, i, ka = objectKeys(a), kb = objectKeys(b);
                } catch (e) {
                    return false;
                }
                if (ka.length != kb.length) return false;
                ka.sort();
                kb.sort();
                for (i = ka.length - 1; i >= 0; i--) if (ka[i] != kb[i]) return false;
                for (i = ka.length - 1; i >= 0; i--) {
                    key = ka[i];
                    if (!_deepEqual(a[key], b[key])) return false;
                }
                return true;
            }
            function expectedException(actual, expected) {
                if (!actual || !expected) return false;
                if ("[object RegExp]" == Object.prototype.toString.call(expected)) return expected.test(actual);
                if (actual instanceof expected) return true;
                if (true === expected.call({}, actual)) return true;
                return false;
            }
            function _throws(shouldThrow, block, expected, message) {
                var actual;
                if (util.isString(expected)) {
                    message = expected;
                    expected = null;
                }
                try {
                    block();
                } catch (e) {
                    actual = e;
                }
                message = (expected && expected.name ? " (" + expected.name + ")." : ".") + (message ? " " + message : ".");
                shouldThrow && !actual && fail(actual, expected, "Missing expected exception" + message);
                !shouldThrow && expectedException(actual, expected) && fail(actual, expected, "Got unwanted exception" + message);
                if (shouldThrow && actual && expected && !expectedException(actual, expected) || !shouldThrow && actual) throw actual;
            }
            var util = _dereq_("util/");
            var pSlice = Array.prototype.slice;
            var hasOwn = Object.prototype.hasOwnProperty;
            var assert = module.exports = ok;
            assert.AssertionError = function(options) {
                this.name = "AssertionError";
                this.actual = options.actual;
                this.expected = options.expected;
                this.operator = options.operator;
                if (options.message) {
                    this.message = options.message;
                    this.generatedMessage = false;
                } else {
                    this.message = getMessage(this);
                    this.generatedMessage = true;
                }
                var stackStartFunction = options.stackStartFunction || fail;
                if (Error.captureStackTrace) Error.captureStackTrace(this, stackStartFunction); else {
                    var err = new Error();
                    if (err.stack) {
                        var out = err.stack;
                        var fn_name = stackStartFunction.name;
                        var idx = out.indexOf("\n" + fn_name);
                        if (idx >= 0) {
                            var next_line = out.indexOf("\n", idx + 1);
                            out = out.substring(next_line + 1);
                        }
                        this.stack = out;
                    }
                }
            };
            util.inherits(assert.AssertionError, Error);
            assert.fail = fail;
            assert.ok = ok;
            assert.equal = function(actual, expected, message) {
                actual != expected && fail(actual, expected, message, "==", assert.equal);
            };
            assert.notEqual = function(actual, expected, message) {
                actual == expected && fail(actual, expected, message, "!=", assert.notEqual);
            };
            assert.deepEqual = function(actual, expected, message) {
                _deepEqual(actual, expected) || fail(actual, expected, message, "deepEqual", assert.deepEqual);
            };
            assert.notDeepEqual = function(actual, expected, message) {
                _deepEqual(actual, expected) && fail(actual, expected, message, "notDeepEqual", assert.notDeepEqual);
            };
            assert.strictEqual = function(actual, expected, message) {
                actual !== expected && fail(actual, expected, message, "===", assert.strictEqual);
            };
            assert.notStrictEqual = function(actual, expected, message) {
                actual === expected && fail(actual, expected, message, "!==", assert.notStrictEqual);
            };
            assert.throws = function() {
                _throws.apply(this, [ true ].concat(pSlice.call(arguments)));
            };
            assert.doesNotThrow = function() {
                _throws.apply(this, [ false ].concat(pSlice.call(arguments)));
            };
            assert.ifError = function(err) {
                if (err) throw err;
            };
            var objectKeys = Object.keys || function(obj) {
                var keys = [];
                for (var key in obj) hasOwn.call(obj, key) && keys.push(key);
                return keys;
            };
        }, {
            "util/": 18
        } ],
        17: [ function(_dereq_, module) {
            module.exports = function(arg) {
                return arg && "object" == typeof arg && "function" == typeof arg.copy && "function" == typeof arg.fill && "function" == typeof arg.readUInt8;
            };
        }, {} ],
        18: [ function(_dereq_, module, exports) {
            function inspect(obj, opts) {
                var ctx = {
                    seen: [],
                    stylize: stylizeNoColor
                };
                arguments.length >= 3 && (ctx.depth = arguments[2]);
                arguments.length >= 4 && (ctx.colors = arguments[3]);
                isBoolean(opts) ? ctx.showHidden = opts : opts && exports._extend(ctx, opts);
                isUndefined(ctx.showHidden) && (ctx.showHidden = false);
                isUndefined(ctx.depth) && (ctx.depth = 2);
                isUndefined(ctx.colors) && (ctx.colors = false);
                isUndefined(ctx.customInspect) && (ctx.customInspect = true);
                ctx.colors && (ctx.stylize = stylizeWithColor);
                return formatValue(ctx, obj, ctx.depth);
            }
            function stylizeWithColor(str, styleType) {
                var style = inspect.styles[styleType];
                return style ? "[" + inspect.colors[style][0] + "m" + str + "[" + inspect.colors[style][1] + "m" : str;
            }
            function stylizeNoColor(str) {
                return str;
            }
            function arrayToHash(array) {
                var hash = {};
                array.forEach(function(val) {
                    hash[val] = true;
                });
                return hash;
            }
            function formatValue(ctx, value, recurseTimes) {
                if (ctx.customInspect && value && isFunction(value.inspect) && value.inspect !== exports.inspect && !(value.constructor && value.constructor.prototype === value)) {
                    var ret = value.inspect(recurseTimes, ctx);
                    isString(ret) || (ret = formatValue(ctx, ret, recurseTimes));
                    return ret;
                }
                var primitive = formatPrimitive(ctx, value);
                if (primitive) return primitive;
                var keys = Object.keys(value);
                var visibleKeys = arrayToHash(keys);
                ctx.showHidden && (keys = Object.getOwnPropertyNames(value));
                if (isError(value) && (keys.indexOf("message") >= 0 || keys.indexOf("description") >= 0)) return formatError(value);
                if (0 === keys.length) {
                    if (isFunction(value)) {
                        var name = value.name ? ": " + value.name : "";
                        return ctx.stylize("[Function" + name + "]", "special");
                    }
                    if (isRegExp(value)) return ctx.stylize(RegExp.prototype.toString.call(value), "regexp");
                    if (isDate(value)) return ctx.stylize(Date.prototype.toString.call(value), "date");
                    if (isError(value)) return formatError(value);
                }
                var base = "", array = false, braces = [ "{", "}" ];
                if (isArray(value)) {
                    array = true;
                    braces = [ "[", "]" ];
                }
                if (isFunction(value)) {
                    var n = value.name ? ": " + value.name : "";
                    base = " [Function" + n + "]";
                }
                isRegExp(value) && (base = " " + RegExp.prototype.toString.call(value));
                isDate(value) && (base = " " + Date.prototype.toUTCString.call(value));
                isError(value) && (base = " " + formatError(value));
                if (0 === keys.length && (!array || 0 == value.length)) return braces[0] + base + braces[1];
                if (0 > recurseTimes) return isRegExp(value) ? ctx.stylize(RegExp.prototype.toString.call(value), "regexp") : ctx.stylize("[Object]", "special");
                ctx.seen.push(value);
                var output;
                output = array ? formatArray(ctx, value, recurseTimes, visibleKeys, keys) : keys.map(function(key) {
                    return formatProperty(ctx, value, recurseTimes, visibleKeys, key, array);
                });
                ctx.seen.pop();
                return reduceToSingleString(output, base, braces);
            }
            function formatPrimitive(ctx, value) {
                if (isUndefined(value)) return ctx.stylize("undefined", "undefined");
                if (isString(value)) {
                    var simple = "'" + JSON.stringify(value).replace(/^"|"$/g, "").replace(/'/g, "\\'").replace(/\\"/g, '"') + "'";
                    return ctx.stylize(simple, "string");
                }
                if (isNumber(value)) return ctx.stylize("" + value, "number");
                if (isBoolean(value)) return ctx.stylize("" + value, "boolean");
                if (isNull(value)) return ctx.stylize("null", "null");
            }
            function formatError(value) {
                return "[" + Error.prototype.toString.call(value) + "]";
            }
            function formatArray(ctx, value, recurseTimes, visibleKeys, keys) {
                var output = [];
                for (var i = 0, l = value.length; l > i; ++i) output.push(hasOwnProperty(value, String(i)) ? formatProperty(ctx, value, recurseTimes, visibleKeys, String(i), true) : "");
                keys.forEach(function(key) {
                    key.match(/^\d+$/) || output.push(formatProperty(ctx, value, recurseTimes, visibleKeys, key, true));
                });
                return output;
            }
            function formatProperty(ctx, value, recurseTimes, visibleKeys, key, array) {
                var name, str, desc;
                desc = Object.getOwnPropertyDescriptor(value, key) || {
                    value: value[key]
                };
                desc.get ? str = desc.set ? ctx.stylize("[Getter/Setter]", "special") : ctx.stylize("[Getter]", "special") : desc.set && (str = ctx.stylize("[Setter]", "special"));
                hasOwnProperty(visibleKeys, key) || (name = "[" + key + "]");
                if (!str) if (ctx.seen.indexOf(desc.value) < 0) {
                    str = isNull(recurseTimes) ? formatValue(ctx, desc.value, null) : formatValue(ctx, desc.value, recurseTimes - 1);
                    str.indexOf("\n") > -1 && (str = array ? str.split("\n").map(function(line) {
                        return "  " + line;
                    }).join("\n").substr(2) : "\n" + str.split("\n").map(function(line) {
                        return "   " + line;
                    }).join("\n"));
                } else str = ctx.stylize("[Circular]", "special");
                if (isUndefined(name)) {
                    if (array && key.match(/^\d+$/)) return str;
                    name = JSON.stringify("" + key);
                    if (name.match(/^"([a-zA-Z_][a-zA-Z_0-9]*)"$/)) {
                        name = name.substr(1, name.length - 2);
                        name = ctx.stylize(name, "name");
                    } else {
                        name = name.replace(/'/g, "\\'").replace(/\\"/g, '"').replace(/(^"|"$)/g, "'");
                        name = ctx.stylize(name, "string");
                    }
                }
                return name + ": " + str;
            }
            function reduceToSingleString(output, base, braces) {
                var numLinesEst = 0;
                var length = output.reduce(function(prev, cur) {
                    numLinesEst++;
                    cur.indexOf("\n") >= 0 && numLinesEst++;
                    return prev + cur.replace(/\u001b\[\d\d?m/g, "").length + 1;
                }, 0);
                if (length > 60) return braces[0] + ("" === base ? "" : base + "\n ") + " " + output.join(",\n  ") + " " + braces[1];
                return braces[0] + base + " " + output.join(", ") + " " + braces[1];
            }
            function isArray(ar) {
                return Array.isArray(ar);
            }
            function isBoolean(arg) {
                return "boolean" == typeof arg;
            }
            function isNull(arg) {
                return null === arg;
            }
            function isNullOrUndefined(arg) {
                return null == arg;
            }
            function isNumber(arg) {
                return "number" == typeof arg;
            }
            function isString(arg) {
                return "string" == typeof arg;
            }
            function isSymbol(arg) {
                return "symbol" == typeof arg;
            }
            function isUndefined(arg) {
                return void 0 === arg;
            }
            function isRegExp(re) {
                return isObject(re) && "[object RegExp]" === objectToString(re);
            }
            function isObject(arg) {
                return "object" == typeof arg && null !== arg;
            }
            function isDate(d) {
                return isObject(d) && "[object Date]" === objectToString(d);
            }
            function isError(e) {
                return isObject(e) && ("[object Error]" === objectToString(e) || e instanceof Error);
            }
            function isFunction(arg) {
                return "function" == typeof arg;
            }
            function isPrimitive(arg) {
                return null === arg || "boolean" == typeof arg || "number" == typeof arg || "string" == typeof arg || "symbol" == typeof arg || "undefined" == typeof arg;
            }
            function objectToString(o) {
                return Object.prototype.toString.call(o);
            }
            function pad(n) {
                return 10 > n ? "0" + n.toString(10) : n.toString(10);
            }
            function timestamp() {
                var d = new Date();
                var time = [ pad(d.getHours()), pad(d.getMinutes()), pad(d.getSeconds()) ].join(":");
                return [ d.getDate(), months[d.getMonth()], time ].join(" ");
            }
            function hasOwnProperty(obj, prop) {
                return Object.prototype.hasOwnProperty.call(obj, prop);
            }
            var formatRegExp = /%[sdj%]/g;
            exports.format = function(f) {
                if (!isString(f)) {
                    var objects = [];
                    for (var i = 0; i < arguments.length; i++) objects.push(inspect(arguments[i]));
                    return objects.join(" ");
                }
                var i = 1;
                var args = arguments;
                var len = args.length;
                var str = String(f).replace(formatRegExp, function(x) {
                    if ("%%" === x) return "%";
                    if (i >= len) return x;
                    switch (x) {
                      case "%s":
                        return String(args[i++]);

                      case "%d":
                        return Number(args[i++]);

                      case "%j":
                        try {
                            return JSON.stringify(args[i++]);
                        } catch (_) {
                            return "[Circular]";
                        }

                      default:
                        return x;
                    }
                });
                for (var x = args[i]; len > i; x = args[++i]) str += isNull(x) || !isObject(x) ? " " + x : " " + inspect(x);
                return str;
            };
            exports.deprecate = function(fn, msg) {
                function deprecated() {
                    if (!warned) {
                        if (process.throwDeprecation) throw new Error(msg);
                        process.traceDeprecation ? console.trace(msg) : console.error(msg);
                        warned = true;
                    }
                    return fn.apply(this, arguments);
                }
                if (isUndefined(global.process)) return function() {
                    return exports.deprecate(fn, msg).apply(this, arguments);
                };
                if (true === process.noDeprecation) return fn;
                var warned = false;
                return deprecated;
            };
            var debugs = {};
            var debugEnviron;
            exports.debuglog = function(set) {
                isUndefined(debugEnviron) && (debugEnviron = process.env.NODE_DEBUG || "");
                set = set.toUpperCase();
                if (!debugs[set]) if (new RegExp("\\b" + set + "\\b", "i").test(debugEnviron)) {
                    var pid = process.pid;
                    debugs[set] = function() {
                        var msg = exports.format.apply(exports, arguments);
                        console.error("%s %d: %s", set, pid, msg);
                    };
                } else debugs[set] = function() {};
                return debugs[set];
            };
            exports.inspect = inspect;
            inspect.colors = {
                bold: [ 1, 22 ],
                italic: [ 3, 23 ],
                underline: [ 4, 24 ],
                inverse: [ 7, 27 ],
                white: [ 37, 39 ],
                grey: [ 90, 39 ],
                black: [ 30, 39 ],
                blue: [ 34, 39 ],
                cyan: [ 36, 39 ],
                green: [ 32, 39 ],
                magenta: [ 35, 39 ],
                red: [ 31, 39 ],
                yellow: [ 33, 39 ]
            };
            inspect.styles = {
                special: "cyan",
                number: "yellow",
                "boolean": "yellow",
                undefined: "grey",
                "null": "bold",
                string: "green",
                date: "magenta",
                regexp: "red"
            };
            exports.isArray = isArray;
            exports.isBoolean = isBoolean;
            exports.isNull = isNull;
            exports.isNullOrUndefined = isNullOrUndefined;
            exports.isNumber = isNumber;
            exports.isString = isString;
            exports.isSymbol = isSymbol;
            exports.isUndefined = isUndefined;
            exports.isRegExp = isRegExp;
            exports.isObject = isObject;
            exports.isDate = isDate;
            exports.isError = isError;
            exports.isFunction = isFunction;
            exports.isPrimitive = isPrimitive;
            exports.isBuffer = _dereq_("./support/isBuffer");
            var months = [ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" ];
            exports.log = function() {
                console.log("%s - %s", timestamp(), exports.format.apply(exports, arguments));
            };
            exports.inherits = _dereq_("inherits");
            exports._extend = function(origin, add) {
                if (!add || !isObject(add)) return origin;
                var keys = Object.keys(add);
                var i = keys.length;
                while (i--) origin[keys[i]] = add[keys[i]];
                return origin;
            };
        }, {
            "./support/isBuffer": 17,
            inherits: 19
        } ],
        19: [ function(_dereq_, module) {
            module.exports = "function" == typeof Object.create ? function(ctor, superCtor) {
                ctor.super_ = superCtor;
                ctor.prototype = Object.create(superCtor.prototype, {
                    constructor: {
                        value: ctor,
                        enumerable: false,
                        writable: true,
                        configurable: true
                    }
                });
            } : function(ctor, superCtor) {
                ctor.super_ = superCtor;
                var TempCtor = function() {};
                TempCtor.prototype = superCtor.prototype;
                ctor.prototype = new TempCtor();
                ctor.prototype.constructor = ctor;
            };
        }, {} ]
    }, {}, [ 14 ])(14);
});