
    
    

class Solution:
    #Function to find a Mother Vertex in the Graph.
    def dfs(self, adj, visited, ind):
        visited[ind] = 1
        for i in adj[ind]:
            if not visited[i]:
                self.dfs(adj, visited, i)
                
    def findMotherVertex(self, V, adj):
        #Code here
        visited = [ 0 for i in range(V) ]
        v = 0
        for i in range(V):
            if not visited[i]:
                self.dfs(adj, visited, i)
                v = i 
        visited = [ 0 for i in range(V) ]
        self.dfs(adj, visited, v)
        if 0 in visited:
            return -1
        return v
