var TimeLimitedCache = function() {
     this.cache = new Map();  
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    let valcache = this.cache.get(key);
    if(valcache){
        clearTimeout(valcache.timeout);
    }
  let timeout = setTimeout(() => this.cache.delete(key), duration);
  this.cache.set(key, {value, timeout});
  return Boolean(valcache)
};

TimeLimitedCache.prototype.get = function(key) {
    return this.cache.has(key) ? this.cache.get(key).value : -1;
};

TimeLimitedCache.prototype.count = function() {
    return this.cache.size;
};


/** Follow on Github : @utsxvrai  **/