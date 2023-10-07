1. Initialize a priority queue to store the nodes that need to be visited. The priority queue is sorted in descending order of the effort required to reach the node.
2. Add the source node to the priority queue with an effort of 0.
3. While the priority queue is not empty:
    * Pop the node with the lowest effort from the priority queue.
    * If the popped node is the destination node, then return the effort.
    * For each neighbor of the popped node:
        * Calculate the effort to reach the neighbor.
        * If the calculated effort is lower than the current effort for the neighbor, then update the effort for the neighbor and add it to the priority queue.
4. Return the effort required to reach the destination node, or -1 if the destination node is unreachable.

The code implements Dijkstra's algorithm efficiently by using a priority queue to store the nodes that need to be visited. Priority queue ensures that the nodes are visited in order of increasing effort, which leads to a more efficient search.