"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var src_1 = require("../src");
// middleware/validation-chain-builders
Object.defineProperty(exports, "check", { enumerable: true, get: function () { return src_1.check; } });
Object.defineProperty(exports, "body", { enumerable: true, get: function () { return src_1.body; } });
Object.defineProperty(exports, "cookie", { enumerable: true, get: function () { return src_1.cookie; } });
Object.defineProperty(exports, "header", { enumerable: true, get: function () { return src_1.header; } });
Object.defineProperty(exports, "param", { enumerable: true, get: function () { return src_1.param; } });
Object.defineProperty(exports, "query", { enumerable: true, get: function () { return src_1.query; } });
Object.defineProperty(exports, "buildCheckFunction", { enumerable: true, get: function () { return src_1.buildCheckFunction; } });
// middleware/schema
Object.defineProperty(exports, "checkSchema", { enumerable: true, get: function () { return src_1.checkSchema; } });
// middleware/one-of
Object.defineProperty(exports, "oneOf", { enumerable: true, get: function () { return src_1.oneOf; } });
// validation-result
Object.defineProperty(exports, "validationResult", { enumerable: true, get: function () { return src_1.validationResult; } });
Object.defineProperty(exports, "Result", { enumerable: true, get: function () { return src_1.Result; } });
console.warn('express-validator: requires to express-validator/check are deprecated.' +
    'You should just use require("express-validator") instead.');
