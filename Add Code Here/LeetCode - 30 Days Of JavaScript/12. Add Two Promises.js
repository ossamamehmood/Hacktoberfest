/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
  
    return new Promise(async (resolve, reject) => {
      const result1 = await promise1;
      const result2 = await promise2;

      resolve(result1 + result2)
    })
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

/** Follow on Github : @utsxvrai  **/