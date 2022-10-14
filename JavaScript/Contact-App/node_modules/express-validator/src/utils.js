"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.toString = exports.bindAll = void 0;
exports.bindAll = (object) => {
    const protoKeys = Object.getOwnPropertyNames(Object.getPrototypeOf(object));
    protoKeys.forEach(key => {
        const maybeFn = object[key];
        if (typeof maybeFn === 'function' && key !== 'constructor') {
            object[key] = maybeFn.bind(object);
        }
    });
    return object;
};
function toString(value, deep = true) {
    if (Array.isArray(value) && value.length && deep) {
        return toString(value[0], false);
    }
    else if (value instanceof Date) {
        return value.toISOString();
    }
    else if (value && typeof value === 'object' && value.toString) {
        if (typeof value.toString !== 'function') {
            return Object.getPrototypeOf(value).toString.call(value);
        }
        return value.toString();
    }
    else if (value == null || (isNaN(value) && !value.length)) {
        return '';
    }
    return String(value);
}
exports.toString = toString;
