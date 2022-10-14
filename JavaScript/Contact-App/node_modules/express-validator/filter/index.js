"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var src_1 = require("../src");
// middleware/sanitization-chain-builders
Object.defineProperty(exports, "sanitize", { enumerable: true, get: function () { return src_1.sanitize; } });
Object.defineProperty(exports, "sanitizeBody", { enumerable: true, get: function () { return src_1.sanitizeBody; } });
Object.defineProperty(exports, "sanitizeCookie", { enumerable: true, get: function () { return src_1.sanitizeCookie; } });
Object.defineProperty(exports, "sanitizeParam", { enumerable: true, get: function () { return src_1.sanitizeParam; } });
Object.defineProperty(exports, "sanitizeQuery", { enumerable: true, get: function () { return src_1.sanitizeQuery; } });
Object.defineProperty(exports, "buildSanitizeFunction", { enumerable: true, get: function () { return src_1.buildSanitizeFunction; } });
// matched-data
Object.defineProperty(exports, "matchedData", { enumerable: true, get: function () { return src_1.matchedData; } });
console.warn('express-validator: requires to express-validator/filter are deprecated.' +
    'You should just use require("express-validator") instead.');
