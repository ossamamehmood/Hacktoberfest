1. Initialize the number of operations to 0.
2. Initialize the previous bound to the largest element in the array.
3. Iterate over the array in reverse order:
    * For each element in the array, calculate the number of times it needs to be divided by the previous bound to make it less than or equal to the previous bound.
    * Add the number of times the element needs to be divided to the number of operations.
    * Update the previous bound to the element divided by the number of times it was divided.
4. Return the number of operations.

For example, consider the following input:

nums = [3, 2, 1]

The output is 1.

**Explanation:**

The largest element in the array is 3, so the previous bound is initialized to 3.

The first element in the array is 2, which is greater than the previous bound. To make the element less than or equal to the previous bound, it needs to be divided by 3 once.

The second element in the array is 1, which is less than or equal to the previous bound, so it does not need to be divided.

The updated previous bound is 2, since the first element was divided by 3.

The total number of operations is 1, since the first element needed to be divided once.
