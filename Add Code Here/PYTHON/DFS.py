class Node:
    def __init__(self,data):
        self.left = None;
        self.right = None;
        self.data = data;
            
    def preorder(self,root):
        if root is None:
            return
        print (root.data)
        return self.preorder(root.left), self.preorder(root.right)
    
    def inorder(self,root):
        if root is None:
            return
        if self.inorder(root.left)!= None:
            print(self.inorder(root.left)) 
        print(root.data)  
        if self.inorder(root.right):            
            print(self.inorder(root.right))   
            
    def postorder(self,root):
        if root is None:
            return
        if self.inorder(root.left)!= None:
            print(self.inorder(root.left))  
        if self.inorder(root.right):            
            print(self.inorder(root.right)) 
        print(root.data) 

root = Node(1)
root.left = Node(2)
root.right = Node(3)

root.preorder(root)
root.inorder(root)
root.postorder(root)