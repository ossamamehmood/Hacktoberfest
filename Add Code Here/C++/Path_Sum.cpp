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
class Solution {
public:
     bool pathSum(int sum,TreeNode* root,int t){
        if(root==NULL) return false;
        if(root->left==NULL and root->right==NULL){
            if(sum+root->val==t)
                return true;
        }
        return pathSum(sum+root->val,root->left,t) or pathSum(sum+root->val,root->right,t);
        
        //return false;
     }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(0,root,targetSum);
    }
};