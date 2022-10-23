const getMessage = (username,message,url) =>{
    return {
        username,
        message,
        url,
        createdAt: new Date().getTime(),
    }
}

module.exports = {
    getMessage
}