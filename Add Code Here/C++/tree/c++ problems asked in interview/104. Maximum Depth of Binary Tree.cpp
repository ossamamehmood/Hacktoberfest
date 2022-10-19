Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1
  
Solution :

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        if(leftDepth > rightDepth)
            return leftDepth+1;
        else
            return rightDepth+1;
    }
};

Time Complexity - O(N) where N is the number of nodes present in the tree. 
