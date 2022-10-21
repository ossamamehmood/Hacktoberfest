"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Sanitization = void 0;
const utils_1 = require("../utils");
class Sanitization {
    constructor(sanitizer, custom, options = []) {
        this.sanitizer = sanitizer;
        this.custom = custom;
        this.options = options;
    }
    async run(context, value, meta) {
        const { path, location } = meta;
        const runCustomSanitizer = async () => {
            const sanitizerValue = this.sanitizer(value, meta);
            return Promise.resolve(sanitizerValue);
        };
        const newValue = this.custom
            ? await runCustomSanitizer()
            : this.sanitizer(utils_1.toString(value), ...this.options);
        context.setData(path, newValue, location);
    }
}
exports.Sanitization = Sanitization;
