var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let results = new Array(functions.length);
        let count = 0;
        functions.forEach((fn, i) => {
            fn()
            .then(val => {
            results[i] = val;
            count++;
            if(count === functions.length) resolve(results)
            .catch(reason => reject(reason));
        })
      .catch(reason => reject(reason));
    })
  })
};

/** Follow on Github : @utsxvrai  **/