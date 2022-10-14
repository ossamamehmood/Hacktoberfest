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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=0,right=0;
        TreeNode *ptr1=root, *ptr2=root;
        
        while(ptr1){
            ptr1=ptr1->left;
            left++;
        }
        
        while(ptr2){
            ptr2=ptr2->right;
            right++;
        }
        if(left == right)
            return pow(2,left) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};