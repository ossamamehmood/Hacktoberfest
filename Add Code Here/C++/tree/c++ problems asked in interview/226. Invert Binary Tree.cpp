Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []

Solution :

Time Complexity - O(N) where N is the number of elements present in the tree.
Space Complexity - O(1) because we are not using any extra space.
  
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       if(root)
       {
           invertTree(root->left);
           invertTree(root->right);
           swap(root->left,root->right); 
       }
        return root;
    }
};

This is a recursive approach. 
