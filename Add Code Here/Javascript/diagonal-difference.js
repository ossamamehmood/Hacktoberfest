function diagonalDifference(arr) {
    let diagonal1 = 0
    let diagonal2 = 0
    for(let i=0; i<arr.length; i++) {
     for(let j=0; j<arr.length; j++) {
        if(i === j) {
            diagonal1+=arr[i][j]
        }
        if (i+j === arr.length - 1) {
            diagonal2 += arr[i][j]
        }
    }   
    }
    return Math.abs(diagonal2 - diagonal1)
}