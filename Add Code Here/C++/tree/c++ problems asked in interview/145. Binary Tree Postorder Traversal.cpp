Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]
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
Output: [2,1]

Solution : 
Time and Space Complexity - O(N) where N is the number of elements in the binary search tree.
  
class Solution {
public:
    vector<int>ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
            return ans;
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        
        return ans;
    }
};
