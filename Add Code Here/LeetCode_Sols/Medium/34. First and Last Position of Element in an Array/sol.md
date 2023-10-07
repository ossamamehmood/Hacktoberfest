1. Create a new array `arr` of size 2 to store the start and end indices of the target element in the sorted array `nums`.
2. Call the `firstIndex()` function to find the start index of the target element in the sorted array.
3. Call the `lastIndex()` function to find the end index of the target element in the sorted array.
4. Return the array `arr`.

The `firstIndex()` and `lastIndex()` functions work in a similar way. They both use binary search to find the start and end indices of the target element in the sorted array, respectively.

The `firstIndex()` function works as follows:

1. Initialize two pointers, `s` and `e`, to the start and end indices of the sorted array, respectively.
2. While `s` is less than or equal to `e`:
    * Calculate the middle index `mid` as `s + (e - s) / 2`.
    * If the element at the middle index is greater than or equal to the target element, then set the end index `e` to `mid - 1`.
    * Otherwise, set the start index `s` to `mid + 1`.
    * If the element at the middle index is equal to the target element, then set the start index `s` to `mid`.
3. Return the start index `s`.

The `lastIndex()` function works in a similar way, except that it sets the end index `e` to `mid + 1` if the element at the middle index is less than or equal to the target element.

**Example:**

Consider the following sorted array `nums` and the target element `target = 5`:

nums = [1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9]


The `firstIndex()` function will return the index `3`, which is the start index of the target element in the sorted array.

The `lastIndex()` function will return the index `5`, which is the end index of the target element in the sorted array.

Therefore, the `searchRange()` function will return the array `[3, 5]`.


