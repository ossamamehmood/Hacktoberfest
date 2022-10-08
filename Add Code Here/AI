graph1 = {
'A': set(['B', 'C']),
'B': set(['A', 'D', 'E']),
'C': set(['A', 'F']),
'D': set(['B']),
'E': set(['B', 'F']),
'F': set(['C', 'E'])
}

def dfs(graph, node, visited):
    if node not in visited: 
        visited.append(node)
        for n in graph[node]:
            dfs(graph,n, visited)


    return visited
visited = dfs(graph1,'A', [])
print(visited)
