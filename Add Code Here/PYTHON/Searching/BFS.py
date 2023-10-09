# Breadth First Search Algorithm

from collections import defaultdict, deque

# Define a class to represent a graph
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    # Function to add an edge to the graph
    def add_edge(self, vertex, neighbor):
        self.graph[vertex].append(neighbor)

    # Function to perform BFS traversal
    def bfs(self, start_vertex):
        # Create a set to keep track of visited vertices
        visited = set()
        
        # Create a queue for BFS
        queue = deque()
        
        # Enqueue the starting vertex
        queue.append(start_vertex)
        
        # Mark the starting vertex as visited
        visited.add(start_vertex)
        
        # Print the starting vertex to visualize the traversal
        print("Breadth-First Traversal:")

        while queue:
            # Dequeue a vertex from the queue
            current_vertex = queue.popleft()
            print(current_vertex, end=' ')

            # Explore neighbors of the current vertex
            for neighbor in self.graph[current_vertex]:
                if neighbor not in visited:
                    # Enqueue unvisited neighbors and mark them as visited
                    queue.append(neighbor)
                    visited.add(neighbor)

# Create a graph
g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

# Choose a starting vertex for BFS
start_vertex = 1

# Perform BFS traversal starting from the chosen vertex
g.bfs(start_vertex)
