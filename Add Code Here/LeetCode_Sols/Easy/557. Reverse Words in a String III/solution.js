const reverseWords = function(s) {
    //convert string to array
    let arrayOfs = s.split(" ")

    //loop over the hole array
    let finalstr = arrayOfs.map((item) => {
        //every element of array convert to a nasted array and reverser it then make it string again
        return item.split("").reverse().join("")
    })
    return finalstr.join(" ")
};