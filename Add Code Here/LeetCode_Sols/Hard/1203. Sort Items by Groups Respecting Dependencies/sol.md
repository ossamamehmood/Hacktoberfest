The algorithm for the `sortItems()` function can be summarized as follows:

1. Assign a unique group ID to each item that does not already have one.
2. Construct two graphs:
    * An item graph, where each edge connects a pair of items where the first item must be completed before the second item can be started.
    * A group graph, where each edge connects a pair of groups where the first group must be completed before the second group can be started.
3. Calculate the indegree of each item and group.
4. Perform a topological sort on the item graph. If the topological sort is unsuccessful, then the input is invalid and the function returns an empty array.
5. Perform a topological sort on the group graph. If the topological sort is unsuccessful, then the input is invalid and the function returns an empty array.
6. Construct a map that maps each group ID to a list of items in that group.
7. Iterate over the groups in topological order, adding the items in each group to the answer list.
8. Return the answer list.

For example, consider the following input:


n = 8
m = 2
group = [-1, -1, 1, 0, 0, 1, 1, -1]
beforeItems = {[], [6], [5], [], [6], [], [], [5]}


The item graph is:

itemGraph = {
    0: [],
    1: [6],
    2: [5],
    3: [],
    4: [6],
    5: [],
    6: [],
    7: [5]
}

The group graph is:

groupGraph = {
    0: [1],
    1: []
}

The indegree of each item is:

itemIndegree = [0, 1, 1, 0, 1, 0, 0, 1]

The indegree of each group is:

groupIndegree = [1, 0]

The topological sort of the item graph is `[0, 3, 4, 1, 2, 5, 6, 7]`.

The topological sort of the group graph is `[0, 1]`.

The map of group IDs to lists of items is:

orderedGroups = {
    0: [0, 3, 4],
    1: [1, 2, 5, 6, 7]
}

The answer list is `[0, 3, 4, 1, 2, 5, 6, 7]`.
