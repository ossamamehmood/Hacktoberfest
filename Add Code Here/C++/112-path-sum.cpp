/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution by Sameer Aggrawal
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        if(!root->left and !root->right)
        {
            if(targetSum==root->val) return true;
            return false;
        }
        
        if(hasPathSum(root->left,targetSum-root->val)) return true;
        
        if(hasPathSum(root->right,targetSum-root->val)) return true;
        
        return false;
    }
};
