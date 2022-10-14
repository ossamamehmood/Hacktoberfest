# N-Queen using DFS
import collections
import sys
sys.setrecursionlimit(1000000)
N=int(input())
queenpos=collections.deque()
def checkboard(y,x):
	for dy,dx in queenpos:
		if dy == y and dx == x:
			continue
		if dy == y:
			return 0
		if dx == x:
			return 0
		if abs(dy-y) == abs(dx-x):
			return 0
	return 1

def DFS(y,x):
	result = 0
	queenpos.append((y,x))
	if y == N-1:
		result += checkboard(y,x)
	else:
		if checkboard(y,x) == 1:
			for i in range(0,N):
				result += DFS(y+1,i)
	queenpos.pop()
	return result
result = 0
for i in range(0,N):
	result += DFS(0,i)

print(result)