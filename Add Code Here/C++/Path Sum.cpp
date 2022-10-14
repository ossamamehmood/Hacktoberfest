// https://leetcode.com/problems/path-sum/

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
    
    int solve(TreeNode* root, int t,int sum){
        
        if(root==nullptr)
        {
            return 0;
            
        }
        
        if(sum==INT_MIN)
            sum=0;
        
        sum+= root->val;
        
        
        
        
        if(root->left==nullptr && root->right==nullptr){
            if(sum==INT_MIN)
                return 0;
            if(sum==t)
                return 1;
            else
                return 0;
        }
        
        
        
        
        
        
        
        
        
        return max(solve(root->left,t,sum),solve(root->right,t,sum)  );
        
        
        
        
    }
    
    
    
    
    
    
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root,targetSum,INT_MIN);
        
        
    }
};
