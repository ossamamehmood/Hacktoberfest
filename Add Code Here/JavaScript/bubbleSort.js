/**
 * Bubble Sort algorithm implementation for sorting an array of numbers in ascending order.
 * @param {number[]} arr - The array of numbers to be sorted.
 */
function bubbleSort(arr) {
  const n = arr.length;
  let swapped;

  do {
    swapped = false;
    for (let i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        // Swaping elements if they are in the wrong order
        const temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
}

// Example usage:
const arr = [64, 34, 25, 12, 22, 11, 90];
bubbleSort(arr);
console.log('Sorted array: ' + arr.join(' '));

// You can Export the bubbleSort function for use in other files
module.exports = bubbleSort;
