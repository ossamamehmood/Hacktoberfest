"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.selectFields = void 0;
const _ = require("lodash");
exports.selectFields = (req, fields, locations) => _(fields)
    .flatMap(field => _.flatMap(locations, location => {
    return expandField(req, field, location);
}))
    // Avoid duplicates if multiple field selections would return the same field twice.
    // E.g. with fields = ['*.foo', 'bar.foo'] and req.body = { bar: { foo: 1 }, baz: { foo: 2 } },
    // the instance bla.foo would appear twice, and baz.foo once.
    .uniqWith(isSameFieldInstance)
    .value();
function isSameFieldInstance(a, b) {
    return a.path === b.path && a.location === b.location;
}
function expandField(req, field, location) {
    const originalPath = field;
    const pathToExpand = location === 'headers' ? field.toLowerCase() : field;
    const paths = [];
    expandPath(req[location], pathToExpand, paths);
    return paths.map(path => {
        const value = path === '' ? req[location] : _.get(req[location], path);
        return {
            location,
            path,
            originalPath,
            value,
            originalValue: value,
        };
    });
}
function expandPath(object, path, accumulator) {
    const segments = _.toPath(path);
    const wildcardPos = segments.indexOf('*');
    if (wildcardPos > -1) {
        const subObject = wildcardPos === 0 ? object : _.get(object, segments.slice(0, wildcardPos));
        if (!subObject || !_.isObjectLike(subObject)) {
            return;
        }
        Object.keys(subObject)
            .map(key => segments
            // Before the *
            .slice(0, wildcardPos)
            // The part that the * matched
            .concat(key)
            // After the *
            .concat(segments.slice(wildcardPos + 1)))
            .forEach(subPath => {
            expandPath(object, subPath, accumulator);
        });
    }
    else {
        const reconstructedPath = segments.reduce((prev, segment) => {
            let part = '';
            // TODO: Handle brackets?
            if (segment.includes('.')) {
                // Special char key access
                part = `["${segment}"]`;
            }
            else if (/^\d+$/.test(segment)) {
                // Index access
                part = `[${segment}]`;
            }
            else if (prev) {
                // Object key access
                part = `.${segment}`;
            }
            else {
                // Top level key
                part = segment;
            }
            return prev + part;
        }, '');
        accumulator.push(reconstructedPath);
    }
}
