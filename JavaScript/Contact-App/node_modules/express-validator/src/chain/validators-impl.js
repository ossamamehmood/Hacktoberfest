"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ValidatorsImpl = void 0;
const validator = require("validator");
const context_items_1 = require("../context-items");
class ValidatorsImpl {
    constructor(builder, chain) {
        this.builder = builder;
        this.chain = chain;
        this.negateNext = false;
    }
    addItem(item) {
        this.builder.addItem(item);
        this.lastValidator = item;
        // Reset this.negateNext so that next validation isn't negated too
        this.negateNext = false;
        return this.chain;
    }
    // validation manipulation
    not() {
        this.negateNext = true;
        return this.chain;
    }
    withMessage(message) {
        this.lastValidator.message = message;
        return this.chain;
    }
    // custom validators
    custom(validator) {
        return this.addItem(new context_items_1.CustomValidation(validator, this.negateNext));
    }
    exists(options = {}) {
        let validator;
        if (options.checkFalsy) {
            validator = value => !!value;
        }
        else if (options.checkNull) {
            validator = value => value != null;
        }
        else {
            validator = value => value !== undefined;
        }
        return this.custom(validator);
    }
    isArray(options = {}) {
        return this.custom(value => Array.isArray(value) &&
            (typeof options.min === 'undefined' || value.length >= options.min) &&
            (typeof options.max === 'undefined' || value.length <= options.max));
    }
    isObject(options = { strict: true }) {
        return this.custom(value => typeof value === 'object' &&
            (options.strict ? value !== null && !Array.isArray(value) : true));
    }
    isString() {
        return this.custom(value => typeof value === 'string');
    }
    notEmpty(options) {
        this.not();
        return this.isEmpty(options);
    }
    // Standard validators
    addStandardValidation(validator, ...options) {
        return this.addItem(new context_items_1.StandardValidation(validator, this.negateNext, options));
    }
    contains(elem, options) {
        return this.addStandardValidation(validator.contains, elem, options);
    }
    equals(comparison) {
        return this.addStandardValidation(validator.equals, comparison);
    }
    isAfter(date) {
        return this.addStandardValidation(validator.isAfter, date);
    }
    isAlpha(locale, options) {
        const ignore = Array.isArray(options === null || options === void 0 ? void 0 : options.ignore) ? options === null || options === void 0 ? void 0 : options.ignore.join('') : options === null || options === void 0 ? void 0 : options.ignore;
        return this.addStandardValidation(validator.isAlpha, locale, Object.assign(Object.assign({}, options), { ignore }));
    }
    isAlphanumeric(locale) {
        return this.addStandardValidation(validator.isAlphanumeric, locale);
    }
    isAscii() {
        return this.addStandardValidation(validator.isAscii);
    }
    isBase32() {
        return this.addStandardValidation(validator.isBase32);
    }
    isBase58() {
        return this.addStandardValidation(validator.isBase58);
    }
    isBase64(options) {
        return this.addStandardValidation(validator.isBase64, options);
    }
    isBefore(date) {
        return this.addStandardValidation(validator.isBefore, date);
    }
    isBIC() {
        return this.addStandardValidation(validator.isBIC);
    }
    isBoolean(options) {
        if (options === null || options === void 0 ? void 0 : options.strict) {
            return this.custom(value => {
                return value === true || value === false;
            });
        }
        return this.addStandardValidation(validator.isBoolean);
    }
    isBtcAddress() {
        return this.addStandardValidation(validator.isBtcAddress);
    }
    isByteLength(options) {
        return this.addStandardValidation(validator.isByteLength, options);
    }
    isCreditCard() {
        return this.addStandardValidation(validator.isCreditCard);
    }
    isCurrency(options) {
        return this.addStandardValidation(validator.isCurrency, options);
    }
    isDataURI() {
        return this.addStandardValidation(validator.isDataURI);
    }
    isDate(options) {
        return this.addStandardValidation(validator.isDate, options);
    }
    isDecimal(options) {
        return this.addStandardValidation(validator.isDecimal, options);
    }
    isDivisibleBy(number) {
        return this.addStandardValidation(validator.isDivisibleBy, number);
    }
    isEAN() {
        return this.addStandardValidation(validator.isEAN);
    }
    isEmail(options) {
        return this.addStandardValidation(validator.isEmail, options);
    }
    isEmpty(options) {
        return this.addStandardValidation(validator.isEmpty, options);
    }
    isEthereumAddress() {
        return this.addStandardValidation(validator.isEthereumAddress);
    }
    isFQDN(options) {
        return this.addStandardValidation(validator.isFQDN, options);
    }
    isFloat(options) {
        return this.addStandardValidation(validator.isFloat, options);
    }
    isFullWidth() {
        return this.addStandardValidation(validator.isFullWidth);
    }
    isHalfWidth() {
        return this.addStandardValidation(validator.isHalfWidth);
    }
    isHash(algorithm) {
        return this.addStandardValidation(validator.isHash, algorithm);
    }
    isHexColor() {
        return this.addStandardValidation(validator.isHexColor);
    }
    isHexadecimal() {
        return this.addStandardValidation(validator.isHexadecimal);
    }
    isHSL() {
        return this.addStandardValidation(validator.isHSL);
    }
    isIBAN() {
        return this.addStandardValidation(validator.isIBAN);
    }
    isIdentityCard(locale) {
        return this.addStandardValidation(validator.isIdentityCard, locale);
    }
    isIMEI(options) {
        return this.addStandardValidation(validator.isIMEI, options);
    }
    isIP(version) {
        return this.addStandardValidation(validator.isIP, version);
    }
    isIPRange() {
        return this.addStandardValidation(validator.isIPRange);
    }
    isISBN(version) {
        return this.addStandardValidation(validator.isISBN, version);
    }
    isISSN(options) {
        return this.addStandardValidation(validator.isISSN, options);
    }
    isISIN() {
        return this.addStandardValidation(validator.isISIN);
    }
    isISO8601(options) {
        return this.addStandardValidation(validator.isISO8601, options);
    }
    isISO31661Alpha2() {
        return this.addStandardValidation(validator.isISO31661Alpha2);
    }
    isISO31661Alpha3() {
        return this.addStandardValidation(validator.isISO31661Alpha3);
    }
    isISRC() {
        return this.addStandardValidation(validator.isISRC);
    }
    isIn(values) {
        return this.addStandardValidation(validator.isIn, values);
    }
    isInt(options) {
        return this.addStandardValidation(validator.isInt, options);
    }
    isJSON(options) {
        return this.addStandardValidation(validator.isJSON, options);
    }
    isJWT() {
        return this.addStandardValidation(validator.isJWT);
    }
    isLatLong(options) {
        return this.addStandardValidation(validator.isLatLong, options);
    }
    isLength(options) {
        return this.addStandardValidation(validator.isLength, options);
    }
    isLocale() {
        return this.addStandardValidation(validator.isLocale);
    }
    isLowercase() {
        return this.addStandardValidation(validator.isLowercase);
    }
    isMagnetURI() {
        return this.addStandardValidation(validator.isMagnetURI);
    }
    isMACAddress(options) {
        return this.addStandardValidation(validator.isMACAddress, options);
    }
    isMD5() {
        return this.addStandardValidation(validator.isMD5);
    }
    isMimeType() {
        return this.addStandardValidation(validator.isMimeType);
    }
    isMobilePhone(locale, options) {
        return this.addStandardValidation(validator.isMobilePhone, locale, options);
    }
    isMongoId() {
        return this.addStandardValidation(validator.isMongoId);
    }
    isMultibyte() {
        return this.addStandardValidation(validator.isMultibyte);
    }
    isNumeric(options) {
        return this.addStandardValidation(validator.isNumeric, options);
    }
    isOctal() {
        return this.addStandardValidation(validator.isOctal);
    }
    isPassportNumber(countryCode) {
        return this.addStandardValidation(validator.isPassportNumber, countryCode);
    }
    isPort() {
        return this.addStandardValidation(validator.isPort);
    }
    isPostalCode(locale) {
        return this.addStandardValidation(validator.isPostalCode, locale);
    }
    isRFC3339() {
        return this.addStandardValidation(validator.isRFC3339);
    }
    isRgbColor(includePercentValues) {
        return this.addStandardValidation(validator.isRgbColor, includePercentValues);
    }
    isSemVer() {
        return this.addStandardValidation(validator.isSemVer);
    }
    isSlug() {
        return this.addStandardValidation(validator.isSlug);
    }
    isStrongPassword(options) {
        return this.addStandardValidation(validator.isStrongPassword, options);
    }
    isSurrogatePair() {
        return this.addStandardValidation(validator.isSurrogatePair);
    }
    isTaxID(locale) {
        return this.addStandardValidation(validator.isTaxID, locale);
    }
    isURL(options) {
        return this.addStandardValidation(validator.isURL, options);
    }
    isUUID(version) {
        return this.addStandardValidation(validator.isUUID, version);
    }
    isUppercase() {
        return this.addStandardValidation(validator.isUppercase);
    }
    isVariableWidth() {
        return this.addStandardValidation(validator.isVariableWidth);
    }
    isVAT(countryCode) {
        return this.addStandardValidation(validator.isVAT, countryCode);
    }
    isWhitelisted(chars) {
        return this.addStandardValidation(validator.isWhitelisted, chars);
    }
    matches(pattern, modifiers) {
        return this.addStandardValidation(validator.matches, pattern, modifiers);
    }
}
exports.ValidatorsImpl = ValidatorsImpl;
