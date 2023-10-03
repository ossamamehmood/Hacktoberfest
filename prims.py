import sys

def prim_mst(vertices, start, graph):
    visited = [False] * vertices
    key = [sys.maxsize] * vertices
    key[start] = 0
    total_weight = 0

    for _ in range(vertices):
        min_key = sys.maxsize
        for v in range(vertices):
            if not visited[v] and key[v] < min_key:
                min_key = key[v]
                u = v

        visited[u] = True
        total_weight += key[u]

        for v in range(vertices):
            if (
                not visited[v]
                and graph[u][v] != 0
                and graph[u][v] < key[v]
            ):
                key[v] = graph[u][v]

    return total_weight


vertices = int(input())
start = int(input()) - 1
graph = []
for _ in range(vertices):
    row = list(map(int, input().split(',')))
    graph.append(row)


mst_weight = prim_mst(vertices, start, graph)

print(mst_weight)
