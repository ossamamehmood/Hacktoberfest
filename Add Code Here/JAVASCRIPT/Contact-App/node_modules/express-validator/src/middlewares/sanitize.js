"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.sanitize = void 0;
const chain_1 = require("../chain");
const utils_1 = require("../utils");
const context_builder_1 = require("../context-builder");
let hasNotified = false;
function sanitize(fields = '', locations = []) {
    if (!hasNotified) {
        hasNotified = true;
        console.warn('express-validator: sanitize(), sanitizeBody() and other sanitization-only middlewares ' +
            'have been deprecated.\nPlease use check(), body() and others instead, which must offer ' +
            'the same API, and more.');
    }
    const builder = new context_builder_1.ContextBuilder()
        .setFields(Array.isArray(fields) ? fields : [fields])
        .setLocations(locations);
    const runner = new chain_1.ContextRunnerImpl(builder);
    const middleware = async (req, _res, next) => {
        try {
            await runner.run(req);
            next();
        }
        catch (e) {
            next(e);
        }
    };
    return Object.assign(middleware, utils_1.bindAll(runner), utils_1.bindAll(new chain_1.SanitizersImpl(builder, middleware)), { builder });
}
exports.sanitize = sanitize;
