"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Context = void 0;
const _ = require("lodash");
function getDataMapKey(path, location) {
    return `${location}:${path}`;
}
class Context {
    constructor(fields, locations, stack, optional, message) {
        this.fields = fields;
        this.locations = locations;
        this.stack = stack;
        this.optional = optional;
        this.message = message;
        this._errors = [];
        this.dataMap = new Map();
    }
    get errors() {
        return this._errors;
    }
    getData(options = { requiredOnly: false }) {
        // Have to store this.optional in a const otherwise TS thinks the value could have changed
        // when the functions below run
        const { optional } = this;
        const checks = options.requiredOnly && optional
            ? [
                (value) => value !== undefined,
                (value) => (optional.nullable ? value != null : true),
                (value) => (optional.checkFalsy ? value : true),
            ]
            : [];
        return _([...this.dataMap.values()])
            .groupBy('originalPath')
            .flatMap((instances, group) => {
            const locations = _.uniqBy(instances, 'location');
            // #331 - When multiple locations are involved, all of them must pass the validation.
            // If none of the locations contain the field, we at least include one for error reporting.
            // #458, #531 - Wildcards are an exception though: they may yield 0..* instances with different
            // paths, so we may want to skip this filtering.
            if (instances.length > 1 && locations.length > 1 && !group.includes('*')) {
                const withValue = instances.filter(instance => instance.value !== undefined);
                return withValue.length ? withValue : [instances[0]];
            }
            return instances;
        })
            .filter(instance => checks.every(check => check(instance.value)))
            .valueOf();
    }
    addFieldInstances(instances) {
        instances.forEach(instance => {
            this.dataMap.set(getDataMapKey(instance.path, instance.location), Object.assign({}, instance));
        });
    }
    setData(path, value, location) {
        const instance = this.dataMap.get(getDataMapKey(path, location));
        if (!instance) {
            throw new Error('Attempt to write data that did not pre-exist in context');
        }
        instance.value = value;
    }
    addError(message, valueOrNestedErrors, meta) {
        const msg = message || this.message || 'Invalid value';
        if (meta) {
            this._errors.push({
                value: valueOrNestedErrors,
                msg: typeof msg === 'function' ? msg(valueOrNestedErrors, meta) : msg,
                param: meta.path,
                location: meta.location,
            });
        }
        else {
            this._errors.push({
                msg,
                param: '_error',
                nestedErrors: valueOrNestedErrors,
            });
        }
    }
}
exports.Context = Context;
