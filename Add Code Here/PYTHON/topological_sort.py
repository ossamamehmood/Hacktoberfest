class Vertex:
    def __init__(self, name):
        self.name = name
        self.edges = []

    def addEdge(self, vertex):
        self.edges.append(vertex)

class Graph:
    def __init__(self, num_vertices):
        self.vertices = {}
        self.num_vertices = num_vertices

    def addVertex(self, vertex):
        new_vertex = Vertex(vertex)
        self.vertices[vertex] = new_vertex

    def addEdge(self, vertex1, vertex2):
        if vertex1 not in self.vertices:
            self.addVertex(vertex1)
        if vertex2 not in self.vertices:
            self.addVertex(vertex2)
        
        self.vertices[vertex1].addEdge(vertex2)
    
    def topologicalSortUtil(self, v, visited, stack, cycle_check):
        visited[v] = True
        cycle_check[v] = True  
        for vertex in self.vertices[v].edges:
            if visited[vertex] == False:
                if self.topologicalSortUtil(vertex, visited, stack, cycle_check):
                    return True
            elif cycle_check[vertex]:
                return True
        stack.insert(0, v)
        cycle_check[v] = False  
        return False
    
    def topologicalSort(self):
        visited = [False] * (self.num_vertices + 1)  
        stack = []
        cycle_check = [False] * (self.num_vertices + 1) 

        for vertex in self.vertices:
            if visited[vertex] == False:
                if self.topologicalSortUtil(vertex, visited, stack, cycle_check):
                    return None
        
        return stack
        

T = int(input())

while T > 0:
    N, M = map(int, input().split())
    
    g = Graph(N)
    
    while M > 0:
        A, B = map(int, input().split())
        
        if B > N:
            break
        
        g.addEdge(A, B)
        M -= 1
    
    sorted_vertices = g.topologicalSort()
    if sorted_vertices is None:
        print("YES")
    else:
        print("NO")
    
    T -= 1