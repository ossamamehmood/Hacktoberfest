mag = 1000000
inf = 1e18
MOD = 1000000007
nodes, edges = map(int, input().split())
vst = [False] * (mag + 1)
mp = [[] for _ in range(mag + 1)]
topo = []

def DFS(v):
    vst[v] = True
    for u in mp[v]:
        if not vst[u]:
            DFS(u)
    topo.append(v)

def DFSmain():
    for i in range(1, nodes + 1):
        if not vst[i]:
            DFS(i)

for _ in range(edges):
    x, y = map(int, input().split())
    mp[x].append(y)

DFSmain()

topo.reverse()
print("Topological sort is:")
for i in topo:
    print(i, end=' ')
