function largestOfFour (arr) {
  const finalArray = []

  for (let i = 0; i < arr.length; i++) {
    let baseNum = arr[i][0]
    for (let j = 0; j < arr[i].length; j++) {
      if (baseNum < arr[i][j]) {
        baseNum = arr[i][j]
      }
    }
    finalArray.push(baseNum)
  }
  return finalArray
}