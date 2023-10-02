/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nodeToRootPath(TreeNode* root,int value){
    if(root->val==value){
        vector<TreeNode*>path;
        path.push_back(root);
        return path;
    }
    vector<TreeNode*>result;
    if(root->left!=NULL){
       result= nodeToRootPath(root->left,value);
       if(result.size()>0){
        result.push_back(root);
       }
    }
    if(result.size()==0){
    if(root->right!=NULL){
        result=nodeToRootPath(root->right,value);
        if(result.size()>0){
        result.push_back(root);
       }
    }
    }
    return result;
    }
    void klevelsdown(TreeNode* root,int k,TreeNode* block){
    if(root==NULL || k<0 || root==block){
        return;
    }
    if(k==0){
        result.push_back(root->val);
    }
    klevelsdown(root->left,k-1,block);
    klevelsdown(root->right,k-1,block);
    }
    vector<int>result;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<TreeNode*>path=nodeToRootPath(root,target->val);
    for(int i=0;i<path.size();i++){
        klevelsdown(path[i],k-i,i==0?NULL:path[i-1]);
    }
    return result;
    }
};
