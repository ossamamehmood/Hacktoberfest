class BinaryTree:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
        
def treeinput():
    data=int(input())
    if data==-1:
        return None
    root=BinaryTree(data)
    leftdata=treeinput()
    rightdata=treeinput()
    root.left=leftdata
    root.right=rightdata
    return root
        
def printTree(root):
    if root==None:
        return
    print(root.data,end=":")
    if root.left!=None:
        print("L",root.left.data,end=",")
    if root.right!=None:
        print("R",root.right.data,end="")
    print()
    printTree(root.left)
    printTree(root.right)
    
def height(root):
    if root==None:
        return 0
    return max(height(root.left),height(root.right)) + 1

root=treeinput()
printTree(root)
print("HEIGHT OF THE BINARY TREE IS : ",height(root))