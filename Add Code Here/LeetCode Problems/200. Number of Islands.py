class Solution:
    def issafe(self,i,j,visited,grid):
        return ( i>=0 and j>=0 and i<self.row and j<self.col and visited[i][j]==False and grid[i][j]=="1")
    def bfs(self,i,j,visited,grid):
        RowN = [-1,0,0,1]
        ColN = [0,-1,1,0]
        visited[i][j] = True
        global ce
        for ik in range(4):
            
            if self.issafe(i+RowN[ik],j+ColN[ik],visited,grid):
                self.bfs(i+RowN[ik],j+ColN[ik],visited,grid)
                ce +=1
                print(ce,i+RowN[ik],j+ColN[ik])
        
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        global ce 
        ce = 0
        self.row = len(grid)
        self.col = len(grid[0])
        visited = [[False for i in range(len(grid[0]))] for j in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if  visited[i][j] ==False and grid[i][j]=="1":
                    self.bfs(i,j,visited,grid)
                    count +=1
        return count
        
        
        