# Depth First Search Algorithm

# Define a class to represent a graph
class Graph:
    def __init__(self):
        self.graph = {}

    # Function to add an edge to the graph
    def add_edge(self, vertex, neighbor):
        if vertex in self.graph:
            self.graph[vertex].append(neighbor)
        else:
            self.graph[vertex] = [neighbor]

    # Recursive function to perform DFS traversal
    def dfs(self, start_vertex, visited=None):
        if visited is None:
            visited = set()
        
        # Mark the current vertex as visited
        visited.add(start_vertex)
        
        # Print the current vertex to visualize the traversal
        print(start_vertex, end=' ')

        # Recur for all the neighboring vertices that are not visited
        for neighbor in self.graph.get(start_vertex, []):
            if neighbor not in visited:
                self.dfs(neighbor, visited)

# Create a graph
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

# Choose a starting vertex for DFS
start_vertex = 2

# Perform DFS traversal starting from the chosen vertex
print("Depth-First Traversal (starting from vertex {}):".format(start_vertex))
g.dfs(start_vertex)
