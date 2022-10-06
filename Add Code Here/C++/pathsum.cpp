// https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       
        if(root == NULL)return false;
         return  pSum(root,0,targetSum);
    }
    bool pSum(TreeNode* root,int sum , int targetSum){
       sum += root->val;
       bool lh = false, rh = false;
        if(root->left == NULL && root->right == NULL ){
            if(sum == targetSum){return true;}
            return false;
        }
        else {
         if((root->left) != NULL){lh =  pSum(root->left,sum,targetSum);}
              if((root->right) != NULL){rh =  pSum(root->right,sum,targetSum);}
        }
        return lh || rh;
    }
};
