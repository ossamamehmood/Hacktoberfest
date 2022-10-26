class Node():
    def __init__(self,name):
        self.children = []
        self.name = name
        
    def add_child(self, name):
        self.children.append(Node(name))
    def display(self):
        return self.children.name
        
    def bfs(self, array):
        qeue = [self]
        while len(qeue) > 0:
            current = qeue.pop(0)
            array.append(current.name)
            for child in current.children:
                qeue.append(child)
        return array
    
#code below
n = Node("A")
n.add_child("a")
n.add_child("b")
n.add_child("c")

n.bfs(array)
