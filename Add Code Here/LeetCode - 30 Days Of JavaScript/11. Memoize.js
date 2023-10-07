/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    let cache = {}
    return function(...args) {
        let key=`${args}`
        if(cache.hasOwnProperty(key)){
            return cache[key]
        }
        else {

    cache[key] = fn.apply(this, args)
    return cache[key]
        }
    }
}


/** Follow on Github : @utsxvrai  **/