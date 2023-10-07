var cancellable = function(fn, args, t) {
    fn(...args);
    let timer = setInterval(() => fn(...args), t);
    
    let cancelFn = () => clearInterval(timer);
    return cancelFn;
};

/** Follow on Github : @utsxvrai  **/