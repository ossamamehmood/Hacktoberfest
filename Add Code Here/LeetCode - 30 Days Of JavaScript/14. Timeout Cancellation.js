var cancellable = function(fn, args, t) {
      const timeout = setTimeout(() => {
          fn(...args);
      }, t)
      return cancel = () => {
          clearTimeout(timeout);
      } 
};

/** Follow on Github : @utsxvrai  **/