/**
 * Abdul Rehman
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
    int checkForBalanced(TreeNode *root, bool &ans) {
        if (ans == false) return -1;
        if (!root) return 0;
        int lheight = checkForBalanced(root->left, ans);
        int rheight = checkForBalanced(root->right, ans);
        if (abs(lheight-rheight) > 1) ans = false;
        return 1 + max (lheight, rheight);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = checkForBalanced(root, ans);
        return ans;
    }
};