from bfs import bfs


def augment_flow(graph, flow_path):
    """ Augment flow of the graph
    :param graph:
    :param flow_path: (list) eg [('source', 'CA'), ('CA', 'AZ'), ('AZ', 'sink')]
    :return:
        1. get the bottleneck capacity
        2. update the residual capacities of forward and back edges
        3. return graph with flow augmented.
    """
    bottleneck = min([graph[u][v]['capacity'] for u, v in flow_path])
    for u, v in flow_path:
        updated_capacity = graph.edge[u][v]['capacity'] - bottleneck
        if updated_capacity:
            graph.edge[u][v]['capacity'] = updated_capacity
        else:
            graph.remove_edge(u, v)
        if not graph.has_edge(v, u):
            graph.add_edge(v, u)
            graph.edge[v][u]['capacity'] = 0
        graph.edge[v][u]['capacity'] += bottleneck
    return graph


def ford_fulkerson(graph, source, sink):
    """ Run the Ford Fulkerson method using BFS for shortest path
    :param graph:
    :param source:
    :param sink:
    :return:
        Once BFS can no longer find any shortest direct path between source and sink,
        return the residual graph with the updated capacities.
    """
    path = bfs(graph, source, sink)
    while path:
        flow_path = zip(path[:-1], path[1:])
        graph = augment_flow(graph, flow_path)
        path = bfs(graph, source, sink)
    return graph


if __name__ == '__main__':
    pass
