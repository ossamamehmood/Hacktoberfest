/**
 * @param {Object} context
 * @param {Array} args
 * @return {null|boolean|number|string|Array|Object}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    return this.apply(context, args);
 }
 
 /**
  * function increment() { this.count++; return this.count; }
  * increment.callPolyfill({count: 1}); // 2
  */