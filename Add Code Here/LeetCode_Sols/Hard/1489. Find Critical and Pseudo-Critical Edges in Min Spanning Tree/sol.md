The algorithm for the `findCriticalAndPseudoCriticalEdges()` function can be summarized as follows:

1. Sort the edges in ascending order by weight.
2. Initialize two empty lists: `critical` and `pseudoCritical`.
3. Iterate over the edges in sorted order:
    * If the MST weight increases when the edge is removed, then the edge is critical and should be added to the `critical` list.
    * If the MST weight does not change when the edge is removed, then the edge is pseudo-critical and should be added to the `pseudoCritical` list.
4. Return the `critical` and `pseudoCritical` lists.

The `findMST()` function uses Prim's algorithm to find the minimum spanning tree of the graph. It takes three arguments:

* `n`: The number of nodes in the graph.
* `edges`: An array of edges, where each edge is represented by a 4-element array `[u, v, w, i]`, where `u` and `v` are the nodes that the edge connects, `w` is the weight of the edge, and `i` is the index of the edge in the original `edges` array.
* `block`: The index of the edge to block, or -1 if no edge should be blocked.
* `e`: The index of the edge to add before finding the MST, or -1 if no edge should be added.

The `findMST()` function returns the weight of the MST, or `Integer.MAX_VALUE` if the graph is not connected.

For example, consider the following input:

n = 4
edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [0, 3, 4], [1, 4, 5], [2, 4, 6]]

The sorted edges array is as follows:

edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [0, 3, 4], [1, 4, 5], [2, 4, 6]]

The MST weight without any edges blocked is 6.

The MST weight with the edge `[0, 3]` blocked is 9.

The MST weight with the edge `[1, 4]` blocked is 7.

Therefore, the critical edges are `[0, 3]` and `[1, 4]`, and the pseudo-critical edges are `[1, 2]`, `[2, 3]`, and `[2, 4]`.
