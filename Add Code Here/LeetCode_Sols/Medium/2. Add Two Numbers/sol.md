1. Create a new linked list `temp` to store the sum of the two input linked lists.
2. Iterate over the two input linked lists, `l1` and `l2`:
    * Add the values of the current nodes in `l1` and `l2`, and the carryover from the previous iteration, to get the sum.
    * Calculate the carryover by dividing the sum by 10 and taking the remainder.
    * Add the remainder to the new linked list `temp`.
    * Move to the next nodes in `l1` and `l2`.
3. If there is a carryover after the iteration, add it to the new linked list `temp`.
4. Return the head of the new linked list `temp`.

**Example:**

Consider the following input:

l1 = [2, 4, 3]
l2 = [5, 6, 4]

The algorithm will work as follows:

Iteration | l1.val | l2.val | sum | carryover | temp
-------- | -------- | -------- | -------- | -------- | --------
1        | 2        | 5        | 7        | 0       | [7]
2        | 4        | 6        | 10       | 1       | [7, 1]
3        | 3        | 4        | 7        | 0       | [7, 1, 7]

The output of the algorithm is the head of the new linked list `temp`, which is `[7, 1, 7]`.
