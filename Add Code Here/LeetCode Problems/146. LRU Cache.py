class Node:
    def __init__(self,key,val):
        self.key,self.val,self.prev,self.nxt = key,val,None,None


# Doubly Linked List nodes with a cache as dictionary
class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.left,self.right = Node(0,0),Node(0,0)
        self.left.nxt,self.right.prev = self.right,self.left
        self.cache = {}

    def insert(self,curr):
        a,b = self.right.prev,self.right
        curr.prev,curr.nxt = a,b
        a.nxt = b.prev = curr 

    def remove(self,curr):
        a,b = curr.prev,curr.nxt
        a.nxt,b.prev = b,a

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key,value)
        self.insert(self.cache[key])
        if len(self.cache)>self.cap:
            del self.cache[self.left.nxt.key]
            self.remove(self.left.nxt)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)