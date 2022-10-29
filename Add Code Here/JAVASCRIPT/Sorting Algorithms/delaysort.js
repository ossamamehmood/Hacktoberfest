// Delay/timer sort Implementation using Javascript

//array to be sorted
var arr = [25, 13, 55, 63, 2, 61, 35, 47];

const delaySort = async (arr) => {
  let result = [];
  let handler = arr.map(async (i) => {
    return new Promise((resolve) =>
      setTimeout(() => {
        result.push(i);
        resolve();
      }, i)
    );
  });

  await Promise.all(handler);
  return result;
};

// sort an array of numbers using javascript timer method asyncronously
delaySort(arr).then(function (result) {
  console.log("Sorted array:", result);
});
