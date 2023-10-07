**Algorithm:**

1. Initialize two pointers, `left` and `right`, to the beginning of the array.
2. While `right` is less than the length of the array:
3. If the element at `right` is even:
    * Swap the elements at `left` and `right`.
    * Increment `left`.
4. Increment `right`.
5. Return the array.

**Time complexity:** O(n), where n is the length of the array.

**Space complexity:** O(1), as we only use two pointers.

For example, consider the following array:

[1, 2, 3, 4, 5]
If we call the `sortArrayByParity()` function on this array, the following steps will be taken:

1. The `left` and `right` pointers will both be initialized to the beginning of the array, which is index 0.
2. The element at `right` (index 0) is 1, which is odd. Therefore, the `left` and `right` pointers will not be swapped.
3. The `right` pointer is incremented to index 1.
4. The element at `right` (index 1) is 2, which is even. Therefore, the elements at `left` (index 0) and `right` (index 1) will be swapped.
5. The `left` pointer is incremented to index 1.
6. The `right` pointer is incremented to index 2.
7. The element at `right` (index 2) is 3, which is odd. Therefore, the `left` and `right` pointers will not be swapped.
8. The `right` pointer is incremented to index 3.
9. The element at `right` (index 3) is 4, which is even. Therefore, the elements at `left` (index 1) and `right` (index 3) will be swapped.
10. The `left` pointer is incremented to index 2.
11. The `right` pointer is incremented to index 4.
12. The element at `right` (index 4) is 5, which is odd. Therefore, the `left` and `right` pointers will not be swapped.
13. The `right` pointer has reached the end of the array, so the loop will terminate.
14. The function will return the array, which is now sorted by parity:

ans = [2, 4, 1, 3, 5]
