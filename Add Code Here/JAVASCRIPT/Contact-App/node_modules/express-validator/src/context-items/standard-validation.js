"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.StandardValidation = void 0;
const utils_1 = require("../utils");
class StandardValidation {
    constructor(validator, negated, options = []) {
        this.validator = validator;
        this.negated = negated;
        this.options = options;
    }
    async run(context, value, meta) {
        const result = this.validator(utils_1.toString(value), ...this.options);
        if (this.negated ? result : !result) {
            context.addError(this.message, value, meta);
        }
    }
}
exports.StandardValidation = StandardValidation;
