class Solution {
public:
TreeNode* built(vector<int>&postorder,vector<int>&inorder,int start,int end,int& ind){
    if(start>end||ind<0)return NULL;
    TreeNode* root=new TreeNode(postorder[ind--]);
    int pos=0;
    for(int i=start;i<=end;i++){
        if(inorder[i]==root->val){
            pos=i;
            break;
        }
    }
root->right=built(postorder,inorder,pos+1,end,ind);
    root->left=built(postorder,inorder,start,pos-1,ind);
     
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size()-1;
    return built(postorder,inorder,0,inorder.size()-1,n) ;
    }
};
