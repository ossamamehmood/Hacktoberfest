1. Create a dummy node and set its next pointer to the head of the linked list.
2. Initialize two pointers, `first` and `second`, to the dummy node.
3. Advance the `first` pointer `n + 1` nodes forward.
4. While the `first` pointer is not null:
    * Advance both the `first` and `second` pointers one node forward.
5. Set the `next` pointer of the `second` node to the `next` pointer of the `second.next` node.
6. Return the next pointer of the dummy node.

The time complexity of the algorithm is O(n), where n is the length of the linked list. This is because the algorithm needs to traverse the linked list twice.

The space complexity of the algorithm is O(1), since it only needs to store three pointers.
