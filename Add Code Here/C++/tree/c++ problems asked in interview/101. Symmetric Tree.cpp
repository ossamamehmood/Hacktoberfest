Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

Solution :

Time Complexity - O(n) where n is the number of nodes in the tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetricTest(root->left , root->right); //treating both branches as separate trees 
    }
    
    bool isSymmetricTest(TreeNode* p,TreeNode* q )
    {
        if(p==NULL && q==NULL)
            return true;
        
        else if(p==NULL || q==NULL)
            return false;
        
        else if(p->val!=q->val)
            return false;
        
        return isSymmetricTest(p->left,q->right) && isSymmetricTest(p->right,q->left);
    }
};
