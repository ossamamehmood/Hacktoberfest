Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]

Solution : Time & Space Complexity - O(n) where n is the number of nodes in the binary search tree.
  
class Solution {
public:
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        
        return ans;
    }
};
