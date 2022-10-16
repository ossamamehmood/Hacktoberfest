graph=[]
nodes=int(input("Enter the number of nodes: "))
print("Enter 0 if nodes are not connected and 1 if connected:")
for i in range(nodes):
    arr=list(map(int,input(f"Node {i}: ").split()))
    graph.append(arr)
start_node=int(input("Enter the start node: "))
destination_node=int(input("Enter the destination node: "))
queue=[start_node]
visited=[]
def DFS(u):
    visited.append(u)
    if destination_node==u:
        return
    for v in range(len(graph)):
        if graph[u][v]==1 and v not in visited:
            DFS(v)

DFS(start_node)
for i in visited:
    print(i,end=" ")
        