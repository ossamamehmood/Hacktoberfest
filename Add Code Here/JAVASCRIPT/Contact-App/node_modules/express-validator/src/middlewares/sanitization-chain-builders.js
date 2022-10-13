"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.sanitizeQuery = exports.sanitizeParam = exports.sanitizeCookie = exports.sanitizeBody = exports.sanitize = exports.buildSanitizeFunction = void 0;
const sanitize_1 = require("./sanitize");
function buildSanitizeFunction(locations) {
    return (fields) => sanitize_1.sanitize(fields, locations);
}
exports.buildSanitizeFunction = buildSanitizeFunction;
exports.sanitize = buildSanitizeFunction(['body', 'cookies', 'params', 'query']);
exports.sanitizeBody = buildSanitizeFunction(['body']);
exports.sanitizeCookie = buildSanitizeFunction(['cookies']);
exports.sanitizeParam = buildSanitizeFunction(['params']);
exports.sanitizeQuery = buildSanitizeFunction(['query']);
