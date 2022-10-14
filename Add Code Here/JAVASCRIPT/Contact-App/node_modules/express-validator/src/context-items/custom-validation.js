"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.CustomValidation = void 0;
class CustomValidation {
    constructor(validator, negated) {
        this.validator = validator;
        this.negated = negated;
    }
    async run(context, value, meta) {
        try {
            const result = this.validator(value, meta);
            const actualResult = await result;
            const isPromise = result && result.then;
            const failed = this.negated ? actualResult : !actualResult;
            // A promise that was resolved only adds an error if negated.
            // Otherwise it always suceeds
            if ((!isPromise && failed) || (isPromise && this.negated)) {
                context.addError(this.message, value, meta);
            }
        }
        catch (err) {
            if (this.negated) {
                return;
            }
            context.addError((err instanceof Error ? err.message : err) || this.message, value, meta);
        }
    }
}
exports.CustomValidation = CustomValidation;
