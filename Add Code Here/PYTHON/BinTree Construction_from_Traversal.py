'''
Recursive Approach

BASE CASE -> If the array inorder is empty. -> RETURN
SELF WORK -> Create a new node with the value preorder[0] as first element is the root of the tree.
Recursion ->

Let the index of preorder[0] in inorder be INDEX.
Recursivly create left subtree by passing -> preorder with first element removed and the part of inorder array that lies to the left of INDEX. ->inorder[:INDEX]
Recursivly create right subtree by passing -> the part of inorder array that lies to the right of INDEX. ->inorder[:INDEX]

'''


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(self, preorder, inorder):
    if inorder:
        INDEX = inorder.index(preorder.pop(0))
        root = TreeNode(inorder[INDEX])
        root.left = self.buildTree(preorder, inorder[:INDEX])
        root.right = self.buildTree(preorder, inorder[INDEX+1:])
			
        return root
      
preorder = list(map(int,input().split()))
inorder  = list(map(int,input().split()))

root = buildTree(preorder,inorder)
