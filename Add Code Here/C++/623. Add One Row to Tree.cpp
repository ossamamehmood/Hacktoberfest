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
    
    void dfs(TreeNode* root, int val, int depth,int lvl){
        
        if(root==nullptr)
            return ;
        
        if(lvl==depth-1)
        {
        
            TreeNode *n1= new TreeNode(val,root->left,nullptr);
              TreeNode  *n2= new TreeNode(val,nullptr,root->right);
            
             root->left=n1;
        root->right=n2;
            
            return ;
        }
        
       
        
          dfs(root->left,val,depth,lvl+1);
        
          dfs(root->right,val,depth,lvl+1);
        
        
        
    }
    
    
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        
        if(depth==1){
            
             TreeNode *n1= new TreeNode(val,root,nullptr);
            return  n1;
            
        }
        
        
        dfs(root,val,depth,1);
        
        return root;        
        
        
        
        
        
        
        
    }
};
