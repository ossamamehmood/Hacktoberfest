class Solution:
    def totalNQueens(self, n: int) -> int:
        import numpy as np
        chess = np.zeros(shape=(n,n))
        columns = [0]*len(chess)
        dia1 = [False]*(2*len(chess)-1)
        dia2 = [False]*(2*len(chess)-1)

        count = []

        def findNQueens(chess, y, count):
            if(y==len(chess)):
                count.append(1)
            else:
                for x in range(len(chess)):
                    if(columns[x] or dia1[y+x] or dia2[x-y+len(chess)-1]):
                        continue
                    else:
                        columns[x]=dia1[x+y]=dia2[x-y+len(chess)-1]=True
                        findNQueens(chess, y+1, count)
                        columns[x]=dia1[x+y]=dia2[x-y+len(chess)-1]=False
        findNQueens(chess, 0, count)
        return sum(count)