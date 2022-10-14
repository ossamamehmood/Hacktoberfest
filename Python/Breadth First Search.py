graph=[]
nodes=int(input("Enter the number of nodes: "))
print("Enter 0 if nodes are not connected and 1 if connected:")
for i in range(nodes):
    arr=list(map(int,input(f"Node {i}: ").split()))
    graph.append(arr)
start_node=int(input("Enter the start node: "))
destination_node=int(input("Enter the destination node: "))
visited=[]
result=[]
queue=[start_node]
while(queue):
    for j in range(nodes):
        if graph[queue[0]][j]==1 and j not in queue and j not in visited:
            queue.append(j)
    result.append(queue[0])
    visited.append(queue[0])
    if destination_node==queue[0]:
        break
    queue.remove(queue[0])
print("The final search result is: ")
for i in result:
    print(i,end=" ")