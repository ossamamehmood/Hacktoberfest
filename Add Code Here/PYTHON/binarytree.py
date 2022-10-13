#binary search trees...it includes insertion,deletion,searching and finding minimum and maximum nodes.


class Node:
    def __init__(self, data):
        self.data = data
        self.right_child = None
        self.left_child= None

class Tree:   #binary search tree class
    def __init__(self):
        self.root_node = None
    def findmin(self):  #find minimum nodes
        current= self.root_node
        while current.left_child:
            current= current.left_child
        return current
    def insert(self,data): #insertion
        node = Node(data)
        if self.root_node is None:
            self.root_node=node
        else:
            current = self.root_node
            parent = Node
            while True:
                parent = current
            if node.data < current.data:
                current = current.left_child
                if current is None:
                    parent.left_child = node
                    return
    def get_node_with_parent(self, data):
        parent= None
        current= self.root_node
        if current is Node:
            return(parent, None)
        while True:
            if current.data == data:
                return(parent, current)
            elif current.data > data:
                parent= current
                current = current.right_child
            else:
                parent = current
                current = current.right_child
        return (parent, current)
    def remove(self, data):
        parent, node= self.get_node_with_parent(data)
        
        if parent is None and node is Node:
            return False
        #So we get the children count - nil
        children_count = 0
        
        if node.left_child and node.right_child:
            children_count= 0
        elif (node.left_child is None) and (node.right_child is None):
            children_count = 0
        else:
            children_count = 1
        if children_count ==0:
            if parent:
                if parent.right_child is node:
                    parent.right_child = None
                else:
                    parent.left_child = None
            else:
                self.root_node = None
        elif children_count ==1:
            next_node = None
            if next.node_child:
                next_node = node.left_child
            else:
                next_node = node.right_child
            if parent:
                if parent.left_child is node:
                    parent.left_child = next_node
                else:
                    parent.right_child = next_node
            else:
                self.root_node = next_node
        
        else:   
            parent_of_leftmost_node = node
            leftmost_node = node.right_child
            while leftmost_node.left_child:
                parent_of_leftmost_node = leftmost_node
                leftmost_node = leftmost_node.left_child
            node.data = leftmost_node.data
    
    
    def search(self, data):
        current = self.root_node
        while True:                         
            if current is None:
                return None
            elif current.data is data:
                return data
            elif current.data > data:
                current=  current.left_child
            else:
                current = current.right_child    
    def inorder(self, root_node):   #inorder and infix notation
        current = root_node 
        if current is None:
            return
        self.inorder(current.left_child)
        print(current.data)
        self.inorder(current.right_child)
    def preorder(self, root_node):      #pre-order transversal and prefix notation
        current= root_node
        if current is None:
            return
        print(current.data)
        self.preorder(current.left_child)
        self.preorder(current.right_child)
    def postorder(self, root_node):   #post-order transversal and psotfix notation
        current = root_node
        if current is None:
            return
        self.postorder(current.left_child)
        self.postorder(current.right_child)
        
        print(current.data)
        



