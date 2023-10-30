function flattenArray(arr) {
    const flattened = [];
  
    function flattenHelper(arr) {
      for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i])) {
          flattenHelper(arr[i]);
        } else {
          flattened.push(arr[i]);
        }
      }
    }
  
    flattenHelper(arr);
  
    return flattened;
  }
  
  const arr = [1, 2, [1, 2, 3], [4, 5], 6];
  const flattenedArr = flattenArray(arr);
  console.log(flattenedArr);
  