"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.matchedData = void 0;
const _ = require("lodash");
const base_1 = require("./base");
function matchedData(req, options = {}) {
    const internalReq = req;
    const fieldExtractor = createFieldExtractor(options.includeOptionals !== true);
    const validityFilter = createValidityFilter(options.onlyValidData);
    const locationFilter = createLocationFilter(options.locations);
    return _(internalReq[base_1.contextsKey])
        .flatMap(fieldExtractor)
        .filter(validityFilter)
        .map(field => field.instance)
        .filter(locationFilter)
        .reduce((state, instance) => _.set(state, instance.path, instance.value), {})
        .valueOf();
}
exports.matchedData = matchedData;
function createFieldExtractor(removeOptionals) {
    return (context) => {
        const instances = context.getData({ requiredOnly: removeOptionals });
        return instances.map((instance) => ({ instance, context }));
    };
}
function createValidityFilter(onlyValidData = true) {
    return !onlyValidData
        ? () => true
        : (field) => {
            const hasError = field.context.errors.some(error => error.location === field.instance.location && error.param === field.instance.path);
            return !hasError;
        };
}
function createLocationFilter(locations = []) {
    // No locations mean all locations
    const allLocations = locations.length === 0;
    return allLocations ? () => true : (field) => locations.includes(field.location);
}
