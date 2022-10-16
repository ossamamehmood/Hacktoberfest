// Linear search algorithm

function linearSearch(arr, num) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === num) return i;
    }
    return -1
}
linearSearch([10, 15, 20, 25, 30], 15)
