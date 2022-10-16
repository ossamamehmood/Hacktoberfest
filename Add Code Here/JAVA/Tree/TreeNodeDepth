
	
	Following is the structure used to represent the Binary Tree Node

	class BinaryTreeNode<T> {
		T data;
		BinaryTreeNode<T> left;
		BinaryTreeNode<T> right;

		public BinaryTreeNode(T data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}



public class Solution {
    
    public static void changeToDepthTree(BinaryTreeNode<Integer> root)
    {
        changeToDepthTree(root, 0); 

    } 


	public static void changeToDepthTree(BinaryTreeNode<Integer> root,int h) 
    {
	    if(root==null)
        {
            return;
        }
        root.data=h;
        changeToDepthTree(root.left,h+1);
        changeToDepthTree(root.right,h+1);
	}

}
