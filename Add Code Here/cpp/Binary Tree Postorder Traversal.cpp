class Solution {
public:
    void pre(TreeNode* root,vector<int> &a){
        if(root==NULL){
            return;
        }
    
        pre(root->left,a);
        pre(root->right,a);
        a.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        pre(root,v);
        return v;
        
        
    }
};