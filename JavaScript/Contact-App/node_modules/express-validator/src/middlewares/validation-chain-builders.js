"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.query = exports.param = exports.header = exports.cookie = exports.body = exports.check = exports.buildCheckFunction = void 0;
const check_1 = require("./check");
function buildCheckFunction(locations) {
    return (fields, message) => check_1.check(fields, locations, message);
}
exports.buildCheckFunction = buildCheckFunction;
exports.check = buildCheckFunction(['body', 'cookies', 'headers', 'params', 'query']);
exports.body = buildCheckFunction(['body']);
exports.cookie = buildCheckFunction(['cookies']);
exports.header = buildCheckFunction(['headers']);
exports.param = buildCheckFunction(['params']);
exports.query = buildCheckFunction(['query']);
