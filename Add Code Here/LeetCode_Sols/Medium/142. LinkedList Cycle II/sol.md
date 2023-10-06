1. Initialize two pointers, `slow` and `fast`, to the head of the linked list.
2. Iterate over the linked list:
    * Move the `slow` pointer one node forward.
    * Move the `fast` pointer two nodes forward.
    * If the `fast` pointer and the `slow` pointer meet, then there is a cycle in the linked list.
3. If the `fast` pointer reaches the end of the linked list without meeting the `slow` pointer, then there is no cycle in the linked list.
4. If there is a cycle in the linked list, then the function returns the node where the `slow` pointer and the `fast` pointer meet.

**Example:**

Consider the following linked list:
head -> 1 -> 2 -> 3 -> 4 -> 5 -> 3


The algorithm will work as follows:


Iteration | slow.val | fast.val |
-------- | -------- | -------- |
1        | 1        | 1        |
2        | 2        | 3        |
3        | 3        | 4        |
4        | 4        | 5        |
5        | 5        | 3        |


At the fifth iteration, the `slow` pointer and the `fast` pointer meet at the node `3`. Therefore, the function returns the node `3`.
