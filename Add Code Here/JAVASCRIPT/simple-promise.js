function generatePromise(msg) {
    return new Promise((resolve, reject) => {
        if(msg === 'hacktoberfest') {
            resolve('Hello Hacktoberfest')
        } else {
            reject(':(')
        }
    })
}