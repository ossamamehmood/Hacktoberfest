"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Result = exports.validationResult = void 0;
const _ = require("lodash");
const base_1 = require("./base");
const utils_1 = require("./utils");
// Assign to a variable so that TS doesn't use its catch all overload, which returns any
const withWithDefaults = { withDefaults };
exports.validationResult = Object.assign(withDefaults(), withWithDefaults);
class Result {
    constructor(formatter, errors) {
        this.formatter = formatter;
        this.errors = errors;
    }
    array(options) {
        return options && options.onlyFirstError
            ? Object.values(this.mapped())
            : this.errors.map(this.formatter);
    }
    mapped() {
        return this.errors.reduce((mapping, error) => {
            if (!mapping[error.param]) {
                mapping[error.param] = this.formatter(error);
            }
            return mapping;
        }, {});
    }
    formatWith(formatter) {
        return new Result(formatter, this.errors);
    }
    isEmpty() {
        return this.errors.length === 0;
    }
    throw() {
        if (!this.isEmpty()) {
            throw Object.assign(new Error(), utils_1.bindAll(this));
        }
    }
}
exports.Result = Result;
function withDefaults(options = {}) {
    const defaults = {
        formatter: error => error,
    };
    const actualOptions = _.defaults(options, defaults);
    return (req) => {
        const contexts = req[base_1.contextsKey] || [];
        const errors = _.flatMap(contexts, 'errors');
        return new Result(actualOptions.formatter, errors);
    };
}
