class Node:
    def __init__(self, data):
        self.data = data
        self.leftChild = None
        self.rightChild = None

    def PrintTree(self):
        print(self.data)

root = Node(27)
root.PrintTree()
