1. If the linked list is empty or has only one node, then return the head of the linked list.
2. Calculate the length of the linked list.
3. Set the `next` pointer of the last node in the linked list to the head of the linked list.
4. Calculate the new head of the linked list by moving `k` nodes from the end of the linked list.
5. Set the `next` pointer of the node before the new head to `null`.
6. Return the new head of the linked list.

**Example:**

Consider the following linked list:

head -> 1 -> 2 -> 3 -> 4 -> 5

and the value `k = 2`.

The algorithm will work as follows:

1. Calculate the length of the linked list, which is 5.
2. Set the `next` pointer of the last node in the linked list (node 5) to the head of the linked list (node 1).
3. Calculate the new head of the linked list by moving 2 nodes from the end of the linked list. The new head is node 4.
4. Set the `next` pointer of the node before the new head (node 3) to `null`.
5. Return the new head of the linked list, which is node 4.

The output of the algorithm is the following linked list:

4 -> 5 -> 1 -> 2 -> 3 -> null
