var debounce = function(fn, t) {
    let timer;
    return function(...args) {
        clearTimeout(timer);
        timer = setTimeout(() => fn(...args), t)
    }
};


/** Follow on Github : @utsxvrai  **/