import heapq
from collections import Counter

class Node:
    def __init__(self,freq,symbol,left=None,right=None):
        self.freq=freq
        self.symbol=symbol
        self.left=left
        self.right=right
        self.huff=''
        
    def __lt__(self,other):
        return self.freq<other.freq
    
    
def printNodes(node, val=''):
    if not node:
        return
    newVal=val+str(node.huff)
    if not node.left and not node.right:
        print(f"{node.symbol} -> {newVal}")
    printNodes(node.left,newVal)
    printNodes(node.right,newVal)
    
string=input("Enter the string: ").lower()
res = Counter(string)
nodes = [Node(freq,char) for char,freq in res.items()]
heapq.heapify(nodes)

while len(nodes)>1:
    left=heapq.heappop(nodes)
    right=heapq.heappop(nodes)
    left.huff='0'
    right.huff='1'
    newNode=Node(left.freq+right.freq,left.symbol+right.symbol,left,right)
    heapq.heappush(nodes,newNode)
    
printNodes(nodes[0])
        
