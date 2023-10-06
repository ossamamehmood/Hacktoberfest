1. Initialize two pointers, `slowPtr` and `fastPtr`, to the beginning of the array.
2. While the two pointers are not equal:
    * Move the `fastPtr` pointer two steps forward.
    * Move the `slowPtr` pointer one step forward.
3. Initialize the `fastPtr` pointer to the beginning of the array.
4. While the two pointers are not equal:
    * Move the `fastPtr` pointer one step forward.
    * Move the `slowPtr` pointer one step forward.
5. The `slowPtr` pointer will now be pointing to the duplicate element in the array.
6. Return the value of the `slowPtr` pointer.

The Floyd's cycle detection algorithm works by finding the intersection point of two runners, one that moves two steps at a time and the other that moves one step at a time. If there is a cycle in the array, then the two runners will eventually meet at the intersection point. The intersection point will be the duplicate element in the array.

The time complexity of the algorithm is O(n), where n is the length of the array. This is because the algorithm traverses the array twice.

The space complexity of the algorithm is O(1), since it only needs to store two pointers.