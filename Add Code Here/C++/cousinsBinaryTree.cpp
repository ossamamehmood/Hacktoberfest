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
class myPair{
    public:
    int value=-1;
    int height=-1;
};
class Solution {
public:
    TreeNode*lca(TreeNode*root,int a,int b){
        if(root==NULL){
            return NULL;
        }
        if(root->val==a || root->val==b){
            return root;
        }
        TreeNode*leftans= lca(root->left,a,b);
        TreeNode*rightans = lca(root->right,a,b);
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        if(leftans!=NULL){
            return leftans;
        }
        return rightans;
    }
    myPair findLevel(TreeNode*root,int x,int y){
        myPair p;
        if(root==NULL){
            p.height=-1;
            return p;
        }
        if((root->val==x) || (root->val==y)){
            p.value = root->val;
            p.height = 0;
            return p;
        }
        myPair l = findLevel(root->left,x,y);
        myPair r = findLevel(root->right,x,y);
        if(l.height!=-1 ||r.height!=-1){
            p.height = max(l.height,r.height)+1;
        }
        if(l.value!=-1){
            p.value = l.value;
        }
        if(r.value!=-1){
            p.value = r.value;
        }
        return p;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode*found = lca(root,x,y);
        //need to find the level of the both values from the node next to root node
        TreeNode*leftNode=NULL;
        TreeNode*rightNode=NULL;
        if(found!=NULL && found->left!=NULL && found->right!=NULL){
            leftNode=found->left;
            rightNode=found->right;
        }
        myPair leftLevel = findLevel(leftNode,x,y);
        myPair rightLevel = findLevel(rightNode,x,y);
        int leftValue = leftLevel.value;
        int rightValue = rightLevel.value;
        if((rightValue==x && leftValue==y) || (rightValue==y && leftValue==x)){
            if(leftLevel.height==rightLevel.height && leftLevel.height!=0 && rightLevel.height!=0 && leftLevel.height!=-1 && rightLevel.height!=-1){
                return true;
            }
        }
        return false;
    }
};
