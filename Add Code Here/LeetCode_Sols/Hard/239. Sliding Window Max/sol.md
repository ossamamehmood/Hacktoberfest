**Algorithm:**

1. Initialize a deque to store the indices of the elements in the sliding window.
2. Iterate over the array `nums`:
    * While the deque is not empty and the front element of the deque is outside the sliding window, remove the front element from the deque.
    * While the deque is not empty and the element at the back of the deque is smaller than the current element, remove the back element from the deque.
    * Add the index of the current element to the back of the deque.
    * If the current index is greater than or equal to `k - 1`, then the sliding window has reached its full size. Add the element at the front of the deque to the answer array.
3. Return the answer array.

**Time complexity:** O(n), where n is the length of the array `nums`.

**Space complexity:** O(k), where k is the size of the sliding window.

For example, consider the following input:

nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3

The deque will be filled like this:

[0, 1, 2]
[1, 2, 3]
[2, 3, 4]
[3, 4, 5]
[4, 5, 6]
[5, 6, 7]

The answer array will be filled like this:

ans = [3, 3, 5, 5, 6, 7]
