1. Initialize a priority queue to store the edges that need to be considered. The priority queue is sorted in ascending order of the edge weight.
2. Add the edge with the lowest weight to the priority queue.
3. While the priority queue is not empty:
    * Pop the edge with the lowest weight from the priority queue.
    * If the popped edge connects two unconnected vertices, then add the edge to the spanning tree and mark the two vertices as connected.
    * Otherwise, discard the edge.
4. Return the spanning tree.

Our code implements Prim's algorithm efficiently by using a priority queue to store the edges that need to be considered. The priority queue ensures that the edges are considered in order of increasing weight, which leads to a more efficient search.

Here are some specific comments about the code:

* We use a `boolean[]` array to track which vertices have already been visited. This is a good approach, as it allows we to avoid adding duplicate edges to the spanning tree.
* We use a `Queue<Integer>` to store the vertices that need to be considered. This is also a good approach, as it allows we to implement Prim's algorithm in a recursive manner.
* We use a `Integer.MAX_VALUE` as the initial value for the `len` variable. This ensures that the first edge added to the priority queue is the edge with the lowest weight.
* We use a `choosen` variable to track the vertex that is connected to the lowest-weight edge. This allows you to avoid adding the same edge to the priority queue multiple times.
