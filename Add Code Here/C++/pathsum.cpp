
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
