1. Initialize two pointers, `start` and `end`, to the beginning and end of the input array `nums`, respectively.
2. Initialize a variable `ans` to the value of `start`.
3. While the element at the index `start` is greater than the element at the index `end`:
    * Calculate the middle index `mid` as (`start` + `end`) / 2.
    * If the element at the index `mid` is less than or equal to the element at the index `start` and the element at the index `mid` is less than or equal to the element at the index `end`, then set the value of `end` to `mid`.
    * If the element at the index `mid` is greater than or equal to the element at the index `start` and the element at the index `mid` is greater than or equal to the element at the index `end`, then set the value of `start` to `mid + 1`.
    * Otherwise, return the element at the index `mid`.
4. Update the value of `ans` to `start`.
5. Return the element at the index `ans`.

**Example:**

Consider the following input array `nums`:

nums = [3, 4, 5, 1, 2]

The algorithm will work as follows:

Iteration | start | end | mid | ans
-------- | -------- | -------- | -------- | --------
1        | 0        | 4        | 2        | 0
2        | 0        | 1        | 0        | 0

The algorithm will return the element at the index `ans`, which is `1`.